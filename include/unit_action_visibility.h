#ifndef UNIT_ACTION_VISIBILITY_H
#define UNIT_ACTION_VISIBILITY_H

#include "unit_action_rebind.h"

extern "C" {
    extern int *D_50A5A0[];

    void func_205F70(void *world, void *action);
    void func_26A540(void *action, int flag);
    int func_123350(float val);
    void func_328300(void *obj, short val, unsigned char flag);
    int func_1EBA00(void *obj);
    void func_1ECD00(void *field98, void *action);
    void func_1ECBF0(void *field98, void *action, void *sight);

    void func_00267E60(ActionRebind *self);
    void func_00267EB0(ActionRebind *self);
    void func_00268070(ActionRebind *self);
}

#endif // UNIT_ACTION_VISIBILITY_H
