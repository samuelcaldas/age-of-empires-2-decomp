#pragma exceptions off
#include "unit_action_tile_node.h"

void func_00269D80(void *node, int a1, int a2) {
    if (node == 0) {
        return;
    }
    short field60 = *(short*)((char*)node + 0x60);
    if (field60 == -1) {
        return;
    }
    void *f8 = *(void**)((char*)node + 8);
    void *f4 = *(void**)((char*)node + 4);
    func_003357B0(f4, field60);
    func_00335920(f8, field60);
    func_00334FC0(f4, field60);
    *(short*)((char*)node + 0x60) = -1;
}

unsigned char func_00269E50(ActionRebind *self, int tile_x, int tile_y) {
    if (self == 0) {
        return 0;
    }
    (void)tile_x; (void)tile_y;
    short field60 = *(short*)((char*)self + 0x60);
    if (field60 != -1) {
        void *f8 = *(void**)((char*)self + 8);
        void *f4 = *(void**)((char*)self + 4);
        func_003357B0(f4, field60);
        func_00335920(f8, field60);
        func_00334FC0(f4, field60);
    }
    *(short*)((char*)self + 0x60) = (short)tile_x;
    return 1;
}

int func_00269F30(ActionRebind *self, int curr_type, int target_type) {
    if (self == 0) {
        return 0;
    }
    (void)curr_type; (void)target_type;
    short field60 = *(short*)((char*)self + 0x60);
    if (field60 != -1) {
        void *f8 = *(void**)((char*)self + 8);
        void *f4 = *(void**)((char*)self + 4);
        func_003357B0(f4, field60);
        func_00335920(f8, field60);
        func_00334FC0(f4, field60);
        *(short*)((char*)self + 0x60) = -1;
    }
    return 1;
}
