#include "zone_dispatch_fixture_common.h"
#include "zone_dispatch.h"

static int g_helper_calls;
static void *g_helper_self;
static int g_helper_arguments[4];

void func_001C9FA0(void *self, int x0, int y0, int x1, int y1) {
    g_helper_calls++;
    g_helper_self = self;
    g_helper_arguments[0] = x0;
    g_helper_arguments[1] = y0;
    g_helper_arguments[2] = x1;
    g_helper_arguments[3] = y1;
}

static void initialize_grid(DispatchLayout *layout, int width, int height,
                            DispatchCell **rows) {
    std::memset(layout, 0, sizeof(*layout));
    layout->width = width;
    layout->height = height;
    layout->cells_ptr = rows;
}

static void test_rectangle_reversed_clipped_inclusive() {
    DispatchLayout layout;
    DispatchCell cells[4][6];
    DispatchCell *rows[4] = {cells[0], cells[1], cells[2], cells[3]};
    std::memset(cells, 0x33, sizeof(cells));
    initialize_grid(&layout, 4, 4, rows);
    func_001C9E00(&layout, 4, 3, -2, 1, 0x5A);
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 6; x++) {
            bool selected = y >= 1 && y <= 3 && x <= 3;
            assert((unsigned char)cells[y][x].pad_0[7] == (selected ? 0xCC : 0x33));
            assert((unsigned char)cells[y][x].pad_0[10] == (selected ? 0x5A : 0x33));
            assert((unsigned char)cells[y][x].pad_0[6] == 0x33);
        }
    }
}

static void test_rectangle_zero_width_is_noop() {
    DispatchLayout layout;
    initialize_grid(&layout, 0, 2, nullptr);
    func_001C9E00(&layout, 0, 0, 1, 1, 0x5A);
}

static void test_grid_reset_fields_only() {
    DispatchLayout layout;
    DispatchCell cells[2][4];
    DispatchCell *rows[2] = {cells[0], cells[1]};
    std::memset(cells, 0x33, sizeof(cells));
    initialize_grid(&layout, 3, 2, rows);
    func_001C9F00(&layout);
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 4; x++) {
            bool selected = x < 3;
            assert((unsigned char)cells[y][x].pad_0[7] == (selected ? 0 : 0x33));
            assert((unsigned char)cells[y][x].pad_0[8] == (selected ? 0xFF : 0x33));
            assert((unsigned char)cells[y][x].pad_0[14] == (selected ? 0xFF : 0x33));
            assert((unsigned char)cells[y][x].pad_0[9] == (selected ? 0 : 0x33));
            assert((unsigned char)cells[y][x].pad_0[10] == (selected ? 0 : 0x33));
            assert((unsigned char)cells[y][x].pad_0[6] == 0x33);
        }
    }
}

static void test_grid_update_delegates_bounds() {
    DispatchLayout layout;
    initialize_grid(&layout, 3, 2, nullptr);
    g_helper_calls = 0;
    g_helper_self = nullptr;
    func_001C9F80(&layout);
    assert(g_helper_calls == 1);
    assert(g_helper_self == &layout);
    assert(g_helper_arguments[0] == 0 && g_helper_arguments[1] == 0);
    assert(g_helper_arguments[2] == 2 && g_helper_arguments[3] == 1);
}

int main(int argc, char **argv) {
    assert(argc == 2);
    if (std::string(argv[1]) == "rectangle") test_rectangle_reversed_clipped_inclusive();
    if (std::string(argv[1]) == "zero_width") test_rectangle_zero_width_is_noop();
    if (std::string(argv[1]) == "reset") test_grid_reset_fields_only();
    if (std::string(argv[1]) == "update") test_grid_update_delegates_bounds();
    return 0;
}
