#include <cassert>
#include <cstdio>
#include <cstring>

#define func_00332DA0 mock_func_00332DA0
#define func_202B10 mock_func_202B10
#define func_001510D0 mock_func_001510D0

static int g_s0_val = 0;
static int g_valid_val = 0;

extern "C" {
int mock_func_00332DA0(void *obj) {
    return g_s0_val;
}

int mock_func_202B10(void *obj) {
    return g_valid_val;
}

void *mock_func_001510D0(void *self, int id) {
    return NULL;
}
}

#include "../../src/trade/trade_action_market_items.cpp"

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
float MarketObj::Method88(short a1, int a2, int a3, float f12, void *t0) { return 10.0f; }
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
float MarketObj::Method108(void *item) { return 1.0f; }

void TradeActionBase::vfn0() {}
void TradeActionBase::vfn1() {}
void TradeActionBase::vfn2() {}
void TradeActionBase::vfn3() {}
void TradeActionBase::vfn4() {}
void TradeActionBase::vfn5() {}
void TradeActionBase::vfn6() {}
void TradeActionBase::vfn7() {}
void TradeActionBase::vfn8() {}
void TradeActionBase::Method2C(int a1, float f12, float f13) {}

int main() {
    TradeActionBase action;
    MarketObj market;
    MarketData8 d8;
    MarketData4 d4;
    std::memset(&d8, 0, sizeof(d8));
    std::memset(&d4, 0, sizeof(d4));
    d4.m_val1C = 100.0f;

    market.m_field8 = &d8;
    *(MarketData4 **)((char *)&market + 4) = &d4;
    action.m_market = &market;

    // Case 1: valid = 0 -> returns 2.0 * val1C = 200.0f
    g_valid_val = 0;
    g_s0_val = 5;
    float res = func_001499F0(&action);
    assert(res == 200.0f);

    // Case 2: valid = 1, s0 = 2 (< 3) -> 200.0f
    g_valid_val = 1;
    g_s0_val = 2;
    res = func_001499F0(&action);
    assert(res == 200.0f);

    // Case 3: valid = 1, s0 = 3 -> rate 75 -> 75.0f
    g_valid_val = 1;
    g_s0_val = 3;
    res = func_001499F0(&action);
    assert(res == 75.0f);

    // Case 4: valid = 1, s0 = 4 -> rate 50 -> 50.0f
    g_valid_val = 1;
    g_s0_val = 4;
    res = func_001499F0(&action);
    assert(res == 50.0f);

    // Case 5: valid = 1, s0 = 5 -> rate 100 -> 100.0f
    g_valid_val = 1;
    g_s0_val = 5;
    res = func_001499F0(&action);
    assert(res == 100.0f);

    // Case 6: min bound 1.0f
    d4.m_val1C = 0.5f;
    g_s0_val = 4; // rate 50 -> 0.25f < 1.0f -> 1.0f
    res = func_001499F0(&action);
    assert(res == 1.0f);

    std::printf("trade_action_market_items_test passed\n");
    return 0;
}
