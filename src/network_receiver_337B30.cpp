#include "network_receiver_337B30.h"

extern int D_010890C0[4];
extern int D_010890E0[16][123];
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

static inline int *ring_packet(int index) {
    return D_010890E0[index];
}

static inline int swap_address_word(int value) {
    unsigned int word = (unsigned int)value;
    return (int)((word >> 24) | ((word << 24) |
                 (((word >> 8) & 0xFF00) | ((word & 0xFF00) << 8))));
}

extern "C" void func_00337B30(void) {
    func_118de0(D_004D1F20);
    while (1) {
        if (D_004E352C != 0) {
            int received = func_388E60(D_004E353C, ring_packet(D_004E3558), 492, 0);
            if (received != 492) continue;
            func_003378D0(ring_packet(D_004E3558));
            ++D_004E355C;
            D_004E3558 = (D_004E3558 + 1) & 15;
            continue;
        }
        int address[4];
        int address_length = 16;
        int received = func_388F90(D_004E353C, ring_packet(D_004E3558), 492, 0,
                                   address, &address_length);
        if (received != 492) continue;
        if (address[1] == D_004E3540 && address[2] == D_004E3544) continue;
        func_118de0(D_004D1F38);
        D_010890C0[1] = address[1];
        D_010890C0[2] = address[2];
        D_004E3550 = swap_address_word(D_010890C0[1]);
        D_004E3554 = swap_address_word(D_010890C0[2]);
        int connected = func_388CC0(D_004E3538, D_010890C0, 16);
        if (connected == 0) {
            D_004E352C = 1;
            ++D_004E355C;
            D_004E3558 = (D_004E3558 + 1) & 15;
            func_118de0(D_004D1F40, D_004E3550, D_004E3554);
            continue;
        }
        D_004E3554 = 0;
        D_004E3550 = 0;
    }
}
