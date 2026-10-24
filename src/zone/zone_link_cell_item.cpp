#pragma exceptions off

#include "zone_link_cell_item.h"

extern "C" {
void *func_1D0DC0(void *self, int size_level);
void func_1D0EC0(void *self, void *bucket, void *buffer);
void *func_117AF8(void *dest, void *src, int n);
}

extern "C" void func_001D0CB0(void *self, void *cell, void *item) {
    char *c = (char *)cell;
    int num_items = *(unsigned char *)(c + 0xD);
    char *zm = (char *)self;

    if (num_items == 0) {
        void **new_list = (void **)func_1D0DC0(self, 0);
        *(void ***)(c + 0x14) = new_list;
        new_list[0] = item;
        c[0xD] = 1;
        return;
    }

    char *lookup = *(char **)(zm + 0x8F00);
    int bucket_level = (unsigned char)lookup[num_items];

    if (num_items < 250) {
        void **items_list = *(void ***)(c + 0x14);
        int next_level = (unsigned char)lookup[num_items + 1];

        if (bucket_level != next_level) {
            void **new_list = (void **)func_1D0DC0(self, bucket_level + 1);
            func_117AF8(new_list, items_list, num_items * 4);

            char *bucket_desc = zm + 0x8F24 + bucket_level * 68;
            func_1D0EC0(self, *(void **)(bucket_desc + 0x2C), items_list);

            *(void ***)(c + 0x14) = new_list;
        }

        void **cur_list = *(void ***)(c + 0x14);
        cur_list[num_items] = item;
        c[0xD] = (char)(num_items + 1);
    }
}
