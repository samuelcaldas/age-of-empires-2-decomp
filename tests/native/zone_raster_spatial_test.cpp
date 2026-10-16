#include "zone_raster_fixture_common.h"

extern "C" {
void func_001C9FA0(void *self, int x0, int y0, int x1, int y1);
int func_001CA430(void *self, int x0, int y0, int x1, int y1);
int func_001CA560(void *self, int x, int y, int *out_x, int *out_y);
int func_001CA670(void *self, int x, int y, int *out_x1, int *out_y1, int *out_x2, int *out_y2);

int D_00392020[16] = {0, 1, 2, 3, 4, 5, 6, 7, -8, -7, -6, -5, -4, -3, -2, -1};
}

void test_rect_update_calculations_and_mask_subtraction() {
    TestZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.width = 8;
    zm.height = 8;
    zm.f_8EB2 = 3;
    zm.f_8EB4 = 5;
    zm.f_8EB6 = 7;

    TestCell cells[8][8];
    std::memset(cells, 0, sizeof(cells));
    TestCell *row_ptrs[8];
    for (int y = 0; y < 8; y++) row_ptrs[y] = cells[y];
    zm.cells_ptr = row_ptrs;

    cells[2][2].f_4 = 15; // mask hit -> subtracts f_8EB6
    cells[3][3].f_4 = 99; // no mask hit

    func_001C9FA0(&zm, -2, -2, 10, 10);
    assert(cells[2][2].f_0 == 20);
    assert(cells[2][2].f_2 == -7);
    assert(cells[3][3].f_0 == 30);
    assert(cells[3][3].f_2 == 0);
}

void test_raster_untag_clears_cells() {
    TestZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.width = 6;
    zm.height = 6;

    TestCell cells[6][6];
    std::memset(cells, 0x7F, sizeof(cells));
    TestCell *row_ptrs[6];
    for (int y = 0; y < 6; y++) row_ptrs[y] = cells[y];
    zm.cells_ptr = row_ptrs;

    int res = func_001CA430(&zm, 1, 1, 1, 1);
    assert(res == 1 && cells[1][1].f_C == static_cast<unsigned char>(0x7F));

    res = func_001CA430(&zm, 1, 1, 2, 2);
    assert(res == 1);
    for (int y = 1; y <= 2; y++) {
        for (int x = 1; x <= 2; x++) {
            assert(cells[y][x].f_C == 0);
            assert(cells[y][x].f_B == (0x7F & 0x9F));
        }
    }
    assert(cells[0][0].f_C == static_cast<unsigned char>(0x7F));
}

void test_raster_trace_backtracking() {
    TestZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.width = 5;
    zm.height = 5;

    TestCell cells[5][5];
    std::memset(cells, 0, sizeof(cells));
    TestCell *row_ptrs[5];
    for (int y = 0; y < 5; y++) row_ptrs[y] = cells[y];
    zm.cells_ptr = row_ptrs;

    cells[1][1].f_B = 0x40;
    cells[3][2].f_B = 0x20;
    cells[3][2].f_C = 0x21; // dx=1, dy=2

    int out_x = -1, out_y = -1;
    int ok = func_001CA560(&zm, 2, 3, &out_x, &out_y);
    assert(ok == 1 && out_x == 1 && out_y == 1);

    cells[4][4].f_B = 0x20;
    cells[4][4].f_C = 0x00;
    ok = func_001CA560(&zm, 4, 4, &out_x, &out_y);
    assert(ok == 0);

    assert(func_001CA560(&zm, -1, 2, &out_x, &out_y) == 0);
    assert(func_001CA560(&zm, 5, 2, &out_x, &out_y) == 0);
}

void test_raster_extent_resolution() {
    TestZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.width = 10;
    zm.height = 10;

    TestCell cells[10][10];
    std::memset(cells, 0, sizeof(cells));
    TestCell *row_ptrs[10];
    for (int y = 0; y < 10; y++) row_ptrs[y] = cells[y];
    zm.cells_ptr = row_ptrs;

    int packed_table[4] = {0x04030201, 0, 0, 0};
    zm.f_8ED8 = packed_table;

    cells[5][5].f_B = 0x40;
    cells[5][5].f_C = 1;

    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    int ok = func_001CA670(&zm, 5, 5, &x1, &y1, &x2, &y2);
    assert(ok == 1);
    assert(x1 == 4 && y1 == 3 && x2 == 8 && y2 == 9);
}
