#pragma exceptions off

#include "zone_unlink_cell_item.h"

extern "C" {
void func_1D0EC0(void *self, void *bucket, void *buffer);
void *func_1D0DC0(void *self, int size_level);
void *func_117AF8(void *dest, void *src, int n);
}

typedef void (*UnlinkItemFn)(void *item);

extern "C" void func_001D09C0(void *self, void *cell, int index) {
    char *c = (char *)cell;
    int num_items = *(unsigned char *)(c + 0xD);
    if (num_items <= 0 || index >= num_items) {
        return;
    }

    char *zm = (char *)self;
    char *lookup = *(char **)(zm + 0x8F00);
    int bucket_level = (unsigned char)lookup[num_items];

    c[0xF] = 1;

    void **items_list = *(void ***)(c + 0x14);
    void *item = items_list[index];
    if (item != 0) {
        void **vtable = *(void ***)item;
        ((UnlinkItemFn)vtable[2])(item);
    }

    num_items--;

    if (index < num_items) {
        items_list[index] = items_list[num_items];
    }

    c[0xF] = 0;

    if (num_items == 0) {
        char *bucket_desc = zm + 0x8F24 + bucket_level * 68;
        func_1D0EC0(self, *(void **)(bucket_desc + 0x2C), items_list);
        c[0xD] = 0;
        return;
    }

    int next_level = (unsigned char)lookup[num_items];
    if (next_level != bucket_level) {
        void *new_list = func_1D0DC0(self, bucket_level - 1);
        func_117AF8(new_list, items_list, num_items * 4);

        char *bucket_desc = zm + 0x8F24 + bucket_level * 68;
        func_1D0EC0(self, *(void **)(bucket_desc + 0x2C), items_list);

        *(void **)(c + 0x14) = new_list;
        c[0xD] = (char)num_items;
    } else {
        c[0xD] = (char)num_items;
    }
}
