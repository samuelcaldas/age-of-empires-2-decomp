#pragma exceptions off

#include "zone_cleanup_render_items.h"

extern "C" {
void func_25DE30(void *item, int flag);
void *func_117CAC(void *heap, int flag, int size);
}

extern "C" void func_001D1560(void *self) {
    char *zm = (char *)self;
    if (*(void **)(zm + 0x903C) == 0) {
        return;
    }

    for (int i = 0; i < 17; i++) {
        void **item_ptr = *(void ***)(zm + 0x90D0 + i * 4);
        while (item_ptr != 0) {
            void *item = item_ptr[0];
            func_25DE30(item, 1);
            item_ptr[0] = 0;
            item_ptr = (void **)item_ptr[1];
        }
    }

    int count = *(int *)(zm + 0x9044);
    char *items_buf = *(char **)(zm + 0x903C);

    for (int i = 0; i < count; i++) {
        char *entry = *(char **)(items_buf + i * 8);
        if (entry != 0) {
            void *sub_item = *(void **)(entry + 0x10);
            func_25DE30(sub_item, 1);
            *(void **)(*(char **)(items_buf + i * 8) + 0x10) = 0;
        }
    }

    for (int i = 0; i < 17; i++) {
        *(int *)(zm + 0x9048 + i * 4) = 0;
        *(int *)(zm + 0x908C + i * 4) = 0;
        *(int *)(zm + 0x90D0 + i * 4) = 0;
    }

    int total_words = *(int *)(zm + 0x9040);
    func_117CAC(*(void **)(zm + 0x903C), 0, total_words * 8);
    *(int *)(zm + 0x9044) = 0;
}
