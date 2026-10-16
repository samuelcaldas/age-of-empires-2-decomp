#pragma exceptions off
#include "unit_action_movement_ops.h"

void func_0026B550(ActionRebind *self, int arg1) {
    if (self == 0) {
        return;
    }
    (void)arg1;
    func_26AD60(self, 1);
    func_00272D10(self);
    func_26AD60(self, 2);
    func_26AD60(self, 4);
    func_26AD60(self, 8);
    func_0026BDF0(self);

    if (func_26AD20(self, 16) != 0) {
        int tx = func_123350(self->m_x);
        int ty = func_123350(self->m_y);
        (void)tx; (void)ty;
        void *field98 = *(void**)((char*)self + 0x98);
        func_1ECBF0(field98, self, 0);
        func_26AD30(self, 16);
    }
}

int func_0026B710(ActionRebind *self, void *stream, int arg2, int arg3, int arg4) {
    if (self == 0 || stream == 0) {
        return 0;
    }
    (void)arg2; (void)arg3; (void)arg4;
    func_00270530(self);
    func_00116F68(stream, &self->m_field39, 1);
    func_00270A20(self);
    int tx = func_123350(self->m_x);
    int ty = func_123350(self->m_y);
    (void)tx; (void)ty;
    func_00272DD0(self);
    return 1;
}

void func_0026BA00(ActionRebind *self, void *stream) {
    if (self == 0) {
        return;
    }
    func_0026B710(self, stream, 0, 0, 0);
    func_00272E10(self);
}
