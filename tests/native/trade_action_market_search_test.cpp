#include <cassert>
#include <cstdio>
#include <cstring>

#define func_001510D0 mock_func_001510D0
#define func_002690D0 mock_func_002690D0
#define func_00147160 mock_func_00147160
#define func_00147170 mock_func_00147170
#define func_001471A0 mock_func_001471A0
#define func_001471C0 mock_func_001471C0

static int g_method2c_called = 0;
static int g_method150_called = 0;
static int g_method1b8_called = 0;

extern "C" {
int *mock_d_f99910[4];
int mock_d_f99930[4];
}

#define D_F99910 mock_d_f99910
#define D_F99930 mock_d_f99930

#include "../../src/trade/trade_action_market_search.cpp"

void Base0::b0() {}
void Base1::b1_0() {}
int Base1::Method0C(TargetObj *other) { return 1; }
int Base1::v2() { return 0; }
int Base1::v3() { return 0; }
int Base1::v4() { return 0; }
int Base1::v5() { return 0; }
int Base1::v6() { return 0; }
int Base1::v7() { return 0; }
int Base1::v8() { return 0; }
int Base1::v9() { return 0; }
#define DEF_VSLOT_10(cls, base) \
    int cls::v##base##0() { return 0; } int cls::v##base##1() { return 0; } int cls::v##base##2() { return 0; } int cls::v##base##3() { return 0; } int cls::v##base##4() { return 0; } \
    int cls::v##base##5() { return 0; } int cls::v##base##6() { return 0; } int cls::v##base##7() { return 0; } int cls::v##base##8() { return 0; } int cls::v##base##9() { return 0; }

DEF_VSLOT_10(Base1, 1)
DEF_VSLOT_10(Base1, 2)
DEF_VSLOT_10(Base1, 3)
DEF_VSLOT_10(Base1, 4)
DEF_VSLOT_10(Base1, 5)
DEF_VSLOT_10(Base1, 6)
DEF_VSLOT_10(Base1, 7)
int Base1::v80() { return 0; }
int Base1::v81() { return 0; }
void Base1::Method150(int a1, int a2) { g_method150_called++; }

void PlayerDiplomacy::vfn0() {}
void PlayerDiplomacy::vfn1() {}
void PlayerDiplomacy::vfn2() {}
void PlayerDiplomacy::vfn3() {}
void PlayerDiplomacy::vfn4() {}
void PlayerDiplomacy::vfn5() {}
void PlayerDiplomacy::vfn6() {}
int PlayerDiplomacy::IsAllied() { return 1; }

DEF_VSLOT_10(TargetObj, 0)
DEF_VSLOT_10(TargetObj, 1)
DEF_VSLOT_10(TargetObj, 2)
DEF_VSLOT_10(TargetObj, 3)
DEF_VSLOT_10(TargetObj, 4)
DEF_VSLOT_10(TargetObj, 5)
DEF_VSLOT_10(TargetObj, 6)
int TargetObj::v70() { return 0; }
float TargetObj::Method124() { return 10.0f; }
int TargetObj::v72() { return 0; } int TargetObj::v73() { return 0; } int TargetObj::v74() { return 0; } int TargetObj::v75() { return 0; }
int TargetObj::v76() { return 0; } int TargetObj::v77() { return 0; } int TargetObj::v78() { return 0; } int TargetObj::v79() { return 0; }
int TargetObj::v80() { return 0; } int TargetObj::v81() { return 0; } int TargetObj::v82() { return 0; } int TargetObj::v83() { return 0; }
int TargetObj::v84() { return 0; } int TargetObj::v85() { return 0; } int TargetObj::v86() { return 0; }
SubObj* TargetObj::Method164() {
    static SubObj dummySub;
    return &dummySub;
}
int TargetObj::v88() { return 0; } int TargetObj::v89() { return 0; }
DEF_VSLOT_10(TargetObj, 9)
int TargetObj::v100() { return 0; } int TargetObj::v101() { return 0; } int TargetObj::v102() { return 0; } int TargetObj::v103() { return 0; }
int TargetObj::v104() { return 0; } int TargetObj::v105() { return 0; } int TargetObj::v106() { return 0; } int TargetObj::v107() { return 0; }
int TargetObj::Method1B8(int a1, int a2, float f12, int a3, int t0, int t1) {
    g_method1b8_called++;
    return 1;
}
int TargetObj::v109() { return 0; }
int TargetObj::v110() { return 0; } int TargetObj::v111() { return 0; } int TargetObj::v112() { return 0; } int TargetObj::v113() { return 0; }
int TargetObj::v114() { return 0; } int TargetObj::v115() { return 0; }
int TargetObj::Method1D8() { return 0; }

int TradeAction::v0() { return 0; } int TradeAction::v1() { return 0; } int TradeAction::v2() { return 0; } int TradeAction::v3() { return 0; }
int TradeAction::v4() { return 0; } int TradeAction::v5() { return 0; } int TradeAction::v6() { return 0; } int TradeAction::v7() { return 0; }
int TradeAction::v8() { return 0; }
int TradeAction::Method2C(float x, float y, int a1) {
    g_method2c_called++;
    return 0;
}

static TargetObj s_target;
static TargetObj s_cand;
static PlayerDiplomacy s_targetPlayer;
static PlayerDiplomacy s_candPlayer;
static char s_candNode[0x20];
static char s_targetNode[0x20];

extern "C" {
TargetObj* mock_func_001510D0(void *self, int a1) {
    if (a1 == 99) return &s_target;
    if (a1 == 42) return &s_cand;
    return NULL;
}
float mock_func_002690D0(TargetObj *a, TargetObj *b) { return 5.0f; }
short mock_func_00147160(void *arg) { return 0; }
short mock_func_00147170(void *arg) { return -1; }
short mock_func_001471A0(void *arg) { return -1; }
short mock_func_001471C0(void *arg) { return -1; }
}

int main() {
    TradeAction action;
    // Don't memset action over vtable pointer
    s_target.m_game = &s_targetPlayer;
    s_target.m_node = s_targetNode;
    s_target.m_field24 = 10;
    s_target.x = 1.0f;
    s_target.y = 2.0f;

    s_cand.m_game = &s_candPlayer;
    s_cand.m_node = s_candNode;
    s_cand.m_field24 = 42;
    s_cand.m_field39 = 0;
    *(short *)((char *)s_cand.m_node + 0xE) = 5; // valid type

    action.m_target = &s_target;

    int list1[2] = { 42, 0 };
    mock_d_f99910[1] = list1;
    mock_d_f99930[1] = 1;
    mock_d_f99910[2] = NULL;
    mock_d_f99930[2] = 0;

    func_0014C470(&action, 99);

    assert(g_method2c_called == 1);
    assert(g_method1b8_called == 1);
    assert(g_method150_called == 1);

    printf("trade_action_market_search_test passed\n");
    return 0;
}
