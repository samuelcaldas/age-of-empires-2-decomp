#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_build_progress_frame_fixture.h"

static void reset_test_state() {
    g_func_123350_called = 0;
}

static void test_clamps_to_max_progress_and_decrements() {
    reset_test_state();
    DummyFrameMaster master = {};
    master.m_max_progress = 10.0f;
    master.m_max_frame = 20;

    DummyFrameAction action = {};
    action.m_master = &master;
    action.m_progress = 15.0f;

    int frame = func_00270E70((ActionRebind*)&action);
    assert(g_func_123350_called == 1);
    assert(frame == 9);
}

static void test_clamps_to_max_frame() {
    reset_test_state();
    DummyFrameMaster master = {};
    master.m_max_progress = 100.0f;
    master.m_max_frame = 5;

    DummyFrameAction action = {};
    action.m_master = &master;
    action.m_progress = 50.0f;

    int frame = func_00270E70((ActionRebind*)&action);
    assert(frame == 4);
}

static void test_zero_or_negative_returns_zero() {
    reset_test_state();
    DummyFrameMaster master = {};
    master.m_max_progress = 10.0f;
    master.m_max_frame = 5;

    DummyFrameAction action = {};
    action.m_master = &master;
    action.m_progress = 0.0f;

    int frame = func_00270E70((ActionRebind*)&action);
    assert(frame == 0);
}

static void test_progress_within_bounds() {
    reset_test_state();
    DummyFrameMaster master = {};
    master.m_max_progress = 50.0f;
    master.m_max_frame = 20;

    DummyFrameAction action = {};
    action.m_master = &master;
    action.m_progress = 8.0f;

    int frame = func_00270E70((ActionRebind*)&action);
    assert(frame == 7);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_clamps_to_max_progress_and_decrements();
        test_clamps_to_max_frame();
        test_zero_or_negative_returns_zero();
        test_progress_within_bounds();
        return 0;
    }
    int t = atoi(argv[1]);
    if (t == 0) test_clamps_to_max_progress_and_decrements();
    if (t == 1) test_clamps_to_max_frame();
    if (t == 2) test_zero_or_negative_returns_zero();
    if (t == 3) test_progress_within_bounds();
    return 0;
}
