#include <cassert>
#include <cstdio>
#include <cstring>

#define func_0014BCE0 mock_func_0014BCE0
#define func_001471B0 mock_func_001471B0
#define func_123350 mock_func_123350

static int g_bce0_called = 0;
static int g_71b0_called = 0;
static int g_71b0_val = 0;
static int g_m5c_called = 0;
static int g_m60_called = 0;
static int g_m64_called = 0;

extern "C" {
void mock_func_0014BCE0(void *self) { g_bce0_called++; }
void mock_func_001471B0(void *self, int a1) { g_71b0_called++; g_71b0_val = a1; }
int mock_func_123350(float val) { return (int)val; }
}

#include "../../src/trade/trade_action_trade_eval.cpp"

void TargetObj::vfn0() {}

int TradeAction::v0() { return 0; } int TradeAction::v1() { return 0; } int TradeAction::v2() { return 0; } int TradeAction::v3() { return 0; }
int TradeAction::v4() { return 0; } int TradeAction::v5() { return 0; } int TradeAction::v6() { return 0; } int TradeAction::v7() { return 0; }
int TradeAction::v8() { return 0; } int TradeAction::v9() { return 0; } int TradeAction::v10() { return 0; } int TradeAction::v11() { return 0; }
int TradeAction::v12() { return 0; } int TradeAction::v13() { return 0; } int TradeAction::v14() { return 0; } int TradeAction::v15() { return 0; }
int TradeAction::v16() { return 0; } int TradeAction::v17() { return 0; } int TradeAction::v18() { return 0; } int TradeAction::v19() { return 0; }
int TradeAction::v20() { return 0; }
int TradeAction::Method5C(int a1) { g_m5c_called++; return 1; }
int TradeAction::Method60(int a1, int a2) { g_m60_called++; return 1; }
int TradeAction::Method64(int a1) { g_m64_called++; return 1; }
int TradeAction::Method68(int a1, int a2) { return 1; }
int TradeAction::Method6C(int a1, int a2) { return 1; }
int TradeAction::Method70(int a1, int a2) { return 1; }
int TradeAction::Method74(int a1, int a2) { return 1; }
int TradeAction::Method78(int a1, int a2) { return 1; }
int TradeAction::Method7C(int a1, int a2) { return 1; }
int TradeAction::v30() { return 0; }
int TradeAction::Method84(int a1, int a2, int a3) { return 1; }
int TradeAction::Method88(int a1, int a2) { return 1; }
int TradeAction::Method8C(float f12, float f13, int a1) { return 1; }
int TradeAction::Method90(int a1, float f12, float f13, float f14) { return 1; }
int TradeAction::v35() { return 0; } int TradeAction::v36() { return 0; }
int TradeAction::Method9C(int a1, float f12, float f13, float f14, float f15, int a2) { return 1; }
int TradeAction::v38() { return 0; } int TradeAction::v39() { return 0; }
int TradeAction::MethodA8(int a1, int a2) { return 1; }
int TradeAction::MethodAC(int a1, int a2, float f12) { return 1; }
int TradeAction::MethodB0(int a1, int a2, float f12) { return 1; }
int TradeAction::MethodB4(float f12, float f13, float f14, int a1) { return 1; }
int TradeAction::MethodB8(int a1, int a2, int a3, int t0) { return 1; }
int TradeAction::MethodBC(int a1, int a2, int a3) { return 1; }

int main() {
    TradeAction action;
    TargetObj target;
    char targetNode[0x20] = {0};
    target.m_node = targetNode;
    action.m_target = &target;

    ActionEntry entries[4];
    memset(entries, 0, sizeof(entries));
    entries[0].m_type = 706;
    entries[0].m_field4 = 55;
    entries[1].m_type = 700;
    entries[1].m_field4 = 66;

    action.m_entries = entries;
    action.m_entry_count = 2;

    int ret = func_0014CAB0(&action, &entries[0], 0);
    assert(ret == 1);
    assert(g_bce0_called == 1);
    assert(g_m5c_called == 1);
    assert(action.m_field44 == -1);
    assert(action.m_field46 == -1);
    assert(action.m_entry_count == 1);
    assert(action.m_entries[0].m_type == 700);

    ret = func_0014CAB0(&action, &entries[0], 0);
    assert(ret == 1);
    assert(g_m60_called == 1);
    assert(action.m_field44 == 700);
    assert(action.m_field46 == 66);
    assert(action.m_entry_count == 0);

    printf("trade_action_trade_eval_test passed\n");
    return 0;
}
