#pragma exceptions off
#include "unit_action_update.h"

void func_00268200(ActionRebind *self, unsigned char new_state) {
    if (self->m_field39 == new_state) {
        return;
    }
    if (new_state < self->m_field39 && new_state != 0) {
        return;
    }

    if (new_state >= 3 && self->m_field39 < 3) {
        func_2643C0(self);
        if (*(unsigned char*)((char*)self->m_field4 + 144) == 2) {
            self->Method30();
        }
    }

    if (self->m_field39 < 4) {
        if (new_state >= 7) {
            self->Method29();
        }
    }

    if (new_state >= 3) {
        if (self->m_field39 == 2 && self->m_field18 != 0) {
            self->Method62(self->m_world, 0, -1, 0);
            if (*(float*)((char*)self->m_field4 + 28) > 0.0f) {
                self->Method61(self->m_world, 1, -1, 0);
            }
        }
    }

    if (self->m_field39 < 7) {
        if (new_state == 7 && self->m_field18 != 0) {
            if (*(float*)((char*)self->m_field4 + 28) > 0.0f) {
                self->Method62(self->m_world, 1, -1, 0);
            }
        }
    }

    self->m_field39 = new_state;

    if (func_26AD20(self, 1) != 0) {
        if (self->m_field39 != 2) {
            func_26A540(self, 0);
        }
    }
}

int func_002683F0(ActionRebind *self) {
    return self->m_field39 < 3;
}

int func_00268410(ActionRebind *self) {
    if (self->m_field10 == 0) {
        return 0;
    }
    if (self->m_fieldC != 0) {
        return (unsigned char)func_183070(self->m_fieldC);
    }
    return (unsigned char)func_262BA0(self->m_field10, self->m_field35);
}

void func_00268470(ActionRebind *self, int arg) {
    if (self->m_field10 == 0) {
        return;
    }
    if (self->m_fieldC == 0) {
        return;
    }
    typedef void (*Method36Fn)(void *fieldC, int target, int arg);
    void *sub = *(void**)((char*)self->m_fieldC + 8);
    Method36Fn method36 = *(Method36Fn*)((char*)sub + 36);
    method36(self->m_fieldC, self->m_field10, arg);
}

int func_002684B0(ActionRebind *self) {
    int res = 0;
    if (self->m_field10 != 0 && self->m_fieldC != 0) {
        typedef int (*Method12Fn)(void *fieldC, int target);
        void *sub = *(void**)((char*)self->m_fieldC + 8);
        Method12Fn method12 = *(Method12Fn*)((char*)sub + 12);
        res = method12(self->m_fieldC, self->m_field10);
    }
    return res;
}

int func_00268500(ActionRebind *self) {
    if ((unsigned int)self->m_field1C != 0) {
        return 0;
    }
    return (unsigned int)self->m_field20 != 0;
}
