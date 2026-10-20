#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_pick_query.h"

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

static int s_31c7f0_calls = 0;
static void *s_last_31c7f0_self = nullptr;
static int s_last_31c7f0_mode = -1;
static int s_last_31c7f0_flag = -1;
static int s_last_31c7f0_x = -1;
static int s_last_31c7f0_y = -1;
static void *s_last_31c7f0_buf = nullptr;
static void *s_last_31c7f0_target_sub = nullptr;
static int s_last_31c7f0_recurse_flag = -1;
static int s_31c7f0_return_val = 0x133;

extern "C" {
    int sub_31C7F0(CombatSubsystemControllerInstance *self, int mode, int flag, int x, int y, void *buf, void *target_sub, int recurse_flag) {
        s_31c7f0_calls++;
        s_last_31c7f0_self = self;
        s_last_31c7f0_mode = mode;
        s_last_31c7f0_flag = flag;
        s_last_31c7f0_x = x;
        s_last_31c7f0_y = y;
        s_last_31c7f0_buf = buf;
        s_last_31c7f0_target_sub = target_sub;
        s_last_31c7f0_recurse_flag = recurse_flag;
        return s_31c7f0_return_val;
    }

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

    s_31c7f0_calls = 0;
    s_last_31c7f0_self = nullptr;
    s_last_31c7f0_mode = -1;
    s_last_31c7f0_flag = -1;
    s_last_31c7f0_x = -1;
    s_last_31c7f0_y = -1;
    s_last_31c7f0_buf = nullptr;
    s_last_31c7f0_target_sub = nullptr;
    s_last_31c7f0_recurse_flag = -1;
    s_31c7f0_return_val = 0x133;

    std::memset(&s_vtable, 0, sizeof(s_vtable));
    s_vtable.func_120 = mock_func_120;
}

static void test_mode41_flag0_zero_return() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    char buf[64];
    std::memset(buf, 0xAA, sizeof(buf));

    int ret = func_0032D400(&inst, 41, 0, 100, 200, buf, nullptr, 0);

    TEST_ASSERT(ret == 50, "mode 41 flag 0 zero return must return 50");
    TEST_ASSERT(s_func120_calls == 1, "mode 41 must call func_120 once");
    TEST_ASSERT(s_last_120_self == &inst, "func_120 self mismatch");
    TEST_ASSERT(s_last_120_a1 == 100, "func_120 a1 mismatch (x)");
    TEST_ASSERT(s_last_120_a2 == 200, "func_120 a2 mismatch (y)");
    TEST_ASSERT(s_last_120_a3 == 0, "func_120 a3 mismatch (flag 0)");
    TEST_ASSERT(s_last_120_t0 == 40, "func_120 t0 mismatch (40)");
    TEST_ASSERT(s_last_120_t1 == 15, "func_120 t1 mismatch (15)");
    TEST_ASSERT(s_last_120_t2 == 4, "func_120 t2 mismatch (4)");
    TEST_ASSERT(s_last_120_t3 == 1, "func_120 t3 mismatch (1)");

    for (int i = 0; i < 20; i++) {
        TEST_ASSERT(buf[i] == 0, "mode 41 must zero first 20 bytes of buf");
    }
    TEST_ASSERT((unsigned char)buf[20] == 0xAA, "mode 41 must not zero past 20 bytes");
}

static void test_mode41_flag1_zero_return() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    char buf[64];
    std::memset(buf, 0xBB, sizeof(buf));

    int ret = func_0032D400(&inst, 41, 1, 101, 201, buf, nullptr, 0);

    TEST_ASSERT(ret == 50, "mode 41 flag 1 zero return must return 50");
    TEST_ASSERT(s_func120_calls == 1, "mode 41 flag 1 must call func_120 once");
    TEST_ASSERT(s_last_120_a1 == 101, "func_120 a1 mismatch (x)");
    TEST_ASSERT(s_last_120_a2 == 201, "func_120 a2 mismatch (y)");
    TEST_ASSERT(s_last_120_a3 == 10, "func_120 a3 mismatch (10)");
    TEST_ASSERT(s_last_120_t0 == 30, "func_120 t0 mismatch (30)");
    TEST_ASSERT(s_last_120_t1 == 15, "func_120 t1 mismatch (15)");
    TEST_ASSERT(s_last_120_t2 == 4, "func_120 t2 mismatch (4)");
    TEST_ASSERT(s_last_120_t3 == 1, "func_120 t3 mismatch (1)");
}

static void test_mode42_recurse_hit() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    char buf[64];
    std::memset(buf, 0, sizeof(buf));

    s_120_return_val = 1; // triggers mode 41 return 52
    s_31c7f0_return_val = 0x111; // 0x11 = 17 != 52

    int ret = func_0032D400(&inst, 42, 0, 10, 20, buf, nullptr, 0);

    TEST_ASSERT(ret == 52, "mode 42 recursion hit must return 52");
    TEST_ASSERT(s_func120_calls == 1, "mode 42 recursion hit must invoke func_120 via mode 41");
    TEST_ASSERT(s_31c7f0_calls == 0, "mode 42 recursion hit must suppress sub_31C7F0");
}

static void test_fallback_mode40() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    char buf[64];
    std::memset(buf, 0, sizeof(buf));
    s_31c7f0_return_val = 0x151; // 8-bit masked -> 0x51 = 81

    int ret = func_0032D400(&inst, 40, 2, 5, 6, buf, (void*)0x1234, 1);

    TEST_ASSERT(ret == 0x51, "fallback mode must return masked 8-bit result of sub_31C7F0");
    TEST_ASSERT(s_func120_calls == 0, "fallback mode must not invoke func_120");
    TEST_ASSERT(s_31c7f0_calls == 1, "fallback mode must call sub_31C7F0 once");
    TEST_ASSERT(s_last_31c7f0_self == &inst, "fallback self mismatch");
    TEST_ASSERT(s_last_31c7f0_mode == 40, "fallback mode mismatch");
    TEST_ASSERT(s_last_31c7f0_flag == 2, "fallback flag mismatch");
    TEST_ASSERT(s_last_31c7f0_x == 5, "fallback x mismatch");
    TEST_ASSERT(s_last_31c7f0_y == 6, "fallback y mismatch");
    TEST_ASSERT(s_last_31c7f0_buf == buf, "fallback buf mismatch");
    TEST_ASSERT(s_last_31c7f0_target_sub == (void*)0x1234, "fallback target_sub mismatch");
    TEST_ASSERT(s_last_31c7f0_recurse_flag == 1, "fallback recurse_flag mismatch");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "mode41_flag0") == 0) { test_mode41_flag0_zero_return(); return 0; }
        if (std::strcmp(argv[1], "mode41_flag1") == 0) { test_mode41_flag1_zero_return(); return 0; }
        if (std::strcmp(argv[1], "mode42_recurse") == 0) { test_mode42_recurse_hit(); return 0; }
        if (std::strcmp(argv[1], "fallback") == 0) { test_fallback_mode40(); return 0; }
    }
    test_mode41_flag0_zero_return();
    test_mode41_flag1_zero_return();
    test_mode42_recurse_hit();
    test_fallback_mode40();
    return 0;
}
