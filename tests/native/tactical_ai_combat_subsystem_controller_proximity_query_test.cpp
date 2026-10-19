#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_proximity_query.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static int s_func120_calls = 0;
static void *s_last_120_self = nullptr;
static int s_last_120_a1 = -1;
static int s_last_120_a2 = -1;
static int s_last_120_a3 = -1;
static int s_last_120_t0 = -1;
static int s_last_120_t1 = -1;
static int s_last_120_t2 = -1;
static int s_last_120_t3 = -1;
static int s_120_return_val = 0;

static int mock_func_120(void *self, int a1, int a2, int a3, int t0, int t1, int t2, int t3) {
    s_func120_calls++;
    s_last_120_self = self;
    s_last_120_a1 = a1;
    s_last_120_a2 = a2;
    s_last_120_a3 = a3;
    s_last_120_t0 = t0;
    s_last_120_t1 = t1;
    s_last_120_t2 = t2;
    s_last_120_t3 = t3;
    return s_120_return_val;
}

extern "C" {
    void func_117AF8(void *dest, int unused, int count) {
        (void)unused;
        if (dest && count > 0) {
            std::memset(dest, 0, count);
        }
    }
}

static CombatSubsystemVtable s_vtable;

static void reset_mocks() {
    s_func120_calls = 0;
    s_last_120_self = nullptr;
    s_last_120_a1 = -1;
    s_last_120_a2 = -1;
    s_last_120_a3 = -1;
    s_last_120_t0 = -1;
    s_last_120_t1 = -1;
    s_last_120_t2 = -1;
    s_last_120_t3 = -1;
    s_120_return_val = 0;

    std::memset(&s_vtable, 0, sizeof(s_vtable));
    s_vtable.func_120 = mock_func_120;
}

static void test_func120_zero_return() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    int status = 0x999;
    int ret = func_0032DA90(&inst, 50, 60, &status, 1, 2, 3, 4);

    TEST_ASSERT(ret == 0, "func_120 zero return must return 0");
    TEST_ASSERT(status == 0, "out_status must be zeroed on entry");
    TEST_ASSERT(s_func120_calls == 1, "func_120 must be called once");
    TEST_ASSERT(s_last_120_self == &inst, "func_120 self mismatch");
    TEST_ASSERT(s_last_120_a1 == 50, "func_120 a1 mismatch (x)");
    TEST_ASSERT(s_last_120_a2 == 60, "func_120 a2 mismatch (y)");
    TEST_ASSERT(s_last_120_a3 == 10, "func_120 a3 mismatch (10)");
    TEST_ASSERT(s_last_120_t0 == 30, "func_120 t0 mismatch (30)");
    TEST_ASSERT(s_last_120_t1 == 15, "func_120 t1 mismatch (15)");
    TEST_ASSERT(s_last_120_t2 == 4, "func_120 t2 mismatch (4)");
    TEST_ASSERT(s_last_120_t3 == 1, "func_120 t3 mismatch (1)");
}

static void test_null_out_status() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    int ret = func_0032DA90(&inst, 15, 25, nullptr, 0, 0, 0, 0);

    TEST_ASSERT(ret == 0, "null out_status must return 0 on zero return");
    TEST_ASSERT(s_func120_calls == 1, "func_120 must be called once with null out_status");
}

static void test_func120_hit_return() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    s_120_return_val = 1; // hit
    int status = 0x999;
    int ret = func_0032DA90(&inst, 50, 60, &status, 1, 2, 3, 4);

    TEST_ASSERT(ret == 1, "func_120 hit return must return 1");
    TEST_ASSERT(status == 1, "out_status must be set to 1 on hit");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "zero_return") == 0) { test_func120_zero_return(); return 0; }
        if (std::strcmp(argv[1], "null_status") == 0) { test_null_out_status(); return 0; }
        if (std::strcmp(argv[1], "hit_return") == 0) { test_func120_hit_return(); return 0; }
    }
    test_func120_zero_return();
    test_null_out_status();
    test_func120_hit_return();
    return 0;
}
