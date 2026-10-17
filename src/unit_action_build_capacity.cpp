#pragma exceptions off
#include "unit_action_build_capacity.h"

int func_00271460(ActionRebind *self) {
    if (func_00268500(self) == 0) {
        return 0;
    }

    int res = func_00268530(self);
    short f366 = *(short*)((char*)self + 366);
    return res - (int)f366;
}
