#include "sub_list.h"

extern "C" {

struct SubListItemBase {
    void *m_vtable;
    int m_field4;
    int m_field8;
    int m_fieldC;
    float m_field10;
    float m_field14;
    float m_field18;
    float m_field1C;
    float m_field20;
    float m_field24;
    int m_field28;
    char m_name[64];
};

struct SubListBuildItem : public SubListItemBase {
    int m_field6C;
    int m_field70;
    int m_field74;
    int m_field78;
    int m_field7C;
    int m_field80;
    int m_field84;
    int m_targets[3];
    int m_field94;
    int m_field98;
    int m_field9C;
    int m_fieldA0;
    int m_fieldA4;
    int m_fieldA8;
    int pad_AC;
    unsigned char m_fieldB0;
};

extern char D_4D75E0[];

SubListItemBase* func_0013C660(SubListItemBase *self);
void func_0013C6D0(SubListItemBase *self, int a1, int a2, int a3,
                   float f1, float f2, float f3, float f4, float f5, float f6,
                   const char *str);
SubListItemBase* func_0013C770(SubListItemBase *self, int flag);
void __vec_ctor(void *self);

SubListBuildItem* func_0013C8E0(SubListBuildItem *self) {
    func_0013C660((SubListItemBase*)self);
    *(void**)self = D_4D75E0;
    self->m_field6C = 0;
    self->m_field70 = 0;
    self->m_field74 = -1;
    self->m_field78 = 0;
    self->m_field7C = 0;
    self->m_field80 = 0;
    self->m_field84 = -1;
    self->m_targets[0] = -1;
    self->m_field94 = 0;
    self->m_field98 = -1;
    self->m_field9C = 0;
    self->m_fieldA0 = 0;
    self->m_fieldA4 = 0;
    self->m_fieldA8 = 0;
    self->m_fieldB0 = 0;
    self->m_targets[1] = -1;
    self->m_targets[2] = -1;
    return self;
}

asm void func_0013C960(SubListBuildItem *self, int p74, int a1, int a3,
                   int p78, int p7C, int p84, const char *str,
                   float f15, float f16, float f17,
                   int p88, int p8C, int p90, int pA8) {
    addiu sp, sp, -0x60
    mov.s f16, f13
    sq ra, 0x50(sp)
    sq s4, 0x40(sp)
    sq s3, 0x30(sp)
    sq s2, 0x20(sp)
    sq s1, 0x10(sp)
    paddub s4, a1, zero
    lui v0, 0xBF80
    paddub a1, a2, zero
    sq s0, 0x0(sp)
    paddub s3, t0, zero
    mtc1 v0, f13
    nop
    mov.s f15, f12
    mov.s f17, f14
    addiu a2, zero, -1
    mov.s f14, f13
    paddub s2, t1, zero
    paddub s1, t2, zero
    paddub s0, a0, zero
    paddub t0, t3, zero
    jal func_0013C6D0
    mov.s f12, f13
    sw s4, 0x74(s0)
    sw s3, 0x78(s0)
    sw s2, 0x7C(s0)
    sw zero, 0xA0(s0)
    sw zero, 0xA4(s0)
    sw zero, 0x80(s0)
    sw s1, 0x84(s0)
    lw a0, 0x60(sp)
    addiu v1, zero, -1
    sw a0, 0x88(s0)
    lw a0, 0x78(sp)
    sw a0, 0xA8(s0)
    sw zero, 0x6C(s0)
    sw zero, 0x70(s0)
    sw zero, 0x94(s0)
    sw v1, 0x98(s0)
    sw zero, 0x9C(s0)
    sb zero, 0xB0(s0)
    lw v1, 0x68(sp)
    sw v1, 0x8C(s0)
    lw v1, 0x70(sp)
    sw v1, 0x90(s0)
    lq ra, 0x50(sp)
    lq s4, 0x40(sp)
    lq s3, 0x30(sp)
    lq s2, 0x20(sp)
    lq s1, 0x10(sp)
    lq s0, 0x0(sp)
    jr ra
    addiu sp, sp, 0x60
}

SubListBuildItem* func_0013CA40(SubListBuildItem *self, int flag) {
    if (self) {
        *(void**)self = D_4D75E0;
        self->m_field6C = 0;
        self->m_field70 = 0;
        func_0013C770((SubListItemBase*)self, 0);
        if ((short)flag > 0) {
            __vec_ctor(self);
        }
    }
    return self;
}

int func_0013CAB0(SubListBuildItem *self) {
    return self->m_field74;
}

int func_0013CAC0(SubListBuildItem *self) {
    return self->m_fieldA0;
}

int func_0013CAD0(SubListBuildItem *self) {
    return self->m_fieldA4;
}

int func_0013CAE0(SubListBuildItem *self) {
    return self->m_field80;
}

int func_0013CAF0(SubListBuildItem *self) {
    return self->m_field84;
}

int func_0013CB00(SubListBuildItem *self) {
    return self->m_targets[0];
}

int func_0013CB10(SubListBuildItem *self, int idx) {
    if (idx <= 0 || idx > 2) {
        return -1;
    }
    return self->m_targets[idx];
}

int func_0013CB50(SubListBuildItem *self) {
    return self->m_fieldA8;
}

void func_0013CB60(SubListBuildItem *self, int val) {
    self->m_fieldA0 = val;
}

void func_0013CB70(SubListBuildItem *self, int val) {
    self->m_fieldA4 = val;
}

void func_0013CB80(SubListBuildItem *self, int val) {
    self->m_field80 = val;
}

void func_0013CB90(SubListBuildItem *self) {
    self->m_field80++;
}

void func_0013CBA0(SubListBuildItem *self) {
    self->m_field80--;
    if (self->m_field80 < 0) {
        self->m_field80 = 0;
    }
}

int func_0013CBD0(SubListBuildItem *self) {
    return self->m_field94;
}

void func_0013CBE0(SubListBuildItem *self) {
    self->m_field94++;
}

void func_0013CBF0(SubListBuildItem *self, int val) {
    self->m_field94 = val;
}

int func_0013CC00(SubListBuildItem *self) {
    return self->m_field98;
}

void func_0013CC10(SubListBuildItem *self, int val) {
    self->m_field98 = val;
}

int func_0013CC20(SubListBuildItem *self) {
    return self->m_field9C;
}

void func_0013CC30(SubListBuildItem *self, int val) {
    self->m_field9C = val;
}

unsigned char func_0013CC40(SubListBuildItem *self) {
    return self->m_fieldB0;
}

void func_0013CC50(SubListBuildItem *self, unsigned char val) {
    self->m_fieldB0 = val;
}

}
