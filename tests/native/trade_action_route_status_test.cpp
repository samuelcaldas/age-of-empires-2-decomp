#include <cassert>
#include <cstdio>
#include <cstring>

#define func_332e60 mock_func_332e60
#define func_001471B0 mock_func_001471B0
#define func_0014BD20 mock_func_0014BD20
#define func_2690D0 mock_func_2690D0

static int g_action_id = 0;
static int g_bd20_called = 0;
static short g_bd20_id = 0;
static float g_dist_returned = 5.0f;

extern "C" {
void *mock_func_332e60(void *mgr, short id) {
    static char dummy_entity[0x100];
    if (id == 999) return NULL;
    return dummy_entity;
}

void mock_func_001471B0(void *self, short actionId) {
    g_action_id = actionId;
}

void mock_func_0014BD20(void *self, short id, float f12, float f13, float f14) {
    g_bd20_called++;
    g_bd20_id = id;
}

float mock_func_2690D0(void *obj, void *target) {
    return g_dist_returned;
}
}

#include "../../src/trade/trade_action_route_status.cpp"

void MarketObj::vfn0() {}
void MarketObj::vfn1() {}
void MarketObj::vfn2() {}
void MarketObj::vfn3() {}
void MarketObj::vfn4() {}
void MarketObj::vfn5() {}
void MarketObj::vfn6() {}
void MarketObj::vfn7() {}
void MarketObj::vfn8() {}
void MarketObj::vfn9() {}
void MarketObj::vfn10() {}
void MarketObj::vfn11() {}
void MarketObj::vfn12() {}
void MarketObj::vfn13() {}
void MarketObj::vfn14() {}
void MarketObj::vfn15() {}
void MarketObj::vfn16() {}
void MarketObj::vfn17() {}
void MarketObj::vfn18() {}
void MarketObj::vfn19() {}
void MarketObj::vfn20() {}
void MarketObj::vfn21() {}
void MarketObj::vfn22() {}
void MarketObj::vfn23() {}
void MarketObj::vfn24() {}
void MarketObj::vfn25() {}
void MarketObj::vfn26() {}
void MarketObj::vfn27() {}
void MarketObj::vfn28() {}
void MarketObj::vfn29() {}
void MarketObj::vfn30() {}
void MarketObj::vfn31() {}
void MarketObj::vfn32() {}
void MarketObj::vfn33() {}
void MarketObj::vfn34() {}
void MarketObj::vfn35() {}
void MarketObj::vfn36() {}
void MarketObj::vfn37() {}
void MarketObj::vfn38() {}
void MarketObj::vfn39() {}
void MarketObj::vfn40() {}
void MarketObj::vfn41() {}
void MarketObj::vfn42() {}
void MarketObj::vfn43() {}
void MarketObj::vfn44() {}
void MarketObj::vfn45() {}
void MarketObj::vfn46() {}
void MarketObj::vfn47() {}
void MarketObj::vfn48() {}
void MarketObj::vfn49() {}
void MarketObj::vfn50() {}
void MarketObj::vfn51() {}
void MarketObj::vfn52() {}
void MarketObj::vfn53() {}
void MarketObj::vfn54() {}
void MarketObj::vfn55() {}
void MarketObj::vfn56() {}
void MarketObj::vfn57() {}
void MarketObj::vfn58() {}
void MarketObj::vfn59() {}
void MarketObj::vfn60() {}
void MarketObj::vfn61() {}
void MarketObj::vfn62() {}
void MarketObj::vfn63() {}
void MarketObj::vfn64() {}
void MarketObj::vfn65() {}
void MarketObj::vfn66() {}
void MarketObj::vfn67() {}
void MarketObj::vfn68() {}
void MarketObj::vfn69() {}
void MarketObj::vfn70() {}
void MarketObj::vfn71() {}
void MarketObj::vfn72() {}
void MarketObj::vfn73() {}
void MarketObj::vfn74() {}
void MarketObj::vfn75() {}
void MarketObj::vfn76() {}
void MarketObj::vfn77() {}
void MarketObj::vfn78() {}
void MarketObj::vfn79() {}
void MarketObj::vfn80() {}
void MarketObj::vfn81() {}
void MarketObj::vfn82() {}
void MarketObj::vfn83() {}
void MarketObj::vfn84() {}
void MarketObj::vfn85() {}
void MarketObj::vfn86() {}
void MarketObj::vfn87() {}
void MarketObj::vfn88() {}
int MarketObj::Method16C(short a1, int a2) { return 1; }

void TradeActionBase::vfn0() {}
void TradeActionBase::vfn1() {}
void TradeActionBase::vfn2() {}
void TradeActionBase::vfn3() {}
void TradeActionBase::vfn4() {}
void TradeActionBase::vfn5() {}
void TradeActionBase::vfn6() {}
void TradeActionBase::vfn7() {}
void TradeActionBase::vfn8() {}
void TradeActionBase::vfn9() {}
void TradeActionBase::vfn10() {}
void TradeActionBase::vfn11() {}
void TradeActionBase::vfn12() {}
void TradeActionBase::vfn13() {}
void TradeActionBase::vfn14() {}
void TradeActionBase::vfn15() {}
void TradeActionBase::vfn16() {}
void TradeActionBase::vfn17() {}
void TradeActionBase::vfn18() {}
void TradeActionBase::vfn19() {}
void TradeActionBase::vfn20() {}
void TradeActionBase::vfn21() {}
void TradeActionBase::vfn22() {}
void TradeActionBase::vfn23() {}
void TradeActionBase::vfn24() {}
void TradeActionBase::vfn25() {}
void TradeActionBase::vfn26() {}
void TradeActionBase::vfn27() {}
void TradeActionBase::vfn28() {}
void TradeActionBase::vfn29() {}
void TradeActionBase::vfn30() {}
void TradeActionBase::vfn31() {}
void TradeActionBase::vfn32() {}
void TradeActionBase::vfn33() {}
void TradeActionBase::vfn34() {}
void TradeActionBase::vfn35() {}
static int g_method98_called = 0;
void TradeActionBase::Method98(short a1, int a2) {
    g_method98_called++;
}

int main() {
    TradeActionBase action;
    MarketObj market;
    MarketPlayerMgr mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    market.m_field8 = &mgr;
    market.m_posZ = 10.0f;
    action.m_market = &market;
    action.m_actionId = -1;
    action.m_field4A = 12;

    // Test func_0014B8F0
    g_dist_returned = 15.0f;
    int res = func_0014B8F0(&action, 5, 0, 10.0f);
    assert(res == 1);
    assert(g_action_id == 0x264);
    assert(g_bd20_called == 1);
    assert(g_bd20_id == 5);
    assert(g_method98_called == 1); // dist (15) > bound (10)

    // Test func_0014B9E0
    res = func_0014B9E0(&action, 7, 1, 8.0f);
    assert(res == 1);
    assert(g_action_id == 0x259);
    assert(action.m_field4E == 7);
    assert(action.m_field5C == 8.0f);

    // Test func_0014BAA0
    res = func_0014BAA0(&action, 1, 1.0f, 2.0f, 3.0f);
    assert(res == 1);
    assert(action.m_field4E == -1);
    assert(action.m_field5C == 3.0f);

    // Test func_0014BB40
    res = func_0014BB40(&action, 3, 10, 20, 1);
    assert(res == 1);
    assert(g_action_id == 0x26E);

    std::printf("trade_action_route_status_test passed\n");
    return 0;
}
