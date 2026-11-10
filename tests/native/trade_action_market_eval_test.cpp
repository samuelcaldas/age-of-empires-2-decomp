#include <cassert>
#include <cstdio>
#include <cstring>

extern "C" {
float D_004E2808 = 1.0e30f;
float D_004E2824 = 1.0e-7f;

short func_001471C0(void *obj) {
    return 10;
}
}

#include "../../src/trade/trade_action_market_eval.cpp"

#define V_STUB_T(n) void TargetObj::vfn##n() {}
V_STUB_T(0) V_STUB_T(1) V_STUB_T(2) V_STUB_T(3) V_STUB_T(4) V_STUB_T(5) V_STUB_T(6) V_STUB_T(7) V_STUB_T(8) V_STUB_T(9)
V_STUB_T(10) V_STUB_T(11) V_STUB_T(12) V_STUB_T(13) V_STUB_T(14) V_STUB_T(15) V_STUB_T(16) V_STUB_T(17) V_STUB_T(18) V_STUB_T(19)
V_STUB_T(20) V_STUB_T(21) V_STUB_T(22) V_STUB_T(23) V_STUB_T(24) V_STUB_T(25) V_STUB_T(26) V_STUB_T(27) V_STUB_T(28) V_STUB_T(29)
V_STUB_T(30) V_STUB_T(31) V_STUB_T(32) V_STUB_T(33) V_STUB_T(34) V_STUB_T(35) V_STUB_T(36) V_STUB_T(37) V_STUB_T(38) V_STUB_T(39)
V_STUB_T(40) V_STUB_T(41) V_STUB_T(42) V_STUB_T(43) V_STUB_T(44) V_STUB_T(45) V_STUB_T(46) V_STUB_T(47) V_STUB_T(48) V_STUB_T(49)
V_STUB_T(50) V_STUB_T(51) V_STUB_T(52) V_STUB_T(53) V_STUB_T(54) V_STUB_T(55) V_STUB_T(56) V_STUB_T(57) V_STUB_T(58) V_STUB_T(59)
V_STUB_T(60) V_STUB_T(61) V_STUB_T(62) V_STUB_T(63) V_STUB_T(64) V_STUB_T(65) V_STUB_T(66) V_STUB_T(67) V_STUB_T(68)
float TargetObj::Method114() { return 1.0f; }
float TargetObj::Method118() { return 2.0f; }
float TargetObj::Method11C() { return 1.0f; }
float TargetObj::Method120(TargetObj *other) { return 5.0f; }
float TargetObj::Method124() { return 100.0f; }
V_STUB_T(74) V_STUB_T(75) V_STUB_T(76) V_STUB_T(77) V_STUB_T(78) V_STUB_T(79)
V_STUB_T(80) V_STUB_T(81) V_STUB_T(82) V_STUB_T(83) V_STUB_T(84) V_STUB_T(85) V_STUB_T(86) V_STUB_T(87) V_STUB_T(88)
void* TargetObj::Method164() { return this; }

int main() {
    TradeAction action;
    memset(&action, 0, sizeof(action));
    action.m_minDistance = 9999.0f;
    action.m_minCost = 9999.0f;
    action.m_minMarketDist = 9999.0f;
    action.m_minMarketCost = 9999.0f;
    action.m_field74 = 9999.0f;

    TargetObj s2;
    TargetObj s1;
    s2.m_field24 = 10;
    s1.m_field24 = 20;
    s1.m_field30 = 50.0f;

    // Test with valid targets
    func_00148FF0(&action, &s2, &s1, 0, 10.0f);

    assert(action.m_count == 1);
    assert(action.m_minDistance == 10.0f);
    assert(action.m_maxDistance == 10.0f);
    assert(action.m_field21 == 1); // Method114() > 0
    assert(action.m_field22 == 1); // Method11C() > 0
    assert(action.m_field23 == 1); // 10.0 <= 100.0

    // Test with null target (should return immediately)
    func_00148FF0(&action, NULL, &s1, 0, 10.0f);
    assert(action.m_count == 1);

    printf("trade_action_market_eval_test passed\n");
    return 0;
}
