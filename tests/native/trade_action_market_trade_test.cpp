#include <cassert>
#include <cstdio>
#include <cstring>

#define func_332e60 mock_func_332e60
#define func_001471B0 mock_func_001471B0
#define func_0014BD20 mock_func_0014BD20

static int g_action_id = 0;
static int g_bd20_called = 0;
static int g_bd20_id = 0;

extern "C" {
void *mock_func_332e60(void *mgr, int id) {
    static char dummy_entity[0x100];
    if (id == 999) return NULL;
    return dummy_entity;
}

void mock_func_001471B0(void *self, short actionId) {
    g_action_id = actionId;
}

void mock_func_0014BD20(void *self, int id, float f12, float f13, float f14) {
    g_bd20_called++;
    g_bd20_id = id;
}
}

#include "../../src/trade/trade_action_market_trade.cpp"

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
float MarketObj::Method124() { return 1.0f; }
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
int MarketObj::Method16C(int a1, int a2) { return 1; }
void MarketObj::vfn90() {}
void MarketObj::vfn91() {}
void MarketObj::vfn92() {}
void MarketObj::vfn93() {}
void MarketObj::vfn94() {}
void MarketObj::vfn95() {}
void MarketObj::vfn96() {}
void MarketObj::vfn97() {}
void MarketObj::vfn98() {}
void MarketObj::vfn99() {}
void MarketObj::vfn100() {}
void MarketObj::vfn101() {}
void MarketObj::vfn102() {}
void MarketObj::vfn103() {}
void MarketObj::vfn104() {}
void MarketObj::vfn105() {}
void MarketObj::vfn106() {}
void MarketObj::vfn107() {}
int MarketObj::Method1B8(int a1, int a2, int a3, float f12, int t0, int t1) { return 1; }

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
int TradeActionBase::Method54(void *entity) { return 1; }

int main() {
    TradeActionBase action;
    MarketObj market;
    MarketPlayerMgr mgr;
    std::memset(&mgr, 0, sizeof(mgr));
    market.m_game = &mgr;
    action.m_target = &market;
    action.m_field4A = 5;
    action.m_actionId = -1;

    // Target equal to m_field4A -> returns 0
    int res = func_0014CFF0(&action, 5);
    assert(res == 0);

    // Target not equal -> executes
    res = func_0014CFF0(&action, 10);
    assert(res == 1);
    assert(g_action_id == 0x258);
    assert(g_bd20_called == 1);
    assert(g_bd20_id == 10);

    // Test func_0014D160
    res = func_0014D160(&action, 20, 1);
    assert(res == 1);
    assert(g_bd20_called == 2);
    assert(g_bd20_id == 20);

    std::printf("trade_action_market_trade_test passed\n");
    return 0;
}
