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

    void *buf = *(void **)(zm + 0x903C);
    if (buf != 0) {
        func_00100670(buf);
        *(void **)(zm + 0x903C) = 0;
    }

    for (int i = 0; i < 17; i++) {
        void **item_slot = (void **)(zm + 0x9114 + i * 4);
        void *item = *item_slot;
        if (item != 0) {
            func_25DE30(item, 1);
        }
        *item_slot = 0;
    }

    *(int *)(zm + 0x9040) = 0;
    *(int *)(zm + 0x9044) = 0;
    *(void **)(zm + 0x9034) = 0;
}
