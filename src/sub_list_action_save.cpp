#include "sub_list.h"

extern "C" {
    extern char D_10B68F0[];
    void* func_3668C0(void *obj, void *arg);
    void* func_2668c0(void *player, int id);
}

void func_0013BAD0(SubList *self) {
    func_3668C0(D_10B68F0, self->m_field8);
}

void func_0013BAE0(SubList *self) {
    if (self->m_field10) {
        self->m_field10 = (int)func_2668c0(self->m_field8, self->m_field10);
        if (self->m_field10) {
            self->m_field18 = *(short*)((char*)self->m_field10 + 0x24);
        }
    }
    if (self->m_field14) {
        self->m_field14 = (int)func_2668c0(self->m_field8, self->m_field14);
        if (self->m_field14) {
            self->m_field1C = *(short*)((char*)self->m_field14 + 0x24);
        }
    }
    if (self->m_field34) {
        ((BaseList*)self->m_field34)->Action();
    }
}

static inline void write_fields(SubList *self, void *stream) {
    func_226f70(stream, &self->m_field18, 4);
    func_226f70(stream, &self->m_field1C, 4);
    func_226f70(stream, &self->m_field20, 4);
    func_226f70(stream, &self->m_field24, 4);
    func_226f70(stream, &self->m_field28, 4);
    func_226f70(stream, &self->m_field2C, 4);
    func_226f70(stream, &self->m_field3D, 1);
}

void func_0013BB70(SubList *self, void *stream) {
    int temp;
    short id;

    func_226f70(stream, &self->m_field4_short, 2);
    func_226f70(stream, &self->m_fieldC, 1);

    if (!self->m_field10) {
        temp = -1;
    } else {
        temp = *(short*)((char*)self->m_field10 + 0x24);
    }
    func_226f70(stream, &temp, 4);

    if (!self->m_field14) {
        temp = -1;
    } else {
        temp = *(short*)((char*)self->m_field14 + 0x24);
    }
    func_226f70(stream, &temp, 4);

    write_fields(self, stream);

    if (!self->m_field30) {
        id = -1;
    } else {
        id = *(short*)((char*)self->m_field30 + 2);
    }
    func_226f70(stream, &id, 2);

    func_226f70(stream, &self->m_field3C, 1);
    ((BaseList*)self->m_field34)->Save(stream);

    if (!self->m_field38) {
        id = -1;
    } else {
        id = *(short*)((char*)self->m_field38 + 0x34);
    }
    func_226f70(stream, &id, 2);
}
