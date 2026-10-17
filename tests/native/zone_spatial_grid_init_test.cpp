#include <cassert>
#include "zone_spatial_entity_stub_1e3830.h"
#include "zone_spatial_entity_identity_getter.h"
#include "zone_spatial_grid_init_node_buffer.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

static int s_func_100670_called = 0;
extern "C" void func_100670() {
    s_func_100670_called++;
}

static int s_func_1E3710_called = 0;
extern "C" void func_1E3710(void *p) {
    s_func_1E3710_called++;
}

static void test_stub_and_identity() {
    char buf[16];
    s_func_1E3710_called = 0;
    func_001E3830(buf);
    assert(s_func_1E3710_called == 1);

    assert(func_001E3F90(buf) == buf);
}

static void test_grid_init_node_buffer() {
    char grid_buf[32];
    s_func_100670_called = 0;

    assert(func_001E4050(nullptr, 10) == nullptr);
    assert(s_func_100670_called == 0);

    assert(func_001E4050(grid_buf, 0) == grid_buf);
    assert(s_func_100670_called == 0);

    assert(func_001E4050(grid_buf, 5) == grid_buf);
    assert(s_func_100670_called == 1);
}

int main(int argc, char **argv) {
    test_stub_and_identity();
    test_grid_init_node_buffer();
    return 0;
}
