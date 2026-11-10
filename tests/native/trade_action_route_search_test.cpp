#include <cassert>
#include <cstdio>
#include <cstring>

#include "trade_action_route_search.h"

#define func_332e60 mock_func_332e60
#define D_00F99910 mock_D_00F99910
#define D_00F99930 mock_D_00F99930

static int g_method2c_called = 0;
static int g_method58_called = 0;

extern "C" {
SearchItem *mock_D_00F99910[5];
int mock_D_00F99930[5];
}

void TargetObj::vfn0() {}

int TradeAction::v0() { return 0; } int TradeAction::v1() { return 0; } int TradeAction::v2() { return 0; } int TradeAction::v3() { return 0; }
int TradeAction::v4() { return 0; } int TradeAction::v5() { return 0; } int TradeAction::v6() { return 0; } int TradeAction::v7() { return 0; }
int TradeAction::v8() { return 0; }
int TradeAction::Method2C(int a1, float x, float y) {
    g_method2c_called++;
    return 1;
}
int TradeAction::v10() { return 0; } int TradeAction::v11() { return 0; } int TradeAction::v12() { return 0; } int TradeAction::v13() { return 0; }
int TradeAction::v14() { return 0; } int TradeAction::v15() { return 0; } int TradeAction::v16() { return 0; } int TradeAction::v17() { return 0; }
int TradeAction::v18() { return 0; } int TradeAction::v19() { return 0; }
int TradeAction::Method58(short id) {
    g_method58_called++;
    return 1;
}

static char dummyTarget[0x100];
static TimerNode dummyNode;

extern "C" {
void *mock_func_332e60(void *timer, int id) {
    TargetObj *t = (TargetObj *)dummyTarget;
    t->m_field39 = 0;
    dummyNode.m_id = 10;
    t->m_node = &dummyNode;
    return t;
}
}

#include "../../src/trade/trade_action_route_search.cpp"

int main() {
    TradeAction action;
    TargetObj target;
    memset(&target, 0, sizeof(target));
    char gameBuf[4000];
    char timerBuf[100];
    *(void **)(gameBuf + 2968) = timerBuf;
    target.m_game = gameBuf;
    action.m_target = &target;

    SearchItem items[2];
    items[0].id = 101;
    items[0].field_4 = 0;
    items[1].id = 102;
    items[1].field_4 = 0;
    mock_D_00F99910[0] = items;
    mock_D_00F99930[0] = 2;

    int results[10] = {0};
    int count = 0;

    func_0014C110(&action, 0, results, &count, 10);
    assert(g_method2c_called == 1);
    assert(count == 2);
    assert(results[0] == 101);
    assert(results[1] == 102);

    RouteItem ritems[2];
    ritems[0].m_id = 55;
    ritems[1].m_id = 77;
    action.m_items = ritems;
    action.m_item_count = 2;

    assert(func_0014C420(&action, 55) == 1);
    assert(func_0014C420(&action, 99) == 0);

    printf("trade_action_route_search_test passed\n");
    return 0;
}
