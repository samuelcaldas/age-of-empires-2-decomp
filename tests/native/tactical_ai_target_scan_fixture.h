#ifndef TACTICAL_AI_TARGET_SCAN_FIXTURE_H
#define TACTICAL_AI_TARGET_SCAN_FIXTURE_H

#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_target_scan.h"

static_assert(sizeof(void *) == 4, "requires 32-bit pointers");

struct MarkCallRecord {
    TargetEntity *ent;
    int mark;
    int a3;
    int t0;
};

struct ActionCallRecord {
    TargetEntity *ent;
    int a2;
    int s6;
    int s2;
};

struct PlotCallRecord {
    int x;
    int y;
    int mark;
    int type;
};

static const int S_MAX_CALLS = 64;
static MarkCallRecord s_mark_log[S_MAX_CALLS];
static ActionCallRecord s_action_log[S_MAX_CALLS];
static PlotCallRecord s_plot_log[S_MAX_CALLS];

static int s_timestamp = 1000;
static int s_gate_check_return = 1;
static int s_gate_check_calls = 0;
static int s_cleanup_calls = 0;
static int s_waypoint_cost_calls = 0;
static int s_mark_calls = 0;
static int s_last_mark = 0;
static int s_last_a3 = 0;
static int s_last_t0 = 0;
static int s_action_calls = 0;
static int s_last_action_s6 = 0;
static int s_last_action_s2 = 0;
static int s_plot_calls = 0;

static int mock_is_ally(void *, int p) { return p == 1; }
static int mock_is_enemy(void *, int p) { return p == 2; }
static int mock_is_neutral(void *, int) { return 0; }
static void *s_diplomacy_vtable[16] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    reinterpret_cast<void *>(mock_is_enemy),
    reinterpret_cast<void *>(mock_is_ally),
    reinterpret_cast<void *>(mock_is_neutral)
};

extern "C" {
int func_2261c0() { return s_timestamp; }
int func_1ab8f0(void *, int one) { assert(one == 1); s_gate_check_calls++; return s_gate_check_return; }
void func_1ab9d0(void *) { s_cleanup_calls++; }
void func_309500(void *, TargetEntity *e, int mark, int a3, int t0) {
    if (s_mark_calls < S_MAX_CALLS) {
        s_mark_log[s_mark_calls].ent = e;
        s_mark_log[s_mark_calls].mark = mark;
        s_mark_log[s_mark_calls].a3 = a3;
        s_mark_log[s_mark_calls].t0 = t0;
    }
    s_mark_calls++; s_last_mark = mark; s_last_a3 = a3; s_last_t0 = t0;
}
void func_309330(void *, TargetEntity *e, int a2, int s6, int s2) {
    if (s_action_calls < S_MAX_CALLS) {
        s_action_log[s_action_calls].ent = e;
        s_action_log[s_action_calls].a2 = a2;
        s_action_log[s_action_calls].s6 = s6;
        s_action_log[s_action_calls].s2 = s2;
    }
    s_action_calls++; s_last_action_s6 = s6; s_last_action_s2 = s2;
}
int func_00268500(TargetEntity *) { return 1; }
int func_00268530(TargetEntity *) { return 1; }
int func_00268610(TargetEntity *, int, int, int, int, int, int, int) { return 1; }
int func_26ad20(TargetEntity *, int sixteen) { assert(sixteen == 16); return 1; }
int func_123350(float val) { return static_cast<int>(val); }
void func_00308A70(void *, int x, int y, int mark, int type) {
    if (s_plot_calls < S_MAX_CALLS) {
        s_plot_log[s_plot_calls].x = x;
        s_plot_log[s_plot_calls].y = y;
        s_plot_log[s_plot_calls].mark = mark;
        s_plot_log[s_plot_calls].type = type;
    }
    s_plot_calls++;
}
void func_00307640(void *) { s_waypoint_cost_calls++; }
}

static void reset_tracking() {
    s_timestamp = 1000;
    s_gate_check_return = 1;
    s_gate_check_calls = 0;
    s_cleanup_calls = 0;
    s_waypoint_cost_calls = 0;
    s_mark_calls = 0;
    s_last_mark = 0;
    s_last_a3 = 0;
    s_last_t0 = 0;
    s_action_calls = 0;
    s_last_action_s6 = 0;
    s_last_action_s2 = 0;
    s_plot_calls = 0;
    std::memset(s_mark_log, 0, sizeof(s_mark_log));
    std::memset(s_action_log, 0, sizeof(s_action_log));
    std::memset(s_plot_log, 0, sizeof(s_plot_log));
}

#endif // TACTICAL_AI_TARGET_SCAN_FIXTURE_H
