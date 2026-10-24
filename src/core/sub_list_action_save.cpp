#include "sub_list.h"

#pragma exceptions off

extern "C" {
    extern char D_10B68F0[];
    void* func_3668C0(void *obj, void *item);
    void* func_2668c0(void *world, void *item);
    void func_00226F70(void *stream, void *src, int size);
}

void* func_0013BAD0(SubList *self) {
    return func_3668C0(D_10B68F0, self->m_field8);
}

void func_0013BAE0(SubList *self) {
    if (self->m_field10) {
        self->m_field10 = (int)func_2668c0(self->m_field8, (void*)self->m_field10);
        if (self->m_field10) {
            self->m_field18 = *(short*)((char*)self->m_field10 + 0x24);
        }
    }
    if (self->m_field14) {
        self->m_field14 = (int)func_2668c0(self->m_field8, (void*)self->m_field14);
        if (self->m_field14) {
            self->m_field1C = *(short*)((char*)self->m_field14 + 0x24);
        }
    }
    if (self->m_field34) {
        ((BaseList*)self->m_field34)->Action();
    }
}

void func_0013BB70(SubList *self, void *stream) {
    func_00226F70(stream, &self->m_field4, 2);
    func_00226F70(stream, &self->m_fieldC, 1);

    int id;
    if (!self->m_field10) {
        id = -1;
    } else {
        id = *(short*)((char*)self->m_field10 + 0x24);
    }
    func_00226F70(stream, &id, 4);

    if (!self->m_field14) {
        id = -1;
    } else {
        id = *(short*)((char*)self->m_field14 + 0x24);
    }
    func_00226F70(stream, &id, 4);

    func_00226F70(stream, &self->m_field18, 4);
    func_00226F70(stream, &self->m_field1C, 4);
    func_00226F70(stream, &self->m_field20, 4);
    func_00226F70(stream, &self->m_field24, 4);
    func_00226F70(stream, &self->m_field28, 4);
    func_00226F70(stream, &self->m_field2C, 4);
    func_00226F70(stream, &self->m_field3D, 1);

    short s;
    if (!self->m_field30) {
        s = -1;
    } else {
        s = *(short*)((char*)self->m_field30 + 0x2);
    }
    func_00226F70(stream, &s, 2);

    func_00226F70(stream, &self->m_field3C, 1);
    ((BaseList*)self->m_field34)->Save(stream);

    if (!self->m_field38) {
        s = -1;
    } else {
        s = *(short*)((char*)self->m_field38 + 0x34);
    }
    func_00226F70(stream, &s, 2);
}
