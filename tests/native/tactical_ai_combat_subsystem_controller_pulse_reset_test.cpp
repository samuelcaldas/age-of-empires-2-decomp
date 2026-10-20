#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_pulse_reset.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_1880d0_ret = 1;
static int s_1880d0_calls = 0;
static SystemManager *s_last_1880d0_mgr = nullptr;

static int s_185f00_calls = 0;
static SystemManager *s_last_185f00_mgr = nullptr;
static int s_last_185f00_a1 = -1;
static int s_last_185f00_a2 = -1;

static int s_324470_calls = 0;
static void *s_last_324470_self = nullptr;

static std::vector<const char*> s_call_order;

extern "C" {
    int func_1880D0(SystemManager *mgr) {
        s_1880d0_calls++;
        s_last_1880d0_mgr = mgr;
        s_call_order.push_back("func_1880D0");
        return s_1880d0_ret;
    }
    void func_185F00(SystemManager *mgr, int a1, int a2) {
        s_185f00_calls++;
        s_last_185f00_mgr = mgr;
        s_last_185f00_a1 = a1;
        s_last_185f00_a2 = a2;
        s_call_order.push_back("func_185F00");
    }
    void func_00324470(CombatSubsystemControllerInstance *self) {
        s_324470_calls++;
        s_last_324470_self = self;
        s_call_order.push_back("func_00324470");
    }
}

static void reset_mocks() {
    s_1880d0_ret = 1;
    s_1880d0_calls = 0;
    s_last_1880d0_mgr = nullptr;
    s_185f00_calls = 0;
    s_last_185f00_mgr = nullptr;
    s_last_185f00_a1 = -1;
    s_last_185f00_a2 = -1;
    s_324470_calls = 0;
    s_last_324470_self = nullptr;
    s_call_order.clear();
}

static void test_full_reset_active_3420() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_field_341C = 1;
    inst.m_field_190 = 2;
    inst.m_field_3424 = 1;
    inst.m_field_3420 = 1;

    func_0032C480(&inst);
    TEST_ASSERT(inst.m_field_3424 == 0, "m_field_3424 must be reset to 0");
    TEST_ASSERT(s_185f00_calls == 1, "must call func_185F00 once");
    TEST_ASSERT(s_last_185f00_mgr == D_004E3180, "func_185F00 mgr mismatch");
    TEST_ASSERT(s_last_185f00_a1 == 0, "func_185F00 a1 must be 0");
    TEST_ASSERT(s_last_185f00_a2 == 0, "func_185F00 a2 must be 0");
    TEST_ASSERT(inst.m_field_3420 == 0, "m_field_3420 must be reset to 0");
    TEST_ASSERT(s_324470_calls == 1, "must call func_00324470 once");
    TEST_ASSERT(s_last_324470_self == &inst, "func_00324470 self mismatch");

    TEST_ASSERT(s_call_order.size() == 3, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_1880D0") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_185F00") == 0, "call 1 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[2], "func_00324470") == 0, "call 2 mismatch");
}

static void test_reset_inactive_3420() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_field_341C = 1;
    inst.m_field_190 = 2;
    inst.m_field_3424 = 1;
    inst.m_field_3420 = 0; // inactive

    func_0032C480(&inst);
    TEST_ASSERT(inst.m_field_3424 == 0, "m_field_3424 must be reset to 0");
    TEST_ASSERT(s_185f00_calls == 0, "must suppress func_185F00 when m_field_3420 is 0");
    TEST_ASSERT(inst.m_field_3420 == 0, "m_field_3420 must remain 0");
    TEST_ASSERT(s_324470_calls == 1, "must call func_00324470 once");

    TEST_ASSERT(s_call_order.size() == 2, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_1880D0") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_00324470") == 0, "call 1 mismatch");
}

static void test_gates_suppression() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    // 1. m_field_341C == 0
    reset_mocks();
    inst.m_field_341C = 0;
    inst.m_field_190 = 2;
    inst.m_field_3424 = 1;
    inst.m_field_3420 = 1;
    func_0032C480(&inst);
    TEST_ASSERT(s_1880d0_calls == 0, "must suppress func_1880D0 when m_field_341C==0");
    TEST_ASSERT(inst.m_field_3424 == 1, "m_field_3424 must remain untouched");
    TEST_ASSERT(inst.m_field_3420 == 1, "m_field_3420 must remain untouched");
    TEST_ASSERT(s_324470_calls == 1, "must call func_00324470 unconditionally");

    // 2. func_1880D0 == 0
    reset_mocks();
    inst.m_field_341C = 1;
    inst.m_field_190 = 2;
    inst.m_field_3424 = 1;
    inst.m_field_3420 = 1;
    s_1880d0_ret = 0;
    func_0032C480(&inst);
    TEST_ASSERT(s_1880d0_calls == 1, "must call func_1880D0 once");
    TEST_ASSERT(inst.m_field_3424 == 1, "m_field_3424 must remain untouched when func_1880D0==0");
    TEST_ASSERT(inst.m_field_3420 == 1, "m_field_3420 must remain untouched when func_1880D0==0");
    TEST_ASSERT(s_324470_calls == 1, "must call func_00324470 unconditionally");

    // 3. m_field_190 != 2
    reset_mocks();
    inst.m_field_341C = 1;
    inst.m_field_190 = 1; // not 2
    inst.m_field_3424 = 1;
    inst.m_field_3420 = 1;
    s_1880d0_ret = 1;
    func_0032C480(&inst);
    TEST_ASSERT(inst.m_field_3424 == 1, "m_field_3424 must remain untouched when m_field_190!=2");
    TEST_ASSERT(inst.m_field_3420 == 1, "m_field_3420 must remain untouched when m_field_190!=2");
    TEST_ASSERT(s_324470_calls == 1, "must call func_00324470 unconditionally");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "full_reset") == 0) { test_full_reset_active_3420(); return 0; }
        if (std::strcmp(argv[1], "inactive_3420") == 0) { test_reset_inactive_3420(); return 0; }
        if (std::strcmp(argv[1], "gates") == 0) { test_gates_suppression(); return 0; }
    }
    test_full_reset_active_3420();
    test_reset_inactive_3420();
    test_gates_suppression();
    return 0;
}
