#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_terrain_action.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

int D_004E2EA0 = 1;
static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_32e820_calls = 0;
static void *s_last_32e820_self = nullptr;

static int s_func168_calls = 0;
static int s_func168_ret = 1;
static int s_last_168_a3 = 0;
static int s_last_168_t0 = 0;
static int s_last_168_t1 = 0;
static int s_last_168_t2 = 0;
static int s_last_168_t3 = 0;

static int s_32d400_calls = 0;
static int s_32d400_ret = 51;
static int s_last_32d400_mode = -1;
static int s_last_32d400_flag = -1;
static int s_last_32d400_x = -1;
static int s_last_32d400_y = -1;
static void *s_last_32d400_buf = nullptr;

static int s_32e580_calls = 0;
static void *s_last_32e580_buf = nullptr;

static int s_func180_calls = 0;
static int s_func180_ret = 1;

static int s_32e6b0_calls = 0;
static int s_last_32e6b0_a1 = -1;
static int s_last_32e6b0_a2 = -1;
static int s_last_32e6b0_a3 = -1;
static int s_last_32e6b0_t0 = -1;

static int s_mgr_func18_calls = 0;

static std::vector<const char*> s_call_order;

static int mock_func_168(void *self, void *sp104, void *sp110, int a3, int t0, int t1, int t2, int t3) {
    (void)self;
    (void)sp104;
    (void)sp110;
    s_func168_calls++;
    s_last_168_a3 = a3;
    s_last_168_t0 = t0;
    s_last_168_t1 = t1;
    s_last_168_t2 = t2;
    s_last_168_t3 = t3;
    s_call_order.push_back("target_func_168");
    return s_func168_ret;
}

static int mock_func_180(void *self, int sp92, ...) {
    (void)self;
    (void)sp92;
    s_func180_calls++;
    s_call_order.push_back("target_func_180");
    return s_func180_ret;
}

static void mock_mgr_func_18(void *self, int a1, int a2) {
    (void)self;
    (void)a1;
    (void)a2;
    s_mgr_func18_calls++;
    s_call_order.push_back("mgr_func_18");
}

extern "C" {
    void func_0032E820(CombatSubsystemControllerInstance *self) {
        s_32e820_calls++;
        s_last_32e820_self = self;
        s_call_order.push_back("func_0032E820");
    }

    int func_0032D400(CombatSubsystemControllerInstance *self, int mode, int flag, int x, int y, void *buf, void *target_sub, int recurse_flag) {
        (void)self;
        (void)target_sub;
        (void)recurse_flag;
        s_32d400_calls++;
        s_last_32d400_mode = mode;
        s_last_32d400_flag = flag;
        s_last_32d400_x = x;
        s_last_32d400_y = y;
        s_last_32d400_buf = buf;
        s_call_order.push_back("func_0032D400");
        return s_32d400_ret;
    }

    void func_0032E580(CombatSubsystemControllerInstance *self, void *buf) {
        (void)self;
        s_32e580_calls++;
        s_last_32e580_buf = buf;
        s_call_order.push_back("func_0032E580");
    }

    void func_0032E6B0(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0) {
        (void)self;
        s_32e6b0_calls++;
        s_last_32e6b0_a1 = a1;
        s_last_32e6b0_a2 = a2;
        s_last_32e6b0_a3 = a3;
        s_last_32e6b0_t0 = t0;
        s_call_order.push_back("func_0032E6B0");
    }
}

static SystemManagerVtable s_mgr_vtable;
static TargetMethodVtable s_target_vtable;
static TargetSubField6960 s_target_sub;
static TargetObj s_target_obj;

static void reset_mocks() {
    D_004E2EA0 = 1;
    s_32e820_calls = 0;
    s_last_32e820_self = nullptr;

    s_func168_calls = 0;
    s_func168_ret = 1;
    s_last_168_a3 = 0;
    s_last_168_t0 = 0;
    s_last_168_t1 = 0;
    s_last_168_t2 = 0;
    s_last_168_t3 = 0;

    s_32d400_calls = 0;
    s_32d400_ret = 51;
    s_last_32d400_mode = -1;
    s_last_32d400_flag = -1;
    s_last_32d400_x = -1;
    s_last_32d400_y = -1;
    s_last_32d400_buf = nullptr;

    s_32e580_calls = 0;
    s_last_32e580_buf = nullptr;

    s_func180_calls = 0;
    s_func180_ret = 1;

    s_32e6b0_calls = 0;
    s_last_32e6b0_a1 = -1;
    s_last_32e6b0_a2 = -1;
    s_last_32e6b0_a3 = -1;
    s_last_32e6b0_t0 = -1;

    s_mgr_func18_calls = 0;
    s_call_order.clear();

    std::memset(&s_mgr_vtable, 0, sizeof(s_mgr_vtable));
    s_mgr_vtable.func_18 = mock_mgr_func_18;
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_vtable = &s_mgr_vtable;

    std::memset(&s_target_vtable, 0, sizeof(s_target_vtable));
    s_target_vtable.func_168 = mock_func_168;
    s_target_vtable.func_180 = mock_func_180;
    s_target_sub.m_vtable = &s_target_vtable;

    std::memset(&s_target_obj, 0, sizeof(s_target_obj));
    s_target_obj.m_sub6960 = &s_target_sub;
}

static void test_gate_d004e2ea0_zero() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_target = &s_target_obj;

    D_004E2EA0 = 0; // gate fails

    int ret = func_0032E0E0(&inst, 10, 20);

    TEST_ASSERT(ret == 0, "D_004E2EA0==0 must return 0");
    TEST_ASSERT(s_32e820_calls == 1, "must call func_0032E820 first");
    TEST_ASSERT(s_last_32e820_self == &inst, "func_0032E820 self mismatch");
    TEST_ASSERT(s_func168_calls == 0, "D_004E2EA0==0 must suppress target func_168");
    TEST_ASSERT(s_32d400_calls == 0, "D_004E2EA0==0 must suppress func_0032D400");
    TEST_ASSERT(s_call_order.size() == 1, "only cleanup should be called");
}

static void test_target_query_zero() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_target = &s_target_obj;

    s_func168_ret = 0; // target query returns 0

    int ret = func_0032E0E0(&inst, 10, 20);

    TEST_ASSERT(ret == 0, "target query zero must return 0");
    TEST_ASSERT(s_32e820_calls == 1, "must call func_0032E820 first");
    TEST_ASSERT(s_func168_calls == 1, "must call target func_168 once");
    TEST_ASSERT(s_last_168_a3 == -1, "func_168 a3 must be -1");
    TEST_ASSERT(s_last_168_t0 == -1, "func_168 t0 must be -1");
    TEST_ASSERT(s_last_168_t1 == -1, "func_168 t1 must be -1");
    TEST_ASSERT(s_last_168_t2 == -1, "func_168 t2 must be -1");
    TEST_ASSERT(s_last_168_t3 == 0, "func_168 t3 must be 0");
    TEST_ASSERT(s_32d400_calls == 0, "target query 0 must suppress func_0032D400");
}

static void test_pick_query_50() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_target = &s_target_obj;

    s_func168_ret = 1;
    s_32d400_ret = 50; // returns 50

    int ret = func_0032E0E0(&inst, 11, 22);

    TEST_ASSERT(ret == 0, "pick query 50 must return 0");
    TEST_ASSERT(s_32d400_calls == 1, "must call func_0032D400 once");
    TEST_ASSERT(s_last_32d400_mode == 42, "func_0032D400 mode must be 42");
    TEST_ASSERT(s_last_32d400_flag == 1, "func_0032D400 flag must be 1");
    TEST_ASSERT(s_last_32d400_x == 11, "func_0032D400 x mismatch");
    TEST_ASSERT(s_last_32d400_y == 22, "func_0032D400 y mismatch");
    TEST_ASSERT(s_32e580_calls == 0, "pick query 50 must suppress func_0032E580");
    TEST_ASSERT(s_32e6b0_calls == 0, "pick query 50 must suppress func_0032E6B0");
    TEST_ASSERT(s_mgr_func18_calls == 1, "pick query 50 must notify manager");
}

static void test_success_path() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_target = &s_target_obj;

    s_func168_ret = 1;
    s_32d400_ret = 51;
    s_func180_ret = 1;

    int ret = func_0032E0E0(&inst, 11, 22);

    TEST_ASSERT(ret == 1, "success path must return 1");
    TEST_ASSERT(s_32e820_calls == 1, "must call func_0032E820 first");
    TEST_ASSERT(s_func168_calls == 1, "must call target func_168 once");
    TEST_ASSERT(s_32d400_calls == 1, "must call func_0032D400 once");
    TEST_ASSERT(s_32e580_calls == 1, "must call func_0032E580 once");
    TEST_ASSERT(s_last_32e580_buf == s_last_32d400_buf, "func_0032E580 buf must match func_0032D400 buf");
    TEST_ASSERT(s_func180_calls == 1, "must call target func_180 once");
    TEST_ASSERT(s_32e6b0_calls == 1, "must call func_0032E6B0 once");
    TEST_ASSERT(s_last_32e6b0_a1 == 2961, "func_0032E6B0 a1 must be 2961");
    TEST_ASSERT(s_last_32e6b0_a2 == 0, "func_0032E6B0 a2 must be 0");
    TEST_ASSERT(s_last_32e6b0_a3 == -1, "func_0032E6B0 a3 must be -1");
    TEST_ASSERT(s_last_32e6b0_t0 == 1, "func_0032E6B0 t0 must be 1");
    TEST_ASSERT(s_mgr_func18_calls == 1, "must call manager func_18 once");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "gate_zero") == 0) { test_gate_d004e2ea0_zero(); return 0; }
        if (std::strcmp(argv[1], "target_zero") == 0) { test_target_query_zero(); return 0; }
        if (std::strcmp(argv[1], "pick_50") == 0) { test_pick_query_50(); return 0; }
        if (std::strcmp(argv[1], "success") == 0) { test_success_path(); return 0; }
    }
    test_gate_d004e2ea0_zero();
    test_target_query_zero();
    test_pick_query_50();
    test_success_path();
    return 0;
}
