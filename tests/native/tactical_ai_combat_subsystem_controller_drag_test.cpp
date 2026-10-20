#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cstring>
#include "tactical_ai_combat_subsystem_controller_drag.h"

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
static int s_329450_calls = 0;
static int s_last_329450_lock = -1;
static int s_sub0036ddf0_calls = 0;
static unsigned char s_mock_buffer[256];
static unsigned int s_2261C0_ret = 2000;
static int s_204920_calls = 0;
static float s_last_204920_x = 0;
static float s_last_204920_y = 0;
static int s_v28_self_calls = 0;
static int s_v28_child_calls = 0;
static int s_func44_calls = 0;
static float s_last_func44_a1 = 0;
static float s_last_func44_a2 = 0;

extern "C" {
    int func_185DC0(SystemManager *) { return s_185DC0_ret; }
    void func_00329450(CombatSubsystemControllerInstance *inst, int lock) {
        s_329450_calls++;
        s_last_329450_lock = lock;
        if (inst) {
            inst->m_lock_342C = lock;
        }
    }
    void sub_0036ddf0(void *buf) {
        s_sub0036ddf0_calls++;
        std::memcpy(buf, s_mock_buffer, sizeof(s_mock_buffer));
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

static void mock_target_sub_func_44(void *, float a1, float a2) {
    s_func44_calls++;
    s_last_func44_a1 = a1;
    s_last_func44_a2 = a2;
}

static ViewVtable s_self_vtable = { {}, mock_view_func_28_self };
static ViewVtable s_child_vtable = { {}, mock_view_func_28_child };
static TargetSubVtable s_target_sub_vtable = { {}, mock_target_sub_func_44 };

static void reset_mocks() {
    std::memset(&s_sub28, 0, sizeof(s_sub28));
    s_sub28.m_duration_94 = 100;
    s_sub28.m_max_speed_98 = 10.0f;
    s_sub28.m_margin_9C = 5.0f;

    std::memset(&s_mgr, 0, sizeof(s_mgr));
    s_mgr.m_sub28 = &s_sub28;
    s_mgr.m_mode = 4;
    s_mgr.m_field_1CC = 18;

    s_185DC0_ret = 0;
    s_329450_calls = 0;
    s_last_329450_lock = -1;
    s_sub0036ddf0_calls = 0;
    std::memset(s_mock_buffer, 0xFF, sizeof(s_mock_buffer)); // default: no directional input
    s_2261C0_ret = 2000;
    s_204920_calls = 0;
    s_last_204920_x = 0;
    s_last_204920_y = 0;
    s_v28_self_calls = 0;
    s_v28_child_calls = 0;
    s_func44_calls = 0;
    s_last_func44_a1 = 0;
    s_last_func44_a2 = 0;
}

static void test_gate_rejection() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_self_vtable;
    inst.m_field_90 = 1;
    inst.m_lock_342C = 1;

    // 1. Manager busy check
    s_185DC0_ret = 1;
    int ret = func_003299F0(&inst);
    TEST_ASSERT(s_sub0036ddf0_calls == 0, "busy manager must not query controller buffer");
    TEST_ASSERT(ret == 0, "busy manager must return 0");
    TEST_ASSERT(s_329450_calls == 1, "busy manager must call func_00329450");
    TEST_ASSERT(s_last_329450_lock == 0, "busy manager must reset lock to 0");

    // 2. Unsupported mode check (e.g. mode 1)
    reset_mocks();
    s_mgr.m_mode = 1;
    ret = func_003299F0(&inst);
    TEST_ASSERT(ret == 0, "unsupported mode must return 0");
    TEST_ASSERT(s_329450_calls == 1, "unsupported mode must call func_00329450");
    TEST_ASSERT(s_last_329450_lock == 0, "unsupported mode must reset lock to 0");

    // 3. m_field_90 == 0 check
    reset_mocks();
    inst.m_field_90 = 0;
    ret = func_003299F0(&inst);
    TEST_ASSERT(ret == 0, "zero field_90 must return 0");
    TEST_ASSERT(s_329450_calls == 1, "zero field_90 must call func_00329450");
    TEST_ASSERT(s_last_329450_lock == 0, "zero field_90 must reset lock to 0");
}

static void test_center_idle() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_self_vtable;
    inst.m_field_90 = 1;
    inst.m_lock_342C = 1;

    TargetSubCA8 sub_ca8;
    std::memset(&sub_ca8, 0, sizeof(sub_ca8));
    sub_ca8.m_vtable = &s_target_sub_vtable;

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    target.m_sub_ca8 = &sub_ca8;
    inst.m_target = &target;

    int ret = func_003299F0(&inst);
    TEST_ASSERT(s_329450_calls == 1, "center idle must call func_00329450");
    TEST_ASSERT(s_last_329450_lock == 0, "center idle must reset lock to 0");
    TEST_ASSERT(ret == 0, "center idle must return 0");
    TEST_ASSERT(s_204920_calls == 0, "center idle should not apply movement");
    TEST_ASSERT(s_v28_self_calls == 0, "center idle should not notify views");
}

static void test_drag_movement() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_self_vtable;
    inst.m_field_90 = 1;
    inst.m_lock_342C = 0;

    TargetSubCA8 sub_ca8;
    std::memset(&sub_ca8, 0, sizeof(sub_ca8));
    sub_ca8.m_vtable = &s_target_sub_vtable;
    sub_ca8.m_x = 100.0f;
    sub_ca8.m_y = 200.0f;

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    target.m_x = 500.0f;
    target.m_y = 500.0f;
    target.m_sub_ca8 = &sub_ca8;
    inst.m_target = &target;

    ViewObj child;
    child.m_vtable = &s_child_vtable;
    inst.m_child_3408 = &child;

    // Set byte 165 (offset 37) to 0 (< 2) -> activates s2 = -1 (left direction)
    s_mock_buffer[165 - 128] = 0;

    int ret = func_003299F0(&inst);
    TEST_ASSERT(s_329450_calls == 1, "drag movement must call func_00329450");
    TEST_ASSERT(s_last_329450_lock == 1, "drag movement initial must set lock to 1");
    TEST_ASSERT(ret == 1, "drag movement return must be 1");
    TEST_ASSERT(s_204920_calls == 1, "drag movement must apply movement");
    TEST_ASSERT(s_last_204920_x == 499.0f, "drag movement target X mismatch");
    TEST_ASSERT(s_last_204920_y == 499.0f, "drag movement target Y mismatch");
    TEST_ASSERT(s_v28_self_calls == 1, "drag movement self view notification failed");
    TEST_ASSERT(s_v28_child_calls == 1, "drag movement child view notification failed");
    TEST_ASSERT(inst.m_time_3428 == 2000, "drag movement timestamp update failed");
    TEST_ASSERT(s_func44_calls == 1, "drag movement sub_ca8 func_44 call failed");
}

static void test_acceleration_clamping() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_self_vtable;
    inst.m_field_90 = 1;
    inst.m_lock_342C = 1; // already locked -> accelerates
    inst.m_time_3428 = 1000;

    TargetSubCA8 sub_ca8;
    std::memset(&sub_ca8, 0, sizeof(sub_ca8));
    sub_ca8.m_vtable = &s_target_sub_vtable;

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    target.m_x = 500.0f;
    target.m_y = 500.0f;
    target.m_sub_ca8 = &sub_ca8;
    inst.m_target = &target;

    // dt = 2500 - 1000 = 1500; progress = 1500 / 100 = 15.0f; clamp to max_speed 8.0f
    s_2261C0_ret = 2500;
    s_sub28.m_max_speed_98 = 8.0f;
    s_mock_buffer[165 - 128] = 0; // s2 = -1

    int ret = func_003299F0(&inst);
    TEST_ASSERT(ret == 1, "acceleration return must be 1");
    TEST_ASSERT(s_329450_calls == 0, "accelerated path must not call lock setter");
    TEST_ASSERT(s_204920_calls == 1, "acceleration movement call count failed");
    TEST_ASSERT(s_last_204920_x == 492.0f, "acceleration clamped speed target X mismatch");
    TEST_ASSERT(s_last_204920_y == 492.0f, "acceleration clamped speed target Y mismatch");
    TEST_ASSERT(inst.m_time_3428 == 2500, "acceleration timestamp update failed");
}

static void test_combined_directional_inputs() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_vtable = &s_self_vtable;
    inst.m_field_90 = 1;
    inst.m_lock_342C = 0;

    TargetSubCA8 sub_ca8;
    std::memset(&sub_ca8, 0, sizeof(sub_ca8));
    sub_ca8.m_vtable = &s_target_sub_vtable;

    TargetObj target;
    std::memset(&target, 0, sizeof(target));
    target.m_x = 500.0f;
    target.m_y = 500.0f;
    target.m_sub_ca8 = &sub_ca8;
    inst.m_target = &target;

    ViewObj child;
    child.m_vtable = &s_child_vtable;
    inst.m_child_3408 = &child;

    // Both X (right: byte 167 = 0 -> s2 = 1) and Y (down: byte 168 = 0 -> s3 = 1) active
    s_mock_buffer[167 - 128] = 0;
    s_mock_buffer[168 - 128] = 0;

    int ret = func_003299F0(&inst);
    TEST_ASSERT(ret == 1, "combined input return must be 1");
    TEST_ASSERT(s_329450_calls == 1, "combined input must activate lock");
    TEST_ASSERT(s_func44_calls == 2, "combined input must invoke both sub_ca8 callbacks");
    TEST_ASSERT(s_204920_calls == 2, "combined input must apply both X and Y movements");
    // Initial speed = 1.0f (initial lock == 0), speed2 = 2.0f
    // s3 == 1 (down): target->m_x - speed2, target->m_y + speed2
    TEST_ASSERT(s_last_204920_x == 498.0f, "combined input last target X mismatch");
    TEST_ASSERT(s_last_204920_y == 502.0f, "combined input last target Y mismatch");
    TEST_ASSERT(s_v28_self_calls == 1, "combined input self view notification failed");
    TEST_ASSERT(s_v28_child_calls == 1, "combined input child view notification failed");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "gate_rejection") == 0) { test_gate_rejection(); return 0; }
        if (std::strcmp(argv[1], "center_idle") == 0) { test_center_idle(); return 0; }
        if (std::strcmp(argv[1], "drag_movement") == 0) { test_drag_movement(); return 0; }
        if (std::strcmp(argv[1], "acceleration") == 0) { test_acceleration_clamping(); return 0; }
        if (std::strcmp(argv[1], "combined_inputs") == 0) { test_combined_directional_inputs(); return 0; }
    }
    test_gate_rejection();
    test_center_idle();
    test_drag_movement();
    test_acceleration_clamping();
    test_combined_directional_inputs();
    return 0;
}
