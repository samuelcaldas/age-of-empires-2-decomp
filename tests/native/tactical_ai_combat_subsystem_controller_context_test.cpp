#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_context.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;
int D_004E2EA0 = 0;

static int s_185dc0_ret = 0;
static int s_185dc0_calls = 0;
static SystemManager *s_last_185dc0_mgr = nullptr;

static int s_1f65a0_calls = 0;
static void *s_last_1f65a0_self = nullptr;

static int s_32d400_calls = 0;
static int s_32d400_ret = 0;
static void *s_last_32d400_self = nullptr;
static int s_last_32d400_a1 = -1;
static int s_last_32d400_a2 = -1;
static int s_last_32d400_a3 = -1;
static int s_last_32d400_t0 = -1;
static void *s_last_32d400_buf = nullptr;
static void *s_last_32d400_target_sub = nullptr;
static int s_last_32d400_flag = -1;

static int s_225590_calls = 0;
static int s_last_225590_arg = -1;

static int s_32e580_calls = 0;
static void *s_last_32e580_self = nullptr;
static void *s_last_32e580_buf = nullptr;

static int s_32e6b0_calls = 0;
static void *s_last_32e6b0_self = nullptr;
static int s_last_32e6b0_a1 = -1;
static int s_last_32e6b0_a2 = -1;
static int s_last_32e6b0_a3 = -1;
static int s_last_32e6b0_t0 = -1;

static int s_31a720_calls = 0;
static void *s_last_31a720_self = nullptr;
static int s_last_31a720_a1 = 0;
static int s_last_31a720_a2 = 0;
static int s_last_31a720_a3 = 0;
static int s_last_31a720_t0 = 0;

static int s_32e820_calls = 0;
static int s_205ee0_calls = 0;

static int s_v110_calls = 0;
static void *s_last_v110_self = nullptr;

static int s_v12c_calls = 0;
static void *s_last_v12c_self = nullptr;
static int s_last_v12c_a1 = -1;
static int s_last_v12c_a2 = -1;
static int s_last_v12c_a3 = -1;
static int s_last_v12c_t0 = -1;

static int s_v28_calls = 0;
static void *s_last_v28_self = nullptr;
static int s_last_v28_a1 = -1;

static int s_v8c_calls = 0;
static int s_last_v8c_a1 = 0;

static int s_mgr_v18_calls = 0;
static int s_last_mgr_v18_a1 = -1;
static int s_last_mgr_v18_a2 = -1;

static std::vector<const char*> s_call_order;

extern "C" {
    void func_1F65A0(CombatSubsystemControllerInstance *self) {
        s_1f65a0_calls++;
        s_last_1f65a0_self = self;
        s_call_order.push_back("func_1F65A0");
    }
    int func_0032D400(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0, void *buf, void *target_sub, int flag) {
        s_32d400_calls++;
        s_last_32d400_self = self;
        s_last_32d400_a1 = a1;
        s_last_32d400_a2 = a2;
        s_last_32d400_a3 = a3;
        s_last_32d400_t0 = t0;
        s_last_32d400_buf = buf;
        s_last_32d400_target_sub = target_sub;
        s_last_32d400_flag = flag;
        s_call_order.push_back("func_0032D400");
        if (buf && s_32d400_ret == 52) {
            static ViewVtable vtab;
            vtab.func_8C = [](void *, int a1) {
                s_v8c_calls++;
                s_last_v8c_a1 = a1;
                s_call_order.push_back("func_8C");
            };
            static ViewObj view_obj;
            view_obj.m_vtable = &vtab;
            *((void**)((char*)buf + 12)) = &view_obj;
        }
        return s_32d400_ret;
    }
    int func_185DC0(SystemManager *mgr) {
        s_185dc0_calls++;
        s_last_185dc0_mgr = mgr;
        s_call_order.push_back("func_185DC0");
        return s_185dc0_ret;
    }
    int func_225590(int a0) {
        s_225590_calls++;
        s_last_225590_arg = a0;
        s_call_order.push_back("func_225590");
        return 0;
    }
    void func_0032E580(CombatSubsystemControllerInstance *self, void *buf) {
        s_32e580_calls++;
        s_last_32e580_self = self;
        s_last_32e580_buf = buf;
        s_call_order.push_back("func_0032E580");
    }
    void func_0032E6B0(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0) {
        s_32e6b0_calls++;
        s_last_32e6b0_self = self;
        s_last_32e6b0_a1 = a1;
        s_last_32e6b0_a2 = a2;
        s_last_32e6b0_a3 = a3;
        s_last_32e6b0_t0 = t0;
        s_call_order.push_back("func_0032E6B0");
    }
    void func_31A720(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0) {
        s_31a720_calls++;
        s_last_31a720_self = self;
        s_last_31a720_a1 = a1;
        s_last_31a720_a2 = a2;
        s_last_31a720_a3 = a3;
        s_last_31a720_t0 = t0;
        s_call_order.push_back("func_31A720");
    }
    void func_0032E820(CombatSubsystemControllerInstance *) {
        s_32e820_calls++;
        s_call_order.push_back("func_0032E820");
    }
    void func_205EE0(void *) {
        s_205ee0_calls++;
        s_call_order.push_back("func_205EE0");
    }
}

static void mock_view_func_110(void *self) {
    s_v110_calls++;
    s_last_v110_self = self;
    s_call_order.push_back("func_110");
}

static void mock_view_func_12c(void *self, int a1, int a2, int a3, int t0) {
    s_v12c_calls++;
    s_last_v12c_self = self;
    s_last_v12c_a1 = a1;
    s_last_v12c_a2 = a2;
    s_last_v12c_a3 = a3;
    s_last_v12c_t0 = t0;
    s_call_order.push_back("func_12C");
}

static void mock_view_func_28(void *self, int a1) {
    s_v28_calls++;
    s_last_v28_self = self;
    s_last_v28_a1 = a1;
    s_call_order.push_back("func_28");
}

static void mock_mgr_func_18(void *, int a1, int a2) {
    s_mgr_v18_calls++;
    s_last_mgr_v18_a1 = a1;
    s_last_mgr_v18_a2 = a2;
    s_call_order.push_back("mgr_func_18");
}

static CombatSubsystemVtable s_vtable = {
    {}, mock_view_func_28,
    {}, mock_view_func_110,
    {}, mock_view_func_12c
};

static SystemManagerVtable s_mgr_vtable = {
    {}, mock_mgr_func_18
};

static void reset_mocks() {
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_vtable = &s_mgr_vtable;
    s_mgr.m_mode = 4;
    s_mgr.m_field_1CC = 0;
    D_004E2EA0 = 0;
    s_185dc0_ret = 0;
    s_185dc0_calls = 0;
    s_last_185dc0_mgr = nullptr;
    s_1f65a0_calls = 0;
    s_last_1f65a0_self = nullptr;
    s_32d400_calls = 0;
    s_32d400_ret = 0;
    s_225590_calls = 0;
    s_last_225590_arg = -1;
    s_32e580_calls = 0;
    s_32e6b0_calls = 0;
    s_31a720_calls = 0;
    s_32e820_calls = 0;
    s_205ee0_calls = 0;
    s_v110_calls = 0;
    s_last_v110_self = nullptr;
    s_v28_calls = 0;
    s_last_v28_self = nullptr;
    s_last_v28_a1 = -1;
    s_v8c_calls = 0;
    s_last_v8c_a1 = 0;
    s_mgr_v18_calls = 0;
    s_last_mgr_v18_a1 = -1;
    s_last_mgr_v18_a2 = -1;
    s_v12c_calls = 0;
    s_last_v12c_self = nullptr;
    s_last_v12c_a1 = -1;
    s_last_v12c_a2 = -1;
    s_last_v12c_a3 = -1;
    s_last_v12c_t0 = -1;
    s_last_32d400_self = nullptr;
    s_last_32d400_a1 = -1;
    s_last_32d400_a2 = -1;
    s_last_32d400_a3 = -1;
    s_last_32d400_t0 = -1;
    s_last_32d400_buf = nullptr;
    s_last_32d400_target_sub = nullptr;
    s_last_32d400_flag = -1;
    s_last_31a720_self = nullptr;
    s_last_31a720_a1 = 0;
    s_last_31a720_a2 = 0;
    s_last_31a720_a3 = 0;
    s_last_31a720_t0 = 0;
    s_last_32e580_self = nullptr;
    s_last_32e580_buf = nullptr;
    s_last_32e6b0_self = nullptr;
    s_last_32e6b0_a1 = -1;
    s_last_32e6b0_a2 = -1;
    s_last_32e6b0_a3 = -1;
    s_last_32e6b0_t0 = -1;
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
        int ret = func_0032BF70(&inst, 10, 20, 30, 40);
        TEST_ASSERT(ret == 0, "unsupported mode must return 0");
        TEST_ASSERT(s_call_order.empty(), "rejected mode must suppress all calls");
    }
}

static void test_active_field_190() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 1; // active

    int ret = func_0032BF70(&inst, 11, 22, 33, 44);
    TEST_ASSERT(ret == 1, "active field_190 must return 1");
    TEST_ASSERT(s_v110_calls == 1, "must call func_110 once");
    TEST_ASSERT(s_last_v110_self == &inst, "func_110 self mismatch");
    TEST_ASSERT(s_1f65a0_calls == 0, "active field_190 must not call func_1F65A0");
    TEST_ASSERT(s_call_order.size() == 1, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_110") == 0, "sole call must be func_110");
}

static void test_state_20_hit_52() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 0;

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    TargetSubCA8 sub_ca8;
    target.m_sub_ca8 = &sub_ca8;
    inst.m_target = &target;

    s_mgr.m_field_1CC = 20; // state 20
    s_32d400_ret = 52;      // hit 52

    int ret = func_0032BF70(&inst, 11, 22, 33, 44);
    TEST_ASSERT(ret == 1, "state 20 hit 52 must return 1");
    TEST_ASSERT(s_1f65a0_calls == 1, "must call func_1F65A0 once");
    TEST_ASSERT(s_32d400_calls == 1, "must call func_0032D400 once");
    TEST_ASSERT(s_last_32d400_self == &inst, "func_0032D400 self mismatch");
    TEST_ASSERT(s_last_32d400_a1 == 41, "func_0032D400 a1 must be 41");
    TEST_ASSERT(s_last_32d400_a2 == 2, "func_0032D400 a2 must be 2");
    TEST_ASSERT(s_last_32d400_a3 == 11, "func_0032D400 a3 mismatch");
    TEST_ASSERT(s_last_32d400_t0 == 22, "func_0032D400 t0 mismatch");
    TEST_ASSERT(s_last_32d400_target_sub == &sub_ca8, "func_0032D400 target_sub mismatch");
    TEST_ASSERT(s_last_32d400_buf != nullptr, "func_0032D400 buf must be non-null stack buffer");
    TEST_ASSERT(s_last_32d400_flag == 1, "func_0032D400 flag must be 1");
    TEST_ASSERT(s_v8c_calls == 1, "must dispatch func_8C on hit 52");
    TEST_ASSERT(s_last_v8c_a1 == -1, "func_8C a1 must be -1");
    TEST_ASSERT(s_call_order.size() == 3, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_1F65A0") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_0032D400") == 0, "call 1 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[2], "func_8C") == 0, "call 2 mismatch");
}

static void test_state_20_miss() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 0;

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    inst.m_target = &target;

    s_mgr.m_field_1CC = 20; // state 20
    s_32d400_ret = 0;       // miss (not 52)

    int ret = func_0032BF70(&inst, 11, 22, 33, 44);
    TEST_ASSERT(ret == 1, "state 20 miss must return 1");
    TEST_ASSERT(s_1f65a0_calls == 1, "must call func_1F65A0 once");
    TEST_ASSERT(s_32d400_calls == 1, "must call func_0032D400 once");
    TEST_ASSERT(s_v8c_calls == 0, "must not dispatch func_8C on miss");
}

static void test_state_21_routing() {
    int field_values[] = { 1, 2 };
    for (int field_val : field_values) {
        reset_mocks();
        CombatSubsystemControllerInstance inst;
        std::memset(&inst, 0, sizeof(inst));
        inst.m_vtable = &s_vtable;
        inst.m_field_190 = 0;
        inst.m_field_108 = field_val;

        ManagerSubA0 sub_a0;
        std::memset(&sub_a0, 0, sizeof(sub_a0));
        sub_a0.m_val_a0 = 2;
        s_mgr.m_sub_a0 = &sub_a0;
        s_mgr.m_mode = 4;
        s_mgr.m_field_1CC = 21; // state 21

        int ret = func_0032BF70(&inst, 11, 22, 33, 44);
        TEST_ASSERT(ret == 1, "state 21 must return 1");
        TEST_ASSERT(s_31a720_calls == 1, "must call func_31A720 once");
        TEST_ASSERT(s_last_31a720_self == &inst, "func_31A720 self mismatch");
        TEST_ASSERT(s_last_31a720_a1 == -1, "func_31A720 a1 mismatch");
        TEST_ASSERT(s_last_31a720_a2 == -1, "func_31A720 a2 mismatch");
        TEST_ASSERT(s_last_31a720_a3 == -1, "func_31A720 a3 mismatch");
        TEST_ASSERT(s_last_31a720_t0 == -1, "func_31A720 t0 mismatch");
        TEST_ASSERT(s_v28_calls == 1, "must call view func_28 once");
        TEST_ASSERT(s_last_v28_a1 == 1, "view func_28 a1 must be 1");
        TEST_ASSERT(s_mgr_v18_calls == 1, "must call mgr func_18 once");
        TEST_ASSERT(s_last_mgr_v18_a1 == 0, "mgr func_18 a1 must be 0");
        TEST_ASSERT(s_last_mgr_v18_a2 == 0, "mgr func_18 a2 must be 0");

        TEST_ASSERT(s_call_order.size() == 6, "state 21 call order size mismatch");
        TEST_ASSERT(std::strcmp(s_call_order[0], "func_1F65A0") == 0, "call 0 mismatch");
        TEST_ASSERT(std::strcmp(s_call_order[1], "func_185DC0") == 0, "call 1 mismatch");
        TEST_ASSERT(std::strcmp(s_call_order[2], "func_225590") == 0, "call 2 mismatch");
        TEST_ASSERT(std::strcmp(s_call_order[3], "func_31A720") == 0, "call 3 mismatch");
        TEST_ASSERT(std::strcmp(s_call_order[4], "func_28") == 0, "call 4 mismatch");
        TEST_ASSERT(std::strcmp(s_call_order[5], "mgr_func_18") == 0, "call 5 mismatch");
    }
}

static void test_t0_split() {
    // 1. t0 == 0 -> func_12C
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 0;
    inst.m_field_108 = 1;

    ManagerSubA0 sub_a0;
    std::memset(&sub_a0, 0, sizeof(sub_a0));
    sub_a0.m_val_a0 = 2;
    s_mgr.m_sub_a0 = &sub_a0;
    s_mgr.m_mode = 4;
    s_mgr.m_field_1CC = 0; // state != 21

    int ret = func_0032BF70(&inst, 11, 22, 33, 0); // t0 == 0
    TEST_ASSERT(ret == 1, "t0==0 must return 1");
    TEST_ASSERT(s_v12c_calls == 1, "must call view func_12C once");
    TEST_ASSERT(s_last_v12c_self == &inst, "view func_12C self mismatch");
    TEST_ASSERT(s_last_v12c_a1 == 11, "view func_12C a1 mismatch");
    TEST_ASSERT(s_last_v12c_a2 == 22, "view func_12C a2 mismatch");
    TEST_ASSERT(s_last_v12c_a3 == 1, "view func_12C a3 must be 1");
    TEST_ASSERT(s_last_v12c_t0 == -1, "view func_12C t0 must be -1");

    TEST_ASSERT(s_call_order.size() == 4, "t0==0 call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_1F65A0") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_185DC0") == 0, "call 1 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[2], "func_225590") == 0, "call 2 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[3], "func_12C") == 0, "call 3 mismatch");

    // 2. t0 != 0 and hit 51 -> func_0032D400 + func_0032E580 + func_0032E6B0
    reset_mocks();
    s_mgr.m_sub_a0 = &sub_a0;
    s_mgr.m_mode = 4;
    s_mgr.m_field_1CC = 0;
    s_32d400_ret = 51;

    ret = func_0032BF70(&inst, 11, 22, 33, 1); // t0 == 1
    TEST_ASSERT(ret == 1, "t0!=0 hit 51 must return 1");
    TEST_ASSERT(s_32d400_calls == 1, "must call func_0032D400 once");
    TEST_ASSERT(s_last_32d400_a1 == 40, "func_0032D400 a1 must be 40");
    TEST_ASSERT(s_last_32d400_a2 == 0, "func_0032D400 a2 must be 0");
    TEST_ASSERT(s_last_32d400_a3 == 11, "func_0032D400 a3 mismatch");
    TEST_ASSERT(s_last_32d400_t0 == 22, "func_0032D400 t0 mismatch");
    TEST_ASSERT(s_last_32d400_buf != nullptr, "func_0032D400 buf must be non-null stack buffer");
    TEST_ASSERT(s_last_32d400_target_sub == nullptr, "func_0032D400 target_sub must be nullptr");
    TEST_ASSERT(s_last_32d400_flag == 1, "func_0032D400 flag must be 1");
    TEST_ASSERT(s_32e580_calls == 1, "must call func_0032E580 once");
    TEST_ASSERT(s_last_32e580_self == &inst, "func_0032E580 self mismatch");
    TEST_ASSERT(s_last_32e580_buf == s_last_32d400_buf, "func_0032E580 buf must match func_0032D400 buf");
    TEST_ASSERT(s_32e6b0_calls == 1, "must call func_0032E6B0 once");
    TEST_ASSERT(s_last_32e6b0_self == &inst, "func_0032E6B0 self mismatch");
    TEST_ASSERT(s_last_32e6b0_a1 == 2962, "func_0032E6B0 a1 must be 2962");
    TEST_ASSERT(s_last_32e6b0_a2 == 0, "func_0032E6B0 a2 must be 0");
    TEST_ASSERT(s_last_32e6b0_a3 == 0, "func_0032E6B0 a3 must be 0");
    TEST_ASSERT(s_last_32e6b0_t0 == 0, "func_0032E6B0 t0 must be 0");

    TEST_ASSERT(s_call_order.size() == 6, "t0!=0 hit 51 call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_1F65A0") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_185DC0") == 0, "call 1 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[2], "func_225590") == 0, "call 2 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[3], "func_0032D400") == 0, "call 3 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[4], "func_0032E580") == 0, "call 4 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[5], "func_0032E6B0") == 0, "call 5 mismatch");
}

static void test_sub_a0_gate() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 0;
    inst.m_field_108 = 1;

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    inst.m_target = &target;

    ManagerSubA0 sub_a0;
    std::memset(&sub_a0, 0, sizeof(sub_a0));
    sub_a0.m_val_a0 = 1; // not 2
    s_mgr.m_sub_a0 = &sub_a0;
    s_mgr.m_mode = 4;

    int ret = func_0032BF70(&inst, 11, 22, 33, 44);
    TEST_ASSERT(ret == 1, "val_a0!=2 must return 1 via fallback");
    TEST_ASSERT(s_32e820_calls == 1, "val_a0!=2 must fall back to func_0032E820");
    TEST_ASSERT(s_205ee0_calls == 1, "val_a0!=2 must fall back to func_205EE0");
    TEST_ASSERT(s_31a720_calls == 0, "val_a0!=2 must bypass func_31A720");
}

static void test_modes_5_and_7() {
    int bypass_modes[] = { 5, 7 };
    for (int m : bypass_modes) {
        reset_mocks();
        CombatSubsystemControllerInstance inst;
        std::memset(&inst, 0, sizeof(inst));
        inst.m_vtable = &s_vtable;
        inst.m_field_190 = 0;
        inst.m_field_108 = 1;

        ManagerSubA0 sub_a0;
        std::memset(&sub_a0, 0, sizeof(sub_a0));
        sub_a0.m_val_a0 = 2;
        s_mgr.m_sub_a0 = &sub_a0;
        s_mgr.m_mode = m;

        int ret = func_0032BF70(&inst, 11, 22, 33, 44);
        TEST_ASSERT(ret == 1, "modes 5/7 must return 1");
        TEST_ASSERT(s_31a720_calls == 0, "modes 5/7 must bypass func_31A720");
        TEST_ASSERT(s_v12c_calls == 0, "modes 5/7 must bypass func_12C");
    }
}

static void test_busy_manager() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 0;

    s_mgr.m_field_1CC = 0; // state != 20
    s_185dc0_ret = 1;      // busy manager

    int ret = func_0032BF70(&inst, 11, 22, 33, 44);
    TEST_ASSERT(ret == 0, "busy manager must return 0");
    TEST_ASSERT(s_1f65a0_calls == 1, "must call func_1F65A0 once");
    TEST_ASSERT(s_185dc0_calls == 1, "must call func_185DC0 once");
    TEST_ASSERT(s_last_185dc0_mgr == D_004E3180, "func_185DC0 must receive D_004E3180");
    TEST_ASSERT(s_225590_calls == 0, "busy manager must suppress func_225590");
}

static void test_idle_manager_fallback() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_190 = 0;
    inst.m_field_108 = 0; // fallback condition

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    inst.m_target = &target;

    s_mgr.m_field_1CC = 0; // state != 20
    s_185dc0_ret = 0;      // idle manager

    int ret = func_0032BF70(&inst, 11, 22, 33, 44);
    TEST_ASSERT(ret == 1, "idle manager fallback must return 1");
    TEST_ASSERT(s_1f65a0_calls == 1, "must call func_1F65A0 once");
    TEST_ASSERT(s_185dc0_calls == 1, "must call func_185DC0 once");
    TEST_ASSERT(s_225590_calls == 1, "must call func_225590 once");
    TEST_ASSERT(s_last_225590_arg == 18, "func_225590 arg must be 18");
    TEST_ASSERT(s_32e820_calls == 1, "must call func_0032E820 once");
    TEST_ASSERT(s_205ee0_calls == 1, "must call func_205EE0 once");
    TEST_ASSERT(s_v28_calls == 1, "must call view func_28 once");
    TEST_ASSERT(s_last_v28_a1 == 1, "view func_28 a1 must be 1");
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
        int ret = func_0032BF70(&inst, 10, 20, 30, 40);
        TEST_ASSERT(ret == 1, "accepted mode must return 1");
    }
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "gate_rejection") == 0) { test_gate_rejection(); return 0; }
        if (std::strcmp(argv[1], "active_190") == 0) { test_active_field_190(); return 0; }
        if (std::strcmp(argv[1], "state_20_hit") == 0) { test_state_20_hit_52(); return 0; }
        if (std::strcmp(argv[1], "state_20_miss") == 0) { test_state_20_miss(); return 0; }
        if (std::strcmp(argv[1], "busy") == 0) { test_busy_manager(); return 0; }
        if (std::strcmp(argv[1], "idle_fallback") == 0) { test_idle_manager_fallback(); return 0; }
        if (std::strcmp(argv[1], "accepted_modes") == 0) { test_accepted_modes(); return 0; }
        if (std::strcmp(argv[1], "state_21") == 0) { test_state_21_routing(); return 0; }
        if (std::strcmp(argv[1], "t0_split") == 0) { test_t0_split(); return 0; }
        if (std::strcmp(argv[1], "sub_a0") == 0) { test_sub_a0_gate(); return 0; }
        if (std::strcmp(argv[1], "modes_5_7") == 0) { test_modes_5_and_7(); return 0; }
    }
    test_gate_rejection();
    test_accepted_modes();
    test_active_field_190();
    test_state_20_hit_52();
    test_state_20_miss();
    test_busy_manager();
    test_idle_manager_fallback();
    test_state_21_routing();
    test_t0_split();
    test_sub_a0_gate();
    test_modes_5_and_7();
    return 0;
}
