#include <cassert>
#include <cstdio>
#include <cstring>

#define func_332e60 mock_func_332e60
#define func_123350 mock_func_123350
#define D_F99910 mock_D_F99910
#define D_F99930 mock_D_F99930
#define D_004E3064 mock_D_004E3064

static int g_method2c_called = 0;
static int g_method1b8_called = 0;

extern "C" {
int *mock_D_F99910[5];
int mock_D_F99930[5];
int mock_D_004E3064 = 0;

int mock_func_123350(float val) { return (int)val; }
}

#include "../../src/trade/trade_action_market_select.cpp"

#define DEF_VSLOT_10(cls, base) \
    int cls::v##base##0() { return 0; } int cls::v##base##1() { return 0; } int cls::v##base##2() { return 0; } int cls::v##base##3() { return 0; } int cls::v##base##4() { return 0; } \
    int cls::v##base##5() { return 0; } int cls::v##base##6() { return 0; } int cls::v##base##7() { return 0; } int cls::v##base##8() { return 0; } int cls::v##base##9() { return 0; }

DEF_VSLOT_10(TargetObj, 0)
DEF_VSLOT_10(TargetObj, 1)
DEF_VSLOT_10(TargetObj, 2)
DEF_VSLOT_10(TargetObj, 3)
DEF_VSLOT_10(TargetObj, 4)
DEF_VSLOT_10(TargetObj, 5)
DEF_VSLOT_10(TargetObj, 6)
int TargetObj::v70() { return 0; } int TargetObj::v71() { return 0; } int TargetObj::v72() { return 0; } int TargetObj::v73() { return 0; }
int TargetObj::v74() { return 0; } int TargetObj::v75() { return 0; }
float TargetObj::Method138() { return 10.0f; }
int TargetObj::v77() { return 0; } int TargetObj::v78() { return 0; } int TargetObj::v79() { return 0; }
DEF_VSLOT_10(TargetObj, 8)
DEF_VSLOT_10(TargetObj, 9)
int TargetObj::v100() { return 0; } int TargetObj::v101() { return 0; } int TargetObj::v102() { return 0; } int TargetObj::v103() { return 0; }
int TargetObj::v104() { return 0; } int TargetObj::v105() { return 0; } int TargetObj::v106() { return 0; } int TargetObj::v107() { return 0; }
int TargetObj::Method1B8(int a1, int a2, float f12, int a3, int t0, int t1) {
    g_method1b8_called++;
    return 1;
}
int TargetObj::v109() { return 0; }
DEF_VSLOT_10(TargetObj, 11)
DEF_VSLOT_10(TargetObj, 12)
int TargetObj::v130() { return 0; } int TargetObj::v131() { return 0; } int TargetObj::v132() { return 0; } int TargetObj::v133() { return 0; }
int TargetObj::v134() { return 0; } int TargetObj::v135() { return 0; }
int TargetObj::Method228() { return 0; }

int TradeAction::v0() { return 0; } int TradeAction::v1() { return 0; } int TradeAction::v2() { return 0; } int TradeAction::v3() { return 0; }
int TradeAction::v4() { return 0; } int TradeAction::v5() { return 0; } int TradeAction::v6() { return 0; } int TradeAction::v7() { return 0; }
int TradeAction::v8() { return 0; }
int TradeAction::Method2C(float x, float y, int a1) {
    g_method2c_called++;
    return 1;
}

static TargetObj s_cand;
static char s_candNode[0x20];

extern "C" {
void *mock_func_332e60(void *timer, int a1) {
    if (a1 == 42) return &s_cand;
    return NULL;
}
}

int main() {
    TradeAction action;
    TargetObj target;
    char gameBuf[4000];
    char timerBuf[100];
    *(void **)(gameBuf + 0xB98) = timerBuf;
    target.m_game = gameBuf;
    target.m_field24 = 10;
    action.m_target = &target;

    s_cand.m_field24 = 42;
    s_cand.m_field39 = 0;
    s_cand.m_field3A = 5;
    s_cand.m_node = s_candNode;
    *(short *)(s_candNode + 0xE) = 15;
    *(short *)(s_candNode + 8) = 25;

    // List with one item: candidate_id = 42, score byte = 10, group byte = 1
    int itemData[2];
    itemData[0] = 42;
    // score at +4, group at +5
    unsigned char *p = (unsigned char *)&itemData[1];
    p[0] = 10; // score
    p[1] = 1;  // group

    mock_D_F99910[1] = itemData;
    mock_D_F99930[1] = 1;

    for (int i = 0; i < 5; i++) {
        if (i != 1) {
            mock_D_F99910[i] = NULL;
            mock_D_F99930[i] = 0;
        }
    }

    int score_out = 0;
    int best = func_0014EA40(&action, 15, 0, 0, 25, 3, &score_out);
    assert(best == 42);
    assert(score_out == 10);
    assert(g_method2c_called == 1);
    assert(g_method1b8_called == 1);
    assert(mock_D_004E3064 == 1);

    assert(func_0014EE70(&action) == -1);

    printf("trade_action_market_select_test passed\n");
    return 0;
}
