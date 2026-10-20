#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_action.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_185dc0_ret = 0;
static int s_32d400_calls = 0;
static CombatSubsystemControllerInstance *s_32d400_last_self = nullptr;
static int s_32d400_last_a1 = -1;
static int s_32d400_last_a2 = -1;
static int s_32d400_last_a3 = -1;
static int s_32d400_last_t0 = -1;
static void *s_32d400_last_buf = nullptr;
static TargetSubCA8 *s_32d400_last_sub_ca8 = nullptr;
static int s_32d400_ret = 52;

static int s_205ee0_calls = 0;
static TargetObj *s_205ee0_last_target = nullptr;

static int s_205ca0_calls = 0;
static TargetObj *s_205ca0_last_target = nullptr;
static void *s_205ca0_last_item = nullptr;
static int s_205ca0_last_a2 = -1;

static int s_v28_calls = 0;
static void *s_v28_last_self = nullptr;
static int s_v28_last_a1 = -1;

static int s_32e580_calls = 0;
static CombatSubsystemControllerInstance *s_32e580_last_self = nullptr;
static void *s_32e580_last_buf = nullptr;
static std::vector<const char*> s_call_order;

static int s_mock_item_data = 0x1234;
static void *s_mock_item = &s_mock_item_data;

extern "C" {
    int func_185DC0(SystemManager *) { return s_185dc0_ret; }
    int func_0032D400(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0, void *buf, TargetSubCA8 *sub_ca8) {
        s_32d400_calls++;
        s_32d400_last_self = self;
        s_32d400_last_a1 = a1;
        s_32d400_last_a2 = a2;
        s_32d400_last_a3 = a3;
        s_32d400_last_t0 = t0;
        s_32d400_last_buf = buf;
        s_32d400_last_sub_ca8 = sub_ca8;
        s_call_order.push_back("func_0032D400");
        if (buf) {
            *(void**)((char*)buf + 12) = s_mock_item;
        }
        return s_32d400_ret;
    }
    void func_205EE0(TargetObj *target) {
        s_205ee0_calls++;
        s_205ee0_last_target = target;
        s_call_order.push_back("func_205EE0");
    }
    void func_205CA0(TargetObj *target, void *item, int a2) {
        s_205ca0_calls++;
        s_205ca0_last_target = target;
        s_205ca0_last_item = item;
        s_205ca0_last_a2 = a2;
        s_call_order.push_back("func_205CA0");
    }
    void func_00268410(void *, short *, short *, short *, short *) {}
    void func_0032E580(CombatSubsystemControllerInstance *self, void *buf) {
        s_32e580_calls++;
        s_32e580_last_self = self;
        s_32e580_last_buf = buf;
        s_call_order.push_back("func_0032E580");
    }
    int func_123350(float) { return 0; }
    void func_0031A720(void *, void *, void *) {}
    void func_001830E0(void *) {}
    void func_00262FA0(void *, void *, void *) {}
    void func_186010(SystemManager *, void *, void *, void *) {}
    void func_1F6510(void *, void *, void *, void *) {}
}

static void mock_view_func_28(void *self, int a1) {
    s_v28_calls++;
    s_v28_last_self = self;
    s_v28_last_a1 = a1;
    s_call_order.push_back("func_28");
}
static void mock_view_func_108(void *, int, int, int, int, int) {}
static CombatSubsystemVtable s_vtable = { {}, mock_view_func_28, {}, mock_view_func_108 };

static void reset_mocks() {
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_mode = 4;
    s_mgr.m_field_1CC = 0;
    s_185dc0_ret = 0;
    s_32d400_calls = 0;
    s_32d400_last_self = nullptr;
    s_32d400_last_a1 = -1;
    s_32d400_last_a2 = -1;
    s_32d400_last_a3 = -1;
    s_32d400_last_t0 = -1;
    s_32d400_last_buf = nullptr;
    s_32d400_last_sub_ca8 = nullptr;
    s_32d400_ret = 52;
    s_205ee0_calls = 0;
    s_205ee0_last_target = nullptr;
    s_205ca0_calls = 0;
    s_205ca0_last_target = nullptr;
    s_205ca0_last_item = nullptr;
    s_205ca0_last_a2 = -1;
    s_v28_calls = 0;
    s_v28_last_self = nullptr;
    s_v28_last_a1 = -1;
    s_32e580_calls = 0;
    s_32e580_last_self = nullptr;
    s_32e580_last_buf = nullptr;
    s_call_order.clear();
}

static void test_gate_rejection() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;

    // 1. Manager busy check
    s_185dc0_ret = 1;
    int ret = func_0032A060(&inst, 0, 0, 0, 0);
    TEST_ASSERT(ret == 0, "busy manager must return 0");

    // 2. Unsupported mode check (e.g. mode 1)
    reset_mocks();
    s_mgr.m_mode = 1;
    ret = func_0032A060(&inst, 0, 0, 0, 0);
    TEST_ASSERT(ret == 0, "unsupported mode must return 0");
}

static void test_default_state() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;
    s_mgr.m_field_1CC = 0; // unhandled state

    int ret = func_0032A060(&inst, 0, 0, 0, 0);
    TEST_ASSERT(ret == 1, "default state must return 1");
    TEST_ASSERT(s_32d400_calls == 0, "default state must not call func_0032D400");
}

static void test_state_18_success() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;

    TargetSubCA8 sub_ca8;
    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    target.m_sub_ca8 = &sub_ca8;
    inst.m_target = &target;

    s_mgr.m_field_1CC = 18;
    s_32d400_ret = 52; // matches 0x34

    int ret = func_0032A060(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 1, "state 18 must return 1");
    TEST_ASSERT(s_32d400_calls == 1, "state 18 must call func_0032D400 once");
    TEST_ASSERT(s_32d400_last_self == &inst, "state 18 func_0032D400 self mismatch");
    TEST_ASSERT(s_32d400_last_a1 == 41, "state 18 func_0032D400 action must be 41");
    TEST_ASSERT(s_32d400_last_a2 == 0, "state 18 func_0032D400 a2 must be 0");
    TEST_ASSERT(s_32d400_last_a3 == 10, "state 18 func_0032D400 arg1 mismatch");
    TEST_ASSERT(s_32d400_last_t0 == 20, "state 18 func_0032D400 arg2 mismatch");
    TEST_ASSERT(s_32d400_last_sub_ca8 == &sub_ca8, "state 18 func_0032D400 sub_ca8 mismatch");
    TEST_ASSERT(s_205ee0_calls == 1, "state 18 must call func_205EE0");
    TEST_ASSERT(s_205ee0_last_target == &target, "state 18 func_205EE0 target mismatch");
    TEST_ASSERT(s_205ca0_calls == 1, "state 18 must call func_205CA0");
    TEST_ASSERT(s_205ca0_last_target == &target, "state 18 func_205CA0 target mismatch");
    TEST_ASSERT(s_205ca0_last_item == s_mock_item, "state 18 item pointer must come from buf+12");
    TEST_ASSERT(s_205ca0_last_a2 == 1, "state 18 func_205CA0 flag must be 1");
    TEST_ASSERT(s_v28_calls == 1, "state 18 must call view func_28");
    TEST_ASSERT(s_v28_last_self == &inst, "state 18 func_28 self mismatch");
    TEST_ASSERT(s_v28_last_a1 == 1, "state 18 func_28 flag must be 1");

    // Call order verification: 32d400 -> 205ee0 -> 205ca0 -> func_28
    TEST_ASSERT(s_call_order.size() == 4, "state 18 call sequence length mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_0032D400") == 0, "call order 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_205EE0") == 0, "call order 1 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[2], "func_205CA0") == 0, "call order 2 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[3], "func_28") == 0, "call order 3 mismatch");
}

static void test_state_18_non52() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;

    TargetSubCA8 sub_ca8;
    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    target.m_sub_ca8 = &sub_ca8;
    inst.m_target = &target;

    s_mgr.m_field_1CC = 18;
    s_32d400_ret = 50; // non-52 result

    int ret = func_0032A060(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 1, "state 18 non-52 must return 1");
    TEST_ASSERT(s_32d400_calls == 1, "state 18 non-52 must call func_0032D400");
    TEST_ASSERT(s_205ee0_calls == 0, "state 18 non-52 must not call func_205EE0");
    TEST_ASSERT(s_205ca0_calls == 0, "state 18 non-52 must not call func_205CA0");
    TEST_ASSERT(s_v28_calls == 0, "state 18 non-52 must not call view func_28");
}

static void test_state_1_success() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;

    s_mgr.m_field_1CC = 1;
    s_32d400_ret = 51; // matches 0x33

    int ret = func_0032A060(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 1, "state 1 must return 1");
    TEST_ASSERT(s_32d400_calls == 1, "state 1 must call func_0032D400 once");
    TEST_ASSERT(s_32d400_last_self == &inst, "state 1 func_0032D400 self mismatch");
    TEST_ASSERT(s_32d400_last_a1 == 40, "state 1 func_0032D400 action must be 40");
    TEST_ASSERT(s_32d400_last_a2 == 0, "state 1 func_0032D400 a2 must be 0");
    TEST_ASSERT(s_32d400_last_a3 == 10, "state 1 func_0032D400 arg1 mismatch");
    TEST_ASSERT(s_32d400_last_t0 == 20, "state 1 func_0032D400 arg2 mismatch");
    TEST_ASSERT(s_32d400_last_sub_ca8 == nullptr, "state 1 func_0032D400 sub_ca8 must be null");
    TEST_ASSERT(s_32e580_calls == 1, "state 1 must call func_0032E580");
    TEST_ASSERT(s_32e580_last_self == &inst, "state 1 func_0032E580 self mismatch");
    TEST_ASSERT(s_32e580_last_buf == s_32d400_last_buf, "state 1 func_0032E580 buffer must match func_0032D400 buffer");
}

static void test_state_1_non51() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    inst.m_vtable = &s_vtable;

    s_mgr.m_field_1CC = 1;
    s_32d400_ret = 50; // non-51 result

    int ret = func_0032A060(&inst, 10, 20, 30, 40);
    TEST_ASSERT(ret == 1, "state 1 non-51 must return 1");
    TEST_ASSERT(s_32d400_calls == 1, "state 1 non-51 must call func_0032D400");
    TEST_ASSERT(s_32e580_calls == 0, "state 1 non-51 must not call func_0032E580");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "gate_rejection") == 0) { test_gate_rejection(); return 0; }
        if (std::strcmp(argv[1], "default_state") == 0) { test_default_state(); return 0; }
        if (std::strcmp(argv[1], "state_18_success") == 0) { test_state_18_success(); return 0; }
        if (std::strcmp(argv[1], "state_18_non52") == 0) { test_state_18_non52(); return 0; }
        if (std::strcmp(argv[1], "state_1_success") == 0) { test_state_1_success(); return 0; }
        if (std::strcmp(argv[1], "state_1_non51") == 0) { test_state_1_non51(); return 0; }
    }
    test_gate_rejection();
    test_default_state();
    test_state_18_success();
    test_state_18_non52();
    test_state_1_success();
    test_state_1_non51();
    return 0;
}
