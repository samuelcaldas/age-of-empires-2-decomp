#pragma exceptions off

#include "zone_spatial_node_cleanup.h"

extern "C" {
void *func_1D1FB0(void *pyramid, int flag);
void func_100630(void *ptr);
void func_1EE700(void *mgr, void *code, int flag);
}

extern "C" void func_001D7B20(void *self) {
    char *p = (char *)self;
    int count = *(int *)(p + 4);

    if (count > 0) {
        void **items = *(void ***)(p + 0);
        for (int i = 0; i < count; i++) {
            func_1D1FB0(items[i], 1);
        }
        func_100630(items);
        *(void **)(p + 0) = 0;
    }

    *(int *)(p + 4) = 0;
}
