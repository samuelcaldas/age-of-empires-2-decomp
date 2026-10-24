#pragma exceptions off

#include "zone_init_render_items.h"

extern "C" {
void *func_25F2B0(int size);
void func_25DBF0(void *item, void *template_item);
}

extern "C" void func_001D1430(void *self, void *template_source) {
    char *zm = (char *)self;
    *(void **)(zm + 0x9034) = template_source;

    for (int i = 0; i < 17; i++) {
        *(int *)(zm + 0x9048 + i * 4) = 0;
        *(int *)(zm + 0x908C + i * 4) = 0;
        *(int *)(zm + 0x90D0 + i * 4) = 0;
    }

    *(int *)(zm + 0x9038) = 0;
    *(int *)(zm + 0x9040) = 400;
    *(int *)(zm + 0x9040) = 0;
    *(int *)(zm + 0x9038) = 1;
    *(int *)(zm + 0x9044) = 0;
    *(int *)(zm + 0x903C) = 0;

    for (int i = 0; i < 17; i++) {
        void *item = func_25F2B0(0x14);
        if (item != 0) {
            void *template_item = *(void **)((char *)template_source + 0x26F4 + i * 4);
            func_25DBF0(item, template_item);
        }
        *(void **)(zm + 0x9114 + i * 4) = item;
    }
}
