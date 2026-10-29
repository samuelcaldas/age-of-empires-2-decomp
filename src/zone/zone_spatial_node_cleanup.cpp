#pragma exceptions off

#include "zone_spatial_node_cleanup.h"

extern "C" {
void *func_001D1FB0(void *pyramid, int flag);
void func_100630(void *ptr);
void func_1EE700(void *mgr, void *code, int flag);
void func_001D7E70(void);
extern void *D_4E3244;
}

struct SpatialNodeContainer {
    void **items;
    int count;
};

extern "C" void func_001D7B20(void *self) {
    SpatialNodeContainer *c = (SpatialNodeContainer *)self;
    if (c->count > 0) {
        int i = 0;
        while (i < c->count) {
            func_001D1FB0(c->items[i], 1);
            i++;
        }
        func_100630(c->items);
        c->items = 0;
    }

    if (D_4E3244 != 0) {
        func_1EE700(D_4E3244, (void *)func_001D7E70, 0);
    }

    c->count = 0;
}
