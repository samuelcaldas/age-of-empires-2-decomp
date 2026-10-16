#include "zone_dispatch_fixture_common.h"

static void test_nonpositive_resize_is_rejected() {
    DispatchLayout layout;
    std::memset(&layout, 0, sizeof(layout));
    layout.width = 13;
    layout.height = 17;
    g_1387c0_calls = 0;
    g_c9fa0_calls = 0;
    func_001C98A0(&layout, 0, 3);
    assert(layout.width == 13 && layout.height == 17);
    assert(g_1387c0_calls == 0 && g_c9fa0_calls == 0);
}

static void test_resize_clamps_and_preserves_callback_arguments() {
    DispatchLayout layout;
    char child[0x60];
    std::memset(&layout, 0, sizeof(layout));
    std::memset(child, 0, sizeof(child));
    *reinterpret_cast<short *>(child + 0x50) = 7;
    layout.zone_child = child;
    g_expected_zm = &layout;
    g_1387c0_calls = 0;
    g_c9fa0_calls = 0;
    g_d0430_calls = 0;
    func_001C98A0(&layout, 201, 202);
    assert(layout.width == 200 && layout.height == 200);
    assert(g_1387c0_calls == 1);
    assert(g_1387c0_width == 201 && g_1387c0_height == 202);
    assert(g_c9fa0_calls == 1 && g_c9fa0_self == &layout);
    assert(g_c9fa0_x0 == 0 && g_c9fa0_y0 == 0);
    assert(g_c9fa0_x1 == 199 && g_c9fa0_y1 == 199);
    assert(g_3273e0_self == D_4E2DEC);
    assert(g_3273e0_count == 7 && g_3273e0_flag == 0x40);
    assert(layout.cells_ptr[200] == reinterpret_cast<DispatchCell *>(D_81D120));
    assert(g_d0430_calls == 1);
}

int main(int argc, char **argv) {
    assert(argc == 2);
    if (std::string(argv[1]) == "reject") test_nonpositive_resize_is_rejected();
    if (std::string(argv[1]) == "clamp") test_resize_clamps_and_preserves_callback_arguments();
    return 0;
}
