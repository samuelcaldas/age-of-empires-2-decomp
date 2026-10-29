#pragma exceptions off

#include "zone_destroy_render_items.h"

extern "C" {
void func_001D1560(void *self);
void func_00100670(void *ptr);
void func_25DE30(void *item, int flag);
}

extern "C" void func_001D16D0(void *self) {
    char *zm = (char *)self;
    func_001D1560(self);

    char *high = zm + 0x10000;
    void *buf = *(void **)(high - 0x6FC4);
    if (buf != 0) {
        func_00100670(buf);
        *(void **)(high - 0x6FC4) = 0;
    }

    int i = 0;
    while (i < 17) {
        void **item_slot = (void **)(zm + 0x111C + 0x7FF8 + i * 4);
        void *item = *item_slot;
        if (item != 0) {
            func_25DE30(item, 1);
        }
        *item_slot = 0;
        i++;
    }

    *(int *)(high - 0x6FC0) = 0;
    *(int *)(high - 0x6FBC) = 0;
    *(void **)(high - 0x6FCC) = 0;
}
