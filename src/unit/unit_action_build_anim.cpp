#pragma exceptions off
#include "unit_action_build_anim.h"

static void determine_and_set_frame(ActionRebind *self, int *sp_vals) {
    int v1 = sp_vals[0];
    int v0_34 = sp_vals[1];
    int v0_38 = sp_vals[2];
    int v0_3C = sp_vals[3];

    if (v1 != 0 && v0_34 != 0 && v0_38 == 0 && v0_3C == 0) {
        func_0026A680(self, 1);
        return;
    }
    if (v0_38 == 0 && v0_3C == 0 && v1 == 0 && v0_34 != 0) {
        func_0026A680(self, 0);
        return;
    }

    int v1_40 = sp_vals[4];
    int v0_44 = sp_vals[5];
    int v0_48 = sp_vals[6];
    int v0_4C = sp_vals[7];

    if (v1_40 != 0 && v0_4C != 0 && v0_44 == 0 && v0_48 == 0) {
        func_0026A680(self, 3);
        return;
    }
    if (v0_44 != 0 && v0_48 != 0 && v1_40 == 0 && v0_4C != 0) {
        func_0026A680(self, 4);
        return;
    }
    func_0026A680(self, 2);
}

void func_0026E560(ActionRebind *self, int arg1) {
    if (self == 0 || self->m_field10 == 0) {
        return;
    }

    int sp_vals[8] = {0};
    func_0026E230(self, sp_vals);

    void *f4 = self->m_field4;
    if (f4 != 0 && *(short*)((char*)f4 + 0xE) != 0x27) {
        typedef void (*Method184Fn)(void *action);
        void **vtable = *(void***)self;
        Method184Fn m184 = (Method184Fn)vtable[184];
        if (m184 != 0) {
            m184(self);
        }
    }

    determine_and_set_frame(self, sp_vals);

    if (arg1 != 0) {
        ActionRebind **actions = (ActionRebind**)sp_vals;
        for (int i = 0; i < 8; ++i) {
            ActionRebind *child = actions[i];
            if (child != 0) {
                func_0026E560(child, 0);
            }
        }
    }
}

void func_0026E710(ActionRebind *self) {
    if (self == 0) {
        return;
    }
    func_26AD30(self, 0x200);
    func_26E750(self);
}
