#ifndef UNIT_ACTION_ADVANCE_H
#define UNIT_ACTION_ADVANCE_H

#include "unit_action_los.h"

extern "C" {
    void func_0026A540(void *action, int flag);
    int func_001AAB30();
    int func_26A700(void *action, int *out1, int *out2);
    void func_25F6E0(void *field38, int a1, int a2, int a3, int a4, int a5);
    void func_001AAB70(int obj);
    void func_26A680(void *action, unsigned char frame);

    void func_00268DE0(ActionRebind *self);
    float func_00268EB0(int count, void *arr, float scale);
    void func_00268F00(ActionRebind *self, int delta);
    void func_00268F40(ActionRebind *self, short val, float fval);
    void func_00268F50(ActionRebind *self, int add_flag, int clamp_flag, float delta);
    int func_00268FB0(ActionRebind *self, float delta);
}

#endif // UNIT_ACTION_ADVANCE_H
