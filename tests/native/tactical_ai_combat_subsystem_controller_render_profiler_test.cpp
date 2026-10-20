#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_render_profiler.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_2261c0_calls = 0;
static int s_2261c0_sequence[4] = { 100, 115, 0, 0 };

static int s_184bf0_calls = 0;
static SystemManager *s_last_184bf0_mgr = nullptr;
static int s_last_184bf0_channel = -1;
static int s_184bf0_sequence[4] = { 20, 25, 0, 0 };

static int s_v30_calls = 0;
static void *s_last_v30_self = nullptr;
static int s_last_v30_a1 = -1;

static int s_1abd90_calls = 0;
static void *s_last_1abd90_a0 = nullptr;
static void *s_last_1abd90_a1 = nullptr;
static unsigned char s_last_1abd90_a2 = 0;

static int s_v34_calls = 0;
static void *s_last_v34_self = nullptr;

static int s_31aab0_calls = 0;
static void *s_last_31aab0_self = nullptr;

struct MetricRecord {
    int channel;
    int val;
};
static std::vector<MetricRecord> s_metric_records;

static int s_184bb0_calls = 0;
static SystemManager *s_last_184bb0_mgr = nullptr;

static std::vector<const char*> s_call_order;

extern "C" {
    int func_2261C0(void) {
        int val = s_2261c0_sequence[s_2261c0_calls % 4];
        s_2261c0_calls++;
        s_call_order.push_back("func_2261C0");
        return val;
    }
    int func_184BF0(SystemManager *mgr, int channel) {
        s_last_184bf0_mgr = mgr;
        s_last_184bf0_channel = channel;
        int val = s_184bf0_sequence[s_184bf0_calls % 4];
        s_184bf0_calls++;
        s_call_order.push_back("func_184BF0");
        return val;
    }
    void func_1ABD90(void *a0, void *a1, unsigned char a2) {
        s_1abd90_calls++;
        s_last_1abd90_a0 = a0;
        s_last_1abd90_a1 = a1;
        s_last_1abd90_a2 = a2;
        s_call_order.push_back("func_1ABD90");
    }
    void func_31AAB0(CombatSubsystemControllerInstance *self) {
        s_31aab0_calls++;
        s_last_31aab0_self = self;
        s_call_order.push_back("func_31AAB0");
    }
    void func_184B60(SystemManager *mgr, int channel, int val) {
        s_metric_records.push_back({ channel, val });
        (void)mgr;
        s_call_order.push_back("func_184B60");
    }
    void func_184BB0(SystemManager *mgr) {
        s_184bb0_calls++;
        s_last_184bb0_mgr = mgr;
        s_call_order.push_back("func_184BB0");
    }
}

static void mock_view_func_30(void *self, int a1) {
    s_v30_calls++;
    s_last_v30_self = self;
    s_last_v30_a1 = a1;
    s_call_order.push_back("func_30");
}

static void mock_view_func_34(void *self) {
    s_v34_calls++;
    s_last_v34_self = self;
    s_call_order.push_back("func_34");
}

static CombatSubsystemVtable s_vtable = {
    {}, mock_view_func_30, mock_view_func_34
};

static void reset_mocks() {
    s_2261c0_calls = 0;
    s_2261c0_sequence[0] = 100;
    s_2261c0_sequence[1] = 115;
    s_184bf0_calls = 0;
    s_last_184bf0_mgr = nullptr;
    s_last_184bf0_channel = -1;
    s_184bf0_sequence[0] = 20;
    s_184bf0_sequence[1] = 25;
    s_v30_calls = 0;
    s_last_v30_self = nullptr;
    s_last_v30_a1 = -1;
    s_1abd90_calls = 0;
    s_last_1abd90_a0 = nullptr;
    s_last_1abd90_a1 = nullptr;
    s_last_1abd90_a2 = 0;
    s_v34_calls = 0;
    s_last_v34_self = nullptr;
    s_31aab0_calls = 0;
    s_last_31aab0_self = nullptr;
    s_metric_records.clear();
    s_184bb0_calls = 0;
    s_last_184bb0_mgr = nullptr;
    s_call_order.clear();
}

static void test_null_target_branch() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_20 = (void*)0x12345678;
    inst.m_field_10B = 0x5A;
    inst.m_field_12C = (void*)0x99998888;
    inst.m_target = nullptr; // null target with valid m_field_12C tests OR condition

    func_0032C500(&inst);
    TEST_ASSERT(s_2261c0_calls == 2, "must call func_2261C0 twice");
    TEST_ASSERT(s_184bf0_calls == 2, "must call func_184BF0 twice");
    TEST_ASSERT(s_v30_calls == 1, "must call func_30 once");
    TEST_ASSERT(s_last_v30_self == &inst, "func_30 self mismatch");
    TEST_ASSERT(s_last_v30_a1 == 0, "func_30 a1 must be 0");
    TEST_ASSERT(s_1abd90_calls == 1, "must call func_1ABD90 once");
    TEST_ASSERT(s_last_1abd90_a0 == (void*)0x12345678, "func_1ABD90 a0 mismatch");
    TEST_ASSERT(s_last_1abd90_a1 == &inst.m_field_24, "func_1ABD90 a1 mismatch");
    TEST_ASSERT(s_last_1abd90_a2 == 0x5A, "func_1ABD90 a2 mismatch");
    TEST_ASSERT(s_v34_calls == 1, "must call func_34 once");
    TEST_ASSERT(s_last_v34_self == &inst, "func_34 self mismatch");
    TEST_ASSERT(s_31aab0_calls == 0, "must suppress func_31AAB0 on null target");

    // Metrics verification:
    // start: time=100, metric=20
    // end: metric=25, time=115
    // delta = 25 - 20 = 5
    // elapsed = 115 - 100 = 15
    // channel 6: elapsed - delta = 15 - 5 = 10
    // channel 12: delta = 5
    TEST_ASSERT(s_metric_records.size() == 2, "must record two metric updates");
    TEST_ASSERT(s_metric_records[0].channel == 6, "first metric channel must be 6");
    TEST_ASSERT(s_metric_records[0].val == 10, "channel 6 delta mismatch");
    TEST_ASSERT(s_metric_records[1].channel == 12, "second metric channel must be 12");
    TEST_ASSERT(s_metric_records[1].val == 5, "channel 12 delta mismatch");
    TEST_ASSERT(s_184bb0_calls == 1, "must call func_184BB0 once");
    TEST_ASSERT(s_last_184bb0_mgr == D_004E3180, "func_184BB0 mgr mismatch");

    // Order: func_2261C0 -> func_184BF0 -> func_30 -> func_1ABD90 -> func_34 -> func_184BF0 -> func_2261C0 -> func_184B60 -> func_184BB0 -> func_184B60
    TEST_ASSERT(s_call_order.size() == 10, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_2261C0") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_184BF0") == 0, "call 1 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[2], "func_30") == 0, "call 2 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[3], "func_1ABD90") == 0, "call 3 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[4], "func_34") == 0, "call 4 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[5], "func_184BF0") == 0, "call 5 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[6], "func_2261C0") == 0, "call 6 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[7], "func_184B60") == 0, "call 7 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[8], "func_184BB0") == 0, "call 8 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[9], "func_184B60") == 0, "call 9 mismatch");
}

static void test_active_target_branch() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;

    TargetObj target;
    inst.m_field_12C = (void*)0x11112222;
    inst.m_target = &target;

    func_0032C500(&inst);
    TEST_ASSERT(s_2261c0_calls == 2, "must call func_2261C0 twice");
    TEST_ASSERT(s_184bf0_calls == 2, "must call func_184BF0 twice");
    TEST_ASSERT(s_31aab0_calls == 1, "must call func_31AAB0 once");
    TEST_ASSERT(s_last_31aab0_self == &inst, "func_31AAB0 self mismatch");
    TEST_ASSERT(s_v30_calls == 0, "active target must suppress func_30");
    TEST_ASSERT(s_1abd90_calls == 0, "active target must suppress func_1ABD90");
    TEST_ASSERT(s_v34_calls == 0, "active target must suppress func_34");

    TEST_ASSERT(s_metric_records.size() == 2, "must record two metric updates");
    TEST_ASSERT(s_184bb0_calls == 1, "must call func_184BB0 once");

    // Order: func_2261C0 -> func_184BF0 -> func_31AAB0 -> func_184BF0 -> func_2261C0 -> func_184B60 -> func_184BB0 -> func_184B60
    TEST_ASSERT(s_call_order.size() == 8, "call order size mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_2261C0") == 0, "call 0 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_184BF0") == 0, "call 1 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[2], "func_31AAB0") == 0, "call 2 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[3], "func_184BF0") == 0, "call 3 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[4], "func_2261C0") == 0, "call 4 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[5], "func_184B60") == 0, "call 5 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[6], "func_184BB0") == 0, "call 6 mismatch");
    TEST_ASSERT(std::strcmp(s_call_order[7], "func_184B60") == 0, "call 7 mismatch");
}

static void test_null_field_12c_active_target() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_vtable;
    inst.m_field_20 = (void*)0x87654321;
    inst.m_field_10B = 0xA5;

    TargetObj target;
    inst.m_field_12C = nullptr; // null field 12C
    inst.m_target = &target;    // non-null target

    func_0032C500(&inst);
    TEST_ASSERT(s_v30_calls == 1, "null field_12C must dispatch func_30");
    TEST_ASSERT(s_last_v30_self == &inst, "func_30 self mismatch");
    TEST_ASSERT(s_last_v30_a1 == 0, "func_30 a1 must be 0");
    TEST_ASSERT(s_1abd90_calls == 1, "null field_12C must dispatch func_1ABD90");
    TEST_ASSERT(s_last_1abd90_a0 == (void*)0x87654321, "func_1ABD90 a0 mismatch");
    TEST_ASSERT(s_last_1abd90_a1 == &inst.m_field_24, "func_1ABD90 a1 mismatch");
    TEST_ASSERT(s_last_1abd90_a2 == 0xA5, "func_1ABD90 a2 mismatch");
    TEST_ASSERT(s_v34_calls == 1, "null field_12C must dispatch func_34");
    TEST_ASSERT(s_31aab0_calls == 0, "null field_12C must suppress func_31AAB0");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "null_target") == 0) { test_null_target_branch(); return 0; }
        if (std::strcmp(argv[1], "active_target") == 0) { test_active_target_branch(); return 0; }
        if (std::strcmp(argv[1], "null_12c") == 0) { test_null_field_12c_active_target(); return 0; }
    }
    test_null_target_branch();
    test_active_target_branch();
    test_null_field_12c_active_target();
    return 0;
}
