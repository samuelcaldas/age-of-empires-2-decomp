#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_camera.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_185dc0_ret = 0;
static int s_205ee0_calls = 0;
static TargetObj *s_last_205ee0_target = nullptr;

static int s_1f6510_calls = 0;
static void *s_last_1f6510_self = nullptr;

static int s_v28_calls = 0;
static void *s_last_v28_self = nullptr;
static int s_last_v28_a1 = -1;

static int s_mgr_v18_calls = 0;
static void *s_last_mgr_v18_self = nullptr;
static int s_last_mgr_v18_a1 = -1;
static int s_last_mgr_v18_a2 = -1;

static int s_v108_calls = 0;
static void *s_last_v108_self = nullptr;
static int s_last_v108_a1 = -1;
static int s_last_v108_a2 = -1;
static int s_last_v108_a3 = -1;
static int s_last_v108_t0 = -1;
static int s_last_v108_t1 = -1;

static std::vector<const char*> s_call_order;

extern "C" {
    int func_185DC0(SystemManager *) { return s_185dc0_ret; }
    void func_205EE0(TargetObj *target) {
        s_205ee0_calls++;
        s_last_205ee0_target = target;
        s_call_order.push_back("func_205EE0");
    }
    void func_1F6510(CombatSubsystemControllerInstance *self) {
        s_1f6510_calls++;
        s_last_1f6510_self = self;
        s_call_order.push_back("func_1F6510");
    }
}

static void mock_view_func_28(void *self, int a1) {
    s_v28_calls++;
    s_last_v28_self = self;
    s_last_v28_a1 = a1;
    s_call_order.push_back("func_28");
}

static void mock_view_func_108(void *self, int a1, int a2, int a3, int t0, int t1) {
    s_v108_calls++;
    s_last_v108_self = self;
    s_last_v108_a1 = a1;
    s_last_v108_a2 = a2;
    s_last_v108_a3 = a3;
    s_last_v108_t0 = t0;
    s_last_v108_t1 = t1;
    s_call_order.push_back("func_108");
}

static void mock_mgr_func_18(void *self, int a1, int a2) {
    s_mgr_v18_calls++;
    s_last_mgr_v18_self = self;
    s_last_mgr_v18_a1 = a1;
    s_last_mgr_v18_a2 = a2;
    s_call_order.push_back("mgr_func_18");
}

static CombatSubsystemVtable s_vtable = {
    {}, mock_view_func_28,
    {}, mock_view_func_108
};

static SystemManagerVtable s_mgr_vtable = {
    {}, mock_mgr_func_18
};

static void reset_mocks() {
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_vtable = &s_mgr_vtable;
    s_mgr.m_mode = 4;
    s_mgr.m_field_1CC = 0;
    s_185dc0_ret = 0;
    s_205ee0_calls = 0;
    s_last_205ee0_target = nullptr;
    s_1f6510_calls = 0;
    s_last_1f6510_self = nullptr;
    s_v28_calls = 0;
    s_last_v28_self = nullptr;
    s_last_v28_a1 = -1;
    s_mgr_v18_calls = 0;
    s_last_mgr_v18_self = nullptr;
    s_last_mgr_v18_a1 = -1;
    s_last_mgr_v18_a2 = -1;
    s_v108_calls = 0;
    s_last_v108_self = nullptr;
    s_last_v108_a1 = -1;
    s_last_v108_a2 = -1;
    s_last_v108_a3 = -1;
    s_last_v108_t0 = -1;
    s_last_v108_t1 = -1;
    s_call_order.clear();
}

static void test_mode_gate_rejection() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    // 1. Unsupported mode check (e.g. mode 1)
    s_mgr.m_mode = 1;
    int ret = func_0032BCE0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 0, "unsupported mode must return 0");
    TEST_ASSERT(s_call_order.empty(), "rejected mode must suppress all calls");

    // 2. Manager busy check
    reset_mocks();
    s_185dc0_ret = 1;
    ret = func_0032BCE0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 0, "busy manager must return 0");
    TEST_ASSERT(s_call_order.empty(), "busy manager must suppress all calls");
}

static void test_accepted_modes() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    // Modes 4, 5, 6, 7 are accepted and manager idle (status 0) passes gate
    int modes[] = { 4, 5, 6, 7 };
    for (int m : modes) {
        reset_mocks();
        s_mgr.m_mode = m;
        s_mgr.m_field_1CC = 0; // fallback path
        s_185dc0_ret = 0;
        int ret = func_0032BCE0(&inst, 10, 20, 30, 40);
        TEST_ASSERT(ret == 1, "accepted mode must pass gate and return 1");
        TEST_ASSERT(s_1f6510_calls == 1, "accepted mode must reach fallback func_1F6510");
        TEST_ASSERT(s_call_order.size() == 1, "accepted mode fallback call sequence size mismatch");
        TEST_ASSERT(std::strcmp(s_call_order[0], "func_1F6510") == 0, "accepted mode sole call must be func_1F6510");
    }
}

static void test_state_19_null_target() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_target = nullptr; // null target

    s_mgr.m_field_1CC = 19;

    int ret = func_0032BCE0(&inst, 11, 22, 33, 44);
    TEST_ASSERT(ret == 1, "null target must return 1");
    TEST_ASSERT(s_1f6510_calls == 1, "null target must fallback to func_1F6510 once");
    TEST_ASSERT(s_last_1f6510_self == &inst, "func_1F6510 self mismatch");
    TEST_ASSERT(s_call_order.size() == 1, "null target call sequence must be sole func_1F6510");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_1F6510") == 0, "sole call must be func_1F6510");
    TEST_ASSERT(s_205ee0_calls == 0, "null target must not call func_205EE0");
    TEST_ASSERT(s_v28_calls == 0, "null target must not call view func_28");
    TEST_ASSERT(s_mgr_v18_calls == 0, "null target must not call mgr func_18");
    TEST_ASSERT(s_v108_calls == 0, "null target must not call view func_108");
}

static void test_state_19_with_sub_ca8() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    TargetSubCA8 sub_ca8;
    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    target.m_sub_ca8 = &sub_ca8;
    inst.m_target = &target;

    s_mgr.m_field_1CC = 19; // state 19

    int ret = func_0032BCE0(&inst, 11, 22, 33, 44);
    TEST_ASSERT(ret == 1, "state 19 with sub_ca8 must return 1");
    TEST_ASSERT(s_205ee0_calls == 1, "state 19 must call func_205EE0 once");
    TEST_ASSERT(s_last_205ee0_target == &target, "func_205EE0 target mismatch");
    TEST_ASSERT(s_v28_calls == 1, "state 19 must call view func_28 once");
    TEST_ASSERT(s_last_v28_self == &inst, "view func_28 self mismatch");
    TEST_ASSERT(s_last_v28_a1 == 1, "view func_28 a1 must be 1");
    TEST_ASSERT(s_mgr_v18_calls == 1, "state 19 must call mgr func_18 once");
    TEST_ASSERT(s_last_mgr_v18_self == D_004E3180, "mgr func_18 self mismatch");
    TEST_ASSERT(s_last_mgr_v18_a1 == 19, "mgr func_18 a1 must be 19");
    TEST_ASSERT(s_last_mgr_v18_a2 == 1, "mgr func_18 a2 must be 1");
    TEST_ASSERT(s_v108_calls == 1, "state 19 must call view func_108 once");
    TEST_ASSERT(s_last_v108_self == &inst, "view func_108 self mismatch");
    TEST_ASSERT(s_last_v108_a1 == 9, "view func_108 a1 must be 9");
    TEST_ASSERT(s_last_v108_a2 == 11, "view func_108 a2 mismatch");
    TEST_ASSERT(s_last_v108_a3 == 22, "view func_108 a3 mismatch");
    TEST_ASSERT(s_last_v108_t0 == 33, "view func_108 t0 mismatch");
    TEST_ASSERT(s_last_v108_t1 == 44, "view func_108 t1 mismatch");
    TEST_ASSERT(s_1f6510_calls == 0, "state 19 with sub_ca8 must not call func_1F6510");

    // Call order: func_205EE0 -> func_28 -> mgr_func_18 -> func_108
    TEST_ASSERT(s_call_order.size() == 4, "call order sequence size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_205EE0") == 0, "call order 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_28") == 0, "call order 1 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[2], "mgr_func_18") == 0, "call order 2 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[3], "func_108") == 0, "call order 3 mismatch");
}

static void test_state_19_without_sub_ca8() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    target.m_sub_ca8 = nullptr; // no sub_ca8
    inst.m_target = &target;

    s_mgr.m_field_1CC = 19;

    int ret = func_0032BCE0(&inst, 11, 22, 33, 44);
    TEST_ASSERT(ret == 1, "state 19 without sub_ca8 must return 1");
    TEST_ASSERT(s_1f6510_calls == 1, "state 19 without sub_ca8 must call func_1F6510 once");
    TEST_ASSERT(s_last_1f6510_self == &inst, "func_1F6510 self mismatch");
    TEST_ASSERT(s_call_order.size() == 1, "state 19 without sub_ca8 call sequence size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_1F6510") == 0, "state 19 without sub_ca8 sole call must be func_1F6510");
    TEST_ASSERT(s_205ee0_calls == 0, "without sub_ca8 must not call func_205EE0");
    TEST_ASSERT(s_v28_calls == 0, "without sub_ca8 must not call view func_28");
    TEST_ASSERT(s_mgr_v18_calls == 0, "without sub_ca8 must not call mgr func_18");
    TEST_ASSERT(s_v108_calls == 0, "without sub_ca8 must not call view func_108");
}

static void test_state_not_19() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    s_mgr.m_field_1CC = 0; // state != 19

    int ret = func_0032BCE0(&inst, 11, 22, 33, 44);
    TEST_ASSERT(ret == 1, "state not 19 must return 1");
    TEST_ASSERT(s_1f6510_calls == 1, "state not 19 must call func_1F6510 once");
    TEST_ASSERT(s_last_1f6510_self == &inst, "func_1F6510 self mismatch");
    TEST_ASSERT(s_call_order.size() == 1, "state not 19 call sequence size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_1F6510") == 0, "state not 19 sole call must be func_1F6510");
    TEST_ASSERT(s_205ee0_calls == 0, "state not 19 must not call func_205EE0");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "gate_rejection") == 0) { test_mode_gate_rejection(); return 0; }
        if (std::strcmp(argv[1], "accepted_modes") == 0) { test_accepted_modes(); return 0; }
        if (std::strcmp(argv[1], "state_19_null_target") == 0) { test_state_19_null_target(); return 0; }
        if (std::strcmp(argv[1], "state_19_sub") == 0) { test_state_19_with_sub_ca8(); return 0; }
        if (std::strcmp(argv[1], "state_19_nosub") == 0) { test_state_19_without_sub_ca8(); return 0; }
        if (std::strcmp(argv[1], "state_not_19") == 0) { test_state_not_19(); return 0; }
    }
    test_mode_gate_rejection();
    test_accepted_modes();
    test_state_19_null_target();
    test_state_19_with_sub_ca8();
    test_state_19_without_sub_ca8();
    test_state_not_19();
    return 0;
}
