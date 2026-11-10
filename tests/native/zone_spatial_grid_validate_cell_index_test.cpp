#include <cassert>
#include <cstring>
#include <iostream>
#include "zone_spatial_grid_validate_cell_index.h"

static int g_func46E0_calls = 0;
static int g_func4820_calls = 0;
static void *g_last_ptr = 0;
static int g_last_a1 = 0;
static int g_last_a2 = 0;

extern "C" {
void func_001E46E0(void *self, void *ptr, int a2) {
    g_func46E0_calls++;
    g_last_ptr = ptr;
    assert(a2 == 1);
}

void func_001E4820(void *self, int a1, int a2) {
    g_func4820_calls++;
    g_last_a1 = a1;
    g_last_a2 = a2;
}
}

struct SpatialStruct {
    int field_0;
    int field_4;
    char pad[0x18];
    int count;
    char pad_24[4];
    char *buffer;
};

int main() {
    char mock_buf[100];
    std::memset(mock_buf, 0, sizeof(mock_buf));

    SpatialStruct s;
    s.field_0 = 123;
    s.field_4 = 456;
    s.count = 3;
    s.buffer = mock_buf;

    int dummy_grid;
    int res = func_001E4EC0((SpatialGrid *)&dummy_grid, &s);

    assert(res == 1);
    assert(g_func46E0_calls == 3);
    assert(g_last_ptr == mock_buf + 2 * 20);
    assert(g_func4820_calls == 1);
    assert(g_last_a1 == 456);
    assert(g_last_a2 == 123);

    std::cout << "zone_spatial_grid_validate_cell_index_test passed\n";
    return 0;
}
