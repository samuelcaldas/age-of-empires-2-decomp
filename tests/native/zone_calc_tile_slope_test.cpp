#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
unsigned char func_001CFCD0(void *self, int x, int y);
}

static void setup_grid_elevations(
    char *zone_mem, char *cells_grid, int width, int height,
    int cx, int cy, unsigned char center_elev,
    unsigned char n, unsigned char s, unsigned char e, unsigned char w,
    unsigned char nw, unsigned char ne, unsigned char sw, unsigned char se
) {
    std::memset(zone_mem, 0, 0x10000);
    std::memset(cells_grid, 0, width * height * 28);

    *reinterpret_cast<int *>(zone_mem + 0x8) = width;
    *reinterpret_cast<int *>(zone_mem + 0xC) = height;

    static char *row_ptrs[10];
    for (int r = 0; r < height; r++) {
        row_ptrs[r] = cells_grid + r * width * 28;
    }
    *reinterpret_cast<char ***>(zone_mem + 0x8E8C) = row_ptrs;

    // Set elevations
    auto set_elev = [&](int x, int y, unsigned char el) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            cells_grid[y * width * 28 + x * 28 + 6] = el;
        }
    };

    set_elev(cx, cy, center_elev);
    set_elev(cx, cy - 1, n);
    set_elev(cx, cy + 1, s);
    set_elev(cx + 1, cy, e);
    set_elev(cx - 1, cy, w);
    set_elev(cx - 1, cy - 1, nw);
    set_elev(cx + 1, cy - 1, ne);
    set_elev(cx - 1, cy + 1, sw);
    set_elev(cx + 1, cy + 1, se);
}

static void test_flat_returns_zero() {
    char zone_mem[0x10000], cells_grid[10 * 10 * 28];
    // All neighbors = 4 -> flat -> returns 0
    setup_grid_elevations(zone_mem, cells_grid, 10, 10, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4);

    unsigned char ret = func_001CFCD0(zone_mem, 3, 3);
    assert(ret == 0);
}

static void test_cardinal_slopes() {
    char zone_mem[0x10000], cells_grid[10 * 10 * 28];

    // North = 5 (elev+1) -> returns 6
    setup_grid_elevations(zone_mem, cells_grid, 10, 10, 3, 3, 4, 5, 4, 4, 4, 4, 4, 4, 4);
    assert(func_001CFCD0(zone_mem, 3, 3) == 6);

    // East = 5 -> returns 8
    setup_grid_elevations(zone_mem, cells_grid, 10, 10, 3, 3, 4, 4, 4, 5, 4, 4, 4, 4, 4);
    assert(func_001CFCD0(zone_mem, 3, 3) == 8);

    // West = 5 -> returns 5
    setup_grid_elevations(zone_mem, cells_grid, 10, 10, 3, 3, 4, 4, 4, 4, 5, 4, 4, 4, 4);
    assert(func_001CFCD0(zone_mem, 3, 3) == 5);

    // South = 5 -> returns 7
    setup_grid_elevations(zone_mem, cells_grid, 10, 10, 3, 3, 4, 4, 5, 4, 4, 4, 4, 4, 4);
    assert(func_001CFCD0(zone_mem, 3, 3) == 7);
}

static void test_corner_slopes() {
    char zone_mem[0x10000], cells_grid[10 * 10 * 28];

    // N + E = 5 -> returns 14
    setup_grid_elevations(zone_mem, cells_grid, 10, 10, 3, 3, 4, 5, 4, 5, 4, 4, 4, 4, 4);
    assert(func_001CFCD0(zone_mem, 3, 3) == 14);

    // W + S = 5 -> returns 13
    setup_grid_elevations(zone_mem, cells_grid, 10, 10, 3, 3, 4, 4, 5, 4, 5, 4, 4, 4, 4);
    assert(func_001CFCD0(zone_mem, 3, 3) == 13);

    // N + W = 5 -> returns 16
    setup_grid_elevations(zone_mem, cells_grid, 10, 10, 3, 3, 4, 5, 4, 4, 5, 4, 4, 4, 4);
    assert(func_001CFCD0(zone_mem, 3, 3) == 16);

    // E + S = 5 -> returns 15
    setup_grid_elevations(zone_mem, cells_grid, 10, 10, 3, 3, 4, 4, 5, 5, 4, 4, 4, 4, 4);
    assert(func_001CFCD0(zone_mem, 3, 3) == 15);
}

static void test_out_of_bounds_returns_zero() {
    char zone_mem[0x10000], cells_grid[10 * 10 * 28];
    setup_grid_elevations(zone_mem, cells_grid, 10, 10, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4);

    assert(func_001CFCD0(zone_mem, -1, 3) == 0);
    assert(func_001CFCD0(zone_mem, 10, 3) == 0);
    assert(func_001CFCD0(zone_mem, 3, -1) == 0);
    assert(func_001CFCD0(zone_mem, 3, 10) == 0);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "cardinal") {
        test_cardinal_slopes();
    } else if (argc > 1 && std::string(argv[1]) == "corner") {
        test_corner_slopes();
    } else if (argc > 1 && std::string(argv[1]) == "oob") {
        test_out_of_bounds_returns_zero();
    } else {
        test_flat_returns_zero();
        test_cardinal_slopes();
        test_corner_slopes();
        test_out_of_bounds_returns_zero();
    }
    return 0;
}
