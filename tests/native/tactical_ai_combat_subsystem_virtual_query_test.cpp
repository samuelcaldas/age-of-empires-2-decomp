#include <cassert>
#include "tactical_ai_combat_subsystem_virtual_query.h"

int TacticalCombatSubsystem::func_0032F2B0() {
    return 14;
}

struct MockSubsystem : public TacticalCombatSubsystem {
    virtual int func_0032F2B0() {
        return 999;
    }
};

int main() {
    MockSubsystem mock;
    int res = mock.func_0032F860();
    assert(res == 999);

    TacticalCombatSubsystem base;
    assert(base.func_0032F860() == 14);

    return 0;
}
