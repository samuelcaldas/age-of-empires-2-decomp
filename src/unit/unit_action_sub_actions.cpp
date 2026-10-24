#pragma exceptions off
#include "unit_action_sub_actions.h"

void func_0026CF30(ActionRebind *self) {
    Action__7SubListFv(self);
    if (func_1880B0(D_004E3180) != 0) {
        int sub0 = *(int*)((char*)self + 0x130);
        if (sub0 != 0) {
            *(int*)((char*)self + 0x130) = (int)func_2668c0(self, sub0 - 1);
            if (*(short*)((char*)*(void**)((char*)self + 0x4) + 0xE) != 39) {
                func_1ECD00((char*)*(void**)((char*)self + 0x8) + 0x98, self);
            }
        }
        for (int i = 0; i < 4; ++i) {
            int sub_val = *(int*)((char*)self + 0x134 + i * 4);
            if (sub_val != 0) {
                *(int*)((char*)self + 0x134 + i * 4) = (int)func_2668c0(self, sub_val - 1);
            }
        }
    }
    Action__8BaseListFv(*(void**)((char*)self + 0x128));
    Action__8BaseListFv(*(void**)((char*)self + 0x12C));
    Action__8BaseListFv(*(void**)((char*)self + 0x14C));
}
