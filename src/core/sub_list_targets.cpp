#include "sub_list.h"

extern "C" {
    void* func_332e60(void *mgr, int id);
}

extern "C" int func_0013BE90(SubList *self) {
    if (self->m_field10 != 0 && ((unsigned char*)self->m_field10)[0x39] >= 7) {
        self->v21(0);
    }
    if (self->m_field14 != 0 && ((unsigned char*)self->m_field14)[0x39] >= 7) {
        self->v22(0);
    }
    ListItem *node = self->m_field34;
    if (node->m_field8 != 0) {
        return node->Action();
    }
    if (self->m_fieldC == 1) {
        return 1;
    }
    return 0;
}

extern "C" void func_0013BF50(SubList *self, void *new_target) {
    if (self->m_field10 != 0 && self->m_field10 != (int)new_target) {
        void *world = *(void**)((char*)self->m_field8 + 8);
        void *mgr = *(void**)((char*)world + 0xB98);
        TargetEntity *obj = (TargetEntity*)func_332e60(mgr, self->m_field18);
        if (obj != 0) {
            obj->Method51(self->m_field8);
        }
    }
    if (self->m_field10 != (int)new_target) {
        self->m_field10 = (int)new_target;
        if (self->m_field10 != 0) {
            self->m_field18 = *(short*)((char*)self->m_field10 + 0x24);
            ((TargetEntity*)self->m_field10)->Method50(self->m_field8, self->m_field4_short, 0);
        } else {
            self->m_field18 = -1;
        }
    }
}

extern "C" void func_0013C010(SubList *self, void *new_target) {
    if (self->m_field14 != 0 && self->m_field14 != (int)new_target) {
        void *world = *(void**)((char*)self->m_field8 + 8);
        void *mgr = *(void**)((char*)world + 0xB98);
        TargetEntity *obj = (TargetEntity*)func_332e60(mgr, self->m_field1C);
        if (obj != 0) {
            obj->Method51(self->m_field8);
        }
    }
    if (self->m_field14 != (int)new_target) {
        self->m_field14 = (int)new_target;
        if (self->m_field14 != 0) {
            self->m_field1C = *(short*)((char*)self->m_field14 + 0x24);
            ((TargetEntity*)self->m_field14)->Method50(self->m_field8, self->m_field4_short, 0);
        } else {
            self->m_field1C = -1;
        }
    }
}
