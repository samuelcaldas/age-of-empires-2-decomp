#ifndef UNIT_ACTION_EXECUTE_H
#define UNIT_ACTION_EXECUTE_H

#include "unit_action_combat_timing.h"

extern "C" {
    void func_00273970(void *action);
    void func_001EC350(void *field98, void *action);
    void func_002D3430(void *action);
    void func_002D34A0(void *action);
    void func_0027B700(void *action);
    void func_0026E9C0(void *action);

    int func_0026C600(ActionRebind *self, int arg1, int arg2, int arg3);
}

#endif // UNIT_ACTION_EXECUTE_H
