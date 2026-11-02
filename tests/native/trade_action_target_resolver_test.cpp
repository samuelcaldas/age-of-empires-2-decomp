#include <cassert>
#include <cstdio>
#include <cstring>

#define func_0014BCE0 mock_func_0014BCE0
#define func_332e60 mock_func_332e60
#define func_00100630 mock_func_00100630
#define func_00100730 mock_func_00100730
#define func_001FC810 mock_func_001FC810

static int g_bce0_called = 0;
static int g_332e60_called = 0;
static int g_100630_called = 0;
static int g_100730_called = 0;
static int g_1fc810_called = 0;
static int g_method5c_called = 0;
static int g_method1f4_called = 0;

static char g_allocated_buf[1024];

extern "C" {
void mock_func_0014BCE0(void *self) { g_bce0_called++; }
void* mock_func_332e60(void *timer, int a1) { g_332e60_called++; return (void*)0x5555; }
void mock_func_00100630(void *p) { g_100630_called++; }
void* mock_func_00100730(int sz) { g_100730_called++; return g_allocated_buf; }
void mock_func_001FC810(void *obj) { g_1fc810_called++; }
}

#include "../../src/trade/trade_action_target_resolver.cpp"

#define V_STUB_T(base) \
    int TargetObj::v##base##0() { return 0; } int TargetObj::v##base##1() { return 0; } \
    int TargetObj::v##base##2() { return 0; } int TargetObj::v##base##3() { return 0; } \
    int TargetObj::v##base##4() { return 0; } int TargetObj::v##base##5() { return 0; } \
    int TargetObj::v##base##6() { return 0; } int TargetObj::v##base##7() { return 0; } \
    int TargetObj::v##base##8() { return 0; } int TargetObj::v##base##9() { return 0; }

V_STUB_T(0)
V_STUB_T(1)
V_STUB_T(2)
V_STUB_T(3)
V_STUB_T(4)
V_STUB_T(5)
V_STUB_T(6)
V_STUB_T(7)
V_STUB_T(8)
V_STUB_T(9)
V_STUB_T(10)
V_STUB_T(11)
int TargetObj::v120() { return 0; }
int TargetObj::v121() { return 0; }
int TargetObj::v122() { return 0; }
void* TargetObj::Method1F4(void *buf) {
    g_method1f4_called++;
    return (void*)0x8888;
}

#define V_STUB_A(base) \
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
int TradeAction::v9() { return 0; }
V_STUB_A(1)
int TradeAction::v20() { return 0; }
int TradeAction::Method5C(int a1) {
    g_method5c_called++;
    return 1;
}

int main() {
    TradeAction action;
    TargetObj target;
    char game_buf[3500];
    memset(game_buf, 0, sizeof(game_buf));
    *(void**)(game_buf + 0xB98) = (void*)0x3333;

    target.m_game = game_buf;
    action.m_target = &target;

    // 1. Test func_00151120
    action.m_field48 = 610;
    assert(func_00151120(&action) == 1);
    action.m_field48 = 999;
    assert(func_00151120(&action) == 0);

    // 2. Test func_001511A0
    action.m_field44 = 710;
    assert(func_001511A0(&action) == 1);
    action.m_field44 = 999;
    assert(func_001511A0(&action) == 0);

    // 3. Test func_00151220
    action.m_field164 = NULL;
    assert(func_00151220(&action) == 0);
    action.m_field164 = (void*)0x1234;
    assert(func_00151220(&action) == 1);

    // 4. Test func_00151230
    int res = func_00151230(&action);
    assert(res == 1);
    assert(g_1fc810_called == 1);
    assert(g_method1f4_called == 1);
    assert(action.m_field164 == (void*)0x8888);

    // 5. Test func_001510D0
    TargetObj *t = func_001510D0(&action, 42);
    assert(t == (TargetObj*)0x5555);
    assert(g_332e60_called == 1);

    // 6. Test func_00151290
    assert(func_00151290() == 0);

    // 7. Test func_00150F50
    RouteEntry entries[2];
    entries[0].m_type = 506;
    entries[0].m_target_id = 610;
    action.m_field40 = entries;
    action.m_field32 = 1;
    action.m_field34 = 1;
    action.m_field35 = 1;
    action.m_field44 = -1;
    action.m_field48 = 610;

    func_00150F50(&action, 100);
    assert(g_bce0_called == 1);
    assert(g_method5c_called == 1);
    assert(action.m_field138 == 100);
    assert(action.m_field32 == 0);

    printf("trade_action_target_resolver_test passed\n");
    return 0;
}
