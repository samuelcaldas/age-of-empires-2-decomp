#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_event.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_185dc0_ret = 0;
static int s_1f65a0_calls = 0;
static void *s_last_1f65a0_self = nullptr;

static int s_v28_calls = 0;
static void *s_last_v28_self = nullptr;
static int s_last_v28_a1 = -1;

static int s_v108_calls = 0;
static int s_last_v108_a1 = -1;
static int s_last_v108_a2 = -1;
static int s_last_v108_a3 = -1;
static int s_last_v108_t0 = -1;
static int s_last_v108_t1 = -1;

static int s_v10c_calls = 0;
static int s_last_v10c_a1 = -1;
static int s_last_v10c_a2 = -1;

static int s_v110_calls = 0;
static void *s_last_v110_self = nullptr;
static std::vector<const char*> s_call_order;

extern "C" {
    int func_185DC0(SystemManager *) { return s_185dc0_ret; }
    void func_1F65A0(CombatSubsystemControllerInstance *self) {
        s_1f65a0_calls++;
        s_last_1f65a0_self = self;
        s_call_order.push_back("func_1F65A0");
    }
}

static void mock_view_func_28(void *self, int a1) {
    s_v28_calls++;
    s_last_v28_self = self;
    s_last_v28_a1 = a1;
    s_call_order.push_back("func_28");
}

static void mock_view_func_108(void *, int a1, int a2, int a3, int t0, int t1) {
    s_v108_calls++;
    s_last_v108_a1 = a1;
    s_last_v108_a2 = a2;
    s_last_v108_a3 = a3;
    s_last_v108_t0 = t0;
    s_last_v108_t1 = t1;
    s_call_order.push_back("func_108");
}

static void mock_view_func_10c(void *, int a1, int a2) {
    s_v10c_calls++;
    s_last_v10c_a1 = a1;
    s_last_v10c_a2 = a2;
    s_call_order.push_back("func_10C");
}

static void mock_view_func_110(void *self) {
    s_v110_calls++;
    s_last_v110_self = self;
    s_call_order.push_back("func_110");
}

static CombatSubsystemVtable s_vtable = {
    {}, mock_view_func_28,
    {}, mock_view_func_108,
    mock_view_func_10c,
    mock_view_func_110
};

static void reset_mocks() {
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_mode = 4;
    s_mgr.m_field_1CC = 0;
    s_185dc0_ret = 0;
    s_1f65a0_calls = 0;
    s_last_1f65a0_self = nullptr;
    s_v28_calls = 0;
    s_last_v28_self = nullptr;
    s_last_v28_a1 = -1;
    s_v108_calls = 0;
    s_last_v108_a1 = -1;
    s_last_v108_a2 = -1;
    s_last_v108_a3 = -1;
    s_last_v108_t0 = -1;
    s_last_v108_t1 = -1;
    s_v10c_calls = 0;
    s_last_v10c_a1 = -1;
    s_last_v10c_a2 = -1;
    s_v110_calls = 0;
    s_last_v110_self = nullptr;
    s_call_order.clear();
}

static void test_mode_gate_rejection() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;

    // Unsupported mode (e.g. mode 1)
    s_mgr.m_mode = 1;
    int ret = func_0032A8F0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 0, "unsupported mode must return 0");
    TEST_ASSERT(s_1f65a0_calls == 0, "rejected mode must not call func_1F65A0");
}

static void test_manager_busy_branches() {
    // 1. Busy + field_190 != 0 -> calls func_110
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 1;
    s_185dc0_ret = 1;

    int ret = func_0032A8F0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 0, "busy manager branch must return 0");
    TEST_ASSERT(s_v110_calls == 1, "busy with field_190 must call func_110");
    TEST_ASSERT(s_last_v110_self == &inst, "func_110 self mismatch");
    TEST_ASSERT(s_1f65a0_calls == 0, "busy with field_190 must not call func_1F65A0");
    TEST_ASSERT(s_call_order.size() == 1, "busy with field_190 call count mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_110") == 0, "call order must be func_110");

    // 2. Busy + field_190 == 0 -> calls func_1F65A0
    reset_mocks();
    inst.m_field_190 = 0;
    s_185dc0_ret = 1;

    ret = func_0032A8F0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 0, "busy manager zero field_190 must return 0");
    TEST_ASSERT(s_1f65a0_calls == 1, "busy zero field_190 must call func_1F65A0");
    TEST_ASSERT(s_last_1f65a0_self == &inst, "func_1F65A0 self mismatch");
    TEST_ASSERT(s_v110_calls == 0, "busy zero field_190 must not call func_110");
    TEST_ASSERT(s_call_order.size() == 1, "busy zero field_190 call count mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_1F65A0") == 0, "call order must be func_1F65A0");
}

static void test_manager_idle_field_190() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 1;
    s_185dc0_ret = 0;

    int ret = func_0032A8F0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 1, "idle field_190 must return 1");
    TEST_ASSERT(s_v10c_calls == 1, "idle field_190 must call func_10C");
    TEST_ASSERT(s_last_v10c_a1 == 10, "func_10C a1 mismatch");
    TEST_ASSERT(s_last_v10c_a2 == 20, "func_10C a2 mismatch");
}

static void test_manager_idle_state_1_7_8() {
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 0;
    s_185dc0_ret = 0;

    // State 1
    reset_mocks();
    s_mgr.m_field_1CC = 1;
    int ret = func_0032A8F0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 1, "state 1 must return 1");
    TEST_ASSERT(s_v28_calls == 1, "state 1 must call func_28");
    TEST_ASSERT(s_last_v28_a1 == 1, "func_28 a1 mismatch");

    // State 7
    reset_mocks();
    s_mgr.m_field_1CC = 7;
    ret = func_0032A8F0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 1, "state 7 must return 1");
    TEST_ASSERT(s_v28_calls == 1, "state 7 must call func_28");

    // State 8
    reset_mocks();
    s_mgr.m_field_1CC = 8;
    ret = func_0032A8F0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 1, "state 8 must return 1");
    TEST_ASSERT(s_v28_calls == 1, "state 8 must call func_28");
}

static void test_manager_idle_state_0() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 0;
    s_185dc0_ret = 0;
    s_mgr.m_field_1CC = 0;

    int ret = func_0032A8F0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 1, "state 0 must return 1");
    TEST_ASSERT(s_v28_calls == 0, "state 0 must not call func_28");
    TEST_ASSERT(s_1f65a0_calls == 0, "state 0 must not call func_1F65A0");
}

static void test_manager_idle_state_other() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 0;
    inst.m_field_E0 = 100;
    inst.m_field_E4 = 200;
    s_185dc0_ret = 0;
    s_mgr.m_field_1CC = 18; // other state

    int ret = func_0032A8F0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 1, "state other must return 1");
    TEST_ASSERT(s_1f65a0_calls == 1, "state other must call func_1F65A0");
    TEST_ASSERT(s_v108_calls == 1, "state other must call func_108");
    TEST_ASSERT(s_last_v108_a1 == 2, "func_108 a1 must be 2");
    TEST_ASSERT(s_last_v108_a2 == 100, "func_108 a2 must match field_E0");
    TEST_ASSERT(s_last_v108_a3 == 200, "func_108 a3 must match field_E4");
    TEST_ASSERT(s_last_v108_t0 == 30, "func_108 t0 must match a3");
    TEST_ASSERT(s_last_v108_t1 == 40, "func_108 t1 must match a4");
    TEST_ASSERT(s_v10c_calls == 1, "state other must call func_10C");
    TEST_ASSERT(s_last_v10c_a1 == 10, "func_10C a1 mismatch");
    TEST_ASSERT(s_last_v10c_a2 == 20, "func_10C a2 mismatch");

    // Call order verification: func_1F65A0 -> func_108 -> func_10C
    TEST_ASSERT(s_call_order.size() == 3, "state other call sequence length mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_1F65A0") == 0, "call order 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_108") == 0, "call order 1 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[2], "func_10C") == 0, "call order 2 mismatch");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "gate_rejection") == 0) { test_mode_gate_rejection(); return 0; }
        if (std::strcmp(argv[1], "busy_branches") == 0) { test_manager_busy_branches(); return 0; }
        if (std::strcmp(argv[1], "idle_field_190") == 0) { test_manager_idle_field_190(); return 0; }
        if (std::strcmp(argv[1], "idle_state_1_7_8") == 0) { test_manager_idle_state_1_7_8(); return 0; }
        if (std::strcmp(argv[1], "idle_state_0") == 0) { test_manager_idle_state_0(); return 0; }
        if (std::strcmp(argv[1], "idle_state_other") == 0) { test_manager_idle_state_other(); return 0; }
    }
    test_mode_gate_rejection();
    test_manager_busy_branches();
    test_manager_idle_field_190();
    test_manager_idle_state_1_7_8();
    test_manager_idle_state_0();
    test_manager_idle_state_other();
    return 0;
}
