#include "network_receiver_337B30.h"

extern int D_004E356C;
extern int D_004E3578;
extern int D_004E357C;
extern int D_004E3580;
extern int D_004E3584;
extern int D_004E3590;
extern int D_004E3594;
extern int D_004E3598;
extern int D_004E359C;

extern "C" {
    extern const char D_004D1F20[];
    extern const char D_004D1F38[];
    extern const char D_004D1F40[];
    int func_118de0(const char *format, ...);
    int func_003378D0(void *packet);
    int func_388E60(int socket, void *buffer, int size, int flags);
    int func_388F90(int socket, void *buffer, int size, int flags, void *address, int *length);
    int func_388CC0(int socket, void *address, int length);
}

static int *ring_packet(int index) {
    return (int *)(0x010890E0 + index * 492);
}

static int swap_address_word(int value) {
    return (value >> 24) | ((value >> 8) & 0x0000FF00) |
           ((value << 8) & 0x00FF0000) | (value << 24);
}

extern "C" void func_00337B30(void) {
    func_118de0(D_004D1F20);
    while (1) {
        if (D_004E356C != 0) {
            int received = func_388E60(D_004E357C, ring_packet(D_004E3598), 492, 0);
            if (received != 492) continue;
            func_003378D0(ring_packet(D_004E3598));
            D_004E3598 = (D_004E3598 + 1) & 15;
            ++D_004E359C;
            continue;
        }
        int address[4];
        int address_length = 16;
        int received = func_388F90(D_004E357C, ring_packet(D_004E3598), 492, 0,
                                   address, &address_length);
        if (received != 492) continue;
        if (address[0] == D_004E3580 && address[1] == D_004E3584) continue;
        func_118de0(D_004D1F38);
        D_004E3590 = address[0];
        D_004E3594 = address[1];
        address[0] = swap_address_word(address[0]);
        address[1] = swap_address_word(address[1]);
        int connected = func_388CC0(D_004E3578, address, 16);
        if (connected == 0) {
            D_004E356C = 1;
            ++D_004E359C;
            ++D_004E3598;
            D_004E3598 &= 15;
            func_118de0(D_004D1F40, D_004E3598, D_004E3590, D_004E3594);
            continue;
        }
        D_004E3594 = 0;
        D_004E3590 = 0;
    }
}
