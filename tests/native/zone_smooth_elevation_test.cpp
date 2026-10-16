#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001CB6D0(void *self, int x0, int y0, int x1, int y1, int max_slope);
}

struct SmoothCell {
    char pad_0[6];
    char f_6;
    char pad_7[21];
};
static_assert(sizeof(SmoothCell) == 28, "Cell size must be 28 bytes");

struct SmoothLayout {
    char pad_0[8];
    short stride_param;     // 0x8
    short pad_A;            // 0xA
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    SmoothCell **cells_ptr; // 0x8E8C
};

static void setup_grid(SmoothLayout *zm, SmoothCell cells[7][7], SmoothCell *row_ptrs[7], int width, int height, char initial_elev) {
    std::memset(zm, 0, sizeof(SmoothLayout));
    *reinterpret_cast<int *>(&zm->stride_param) = width; // width at 0x8 (low 16 bits = stride_param)
    zm->stride_param = static_cast<short>(width);
    zm->height = height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::memset(&cells[y][x], 0, sizeof(SmoothCell));
            cells[y][x].f_6 = initial_elev;
        }
        row_ptrs[y] = cells[y];
    }
    zm->cells_ptr = row_ptrs;
}

static void test_smooth_flat_no_modification() {
    SmoothLayout zm;
    SmoothCell cells[7][7];
    SmoothCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 10);

    // Flat terrain: no slope violation -> returns 0
    int modified = func_001CB6D0(&zm, 2, 2, 4, 4, 15);
    assert(modified == 0);
    assert(cells[3][3].f_6 == 10);
}

static void test_smooth_8_neighbors_upward() {
    const int neighbor_dirs[8][2] = {
        {0, -1},  // North
        {0, 1},   // South
        {-1, 0},  // West
        {1, 0},   // East
        {-1, -1}, // North-West
        {1, -1},  // North-East
        {-1, 1},  // South-West
        {1, 1}    // South-East
    };

    for (int i = 0; i < 8; i++) {
        SmoothLayout zm;
        SmoothCell cells[7][7];
        SmoothCell *row_ptrs[7];
        setup_grid(&zm, cells, row_ptrs, 7, 7, 10);

        int nx = 3 + neighbor_dirs[i][0];
        int ny = 3 + neighbor_dirs[i][1];
        cells[ny][nx].f_6 = 15; // Steep neighbor exceeds elev + 1

        int modified = func_001CB6D0(&zm, 3, 3, 3, 3, 15);
        assert(modified == 1);
        assert(cells[3][3].f_6 == 11); // Smoothed upward (+1)
    }
}

static void test_smooth_downward() {
    SmoothLayout zm;
    SmoothCell cells[7][7];
    SmoothCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 20);

    // North neighbor is steep downward (< elev - 1)
    cells[2][3].f_6 = 10;

    int modified = func_001CB6D0(&zm, 3, 3, 3, 3, 15);
    assert(modified == 1);
    assert(cells[3][3].f_6 == 19); // Smoothed downward (-1)
}

static void test_smooth_bounding_box_expansion_and_corners() {
    SmoothLayout zm;
    SmoothCell cells[7][7];
    SmoothCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 10);

    // Corner cell at (0, 0)
    cells[0][1].f_6 = 15; // East neighbor of (0, 0)
    // Pass single-cell bounding box (0, 0, 0, 0)
    int modified = func_001CB6D0(&zm, 0, 0, 0, 0, 15);
    assert(modified == 1);
    assert(cells[0][0].f_6 == 11); // Corner was expanded and smoothed

    // Far corner cell at (6, 6)
    cells[5][6].f_6 = 18; // North neighbor of (6, 6)
    modified = func_001CB6D0(&zm, 6, 6, 6, 6, 15);
    assert(modified == 1);
    assert(cells[6][6].f_6 == 11); // Boundary check safely handled
}

static void test_smooth_max_slope_low_byte_truncation() {
    // Property: max_slope & 0xFF means (val | 0x100) must produce
    // bit-identical results and return values for all inputs (0, 1, 15, 25, 100, 200)
    const int test_values[] = {0, 1, 15, 25, 100, 200};
    for (int i = 0; i < 6; i++) {
        int val = test_values[i];
        SmoothLayout zm1, zm2;
        SmoothCell cells1[7][7], cells2[7][7];
        SmoothCell *row_ptrs1[7], *row_ptrs2[7];

        setup_grid(&zm1, cells1, row_ptrs1, 7, 7, 20);
        setup_grid(&zm2, cells2, row_ptrs2, 7, 7, 20);
        cells1[2][3].f_6 = 10;
        cells2[2][3].f_6 = 10;

        int mod1 = func_001CB6D0(&zm1, 3, 3, 3, 3, val);
        int mod2 = func_001CB6D0(&zm2, 3, 3, 3, 3, val | 0x100);

        assert(mod1 == mod2);
        assert(std::memcmp(cells1, cells2, sizeof(cells1)) == 0);
    }
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "flat_no_mod") {
        test_smooth_flat_no_modification();
    } else if (argc > 1 && std::string(argv[1]) == "eight_neighbors") {
        test_smooth_8_neighbors_upward();
    } else if (argc > 1 && std::string(argv[1]) == "downward") {
        test_smooth_downward();
    } else if (argc > 1 && std::string(argv[1]) == "corners_expansion") {
        test_smooth_bounding_box_expansion_and_corners();
    } else if (argc > 1 && std::string(argv[1]) == "truncation_andi_ff") {
        test_smooth_max_slope_low_byte_truncation();
    } else {
        test_smooth_flat_no_modification();
        test_smooth_8_neighbors_upward();
        test_smooth_downward();
        test_smooth_bounding_box_expansion_and_corners();
        test_smooth_max_slope_low_byte_truncation();
    }
    return 0;
}
