#pragma exceptions off
#include "unit_action_build_target_check.h"

typedef int (*TargetCheckFn)(void *world, void *target_ba0);

struct TargetChecker {
    char pad[0x1B30];
    void **vtable; // at 0x1B30
};

void func_00270F80(ActionRebind *self, int a1, int a2, int a3, int a4) {
    if (self->m_field39 == 0) {
        if (*(float*)((char*)self + 0x170) == 0.0f) {
            void *res1 = func_00186010(D_004E3180);
            if (!((TargetCheckFn)((TargetChecker*)self->m_world)->vtable[9])(
                    self->m_world, *(void**)((char*)res1 + 0xBA0))) {
                return;
            }

            void *res2 = func_00186010(D_004E3180);
            if (!((TargetCheckFn)((TargetChecker*)res2)->vtable[9])(
                    res2, *(void**)((char*)self->m_world + 0xBA0))) {
                return;
            }
        }
    }

    func_270E30(self);
    func_264450(self, a1, a2, a3, a4);
}
