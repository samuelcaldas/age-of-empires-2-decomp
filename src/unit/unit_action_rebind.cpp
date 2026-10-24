#pragma exceptions off
#include "unit_action_rebind.h"

void func_00267A80(ActionRebind *self, void *new_entity) {
    if (self->m_field39 >= 3) {
        return;
    }

    func_2643C0(self);

    short new_val = *(short*)((char*)new_entity + 62);
    short old_val = *(short*)((char*)self->m_field4 + 62);
    float f20 = ((float)new_val * self->m_field30) / (float)old_val;
    self->m_field30 = (float)old_val;

    if (self->m_field39 == 2) {
        self->Method13();
    }

    if (self->m_field18 != 0) {
        self->Method62(self->m_world, 0, -1, 0);
    }

    func_207AB0(self->m_world, *(short*)((char*)self->m_field4 + 8), -1);
    func_207C30(self->m_world, *(short*)((char*)self->m_field4 + 8), -1);

    func_1EDF20(D_004E3244, self);

    self->m_field4 = new_entity;

    func_207AB0(self->m_world, *(short*)((char*)self->m_field4 + 8), 1);
    func_207C30(self->m_world, *(short*)((char*)self->m_field4 + 8), 1);

    if (self->m_field18 != 0) {
        self->Method61(self->m_world, 0, -1, 0);
    }

    func_1EDA80(D_004E3244, self);

    self->Method19(*(int*)((char*)new_entity + 16));

    self->m_field30 = f20;

    if (self->m_field39 == 2) {
        self->Method13();
    }

    func_264330(self);
}

void func_00267C20(ActionRebind *self, void *new_entity) {
    int target_id = 0;
    if (self->m_field18 != 0 && self->m_field39 == 2) {
        self->Method62(self->m_world, 0, -1, 0);
        float f0 = *(float*)((char*)new_entity + 28);
        int res = func_123350(f0);
        self->Method61(self->m_world, 0, res, 0);
    }

    short old_val = *(short*)((char*)self->m_field4 + 62);
    float f20;
    if (old_val != 0) {
        short new_val = *(short*)((char*)new_entity + 62);
        short res = (short)func_123350(self->m_field30);
        int scaled = ((int)res * (int)new_val) / (int)old_val;
        f20 = (float)scaled;
    } else {
        f20 = self->m_field30;
    }

    self->m_field30 = (float)old_val;

    if (self->m_field39 == 2) {
        self->Method13();
    }

    if (self->m_field10 == *(int*)((char*)self->m_field4 + 16)) {
        target_id = *(int*)((char*)new_entity + 16);
    } else if (self->m_field10 == *(int*)((char*)self->m_field4 + 24)) {
        target_id = *(int*)((char*)new_entity + 24);
    }

    self->m_field30 = f20;

    if (target_id != 0) {
        self->Method19(target_id);
    }

    void *old_field4 = self->m_field4;
    self->m_field4 = new_entity;

    if (self->m_field39 == 2) {
        self->Method13();
    }

    self->m_field4 = old_field4;
}

void func_267DD0(ActionRebind *self) {
    if (self->m_field39 >= 7) {
        return;
    }

    if (self->m_field1C != 0) {
        self->Method58();
    }

    if ((self->m_field36 & 1) != 0) {
        func_205F70(self->m_world, self);
    }

    self->m_field30 = 0.0f;
    func_26A540(self, 0);

    self->Method28(7);
}
