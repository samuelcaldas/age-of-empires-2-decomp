#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001CCD10(void *self, int cx, int cy, int radius, int terrain_type);
}

static int g_rep_count = 0;

struct PaintCell {
    char pad_0[5];
    char f_5;
    char f_6;
    char pad_7[21];
};
static_assert(sizeof(PaintCell) == 28, "Cell size must be 28 bytes");

struct PaintLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8ED8];    // 0x10..0x8EE7
    void *m_world;          // 0x8EE8 (-0x7118)
};

static PaintCell g_cells[7][7];

extern "C" void func_1CF830(void *self, void *world, int x, int y, int terrain_type, int p5, int p6) {
    g_rep_count++;
    assert(x >= 0 && x < 7);
    assert(y >= 0 && y < 7);
    g_cells[y][x].f_5 = static_cast<char>(terrain_type);
}

static void setup_grid(PaintLayout *zm, int width, int height) {
    std::memset(zm, 0, sizeof(PaintLayout));
    zm->width = width;
    zm->height = height;
    zm->m_world = reinterpret_cast<void *>(0x12345678);
    std::memset(g_cells, 0, sizeof(g_cells));
    g_rep_count = 0;
}

static void test_paint_box_normal() {
    PaintLayout zm;
    setup_grid(&zm, 7, 7);

    // Paint radius 1 at center (3, 3) with terrain 5 -> 3x3 region [2..4, 2..4]
    int ret = func_001CCD10(&zm, 3, 3, 1, 5);
    assert(ret == 1);
    assert(g_rep_count == 9);

    const char expected[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 5, 5, 5, 0, 0},
        {0, 0, 5, 5, 5, 0, 0},
        {0, 0, 5, 5, 5, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            assert(g_cells[y][x].f_5 == expected[y][x]);
        }
    }
}

static void test_paint_corner_clamping() {
    PaintLayout zm;
    setup_grid(&zm, 7, 7);

    // Paint radius 2 at corner (0, 0) with terrain 7 -> clamped to [0..2, 0..2]
    int ret = func_001CCD10(&zm, 0, 0, 2, 7);
    assert(ret == 1);
    assert(g_rep_count == 9);

    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            char exp = (y <= 2 && x <= 2) ? 7 : 0;
            assert(g_cells[y][x].f_5 == exp);
        }
    }
}

static void test_paint_single_cell() {
    PaintLayout zm;
    setup_grid(&zm, 7, 7);

    // Radius 0 at (4, 2)
    int ret = func_001CCD10(&zm, 4, 2, 0, 3);
    assert(ret == 1);
    assert(g_rep_count == 1);
    assert(g_cells[2][4].f_5 == 3);
}

static void test_paint_full_map_clamp() {
    PaintLayout zm;
    setup_grid(&zm, 7, 7);

    // Radius 10 at center (3, 3) covers entire map
    int ret = func_001CCD10(&zm, 3, 3, 10, 8);
    assert(ret == 1);
    assert(g_rep_count == 49);
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            assert(g_cells[y][x].f_5 == 8);
        }
    }
}

static void test_paint_negative_center() {
    PaintLayout zm;
    setup_grid(&zm, 7, 7);

    // Negative center (-2, -2) with radius 3 touches [0..1, 0..1]
    int ret = func_001CCD10(&zm, -2, -2, 3, 4);
    assert(ret == 1);
    assert(g_rep_count == 4);
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            char exp = (y <= 1 && x <= 1) ? 4 : 0;
            assert(g_cells[y][x].f_5 == exp);
        }
    }
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "box_normal") {
        test_paint_box_normal();
    } else if (argc > 1 && std::string(argv[1]) == "corner_clamping") {
        test_paint_corner_clamping();
    } else if (argc > 1 && std::string(argv[1]) == "single_cell") {
        test_paint_single_cell();
    } else if (argc > 1 && std::string(argv[1]) == "full_map") {
        test_paint_full_map_clamp();
    } else if (argc > 1 && std::string(argv[1]) == "negative_center") {
        test_paint_negative_center();
    } else {
        test_paint_box_normal();
        test_paint_corner_clamping();
        test_paint_single_cell();
        test_paint_full_map_clamp();
        test_paint_negative_center();
    }
    return 0;
}
