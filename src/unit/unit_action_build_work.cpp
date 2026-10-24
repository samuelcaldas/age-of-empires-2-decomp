#pragma exceptions off
#include "unit_action_build_work.h"

struct Subsystem1B30 {
    char pad[0x13C];
    void (*Method13C)(void *actor, short field24);
    void (*Method140)(void *actor, short field24);
};

void func_00271640(ActionRebind *self) {
    void *master = self->m_field4;
    short field1A2 = *(short*)((char*)master + 0x1A2);
    if (field1A2 == -1) {
        return;
    }

    if (self->m_field39 == 2) {
        if (func_26AD20(self, 0x2000)) {
            if (func_3675D0(self) > D_004E2824) {
                return;
            }
        }

        int out_28;
        int out_2c;
        func_2717B0(self, D_00D8EBC0, &out_28, 0x19, &out_2c);

        if (func_3675D0(self) > D_004E2824) {
            if (out_2c > 0 && !func_26AD20(self, 0x2000)) {
                void *actor = *(void**)((char*)self + 8);
                Subsystem1B30 *sub = *(Subsystem1B30**)((char*)actor + 0x1B30);
                sub->Method140(actor, *(short*)((char*)self + 0x24));
                *(float*)((char*)self + 0x174) = 0.0f;
                return;
            }
        }

        if (func_3675D0(self) < D_004E2824) {
            if (out_28 != 0) {
                return;
            }

            float timer = *(float*)((char*)self + 0x174);
            if (timer > 0.0f) {
                void *actor = *(void**)((char*)self + 8);
                void *world = *(void**)((char*)actor + 0xB98);
                timer -= *(float*)((char*)world + 0xAC);
                *(float*)((char*)self + 0x174) = timer;
                if (timer < 0.0f) {
                    *(float*)((char*)self + 0x174) = 0.0f;
                    Subsystem1B30 *sub = *(Subsystem1B30**)((char*)actor + 0x1B30);
                    sub->Method13C(actor, *(short*)((char*)self + 0x24));
                }
            } else {
                *(float*)((char*)self + 0x174) = 0.5f;
            }
        }
    }
}
