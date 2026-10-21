#include "network_receiver_337B30.h"

extern int D_004E352C;
extern int D_004E3538;
extern int D_004E353C;
extern int D_004E3540;
extern int D_004E3544;
extern int D_004E3550;
extern int D_004E3554;
extern int D_004E3558;
extern int D_004E355C;

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
    unsigned int word = (unsigned int)value;
    return (int)((word >> 24) | ((word >> 8) & 0x0000FF00) |
                 ((word << 8) & 0x00FF0000) | (word << 24));
}

extern "C" void func_00337B30(void) {
    func_118de0(D_004D1F20);
    while (1) {
        if (D_004E352C != 0) {
            int received = func_388E60(D_004E353C, ring_packet(D_004E3558), 492, 0);
            if (received != 492) continue;
            func_003378D0(ring_packet(D_004E3558));
            D_004E3558 = (D_004E3558 + 1) & 15;
            ++D_004E355C;
            continue;
        }
        int address[4];
        int address_length = 16;
        int received = func_388F90(D_004E353C, ring_packet(D_004E3558), 492, 0,
                                   address, &address_length);
        if (received != 492) continue;
        if (address[0] == D_004E3540 && address[1] == D_004E3544) continue;
        func_118de0(D_004D1F38);
        D_004E3550 = address[0];
        D_004E3554 = address[1];
        address[0] = swap_address_word(address[0]);
        address[1] = swap_address_word(address[1]);
        int connected = func_388CC0(D_004E3538, address, 16);
        if (connected == 0) {
            D_004E352C = 1;
            ++D_004E355C;
            ++D_004E3558;
            D_004E3558 &= 15;
            func_118de0(D_004D1F40, D_004E3558, D_004E3550, D_004E3554);
            continue;
        }
        D_004E3554 = 0;
        D_004E3550 = 0;
    }
}
