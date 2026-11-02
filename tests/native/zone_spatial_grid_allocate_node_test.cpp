#include <cassert>
#include <cstring>
#include <iostream>

#include "zone_spatial_grid_allocate_node.h"

struct SpatialGrid {
    char pad_04[0x4];
    int count;
    char pad_0C[0x4];
    void **nodes;
};

static int s_f1E6F50_called = 0;
static int s_f1E6F50_arg = 0;
static int s_f1E3F90_called = 0;
static void *s_f1E3F90_node = NULL;
static char s_mock_node_buffer[44 * 10];

extern "C" {
char D_009397F0[44 * 10];

void func_001E6F50(void *self, int count) {
    s_f1E6F50_called++;
    s_f1E6F50_arg = count;
}

void *func_117CAC(void *dst, int val, unsigned int size) {
    return std::memset(dst, val, size);
}

void func_001E3F90(void *node) {
    s_f1E3F90_called++;
    s_f1E3F90_node = node;
}
}

int main() {
    void *node_ptrs[8] = {0};
    SpatialGrid grid;
    grid.count = 2;
    grid.nodes = node_ptrs;

    int out_index = -1;
    void *ret = func_001E8210(&grid, &out_index);

    // Verify side effects
    assert(s_f1E6F50_called == 1);
    assert(s_f1E6F50_arg == 3);
    assert(out_index == 2);
    assert(grid.count == 3);
    assert(ret == (void *)&D_009397F0[2 * 44]);
    assert(grid.nodes[2] == ret);
    assert(s_f1E3F90_called == 1);
    assert(s_f1E3F90_node == ret);

    // Call again when node is already present
    void *existing_node = (void *)0x12345678;
    grid.nodes[3] = existing_node;
    ret = func_001E8210(&grid, &out_index);
    assert(out_index == 3);
    assert(grid.count == 4);
    assert(ret == existing_node);
    assert(s_f1E3F90_called == 1); // Not called again

    std::cout << "zone_spatial_grid_allocate_node native tests passed!" << std::endl;
    return 0;
}
