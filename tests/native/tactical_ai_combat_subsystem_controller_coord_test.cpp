#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_coord.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_185dc0_ret = 0;
static int s_185dc0_calls = 0;
static SystemManager *s_last_185dc0_mgr = nullptr;

static int s_1f65a0_calls = 0;
static void *s_last_1f65a0_self = nullptr;

static int s_v10c_calls = 0;
static void *s_last_v10c_self = nullptr;
static int s_last_v10c_a1 = -1;
static int s_last_v10c_a2 = -1;

static int s_v110_calls = 0;
static void *s_last_v110_self = nullptr;

static std::vector<const char*> s_call_order;

extern "C" {
    int func_185DC0(SystemManager *mgr) {
        s_185dc0_calls++;
        s_last_185dc0_mgr = mgr;
        s_call_order.push_back("func_185DC0");
        return s_185dc0_ret;
    }
    void func_1F65A0(CombatSubsystemControllerInstance *self) {
        s_1f65a0_calls++;
        s_last_1f65a0_self = self;
        s_call_order.push_back("func_1F65A0");
    }
}

static void mock_view_func_10c(void *self, int a1, int a2) {
    s_v10c_calls++;
    s_last_v10c_self = self;
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
    {}, mock_view_func_10c, mock_view_func_110
};

static void reset_mocks() {
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_mode = 4;
    s_185dc0_ret = 0;
    s_185dc0_calls = 0;
    s_last_185dc0_mgr = nullptr;
    s_1f65a0_calls = 0;
    s_last_1f65a0_self = nullptr;
    s_v10c_calls = 0;
    s_last_v10c_self = nullptr;
    s_last_v10c_a1 = -1;
    s_last_v10c_a2 = -1;
    s_v110_calls = 0;
    s_last_v110_self = nullptr;
    s_call_order.clear();
}

static void test_gate_rejection() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 1;

    int rejected_modes[] = { 0, 1, 2, 3, 8 };
    for (int m : rejected_modes) {
        reset_mocks();
        s_mgr.m_mode = m;
        int ret = func_0032BE50(&inst, 10, 20);
        TEST_ASSERT(ret == 0, "unsupported mode must return 0");
        TEST_ASSERT(s_call_order.empty(), "rejected mode must suppress all calls");
    }
}

static void test_busy_manager_active_field() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 1; // active

    s_185dc0_ret = 1; // busy manager

    int ret = func_0032BE50(&inst, 11, 22);
    TEST_ASSERT(ret == 0, "busy manager with active field must return 0");
    TEST_ASSERT(s_185dc0_calls == 1, "must call func_185DC0 once");
    TEST_ASSERT(s_last_185dc0_mgr == D_004E3180, "func_185DC0 must receive D_004E3180");
    TEST_ASSERT(s_v110_calls == 1, "must call func_110 once");
    TEST_ASSERT(s_last_v110_self == &inst, "func_110 self mismatch");
    TEST_ASSERT(s_1f65a0_calls == 0, "must not call func_1F65A0");
    TEST_ASSERT(s_v10c_calls == 0, "must not call func_10C");
    TEST_ASSERT(s_call_order.size() == 2, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_185DC0") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_110") == 0, "call 1 mismatch");
}

static void test_busy_manager_inactive_field() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 0; // inactive

    s_185dc0_ret = 1; // busy manager

    int ret = func_0032BE50(&inst, 11, 22);
    TEST_ASSERT(ret == 0, "busy manager with inactive field must return 0");
    TEST_ASSERT(s_185dc0_calls == 1, "must call func_185DC0 once");
    TEST_ASSERT(s_last_185dc0_mgr == D_004E3180, "func_185DC0 must receive D_004E3180");
    TEST_ASSERT(s_1f65a0_calls == 1, "must call func_1F65A0 once");
    TEST_ASSERT(s_last_1f65a0_self == &inst, "func_1F65A0 self mismatch");
    TEST_ASSERT(s_v110_calls == 0, "must not call func_110");
    TEST_ASSERT(s_v10c_calls == 0, "must not call func_10C");
    TEST_ASSERT(s_call_order.size() == 2, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_185DC0") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_1F65A0") == 0, "call 1 mismatch");
}

static void test_idle_manager_inactive_field() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 0; // inactive

    s_185dc0_ret = 0; // idle manager

    int ret = func_0032BE50(&inst, 11, 22);
    TEST_ASSERT(ret == 0, "idle manager with inactive field must return 0");
    TEST_ASSERT(s_185dc0_calls == 1, "must call func_185DC0 once");
    TEST_ASSERT(s_last_185dc0_mgr == D_004E3180, "func_185DC0 must receive D_004E3180");
    TEST_ASSERT(s_v10c_calls == 0, "must not call func_10C");
    TEST_ASSERT(s_v110_calls == 0, "must not call func_110");
    TEST_ASSERT(s_1f65a0_calls == 0, "must not call func_1F65A0");
    TEST_ASSERT(s_call_order.size() == 1, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_185DC0") == 0, "call 0 mismatch");
}

static void test_idle_manager_active_field() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 1; // active

    s_185dc0_ret = 0; // idle manager

    int ret = func_0032BE50(&inst, 33, 44);
    TEST_ASSERT(ret == 1, "idle manager with active field must return 1");
    TEST_ASSERT(s_185dc0_calls == 1, "must call func_185DC0 once");
    TEST_ASSERT(s_last_185dc0_mgr == D_004E3180, "func_185DC0 must receive D_004E3180");
    TEST_ASSERT(s_v10c_calls == 1, "must call func_10C once");
    TEST_ASSERT(s_last_v10c_self == &inst, "func_10C self mismatch");
    TEST_ASSERT(s_last_v10c_a1 == 33, "func_10C a1 mismatch");
    TEST_ASSERT(s_last_v10c_a2 == 44, "func_10C a2 mismatch");
    TEST_ASSERT(s_v110_calls == 0, "must not call func_110");
    TEST_ASSERT(s_1f65a0_calls == 0, "must not call func_1F65A0");
    TEST_ASSERT(s_call_order.size() == 2, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_185DC0") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_10C") == 0, "call 1 mismatch");
}

static void test_accepted_modes() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 1;

    int accepted_modes[] = { 4, 5, 6, 7 };
    for (int m : accepted_modes) {
        reset_mocks();
        s_mgr.m_mode = m;
        s_185dc0_ret = 0;
        int ret = func_0032BE50(&inst, 10, 20);
        TEST_ASSERT(ret == 1, "accepted mode must return 1 when active");
        TEST_ASSERT(s_v10c_calls == 1, "accepted mode must reach func_10C");
    }
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "gate_rejection") == 0) { test_gate_rejection(); return 0; }
        if (std::strcmp(argv[1], "busy_active") == 0) { test_busy_manager_active_field(); return 0; }
        if (std::strcmp(argv[1], "busy_inactive") == 0) { test_busy_manager_inactive_field(); return 0; }
        if (std::strcmp(argv[1], "idle_inactive") == 0) { test_idle_manager_inactive_field(); return 0; }
        if (std::strcmp(argv[1], "idle_active") == 0) { test_idle_manager_active_field(); return 0; }
        if (std::strcmp(argv[1], "accepted_modes") == 0) { test_accepted_modes(); return 0; }
    }
    test_gate_rejection();
    test_accepted_modes();
    test_busy_manager_active_field();
    test_busy_manager_inactive_field();
    test_idle_manager_inactive_field();
    test_idle_manager_active_field();
    return 0;
}
