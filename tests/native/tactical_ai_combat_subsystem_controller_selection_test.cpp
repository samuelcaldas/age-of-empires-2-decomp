#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_selection.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;
static int s_dummy_2ea0 = 0;
void *D_004E2EA0 = &s_dummy_2ea0;

static int s_185dc0_ret = 0;
static int s_185dc0_calls = 0;
static int s_1f65a0_calls = 0;
static void *s_last_1f65a0_self = nullptr;
static int s_225590_calls = 0;
static int s_last_225590_a0 = -1;
static int s_v110_calls = 0;
static void *s_last_v110_self = nullptr;
static std::vector<const char*> s_call_order;

extern "C" {
    int func_185DC0(SystemManager *) {
        s_185dc0_calls++;
        s_call_order.push_back("func_185DC0");
        return s_185dc0_ret;
    }
    void func_1F65A0(CombatSubsystemControllerInstance *self) {
        s_1f65a0_calls++;
        s_last_1f65a0_self = self;
        s_call_order.push_back("func_1F65A0");
    }
    int func_225590(int a0) {
        s_225590_calls++;
        s_last_225590_a0 = a0;
        s_call_order.push_back("func_225590");
        return 0;
    }
    int func_0032D400(CombatSubsystemControllerInstance *, int, int, int, int, void *, void *) { return 0; }
    void func_205EE0(TargetObj *) {}
    void func_205CA0(TargetObj *, void *, int) {}
    void func_205F70(TargetObj *, void *) {}
    void func_2066E0(void *, void *, void *) {}
    void func_205B30(TargetObj *, void *) {}
    void func_001830E0(void *) {}
    void func_00262FA0(void *, void *, void *) {}
    int func_123350(float) { return 0; }
    void func_1378C0(void *, void *) {}
    void func_0032E580(CombatSubsystemControllerInstance *, void *) {}
    void func_0032E6B0(CombatSubsystemControllerInstance *) {}
}

static void mock_view_func_110(void *self) {
    s_v110_calls++;
    s_last_v110_self = self;
    s_call_order.push_back("func_110");
}

static CombatSubsystemVtable s_vtable = {
    {}, nullptr, {}, nullptr, nullptr, mock_view_func_110
};

static void reset_mocks() {
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_mode = 4;
    s_mgr.m_field_1CC = 0;
    s_185dc0_ret = 0;
    s_185dc0_calls = 0;
    s_1f65a0_calls = 0;
    s_last_1f65a0_self = nullptr;
    s_225590_calls = 0;
    s_last_225590_a0 = -1;
    s_v110_calls = 0;
    s_last_v110_self = nullptr;
    s_call_order.clear();
}

static void test_gate_rejection() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    // Mode 1 (unsupported)
    reset_mocks();
    s_mgr.m_mode = 1;
    int ret = func_0032AAD0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 0, "unsupported mode must return 0");
    TEST_ASSERT(s_call_order.empty(), "rejected gate must suppress all calls");

    // Mode 0 (unsupported)
    reset_mocks();
    s_mgr.m_mode = 0;
    ret = func_0032AAD0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 0, "unsupported mode must return 0");
    TEST_ASSERT(s_call_order.empty(), "rejected mode 0 must suppress all calls");

    // Mode 2 (unsupported)
    reset_mocks();
    s_mgr.m_mode = 2;
    ret = func_0032AAD0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 0, "unsupported mode must return 0");
    TEST_ASSERT(s_call_order.empty(), "rejected mode 2 must suppress all calls");
}

static void test_supported_modes() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    // Modes 4, 5, 6, 7 are supported
    int modes[] = { 4, 5, 6, 7 };
    for (int m : modes) {
        reset_mocks();
        s_mgr.m_mode = m;
        int ret = func_0032AAD0(&inst, 10, 20, 30, 40);
        TEST_ASSERT(ret == 1, "supported mode must pass gate and return 1");
        TEST_ASSERT(s_1f65a0_calls == 1, "supported mode must call func_1F65A0");
        TEST_ASSERT(s_185dc0_calls == 1, "supported mode must call func_185DC0");
    }
}

static void test_field_190_branch() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 1;

    int ret = func_0032AAD0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 1, "field_190 branch must return 1");
    TEST_ASSERT(s_v110_calls == 1, "field_190 branch must call func_110");
    TEST_ASSERT(s_last_v110_self == &inst, "func_110 self mismatch");

    // Early exit suppresses func_1F65A0, func_185DC0, and func_225590
    TEST_ASSERT(s_call_order.size() == 1, "field_190 call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_110") == 0, "field_190 must only call func_110");
    TEST_ASSERT(s_1f65a0_calls == 0, "field_190 branch must suppress func_1F65A0");
    TEST_ASSERT(s_185dc0_calls == 0, "field_190 branch must suppress func_185DC0");
    TEST_ASSERT(s_225590_calls == 0, "field_190 branch must suppress func_225590");
}

static void test_field_190_zero_busy_manager() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 0;
    s_185dc0_ret = 1; // busy

    int ret = func_0032AAD0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 0, "busy manager path must return 0");
    TEST_ASSERT(s_1f65a0_calls == 1, "busy manager path must call func_1F65A0");
    TEST_ASSERT(s_last_1f65a0_self == &inst, "func_1F65A0 self mismatch");
    TEST_ASSERT(s_185dc0_calls == 1, "busy manager path must call func_185DC0");

    // Early exit suppresses func_225590
    TEST_ASSERT(s_225590_calls == 0, "busy manager path must suppress func_225590");
    TEST_ASSERT(s_call_order.size() == 2, "busy manager call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_1F65A0") == 0, "call order 0 must be func_1F65A0");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_185DC0") == 0, "call order 1 must be func_185DC0");
}

static void test_field_190_zero_idle_manager() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 0;
    s_185dc0_ret = 0; // idle

    int ret = func_0032AAD0(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 1, "idle manager path must return 1");
    TEST_ASSERT(s_1f65a0_calls == 1, "idle manager path must call func_1F65A0");
    TEST_ASSERT(s_185dc0_calls == 1, "idle manager path must call func_185DC0");
    TEST_ASSERT(s_225590_calls == 1, "idle manager path must call func_225590");
    TEST_ASSERT(s_last_225590_a0 == 18, "func_225590 argument must be 18");

    // Full call order: func_1F65A0 -> func_185DC0 -> func_225590
    TEST_ASSERT(s_call_order.size() == 3, "idle manager call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_1F65A0") == 0, "idle order 0 must be func_1F65A0");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_185DC0") == 0, "idle order 1 must be func_185DC0");
    TEST_ASSERT(std::strcmp(s_call_order[2], "func_225590") == 0, "idle order 2 must be func_225590");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "gate_rejection") == 0) { test_gate_rejection(); return 0; }
        if (std::strcmp(argv[1], "supported_modes") == 0) { test_supported_modes(); return 0; }
        if (std::strcmp(argv[1], "field_190_branch") == 0) { test_field_190_branch(); return 0; }
        if (std::strcmp(argv[1], "busy_manager") == 0) { test_field_190_zero_busy_manager(); return 0; }
        if (std::strcmp(argv[1], "idle_manager") == 0) { test_field_190_zero_idle_manager(); return 0; }
    }
    test_gate_rejection();
    test_supported_modes();
    test_field_190_branch();
    test_field_190_zero_busy_manager();
    test_field_190_zero_idle_manager();
    return 0;
}
