#pragma exceptions off
#include "unit_action_build_offset_query.h"

int func_00271460(ActionRebind *self) {
    if (func_00268500(self)) {
        return func_00268530(self) - (int)*(short*)((char*)self + 0x16E);
    }
    return 0;
}
