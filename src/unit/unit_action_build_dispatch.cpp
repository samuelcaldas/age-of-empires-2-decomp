#pragma exceptions off
#include "unit_action_build_dispatch.h"

static int check_world_state(ActionRebind *self) {
    float f1 = *(float*)((char*)self + 368);
    if (f1 != 0.0f) {
        return 1;
    }

    void *sing = D_004E3180;
    func_186010(sing);
    void *world = *(void**)((char*)self + 8);
    typedef void* (*Method36Fn)(void *w, int pcount);
    void *w_vt = *(void**)((char*)world + 6960);
    Method36Fn m36 = *(Method36Fn*)((char*)w_vt + 36);
    int pcount = *(int*)((char*)world + 2976);
    void *res = m36(world, pcount);
    if (res == 0) {
        return 0;
    }

    func_186010(sing);
    w_vt = *(void**)((char*)res + 6960);
    m36 = *(Method36Fn*)((char*)w_vt + 36);
    void *res2 = m36(res, *(int*)((char*)world + 2976));
    if (res2 == 0) {
        return 0;
    }

    return 1;
}

void func_00270F80(ActionRebind *self, int a1, int a2, int a3, int t0) {
    unsigned char flag = *(unsigned char*)((char*)self + 57);
    if (flag == 0) {
        if (check_world_state(self) == 0) {
            return;
        }
    }

    func_00270E30(self);
    func_00264450(self, a1, a2, a3, t0);
}
