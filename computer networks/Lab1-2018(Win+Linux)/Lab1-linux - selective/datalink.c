#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "protocol.h"
#include "datalink.h"

#ifndef DATA_TIMER
    #define DATA_TIMER  3000
#endif
#ifndef ACK_TIMER
    #define ACK_TIMER   240
#endif
#define MAX_SEQ 255
#define NR_BUFS 128
#define inc(x) ((x) = ((x) + 1) % (MAX_SEQ + 1))
#define DATA_MASK 1
#define ACK_MASK 2
#define NAK_MASK 4
#define SHORTFRM_MASK 6
#define DATA 3
#define ACK 2
#define NAK 6

typedef unsigned char seq_nr;
typedef int event_type;
typedef unsigned char frame_kind;
struct FRAME {
    unsigned char kind; /* FRAME_DATA */
    unsigned char ack;
    unsigned char seq;
    unsigned char data[PKT_LEN];
    unsigned int  padding;
};
struct packet {
    unsigned char data[PKT_LEN];
};
typedef struct packet packet;
typedef struct FRAME FRAME;
static bool no_nak = true;
//static seq_nr oldest_frame = MAX_SEQ + 1;
//static unsigned char frame_nr = 0, buffer[PKT_LEN], nbuffered;
//static unsigned char frame_expected = 0;
static int phl_ready = 0;

static void put_frame(unsigned char *frame, int len)
{
    *(unsigned int *)(frame + len) = crc32(frame, len);
    send_frame(frame, len + 4);
    phl_ready = 0;
}

static void send_data_frame(frame_kind kind, seq_nr frame_nr, seq_nr frame_expected, packet buffer[])
{
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
        put_frame((unsigned char *) &s, 3);
    }
    phl_ready = 0;
    stop_ack_timer();
    return;
}


static bool between(seq_nr a, seq_nr b, seq_nr c) {
    return (((a <= b) && (b < c)) || ((c < a) && (a <= b)) || ((b < c) && (c < a)));
}

seq_nr next_frame_to_send;
seq_nr ack_expected;
seq_nr frame_expected;
int len;
FRAME r;
packet  out_buf[NR_BUFS],
        in_buf[NR_BUFS];
seq_nr nbuffered;
seq_nr too_far;
seq_nr i;
event_type event;
int arg;
bool arrived[NR_BUFS];
int main(int argc, char **argv)
{
    int cnt = 1;

    protocol_init(argc, argv);
    lprintf("Designed by CJSoft, build: " __DATE__"  "__TIME__"\n");

//    disable_network_layer();
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
                dbg_frame("Data %d is sent, with ACK %d.\n", next_frame_to_send, frame_expected);
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
                        start_ack_timer(ACK_TIMEOUT);
                    if (between(frame_expected, r.seq, too_far) && (arrived[r.seq % NR_BUFS] == false)) {
                        arrived[r.seq % NR_BUFS] = true;
                        memcpy(in_buf[r.seq % NR_BUFS].data, r.data, PKT_LEN); // TODO
                        while (arrived[frame_expected % NR_BUFS]) {
                            put_packet((unsigned char*)(in_buf[frame_expected % NR_BUFS].data), PKT_LEN);
                            no_nak = true;
                            arrived[frame_expected % NR_BUFS] = false;
                            inc(frame_expected);
                            inc(too_far);
                            start_ack_timer(ACK_TIMEOUT);
                        }
                    }
                }
                if (r.kind & NAK_MASK) {
//                    dbg_event("Recv NAK %d.\n", r.ack);
                    if (between(ack_expected, (r.ack + 1) % (MAX_SEQ + 1), next_frame_to_send))
                        send_data_frame(DATA, (r.ack + 1) % (MAX_SEQ + 1), frame_expected, out_buf);
                }
                if (r.kind & ACK_MASK) {
//                    dbg_event("Recv ACK %d.\n", r.ack);
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
//            if (phl_ready)
//                dbg_warning("Disabling network layer because of buffer is full. # %d\n", cnt++);
//            else
//                dbg_warning("Disabling network layer because of physical layer is busy. # %d\n", cnt++);
            disable_network_layer();
        }
    }


//    int event, arg;
//    struct FRAME f;
//    int len = 0;
//
//    protocol_init(argc, argv);
//    lprintf("Designed by CJSoft, build: " __DATE__"  "__TIME__"\n");
//
//    disable_network_layer();
//
//    for (;;) {
//        event = wait_for_event(&arg);
//
//        switch (event) {
//        case NETWORK_LAYER_READY:
//            get_packet(buffer);
//            nbuffered++;
//            send_data_frame();
//            break;
//
//        case PHYSICAL_LAYER_READY:
//            phl_ready = 1;
//            break;
//
//        case FRAME_RECEIVED:
//            len = recv_frame((unsigned char *)&f, sizeof f);
//            if (len < 5 || crc32((unsigned char *)&f, len) != 0) {
//                dbg_event("**** Receiver Error, Bad CRC Checksum\n");
//                break;
//            }
//            if (f.kind == FRAME_ACK)
//                dbg_frame("Recv ACK  %d\n", f.ack);
//            if (f.kind == FRAME_DATA) {
//                dbg_frame("Recv DATA %d %d, ID %d\n", f.seq, f.ack, *(short *)f.data);
//                if (f.seq == frame_expected) {
//                    put_packet(f.data, len - 7);
//                    frame_expected = 1 - frame_expected;
//                }
//                send_ack_frame();
//            }
//            if (f.ack == frame_nr) {
//                stop_timer(frame_nr);
//                nbuffered--;
//                frame_nr = 1 - frame_nr;
//            }
//            break;
//
//        case DATA_TIMEOUT:
//            dbg_event("---- DATA %d timeout\n", arg);
//            send_data_frame();
//            break;
//        }
//
//        if (nbuffered < 1 && phl_ready)
//            enable_network_layer();
//        else
//            disable_network_layer();
//   }
}
