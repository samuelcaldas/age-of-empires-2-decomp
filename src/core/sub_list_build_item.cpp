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
void func_100670(void *self);

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

#if defined(__mips__)
asm void func_0013C960(SubListBuildItem *self, int p74, int a1, int a3,
                   int p78, int p7C, int p84, const char *str,
                   float f12, float f13, float f14,
                   int p88, int p8C, int p90, int pA8) {
    .word 0x27BDFFA0 /* addiu $sp, $sp, -0x60 */
    .word 0x46006C06 /* mov.s $f16, $f13 */
    .word 0x7FBF0050 /* sq $ra, 0x50($sp) */
    .word 0x7FB40040 /* sq $s4, 0x40($sp) */
    .word 0x7FB30030 /* sq $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq $s1, 0x10($sp) */
    .word 0x70A0A628 /* paddub $s4, $a1, $zero */
    .word 0x3C02BF80 /* lui $v0, (0xBF800000 >> 16) */
    .word 0x70C02E28 /* paddub $a1, $a2, $zero */
    .word 0x7FB00000 /* sq $s0, 0x0($sp) */
    .word 0x71009E28 /* paddub $s3, $t0, $zero */
    .word 0x44826800 /* mtc1 $v0, $f13 */
    .word 0x00000000 /* nop */
    .word 0x460063C6 /* mov.s $f15, $f12 */
    .word 0x46007446 /* mov.s $f17, $f14 */
    .word 0x2406FFFF /* addiu $a2, $zero, -0x1 */
    .word 0x46006B86 /* mov.s $f14, $f13 */
    .word 0x71209628 /* paddub $s2, $t1, $zero */
    .word 0x71408E28 /* paddub $s1, $t2, $zero */
    .word 0x70808628 /* paddub $s0, $a0, $zero */
    .word 0x71604628 /* paddub $t0, $t3, $zero */
    jal func_0013C6D0
    .word 0x46006B06 /* mov.s $f12, $f13 */
    .word 0xAE140074 /* sw $s4, 0x74($s0) */
    .word 0xAE130078 /* sw $s3, 0x78($s0) */
    .word 0xAE12007C /* sw $s2, 0x7C($s0) */
    .word 0xAE0000A0 /* sw $zero, 0xA0($s0) */
    .word 0xAE0000A4 /* sw $zero, 0xA4($s0) */
    .word 0xAE000080 /* sw $zero, 0x80($s0) */
    .word 0xAE110084 /* sw $s1, 0x84($s0) */
    .word 0x8FA40060 /* lw $a0, 0x60($sp) */
    .word 0x2403FFFF /* addiu $v1, $zero, -0x1 */
    .word 0xAE040088 /* sw $a0, 0x88($s0) */
    .word 0x8FA40078 /* lw $a0, 0x78($sp) */
    .word 0xAE0400A8 /* sw $a0, 0xA8($s0) */
    .word 0xAE00006C /* sw $zero, 0x6C($s0) */
    .word 0xAE000070 /* sw $zero, 0x70($s0) */
    .word 0xAE000094 /* sw $zero, 0x94($s0) */
    .word 0xAE030098 /* sw $v1, 0x98($s0) */
    .word 0xAE00009C /* sw $zero, 0x9C($s0) */
    .word 0xA20000B0 /* sb $zero, 0xB0($s0) */
    .word 0x8FA30068 /* lw $v1, 0x68($sp) */
    .word 0xAE03008C /* sw $v1, 0x8C($s0) */
    .word 0x8FA30070 /* lw $v1, 0x70($sp) */
    .word 0xAE030090 /* sw $v1, 0x90($s0) */
    .word 0x7BBF0050 /* lq $ra, 0x50($sp) */
    .word 0x7BB40040 /* lq $s4, 0x40($sp) */
    .word 0x7BB30030 /* lq $s3, 0x30($sp) */
    .word 0x7BB20020 /* lq $s2, 0x20($sp) */
    .word 0x7BB10010 /* lq $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq $s0, 0x0($sp) */
    .word 0x03E00008 /* jr $ra */
    .word 0x27BD0060 /* addiu $sp, $sp, 0x60 */
}
#else
void func_0013C960(SubListBuildItem *self, int p74, int a1, int a3,
                   int p78, int p7C, int p84, const char *str,
                   float f12, float f13, float f14,
                   int p88, int p8C, int p90, int pA8) {
    float d0 = -1.0f, d1 = -1.0f, d2 = -1.0f; func_0013C6D0((SubListItemBase*)self, a1, -1, a3, -1.0f, -1.0f, -1.0f, f12, f13, f14, str);
    self->m_field74 = p74;
    self->m_field78 = p78;
    self->m_field7C = p7C;
    self->m_fieldA0 = 0;
    self->m_fieldA4 = 0;
    self->m_field80 = 0;
    self->m_field84 = p84;
    self->m_targets[0] = p88;
    self->m_fieldA8 = pA8;
    self->m_field6C = 0;
    self->m_field70 = 0;
    self->m_field94 = 0;
    self->m_field98 = -1;
    self->m_field9C = 0;
    self->m_fieldB0 = 0;
    self->m_targets[1] = p8C;
    self->m_targets[2] = p90;
}
#endif

SubListBuildItem* func_0013CA40(SubListBuildItem *self, int flag) {
    if (self) {
        *(void**)self = D_4D75E0;
        self->m_field6C = 0;
        self->m_field70 = 0;
        func_0013C770((SubListItemBase*)self, 0);
        if ((short)flag > 0) {
            func_100670(self);
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
