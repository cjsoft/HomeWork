#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "protocol.h"
#include "datalink.h"
#ifndef DATA_TIMER
    #define DATA_TIMER  2000
#endif
#ifndef ACK_TIMER
    #define ACK_TIMER   300
#endif
#define MAX_SEQ 7
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
    unsigned char kind;
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
    if (kind & DATA_MASK) memcpy(s.data, buffer[frame_nr % (MAX_SEQ + 1)].data, sizeof(s.data));
    if (kind & NAK_MASK) no_nak = false;
    s.seq = frame_nr;
    s.ack = (frame_expected + MAX_SEQ) % (MAX_SEQ + 1);
    if (kind & DATA_MASK) {
        put_frame((unsigned char *) &s, sizeof(FRAME) - 4);
        start_timer(frame_nr % (MAX_SEQ + 1), DATA_TIMER);
    } else if (kind & SHORTFRM_MASK) {
        dbg_frame("Sending short frame %s for %d.\n", (kind == ACK) ? "ACK" : "NAK", frame_expected);
        put_frame((unsigned char *) &s, 2);
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
packet buffer[MAX_SEQ + 1];
seq_nr nbuffered;
seq_nr i;
event_type event;
int arg;
extern int debug_mask;
int main(int argc, char **argv)
{
    protocol_init(argc, argv);
    lprintf("Designed by CJSoft, build: " __DATE__"  "__TIME__"\n");

    disable_network_layer();
//    enable_network_layer();
    ack_expected = 0;
    next_frame_to_send = 0;
    frame_expected = 0;
    nbuffered = 0;
    while (1) {
        event = wait_for_event(&arg);
        switch (event) {
            case NETWORK_LAYER_READY:
                get_packet((unsigned char *)&(buffer[next_frame_to_send].data));
                nbuffered++;
                send_data_frame(DATA, next_frame_to_send, frame_expected, buffer);
                dbg_frame("Data %d is sent, with ACK %d.\n", next_frame_to_send, frame_expected);
                inc(next_frame_to_send);
                break;
            case FRAME_RECEIVED:
                len = recv_frame((unsigned char *)&r, sizeof(r));
                if (len < 5 || crc32((unsigned char *)&r, len) != 0) {
                    dbg_event("**** Receiver Error, Bad CRC Checksum\n");
                    goto BAD_CRC_CHECKSUM;
                }
                if (r.kind & DATA_MASK) {
                    if (r.seq == frame_expected) {
                        dbg_frame("Frame accepted! %d-%d\n", r.kind, r.seq);
                        put_packet(r.data, PKT_LEN);
                        inc(frame_expected);
                        start_ack_timer(ACK_TIMER);
                    } else {
                        dbg_warning("Incorrect seq, discarding %d\n", r.seq);
                    }
                }
                if (r.kind & ACK_MASK) {
                    while (between(ack_expected, r.ack, next_frame_to_send)) {
                        nbuffered--;
                        stop_timer(ack_expected);
                        inc(ack_expected);
                    }

                }

                break;
            case PHYSICAL_LAYER_READY:
                phl_ready = 1;
                break;
            case DATA_TIMEOUT:
                dbg_frame("---- DATA %d timeout, resending DATA\n", arg);
                next_frame_to_send = ack_expected;
                for (i = 1; i <= nbuffered; i++) {
                    send_data_frame(DATA, next_frame_to_send, frame_expected, buffer);
                    inc(next_frame_to_send);
                }
                break;
            case ACK_TIMEOUT:
                send_data_frame(ACK, 0, frame_expected, buffer);
                break;
            BAD_CRC_CHECKSUM:;
//                send_data_frame(NAK, 0, frame_expected, buffer);
        }
        if (nbuffered < MAX_SEQ && phl_ready) enable_network_layer();
        else disable_network_layer();
    }
}
