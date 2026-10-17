#include <cassert>
#include "zone_spatial_grid_reset_cells.h"
#include "zone_spatial_grid_get_cell.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct GridBuffer {
    int count;
    char pad[0x8];
    int *data;
};

static void test_grid_cells() {
    int buf[16];
    for (int i = 0; i < 16; i++) buf[i] = 100 + i;

    GridBuffer gb;
    gb.count = 8;
    gb.data = buf;

    assert(func_001E5350(&gb, -1) == -1);
    assert(func_001E5350(&gb, 8) == -1);
    assert(func_001E5350(&gb, 0) == 100);
    assert(func_001E5350(&gb, 7) == 107);

    func_001E5310(&gb);
    for (int i = 0; i < 8; i++) {
        assert(func_001E5350(&gb, i) == -1);
    }
}

int main(int argc, char **argv) {
    test_grid_cells();
    return 0;
}
