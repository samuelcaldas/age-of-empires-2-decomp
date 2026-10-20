#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_formation.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;
int D_004E2EA0 = 1;

static int s_32d400_calls = 0;
static int s_32d400_ret = 51;
static void *s_last_32d400_self = nullptr;
static int s_last_32d400_a1 = -1;
static int s_last_32d400_a2 = -1;
static int s_last_32d400_a3 = -1;
static int s_last_32d400_t0 = -1;
static void *s_last_32d400_buf = nullptr;

static int s_32e580_calls = 0;
static void *s_last_32e580_self = nullptr;
static void *s_last_32e580_buf = nullptr;

static int s_186010_calls = 0;
static int s_1aab30_calls = 0;
static int s_26a680_calls = 0;
static int s_1830e0_calls = 0;
static int s_262fa0_calls = 0;
static int s_332e60_calls = 0;

static std::vector<const char*> s_call_order;

extern "C" {
    int func_0032D400(CombatSubsystemControllerInstance *self, int a1, int a2, int a3, int t0, void *buf, void *target_sub, int flag) {
        (void)target_sub;
        (void)flag;
        s_32d400_calls++;
        s_last_32d400_self = self;
        s_last_32d400_a1 = a1;
        s_last_32d400_a2 = a2;
        s_last_32d400_a3 = a3;
        s_last_32d400_t0 = t0;
        s_last_32d400_buf = buf;
        s_call_order.push_back("func_0032D400");
        return s_32d400_ret;
    }
    void func_0032E580(CombatSubsystemControllerInstance *self, void *buf) {
        s_32e580_calls++;
        s_last_32e580_self = self;
        s_last_32e580_buf = buf;
        s_call_order.push_back("func_0032E580");
    }
    int func_186010(SystemManager *, int) {
        s_186010_calls++;
        s_call_order.push_back("func_186010");
        return 1;
    }
    void func_1AAB30(void *, int) {
        s_1aab30_calls++;
        s_call_order.push_back("func_1AAB30");
    }
    void func_26A680(void *) {
        s_26a680_calls++;
        s_call_order.push_back("func_26A680");
    }
    void func_1830E0(void *, int) {
        s_1830e0_calls++;
        s_call_order.push_back("func_1830E0");
    }
    void func_262FA0(void *) {
        s_262fa0_calls++;
        s_call_order.push_back("func_262FA0");
    }
    void func_332E60(void *) {
        s_332e60_calls++;
        s_call_order.push_back("func_332E60");
    }
}

static void reset_mocks() {
    D_004E2EA0 = 1;
    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_32d400_calls = 0;
    s_32d400_ret = 51;
    s_last_32d400_self = nullptr;
    s_last_32d400_a1 = -1;
    s_last_32d400_a2 = -1;
    s_last_32d400_a3 = -1;
    s_last_32d400_t0 = -1;
    s_last_32d400_buf = nullptr;
    s_32e580_calls = 0;
    s_last_32e580_self = nullptr;
    s_last_32e580_buf = nullptr;
    s_186010_calls = 0;
    s_1aab30_calls = 0;
    s_26a680_calls = 0;
    s_1830e0_calls = 0;
    s_262fa0_calls = 0;
    s_332e60_calls = 0;
    s_call_order.clear();
}

static void test_gate_d004e2ea0_zero() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    D_004E2EA0 = 0; // gate fails

    int ret = func_0032C600(&inst, 10, 20, 1);
    TEST_ASSERT(ret == 0, "D_004E2EA0==0 must return 0");
    TEST_ASSERT(s_32d400_calls == 0, "D_004E2EA0==0 must suppress func_0032D400");
    TEST_ASSERT(s_32e580_calls == 0, "D_004E2EA0==0 must suppress func_0032E580");
    TEST_ASSERT(s_call_order.empty(), "D_004E2EA0==0 must suppress all calls");
}

static void test_d32d400_miss() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    D_004E2EA0 = 1;
    s_32d400_ret = 0; // miss (not 51)

    int ret = func_0032C600(&inst, 11, 22, 1);
    TEST_ASSERT(ret == 0, "func_0032D400 miss must return 0");
    TEST_ASSERT(s_32d400_calls == 1, "must call func_0032D400 once");
    TEST_ASSERT(s_last_32d400_self == &inst, "func_0032D400 self mismatch");
    TEST_ASSERT(s_last_32d400_a1 == 40, "func_0032D400 a1 must be 40");
    TEST_ASSERT(s_last_32d400_a2 == 0, "func_0032D400 a2 must be 0");
    TEST_ASSERT(s_last_32d400_a3 == 11, "func_0032D400 a3 mismatch");
    TEST_ASSERT(s_last_32d400_t0 == 22, "func_0032D400 t0 mismatch");
    TEST_ASSERT(s_last_32d400_buf != nullptr, "func_0032D400 buf must be non-null stack buffer");
    TEST_ASSERT(s_32e580_calls == 0, "func_0032D400 miss must suppress func_0032E580");
}

static void test_formation_success() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    D_004E2EA0 = 1;
    s_32d400_ret = 51; // hit 51

    int ret = func_0032C600(&inst, 11, 22, 1);
    TEST_ASSERT(ret == 1, "formation success must return 1");
    TEST_ASSERT(s_32d400_calls == 1, "must call func_0032D400 once");
    TEST_ASSERT(s_32e580_calls == 1, "must call func_0032E580 once");
    TEST_ASSERT(s_last_32e580_self == &inst, "func_0032E580 self mismatch");
    TEST_ASSERT(s_last_32e580_buf == s_last_32d400_buf, "func_0032E580 buf must match func_0032D400 buf");

    TEST_ASSERT(s_call_order.size() >= 2, "call order size must be at least 2");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_0032D400") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_0032E580") == 0, "call 1 mismatch");
}

static void test_formation_active_target_events() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    TargetObj target;
    inst.m_target = &target;

    D_004E2EA0 = 1;
    s_32d400_ret = 51; // hit 51

    int ret = func_0032C600(&inst, 11, 22, 5); // formation mode 5
    TEST_ASSERT(ret == 1, "active target must return 1");
    TEST_ASSERT(s_32d400_calls == 1, "must call func_0032D400 once");
    TEST_ASSERT(s_32e580_calls == 1, "must call func_0032E580 once");
    TEST_ASSERT(s_186010_calls == 1, "must call func_186010 once");
    TEST_ASSERT(s_1aab30_calls == 1, "must call func_1AAB30 once");
    TEST_ASSERT(s_26a680_calls == 1, "must call func_26A680 once");
    TEST_ASSERT(s_1830e0_calls == 1, "must call func_1830E0 once");
    TEST_ASSERT(s_262fa0_calls == 1, "must call func_262FA0 once");
    TEST_ASSERT(s_332e60_calls == 1, "must call func_332E60 once");

    // Exact ordered callback sequencing:
    // func_0032D400 -> func_0032E580 -> func_186010 -> func_1AAB30 -> func_26A680 -> func_1830E0 -> func_262FA0 -> func_332E60
    TEST_ASSERT(s_call_order.size() == 8, "active target call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_0032D400") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_0032E580") == 0, "call 1 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[2], "func_186010") == 0, "call 2 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[3], "func_1AAB30") == 0, "call 3 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[4], "func_26A680") == 0, "call 4 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[5], "func_1830E0") == 0, "call 5 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[6], "func_262FA0") == 0, "call 6 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[7], "func_332E60") == 0, "call 7 mismatch");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "gate_zero") == 0) { test_gate_d004e2ea0_zero(); return 0; }
        if (std::strcmp(argv[1], "d400_miss") == 0) { test_d32d400_miss(); return 0; }
        if (std::strcmp(argv[1], "success") == 0) { test_formation_success(); return 0; }
        if (std::strcmp(argv[1], "target_events") == 0) { test_formation_active_target_events(); return 0; }
    }
    test_gate_d004e2ea0_zero();
    test_d32d400_miss();
    test_formation_success();
    test_formation_active_target_events();
    return 0;
}
