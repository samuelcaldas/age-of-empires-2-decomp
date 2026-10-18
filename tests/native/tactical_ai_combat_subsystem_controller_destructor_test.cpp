#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_controller_destructor.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static int s_dummy_vtable = 0x12345678;
void *D_004DED20[] = { &s_dummy_vtable };

static int s_cleanup_calls = 0;
static void *s_last_cleanup_self = nullptr;

static int s_base_dtor_calls = 0;
static void *s_last_base_dtor_self = nullptr;
static int s_last_base_dtor_flags = -1;

static int s_delete_calls = 0;
static void *s_last_delete_ptr = nullptr;

extern "C" {
    void func_32E820(void *self) {
        s_cleanup_calls++;
        s_last_cleanup_self = self;
    }

    void func_318760(void *self, int flags) {
        s_base_dtor_calls++;
        s_last_base_dtor_self = self;
        s_last_base_dtor_flags = flags;
    }

    void func_100670(void *ptr) {
        s_delete_calls++;
        s_last_delete_ptr = ptr;
    }
}

static void reset_mocks() {
    s_cleanup_calls = 0;
    s_last_cleanup_self = nullptr;
    s_base_dtor_calls = 0;
    s_last_base_dtor_self = nullptr;
    s_last_base_dtor_flags = -1;
    s_delete_calls = 0;
    s_last_delete_ptr = nullptr;
}

static void test_null_self() {
    reset_mocks();
    void *res = func_003292A0(nullptr, 1);
    TEST_ASSERT(res == nullptr, "destructor with null self must return null");
    TEST_ASSERT(s_cleanup_calls == 0, "destructor with null self must not call cleanup");
    TEST_ASSERT(s_base_dtor_calls == 0, "destructor with null self must not call base dtor");
    TEST_ASSERT(s_delete_calls == 0, "destructor with null self must not call operator delete");
}

static void test_non_deleting() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0x55, sizeof(inst));

    void *res = func_003292A0(&inst, 0);
    TEST_ASSERT(res == &inst, "destructor must return self pointer");
    TEST_ASSERT(inst.m_vtable == D_004DED20, "destructor must install D_004DED20 vtable");
    TEST_ASSERT(s_cleanup_calls == 1, "member cleanup func_32E820 must be called once");
    TEST_ASSERT(s_last_cleanup_self == &inst, "member cleanup self mismatch");
    TEST_ASSERT(s_base_dtor_calls == 1, "base destructor func_318760 must be called once");
    TEST_ASSERT(s_last_base_dtor_self == &inst, "base destructor self mismatch");
    TEST_ASSERT(s_last_base_dtor_flags == 0, "base destructor flags must be 0");
    TEST_ASSERT(s_delete_calls == 0, "non-deleting destructor must not call operator delete");
}

static void test_deleting() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0x55, sizeof(inst));

    void *res = func_003292A0(&inst, 1);
    TEST_ASSERT(res == &inst, "deleting destructor must return self pointer");
    TEST_ASSERT(inst.m_vtable == D_004DED20, "deleting destructor must install D_004DED20 vtable");
    TEST_ASSERT(s_cleanup_calls == 1, "deleting member cleanup func_32E820 must be called once");
    TEST_ASSERT(s_base_dtor_calls == 1, "deleting base destructor func_318760 must be called once");
    TEST_ASSERT(s_last_base_dtor_flags == 0, "deleting base destructor flags must be 0");
    TEST_ASSERT(s_delete_calls == 1, "deleting destructor must call operator delete once");
    TEST_ASSERT(s_last_delete_ptr == &inst, "operator delete ptr mismatch");
}

static void test_negative_flags() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0x55, sizeof(inst));

    void *res = func_003292A0(&inst, -1);
    TEST_ASSERT(res == &inst, "negative flag destructor must return self pointer");
    TEST_ASSERT(s_cleanup_calls == 1, "negative flag cleanup must be called");
    TEST_ASSERT(s_base_dtor_calls == 1, "negative flag base destructor must be called");
    TEST_ASSERT(s_delete_calls == 0, "negative flag must not trigger operator delete");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "null_self") == 0) { test_null_self(); return 0; }
        if (std::strcmp(argv[1], "non_deleting") == 0) { test_non_deleting(); return 0; }
        if (std::strcmp(argv[1], "deleting") == 0) { test_deleting(); return 0; }
        if (std::strcmp(argv[1], "negative_flags") == 0) { test_negative_flags(); return 0; }
    }
    test_null_self();
    test_non_deleting();
    test_deleting();
    test_negative_flags();
    return 0;
}
