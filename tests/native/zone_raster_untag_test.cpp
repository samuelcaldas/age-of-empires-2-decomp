#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_raster_untag.h"

struct CellMock {
    char pad_0[11];
    unsigned char f_B;
    unsigned char f_C;
    char pad_D[15];
};

struct ZoneLayoutMock {
    char pad_0[8];
    int width;
    int height;
    char pad_10[0x8E7C];
    CellMock **cells_ptr;
};

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    int case_num = std::atoi(argv[1]);

    const int W = 10;
    const int H = 10;
    CellMock grid[H][W];
    CellMock *rows[H];
    for (int y = 0; y < H; ++y) {
        rows[y] = grid[y];
        for (int x = 0; x < W; ++x) {
            std::memset(&grid[y][x], 0, sizeof(CellMock));
            grid[y][x].f_B = 0xFF;
            grid[y][x].f_C = 0xAA;
        }
    }

    ZoneLayoutMock layout;
    std::memset(&layout, 0, sizeof(layout));
    layout.width = W;
    layout.height = H;
    layout.cells_ptr = rows;

    switch (case_num) {
    case 0: {
        // x0 == x1 && y0 == y1 returns 1 immediately, cells untouched
        int res = func_001CA430(&layout, 2, 3, 2, 3);
        assert(res == 1);
        assert(grid[3][2].f_B == 0xFF);
        assert(grid[3][2].f_C == 0xAA);
        break;
    }
    case 1: {
        // Completely out of bounds returns 0
        int res = func_001CA430(&layout, -10, -10, -5, -5);
        assert(res == 0);
        res = func_001CA430(&layout, 20, 20, 25, 25);
        assert(res == 0);
        break;
    }
    case 2: {
        // Reversed coordinates swap and clear
        int res = func_001CA430(&layout, 3, 4, 1, 2);
        assert(res == 1);
        for (int y = 2; y <= 4; ++y) {
            for (int x = 1; x <= 3; ++x) {
                assert(grid[y][x].f_C == 0);
                assert(grid[y][x].f_B == (0xFF & 0x9F));
            }
        }
        // Outside cell untouched
        assert(grid[0][0].f_B == 0xFF);
        assert(grid[0][0].f_C == 0xAA);
        break;
    }
    case 3: {
        // Clamping to boundaries
        int res = func_001CA430(&layout, -2, -2, 1, 1);
        assert(res == 1);
        for (int y = 0; y <= 1; ++y) {
            for (int x = 0; x <= 1; ++x) {
                assert(grid[y][x].f_C == 0);
                assert(grid[y][x].f_B == (0xFF & 0x9F));
            }
        }
        break;
    }
    default:
        return 1;
    }

    return 0;
}
