#include "network_dplay_3380e0.h"

extern char D_01087ED0[];

extern "C" int func_00338CC0(void *self, const void *riid, void **ppvObj) {
    (void)riid;
    *ppvObj = D_01087ED0;
    char *base = static_cast<char *>(self);
    base[4560]++;
    return 0;
}
