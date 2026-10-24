#pragma exceptions off

#include "zone_spatial_pyramid_destroy.h"

extern "C" {
void func_100630(void *ptr);
void func_100670(void *ptr);
}

extern "C" void *func_001D1FB0(void *self, int flag) {
    char *zm = (char *)self;
    if (zm == 0) {
        return 0;
    }

    void *ptr_9c = *(void **)(zm + 0x9C);
    if (ptr_9c != 0) {
        func_100630(ptr_9c);
    }

    void ***root = *(void ****)(zm + 0x0);
    if (root != 0) {
        for (int i = 0; i < 4; i++) {
            int level_count = *(int *)(zm + 0xA4 + i * 4);
            void **level_array = root[i];
            for (int j = 0; j < level_count; j++) {
                func_100630(level_array[j]);
            }
            func_100630(level_array);
        }
        func_100630(root);
    }

    while (*(void **)(zm + 0x80) != 0) {
        void *node = *(void **)(zm + 0x80);
        *(void **)(zm + 0x80) = *(void **)((char *)node + 0x20);
        func_100670(node);
    }

    if ((short)flag > 0) {
        func_100670(zm);
    }

    return zm;
}
