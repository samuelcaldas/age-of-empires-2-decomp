#include "network_dplay_3380e0.h"

extern "C" int func_003391E0(void *self, void *caps, int flags) {
    (void)flags;
    int *out = static_cast<int *>(caps);
    out[9] = 60;
    out[4] = 8;
    out[1] = 64;
    if (*reinterpret_cast<int *>(static_cast<char *>(self) + 1312) != 0) {
        out[1] |= 2;
    }
    return 0;
}
