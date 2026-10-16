#ifndef UNIT_ACTION_MOVEMENT_OPS_H
#define UNIT_ACTION_MOVEMENT_OPS_H

#include "unit_action_state_handlers.h"

extern "C" {
    void func_00270530(void *action);
    void func_00270A20(void *action);
    void func_001CF350(void *world, int a1, int a2);
    void func_001CA430(void *world, int a1, int a2);
    void func_00272D10(void *action);
    void func_00272DD0(void *action);
    void func_00272E10(void *action);
    void func_0026BDF0(ActionRebind *self, void *a1 = 0, void *a2 = 0);

    void func_0026B550(ActionRebind *self, int arg1);
    int func_0026B710(ActionRebind *self, void *stream, int arg2, int arg3, int arg4);
    void func_0026BA00(ActionRebind *self, void *stream);
}

#endif // UNIT_ACTION_MOVEMENT_OPS_H
