#include <cassert>
#include <cstdlib>
#include <cstring>
#include "trade_action_target_management.h"

// Define dummy virtual methods for TargetObj
#define DEF_STUB(name) int TargetObj::name() { return 0; }
#define DEF_STUB_10(base) \
    DEF_STUB(v##base##0) DEF_STUB(v##base##1) DEF_STUB(v##base##2) DEF_STUB(v##base##3) DEF_STUB(v##base##4) \
    DEF_STUB(v##base##5) DEF_STUB(v##base##6) DEF_STUB(v##base##7) DEF_STUB(v##base##8) DEF_STUB(v##base##9)

DEF_STUB_10(0)
DEF_STUB_10(1)
DEF_STUB_10(2)
DEF_STUB_10(3)
DEF_STUB_10(4)
DEF_STUB_10(5)
DEF_STUB_10(6)
DEF_STUB_10(7)
DEF_STUB_10(8)
DEF_STUB_10(9)
DEF_STUB_10(10)
DEF_STUB(v110) DEF_STUB(v111) DEF_STUB(v112) DEF_STUB(v113) DEF_STUB(v114)
DEF_STUB(v115) DEF_STUB(v116) DEF_STUB(v117) DEF_STUB(v118) DEF_STUB(v119)

static int s_method484_calls = 0;
static int s_method488_calls = 0;
static float s_last_484_x = 0.0f;
static float s_last_484_y = 0.0f;
static float s_last_484_z = 0.0f;

int TargetObj::Method484(float x, float y, float z) {
    s_method484_calls++;
    s_last_484_x = x;
    s_last_484_y = y;
    s_last_484_z = z;
    return 1;
}

int TargetObj::Method488() {
    s_method488_calls++;
    return 1;
}

extern "C" {
int D_00491024 = 0x10;

static int s_func_1fd4e0_calls = 0;
static int s_func_1FC810_calls = 0;
static int s_func_332e60_calls = 0;
static int s_func_00145E30_calls = 0;

void* func_1fd4e0(Vector3 *out, RouteObj *route, int idx) {
    (void)route;
    s_func_1fd4e0_calls++;
    out->x = (float)(idx * 10 + 1);
    out->y = (float)(idx * 10 + 2);
    out->z = (float)(idx * 10 + 3);
    return out;
}

void func_1FC810(RouteObj *route) {
    (void)route;
    s_func_1FC810_calls++;
}

static char s_dummy_entity[128];

void* func_332e60(void *mgr, short id) {
    (void)mgr; (void)id;
    s_func_332e60_calls++;
    return (void*)s_dummy_entity;
}

void func_00145E30(void *ptr, Vector3 *p1, Vector3 *p2) {
    (void)ptr; (void)p1; (void)p2;
    s_func_00145E30_calls++;
}
}

int main() {
    TargetObj target;
    TradeAction action;
    std::memset(&action, 0, sizeof(action));
    action.m_target = &target;

    // Test 1: func_001512A0 without route returns 0
    assert(func_001512A0(&action) == 0);

    // Test 2: func_001512A0 with route of count 2
    RouteObj route;
    std::memset(&route, 0, sizeof(route));
    route.m_count = 2;
    action.m_route_obj = &route;

    int r = func_001512A0(&action);
    assert(r == 1);
    assert(s_method488_calls == 1);
    // 2 loop iterations + 1 final pos call = 3 calls to Method484
    assert(s_method484_calls == 3);

    // Test 3: func_001513E0 & func_001513F0
    assert(func_001513E0(&action) == 0);
    func_001513F0(&action);

    // Test 4: func_00151400 (flags test)
    route.m_flags = 0;
    assert(func_00151400(&action) == 0);
    route.m_flags = 0x10; // matches D_00491024
    assert(func_00151400(&action) == 1);

    // Test 5: func_00151440 (cleanup route)
    action.m_field168 = 99;
    func_00151440(&action);
    assert(s_func_1FC810_calls == 1);
    assert(action.m_route_obj == NULL);
    assert(action.m_field168 == 0);

    // Test 6: func_00151480 (target management setup)
    char game_buf[4000];
    std::memset(game_buf, 0, sizeof(game_buf));
    char timer_buf[512];
    std::memset(timer_buf, 0, sizeof(timer_buf));
    *(void**)(game_buf + 2968) = (void*)timer_buf;
    target.m_game = (void*)game_buf;

    Vector3 p1 = {1.0f, 2.0f, 3.0f};
    Vector3 p2 = {4.0f, 5.0f, 6.0f};

    int r_setup = func_00151480(&action, 10, 20, &p1, 5, &p2);
    assert(r_setup == 1);
    assert(action.m_field68 == 10);
    assert(action.m_field6A == 20);
    assert(s_func_00145E30_calls == 1);

    return 0;
}
