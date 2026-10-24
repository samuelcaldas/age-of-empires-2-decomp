#pragma exceptions off

#include "zone_free_spatial_grid.h"

extern "C" {
void func_100630(void *ptr);
void *func_117CAC(void *heap, int flag, int size);
}

extern "C" void func_001D06A0(void *self) {
    char *zm = (char *)self;
    if (*(int *)(zm + 0x8EFC) == 0) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        char *bucket = zm + 0x8F24 + i * 68;

        int count = *(int *)(bucket + 0x10);
        void **items = *(void ***)(bucket + 0x0);
        if (items != 0) {
            for (int j = 0; j < count; j++) {
                if (items[j] != 0) {
                    func_100630(items[j]);
                }
            }
        }

        void *buf1 = *(void **)(bucket + 0x2C);
        if (buf1 != 0) {
            func_100630(buf1);
        }

        void *buf2 = *(void **)(bucket + 0x34);
        if (buf2 != 0) {
            func_100630(buf2);
        }

        *(void **)(bucket + 0x2C) = 0;
        *(void **)(bucket + 0x34) = 0;
    }

    func_117CAC((void *)0x8CEEC0, 0, 251);
    *(void **)(zm + 0x8F00) = 0;
    *(int *)(zm + 0x8EFC) = 0;
}
