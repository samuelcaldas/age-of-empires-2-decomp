#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001CD060(void *self, int cx, int cy, int radius, int elevation);
}

struct PaintCell {
    char pad_0[6];
    char f_6;
    char pad_7[21];
};
static_assert(sizeof(PaintCell) == 28, "Cell size must be 28 bytes");

struct PaintLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    PaintCell **cells_ptr;  // 0x8E8C (-0x7174)
};

static void setup_grid(PaintLayout *zm, PaintCell cells[7][7], PaintCell *row_ptrs[7], int width, int height, char initial_elev) {
    std::memset(zm, 0, sizeof(PaintLayout));
    zm->width = width;
    zm->height = height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::memset(&cells[y][x], 0, sizeof(PaintCell));
            cells[y][x].f_6 = initial_elev;
        }
        row_ptrs[y] = cells[y];
    }
    zm->cells_ptr = row_ptrs;
}

static void test_paint_elevation_box_normal() {
    PaintLayout zm;
    PaintCell cells[7][7];
    PaintCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 5);

    int ret = func_001CD060(&zm, 3, 3, 1, 15);
    assert(ret == 1);

    const char expected[7][7] = {
        { 5,  5,  5,  5,  5,  5,  5},
        { 5,  5,  5,  5,  5,  5,  5},
        { 5,  5, 15, 15, 15,  5,  5},
        { 5,  5, 15, 15, 15,  5,  5},
        { 5,  5, 15, 15, 15,  5,  5},
        { 5,  5,  5,  5,  5,  5,  5},
        { 5,  5,  5,  5,  5,  5,  5}
    };
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            assert(cells[y][x].f_6 == expected[y][x]);
        }
    }
}

static void test_paint_elevation_corner_clamping() {
    PaintLayout zm;
    PaintCell cells[7][7];
    PaintCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 5);

    int ret = func_001CD060(&zm, 0, 0, 2, 20);
    assert(ret == 1);

    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            char exp = (y <= 2 && x <= 2) ? 20 : 5;
            assert(cells[y][x].f_6 == exp);
        }
    }
}

static void test_paint_elevation_single_tile() {
    PaintLayout zm;
    PaintCell cells[7][7];
    PaintCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 5);

    int ret = func_001CD060(&zm, 4, 2, 0, 8);
    assert(ret == 1);
    assert(cells[2][4].f_6 == 8);
    assert(cells[2][3].f_6 == 5);
}

static void test_paint_elevation_full_map_clamp() {
    PaintLayout zm;
    PaintCell cells[7][7];
    PaintCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 5);

    int ret = func_001CD060(&zm, 3, 3, 10, 25);
    assert(ret == 1);
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            assert(cells[y][x].f_6 == 25);
        }
    }
}

static void test_paint_elevation_negative_center() {
    PaintLayout zm;
    PaintCell cells[7][7];
    PaintCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 5);

    int ret = func_001CD060(&zm, -2, -2, 3, 12);
    assert(ret == 1);
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            char exp = (y <= 1 && x <= 1) ? 12 : 5;
            assert(cells[y][x].f_6 == exp);
        }
    }
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "box_normal") {
        test_paint_elevation_box_normal();
    } else if (argc > 1 && std::string(argv[1]) == "corner_clamping") {
        test_paint_elevation_corner_clamping();
    } else if (argc > 1 && std::string(argv[1]) == "single_tile") {
        test_paint_elevation_single_tile();
    } else if (argc > 1 && std::string(argv[1]) == "full_map") {
        test_paint_elevation_full_map_clamp();
    } else if (argc > 1 && std::string(argv[1]) == "negative_center") {
        test_paint_elevation_negative_center();
    } else {
        test_paint_elevation_box_normal();
        test_paint_elevation_corner_clamping();
        test_paint_elevation_single_tile();
        test_paint_elevation_full_map_clamp();
        test_paint_elevation_negative_center();
    }
    return 0;
}
