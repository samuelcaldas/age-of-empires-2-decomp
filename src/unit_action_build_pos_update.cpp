#pragma exceptions off
#include "unit_action_build_pos_update.h"

float func_0026F9E0(ActionRebind *self, float x, float y, float z) {
    if (*(int*)((char*)self + 24) != 0 && *(void**)((char*)self + 304) == 0) {
        void *master = *(void**)((char*)self + 4);
        float px = *(float*)((char*)self + 68);
        float py = *(float*)((char*)self + 72);
        float ex = *(float*)((char*)master + 32);
        float ey = *(float*)((char*)master + 36);

        int min_x = func_123350(px - ex);
        int min_y = func_123350(py - ey);
        int max_x = func_123350((px + ex) - 0.01f);
        int max_y = func_123350((py + ey) - 0.01f);

        void *world = *(void**)((char*)self + 8);
        void *map = *(void**)(*(char**)((char*)world + 2968) + 60);
        func_1CA430(map, min_x, min_y, max_x, max_y);
    }

    float ret = func_197E40(self, x, y, z);

    if (*(int*)((char*)self + 24) != 0 && *(void**)((char*)self + 304) == 0) {
        float px = *(float*)((char*)self + 68);
        float py = *(float*)((char*)self + 72);
        int tile_x = func_123350(px);
        int tile_y = func_123350(py);

        void *master = *(void**)((char*)self + 4);
        float ex = *(float*)((char*)master + 32);
        float ey = *(float*)((char*)master + 36);

        int min_x = func_123350(px - ex);
        int min_y = func_123350(py - ey);
        int max_x = func_123350((px + ex) - 0.01f);
        int max_y = func_123350((py + ey) - 0.01f);

        void *world = *(void**)((char*)self + 8);
        void *map = *(void**)(*(char**)((char*)world + 2968) + 60);

        func_1CA180(map, tile_x, tile_y, min_x, min_y, max_x, max_y);
        char res = func_1CA7F0(map, tile_x, tile_y, min_x, min_y, max_x, max_y);
        *(char*)((char*)self + 198) = res;

        int rad = func_123350(0.5f + (ex + ey) / 2.0f);
        *(char*)((char*)self + 199) = (char)rad;
    }

    return ret;
}
