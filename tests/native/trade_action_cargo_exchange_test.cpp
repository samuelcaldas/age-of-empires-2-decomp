#include <cassert>
#include <cstdio>
#include <cstring>

class TargetObj;
struct TradeAction;

#define func_123350 mock_func_123350
#define func_269190 mock_func_269190
#define func_001471B0 mock_func_001471B0
#define func_0014BD20 mock_func_0014BD20

static int g_71b0_called = 0;
static int g_bd20_called = 0;
static int g_1b4_called = 0;
static int g_17c_called = 0;

extern "C" {
int mock_func_123350(float val) { return (int)val; }
float mock_func_269190(TargetObj *t, float x, float y, float z) { return 10.0f; }
short mock_func_001471B0(TradeAction *self, short cmd) { g_71b0_called++; return 0; }
int mock_func_0014BD20(TradeAction *self, int a1, float x, float y, float z) { g_bd20_called++; return 0; }
}

#include "../../src/trade/trade_action_cargo_exchange.cpp"

#define V_STUB(n) void TargetObj::vfn##n() {}
V_STUB(0) V_STUB(1) V_STUB(2) V_STUB(3) V_STUB(4) V_STUB(5) V_STUB(6) V_STUB(7) V_STUB(8) V_STUB(9)
V_STUB(10) V_STUB(11) V_STUB(12) V_STUB(13) V_STUB(14) V_STUB(15) V_STUB(16) V_STUB(17) V_STUB(18) V_STUB(19)
V_STUB(20) V_STUB(21) V_STUB(22) V_STUB(23) V_STUB(24) V_STUB(25) V_STUB(26) V_STUB(27) V_STUB(28) V_STUB(29)
V_STUB(30) V_STUB(31) V_STUB(32) V_STUB(33) V_STUB(34) V_STUB(35) V_STUB(36) V_STUB(37) V_STUB(38) V_STUB(39)
V_STUB(40) V_STUB(41) V_STUB(42) V_STUB(43) V_STUB(44) V_STUB(45) V_STUB(46) V_STUB(47) V_STUB(48) V_STUB(49)
V_STUB(50) V_STUB(51) V_STUB(52) V_STUB(53) V_STUB(54) V_STUB(55) V_STUB(56) V_STUB(57) V_STUB(58) V_STUB(59)
V_STUB(60) V_STUB(61) V_STUB(62) V_STUB(63) V_STUB(64) V_STUB(65) V_STUB(66) V_STUB(67) V_STUB(68) V_STUB(69)
V_STUB(70) V_STUB(71) V_STUB(72) V_STUB(73) V_STUB(74) V_STUB(75) V_STUB(76) V_STUB(77) V_STUB(78) V_STUB(79)
V_STUB(80) V_STUB(81) V_STUB(82) V_STUB(83) V_STUB(84) V_STUB(85) V_STUB(86) V_STUB(87) V_STUB(88) V_STUB(89)
V_STUB(90) V_STUB(91) V_STUB(92) V_STUB(94) V_STUB(95) V_STUB(96) V_STUB(97) V_STUB(98) V_STUB(99)
V_STUB(100) V_STUB(101) V_STUB(102) V_STUB(103) V_STUB(104) V_STUB(105) V_STUB(106)

int TargetObj::Method17C(float x, float y, int a3, int a4, float z, float f4) {
    g_17c_called++;
    return 1;
}

int TargetObj::Method1B4(int *pos, int a2, int a3, int a4, int a5, int a6) {
    g_1b4_called++;
    return 1;
}

int main() {
    TradeAction action;
    TargetObj target;
    memset(&action, 0, sizeof(action));

    char worldBuf[4000];
    char mgrBuf[100];
    char mapBuf[100];
    *(int *)(mapBuf + 8) = 100; // map_w
    *(int *)(mapBuf + 12) = 100; // map_h
    *(void **)(mgrBuf + 60) = mapBuf;
    *(void **)(worldBuf + 2968) = mgrBuf;

    target.m_world = worldBuf;
    action.m_target = &target;
    action.m_field48 = -1;

    int ret = func_0014B300(&action);
    assert(ret == 0);

    ret = func_0014AEF0(&action, 0, 0, 10.0f, 20.0f, 0.0f);
    assert(ret == 1);
    assert(g_1b4_called >= 1);
    assert(g_17c_called == 1);
    assert(g_71b0_called == 1);
    assert(g_bd20_called == 1);

    printf("trade_action_cargo_exchange_test passed\n");
    return 0;
}
