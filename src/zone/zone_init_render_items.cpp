#pragma exceptions off

#include "zone_init_render_items.h"

extern "C" {
void *func_25F2B0(int size);
void func_25DBF0(void *item, void *template_item);
}

extern "C" void func_001D1430(void *self, void *template_source) {
    char *zm = (char *)self;
    char *high = zm + 0x10000;
    *(void **)(high - 0x6FCC) = template_source;

    for (int i = 0; i < 17; i++) {
        char *entry = zm + i * 4 + 0x10000;
        *(int *)(entry - 0x6FB8) = 0;
        *(int *)(entry - 0x6F74) = 0;
        *(int *)(entry - 0x6F30) = 0;
    }

    *(int *)(high - 0x6FC8) = 0;
    *(int *)(high - 0x6FC0) = 0x190;
    *(int *)(high - 0x6FC0) = 0;
    *(int *)(high - 0x6FC8) = 1;
    *(int *)(high - 0x6FBC) = 0;
    *(int *)(high - 0x6FC4) = 0;

    for (int i = 0; i < 17; i++) {
        void *item = func_25F2B0(0x14);
        if (item != 0) {
            void *template_item = *(void **)(*(char **)(high - 0x6FCC) + 0x26F4 + i * 4);
            func_25DBF0(item, template_item);
        }
        *(void **)(zm + i * 4 + 0x10000 - 0x6EEC) = item;
    }
}
