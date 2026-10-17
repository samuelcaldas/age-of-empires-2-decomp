#pragma exceptions off
#include "unit_action_build_5a40.h"

extern "C" {
    int func_123350(float val);
    int func_801CF350(void *map, int tile_x, int tile_y, int flag);
    void func_802697B0(void *self, int val);
}

typedef int (*VtablePassableMethod)(void *self, int tile_x, int tile_y);

static bool check_corner_passability(void *self, void *map, int tx, int ty) {
    if (func_801CF350(map, tx, ty, 0) == 0) {
        return false;
    }
    void **vtbl = *(void ***)self;
    VtablePassableMethod fn = (VtablePassableMethod)vtbl[45]; // offset
    return fn(self, tx, ty) != 0;
}

int func_275A40(void *self, void *target, void *arg2) {
    float x1 = *(float *)((char *)self + 0x44);
    float y1 = *(float *)((char *)self + 0x48);
    float x2 = *(float *)((char *)target + 0x44);
    float y2 = *(float *)((char *)target + 0x48);

    int tx1 = func_123350(x1);
    int ty1 = func_123350(y1);
    int tx2 = func_123350(x2);
    int ty2 = func_123350(y2);

#if defined(__LP64__) || defined(_LP64)
    void *owner = *(void **)((char *)self + 0x10);
#else
    void *owner = *(void **)((char *)self + 0x8);
#endif
    void *map = *(void **)((char *)owner + 0x70);

    if (!check_corner_passability(self, map, tx1, ty1)) return 0;
    if (!check_corner_passability(self, map, tx2, ty1)) return 0;
    if (!check_corner_passability(self, map, tx1, ty2)) return 0;
    if (!check_corner_passability(self, map, tx2, ty2)) return 0;

    func_802697B0(self, 1);
    return 1;
}
