#ifndef UNIT_ACTION_BUILD_LOAD_H
#define UNIT_ACTION_BUILD_LOAD_H

#include "unit_action_rebind.h"

extern "C" {
    void Free__8BaseListFv(void *item);
    void func_00270530(void *action);
    void func_274970(ActionRebind *self, void *stream);
    void func_002D34A0(void *action);
    int func_00268530(ActionRebind *self);
    ActionRebind* func_00268590(ActionRebind *self, int idx);
    void func_26F590(ActionRebind *child);
    int func_2E00D0(void *arg0, ActionRebind *self);

    void func_0026DE90(ActionRebind *self, void *stream);
}

#endif // UNIT_ACTION_BUILD_LOAD_H
