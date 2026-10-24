#include "network_dplay_3380e0.h"

extern "C" {
    extern const char D_00492C50[];
    extern const char D_004D20F0[];
}

extern "C" int func_00338140(int (*callback)(const void *, const char *, int, int, void *), void *context) {
    callback(D_00492C50, D_004D20F0, 6, 0, context);
    return 0;
}
