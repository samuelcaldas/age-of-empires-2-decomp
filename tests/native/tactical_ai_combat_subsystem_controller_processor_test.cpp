#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_processor.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static Sub28 s_sub28;
static SystemManager s_mgr;
SystemManager *D_004E3180 = &s_mgr;

static int s_185DC0_ret = 0;
static int s_1F26F0_ret = 0;
static void *s_1F26D0_ret = nullptr;
static int s_329350_calls = 0;
static int s_last_329350_mode = -1;
static int s_225520_axis1_ret = 0;
static int s_225520_axis2_ret = 0;
static unsigned int s_2261C0_ret = 1000;
static int s_204920_calls = 0;
static float s_last_204920_x = 0;
static float s_last_204920_y = 0;
static int s_v28_self_calls = 0;
static int s_v28_child_calls = 0;

static int s_mock_rect[4] = { 100, 100, 800, 600 };
static int s_mock_pos[2] = { 400, 300 };

extern "C" {
    int func_185DC0(SystemManager *) { return s_185DC0_ret; }
    int func_1F26F0(void *) { return s_1F26F0_ret; }
    void *func_1F26D0(void *) { return s_1F26D0_ret; }
    void func_00329350(CombatSubsystemControllerInstance *inst, int mode) {
        s_329350_calls++;
        s_last_329350_mode = mode;
        if (inst) {
            inst->m_mode_3410 = mode;
        }
    }
    void func_2254D0(void *, void *rect_out) {
        std::memcpy(rect_out, s_mock_rect, sizeof(s_mock_rect));
    }
    void func_225560(void *pos_out) {
        std::memcpy(pos_out, s_mock_pos, sizeof(s_mock_pos));
    }
    int func_225520(int axis) {
        return (axis == 1) ? s_225520_axis1_ret : s_225520_axis2_ret;
    }
    unsigned int func_2261C0() { return s_2261C0_ret; }
    int func_123350(float val) { return (int)std::floor(val); }
    void func_204920(TargetObj *, int, float x, float y) {
        s_204920_calls++;
        s_last_204920_x = x;
        s_last_204920_y = y;
    }
}

static void mock_view_func_28_self(void *, int) {
    s_v28_self_calls++;
}

static void mock_view_func_28_child(void *, int) {
    s_v28_child_calls++;
}

static ViewVtable s_self_vtable = { {}, mock_view_func_28_self };
static ViewVtable s_child_vtable = { {}, mock_view_func_28_child };

static void reset_mocks() {
    std::memset(&s_sub28, 0, sizeof(s_sub28));
    s_sub28.m_field_80 = 1;
    s_sub28.m_margin_88 = 50;
    s_sub28.m_max_speed_90 = 10.0f;
    s_sub28.m_duration_94 = 100;
    s_mgr.m_sub28 = &s_sub28;
    s_mgr.m_mode = 4;

    s_185DC0_ret = 0;
    s_1F26F0_ret = 0;
    s_1F26D0_ret = nullptr;
    s_329350_calls = 0;
    s_last_329350_mode = -1;
    s_225520_axis1_ret = 0;
    s_225520_axis2_ret = 0;
    s_2261C0_ret = 1000;
    s_204920_calls = 0;
    s_v28_self_calls = 0;
    s_v28_child_calls = 0;

    s_mock_rect[0] = 100;
    s_mock_rect[1] = 100;
    s_mock_rect[2] = 800;
    s_mock_rect[3] = 600;
    s_mock_pos[0] = 400;
    s_mock_pos[1] = 300;
}

static void test_gate_rejection() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_self_vtable;
    inst.m_field_90 = 1;
    inst.m_mode_3410 = 5;

    Obj20 obj20;
    std::memset(&obj20, 0, sizeof(obj20));
    inst.m_obj_20 = &obj20;

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    inst.m_target = &target;

    s_mock_pos[0] = 120; // in scroll zone

    // Unsupported mode (e.g. 1)
    s_mgr.m_mode = 1;
    int ret = func_00329550(&inst);
    TEST_ASSERT(ret == 0, "unsupported mode must return 0");
    TEST_ASSERT(s_329350_calls == 1, "unsupported mode must call func_00329350");
    TEST_ASSERT(s_last_329350_mode == 0, "unsupported mode must reset mode to 0");

    // Locked instance
    s_mgr.m_mode = 4;
    inst.m_lock_342C = 1;
    s_329350_calls = 0;
    ret = func_00329550(&inst);
    TEST_ASSERT(ret == 0, "locked instance must return 0");
    TEST_ASSERT(s_329350_calls == 1, "locked instance must call func_00329350");
    TEST_ASSERT(s_last_329350_mode == 0, "locked instance must reset mode to 0");
}

static void test_center_no_scroll() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_self_vtable;
    inst.m_field_90 = 1;
    inst.m_mode_3410 = 1;

    Obj20 obj20;
    std::memset(&obj20, 0, sizeof(obj20));
    inst.m_obj_20 = &obj20;

    int ret = func_00329550(&inst);
    TEST_ASSERT(s_204920_calls == 0, "center no-scroll should not apply movement");
    TEST_ASSERT(s_329350_calls == 1, "center no-scroll must call func_00329350");
    TEST_ASSERT(s_last_329350_mode == 0, "center no-scroll must reset mode to 0");
    TEST_ASSERT(ret == 0, "center no-scroll return value mismatch");
}

static void test_left_edge_scroll() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_self_vtable;
    inst.m_field_90 = 1;
    inst.m_mode_3410 = 0;

    Obj20 obj20;
    std::memset(&obj20, 0, sizeof(obj20));
    inst.m_obj_20 = &obj20;

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    target.m_x = 500.0f;
    target.m_y = 500.0f;
    inst.m_target = &target;

    ViewObj child;
    child.m_vtable = &s_child_vtable;
    inst.m_child_3408 = &child;

    s_mock_pos[0] = 120; // 120 < 100 + 50 (left edge scroll active)
    s_mock_pos[1] = 300;

    int ret = func_00329550(&inst);
    TEST_ASSERT(s_329350_calls == 1, "left edge initial must activate mode 1");
    TEST_ASSERT(s_last_329350_mode == 1, "left edge mode call arg mismatch");
    TEST_ASSERT(ret == 1, "left edge return mode mismatch");
    TEST_ASSERT(s_204920_calls == 1, "left edge must apply 1 axis movement");
    TEST_ASSERT(s_last_204920_x == 499.0f, "left edge target X mismatch");
    TEST_ASSERT(s_last_204920_y == 499.0f, "left edge target Y mismatch");
    TEST_ASSERT(s_v28_self_calls == 1, "left edge self view notification failed");
    TEST_ASSERT(s_v28_child_calls == 1, "left edge child view notification failed");
    TEST_ASSERT(inst.m_time_340C == 1000, "left edge timestamp update failed");
}

static void test_right_edge_scroll() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_self_vtable;
    inst.m_field_90 = 1;
    inst.m_mode_3410 = 0;

    Obj20 obj20;
    std::memset(&obj20, 0, sizeof(obj20));
    inst.m_obj_20 = &obj20;

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    target.m_x = 500.0f;
    target.m_y = 500.0f;
    inst.m_target = &target;

    s_mock_pos[0] = 780; // 780 > 800 - 50 - 12 = 738 (right edge scroll active)
    s_mock_pos[1] = 300;

    int ret = func_00329550(&inst);
    TEST_ASSERT(ret == 1, "right edge return mode mismatch");
    TEST_ASSERT(s_204920_calls == 1, "right edge must apply movement");
    TEST_ASSERT(s_last_204920_x == 501.0f, "right edge target X mismatch");
    TEST_ASSERT(s_last_204920_y == 501.0f, "right edge target Y mismatch");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "gate_rejection") == 0) { test_gate_rejection(); return 0; }
        if (std::strcmp(argv[1], "center_idle") == 0) { test_center_no_scroll(); return 0; }
        if (std::strcmp(argv[1], "left_edge") == 0) { test_left_edge_scroll(); return 0; }
        if (std::strcmp(argv[1], "right_edge") == 0) { test_right_edge_scroll(); return 0; }
    }
    test_gate_rejection();
    test_center_no_scroll();
    test_left_edge_scroll();
    test_right_edge_scroll();
    return 0;
}
