#ifndef UNIT_ACTION_LIFECYCLE_H
#define UNIT_ACTION_LIFECYCLE_H

#include "unit_action_movement_ops.h"

extern "C" {
    void func_207C30(void *world, short id, int delta);
    void func_1ECD00(void *field98, void *action);
    void func_00272E80(void *action);
    void func_0026E560(void *action);
    void func_0026E940(void *action);
    void func_0030FF80(void *action);
    void func_00273130(void *action);
    void func_00226D90(void *action);
    void func_00138BA0(void *list, void *action);
    void func_001143F8(void *action);

    void func_0026BA70(ActionRebind *self);
    void func_0026BDF0(ActionRebind *self, void *a1, void *a2);
}

#endif // UNIT_ACTION_LIFECYCLE_H
