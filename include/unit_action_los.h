#ifndef UNIT_ACTION_LOS_H
#define UNIT_ACTION_LOS_H

#include "unit_action_spatial.h"

extern "C" {
    int func_123350(float val);
    void func_00137AA0(void *zone, int x, int y, int radius, int arg4, int diff, short field24);
    void func_00137EA0(void *zone, int x, int y, int radius, int arg4, int diff, short field24);
    void func_00138040(void *zone, int min_x, int min_y, int max_x, int max_y, int diff, short field24);
    void func_00138320(void *zone, int min_x, int min_y, int max_x, int max_y, int diff, short field24);

    void func_00268A60(ActionRebind *self, void *world, int flag, int radius_override, int arg4);
    void func_00268C30(ActionRebind *self, void *world, int flag, int radius_override, int arg4);
}

#endif // UNIT_ACTION_LOS_H
