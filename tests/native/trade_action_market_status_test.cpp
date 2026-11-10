#include <cassert>
#include <cstdio>
#include <cstring>

#define func_00148050 mock_func_00148050

static int g_148050_called = 0;
static int g_method118_called = 0;
static int g_method28_called = 0;
static int g_method2c_called = 0;
static int g_method60_called = 0;
static int g_methode8_called = 0;
static int g_method220_called = 0;
static int g_methode8_return = 0;
static int g_method60_return = 0;
static int g_148050_return = 10;

extern "C" {
int mock_func_00148050(void *self, void *pos, int a2, int a3, int t0, int t1, int t2, int t3) {
    g_148050_called++;
    return g_148050_return;
}
}

#include "../../src/trade/trade_action_market_status.cpp"

#define V_STUB_M(n) void ActionMgr::vfn##n() {}
V_STUB_M(0) V_STUB_M(1) V_STUB_M(2) V_STUB_M(3) V_STUB_M(4) V_STUB_M(5) V_STUB_M(6) V_STUB_M(7) V_STUB_M(8) V_STUB_M(9)
V_STUB_M(10) V_STUB_M(11) V_STUB_M(12) V_STUB_M(13) V_STUB_M(14) V_STUB_M(15) V_STUB_M(16) V_STUB_M(17) V_STUB_M(18) V_STUB_M(19)
V_STUB_M(20) V_STUB_M(21) V_STUB_M(22) V_STUB_M(23) V_STUB_M(24) V_STUB_M(25) V_STUB_M(26) V_STUB_M(27) V_STUB_M(28) V_STUB_M(29)
V_STUB_M(30) V_STUB_M(31) V_STUB_M(32) V_STUB_M(33) V_STUB_M(34) V_STUB_M(35) V_STUB_M(36) V_STUB_M(37) V_STUB_M(38) V_STUB_M(39)
V_STUB_M(40) V_STUB_M(41) V_STUB_M(42) V_STUB_M(43) V_STUB_M(44) V_STUB_M(45) V_STUB_M(46) V_STUB_M(47) V_STUB_M(48) V_STUB_M(49)
V_STUB_M(50) V_STUB_M(51) V_STUB_M(52) V_STUB_M(53) V_STUB_M(54) V_STUB_M(55) V_STUB_M(56) V_STUB_M(57) V_STUB_M(58) V_STUB_M(59)
V_STUB_M(60) V_STUB_M(61) V_STUB_M(62) V_STUB_M(63) V_STUB_M(64) V_STUB_M(65) V_STUB_M(66) V_STUB_M(67)
void ActionMgr::Method118(short a1, short a2, short a3) {
    g_method118_called++;
}

#define V_STUB_T(n) void TargetObj::vfn##n() {}
V_STUB_T(0) V_STUB_T(1) V_STUB_T(2) V_STUB_T(3) V_STUB_T(4) V_STUB_T(5) V_STUB_T(6) V_STUB_T(7) V_STUB_T(8) V_STUB_T(9)
V_STUB_T(10) V_STUB_T(11) V_STUB_T(12) V_STUB_T(13) V_STUB_T(14) V_STUB_T(15) V_STUB_T(16) V_STUB_T(17) V_STUB_T(18) V_STUB_T(19)
V_STUB_T(20) V_STUB_T(21) V_STUB_T(22) V_STUB_T(23) V_STUB_T(24) V_STUB_T(25) V_STUB_T(26) V_STUB_T(27) V_STUB_T(28) V_STUB_T(29)
V_STUB_T(30) V_STUB_T(31) V_STUB_T(32) V_STUB_T(33) V_STUB_T(34) V_STUB_T(35) V_STUB_T(36) V_STUB_T(37) V_STUB_T(38) V_STUB_T(39)
V_STUB_T(40) V_STUB_T(41) V_STUB_T(42) V_STUB_T(43) V_STUB_T(44) V_STUB_T(45) V_STUB_T(46) V_STUB_T(47) V_STUB_T(48) V_STUB_T(49)
V_STUB_T(50) V_STUB_T(51) V_STUB_T(52) V_STUB_T(53) V_STUB_T(54) V_STUB_T(55) V_STUB_T(56) V_STUB_T(57) V_STUB_T(58) V_STUB_T(59)
V_STUB_T(60) V_STUB_T(61) V_STUB_T(62) V_STUB_T(63) V_STUB_T(64) V_STUB_T(65) V_STUB_T(66) V_STUB_T(67) V_STUB_T(68) V_STUB_T(69)
V_STUB_T(70) V_STUB_T(71) V_STUB_T(72) V_STUB_T(73) V_STUB_T(74) V_STUB_T(75) V_STUB_T(76) V_STUB_T(77) V_STUB_T(78) V_STUB_T(79)
V_STUB_T(80) V_STUB_T(81) V_STUB_T(82) V_STUB_T(83) V_STUB_T(84) V_STUB_T(85) V_STUB_T(86) V_STUB_T(87) V_STUB_T(88) V_STUB_T(89)
V_STUB_T(90) V_STUB_T(91) V_STUB_T(92) V_STUB_T(93) V_STUB_T(94) V_STUB_T(95) V_STUB_T(96) V_STUB_T(97) V_STUB_T(98) V_STUB_T(99)
V_STUB_T(100) V_STUB_T(101) V_STUB_T(102) V_STUB_T(103) V_STUB_T(104) V_STUB_T(105) V_STUB_T(106) V_STUB_T(107) V_STUB_T(108) V_STUB_T(109)
V_STUB_T(110) V_STUB_T(111) V_STUB_T(112) V_STUB_T(113) V_STUB_T(114) V_STUB_T(115) V_STUB_T(116) V_STUB_T(117) V_STUB_T(118) V_STUB_T(119)
V_STUB_T(120) V_STUB_T(121) V_STUB_T(122) V_STUB_T(123) V_STUB_T(124) V_STUB_T(125) V_STUB_T(126) V_STUB_T(127) V_STUB_T(128) V_STUB_T(129)
V_STUB_T(130) V_STUB_T(131) V_STUB_T(132) V_STUB_T(133) V_STUB_T(134)
void TargetObj::Method220(void *pos) {
    g_method220_called++;
}

#define V_STUB_B(n) void TradeActionBase::vfn##n() {}
V_STUB_B(0) V_STUB_B(1) V_STUB_B(2) V_STUB_B(3) V_STUB_B(4) V_STUB_B(5) V_STUB_B(6) V_STUB_B(7)
void TradeActionBase::Method28(short a1, short a2, short a3, int t0, int t1, int t2) {
    g_method28_called++;
}
void TradeActionBase::Method2C(int a1, float f12, float f13) {
    g_method2c_called++;
}
V_STUB_B(10) V_STUB_B(11) V_STUB_B(12) V_STUB_B(13) V_STUB_B(14) V_STUB_B(15) V_STUB_B(16) V_STUB_B(17) V_STUB_B(18) V_STUB_B(19)
V_STUB_B(20) V_STUB_B(21)
int TradeActionBase::Method60(int a1, int a2) {
    g_method60_called++;
    return g_method60_return;
}
V_STUB_B(23) V_STUB_B(24) V_STUB_B(25) V_STUB_B(26) V_STUB_B(27) V_STUB_B(28) V_STUB_B(29)
V_STUB_B(30) V_STUB_B(31) V_STUB_B(32) V_STUB_B(33) V_STUB_B(34) V_STUB_B(35) V_STUB_B(36) V_STUB_B(37) V_STUB_B(38) V_STUB_B(39)
V_STUB_B(40) V_STUB_B(41) V_STUB_B(42) V_STUB_B(43) V_STUB_B(44) V_STUB_B(45) V_STUB_B(46) V_STUB_B(47) V_STUB_B(48) V_STUB_B(49)
V_STUB_B(50) V_STUB_B(51) V_STUB_B(52) V_STUB_B(53) V_STUB_B(54) V_STUB_B(55)
int TradeActionBase::MethodE8() {
    g_methode8_called++;
    return g_methode8_return;
}

int main() {
    TradeActionBase action;
    TargetObj target;
    ActionMgr mgr;
    char game_buf[8000];
    memset(game_buf, 0, sizeof(game_buf));
    *(void**)(game_buf + 0x1B30) = &mgr;

    target.m_game = game_buf;
    target.m_posX = 15.0f;
    target.m_posY = 25.0f;
    action.m_target = &target;
    action.m_state = 0;

    // 1. Test func_0014F640
    OrderData order;
    order.a1 = 1; order.a2 = 2; order.a3 = 3;
    order.t0 = 4; order.t1 = 5; order.t2 = 6;
    func_0014F640(&action, &order);
    assert(g_method28_called == 1);

    // 2. Test func_0014F670
    int ret = func_0014F670(&action, 10, 20, 30);
    assert(ret == 1);
    assert(g_method118_called == 1);

    // 3. Test func_0014F6C0: a1 == 1, MethodE8() == 8 -> returns 6
    g_methode8_return = 8;
    ret = func_0014F6C0(&action, 1);
    assert(ret == 6);
    assert(g_methode8_called == 1);

    // 4. Test func_0014F6C0: m_state == 3 -> calls Method2C, returns 5
    g_methode8_return = 0;
    action.m_state = 3;
    ret = func_0014F6C0(&action, 0);
    assert(ret == 5);
    assert(g_method2c_called == 1);

    // 5. Test func_0014F6C0: normal path, func_00148050 returns 10, Method60 returns 1 -> returns 6
    action.m_state = 0;
    g_148050_return = 10;
    g_method60_return = 1;
    ret = func_0014F6C0(&action, 0);
    assert(ret == 6);
    assert(g_148050_called == 1);
    assert(g_method60_called == 1);
    assert(g_method220_called == 1);

    // 6. Test func_0014F6C0: func_00148050 returns -1 -> returns 5
    g_148050_return = -1;
    ret = func_0014F6C0(&action, 0);
    assert(ret == 5);

    printf("trade_action_market_status_test passed\n");
    return 0;
}
