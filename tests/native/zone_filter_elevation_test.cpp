#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CBFE0(void *self, int x0, int y0, int x1, int y1, int max_slope);
}

static int g_cb_count = 0;
static int g_cb_x0 = -1, g_cb_y0 = -1, g_cb_x1 = -1, g_cb_y1 = -1;

extern "C" void func_001CF3E0(void *self, int x0, int y0, int x1, int y1, int p5, int p6, int p7) {
    g_cb_count++;
    g_cb_x0 = x0;
    g_cb_y0 = y0;
    g_cb_x1 = x1;
    g_cb_y1 = y1;
}

struct FilterCell {
    char pad_0[6];
    char f_6;
    char pad_7[21];
};
static_assert(sizeof(FilterCell) == 28, "Cell size must be 28 bytes");

struct FilterLayout {
    char pad_0[8];
    short stride_param;     // 0x8
    short pad_A;            // 0xA
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    FilterCell **cells_ptr; // 0x8E8C
};

static void setup_grid(FilterLayout *zm, FilterCell cells[9][9], FilterCell *row_ptrs[9], int width, int height, char initial_elev) {
    std::memset(zm, 0, sizeof(FilterLayout));
    *reinterpret_cast<int *>(&zm->stride_param) = width;
    zm->stride_param = static_cast<short>(width);
    zm->height = height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::memset(&cells[y][x], 0, sizeof(FilterCell));
            cells[y][x].f_6 = initial_elev;
        }
        row_ptrs[y] = cells[y];
    }
    zm->cells_ptr = row_ptrs;
    g_cb_count = 0;
}

static void test_flat_no_mod() {
    FilterLayout zm;
    FilterCell cells[9][9];
    FilterCell *row_ptrs[9];
    setup_grid(&zm, cells, row_ptrs, 9, 9, 10);

    func_001CBFE0(&zm, 2, 2, 6, 6, 15);
    assert(g_cb_count == 1);
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            assert(cells[y][x].f_6 == 10);
        }
    }
}

static void test_corner_saddle_upward() {
    FilterLayout zm;
    FilterCell cells[9][9];
    FilterCell *row_ptrs[9];
    setup_grid(&zm, cells, row_ptrs, 9, 9, 10);

    // NW and NE higher, North equal to cell -> NW corner saddle triggers
    cells[3][3].f_6 = 15; // NW of (4, 4)
    cells[3][5].f_6 = 15; // NE of (4, 4)
    cells[3][4].f_6 = 10; // North of (4, 4)
    cells[4][4].f_6 = 10;

    func_001CBFE0(&zm, 4, 4, 4, 4, 20); // limit 20 > 10
    assert(g_cb_count >= 1);
    assert(cells[4][4].f_6 > 10); // Raised upward
}

static void test_corner_saddle_downward() {
    FilterLayout zm;
    FilterCell cells[9][9];
    FilterCell *row_ptrs[9];
    setup_grid(&zm, cells, row_ptrs, 9, 9, 10);

    // Setup corner saddle with elev=15 >= limit=10
    cells[4][4].f_6 = 15;
    cells[3][3].f_6 = 20; // NW
    cells[3][5].f_6 = 20; // NE
    cells[3][4].f_6 = 10; // North

    func_001CBFE0(&zm, 4, 4, 4, 4, 10);
    assert(g_cb_count >= 1);
    // Higher neighbors leveled down towards 15
    assert(cells[3][3].f_6 <= 15);
    assert(cells[3][5].f_6 <= 15);
}

static void test_bounds_clamping_and_callback() {
    FilterLayout zm;
    FilterCell cells[9][9];
    FilterCell *row_ptrs[9];
    setup_grid(&zm, cells, row_ptrs, 9, 9, 10);

    // Pass out-of-bounds bounding box
    func_001CBFE0(&zm, -10, -10, 50, 50, 15);
    assert(g_cb_count == 1);
    assert(g_cb_x0 >= 0);
    assert(g_cb_y0 >= 0);
    assert(g_cb_x1 < 9);
    assert(g_cb_y1 < 9);
}

static void test_truncation_andi_ff() {
    const int test_vals[] = {0, 1, 10, 25, 100, 200};
    for (int i = 0; i < 6; i++) {
        int v = test_vals[i];
        FilterLayout zm1, zm2;
        FilterCell cells1[9][9], cells2[9][9];
        FilterCell *row_ptrs1[9], *row_ptrs2[9];

        setup_grid(&zm1, cells1, row_ptrs1, 9, 9, 10);
        setup_grid(&zm2, cells2, row_ptrs2, 9, 9, 10);
        cells1[3][3].f_6 = 15; cells1[3][5].f_6 = 15;
        cells2[3][3].f_6 = 15; cells2[3][5].f_6 = 15;

        func_001CBFE0(&zm1, 4, 4, 4, 4, v);
        func_001CBFE0(&zm2, 4, 4, 4, 4, v | 0x100);
        assert(std::memcmp(cells1, cells2, sizeof(cells1)) == 0);
    }

    // Mutation test: with max_slope = 0x100, limit = 0.
    // With mask: elev (10) >= limit (0) -> triggers neighbor leveling, cell stays 10!
    // Without mask: limit = 256 -> elev (10) < 256 -> cell is raised!
    FilterLayout zm;
    FilterCell cells[9][9];
    FilterCell *row_ptrs[9];
    setup_grid(&zm, cells, row_ptrs, 9, 9, 10);
    cells[3][3].f_6 = 15;
    cells[3][5].f_6 = 15;

    func_001CBFE0(&zm, 4, 4, 4, 4, 0x100);
    assert(cells[4][4].f_6 == 10);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "flat_no_mod") {
        test_flat_no_mod();
    } else if (argc > 1 && std::string(argv[1]) == "corner_saddle_upward") {
        test_corner_saddle_upward();
    } else if (argc > 1 && std::string(argv[1]) == "corner_saddle_downward") {
        test_corner_saddle_downward();
    } else if (argc > 1 && std::string(argv[1]) == "bounds_clamping") {
        test_bounds_clamping_and_callback();
    } else if (argc > 1 && std::string(argv[1]) == "truncation_andi_ff") {
        test_truncation_andi_ff();
    } else {
        test_flat_no_mod();
        test_corner_saddle_upward();
        test_corner_saddle_downward();
        test_bounds_clamping_and_callback();
        test_truncation_andi_ff();
    }
    return 0;
}
