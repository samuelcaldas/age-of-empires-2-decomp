#include <cassert>
#include <cstdio>
#include <cstring>

class TargetObj;

#define func_1510D0 mock_func_1510D0
#define func_332e60 mock_func_332e60
#define func_001471B0 mock_func_001471B0
#define func_14bd90 mock_func_14bd90

extern "C" {
int D_00F99940 = 0;
int *D_00F99920 = NULL;

TargetObj *mock_func_1510D0(void *self, int id) { return NULL; }
void *mock_func_332e60(void *timer, int a1) { return NULL; }
void mock_func_001471B0(void *self, int a1) {}
void mock_func_14bd90(void *self, int a1, short a2, float f12, float f13, float f14) {}
}

#include "../../src/trade/trade_action_navigation.cpp"

void TradeAction::Method2C(float x, float z, int a1) {}
void TradeAction::Method5C(int a1) {}
void TradeAction::vfn0() {}
void TradeAction::vfn1() {}
void TradeAction::vfn2() {}
void TradeAction::vfn3() {}
void TradeAction::vfn4() {}
void TradeAction::vfn5() {}
void TradeAction::vfn6() {}
void TradeAction::vfn7() {}
void TradeAction::vfn8() {}
void TradeAction::vfn10() {}
void TradeAction::vfn11() {}
void TradeAction::vfn12() {}
void TradeAction::vfn13() {}
void TradeAction::vfn14() {}
void TradeAction::vfn15() {}
void TradeAction::vfn16() {}
void TradeAction::vfn17() {}
void TradeAction::vfn18() {}
void TradeAction::vfn19() {}
void TradeAction::vfn20() {}

int main() {
    TradeAction action;
    std::memset(&action, 0, sizeof(action));

    // Initially 0 entries
    assert(func_00149D80(&action, 10, 20) == 0);

    // Add entry (10, 20)
    func_00149D20(&action, 10, 20);
    assert(action.m_field134 == 1);
    assert(func_00149D80(&action, 10, 20) == 1);
    assert(func_00149D80(&action, 10, 21) == 0);
    assert(func_00149D80(&action, 11, 20) == 0);

    // Add entry (30, 40)
    func_00149D20(&action, 30, 40);
    assert(action.m_field134 == 2);
    assert(func_00149D80(&action, 10, 20) == 1);
    assert(func_00149D80(&action, 30, 40) == 1);
    assert(func_00149D80(&action, 50, 60) == 0);

    // Simple return-1 functions
    assert(func_00149E00() == 1);
    assert(func_00149E10() == 1);

    std::printf("All trade_action_navigation tests passed!\n");
    return 0;
}
