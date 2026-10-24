#pragma exceptions off
#include "unit_action_build_tile_notify.h"

void func_0026F8A0(ActionRebind *self) {
    int tile_x;
    int tile_y;
    int res = func_26A700(self, &tile_x, &tile_y);
    if (res != 0) {
        void *world = *(void**)((char*)self + 8);
        void *p2968 = *(void**)((char*)world + 2968);
        void *p68 = *(void**)((char*)p2968 + 68);
        void *target = *(void**)((char*)p68 + 1628);
        if (target != 0) {
            func_25F6E0(target, 1, tile_x, tile_y, -1, -1);
        }
    }
}
