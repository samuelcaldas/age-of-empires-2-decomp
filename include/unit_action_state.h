#ifndef UNIT_ACTION_STATE_H
#define UNIT_ACTION_STATE_H

#include "unit_action_update.h"

extern "C" {
    int func_00268500(ActionRebind *self);
    int func_123350(float val);

    int func_00268530(ActionRebind *self);
    ActionRebind* func_00268590(ActionRebind *self, int target_index = 0);
    void func_002685C0(ActionRebind *self);
    int func_00268610(ActionRebind *self, int filter_state, int filter_fieldE, int filter_field8, int min_x, int min_y, int max_x, int max_y, int filter_field74, ActionRebind **out_actions);
    int func_002687C0(ActionRebind *self);
}

#endif // UNIT_ACTION_STATE_H
