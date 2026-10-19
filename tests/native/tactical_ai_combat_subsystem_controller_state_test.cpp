#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include "tactical_ai_combat_subsystem_controller_state.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_func28_calls = 0;
static void *s_last_func28_self = nullptr;
static int s_last_func28_a1 = -1;

static void mock_view_func_28(void *self, int a1) {
    s_func28_calls++;
    s_last_func28_self = self;
    s_last_func28_a1 = a1;
}

static ViewVtable s_vtable = { {}, mock_view_func_28 };

static void reset_mocks() {
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_mode = 4;
    s_mgr.m_field_1CC = 0;
    s_func28_calls = 0;
    s_last_func28_self = nullptr;
    s_last_func28_a1 = -1;
}

static void test_mode_gate_rejection() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;

    // Mode 1 (unsupported)
    s_mgr.m_mode = 1;
    s_mgr.m_field_1CC = 1; // even if field_1CC matches, gate must reject
    int ret = func_00329FA0(&inst);
    TEST_ASSERT(ret == 0, "unsupported mode must return 0");
    TEST_ASSERT(s_func28_calls == 0, "rejected gate must not call func_28");

    // Mode 0 (unsupported)
    reset_mocks();
    s_mgr.m_mode = 0;
    s_mgr.m_field_1CC = 7;
    ret = func_00329FA0(&inst);
    TEST_ASSERT(ret == 0, "mode 0 must return 0");
    TEST_ASSERT(s_func28_calls == 0, "mode 0 must not call func_28");
}

static void test_field_1cc_cases() {
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;

    // Case 1: field_1CC == 1
    reset_mocks();
    s_mgr.m_mode = 4;
    s_mgr.m_field_1CC = 1;
    int ret = func_00329FA0(&inst);
    TEST_ASSERT(ret == 1, "field_1CC 1 must return 1");
    TEST_ASSERT(s_func28_calls == 1, "field_1CC 1 must call func_28 once");
    TEST_ASSERT(s_last_func28_self == &inst, "func_28 self mismatch");
    TEST_ASSERT(s_last_func28_a1 == 1, "func_28 argument must be 1");

    // Case 2: field_1CC == 7
    reset_mocks();
    s_mgr.m_mode = 6;
    s_mgr.m_field_1CC = 7;
    ret = func_00329FA0(&inst);
    TEST_ASSERT(ret == 1, "field_1CC 7 must return 1");
    TEST_ASSERT(s_func28_calls == 1, "field_1CC 7 must call func_28 once");
    TEST_ASSERT(s_last_func28_a1 == 1, "field_1CC 7 argument must be 1");

    // Case 3: field_1CC == 8
    reset_mocks();
    s_mgr.m_mode = 5;
    s_mgr.m_field_1CC = 8;
    ret = func_00329FA0(&inst);
    TEST_ASSERT(ret == 1, "field_1CC 8 must return 1");
    TEST_ASSERT(s_func28_calls == 1, "field_1CC 8 must call func_28 once");
    TEST_ASSERT(s_last_func28_a1 == 1, "field_1CC 8 argument must be 1");
}

static void test_field_1cc_other() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;

    // field_1CC == 0
    s_mgr.m_mode = 4;
    s_mgr.m_field_1CC = 0;
    int ret = func_00329FA0(&inst);
    TEST_ASSERT(ret == 1, "field_1CC 0 must return 1");
    TEST_ASSERT(s_func28_calls == 0, "field_1CC 0 must not call func_28");

    // field_1CC == 2
    reset_mocks();
    s_mgr.m_mode = 7;
    s_mgr.m_field_1CC = 2;
    ret = func_00329FA0(&inst);
    TEST_ASSERT(ret == 1, "field_1CC 2 must return 1");
    TEST_ASSERT(s_func28_calls == 0, "field_1CC 2 must not call func_28");

    // field_1CC == 18
    reset_mocks();
    s_mgr.m_mode = 4;
    s_mgr.m_field_1CC = 18;
    ret = func_00329FA0(&inst);
    TEST_ASSERT(ret == 1, "field_1CC 18 must return 1");
    TEST_ASSERT(s_func28_calls == 0, "field_1CC 18 must not call func_28");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "gate_rejection") == 0) { test_mode_gate_rejection(); return 0; }
        if (std::strcmp(argv[1], "cases_1_7_8") == 0) { test_field_1cc_cases(); return 0; }
        if (std::strcmp(argv[1], "other_cases") == 0) { test_field_1cc_other(); return 0; }
    }
    test_mode_gate_rejection();
    test_field_1cc_cases();
    test_field_1cc_other();
    return 0;
}
