#ifndef UNIT_ACTION_SUB_ACTIONS_H
#define UNIT_ACTION_SUB_ACTIONS_H

#include "unit_action_execute.h"

extern "C" {
    extern void *D_004E3180;
    void Action__7SubListFv(void *self);
    int func_1880B0(void *game);
    int func_001880b0(void *game);
    int func_2668c0(void *self, int index);
    void* func_002668C0(void *self, int index);
    void func_1ECD00(void *target, void *self);
    void func_001ECD00(void *target, void *self);
    void Action__8BaseListFv(void *item);
    void func_0026CF30(ActionRebind *self);
}

#endif // UNIT_ACTION_SUB_ACTIONS_H
