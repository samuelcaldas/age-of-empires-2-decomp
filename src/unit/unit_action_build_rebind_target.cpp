#pragma exceptions off
#include "unit_action_build_rebind_target.h"

float func_002709B0(ActionRebind *self, void *target) {
    float res = func_274C90(self, target);

    if (*(short*)((char*)self + 364) > 0) {
        res *= 1.1f;
    }

    void *target_master = *(void**)((char*)target + 4);
    if (*(unsigned char*)target_master == 80) {
        if (*(short*)((char*)target + 364) > 0) {
            res /= 1.1f;
        }
    }

    return res;
}
