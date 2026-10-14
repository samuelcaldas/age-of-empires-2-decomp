#include "sub_list.h"

extern "C" {
void *memset(void *s, int c, unsigned int n);
void *func_100730(int size);
void func_26AD90(void *ptr, int id);
void func_145680(void *ptr);
void *func_001407B0(void *self, int a1, int a2, int a3);
void *func_001409B0(void *self);
extern char D_4D7768[];
}

struct TacticalAI2 {
    void *m_vtable;
    char pad_04[0x18];
    short field_1C;
    char pad_1E[0x16];
    void *field_34;
    char pad_38[0x4];
    void **field_3C;
    int field_40;
    char field_44[0x148];
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
    char field_1A0[0x100];
    int field_2A0;
    int field_2A4;
    char field_2A8[0x400];
    char *field_6A8;
    int field_6AC;
    int field_6B0;
    int field_6B4;
    int field_6B8;
    int field_6BC;
    int field_6C0;
    char field_6C4[0x28F0];
    int field_2FB4;
    char field_2FB8[0xC8];
    int field_3080;
};

extern "C" {

TacticalAI2 *func_00141D40(TacticalAI2 *self, int a1, int a2, int a3, int t0) {
    (void)&self;
    func_001407B0(self, a1, a2, a3);
    self->m_vtable = D_4D7768;
    func_26AD90(&self->field_34, 0x3F5);
    func_145680(&self->field_44);

    self->field_3C = (void **)func_100730((long)(short)t0 * 4);
    for (int i = 0; i < (short)t0; i++) {
        self->field_3C[i] = 0;
    }

    self->field_40 = 0;
    self->field_18C = -1;
    self->field_190 = 0;
    self->field_194 = 0;
    self->field_198 = 1;
    self->field_19C = 0;
    self->field_1A0[0] = 0;
    self->field_2A0 = 0;
    self->field_2A4 = 0;
    self->field_2A8[0] = 0;
    self->field_6A8 = &self->field_2A8[0];
    self->field_6AC = 0;
    self->field_6B0 = 0;
    self->field_6B4 = 0;
    self->field_6B8 = 0;
    self->field_6BC = 0;
    self->field_6C0 = 0;
    self->field_2FB4 = 0;
    self->field_3080 = 0;
    memset(self->field_6C4, 0, 0x28F0);
    memset(self->field_2FB8, 0, 0xC8);

    return self;
}

TacticalAI2 *func_00141EC0(TacticalAI2 *self) {
    (void)&self;
    func_001409B0(self);
    self->m_vtable = D_4D7768;
    func_26AD90(&self->field_34, 0x3F5);
    func_145680(&self->field_44);

    self->field_3C = (void **)func_100730((long)self->field_1C * 4);
    for (int i = 0; i < self->field_1C; i++) {
        self->field_3C[i] = 0;
    }

    return self;
}

}
