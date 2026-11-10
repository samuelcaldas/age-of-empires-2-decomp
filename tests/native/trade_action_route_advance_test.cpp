#include <cassert>
#include <cstdio>
#include <cstring>
#include "trade_action_route_advance.h"

float D_004E2824 = 0.0001f;
int D_00F99930[5] = {0, 0, 0, 0, 0};
int *D_00F99910[5] = {NULL, NULL, NULL, NULL, NULL};

static int g_method2c_called = 0;
static int g_methoda0_called = 0;
static int g_method344_called = 0;
static float g_last_dest_x = 0.0f;
static float g_last_dest_y = 0.0f;

#define V_STUB_10(base) \
    int TargetObj::v##base##0() { return 0; } int TargetObj::v##base##1() { return 0; } \
    int TargetObj::v##base##2() { return 0; } int TargetObj::v##base##3() { return 0; } \
    int TargetObj::v##base##4() { return 0; } int TargetObj::v##base##5() { return 0; } \
    int TargetObj::v##base##6() { return 0; } int TargetObj::v##base##7() { return 0; } \
    int TargetObj::v##base##8() { return 0; } int TargetObj::v##base##9() { return 0; }

V_STUB_10(0)
V_STUB_10(1)
V_STUB_10(2)
V_STUB_10(3)
V_STUB_10(4)
V_STUB_10(5)
int TargetObj::v60() { return 0; }
int TargetObj::v61() { return 0; }
int TargetObj::v62() { return 0; }
int TargetObj::v63() { return 0; }
int TargetObj::v64() { return 0; }
int TargetObj::v65() { return 0; }
int TargetObj::v66() { return 0; }
float TargetObj::Method276() { return 10.0f; }
int TargetObj::v68() { return 0; }
int TargetObj::v69() { return 0; }
V_STUB_10(7)
int TargetObj::v80() { return 0; }
int TargetObj::v81() { return 0; }
int TargetObj::v82() { return 0; }
int TargetObj::v83() { return 0; }
int TargetObj::Method344(int a1, int a2) { g_method344_called++; return 1; }
int TargetObj::v85() { return 0; }
int TargetObj::v86() { return 0; }
TargetObj* TargetObj::Method356() { return this; }
int TargetObj::v88() { return 0; }
int TargetObj::v89() { return 0; }
V_STUB_10(9)
V_STUB_10(10)
int TargetObj::v110() { return 0; }
int TargetObj::v111() { return 0; }
int TargetObj::v112() { return 0; }
int TargetObj::v113() { return 0; }
int TargetObj::v114() { return 0; }
int TargetObj::v115() { return 0; }
int TargetObj::Method472() { return 0; }

#define V_ACT_STUB_10(base) \
    int TradeAction::v##base##0() { return 0; } int TradeAction::v##base##1() { return 0; } \
    int TradeAction::v##base##2() { return 0; } int TradeAction::v##base##3() { return 0; } \
    int TradeAction::v##base##4() { return 0; } int TradeAction::v##base##5() { return 0; } \
    int TradeAction::v##base##6() { return 0; } int TradeAction::v##base##7() { return 0; } \
    int TradeAction::v##base##8() { return 0; } int TradeAction::v##base##9() { return 0; }

int TradeAction::v0() { return 0; }
int TradeAction::v1() { return 0; }
int TradeAction::v2() { return 0; }
int TradeAction::v3() { return 0; }
int TradeAction::v4() { return 0; }
int TradeAction::v5() { return 0; }
int TradeAction::v6() { return 0; }
int TradeAction::v7() { return 0; }
int TradeAction::v8() { return 0; }
int TradeAction::Method2C(float x, float y) { g_method2c_called++; return 1; }
V_ACT_STUB_10(1)
V_ACT_STUB_10(2)
int TradeAction::v30() { return 0; }
int TradeAction::v31() { return 0; }
int TradeAction::v32() { return 0; }
int TradeAction::v33() { return 0; }
int TradeAction::v34() { return 0; }
int TradeAction::v35() { return 0; }
int TradeAction::v36() { return 0; }
int TradeAction::v37() { return 0; }
int TradeAction::MethodA0(int a1, float x, float y, float z) {
    g_methoda0_called++;
    g_last_dest_x = x;
    g_last_dest_y = y;
    return 1;
}

static TargetObj g_other_obj;
static TimerNode g_other_node;

extern "C" {
void* func_332e60(void *timer, int id) {
    g_other_node.m_id = 22;
    g_other_obj.m_node = &g_other_node;
    g_other_obj.m_field24 = (short)id;
    g_other_obj.x = 100.0f;
    g_other_obj.y = 200.0f;
    return &g_other_obj;
}

int func_00202B10(void *game) {
    return 1;
}

void* func_001510D0(void *self) {
    return &g_other_obj;
}

int func_001471A0(void *arg) {
    return -1;
}

int func_1AAB30() {
    return 16384;
}
}

int main() {
    // 1. Test func_0014B8E0 stub
    int res = func_0014B8E0(NULL);
    assert(res == 0);

    // 2. Setup TradeAction and TargetObj
    TradeAction action;
    TargetObj target;
    TimerNode target_node;
    char game_buf[3500];
    memset(game_buf, 0, sizeof(game_buf));

    target_node.m_id = 10;
    target.m_node = &target_node;
    target.m_game = game_buf;
    target.m_field24 = 5;
    target.m_field39 = 0;
    target.x = 10.0f;
    target.y = 20.0f;
    target.z = 0.0f;
    target.m_field64 = -1;

    action.m_mode = 0;
    action.m_target = &target;
    action.m_field48 = -1;
    action.m_waypoint_count = 0;
    action.m_waypoint_cap = 0;
    action.m_waypoints = NULL;
    action.m_field154 = 50.0f;
    action.m_field158 = 50.0f;

    // Test early exit when mode is 2/3 and game+2976 is non-null
    *(void**)(game_buf + 2976) = (void*)0x1234;
    action.m_mode = 2;
    assert(func_0014B310(&action, 1, 0) == 0);

    // Reset mode
    action.m_mode = 0;
    *(void**)(game_buf + 2976) = NULL;

    // Test normal route advance
    short wps[2] = { 1, 2 };
    action.m_waypoints = wps;
    action.m_waypoint_count = 2;
    action.m_waypoint_cap = 2;

    int r = func_0014B310(&action, 1, -1);
    assert(r == 1);
    assert(g_methoda0_called == 1);

    printf("trade_action_route_advance_test passed\n");
    return 0;
}
