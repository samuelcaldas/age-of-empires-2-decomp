#ifndef UNIT_ACTION_BUILD_WORKER_H
#define UNIT_ACTION_BUILD_WORKER_H

#include "unit_action_rebind.h"

extern "C" {
    int func_123350(float val);
    char func_26AD20(void *action, int flag);
    void func_26AD30(void *action, int flag);
    void func_26AD60(void *action, int flag);
    void func_1ecbf0(void *world, int tx, int ty, void *action);
    void func_1EDA80(void *obj, void *action);
    void func_271220(ActionRebind *self, int arg);

    void func_0026E9C0(ActionRebind *self);
    void func_0026EAB0(ActionRebind *self, float val);
}

#endif // UNIT_ACTION_BUILD_WORKER_H
