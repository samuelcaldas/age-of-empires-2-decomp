#ifndef UNIT_ACTION_SPATIAL_H
#define UNIT_ACTION_SPATIAL_H

#include "unit_action_state.h"

extern "C" {
    extern void *D_004E3244;
    extern void *D_004E3180;

    void func_1D0B40(void *sub, int field18, void *action);
    void func_1EDF20(void *obj, void *action);
    void func_1EE720(void *obj, void *action);
    void* func_333B30(void *obj, int field64);
    void func_1B8910(void *obj, short field24);
    void func_205F70(void *world, void *action);
    int func_123350(float val);
    void* func_00137A40(int tile_x, int tile_y);

    void func_00268800(ActionRebind *self, ActionRebind *parent, int force);
    void func_00268940(ActionRebind *self);
    void func_00268970(ActionRebind *self, ActionRebind *target);
    void func_002689B0(ActionRebind *self);
    void* func_00268A10(ActionRebind *self);
}

#endif // UNIT_ACTION_SPATIAL_H
