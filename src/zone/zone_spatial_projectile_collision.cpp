#include "zone_spatial_projectile_collision.h"

extern "C" {
void *func_100850(unsigned int size);
void func_001ECFC0(void *self);
void func_001DB890(void *self, void *target_pos, void *cur_pos, int a3, int t0, int t1, float f12);
float func_3675D0(void *obj);
void func_1ED050(void *list, void *target, int zero, float f12, float f13);
void func_001ECFD0(void *list, int flag);
extern void *D_938FD0[];
extern int D_004E324C;

#if defined(__mips__)
asm void *func_001D8900(ProjectileMotion *self, float tx, float ty, float tz) {
    .word 0x27BDFF80 /* 001D8900: addiu	sp,sp,-128 */
    .word 0x44800800 /* 001D8904: mtc1	zero,$f1 */
    .word 0x7FBF0050 /* 001D8908: sq	ra,80(sp) */
    .word 0x7FB30040 /* 001D890C: sq	s3,64(sp) */
    .word 0x7FB20030 /* 001D8910: sq	s2,48(sp) */
    .word 0x7FB10020 /* 001D8914: sq	s1,32(sp) */
    .word 0x7FB00010 /* 001D8918: sq	s0,16(sp) */
    .word 0xE7B60008 /* 001D891C: swc1	$f22,8(sp) */
    .word 0xE7B50004 /* 001D8920: swc1	$f21,4(sp) */
    .word 0xE7B40000 /* 001D8924: swc1	$f20,0(sp) */
    .word 0x8C820004 /* 001D8928: lw	v0,4(a0) */
    .word 0x46006586 /* 001D892C: mov.s	$f22,$f12 */
    .word 0x46006D46 /* 001D8930: mov.s	$f21,$f13 */
    .word 0x46007506 /* 001D8934: mov.s	$f20,$f14 */
    .word 0xC4400020 /* 001D8938: lwc1	$f0,32(v0) */
    .word 0x46010036 /* 001D893C: c.le.s	$f0,$f1 */
    .word 0x00000000 /* 001D8940: nop */
    .word 0x45010006 /* 001D8944: bc1t	60 <func_001D8900+0x60> */
    .word 0x70809628 /* 001D8948: paddub	s2,a0,zero */
    .word 0xC4400024 /* 001D894C: lwc1	$f0,36(v0) */
    .word 0x46010036 /* 001D8950: c.le.s	$f0,$f1 */
    .word 0x00000000 /* 001D8954: nop */
    .word 0x45000004 /* 001D8958: bc1f	6c <func_001D8900+0x6c> */
    .word 0x24040004 /* 001D895C: li	a0,4 */
    .word 0x10000047 /* 001D8960: b	180 <func_001D8900+0x180> */
    .word 0x70001628 /* 001D8964: paddub	v0,zero,zero */
    .word 0x24040004 /* 001D8968: li	a0,4 */
    jal        func_100850 /* 001D896C */
    .word 0x00000000 /* 001D8970: nop */
    .word 0x10400003 /* 001D8974: beqz	v0,84 <func_001D8900+0x84> */
    .word 0x70408628 /* 001D8978: paddub	s0,v0,zero */
    jal        func_001ECFC0 /* 001D897C */
    .word 0x72002628 /* 001D8980: paddub	a0,s0,zero */
    .word 0xE7B60060 /* 001D8984: swc1	$f22,96(sp) */
    .word 0xE7B40064 /* 001D8988: swc1	$f20,100(sp) */
    .word 0xE7B50068 /* 001D898C: swc1	$f21,104(sp) */
    .word 0xC6420048 /* 001D8990: lwc1	$f2,72(s2) */
    .word 0xC641004C /* 001D8994: lwc1	$f1,76(s2) */
    .word 0xC6400044 /* 001D8998: lwc1	$f0,68(s2) */
    .word 0x3C023F80 /* 001D899C: lui	v0,0x3f80 */
    .word 0x44826000 /* 001D89A0: mtc1	v0,$f12 */
    .word 0x27A50060 /* 001D89A4: addiu	a1,sp,96 */
    .word 0x27A60070 /* 001D89A8: addiu	a2,sp,112 */
    .word 0xE7A00070 /* 001D89AC: swc1	$f0,112(sp) */
    .word 0xE7A10074 /* 001D89B0: swc1	$f1,116(sp) */
    .word 0x72402628 /* 001D89B4: paddub	a0,s2,zero */
    .word 0xE7A20078 /* 001D89B8: swc1	$f2,120(sp) */
    .word 0x70003E28 /* 001D89BC: paddub	a3,zero,zero */
    .word 0x70004628 /* 001D89C0: paddub	t0,zero,zero */
    jal        func_001DB890 /* 001D89C4 */
    .word 0x70004E28 /* 001D89C8: paddub	t1,zero,zero */
    .word 0x10000020 /* 001D89CC: b	150 <func_001D8900+0x150> */
    .word 0x70008E28 /* 001D89D0: paddub	s1,zero,zero */
    la         v0, D_938FD0 /* 001D89D4 */
    .word 0x00111880 /* 001D89DC: sll	v1,s1,0x2 */
    .word 0x00431021 /* 001D89E0: addu	v0,v0,v1 */
    .word 0x8C420000 /* 001D89E4: lw	v0,0(v0) */
    .word 0x8C530008 /* 001D89E8: lw	s3,8(v0) */
    .word 0x52600018 /* 001D89EC: beqzl	s3,150 <func_001D8900+0x150> */
    .word 0x26310001 /* 001D89F0: addiu	s1,s1,1 */
    .word 0xC661004C /* 001D89F4: lwc1	$f1,76(s3) */
    .word 0xC640004C /* 001D89F8: lwc1	$f0,76(s2) */
    .word 0x72602628 /* 001D89FC: paddub	a0,s3,zero */
    jal        func_3675D0 /* 001D8A00 */
    .word 0x46000D01 /* 001D8A04: sub.s	$f20,$f1,$f0 */
    .word 0x46000007 /* 001D8A08: neg.s	$f0,$f0 */
    .word 0x4600A034 /* 001D8A0C: c.lt.s	$f20,$f0 */
    .word 0x00000000 /* 001D8A10: nop */
    .word 0x4501000D /* 001D8A14: bc1t	14c <func_001D8900+0x14c> */
    .word 0x00000000 /* 001D8A18: nop */
    jal        func_3675D0 /* 001D8A1C */
    .word 0x72402628 /* 001D8A20: paddub	a0,s2,zero */
    .word 0x4600A036 /* 001D8A24: c.le.s	$f20,$f0 */
    .word 0x00000000 /* 001D8A28: nop */
    .word 0x45000007 /* 001D8A2C: bc1f	14c <func_001D8900+0x14c> */
    .word 0x00000000 /* 001D8A30: nop */
    .word 0x44806800 /* 001D8A34: mtc1	zero,$f13 */
    .word 0x72602E28 /* 001D8A38: paddub	a1,s3,zero */
    .word 0x72002628 /* 001D8A3C: paddub	a0,s0,zero */
    .word 0x46006B06 /* 001D8A40: mov.s	$f12,$f13 */
    jal        func_1ED050 /* 001D8A44 */
    .word 0x70003628 /* 001D8A48: paddub	a2,zero,zero */
    .word 0x26310001 /* 001D8A4C: addiu	s1,s1,1 */
    .word 0x8F828A8C /* 001D8A50: lw	v0,-30068(gp) */
    .word 0x0222102A /* 001D8A54: slt	v0,s1,v0 */
    .word 0x1440FFDE /* 001D8A58: bnez	v0,d4 <func_001D8900+0xd4> */
    .word 0x00000000 /* 001D8A5C: nop */
    .word 0x8E020000 /* 001D8A60: lw	v0,0(s0) */
    .word 0x14400006 /* 001D8A64: bnez	v0,180 <func_001D8900+0x180> */
    .word 0x72001628 /* 001D8A68: paddub	v0,s0,zero */
    .word 0x24050001 /* 001D8A6C: li	a1,1 */
    jal        func_001ECFD0 /* 001D8A70 */
    .word 0x72002628 /* 001D8A74: paddub	a0,s0,zero */
    .word 0x70008628 /* 001D8A78: paddub	s0,zero,zero */
    .word 0x72001628 /* 001D8A7C: paddub	v0,s0,zero */
    .word 0x7BBF0050 /* 001D8A80: lq	ra,80(sp) */
    .word 0x7BB30040 /* 001D8A84: lq	s3,64(sp) */
    .word 0x7BB20030 /* 001D8A88: lq	s2,48(sp) */
    .word 0x7BB10020 /* 001D8A8C: lq	s1,32(sp) */
    .word 0x7BB00010 /* 001D8A90: lq	s0,16(sp) */
    .word 0xC7B60008 /* 001D8A94: lwc1	$f22,8(sp) */
    .word 0xC7B50004 /* 001D8A98: lwc1	$f21,4(sp) */
    .word 0xC7B40000 /* 001D8A9C: lwc1	$f20,0(sp) */
    .word 0x03E00008 /* 001D8AA0: jr	ra */
    .word 0x27BD0080 /* 001D8AA4: addiu	sp,sp,128 */
}
#else
void *func_1ECFC0(void *self);
void func_1DB890(void *self, void *target_pos, void *cur_pos, int a3, int t0, int t1, float f12);
void func_1ECFD0(void *list, int flag);
extern void *D_00948FD0[];

struct ProjectileConfig {
    char pad[0x20];
    float radius_x;
    float radius_y;
};

struct CollisionTarget {
    char pad[8];
    void *entity;
};

struct ProjectileMotion {
    void **vtable;
    ProjectileConfig *config; // 0x4
    char pad_44[0x44 - 0x8];
    float x; // 0x44
    float y; // 0x48
    float z; // 0x4C
};

struct HitList {
    int count;
};

void *func_001D8900(ProjectileMotion *self, float tx, float ty, float tz) {
    if (self->config->radius_x <= 0.0f || self->config->radius_y <= 0.0f) {
        return 0;
    }

    HitList *list = (HitList *)func_100850(4);
    if (list != 0) {
        func_1ECFC0(list);
    }

    float target_pos[3];
    target_pos[0] = tx;
    target_pos[1] = tz;
    target_pos[2] = ty;

    float cur_pos[3];
    cur_pos[0] = self->x;
    cur_pos[1] = self->z;
    cur_pos[2] = self->y;

    func_1DB890(self, target_pos, cur_pos, 0, 0, 0, 1.0f);

    for (int i = 0; i < D_004E324C; i++) {
        CollisionTarget *target = (CollisionTarget *)D_00948FD0[i];
        void *ent = target->entity;
        if (ent == 0) {
            continue;
        }

        float ent_z = *(float *)((char *)ent + 0x4C);
        float diff = ent_z - self->z;
        float radius = func_3675D0(ent);
        if (diff < -radius) {
            continue;
        }

        float self_radius = func_3675D0(self);
        if (diff <= self_radius) {
            func_1ED050(list, ent, 0, 0.0f, 0.0f);
        }
    }

    if (list->count == 0) {
        func_1ECFD0(list, 1);
        list = 0;
    }

    return list;
}
#endif
}
