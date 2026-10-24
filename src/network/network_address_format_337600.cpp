#include "network_address_helpers.h"

#pragma optimization_level 1

extern "C" {
extern const char D_004D1E88[];
extern char D_01087EB0[];
int func_11A498(char *destination, const char *format, ...);
}

char *func_00337600(unsigned int address) {
    union {
        unsigned int address;
        unsigned char bytes[4];
    } u;
    unsigned int b0;
    unsigned int v;
    u.address = address;
    b0 = u.bytes[0];
    v = u.address;
    func_11A498(D_01087EB0, D_004D1E88,
        b0, (v >> 8) & 0xFF,
        (v >> 16) & 0xFF, (v >> 24) & 0xFF);
    return D_01087EB0;
}
