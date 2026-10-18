#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_controller_instance.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static_assert(sizeof(void *) == 4, "PS2 pointer width");
static_assert(sizeof(int) == 4, "PS2 int width");
static_assert(offsetof(CombatSubsystemControllerInstance, m_vtable) == 0x00, "vtable");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_DC) == 0xDC, "field_DC");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_2398) == 0x2398, "field_2398");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_3408) == 0x3408, "field_3408");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_340C) == 0x340C, "field_340C");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_3410) == 0x3410, "field_3410");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_3414) == 0x3414, "field_3414");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_3418) == 0x3418, "field_3418");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_341C) == 0x341C, "field_341C");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_3420) == 0x3420, "field_3420");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_3424) == 0x3424, "field_3424");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_3428) == 0x3428, "field_3428");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_342C) == 0x342C, "field_342C");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_3430) == 0x3430, "field_3430");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_3434) == 0x3434, "field_3434");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_345C) == 0x345C, "field_345C");
static_assert(offsetof(CombatSubsystemControllerInstance, m_field_3484) == 0x3484, "field_3484");

static int s_dummy_vtable = 0x12345678;
void *D_004DED20[] = { &s_dummy_vtable };

static int s_base_calls = 0;
static void *s_last_base_self = nullptr;

extern "C" {
    void *func_318340(void *self) {
        s_base_calls++;
        s_last_base_self = self;
        return self;
    }
}

static void test_base_call() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0xAA, sizeof(inst));
    s_base_calls = 0;
    s_last_base_self = nullptr;

    func_003291F0(&inst);
    TEST_ASSERT(s_base_calls == 1, "base constructor must be called exactly once");
    TEST_ASSERT(s_last_base_self == &inst, "base constructor self parameter mismatch");
}

static void test_vtable() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0xAA, sizeof(inst));
    func_003291F0(&inst);
    TEST_ASSERT(inst.m_vtable == D_004DED20, "vtable pointer must be set to D_004DED20");
}

static void test_field_dc() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0xAA, sizeof(inst));
    func_003291F0(&inst);
    TEST_ASSERT(inst.m_field_DC == 10, "field_DC must be initialized to 10");
}

static void test_field_2398() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0xAA, sizeof(inst));
    func_003291F0(&inst);
    TEST_ASSERT(inst.m_field_2398 == 41, "field_2398 must be initialized to 41");
}

static void test_scalar_flags() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0xAA, sizeof(inst));
    func_003291F0(&inst);
    TEST_ASSERT(inst.m_field_3408 == 0, "field_3408 must be 0");
    TEST_ASSERT(inst.m_field_340C == 0, "field_340C must be 0");
    TEST_ASSERT(inst.m_field_3410 == 0, "field_3410 must be 0");
    TEST_ASSERT(inst.m_field_3414 == -1, "field_3414 must be -1");
    TEST_ASSERT(inst.m_field_3418 == -1, "field_3418 must be -1");
    TEST_ASSERT(inst.m_field_341C == 1, "field_341C must be 1");
    TEST_ASSERT(inst.m_field_3420 == 0, "field_3420 must be 0");
    TEST_ASSERT(inst.m_field_3424 == 0, "field_3424 must be 0");
    TEST_ASSERT(inst.m_field_3428 == 0, "field_3428 must be 0");
    TEST_ASSERT(inst.m_field_342C == 0, "field_342C must be 0");
    TEST_ASSERT(inst.m_field_3430 == 0, "field_3430 must be 0");
    TEST_ASSERT(inst.m_field_3484 == 0, "field_3484 must be 0");
}

static void test_table_entries() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0xAA, sizeof(inst));
    func_003291F0(&inst);
    for (int i = 0; i < 10; ++i) {
        TEST_ASSERT(inst.m_field_3434[i] == 0, "field_3434 array slot must be 0");
        TEST_ASSERT(inst.m_field_345C[i] == -1, "field_345C array slot must be -1");
    }
}

static void test_return_this() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0xAA, sizeof(inst));
    CombatSubsystemControllerInstance *res = func_003291F0(&inst);
    TEST_ASSERT(res == &inst, "constructor must return this pointer");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "base_call") == 0) { test_base_call(); return 0; }
        if (std::strcmp(argv[1], "vtable") == 0) { test_vtable(); return 0; }
        if (std::strcmp(argv[1], "field_dc") == 0) { test_field_dc(); return 0; }
        if (std::strcmp(argv[1], "field_2398") == 0) { test_field_2398(); return 0; }
        if (std::strcmp(argv[1], "scalar_flags") == 0) { test_scalar_flags(); return 0; }
        if (std::strcmp(argv[1], "table_entries") == 0) { test_table_entries(); return 0; }
        if (std::strcmp(argv[1], "return_this") == 0) { test_return_this(); return 0; }
    }
    test_base_call();
    test_vtable();
    test_field_dc();
    test_field_2398();
    test_scalar_flags();
    test_table_entries();
    test_return_this();
    return 0;
}
