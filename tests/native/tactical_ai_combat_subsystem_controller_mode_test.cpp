#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_controller_mode.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static_assert(sizeof(void *) == 4, "PS2 pointer width");
static_assert(sizeof(int) == 4, "PS2 int width");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_3410) == 0x3410, "m_field_3410 offset");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_341C) == 0x341C, "m_field_341C offset");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_3420) == 0x3420, "m_field_3420 offset");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_3424) == 0x3424, "m_field_3424 offset");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_342C) == 0x342C, "m_field_342C offset");

struct SystemManager {};
static SystemManager s_dummy_mgr;
SystemManager *D_004E3180 = &s_dummy_mgr;

static int s_mgr_active = 1;
static unsigned int s_mgr_divisor = 10;
static unsigned int s_mgr_dividend = 420; // 420 / 10 = 42 > 40
static int s_mgr_busy = 0;
static int s_notify_calls = 0;
static int s_last_notify_a1 = -1;
static int s_last_notify_a2 = -1;

extern "C" {
    int func_1880D0(SystemManager *mgr) {
        TEST_ASSERT(mgr == D_004E3180, "func_1880D0 mgr mismatch");
        return s_mgr_active;
    }
    unsigned int func_184C10(SystemManager *mgr) {
        TEST_ASSERT(mgr == D_004E3180, "func_184C10 mgr mismatch");
        return s_mgr_divisor;
    }
    unsigned int func_184BD0(SystemManager *mgr, int a1) {
        TEST_ASSERT(mgr == D_004E3180, "func_184BD0 mgr mismatch");
        TEST_ASSERT(a1 == 1, "func_184BD0 a1 mismatch");
        return s_mgr_dividend;
    }
    int func_185DC0(SystemManager *mgr) {
        TEST_ASSERT(mgr == D_004E3180, "func_185DC0 mgr mismatch");
        return s_mgr_busy;
    }
    void func_185F00(SystemManager *mgr, int a1, int a2) {
        TEST_ASSERT(mgr == D_004E3180, "func_185F00 mgr mismatch");
        s_notify_calls++;
        s_last_notify_a1 = a1;
        s_last_notify_a2 = a2;
    }
}

static void reset_mocks() {
    s_mgr_active = 1;
    s_mgr_divisor = 10;
    s_mgr_dividend = 420;
    s_mgr_busy = 0;
    s_notify_calls = 0;
    s_last_notify_a1 = -1;
    s_last_notify_a2 = -1;
}

static void test_same_mode() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_field_3410 = 5;
    inst.m_field_341C = 1;

    func_00329350(&inst, 5);
    TEST_ASSERT(inst.m_field_3410 == 5, "same mode should keep field_3410");
    TEST_ASSERT(s_notify_calls == 0, "same mode should not perform manager calls");
}

static void test_flag_gate() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_field_3410 = 0;
    inst.m_field_341C = 0; // gate disabled

    func_00329350(&inst, 1);
    TEST_ASSERT(inst.m_field_3410 == 1, "field_3410 must be updated even if gate is zero");
    TEST_ASSERT(inst.m_field_3424 == 0, "gate zero must not set field_3424");
    TEST_ASSERT(s_notify_calls == 0, "gate zero must not call notify");
}

static void test_mgr_inactive() {
    reset_mocks();
    s_mgr_active = 0;
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_field_3410 = 0;
    inst.m_field_341C = 1;

    func_00329350(&inst, 1);
    TEST_ASSERT(inst.m_field_3410 == 1, "field_3410 must be updated when mgr inactive");
    TEST_ASSERT(inst.m_field_3424 == 0, "inactive mgr must not set field_3424");
    TEST_ASSERT(s_notify_calls == 0, "inactive mgr must not call notify");
}

static void test_enable_success() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_field_3410 = 0;
    inst.m_field_341C = 1;

    func_00329350(&inst, 2);
    TEST_ASSERT(inst.m_field_3410 == 2, "enable success field_3410 mismatch");
    TEST_ASSERT(inst.m_field_3424 == 1, "enable success field_3424 must be 1");
    TEST_ASSERT(inst.m_field_3420 == 1, "enable success field_3420 must be 1");
    TEST_ASSERT(s_notify_calls == 1, "enable success notify call count failed");
    TEST_ASSERT(s_last_notify_a1 == 1, "enable success notify a1 mismatch");
    TEST_ASSERT(s_last_notify_a2 == 1, "enable success notify a2 mismatch");
}

static void test_enable_low_ratio() {
    reset_mocks();
    s_mgr_divisor = 10;
    s_mgr_dividend = 400; // 400 / 10 = 40 <= 40 -> threshold check fails
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_field_3410 = 0;
    inst.m_field_341C = 1;

    func_00329350(&inst, 1);
    TEST_ASSERT(inst.m_field_3410 == 1, "low ratio field_3410 mismatch");
    TEST_ASSERT(inst.m_field_3424 == 0, "low ratio must not set field_3424");
    TEST_ASSERT(inst.m_field_3420 == 0, "low ratio must not set field_3420");
    TEST_ASSERT(s_notify_calls == 0, "low ratio must not call notify");
}

static void test_enable_busy() {
    reset_mocks();
    s_mgr_busy = 1; // manager busy
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_field_3410 = 0;
    inst.m_field_341C = 1;

    func_00329350(&inst, 1);
    TEST_ASSERT(inst.m_field_3410 == 1, "busy mgr field_3410 mismatch");
    TEST_ASSERT(inst.m_field_3424 == 1, "busy mgr must set field_3424");
    TEST_ASSERT(inst.m_field_3420 == 0, "busy mgr must not set field_3420");
    TEST_ASSERT(s_notify_calls == 0, "busy mgr must not call notify");
}

static void test_disable_locked() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_field_3410 = 1;
    inst.m_field_341C = 1;
    inst.m_field_342C = 1; // locked
    inst.m_field_3424 = 1;
    inst.m_field_3420 = 1;

    func_00329350(&inst, 0);
    TEST_ASSERT(inst.m_field_3410 == 0, "disable locked field_3410 mismatch");
    TEST_ASSERT(inst.m_field_3424 == 1, "locked disable must preserve field_3424");
    TEST_ASSERT(inst.m_field_3420 == 1, "locked disable must preserve field_3420");
    TEST_ASSERT(s_notify_calls == 0, "locked disable must not call notify");
}

static void test_disable_success() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_field_3410 = 1;
    inst.m_field_341C = 1;
    inst.m_field_342C = 0;
    inst.m_field_3424 = 1;
    inst.m_field_3420 = 1;

    func_00329350(&inst, 0);
    TEST_ASSERT(inst.m_field_3410 == 0, "disable success field_3410 mismatch");
    TEST_ASSERT(inst.m_field_3424 == 0, "disable success must clear field_3424");
    TEST_ASSERT(inst.m_field_3420 == 0, "disable success must clear field_3420");
    TEST_ASSERT(s_notify_calls == 1, "disable success notify call count failed");
    TEST_ASSERT(s_last_notify_a1 == 0, "disable success notify a1 mismatch");
    TEST_ASSERT(s_last_notify_a2 == 0, "disable success notify a2 mismatch");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "same_mode") == 0) { test_same_mode(); return 0; }
        if (std::strcmp(argv[1], "flag_gate") == 0) { test_flag_gate(); return 0; }
        if (std::strcmp(argv[1], "mgr_inactive") == 0) { test_mgr_inactive(); return 0; }
        if (std::strcmp(argv[1], "enable_success") == 0) { test_enable_success(); return 0; }
        if (std::strcmp(argv[1], "enable_low_ratio") == 0) { test_enable_low_ratio(); return 0; }
        if (std::strcmp(argv[1], "enable_busy") == 0) { test_enable_busy(); return 0; }
        if (std::strcmp(argv[1], "disable_locked") == 0) { test_disable_locked(); return 0; }
        if (std::strcmp(argv[1], "disable_success") == 0) { test_disable_success(); return 0; }
    }
    test_same_mode();
    test_flag_gate();
    test_mgr_inactive();
    test_enable_success();
    test_enable_low_ratio();
    test_enable_busy();
    test_disable_locked();
    test_disable_success();
    return 0;
}
