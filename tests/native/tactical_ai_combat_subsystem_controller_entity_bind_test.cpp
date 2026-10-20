#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_entity_bind.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static int s_32d400_calls = 0;
static int s_32d400_ret = 52;
static void *s_last_32d400_self = nullptr;
static int s_last_32d400_mode = -1;
static int s_last_32d400_flag = -1;
static int s_last_32d400_x = -1;
static int s_last_32d400_y = -1;
static void *s_last_32d400_buf = nullptr;

static int s_1c8c00_calls = 0;
static void *s_last_1c8c00_handle = nullptr;

static int s_1f6ea0_calls = 0;
static void *s_last_1f6ea0_self = nullptr;
static void *s_last_1f6ea0_res = nullptr;

static int s_1c8c10_calls = 0;
static void *s_last_1c8c10_handle = nullptr;

static int s_1f6ef0_calls = 0;
static int s_1f6ef0_ret = 7;
static void *s_last_1f6ef0_self = nullptr;
static int s_last_1f6ef0_x = -1;
static int s_last_1f6ef0_y = -1;
static char *s_last_1f6ef0_name = nullptr;
static int s_last_1f6ef0_a4 = -1;

static std::vector<const char*> s_call_order;

static struct DummyObj {
    int pad0;
    void *ptr;
} s_dummy_obj = {0, (void*)0x55667788};

static char s_sample_name[] = "Knight";

extern "C" {
    int func_0032D400(CombatSubsystemControllerInstance *self, int mode, int flag, int x, int y, void *buf, void *target_sub, int recurse_flag) {
        (void)target_sub;
        (void)recurse_flag;
        s_32d400_calls++;
        s_last_32d400_self = self;
        s_last_32d400_mode = mode;
        s_last_32d400_flag = flag;
        s_last_32d400_x = x;
        s_last_32d400_y = y;
        s_last_32d400_buf = buf;
        s_call_order.push_back("func_0032D400");
        if (buf && s_32d400_ret == 52) {
            // Place dummy pointer into buffer at offset 12 (sp+108 relative to sp+96)
            void **slot = (void**)((char*)buf + 12);
            *slot = &s_dummy_obj;
        }
        return s_32d400_ret;
    }

    void *sub_1C8C00(void *handle) {
        s_1c8c00_calls++;
        s_last_1c8c00_handle = handle;
        s_call_order.push_back("sub_1C8C00");
        return (void*)0x11223344;
    }

    char *sub_1F6EA0(CombatSubsystemControllerInstance *self, void *sub_res) {
        s_1f6ea0_calls++;
        s_last_1f6ea0_self = self;
        s_last_1f6ea0_res = sub_res;
        s_call_order.push_back("sub_1F6EA0");
        return s_sample_name;
    }

    void sub_1C8C10(void *handle) {
        s_1c8c10_calls++;
        s_last_1c8c10_handle = handle;
        s_call_order.push_back("sub_1C8C10");
    }

    int sub_1F6EF0(CombatSubsystemControllerInstance *self, int x, int y, char *out_name, int a4) {
        s_1f6ef0_calls++;
        s_last_1f6ef0_self = self;
        s_last_1f6ef0_x = x;
        s_last_1f6ef0_y = y;
        s_last_1f6ef0_name = out_name;
        s_last_1f6ef0_a4 = a4;
        s_call_order.push_back("sub_1F6EF0");
        if (out_name) {
            std::strcpy(out_name, "FallbackArcher");
        }
        return s_1f6ef0_ret;
    }
}

static void reset_mocks() {
    s_32d400_calls = 0;
    s_32d400_ret = 52;
    s_last_32d400_self = nullptr;
    s_last_32d400_mode = -1;
    s_last_32d400_flag = -1;
    s_last_32d400_x = -1;
    s_last_32d400_y = -1;
    s_last_32d400_buf = nullptr;

    s_1c8c00_calls = 0;
    s_last_1c8c00_handle = nullptr;

    s_1f6ea0_calls = 0;
    s_last_1f6ea0_self = nullptr;
    s_last_1f6ea0_res = nullptr;

    s_1c8c10_calls = 0;
    s_last_1c8c10_handle = nullptr;

    s_1f6ef0_calls = 0;
    s_1f6ef0_ret = 7;
    s_last_1f6ef0_self = nullptr;
    s_last_1f6ef0_x = -1;
    s_last_1f6ef0_y = -1;
    s_last_1f6ef0_name = nullptr;
    s_last_1f6ef0_a4 = -1;

    s_call_order.clear();
}

static void test_pick_52_binding_order() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    char out_name[64];
    std::memset(out_name, 0, sizeof(out_name));

    int ret = func_0032E4B0(&inst, 10, 20, out_name, 30);

    TEST_ASSERT(ret == 1, "pick 52 hit must return 1");
    TEST_ASSERT(s_32d400_calls == 1, "must call func_0032D400 once");
    TEST_ASSERT(s_last_32d400_self == &inst, "func_0032D400 self mismatch");
    TEST_ASSERT(s_last_32d400_mode == 41, "func_0032D400 mode must be 41");
    TEST_ASSERT(s_last_32d400_flag == 2, "func_0032D400 flag must be 2");
    TEST_ASSERT(s_last_32d400_x == 10, "func_0032D400 x mismatch");
    TEST_ASSERT(s_last_32d400_y == 20, "func_0032D400 y mismatch");

    TEST_ASSERT(s_1c8c00_calls == 1, "must call sub_1C8C00 once on hit");
    TEST_ASSERT(s_last_1c8c00_handle == (void*)0x55667788, "sub_1C8C00 handle mismatch");
    TEST_ASSERT(s_1f6ea0_calls == 1, "must call sub_1F6EA0 once on hit");
    TEST_ASSERT(s_last_1f6ea0_self == &inst, "sub_1F6EA0 self mismatch");
    TEST_ASSERT(s_last_1f6ea0_res == (void*)0x11223344, "sub_1F6EA0 res mismatch");
    TEST_ASSERT(std::strcmp(out_name, "Knight") == 0, "out_name must receive bound name");
    TEST_ASSERT(s_1c8c10_calls == 1, "must call sub_1C8C10 once on hit");
    TEST_ASSERT(s_last_1c8c10_handle == (void*)0x55667788, "sub_1C8C10 handle mismatch");

    TEST_ASSERT(s_1f6ef0_calls == 0, "pick 52 hit must suppress sub_1F6EF0");

    TEST_ASSERT(s_call_order.size() >= 4, "must have at least 4 calls in sequence");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_0032D400") == 0, "call 0 must be D400");
    TEST_ASSERT(std::strcmp(s_call_order[1], "sub_1C8C00") == 0, "call 1 must be 1C8C00");
    TEST_ASSERT(std::strcmp(s_call_order[2], "sub_1F6EA0") == 0, "call 2 must be 1F6EA0");
    TEST_ASSERT(std::strcmp(s_call_order[3], "sub_1C8C10") == 0, "call 3 must be 1C8C10");
}

static void test_non52_fallback_delegation() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    char out_name[64];
    std::memset(out_name, 0, sizeof(out_name));

    s_32d400_ret = 50; // miss (!= 52)
    s_1f6ef0_ret = 42;

    int ret = func_0032E4B0(&inst, 15, 25, out_name, 35);

    TEST_ASSERT(ret == 42, "non-52 return must propagate sub_1F6EF0 return value");
    TEST_ASSERT(s_32d400_calls == 1, "must call func_0032D400 once");
    TEST_ASSERT(s_1f6ef0_calls == 1, "must call sub_1F6EF0 once on miss");
    TEST_ASSERT(s_last_1f6ef0_self == &inst, "sub_1F6EF0 self mismatch");
    TEST_ASSERT(s_last_1f6ef0_x == 15, "sub_1F6EF0 x mismatch");
    TEST_ASSERT(s_last_1f6ef0_y == 25, "sub_1F6EF0 y mismatch");
    TEST_ASSERT(s_last_1f6ef0_name == out_name, "sub_1F6EF0 out_name mismatch");
    TEST_ASSERT(s_last_1f6ef0_a4 == 35, "sub_1F6EF0 a4 mismatch");
    TEST_ASSERT(std::strcmp(out_name, "FallbackArcher") == 0, "out_name must receive fallback name");

    TEST_ASSERT(s_1c8c00_calls == 0, "non-52 miss must suppress sub_1C8C00");
    TEST_ASSERT(s_1f6ea0_calls == 0, "non-52 miss must suppress sub_1F6EA0");
    TEST_ASSERT(s_1c8c10_calls == 0, "non-52 miss must suppress sub_1C8C10");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "pick_52") == 0) { test_pick_52_binding_order(); return 0; }
        if (std::strcmp(argv[1], "fallback") == 0) { test_non52_fallback_delegation(); return 0; }
    }
    test_pick_52_binding_order();
    test_non52_fallback_delegation();
    return 0;
}
