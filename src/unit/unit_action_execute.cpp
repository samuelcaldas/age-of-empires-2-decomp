#pragma exceptions off
#include "unit_action_execute.h"

int func_0026C600(ActionRebind *self, int arg1, int arg2, int arg3) {
    if (self == 0) {
        return 0;
    }
    (void)arg1; (void)arg2; (void)arg3;
    if (self->m_world != 0) {
        func_207C30(self->m_world, self->m_field24, -1);
    }
    func_0026E9C0(self);
    func_0026E560(self);
    if (func_26AD20(self, 1) != 0) {
        func_26AD30(self, 2);
    }
    func_1EDF20(self, self);
    func_00270A20(self);
    func_002D34A0(self);
    func_25F6E0(self, 1, 0, 0, -1, -1);
    func_0027B700(self);
    func_1ECD00(self, self);
    func_26AD60(self, 2);
    func_00273970(self);
    func_001EC350(self, self);
    func_002D3430(self);
    return 1;
}
