#include <cassert>
#include "network_address_helpers.h"

extern "C" {
const char D_004D1E88[] = "%d.%d.%d.%d";
const char D_004D1EA0[] = "%8d.%8d.%8d.%8d";
const signed char D_0049E101[256] = {0};
char D_01087EB0[64];
int func_11A498(char *destination, const char *format, ...) {
    (void)destination; (void)format; return 0;
}
int func_11A510(const char *text, const char *format, ...) {
    (void)text; (void)format; return 0;
}
}

int main() {
    assert(func_00337520(0x12345678u) == 0x78563412u);
    assert(func_00337520(0xFF000080u) == 0x800000FFu);
    assert(func_00337590(0x12345678u) == 0x78563412u);
    assert(func_00337560(0x12345678u) == 0x7856u);
    assert(func_003375D0(0x12345678u) == 0x7856u);
    return 0;
}
