#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_player_dispatch.h"

static_assert(sizeof(void *) == 4, "requires 32-bit pointers");
static_assert(sizeof(DispatchItem) == 68, "DispatchItem ABI");
static_assert(sizeof(DispatchPlayer) == 6968, "DispatchPlayer ABI");
static_assert(sizeof(DispatchManager) == 25072, "DispatchManager ABI");

static int s_dummy_global = 0;
void *D_004E3180 = &s_dummy_global;

static int s_func_2e05f0_calls = 0;
static int s_func_2d42a0_calls = 0;
static int s_func_2e0630_calls = 0;
static int s_last_cmd_5f0 = -1;
static int s_last_cmd_630 = -1;

extern "C" {
void func_2e05f0(void *player, int cmd, int zero) {
    s_func_2e05f0_calls++;
    s_last_cmd_5f0 = cmd;
    assert(zero == 0);
}

void func_2d42a0(void *field1B34) {
    s_func_2d42a0_calls++;
}

void func_2e0630(void *player, int cmd) {
    s_func_2e0630_calls++;
    s_last_cmd_630 = cmd;
}
} // extern "C"

static void reset_tracking() {
    s_func_2e05f0_calls = 0;
    s_func_2d42a0_calls = 0;
    s_func_2e0630_calls = 0;
    s_last_cmd_5f0 = -1;
    s_last_cmd_630 = -1;
}

static void test_null_player_no_op() {
    reset_tracking();
    DispatchManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    func_00305CB0(&mgr, NULL);
    assert(s_func_2e05f0_calls == 0);
    assert(s_func_2d42a0_calls == 0);
    assert(s_func_2e0630_calls == 0);
}

static void test_invalid_player_id_no_op() {
    reset_tracking();
    DispatchManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    DispatchPlayer player;
    std::memset(&player, 0, sizeof(player));
    player.m_player_id = 0; // 0 - 1 = -1 < 0
    func_00305CB0(&mgr, &player);
    assert(s_func_2e05f0_calls == 0);
    assert(s_func_2d42a0_calls == 0);
    assert(s_func_2e0630_calls == 0);
}

static void test_dispatch_normal_flow() {
    reset_tracking();
    DispatchManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    DispatchPlayer player;
    std::memset(&player, 0, sizeof(player));

    player.m_player_id = 1; // index s0 = 0
    DispatchItem item1;
    std::memset(&item1, 0, sizeof(item1));
    DispatchItem *items[4] = { &item1, NULL, NULL, NULL };
    player.m_item_count = 1;
    player.m_items = items;

    mgr.m_counts[0] = 1;
    mgr.m_data[0][0] = 42;

    mgr.m_counts2[0] = 1;
    mgr.m_data2[0][0] = 0;

    mgr.m_mode[0] = 1;

    // Set D_004E3180 + 456 to non-7
    int dummy_data[200];
    std::memset(dummy_data, 0, sizeof(dummy_data));
    dummy_data[456 / 4] = 0;
    D_004E3180 = dummy_data;

    func_00305CB0(&mgr, &player);

    assert(s_func_2e05f0_calls == 1);
    assert(s_last_cmd_5f0 == 42);
    assert(item1.m_field43 == 1);
    assert(item1.m_field42 == 0);
    assert(s_func_2d42a0_calls == 1);
    assert(s_func_2e0630_calls == 1);
    assert(s_last_cmd_630 == 25);
}

int main() {
    test_null_player_no_op();
    test_invalid_player_id_no_op();
    test_dispatch_normal_flow();
    return 0;
}
