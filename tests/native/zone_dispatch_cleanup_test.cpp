#include "zone_dispatch_fixture_common.h"

static void test_child_slot_null_hole_and_sequence() {
    DispatchLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.child_count = 1;
    zm.width = 4; zm.height = 4;
    zm.f_8EAE = 1; zm.f_8EB0 = 1;
    g_expected_zm = &zm;

    char child_struct[0x60];
    std::memset(child_struct, 0, sizeof(child_struct));
    *reinterpret_cast<short *>(child_struct + 0x50) = 3;

    char child0[0xA0], child2[0xA0];
    void *sub_arr[3] = {child0, nullptr, child2};
    *reinterpret_cast<void ***>(child_struct + 0x54) = sub_arr;
    zm.zone_child = child_struct;

    DispatchCell cells[4][4];
    std::memset(cells, 0, sizeof(cells));
    DispatchCell *row_ptrs[4] = {cells[0], cells[1], cells[2], cells[3]};
    zm.cells_ptr = row_ptrs;

    int item1 = 0x11, item2 = 0x22;
    cells[0][1].f_10 = &item1;
    cells[2][3].f_10 = &item2;

    g_eba_calls.clear(); g_seq_log.clear(); g_de30_items.clear();
    g_c9fa0_calls = 0; g_d0430_calls = 0;

    func_001C98A0(&zm, 4, 4);

    // Full 6 child sub-object checks restored (including [1] and [4] offsets +0x80)
    assert(g_eba_calls.size() == 6);
    assert(g_eba_calls[0] == child0 + 0x74);
    assert(g_eba_calls[1] == child0 + 0x80);
    assert(g_eba_calls[2] == child0 + 0x8C);
    assert(g_eba_calls[3] == child2 + 0x74);
    assert(g_eba_calls[4] == child2 + 0x80);
    assert(g_eba_calls[5] == child2 + 0x8C);

    // Strict call sequence: 1D16D0 -> 25DE30 (x2) -> 1D06A0 with self == &zm
    assert(g_seq_log.size() == 4);
    assert(g_seq_log[0] == "1D16D0");
    assert(g_seq_log[1] == "25DE30" && g_seq_log[2] == "25DE30");
    assert(g_seq_log[3] == "1D06A0");
    assert(g_de30_items.size() == 2 && g_de30_items[0] == &item1 && g_de30_items[1] == &item2);

    // Count and args to func_001C9FA0: exactly 1 call with (self, 0, 0, w-1, h-1)
    assert(g_c9fa0_calls == 1);
    assert(g_c9fa0_self == &zm);
    assert(g_c9fa0_x0 == 0 && g_c9fa0_y0 == 0 && g_c9fa0_x1 == 3 && g_c9fa0_y1 == 3);

    // Call and args to AI manager func_3273E0: (D_4E2DEC, count=3, flag=0x40)
    assert(g_3273e0_self == D_4E2DEC);
    assert(g_3273e0_count == 3 && g_3273e0_flag == 0x40);

    // func_1D0430 called exactly once with self == &zm
    assert(g_d0430_calls == 1);
}

static void test_child_subarray_null_handling() {
    DispatchLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.child_count = 1;
    zm.width = 4; zm.height = 4;
    zm.f_8EAE = 1; zm.f_8EB0 = 1;
    g_expected_zm = &zm;

    char child_struct[0x60];
    std::memset(child_struct, 0, sizeof(child_struct));
    *reinterpret_cast<short *>(child_struct + 0x50) = 5;
    *reinterpret_cast<void ***>(child_struct + 0x54) = nullptr;
    zm.zone_child = child_struct;

    DispatchCell cells[4][4];
    std::memset(cells, 0, sizeof(cells));
    DispatchCell *row_ptrs[4] = {cells[0], cells[1], cells[2], cells[3]};
    zm.cells_ptr = row_ptrs;

    g_eba_calls.clear(); g_seq_log.clear();

    func_001C98A0(&zm, 4, 4);

    assert(g_eba_calls.empty());
    assert(!g_seq_log.empty() && g_seq_log[0] == "1D16D0");
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "subarray_null") {
        test_child_subarray_null_handling();
    } else {
        test_child_slot_null_hole_and_sequence();
    }
    return 0;
}
