#ifndef UNIT_ACTION_UPDATE_H
#define UNIT_ACTION_UPDATE_H

#include "unit_action_visibility.h"

extern "C" {
    void func_2643C0(void *action);
    char func_26AD20(void *action, int flag);
    void func_26A540(void *action, int flag);
    int func_183070(void *fieldC);
    int func_262BA0(int target, unsigned char field35);

    void func_00268200(ActionRebind *self, unsigned char new_state);
    int func_002683F0(ActionRebind *self);
    int func_00268410(ActionRebind *self);
    void func_00268470(ActionRebind *self, int arg);
    int func_002684B0(ActionRebind *self);
    int func_00268500(ActionRebind *self);
}

#endif // UNIT_ACTION_UPDATE_H
