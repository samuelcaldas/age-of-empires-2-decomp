#include "network_dplay_3380e0.h"

extern "C" int func_00338C60(void *self) {
    char *base = static_cast<char *>(self);
    if (base[4560] != 0) {
        base[4560]--;
    }
    if (base[4560] == 0) {
        func_00338180(base);
        func_003381A0(base);
    }
    return base[4560];
}
