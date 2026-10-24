#pragma exceptions off
#include "unit_action_build_target_check4.h"

typedef void* (*TargetCheckFn)(void *world, void *target_ba0);

void func_00271150(ActionRebind *self, int a1, int a2, int a3) {
    if (self->m_field39 == 0) {
        if (*(float*)((char*)self + 0x170) == 0.0f) {
            void *res1 = func_00186010(D_004E3180);
            void *actor = self->m_world;
            TargetCheckFn m1 = (TargetCheckFn)(*(void***)((char*)actor + 0x1B30))[9];
            if (!m1(actor, *(void**)((char*)res1 + 0xBA0))) {
                return;
            }

            void *res2 = func_00186010(D_004E3180);
            void *actor2 = self->m_world;
            TargetCheckFn m2 = (TargetCheckFn)(*(void***)((char*)res2 + 0x1B30))[9];
            if (!m2(res2, *(void**)((char*)actor2 + 0xBA0))) {
                return;
            }
        }
    }

    func_2647C0(self, a1, a2, a3);
}
