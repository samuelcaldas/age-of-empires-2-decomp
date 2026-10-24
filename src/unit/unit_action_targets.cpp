#pragma exceptions off
#include "unit_action_targets.h"

float func_00267380(ActionExtended *self, float val) {
    switch (((unsigned char*)self->m_field4)[2]) {
    case 0:
        self->m_z = val;
        break;
    case 1:
        if (self->m_z < val) {
            self->m_z = val;
        }
        break;
    }
    return self->m_z;
}

void func_002673D0(ActionExtended *self, int target_id) {
    if (target_id == 0) {
        target_id = *(int*)((char*)self->m_field4 + 16);
    }
    if (self->m_field10 == target_id) {
        return;
    }
    self->m_field14 = self->m_field10;
    if (self->m_fieldC != 0) {
        func_1827B0(self->m_fieldC, self->m_field10);
        self->m_field10 = target_id;
    } else {
        if (self->m_field10 != 0 && func_2634A0(self->m_field10) != 0) {
            func_26A460(self);
        }
        self->m_field10 = target_id;
    }

    if (self->m_fieldC != 0) {
        func_182610(self->m_fieldC, self->m_field10, 60, 0, 0, self->m_field35);
        self->m_field35 = 0;
    } else {
        if (self->m_field10 != 0 && func_2634A0(self->m_field10) != 0) {
            func_26A460(self);
        }
        self->m_field35 = 0;
    }
}

void func_002674C0(ActionExtended *self, int arg1, int arg2) {
    if (self->m_fieldC != 0) {
        func_182610(self->m_fieldC, arg1, arg2, 0, 0, self->m_field35);
    }
}

void func_00267500(ActionExtended *self, int arg1) {
    if (self->m_fieldC != 0) {
        func_1827B0(self->m_fieldC, arg1);
    }
}

void func_00267530(ActionExtended *self, WorldExtended *world) {
    short id = *(short*)((char*)self->m_field4 + 8);
    void *entity = world->m_entities[id];
    if (entity == 0) {
        return;
    }

    if ((self->m_field36 & 1) != 0) {
        func_205F70(self->m_world, self);
    }

    float f20 = ((float)*(short*)((char*)entity + 62) * self->m_field30) / (float)*(short*)((char*)self->m_field4 + 62);
    func_2643C0(self);

    if (self->m_field39 == 2) {
        self->Method62(self->m_world, 0, -1, 0);
    }

    int a2 = (unsigned char)func_26AD20(self, 1);
    int a3 = (unsigned char)func_26AD20(self, 4);
    self->m_world->m_field1B30->Method114(self->m_world, self, a2, a3, self->m_field26);

    a2 = (unsigned char)func_26AD20(self, 1);
    a3 = (unsigned char)func_26AD20(self, 4);
    self->m_field26 = world->m_field1B30->Method110(world, self, a2, a3);

    int target = 0;
    if (self->m_field10 == *(int*)((char*)self->m_field4 + 16)) {
        target = *(int*)((char*)entity + 16);
    } else if (self->m_field10 == *(int*)((char*)self->m_field4 + 24)) {
        target = *(int*)((char*)entity + 24);
    } else {
        target = *(int*)((char*)entity + 16);
    }

    if (target != 0) {
        self->Method19(target);
    }

    self->m_world = world;
    self->m_field4 = entity;
    self->m_field30 = f20;

    if (self->m_field39 == 2) {
        self->Method61(self->m_world, 0, -1, 0);
    }

    func_264290(self);

    self->Method90(self->m_field24, self->m_field24, 523, world->m_fieldBA0, 0, 0);
}
