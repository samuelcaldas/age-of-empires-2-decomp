#pragma exceptions off
#include "zone_spatial_grid_query_ray_intersection.h"

extern "C" {
int func_00123350(float val);
int func_269E50(void *grid_obj, int ix, int iy);
}

extern "C" void *func_001EC360(
    void *cell,
    int target_type,
    int filter_flag,
    int param_mode,
    void *grid_obj,
    float x,
    float y
) {
    int s2;
    if (x <= -1.0f || y <= -1.0f) {
        s2 = -1;
    } else if (grid_obj == 0) {
        s2 = -1;
    } else {
        int ix = func_00123350(x);
        int iy = func_00123350(y);
        s2 = (unsigned char)func_269E50(grid_obj, ix, iy);
    }

    void *best_item = 0;
    float min_dist = -1.0f;

    for (int i = 0; i < *(short *)((char *)cell + 0x4); i++) {
        void *item = (*(void ***)((char *)cell + 0x0))[i];
        void *info = *(void **)((char *)item + 0x4);
        if (*(short *)((char *)info + 0x8) != (short)target_type) {
            continue;
        }

        if (filter_flag != 0) {
            if (*(unsigned char *)((char *)item + 0x39) != (unsigned char)param_mode) {
                continue;
            }
        }

        if (-1.0f == x && -1.0f == y) {
            return item;
        }

        if (s2 >= 0) {
            int item_ix = func_00123350(*(float *)((char *)item + 0x44));
            int item_iy = func_00123350(*(float *)((char *)item + 0x48));
            if (s2 != (unsigned char)func_269E50(grid_obj, item_ix, item_iy)) {
                continue;
            }
        }

        float dx = x - *(float *)((char *)item + 0x44);
        float dy = y - *(float *)((char *)item + 0x48);
        float dist = dx * dx + dy * dy;

        if (-1.0f == min_dist || dist < min_dist) {
            min_dist = dist;
            best_item = item;
        }
    }

    return best_item;
}
