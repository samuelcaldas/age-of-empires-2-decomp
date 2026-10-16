#ifndef UNIT_ACTION_DISTANCE_H
#define UNIT_ACTION_DISTANCE_H

#include "unit_action_advance.h"

extern "C" {
    void func_0026A540(void *action, int flag);

    void func_00269030(ActionRebind *self);
    void func_00269060(ActionRebind *self);
    float func_002690D0(ActionRebind *self, void *other);
    float func_002690E0(ActionRebind *self, void *other, float x, float y);
    float func_00269190(ActionRebind *self, float target_x, float target_y);
    float func_00269220(ActionRebind *self, float target_x, float target_y);
}

#endif // UNIT_ACTION_DISTANCE_H
