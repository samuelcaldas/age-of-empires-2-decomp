#pragma exceptions off
#include "unit_action_build_cost.h"

void func_0026EDF0(ActionRebind *self, void *arg1) {
    if (self == 0) {
        return;
    }

    void *f4 = self->m_field4;
    void *v10 = *(void**)((char*)self + 0x10);
    if (f4 != 0 && v10 == *(void**)((char*)f4 + 0x16C)) {
        typedef void (*Method19Fn)(void *action, void *arg);
        void **vtable = *(void***)self;
        Method19Fn m19 = (Method19Fn)vtable[17];
        if (m19 != 0 && arg1 != 0) {
            m19(self, *(void**)((char*)arg1 + 0x16C));
        }
    }

    func_2738A0(self, arg1);

    if (self->m_field4 != 0 && *(unsigned char*)((char*)self->m_field4 + 0x1B0) != 0) {
        func_0026E560(self, 1);
    }
}

void func_0026EE70(ActionRebind *self) {
    if (self == 0 || self->m_field4 == 0) {
        return;
    }
    short mtype = *(short*)((char*)self->m_field4 + 0xE);
    if (mtype != 0x1B) {
        func_1DCF10(self);
    }
}
