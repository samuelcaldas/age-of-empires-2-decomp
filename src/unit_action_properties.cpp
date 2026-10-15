#pragma exceptions off
#include "unit_action_properties.h"

void func_00267750(ActionExtended *self, int prop_id, float val) {
    switch (prop_id & 0xFF) {
    case 0: {
        float f0 = (self->m_field30 * val) / (float)*(short*)((char*)self->m_field4 + 62);
        self->m_field30 = (float)func_123350(f0);
        break;
    }
    case 1:
        if (self->m_field18 != 0 && self->m_field39 == 2) {
            self->Method62(self->m_world, 0, -1, 0);
            int res = func_123350(val);
            self->Method61(self->m_world, 0, res, 0);
        }
        break;
    case 21: {
        void *field4 = self->m_field4;
        if (((unsigned char*)field4)[112] == 2) {
            short arg1 = *(short*)((char*)field4 + 90);
            if (arg1 >= 0) {
                WorldProps *world = (WorldProps*)self->m_world;
                float f0 = *(float*)((char*)field4 + 96);
                world->m_field1B30->Method7C(world, arg1, 0, -f0);
            }
            WorldProps *world = (WorldProps*)self->m_world;
            world->m_field1B30->Method7C(world, *(short*)((char*)self->m_field4 + 90), 0, val);
        }
        break;
    }
    }
}

void func_002678A0(ActionExtended *self, int prop_id, float val) {
    switch (prop_id & 0xFF) {
    case 0: {
        float val2 = (float)*(short*)((char*)self->m_field4 + 62);
        float f0 = (self->m_field30 * (val + val2)) / val2;
        self->m_field30 = (float)func_123350(0.5f + f0);
        break;
    }
    case 1:
        if (self->m_field18 != 0 && self->m_field39 == 2) {
            self->Method62(self->m_world, 0, -1, 0);
            float f0 = *(float*)((char*)self->m_field4 + 28);
            int res = func_123350(val + f0);
            self->Method61(self->m_world, 0, res, 0);
        }
        break;
    }
}

void func_002679A0(ActionExtended *self, int prop_id, float val) {
    switch (prop_id & 0xFF) {
    case 0: {
        float f0 = self->m_field30 * val;
        self->m_field30 = (float)func_123350(0.5f + f0);
        break;
    }
    case 1:
        if (self->m_field18 != 0 && self->m_field39 == 2) {
            self->Method62(self->m_world, 0, -1, 0);
            float f0 = *(float*)((char*)self->m_field4 + 28);
            int res = func_123350(f0 * val);
            self->Method61(self->m_world, 0, res, 0);
        }
        break;
    }
}
