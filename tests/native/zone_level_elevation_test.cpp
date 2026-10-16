#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CBB90(void *self, int x0, int y0, int x1, int y1, int max_slope);
}

struct LevelCell {
    char pad_0[6];
    char f_6;
    char pad_7[21];
};
static_assert(sizeof(LevelCell) == 28, "Cell size must be 28 bytes");

struct LevelLayout {
    char pad_0[8];
    short stride_param;     // 0x8
    short pad_A;            // 0xA
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    LevelCell **cells_ptr;  // 0x8E8C
};

static void setup_grid(LevelLayout *zm, LevelCell cells[7][7], LevelCell *row_ptrs[7], int width, int height, char initial_elev) {
    std::memset(zm, 0, sizeof(LevelLayout));
    *reinterpret_cast<int *>(&zm->stride_param) = width;
    zm->stride_param = static_cast<short>(width);
    zm->height = height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::memset(&cells[y][x], 0, sizeof(LevelCell));
            cells[y][x].f_6 = initial_elev;
        }
        row_ptrs[y] = cells[y];
    }
    zm->cells_ptr = row_ptrs;
}

static void test_flat_no_saddle() {
    LevelLayout zm;
    LevelCell cells[7][7];
    LevelCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 10);

    func_001CBB90(&zm, 2, 2, 4, 4, 15);
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            assert(cells[y][x].f_6 == 10);
        }
    }
}

static void test_saddle_orthogonal_upward() {
    // North and South higher (15) with limit=20 > neighbor elevation (15)
    // Cell rises step-by-step through iterations until reaching equilibrium at 15
    LevelLayout zm;
    LevelCell cells[7][7];
    LevelCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 10);
    cells[2][3].f_6 = 15;
    cells[4][3].f_6 = 15;

    func_001CBB90(&zm, 3, 3, 3, 3, 20);
    assert(cells[3][3].f_6 == 15);
    assert(cells[2][3].f_6 == 15);
    assert(cells[4][3].f_6 == 15);

    // East and West higher (15)
    setup_grid(&zm, cells, row_ptrs, 7, 7, 10);
    cells[3][2].f_6 = 15;
    cells[3][4].f_6 = 15;

    func_001CBB90(&zm, 3, 3, 3, 3, 20);
    assert(cells[3][3].f_6 == 15);
    assert(cells[3][2].f_6 == 15);
    assert(cells[3][4].f_6 == 15);
}

static void test_saddle_downward_leveling() {
    // North and South higher (20), but elev=15 >= limit=10 -> levels neighbors down to 15
    LevelLayout zm;
    LevelCell cells[7][7];
    LevelCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 15);
    cells[2][3].f_6 = 20;
    cells[4][3].f_6 = 20;
    cells[2][2].f_6 = 22;

    func_001CBB90(&zm, 3, 3, 3, 3, 10);
    assert(cells[2][3].f_6 == 15);
    assert(cells[4][3].f_6 == 15);
    assert(cells[2][2].f_6 == 15);
    assert(cells[3][3].f_6 == 15);
}

static void test_iterative_expansion() {
    // Starting saddle: cell at 10, neighbors at 15, limit at 12
    // Cell rises to 12 (hitting limit), then remaining iterations level neighbors down to 12
    LevelLayout zm;
    LevelCell cells[7][7];
    LevelCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 10);

    cells[2][3].f_6 = 15;
    cells[4][3].f_6 = 15;

    func_001CBB90(&zm, 3, 3, 3, 3, 12);
    assert(cells[3][3].f_6 == 12);
    assert(cells[2][3].f_6 == 12);
    assert(cells[4][3].f_6 == 12);
}

static void test_truncation_andi_ff() {
    const int test_vals[] = {0, 1, 10, 25, 100, 200};
    for (int i = 0; i < 6; i++) {
        int v = test_vals[i];
        LevelLayout zm1, zm2;
        LevelCell cells1[7][7], cells2[7][7];
        LevelCell *row_ptrs1[7], *row_ptrs2[7];

        setup_grid(&zm1, cells1, row_ptrs1, 7, 7, 10);
        setup_grid(&zm2, cells2, row_ptrs2, 7, 7, 10);
        cells1[2][3].f_6 = 15; cells1[4][3].f_6 = 15;
        cells2[2][3].f_6 = 15; cells2[4][3].f_6 = 15;

        func_001CBB90(&zm1, 3, 3, 3, 3, v);
        func_001CBB90(&zm2, 3, 3, 3, 3, v | 0x100);
        assert(std::memcmp(cells1, cells2, sizeof(cells1)) == 0);
    }

    // Mutation test: with max_slope = 0x100, limit = 0.
    // With mask: elev (10) >= limit (0) -> triggers neighbor leveling, cell stays 10!
    // Without mask: limit = 256 -> elev (10) < 256 -> cell rises towards 15!
    LevelLayout zm;
    LevelCell cells[7][7];
    LevelCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 10);
    cells[2][3].f_6 = 15;
    cells[4][3].f_6 = 15;

    func_001CBB90(&zm, 3, 3, 3, 3, 0x100);
    assert(cells[3][3].f_6 == 10);
    assert(cells[2][3].f_6 == 10);
    assert(cells[4][3].f_6 == 10);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "flat_no_saddle") {
        test_flat_no_saddle();
    } else if (argc > 1 && std::string(argv[1]) == "saddle_upward") {
        test_saddle_orthogonal_upward();
    } else if (argc > 1 && std::string(argv[1]) == "downward_leveling") {
        test_saddle_downward_leveling();
    } else if (argc > 1 && std::string(argv[1]) == "iterative_expansion") {
        test_iterative_expansion();
    } else if (argc > 1 && std::string(argv[1]) == "truncation_andi_ff") {
        test_truncation_andi_ff();
    } else {
        test_flat_no_saddle();
        test_saddle_orthogonal_upward();
        test_saddle_downward_leveling();
        test_iterative_expansion();
        test_truncation_andi_ff();
    }
    return 0;
}
