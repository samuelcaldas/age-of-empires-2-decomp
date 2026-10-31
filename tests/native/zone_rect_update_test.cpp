#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001C9FA0(void *self, int x0, int y0, int x1, int y1);
}

struct TestZoneCell {
    short f_0;              // 0x0
    short f_2;              // 0x2
    unsigned char f_4;      // 0x4
    unsigned char f_5;      // 0x5
    unsigned char f_6;      // 0x6
    unsigned char f_7;      // 0x7
    char pad_8[20];         // total 28 bytes (0x1C)
};

static_assert(sizeof(TestZoneCell) == 0x1C, "TestZoneCell size must be 28 bytes");

struct TestZoneLayout {
    char pad_0[8];          // 0x0
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    TestZoneCell **cells_ptr; // 0x8E8C
    char pad_8E90[0x22];    // 0x8E90..0x8EB1
    short f_8EB2;           // 0x8EB2
    short f_8EB4;           // 0x8EB4
    short f_8EB6;           // 0x8EB6
};

static void test_rect_update_basic() {
    TestZoneLayout layout;
    std::memset(&layout, 0, sizeof(layout));

    layout.width = 10;
    layout.height = 10;
    layout.f_8EB2 = 5;
    layout.f_8EB4 = 3;
    layout.f_8EB6 = 2;

    TestZoneCell grid[10][10];
    std::memset(grid, 0, sizeof(grid));

    TestZoneCell *row_ptrs[10];
    for (int i = 0; i < 10; i++) {
        row_ptrs[i] = grid[i];
    }
    layout.cells_ptr = row_ptrs;

    // Set f_6 for some cells
    grid[2][3].f_6 = 4;
    grid[2][3].f_4 = 0; // not special

    grid[4][5].f_6 = 1;
    grid[4][5].f_4 = 15; // special (cell->f_2 -= f_8EB6)

    grid[6][7].f_6 = 2;
    grid[6][7].f_4 = 6;  // special (cell->f_2 -= f_8EB6)

    // Run rect update for [2, 2] to [8, 8]
    func_001C9FA0(&layout, 2, 2, 8, 8);

    // Check [2, 3]: x=3, y=2
    // f_0 = (3 + 2) * 3 = 15
    // f_2 = (2 - 3) * 5 - 4 * 2 = -5 - 8 = -13
    assert(grid[2][3].f_0 == 15);
    assert(grid[2][3].f_2 == -13);

    // Check [4, 5]: x=5, y=4
    // f_0 = (5 + 4) * 3 = 27
    // f_2 before special = (4 - 5) * 5 - 1 * 2 = -5 - 2 = -7
    // special: -7 - 2 = -9
    assert(grid[4][5].f_0 == 27);
    assert(grid[4][5].f_2 == -9);

    // Check [6, 7]: x=7, y=6
    // f_0 = (7 + 6) * 3 = 39
    // f_2 before special = (6 - 7) * 5 - 2 * 2 = -5 - 4 = -9
    // special: -9 - 2 = -11
    assert(grid[6][7].f_0 == 39);
    assert(grid[6][7].f_2 == -11);

    // Check outside rect [1, 1]: un-updated
    assert(grid[1][1].f_0 == 0);
    assert(grid[1][1].f_2 == 0);
}

static void test_rect_update_clamping() {
    TestZoneLayout layout;
    std::memset(&layout, 0, sizeof(layout));

    layout.width = 4;
    layout.height = 4;
    layout.f_8EB2 = 2;
    layout.f_8EB4 = 2;
    layout.f_8EB6 = 1;

    TestZoneCell grid[4][4];
    std::memset(grid, 0, sizeof(grid));

    TestZoneCell *row_ptrs[4];
    for (int i = 0; i < 4; i++) {
        row_ptrs[i] = grid[i];
    }
    layout.cells_ptr = row_ptrs;

    // Passing out-of-bounds coordinates (-5, -5, 20, 20)
    // Should clamp to (0, 0, 3, 3)
    func_001C9FA0(&layout, -5, -5, 20, 20);

    // Check corner (0, 0)
    assert(grid[0][0].f_0 == 0);
    assert(grid[0][0].f_2 == 0);

    // Check corner (3, 3)
    // f_0 = (3 + 3) * 2 = 12
    // f_2 = (3 - 3) * 2 - 0 = 0
    assert(grid[3][3].f_0 == 12);
    assert(grid[3][3].f_2 == 0);
}

int main(int argc, char **argv) {
    test_rect_update_basic();
    test_rect_update_clamping();
    return 0;
}
