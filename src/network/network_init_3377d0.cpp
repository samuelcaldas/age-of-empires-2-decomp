#include "network_init_3377d0.h"

extern int D_004E3568;
extern "C" int func_003379F0(int value);

void func_003377D0(int enabled) {
    if (enabled == 0) {
        for (int index = 0; index < 3; ++index) {
            func_003379F0(0);
        }
    }
    D_004E3568 = enabled;
}
