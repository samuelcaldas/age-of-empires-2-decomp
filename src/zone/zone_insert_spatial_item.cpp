#pragma exceptions off

#include "zone_insert_spatial_item.h"

extern "C" {
int func_123350(float f);
int func_269E50(void *grid_obj, int ix, int iy);
}

extern "C" void *func_001D0F00(
    void *self,
    void *cell,
    int target_type,
    int filter_flag,
    int param_mode,
    void *grid_obj,
    float x,
    float y
) {
    int s2 = -1;
    if (x > -1.0f && y > -1.0f) {
        if (grid_obj != 0) {
            int ix = func_123350(x);
            int iy = func_123350(y);
            s2 = (unsigned char)func_269E50(grid_obj, ix, iy);
        }
    }

    char *c = (char *)cell;
    int num_items = *(unsigned char *)(c + 0xD);
    void **items_list = *(void ***)(c + 0x14);

    void *best_item = 0;
    float min_dist = -1.0f;

    for (int i = 0; i < num_items; i++) {
        void *item = items_list[i];
        void *info = *(void **)((char *)item + 0x4);
        short type = *(short *)((char *)info + 0x8);

        if (type != (short)target_type) {
            continue;
        }

        if (filter_flag != 0) {
            if (*(unsigned char *)((char *)item + 0x39) != (unsigned char)param_mode) {
                continue;
            }
        }

        if (x == -1.0f && y == -1.0f) {
            return item;
        }

        if (s2 >= 0) {
            float item_x = *(float *)((char *)item + 0x44);
            float item_y = *(float *)((char *)item + 0x48);
            int item_ix = func_123350(item_x);
            int item_iy = func_123350(item_y);
            int item_s2 = (unsigned char)func_269E50(grid_obj, item_ix, item_iy);
            if (s2 != item_s2) {
                continue;
            }
        }

        float ix = *(float *)((char *)item + 0x44);
        float iy = *(float *)((char *)item + 0x48);
        float dx = x - ix;
        float dy = y - iy;
        float dist = dx * dx + dy * dy;

        if (min_dist == -1.0f || dist < min_dist) {
            min_dist = dist;
            best_item = item;
        }
    }

    return best_item;
}
