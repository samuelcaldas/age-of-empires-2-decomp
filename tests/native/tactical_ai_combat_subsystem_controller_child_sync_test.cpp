#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_child_sync.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static int s_323b50_calls = 0;
static int s_323b50_ret = 1;
static void *s_last_323b50_self = nullptr;

static int s_v28_calls = 0;
static void *s_last_v28_self = nullptr;
static int s_last_v28_a1 = -1;

static std::vector<const char*> s_call_order;

extern "C" {
    int func_00323B50(CombatSubsystemControllerInstance *self) {
        s_323b50_calls++;
        s_last_323b50_self = self;
        s_call_order.push_back("func_00323B50");
        return s_323b50_ret;
    }
}

static void mock_view_func_28(void *self, int a1) {
    s_v28_calls++;
    s_last_v28_self = self;
    s_last_v28_a1 = a1;
    s_call_order.push_back("func_28");
}

static ViewVtable s_view_vtable = {
    {}, mock_view_func_28
};

static void reset_mocks() {
    s_323b50_calls = 0;
    s_323b50_ret = 1;
    s_last_323b50_self = nullptr;
    s_v28_calls = 0;
    s_last_v28_self = nullptr;
    s_last_v28_a1 = -1;
    s_call_order.clear();
}

static void test_child_gate_failure() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    ViewObj view;
    view.m_vtable = &s_view_vtable;
    inst.m_view = &view;

    s_323b50_ret = 0; // gate fails

    int ret = func_0032C420(&inst);
    TEST_ASSERT(ret == 0, "failed child gate must return 0");
    TEST_ASSERT(s_323b50_calls == 1, "must call func_00323B50 once");
    TEST_ASSERT(s_last_323b50_self == &inst, "func_00323B50 self mismatch");
    TEST_ASSERT(s_v28_calls == 0, "failed child gate must suppress view func_28");
    TEST_ASSERT(s_call_order.size() == 1, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_00323B50") == 0, "sole call must be func_00323B50");
}

static void test_child_sync_with_view() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    ViewObj view;
    view.m_vtable = &s_view_vtable;
    inst.m_view = &view;

    s_323b50_ret = 1; // gate passes

    int ret = func_0032C420(&inst);
    TEST_ASSERT(ret == 1, "child sync with view must return 1");
    TEST_ASSERT(s_323b50_calls == 1, "must call func_00323B50 once");
    TEST_ASSERT(s_last_323b50_self == &inst, "func_00323B50 self mismatch");
    TEST_ASSERT(s_v28_calls == 1, "must call view func_28 once");
    TEST_ASSERT(s_last_v28_self == &view, "view func_28 self mismatch");
    TEST_ASSERT(s_last_v28_a1 == 1, "view func_28 a1 must be 1");
    TEST_ASSERT(s_call_order.size() == 2, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_00323B50") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_28") == 0, "call 1 mismatch");
}

static void test_child_sync_without_view() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_view = nullptr; // null view

    s_323b50_ret = 1; // gate passes

    int ret = func_0032C420(&inst);
    TEST_ASSERT(ret == 1, "child sync without view must return 1");
    TEST_ASSERT(s_323b50_calls == 1, "must call func_00323B50 once");
    TEST_ASSERT(s_last_323b50_self == &inst, "func_00323B50 self mismatch");
    TEST_ASSERT(s_v28_calls == 0, "null view must suppress view func_28");
    TEST_ASSERT(s_call_order.size() == 1, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_00323B50") == 0, "sole call must be func_00323B50");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "gate_fail") == 0) { test_child_gate_failure(); return 0; }
        if (std::strcmp(argv[1], "with_view") == 0) { test_child_sync_with_view(); return 0; }
        if (std::strcmp(argv[1], "without_view") == 0) { test_child_sync_without_view(); return 0; }
    }
    test_child_gate_failure();
    test_child_sync_with_view();
    test_child_sync_without_view();
    return 0;
}
