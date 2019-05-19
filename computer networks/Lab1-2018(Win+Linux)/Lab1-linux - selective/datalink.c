#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "protocol.h"
#include "datalink.h"

#ifndef DATA_TIMER
    #define DATA_TIMER  2000
#endif
#ifndef ACK_TIMER
    #define ACK_TIMER   240
#endif                          // 可以用编译参数覆盖掉这些设置
#define MAX_SEQ 255
#define NR_BUFS 128              // 限于定时器数量，窗口最大只能开到128
#define inc(x) ((x) = ((x) + 1) % (MAX_SEQ + 1)) // 模意义下自加
#define DATA_MASK 1             // 判断帧是否携带数据的MASK
#define ACK_MASK 2              // 判断帧是否携带ACK的MASK
#define NAK_MASK 4              // 判断帧是否携带NAK的MASK
#define SHORTFRM_MASK 6         // 判断是否是短帧的MASK
#define DATA 3                  // 数据帧
#define ACK 2                   // ACK帧
#define NAK 6                   // NAK帧

struct FRAME {
    unsigned char kind; /* 帧种类 */
    unsigned char ack;  /* ACK号 */
    unsigned char seq;  /* 数据编号 */
    unsigned char data[PKT_LEN];  /* 数据内容 */
    unsigned int  padding;  /* 内部边界，防止贴CRC32时内存访问越界 */
};
struct packet {
    unsigned char data[PKT_LEN];  /* 数据字段 */
};

typedef unsigned char seq_nr;
typedef int event_type;
typedef unsigned char frame_kind;
typedef struct packet packet;
typedef struct FRAME FRAME;
static bool no_nak = true;         // 未发送过nak标记
static int phl_ready = 0;          // 物理层就绪标志
seq_nr next_frame_to_send;         // 发送窗口上界
seq_nr ack_expected;               // 发送窗口下界
seq_nr frame_expected;             // 接收窗口下界-1(即被接受的最后一个帧的编号)
packet  out_buf[NR_BUFS],          // 发送缓存
        in_buf[NR_BUFS];           // 接收缓存
seq_nr nbuffered;                  // 发送缓存中的有效包数目
seq_nr too_far;                    // 接收窗口上界
bool arrived[NR_BUFS];             // 接收缓存有效标记


static void put_frame(unsigned char *frame, int len) {
    // 为len字节的数据计算CRC32，并将贴上了CRC32的共len+4字节数据送到物理层
    *(unsigned int *)(frame + len) = crc32(frame, len);
    send_frame(frame, len + 4);
    phl_ready = 0;
}

static void send_data_frame(frame_kind kind, seq_nr frame_nr, seq_nr frame_expected, packet buffer[]) {
    // 将缓存buffer中编号为frame_nr的数据包作为kind帧发送出去，同时捎带返回frame_expected
    FRAME s;
    s.kind = kind;
    if (kind & DATA_MASK) memcpy(s.data, buffer[frame_nr % NR_BUFS].data, sizeof(s.data));
    if (kind & NAK_MASK) no_nak = false;
    s.seq = frame_nr;
    s.ack = (frame_expected + MAX_SEQ) % (MAX_SEQ + 1);
    if (kind & DATA_MASK) {
        put_frame((unsigned char *) &s, sizeof(FRAME) - 4);
        start_timer(frame_nr % NR_BUFS, DATA_TIMER);
    } else if (kind & SHORTFRM_MASK) {
        dbg_frame("Sending short frame %s for %d.\n", (kind == ACK) ? "ACK" : "NAK", frame_expected);
        put_frame((unsigned char *) &s, 2);
    }
    phl_ready = 0;
    stop_ack_timer();
    return;
}


static bool between(seq_nr a, seq_nr b, seq_nr c) {
    // 判断b是否在a、c构成的窗口内
    return (((a <= b) && (b < c)) || ((c < a) && (a <= b)) || ((b < c) && (c < a)));
}


int main(int argc, char **argv)
{
    int arg;             // 用于接收wait_for_event的第二返回参数
    event_type event;    // 接收event
    FRAME r;             // 存储frame的临时变量
    int len;             // 保存从物理层收到的数据的长度的临时变量
    protocol_init(argc, argv);
    lprintf("Designed by CJSoft, build: " __DATE__"  "__TIME__"\n");
    enable_network_layer();
    ack_expected = 0;
    next_frame_to_send = 0;
    frame_expected = 0;
    too_far = NR_BUFS;
    nbuffered = 0;
    memset(arrived, 0, sizeof(arrived));

    while (1) {
        event = wait_for_event(&arg);
        switch (event) {
            case NETWORK_LAYER_READY:
                get_packet((unsigned char *)&(out_buf[next_frame_to_send % NR_BUFS].data));
                nbuffered++;
                send_data_frame(DATA, next_frame_to_send, frame_expected, out_buf);
                inc(next_frame_to_send);
                break;
            case FRAME_RECEIVED:
                len = recv_frame((unsigned char *)&r, sizeof(r));
                if (len < 5 || crc32((unsigned char *)&r, len) != 0) {
                    dbg_frame("**** Receiver Error, Bad CRC Checksum\n");
                    goto BAD_CRC_CHECKSUM;
                }
                if (r.kind & DATA_MASK) {
                    if (r.seq != frame_expected && no_nak)
                        send_data_frame(NAK, 0, frame_expected, out_buf);
                    else
                        start_ack_timer(ACK_TIMER);
                    if (between(frame_expected, r.seq, too_far) && (arrived[r.seq % NR_BUFS] == false)) {
                        dbg_frame("Recv DATA SEQ:%d ACK:%d, DATA:%d\n", r.seq, r.ack, *(short *)r.data);
                        arrived[r.seq % NR_BUFS] = true;
                        memcpy(in_buf[r.seq % NR_BUFS].data, r.data, PKT_LEN); // TODO
                        while (arrived[frame_expected % NR_BUFS]) {
                            put_packet((unsigned char*)(in_buf[frame_expected % NR_BUFS].data), PKT_LEN);
                            no_nak = true;
                            arrived[frame_expected % NR_BUFS] = false;
                            inc(frame_expected);
                            inc(too_far);
                            start_ack_timer(ACK_TIMER);
                        }
                    }
                }
                if (r.kind & NAK_MASK) {
                    dbg_event("Recv NAK %d.\n", r.ack);
                    if (between(ack_expected, (r.ack + 1) % (MAX_SEQ + 1), next_frame_to_send))
                        send_data_frame(DATA, (r.ack + 1) % (MAX_SEQ + 1), frame_expected, out_buf);
                }
                if (r.kind & ACK_MASK) {
                    dbg_event("Recv ACK %d.\n", r.ack);
                    while (between(ack_expected, r.ack, next_frame_to_send)) {
                        nbuffered--;
                        stop_timer(ack_expected % NR_BUFS);
                        inc(ack_expected);
                    }

                }

                break;
            case PHYSICAL_LAYER_READY:
                phl_ready = 1;
                break;
            case DATA_TIMEOUT:
                dbg_frame("---- DATA %d timeout, resending DATA\n", arg);
                send_data_frame(DATA, ack_expected, frame_expected, out_buf);
                break;
            case ACK_TIMEOUT:
                dbg_frame("ACK timeout, sending ACK frame for %d.\n", frame_expected);
                send_data_frame(ACK, 0, frame_expected, out_buf);
                break;
            BAD_CRC_CHECKSUM:;
                if (no_nak) send_data_frame(NAK, 0, frame_expected, out_buf);
        }
        if (nbuffered < NR_BUFS && phl_ready) enable_network_layer();
        else {
            disable_network_layer();
        }
    }
}
