#pragma exceptions off
#include "zone_spatial_grid_destroy_static_node_pool.h"

class StaticNode {
public:
    char data[0x2C];
    ~StaticNode();
};

extern "C" {
void func_100340(void *ptr, void *dtor, unsigned int size, int count);
void func_001E4040();
extern StaticNode D_009397F0[256];
}

extern "C" void func_001EB2A0() {
    void *ptr = D_009397F0;
    func_100340(ptr, (void *)func_001E4040, 0x2C, 0x100);
}
