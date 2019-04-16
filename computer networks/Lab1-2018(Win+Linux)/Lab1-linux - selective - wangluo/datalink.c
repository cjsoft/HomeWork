#include <stdio.h>
#include <string.h>

#include "protocol.h"
#define FRAME_DATA 1
#define FRAME_ACK  2
#define FRAME_NAK  3

#define MAX_SEQ 15                  //最大的窗口大小
#define NR_BUFS ((MAX_SEQ + 1) / 2)     //缓冲区大小

#define DATA_TIMER  3000       //帧超时时间间隔
#define ACK_TIMER 240          //ack的超时间隔

struct FRAME { 
    //数据帧的结构体定义
    unsigned char kind;
    unsigned char ack;
    unsigned char seq;
    unsigned char data[PKT_LEN]; 
    unsigned int  padding;
};

int no_nak=1;                           //标志是否已经发送过nak
static int phl_ready = 0;               //物理层就绪标记
unsigned char oldest_frame = MAX_SEQ + 1;   //

static int between(unsigned char a,unsigned char b,unsigned char c)  
//滑动窗口判断函数，判断帧号（ack号）是否在窗口内
{
   if(((a <= b) && (b < c)) || ((c < a) && (a <= b)) || ((b < c) && (c < a)))
        return 1;
    else
        return 0;

}

static void put_frame(unsigned char *frame, int len)
{
    //发送帧前预处理，加入校验和crc
    *(unsigned int *)(frame + len) = crc32(frame, len);//crc32校验
    send_frame(frame, len + 4);//发送帧
    phl_ready = 0;//设置物理层阻塞
}

static void send_data_frame(unsigned char fk,unsigned char frame_nr,unsigned char frame_expected,unsigned char buffer[NR_BUFS][PKT_LEN])
{
    //发送数据帧，或ack与nak
    struct FRAME s;
    
    s.kind = fk;
    s.seq = frame_nr;
    s.ack = (frame_expected + MAX_SEQ) % (MAX_SEQ + 1);

    if(fk==FRAME_DATA)//发送的是数据帧
    {
        memcpy(s.data, buffer[frame_nr % NR_BUFS], PKT_LEN);//复制分组到帧内
        dbg_frame("Send DATA %d %d, ID %d\n", s.seq, s.ack, *(short *)s.data);//输出记录
        put_frame((unsigned char *)&s, 3 + PKT_LEN);   //发送
        start_timer(frame_nr % NR_BUFS, DATA_TIMER);     //启动定时器
    }
    else if(fk == FRAME_NAK)//发送的是NAK
    {
        no_nak = 0;                                     //下一次不再发送nak
        put_frame((unsigned char *)&s, 3);            //发送
    }
    else if(fk == FRAME_ACK)//发送的是ACK
    {
        dbg_frame("Send ACK  %d\n", s.ack);//输出记录
        put_frame((unsigned char *)&s, 3);//发送
    }
    phl_ready = 0;                          //物理层阻塞
    stop_ack_timer();                       //关闭ack定时器
}

void main(int argc, char **argv)
{
    int event, arg;
    struct FRAME f;
    int len = 0;
    int i;
    static unsigned char ack_expected = 0, next_frame_to_send = 0;//当前帧和下一期望帧的序号
    static unsigned char frame_expected = 0, too_far = NR_BUFS;
    static unsigned char nbuffered;
    int arrived[NR_BUFS];//缓冲区，存放到达的帧
    static unsigned char out_buf[NR_BUFS][PKT_LEN], in_buf[NR_BUFS][PKT_LEN];

    protocol_init(argc, argv);//初始化协议

    lprintf("Coded by zdf, Build Time: " __DATE__"  "__TIME__"\n");

    for(i = 0; i < NR_BUFS; i++)   //将接收方的缓冲区清空
        arrived[i] = 0;

    enable_network_layer();//启动网络层，准备接收数据

    while(1)
    {
        event = wait_for_event(&arg);           //等待事件，进行下一步操作
        switch (event)
        {
            case NETWORK_LAYER_READY:
                nbuffered++;                    //发送却未被确认的帧计数器+1
                get_packet(out_buf[next_frame_to_send % NR_BUFS]);//得到分组存入缓冲区内
                send_data_frame(FRAME_DATA,next_frame_to_send,frame_expected,out_buf);//发送数据帧
                next_frame_to_send=(next_frame_to_send + 1) % ( MAX_SEQ + 1);//处理滑动窗口
                break;

            case PHYSICAL_LAYER_READY:
                phl_ready = 1;
                break;

            case FRAME_RECEIVED:
                len = recv_frame((unsigned char *)&f, sizeof f);
                if (len < 5 || crc32((unsigned char *)&f, len) != 0)
                {   //校验和错误，发送NAK请求重传
                    if(no_nak == 1)
                        send_data_frame(FRAME_NAK, 0, frame_expected, out_buf);
                    dbg_event("---- Receive Frame Error, Bad CRC Checksum ----\n");//输出记录
                    break;
                }
                if (f.kind == FRAME_DATA)
                {
                    //收到的是数据帧
                    if((f.seq != frame_expected) && no_nak == 1)// 帧序列号错误，不接受
                        send_data_frame(FRAME_NAK,0, frame_expected, out_buf);//返回NAK
                    else 
                        start_ack_timer(ACK_TIMER);//启动ack计时器（捎带确认）
                    if(between(frame_expected, f.seq, too_far) == 1 && arrived[f.seq % NR_BUFS] == 0)
                    {
                        //若收到的帧在接受方滑动窗口里，进行处理
                        dbg_frame("Recv DATA %d %d, ID %d\n", f.seq, f.ack, *(short *)f.data);//输出记录
                        arrived[f.seq % NR_BUFS] = 1;//记录收到的帧
                        memcpy(in_buf[f.seq % NR_BUFS], f.data, len - MAX_SEQ / 2);
                        while(arrived[frame_expected % NR_BUFS])
                        {
                            //一次处理缓冲区内部的所有帧，把小于当前序列号的帧顺次转发到网络层
                            put_packet(in_buf[frame_expected % NR_BUFS], len - MAX_SEQ / 2);
                            no_nak = 1;//复位NAK标记
                            arrived[frame_expected%NR_BUFS] = 0;//清空缓冲区标志

                            frame_expected = (frame_expected+1) % (MAX_SEQ + 1);//窗口指针复位
                            too_far = (too_far + 1) % (MAX_SEQ + 1);//接收方窗口向右滑动1单位
                            start_ack_timer(ACK_TIMER);//启动ack计时器
                        }
                    }
                }
                if((f.kind == FRAME_NAK) && between(ack_expected,(f.ack + 1) % (MAX_SEQ + 1), next_frame_to_send) == 1)
                {
                    //发送方收到nak,重传丢失（出错）的帧
                    dbg_frame("Recv NAK %d\n", f.ack);//输出记录
                    send_data_frame(FRAME_DATA,(f.ack + 1) % (MAX_SEQ + 1), frame_expected, out_buf);
                }
                while(between(ack_expected,f.ack,next_frame_to_send) == 1)
                {
                    //收到期望帧，传输完成
                    nbuffered--;        //发送却未被确认的帧计数器-1
                    stop_timer(ack_expected % NR_BUFS);         //关闭帧的计时器
                    ack_expected = (ack_expected + 1) % (MAX_SEQ + 1);
                }
                break;

            case DATA_TIMEOUT:
                //数据丢失，重新发送数据帧
                dbg_event("---- DATA %d timeout\n", arg);       //输出记录
                send_data_frame(FRAME_DATA,ack_expected, frame_expected, out_buf);//报告超时，要求重传数据
                break;
            case ACK_TIMEOUT:
                //反向ACK丢失，单独发送ACK确认帧
                dbg_event("---- ACK %d timeout\n", arg);        //输出记录
                send_data_frame(FRAME_ACK, 0, frame_expected, out_buf);//报告超时，要求重传ACK
        }

        if (nbuffered < NR_BUFS && phl_ready)
            //缓冲区没有满，继续来~
            enable_network_layer();
        else
            //缓冲区已炸，暂停数据传输
            disable_network_layer();
    }
}
