#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_pulse.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_323860_ret = 1;
static int s_323860_calls = 0;
static void *s_last_323860_self = nullptr;

static int s_v28_calls = 0;
static void *s_last_v28_self = nullptr;
static int s_last_v28_a1 = -1;

static int s_1880d0_ret = 1;
static int s_1880d0_calls = 0;
static SystemManager *s_last_1880d0_mgr = nullptr;

static int s_184c10_ret = 1;
static int s_184c10_calls = 0;
static SystemManager *s_last_184c10_mgr = nullptr;

static int s_184bd0_ret = 100;
static int s_184bd0_calls = 0;
static SystemManager *s_last_184bd0_mgr = nullptr;
static int s_last_184bd0_a1 = -1;

static int s_185dc0_ret = 0;
static int s_185dc0_calls = 0;
static SystemManager *s_last_185dc0_mgr = nullptr;

static int s_185f00_calls = 0;
static SystemManager *s_last_185f00_mgr = nullptr;
static int s_last_185f00_a1 = -1;
static int s_last_185f00_a2 = -1;

static std::vector<const char*> s_call_order;

extern "C" {
    int func_00323860(CombatSubsystemControllerInstance *self) {
        s_323860_calls++;
        s_last_323860_self = self;
        s_call_order.push_back("func_00323860");
        return s_323860_ret;
    }
    int func_1880D0(SystemManager *mgr) {
        s_1880d0_calls++;
        s_last_1880d0_mgr = mgr;
        s_call_order.push_back("func_1880D0");
        return s_1880d0_ret;
    }
    int func_184C10(SystemManager *mgr) {
        s_184c10_calls++;
        s_last_184c10_mgr = mgr;
        s_call_order.push_back("func_184C10");
        return s_184c10_ret;
    }
    int func_184BD0(SystemManager *mgr, int a1) {
        s_184bd0_calls++;
        s_last_184bd0_mgr = mgr;
        s_last_184bd0_a1 = a1;
        s_call_order.push_back("func_184BD0");
        return s_184bd0_ret;
    }
    int func_185DC0(SystemManager *mgr) {
        s_185dc0_calls++;
        s_last_185dc0_mgr = mgr;
        s_call_order.push_back("func_185DC0");
        return s_185dc0_ret;
    }
    void func_185F00(SystemManager *mgr, int a1, int a2) {
        s_185f00_calls++;
        s_last_185f00_mgr = mgr;
        s_last_185f00_a1 = a1;
        s_last_185f00_a2 = a2;
        s_call_order.push_back("func_185F00");
    }
}

static void mock_view_func_28(void *self, int a1) {
    s_v28_calls++;
    s_last_v28_self = self;
    s_last_v28_a1 = a1;
    s_call_order.push_back("func_28");
}

static ViewVtable s_view_vtable = {
    {}, mock_view_func_28
};

static void reset_mocks() {
    s_323860_ret = 1;
    s_323860_calls = 0;
    s_last_323860_self = nullptr;
    s_v28_calls = 0;
    s_last_v28_self = nullptr;
    s_last_v28_a1 = -1;
    s_1880d0_ret = 1;
    s_1880d0_calls = 0;
    s_last_1880d0_mgr = nullptr;
    s_184c10_ret = 1;
    s_184c10_calls = 0;
    s_last_184c10_mgr = nullptr;
    s_184bd0_ret = 100;
    s_184bd0_calls = 0;
    s_last_184bd0_mgr = nullptr;
    s_last_184bd0_a1 = -1;
    s_185dc0_ret = 0;
    s_185dc0_calls = 0;
    s_last_185dc0_mgr = nullptr;
    s_185f00_calls = 0;
    s_last_185f00_mgr = nullptr;
    s_last_185f00_a1 = -1;
    s_last_185f00_a2 = -1;
    s_call_order.clear();
}

static void test_return_propagation() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    s_323860_ret = 42;
    int ret = func_0032C320(&inst);
    TEST_ASSERT(ret == 42, "must propagate func_00323860 return value 42");
    TEST_ASSERT(s_323860_calls == 1, "must call func_00323860 once");
    TEST_ASSERT(s_last_323860_self == &inst, "func_00323860 self mismatch");
}

static void test_view_callback() {
    // 1. ret != 0 with view present -> calls view func_28
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    ViewObj view;
    view.m_vtable = &s_view_vtable;
    inst.m_view = &view;
    s_323860_ret = 1;

    int ret = func_0032C320(&inst);
    TEST_ASSERT(ret == 1, "return must match func_00323860");
    TEST_ASSERT(s_v28_calls == 1, "must call view func_28 once");
    TEST_ASSERT(s_last_v28_self == &view, "view func_28 self mismatch");
    TEST_ASSERT(s_last_v28_a1 == 1, "view func_28 a1 must be 1");

    // 2. ret == 0 with view present -> suppresses view func_28
    reset_mocks();
    inst.m_view = &view;
    s_323860_ret = 0;
    ret = func_0032C320(&inst);
    TEST_ASSERT(ret == 0, "return must match func_00323860 zero");
    TEST_ASSERT(s_v28_calls == 0, "must suppress view func_28 when ret is 0");

    // 3. ret != 0 without view -> suppresses view func_28
    reset_mocks();
    inst.m_view = nullptr;
    s_323860_ret = 1;
    ret = func_0032C320(&inst);
    TEST_ASSERT(ret == 1, "return must match func_00323860");
    TEST_ASSERT(s_v28_calls == 0, "must suppress view func_28 when view is null");
}

static void test_early_exit_gates() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    // 1. m_field_341C == 0
    reset_mocks();
    inst.m_field_341C = 0;
    int ret = func_0032C320(&inst);
    TEST_ASSERT(ret == 1, "must return ret on m_field_341C==0");
    TEST_ASSERT(s_1880d0_calls == 0, "must suppress func_1880D0 on m_field_341C==0");

    // 2. func_1880D0 == 0
    reset_mocks();
    inst.m_field_341C = 1;
    inst.m_field_190 = 2;
    s_1880d0_ret = 0;
    ret = func_0032C320(&inst);
    TEST_ASSERT(ret == 1, "must return ret on func_1880D0==0");
    TEST_ASSERT(s_1880d0_calls == 1, "must call func_1880D0 once");
    TEST_ASSERT(s_last_1880d0_mgr == D_004E3180, "func_1880D0 mgr mismatch");
    TEST_ASSERT(s_184c10_calls == 0, "must suppress division on func_1880D0==0");

    // 3. m_field_190 != 2
    reset_mocks();
    inst.m_field_341C = 1;
    s_1880d0_ret = 1;
    inst.m_field_190 = 1; // not 2
    ret = func_0032C320(&inst);
    TEST_ASSERT(ret == 1, "must return ret on m_field_190!=2");
    TEST_ASSERT(s_184c10_calls == 0, "must suppress division on m_field_190!=2");
}

static void test_division_and_quotient_threshold() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_field_341C = 1;
    inst.m_field_190 = 2; // active value

    // 1. Quotient < 81: num=80, den=1 -> quotient=80 < 81
    reset_mocks();
    s_184c10_ret = 1;
    s_184bd0_ret = 80;
    int ret = func_0032C320(&inst);
    TEST_ASSERT(ret == 1, "must return ret on quotient < 81");
    TEST_ASSERT(s_184c10_calls == 1, "must call func_184C10 once");
    TEST_ASSERT(s_last_184c10_mgr == D_004E3180, "func_184C10 mgr mismatch");
    TEST_ASSERT(s_184bd0_calls == 1, "must call func_184BD0 once");
    TEST_ASSERT(s_last_184bd0_mgr == D_004E3180, "func_184BD0 mgr mismatch");
    TEST_ASSERT(s_last_184bd0_a1 == 1, "func_184BD0 a1 must be 1");
    TEST_ASSERT(inst.m_field_3424 == 0, "m_field_3424 must not be set when quotient < 81");
    TEST_ASSERT(s_185dc0_calls == 0, "must suppress func_185DC0 when quotient < 81");

    // 2. Denominator clamp: den=0 clamped to 1, num=80 -> quotient=80 < 81
    reset_mocks();
    s_184c10_ret = 0; // zero denominator
    s_184bd0_ret = 80;
    ret = func_0032C320(&inst);
    TEST_ASSERT(ret == 1, "must return ret on clamped zero denominator");
    TEST_ASSERT(inst.m_field_3424 == 0, "m_field_3424 must not be set on quotient 80");

    // 3. Quotient >= 81: num=81, den=1 -> quotient=81 -> sets m_field_3424 = 1
    reset_mocks();
    s_184c10_ret = 1;
    s_184bd0_ret = 81;
    s_185dc0_ret = 1; // busy manager to stop here
    inst.m_field_3424 = 0;
    ret = func_0032C320(&inst);
    TEST_ASSERT(ret == 1, "must return ret on quotient >= 81");
    TEST_ASSERT(inst.m_field_3424 == 1, "m_field_3424 must be set to 1 when quotient >= 81");
    TEST_ASSERT(s_185dc0_calls == 1, "must call func_185DC0 once");
    TEST_ASSERT(s_last_185dc0_mgr == D_004E3180, "func_185DC0 mgr mismatch");
    TEST_ASSERT(s_185f00_calls == 0, "must suppress func_185F00 when manager is busy");
    TEST_ASSERT(inst.m_field_3420 == 0, "m_field_3420 must not be set when manager is busy");
}

static void test_idle_manager_success_path() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    ViewObj view;
    view.m_vtable = &s_view_vtable;
    inst.m_view = &view;
    inst.m_field_341C = 1;
    inst.m_field_190 = 2; // active value

    s_323860_ret = 7;
    s_1880d0_ret = 1;
    s_184c10_ret = 1;
    s_184bd0_ret = 100; // quotient = 100 >= 81
    s_185dc0_ret = 0;   // idle manager

    int ret = func_0032C320(&inst);
    TEST_ASSERT(ret == 7, "must return ret 7 on success");
    TEST_ASSERT(inst.m_field_3424 == 1, "m_field_3424 must be set to 1");
    TEST_ASSERT(s_185f00_calls == 1, "must call func_185F00 once");
    TEST_ASSERT(s_last_185f00_mgr == D_004E3180, "func_185F00 mgr mismatch");
    TEST_ASSERT(s_last_185f00_a1 == 1, "func_185F00 a1 must be 1");
    TEST_ASSERT(s_last_185f00_a2 == 1, "func_185F00 a2 must be 1");
    TEST_ASSERT(inst.m_field_3420 == 1, "m_field_3420 must be set to 1");

    // Verify exact call order:
    // func_00323860 -> func_28 -> func_1880D0 -> func_184C10 -> func_184BD0 -> func_185DC0 -> func_185F00
    TEST_ASSERT(s_call_order.size() == 7, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_00323860") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_28") == 0, "call 1 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[2], "func_1880D0") == 0, "call 2 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[3], "func_184C10") == 0, "call 3 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[4], "func_184BD0") == 0, "call 4 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[5], "func_185DC0") == 0, "call 5 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[6], "func_185F00") == 0, "call 6 mismatch");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "return_prop") == 0) { test_return_propagation(); return 0; }
        if (std::strcmp(argv[1], "view_cb") == 0) { test_view_callback(); return 0; }
        if (std::strcmp(argv[1], "gates") == 0) { test_early_exit_gates(); return 0; }
        if (std::strcmp(argv[1], "division") == 0) { test_division_and_quotient_threshold(); return 0; }
        if (std::strcmp(argv[1], "idle_success") == 0) { test_idle_manager_success_path(); return 0; }
    }
    test_return_propagation();
    test_view_callback();
    test_early_exit_gates();
    test_division_and_quotient_threshold();
    test_idle_manager_success_path();
    return 0;
}
