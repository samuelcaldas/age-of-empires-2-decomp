#pragma exceptions off

#include "zone_find_cell_item_by_attr.h"

extern "C" void *func_001D1100(void *self, void *cell, int target_attr) {
    char *c = (char *)cell;
    int num_items = *(unsigned char *)(c + 0xD);
    void **items_list = *(void ***)(c + 0x14);

    for (int i = 0; i < num_items; i++) {
        void *item = items_list[i];
        void *info = *(void **)((char *)item + 0x4);
        short attr = *(short *)((char *)info + 0xE);

        if (attr == (short)target_attr) {
            return item;
        }
    }

    return 0;
}
