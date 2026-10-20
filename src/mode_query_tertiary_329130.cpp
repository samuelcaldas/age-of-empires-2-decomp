
#include "mode_query_tertiary_329130.h"

extern "C" {
int func_00329130(void *self, int a1, int a2) {
    if (!D_004E2EA0) {
        return 0;
    }
    short x;
    short y;
    int extra;
    int res = 0;
    if (func_1A5010(self, a1, a2, &x, &y, &extra)) {
        SecondarySubsystem *mgr = *(SecondarySubsystem **)((char *)self + 0x120);
        float h = 0.5f;
        res = (unsigned char)mgr->query(0, h + x, h + y);
    }
    ((GlobalContextNotify *)D_004E3180)->notify(0, 0);

    return res;
}
}
