#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_target_dispatch.h"

static_assert(sizeof(void *) == 4, "requires 32-bit pointers");

static int s_is_ally_return = 1;
static int s_is_ally_calls = 0;
static int s_dispatch_calls = 0;
static int s_last_mark = 0;
static int s_last_code = 0;

static int mock_is_ally(void *, int) {
    s_is_ally_calls++;
    return s_is_ally_return;
}

static void *s_diplomacy_vtable[16] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    reinterpret_cast<void *>(mock_is_ally), // slot 9
    0
};

static TargetPlayerManager s_renderer_mgr;
void *D_004E3180 = &s_renderer_mgr;

extern "C" {
void *func_186010(void *global) {
    assert(global == D_004E3180);
    return &s_renderer_mgr;
}

void func_1a4960(void *, int, int, int mark, int action_code, TargetEntity *) {
    s_dispatch_calls++;
    s_last_mark = mark;
    s_last_code = action_code;
}
}

static void reset_tracking() {
    s_is_ally_return = 1;
    s_is_ally_calls = 0;
    s_dispatch_calls = 0;
    s_last_mark = 0;
    s_last_code = 0;
    s_renderer_mgr.m_diplomacy_vtable = s_diplomacy_vtable;
}

static void test_not_allied_type80_aborts() {
    TargetScanManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));

    TargetTypeDesc desc;
    std::memset(&desc, 0, sizeof(desc));
    desc.m_type_code = 80;

    TargetEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    ent.m_type_desc = &desc;
    ent.m_field368 = 0.0f;
    *reinterpret_cast<unsigned char *>(reinterpret_cast<char *>(&ent) + 57) = 0; // flag57 = 0

    reset_tracking();
    s_is_ally_return = 0; // not allied

    func_003088A0(&mgr, 10, 20, 30, 40, &ent);

    assert(s_is_ally_calls == 1);
    assert(s_dispatch_calls == 0); // aborted early
}

static void test_mode_4_and_100_mark_resolution() {
    TargetScanManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));

    TargetEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    *reinterpret_cast<unsigned char *>(reinterpret_cast<char *>(&ent) + 57) = 1; // flag57 = 1 (bypass type 80 check)

    // Mode 4 with m_field1A0 == 0 -> mark 69
    mgr.m_field184 = 4;
    mgr.m_field1A0 = 0;
    reset_tracking();
    func_003088A0(&mgr, 1, 2, 30, 10, &ent);
    assert(s_dispatch_calls == 1 && s_last_mark == 69);

    // Mode 100 with m_field1A0 == 0 -> mark 70
    mgr.m_field184 = 100;
    mgr.m_field1A0 = 0;
    reset_tracking();
    func_003088A0(&mgr, 1, 2, 30, 10, &ent);
    assert(s_dispatch_calls == 1 && s_last_mark == 70);

    // Mode 100 with m_field1A0 == 1 -> mark 69
    mgr.m_field184 = 100;
    mgr.m_field1A0 = 1;
    reset_tracking();
    func_003088A0(&mgr, 1, 2, 30, 10, &ent);
    assert(s_dispatch_calls == 1 && s_last_mark == 69);
}

static void test_action_code_override_special_ids() {
    TargetScanManager mgr;
    std::memset(&mgr, 0, sizeof(mgr));

    TargetTypeDesc desc276;
    std::memset(&desc276, 0, sizeof(desc276));
    desc276.m_id = 276;

    TargetEntity ent;
    std::memset(&ent, 0, sizeof(ent));
    ent.m_type_desc = &desc276;
    *reinterpret_cast<unsigned char *>(reinterpret_cast<char *>(&ent) + 57) = 1;

    // ID 276 overrides action code to 4
    reset_tracking();
    func_003088A0(&mgr, 1, 2, 30, 99, &ent);
    assert(s_dispatch_calls == 1 && s_last_code == 4);

    // ID 104 with m_field364 > 0 overrides action code to 4
    TargetTypeDesc desc104;
    std::memset(&desc104, 0, sizeof(desc104));
    desc104.m_id = 104;
    ent.m_type_desc = &desc104;
    ent.m_field364 = 5;

    reset_tracking();
    func_003088A0(&mgr, 1, 2, 30, 99, &ent);
    assert(s_dispatch_calls == 1 && s_last_code == 4);
}

int main() {
    test_not_allied_type80_aborts();
    test_mode_4_and_100_mark_resolution();
    test_action_code_override_special_ids();
    return 0;
}
