#pragma exceptions off
#include "unit_action_build_target_validate.h"

void func_00270EF0(ActionRebind *self) {
    void *master = *(void**)((char*)self + 4);
    short type = *(short*)((char*)master + 8);
    if (type == 50 || type == 199 || type == 276) {
        return;
    }

    func_1950d0();
    void *target = *(void**)((char*)self + 300);
    if (GetHeadItem__8BaseListFv(target) != 0) {
        CallMethod13__8BaseListFv(self);
        Free__8BaseListFv(*(void**)((char*)self + 300));
        return;
    }

    func_00270530(self);
}
