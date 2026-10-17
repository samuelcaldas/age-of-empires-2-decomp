#pragma exceptions off

#include "zone_unlink_entity.h"

extern "C" {
void func_1D0EC0(void *self, void *bucket, void *buffer);
void *func_1D0DC0(void *self, int size_level);
void *func_117AF8(void *dest, void *src, int n);
}

extern "C" void func_001D0B40(void *self, void *cell, void *item_to_remove) {
    char *c = (char *)cell;
    int num_items = *(unsigned char *)(c + 0xD);
    if (num_items <= 0) {
        return;
    }

    char *zm = (char *)self;
    char *lookup = *(char **)(zm + 0x8F00);
    int bucket_level = (unsigned char)lookup[num_items];

    void **items_list = *(void ***)(c + 0x14);

    for (int i = 0; i < num_items; i++) {
        if (items_list[i] == item_to_remove) {
            num_items--;
            if (i < num_items) {
                items_list[i] = items_list[num_items];
            }

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
                return;
            } else {
                c[0xD] = (char)num_items;
                return;
            }
        }
    }
}
