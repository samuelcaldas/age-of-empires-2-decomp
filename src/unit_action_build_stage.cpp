#pragma exceptions off
#include "unit_action_build_stage.h"

void func_0026EEA0(ActionRebind *self, void *arg1) {
    if (*(short*)((char*)self->m_field4 + 8) == 70) {
        if (*(void**)((char*)self + 0x10) != 0) {
            typedef int (*Method12Fn)(void *fC, void *f10);
            typedef void (*Method36Fn)(void *fC, void *f10, int step);

            void *fC = *(void**)((char*)self + 0xC);
            void *vtable = *(void**)((char*)fC + 8);
            Method12Fn m12 = *(Method12Fn*)((char*)vtable + 12);
            int res = m12(fC, *(void**)((char*)self + 0x10));

            short next_val = (short)res + 1;
            int step = 0;
            if (next_val < (int)*(unsigned char*)(*(char**)((char*)self + 0x10) + 0x39)) {
                step = next_val;
            }

            void *fC2 = *(void**)((char*)self + 0xC);
            void *vtable2 = *(void**)((char*)fC2 + 8);
            Method36Fn m36 = *(Method36Fn*)((char*)vtable2 + 36);
            m36(fC2, *(void**)((char*)self + 0x10), step);
        }
    }
    func_001DF340(self, arg1);
}
