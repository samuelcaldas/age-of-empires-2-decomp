#pragma exceptions off
#include "unit_action_state_handlers.h"

void func_0026B130(ActionRebind *self, int arg1) {
    if (self == 0) {
        return;
    }
    (void)arg1;
    func_00272C20(self);
    func_26AD60(self, 1);
    func_26AD60(self, 2);
    func_26AD60(self, 4);
    func_26AD60(self, 8);
    func_0026BA70(self);

    if (func_26AD20(self, 16) != 0) {
        int tx = func_123350(self->m_x);
        int ty = func_123350(self->m_y);
        (void)tx; (void)ty;
        void *field98 = *(void**)((char*)self + 0x98);
        func_1ECBF0(field98, self, 0);
        func_26AD30(self, 16);
    }
}

void func_0026B360(ActionRebind *self, int arg1) {
    if (self == 0) {
        return;
    }
    (void)arg1;
    func_00272C20(self);
    func_26AD60(self, 1);
    func_26AD60(self, 2);
    func_26AD60(self, 4);
    func_26AD60(self, 8);
    func_0026BA70(self);

    if (func_26AD20(self, 16) != 0) {
        int tx = func_123350(self->m_x);
        int ty = func_123350(self->m_y);
        (void)tx; (void)ty;
        void *field98 = *(void**)((char*)self + 0x98);
        func_1ECBF0(field98, self, 0);
        func_26AD30(self, 16);
    }
}
