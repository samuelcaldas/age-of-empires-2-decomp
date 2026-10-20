#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_command_router.h"

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

static int s_func13c_calls = 0;
static void *s_func13c_ret = nullptr;
static int s_last_13c_a1 = -1;
static int s_last_13c_a2 = -1;

static int s_func184_calls = 0;
static int s_func184_ret = 1;
static void *s_last_184_entity = nullptr;

static int s_sub31a160_calls = 0;
static int s_last_31a160_sound_id = -1;
static int s_last_31a160_param = -1;

static int s_32d400_calls = 0;
static int s_32d400_ret = 51;
static int s_last_32d400_mode = -1;
static int s_last_32d400_flag = -1;
static int s_last_32d400_x = -1;
static int s_last_32d400_y = -1;
static void *s_last_32d400_buf = nullptr;

static int s_32e580_calls = 0;
static void *s_last_32e580_buf = nullptr;

static int s_32e6b0_calls = 0;
static int s_last_32e6b0_a1 = -1;
static int s_last_32e6b0_a2 = -1;
static int s_last_32e6b0_a3 = -1;
static int s_last_32e6b0_t0 = -1;

static int s_func28_calls = 0;
static int s_last_func28_a1 = -1;

static int s_mgr_func18_calls = 0;
static void *s_last_mgr_self = nullptr;
static int s_last_mgr_a1 = -1;
static int s_last_mgr_a2 = -1;
static int s_mgr_wrong_slot_calls = 0;

static std::vector<const char*> s_call_order;

static int mock_func_168(void *self, void *sp120, void *sp126, int a3, int t0, int t1, int t2, int t3) {
    (void)self;
    (void)sp120;
    (void)sp126;
    (void)t0;
    (void)t1;
    (void)t2;
    (void)t3;
    s_func168_calls++;
    s_last_168_a3 = a3;
    s_call_order.push_back("target_func_168");
    return s_func168_ret;
}

static int mock_func_184(void *self, void *entity, ...) {
    (void)self;
    s_func184_calls++;
    s_last_184_entity = entity;
    s_call_order.push_back("target_func_184");
    return s_func184_ret;
}

static void *mock_func_13c(void *self, int a1, int a2, void *sp116, int a4, int a5, int a6, int a7) {
    (void)self;
    (void)sp116;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    s_func13c_calls++;
    s_last_13c_a1 = a1;
    s_last_13c_a2 = a2;
    s_call_order.push_back("self_func_13c");
    return s_func13c_ret;
}

static void mock_func_28(void *self, int a1) {
    (void)self;
    s_func28_calls++;
    s_last_func28_a1 = a1;
    s_call_order.push_back("self_func_28");
}

static void mock_mgr_func_18(void *self, int a1, int a2) {
    s_mgr_func18_calls++;
    s_last_mgr_self = self;
    s_last_mgr_a1 = a1;
    s_last_mgr_a2 = a2;
    s_call_order.push_back("mgr_func_18");
}

static void mock_mgr_wrong_slot(void *self, int a1, int a2) {
    (void)self;
    (void)a1;
    (void)a2;
    s_mgr_wrong_slot_calls++;
    s_call_order.push_back("mgr_wrong_slot");
}

extern "C" {
    void func_0032E820(CombatSubsystemControllerInstance *self) {
        s_32e820_calls++;
        s_last_32e820_self = self;
        s_call_order.push_back("func_0032E820");
    }

    void sub_31A160(CombatSubsystemControllerInstance *self, int sound_id, int param) {
        (void)self;
        s_sub31a160_calls++;
        s_last_31a160_sound_id = sound_id;
        s_last_31a160_param = param;
        s_call_order.push_back("sub_31A160");
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
static CombatSubsystemVtable s_ctrl_vtable;
static int s_dummy_entity = 0x1234;

static void reset_mocks() {
    D_004E2EA0 = 1;
    s_32e820_calls = 0;
    s_last_32e820_self = nullptr;

    s_func168_calls = 0;
    s_func168_ret = 1;
    s_last_168_a3 = 0;

    s_func13c_calls = 0;
    s_func13c_ret = nullptr;
    s_last_13c_a1 = -1;
    s_last_13c_a2 = -1;

    s_func184_calls = 0;
    s_func184_ret = 1;
    s_last_184_entity = nullptr;

    s_sub31a160_calls = 0;
    s_last_31a160_sound_id = -1;
    s_last_31a160_param = -1;

    s_32d400_calls = 0;
    s_32d400_ret = 51;
    s_last_32d400_mode = -1;
    s_last_32d400_flag = -1;
    s_last_32d400_x = -1;
    s_last_32d400_y = -1;
    s_last_32d400_buf = nullptr;

    s_32e580_calls = 0;
    s_last_32e580_buf = nullptr;

    s_32e6b0_calls = 0;
    s_last_32e6b0_a1 = -1;
    s_last_32e6b0_a2 = -1;
    s_last_32e6b0_a3 = -1;
    s_last_32e6b0_t0 = -1;

    s_func28_calls = 0;
    s_last_func28_a1 = -1;

    s_mgr_func18_calls = 0;
    s_last_mgr_self = nullptr;
    s_last_mgr_a1 = -1;
    s_last_mgr_a2 = -1;
    s_mgr_wrong_slot_calls = 0;

    s_call_order.clear();

    std::memset(&s_mgr_vtable, 0, sizeof(s_mgr_vtable));
    s_mgr_vtable.func_14 = mock_mgr_wrong_slot;
    s_mgr_vtable.func_18 = mock_mgr_func_18;
    s_mgr_vtable.func_1C = mock_mgr_wrong_slot;

    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_vtable = &s_mgr_vtable;

    std::memset(&s_target_vtable, 0, sizeof(s_target_vtable));
    s_target_vtable.func_168 = mock_func_168;
    s_target_vtable.func_184 = mock_func_184;
    s_target_sub.m_vtable = &s_target_vtable;

    std::memset(&s_target_obj, 0, sizeof(s_target_obj));
    s_target_obj.m_sub6960 = &s_target_sub;

    std::memset(&s_ctrl_vtable, 0, sizeof(s_ctrl_vtable));
    s_ctrl_vtable.func_28 = mock_func_28;
    s_ctrl_vtable.func_13C = mock_func_13c;
}

static void test_gate_d004e2ea0_zero() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_ctrl_vtable;
    inst.m_target = &s_target_obj;

    D_004E2EA0 = 0; // gate fails

    int ret = func_0032E220(&inst, 10, 20, 30);

    TEST_ASSERT(ret == 0, "D_004E2EA0==0 must return 0");
    TEST_ASSERT(s_32e820_calls == 1, "must call func_0032E820 first");
    TEST_ASSERT(s_last_32e820_self == &inst, "func_0032E820 self mismatch");
    TEST_ASSERT(s_func168_calls == 0, "D_004E2EA0==0 must suppress target func_168");
    TEST_ASSERT(s_call_order.size() == 1, "only cleanup should be called on gate zero");
}

static void test_target_query_zero() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_ctrl_vtable;
    inst.m_target = &s_target_obj;

    s_func168_ret = 0; // target query returns 0

    int ret = func_0032E220(&inst, 10, 20, 30);

    TEST_ASSERT(ret == 0, "target query zero must return 0");
    TEST_ASSERT(s_32e820_calls == 1, "must call func_0032E820 first");
    TEST_ASSERT(s_func168_calls == 1, "must call target func_168 once");
    TEST_ASSERT(s_last_168_a3 == -1, "func_168 a3 must be -1");
    TEST_ASSERT(s_func13c_calls == 0, "target query 0 must suppress func_13C");
}

static void test_entity_branch_hit() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_ctrl_vtable;
    inst.m_target = &s_target_obj;

    s_func168_ret = 1;
    s_func13c_ret = &s_dummy_entity; // entity found
    s_func184_ret = 1; // hit

    int ret = func_0032E220(&inst, 10, 20, 30);

    TEST_ASSERT(ret == 1, "entity branch hit must return 1");
    TEST_ASSERT(s_32e820_calls == 1, "must call func_0032E820 first");
    TEST_ASSERT(s_func168_calls == 1, "must call target func_168 once");
    TEST_ASSERT(s_func13c_calls == 1, "must call func_13C once");
    TEST_ASSERT(s_last_13c_a1 == 10, "func_13C a1 mismatch");
    TEST_ASSERT(s_last_13c_a2 == 20, "func_13C a2 mismatch");
    TEST_ASSERT(s_func184_calls == 1, "must call target func_184 once");
    TEST_ASSERT(s_last_184_entity == &s_dummy_entity, "func_184 entity mismatch");
    TEST_ASSERT(s_sub31a160_calls == 1, "must call sub_31A160 once");
    TEST_ASSERT(s_last_31a160_sound_id == 1500, "sub_31A160 sound_id must be 1500");
    TEST_ASSERT(s_last_31a160_param == 30, "sub_31A160 param must be a3");
    TEST_ASSERT(s_32d400_calls == 0, "entity branch must suppress raycast func_0032D400");
    TEST_ASSERT(s_mgr_wrong_slot_calls == 0, "must not call adjacent manager vtable slots");
    TEST_ASSERT(s_mgr_func18_calls == 1, "must call manager func_18 once");
    TEST_ASSERT(s_last_mgr_self == D_004E3180, "manager receiver mismatch");
    TEST_ASSERT(s_last_mgr_a1 == 0, "manager a1 must be 0");
    TEST_ASSERT(s_last_mgr_a2 == 0, "manager a2 must be 0");
}

static void test_raycast_miss() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_ctrl_vtable;
    inst.m_target = &s_target_obj;

    s_func168_ret = 1;
    s_func13c_ret = nullptr; // no entity
    s_32d400_ret = 0; // miss (not 51)

    int ret = func_0032E220(&inst, 11, 22, 33);

    TEST_ASSERT(ret == 0, "raycast miss must return 0");
    TEST_ASSERT(s_func13c_calls == 1, "must call func_13C once");
    TEST_ASSERT(s_32d400_calls == 1, "must call func_0032D400 once");
    TEST_ASSERT(s_last_32d400_mode == 40, "func_0032D400 mode must be 40");
    TEST_ASSERT(s_last_32d400_flag == 0, "func_0032D400 flag must be 0");
    TEST_ASSERT(s_last_32d400_x == 11, "func_0032D400 x mismatch");
    TEST_ASSERT(s_last_32d400_y == 22, "func_0032D400 y mismatch");
    TEST_ASSERT(s_32e580_calls == 0, "raycast miss must suppress func_0032E580");
    TEST_ASSERT(s_32e6b0_calls == 0, "raycast miss must suppress func_0032E6B0");
    TEST_ASSERT(s_func28_calls == 0, "raycast miss must suppress func_28");
    TEST_ASSERT(s_mgr_func18_calls == 1, "raycast miss must notify manager");
    TEST_ASSERT(s_last_mgr_self == D_004E3180, "manager receiver mismatch");
    TEST_ASSERT(s_last_mgr_a1 == 0, "manager a1 must be 0");
    TEST_ASSERT(s_last_mgr_a2 == 0, "manager a2 must be 0");
}

static void test_raycast_hit_success() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_ctrl_vtable;
    inst.m_target = &s_target_obj;

    s_func168_ret = 1;
    s_func13c_ret = nullptr; // no entity
    s_32d400_ret = 51; // hit 51
    s_func184_ret = 1;

    int ret = func_0032E220(&inst, 11, 22, 33);

    TEST_ASSERT(ret == 1, "raycast hit success must return 1");
    TEST_ASSERT(s_32e820_calls == 1, "must call func_0032E820 first");
    TEST_ASSERT(s_func13c_calls == 1, "must call func_13C once");
    TEST_ASSERT(s_32d400_calls == 1, "must call func_0032D400 once");
    TEST_ASSERT(s_32e580_calls == 1, "must call func_0032E580 once");
    TEST_ASSERT(s_last_32e580_buf == s_last_32d400_buf, "func_0032E580 buf must match func_0032D400 buf");
    TEST_ASSERT(s_func184_calls == 1, "must call target func_184 once");
    TEST_ASSERT(s_32e6b0_calls == 1, "must call func_0032E6B0 once");
    TEST_ASSERT(s_last_32e6b0_a1 == 2961, "func_0032E6B0 a1 must be 2961");
    TEST_ASSERT(s_last_32e6b0_a2 == 0, "func_0032E6B0 a2 must be 0");
    TEST_ASSERT(s_last_32e6b0_a3 == -1, "func_0032E6B0 a3 must be -1");
    TEST_ASSERT(s_last_32e6b0_t0 == 1, "func_0032E6B0 t0 must be 1");
    TEST_ASSERT(s_func28_calls == 1, "must call self func_28 once");
    TEST_ASSERT(s_last_func28_a1 == 1, "func_28 a1 must be 1");
    TEST_ASSERT(s_mgr_wrong_slot_calls == 0, "must not call adjacent manager vtable slots");
    TEST_ASSERT(s_mgr_func18_calls == 1, "must call manager func_18 once");
    TEST_ASSERT(s_last_mgr_self == D_004E3180, "manager receiver mismatch");
    TEST_ASSERT(s_last_mgr_a1 == 0, "manager a1 must be 0");
    TEST_ASSERT(s_last_mgr_a2 == 0, "manager a2 must be 0");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "gate_zero") == 0) { test_gate_d004e2ea0_zero(); return 0; }
        if (std::strcmp(argv[1], "target_zero") == 0) { test_target_query_zero(); return 0; }
        if (std::strcmp(argv[1], "entity_hit") == 0) { test_entity_branch_hit(); return 0; }
        if (std::strcmp(argv[1], "raycast_miss") == 0) { test_raycast_miss(); return 0; }
        if (std::strcmp(argv[1], "raycast_hit") == 0) { test_raycast_hit_success(); return 0; }
    }
    test_gate_d004e2ea0_zero();
    test_target_query_zero();
    test_entity_branch_hit();
    test_raycast_miss();
    test_raycast_hit_success();
    return 0;
}
