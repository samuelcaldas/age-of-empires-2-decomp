#ifndef UNIT_ACTION_COMBAT_TIMING_H
#define UNIT_ACTION_COMBAT_TIMING_H

#include "unit_action_teardown.h"

extern "C" {
    int func_002E03F0(void *action, void *target);
    void func_00277D50(void *action, float delta);
    void func_00277E50(void *action, void *target);

    void func_0026C3C0(ActionRebind *self, float delta);
    int func_0026C480(ActionRebind *self, void *target, float range);
}

#endif // UNIT_ACTION_COMBAT_TIMING_H
