#include "network_address_helpers.h"

extern "C" {
extern const char D_004D1E88[];
extern char D_01087EB0[];
int func_11A498(char *destination, const char *format, ...);
}

char *func_00337600(unsigned int address) {
    func_11A498(D_01087EB0, D_004D1E88,
        address & 0xFFu, (address >> 8) & 0xFFu,
        (address >> 16) & 0xFFu, (address >> 24) & 0xFFu);
    return D_01087EB0;
}
