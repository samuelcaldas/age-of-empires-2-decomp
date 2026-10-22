#pragma exceptions off
#include "unit_action_build_flag_2000_set.h"

void func_002715F0(ActionRebind *self, int enable) {
    func_26AD30(self, 0x2000, enable);
    if (func_26AD20(self, 0x2000)) {
        void *game = D_004E3180;
        void *f404 = *(void**)((char*)game + 0x404);
        *(int*)((char*)self + 0xC0) = *(int*)((char*)f404 + 0x18);
    }
}
