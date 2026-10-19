#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_selection_box_clear.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static int s_31a720_calls = 0;
static void *s_last_31a720_self = nullptr;
static int s_last_31a720_a1 = 0;
static int s_last_31a720_a2 = 0;
static int s_last_31a720_a3 = 0;
static int s_last_31a720_t0 = 0;

static int s_func28_calls = 0;
static void *s_last_func28_self = nullptr;
static int s_last_func28_a1 = 0;

static std::vector<const char*> s_call_order;

extern "C" {
    void sub_31A720(void *self, int a1, int a2, int a3, int t0) {
        s_31a720_calls++;
        s_last_31a720_self = self;
        s_last_31a720_a1 = a1;
        s_last_31a720_a2 = a2;
        s_last_31a720_a3 = a3;
        s_last_31a720_t0 = t0;
        s_call_order.push_back("sub_31A720");
    }
}

class MockCombatSubsystemControllerInstance : public CombatSubsystemControllerInstance {
public:
    void func_00() override {}
    void func_04() override {}
    void func_08() override {}
    void func_0C() override {}
    void func_10() override {}
    void func_14() override {}
    void func_18() override {}
    void func_1C() override {}
    void func_28(int a1) override {
        s_func28_calls++;
        s_last_func28_self = this;
        s_last_func28_a1 = a1;
        s_call_order.push_back("func_28");
    }
};

static void reset_mocks() {
    s_31a720_calls = 0;
    s_last_31a720_self = nullptr;
    s_last_31a720_a1 = 0;
    s_last_31a720_a2 = 0;
    s_last_31a720_a3 = 0;
    s_last_31a720_t0 = 0;

    s_func28_calls = 0;
    s_last_func28_self = nullptr;
    s_last_func28_a1 = 0;

    s_call_order.clear();
}

static void test_selection_box_clear_contracts() {
    reset_mocks();
    MockCombatSubsystemControllerInstance inst;

    int ret = func_0032E460(&inst);

    TEST_ASSERT(ret == 0, "func_0032E460 must return 0");
    TEST_ASSERT(s_31a720_calls == 1, "must call sub_31A720 once");
    TEST_ASSERT(s_last_31a720_self == &inst, "sub_31A720 self mismatch");
    TEST_ASSERT(s_last_31a720_a1 == -1, "sub_31A720 a1 must be -1");
    TEST_ASSERT(s_last_31a720_a2 == -1, "sub_31A720 a2 must be -1");
    TEST_ASSERT(s_last_31a720_a3 == -1, "sub_31A720 a3 must be -1");
    TEST_ASSERT(s_last_31a720_t0 == -1, "sub_31A720 t0 must be -1");

    TEST_ASSERT(s_func28_calls == 1, "must call func_28 once");
    TEST_ASSERT(s_last_func28_self == &inst, "func_28 self mismatch");
    TEST_ASSERT(s_last_func28_a1 == 1, "func_28 a1 must be 1");

    TEST_ASSERT(s_call_order.size() == 2, "must have exactly 2 calls in order");
    TEST_ASSERT(std::strcmp(s_call_order[0], "sub_31A720") == 0, "sub_31A720 must be called before func_28");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_28") == 0, "func_28 must be called after sub_31A720");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "clear_contracts") == 0) { test_selection_box_clear_contracts(); return 0; }
    }
    test_selection_box_clear_contracts();
    return 0;
}
