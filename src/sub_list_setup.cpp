#include "sub_list.h"

extern "C" {
    extern float D_4E2F24;
    void func_226d90(void *stream, void *dst, int size);
    void* func_2668d0(void *player, short id);
}

static inline void read_id_field(void *stream, int *field, int *temp) {
    func_226d90(stream, temp, 4);
    if (*temp == -1) {
        *field = 0;
    } else {
        *field = *temp;
    }
}

static inline void read_fields(SubList *self, void *stream) {
    func_226d90(stream, &self->m_field18, 4);
    func_226d90(stream, &self->m_field1C, 4);
    func_226d90(stream, &self->m_field20, 4);
    func_226d90(stream, &self->m_field24, 4);
    func_226d90(stream, &self->m_field28, 4);
    func_226d90(stream, &self->m_field2C, 4);
}

static inline void read_version_and_master(SubList *self, void *stream, short *id) {
    if (D_4E2F24 >= 9.92f) {
        func_226d90(stream, &self->m_field3D, 1);
    }
    func_226d90(stream, id, 2);
    if (*id == -1) {
        self->m_field30 = 0;
    } else {
        void **masters = *(void***)(*(char**)(*(char**)((char*)self->m_field8 + 4) + 0xC8) + 4);
        self->m_field30 = masters[*id];
    }
}

int func_0013B8A0(SubList *self, void *stream, void *player) {
    int temp;
    short id;

    self->m_field4_short = 0;
    self->m_field8 = (WorldContainer*)player;
    self->m_field34 = (ListItem*)self->v3(self->m_field8);
    func_226d90(stream, &self->m_fieldC, 1);
    read_id_field(stream, &self->m_field10, &temp);
    read_id_field(stream, &self->m_field14, &temp);
    read_fields(self, stream);
    read_version_and_master(self, stream, &id);
    func_226d90(stream, &self->m_field3C, 1);
    ((BaseList*)self->m_field34)->Load(stream);
    func_226d90(stream, &id, 2);
    self->m_field38 = func_2668d0(self->m_field8, id);
    return 1;
}

int func_0013BA60(SubList *self, void *player) {
    self->m_field4_short = 0;
    self->m_field8 = (WorldContainer*)player;
    self->m_fieldC = 0;
    self->m_field10 = 0;
    self->m_field14 = 0;
    self->m_field20 = 0;
    self->m_field24 = 0;
    self->m_field28 = 0;
    self->m_field2C = 0;
    self->m_field30 = 0;
    self->m_field34 = (ListItem*)self->v3(self->m_field8);
    self->m_field38 = 0;
    self->m_field3C = 0;
    self->m_field3D = 0;
    return 1;
}
