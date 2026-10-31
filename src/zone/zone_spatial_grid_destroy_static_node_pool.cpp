#pragma exceptions off
#include "zone_spatial_grid_destroy_static_node_pool.h"

extern "C" {
void func_00100340(void *ptr, void *dtor, unsigned int size, int count);
void func_001E4040();
extern char D_9397F0[];
}

extern "C" void func_001EB2A0() {
    void *ptr;
    func_00100340(ptr = D_9397F0, (void *)func_001E4040, 0x2C, 0x100);
}
