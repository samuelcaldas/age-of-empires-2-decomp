#include <cassert>
#include <cstring>
#include "zone_spatial_grid_destroy_static_node_pool.h"
#include "zone_spatial_grid_deserialize_node_array.h"
#include "zone_spatial_grid_free_node_array.h"
#include "zone_spatial_grid_deserialize_child_entries.h"

struct StaticNode {
    char data[0x2C];
};

extern "C" {
StaticNode D_009397F0[256];
void func_100340(void *ptr, void *dtor, unsigned int size, int count) {}
void func_001E4040() {}
int func_226D90(void *stream, void *dst, int size) { return size; }
void *func_1143F8(int count, int elem_size) { return nullptr; }
void func_116F68(void *ptr) {}
void func_100670(void *ptr) {}
void *func_36C3F0(int size) { return nullptr; }
}

int main() {
    func_001EB2A0();

    struct DummyHeader {
        char pad_1C[0x1C];
        short count;
        char pad_20[0x2];
        void *buffer;
    } dummy;
    dummy.count = 5;
    dummy.buffer = (void *)0x1234;

    void *res = func_001EB3B0(&dummy, 0);
    assert(res == &dummy);
    assert(dummy.buffer == nullptr);
    return 0;
}
