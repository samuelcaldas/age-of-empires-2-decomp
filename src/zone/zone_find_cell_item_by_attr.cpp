#pragma exceptions off

#include "zone_find_cell_item_by_attr.h"

extern "C" void *func_001D1100(void *self, void *cell, int target_attr) {
    int i = 0;
    while (i < *(unsigned char *)((char *)cell + 0xD)) {
        void *item = *(void **)(*(char **)((char *)cell + 0x14) + (i << 2));
        if (*(short *)(*(char **)((char *)item + 0x4) + 0xE) == target_attr) {
            return item;
        }
        i++;
    }
    return 0;
}
