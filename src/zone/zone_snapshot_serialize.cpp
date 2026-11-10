#pragma once
#pragma exceptions off

#include "zone_snapshot_serialize.h"

extern "C" {
void *func_1143F8(int pool, int size);
void *func_117AF8(void *dst, void *src, int size);
int func_226F70(void *stream, void *src, int size);
void func_229940(void *sub, void *stream);
void func_116F68(void *ptr);

#if defined(__mips__)
asm void func_001CDBB0(void *self, void *stream) {
    .word 0x27BDFFC0 /* 001CDBB0 addiu      $sp, $sp, -0x40 */
    .word 0x7FBF0030 /* 001CDBB4 sq         $ra, 0x30($sp) */
    .word 0x7FB20020 /* 001CDBB8 sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001CDBBC sq         $s1, 0x10($sp) */
    .word 0x70809628 /* 001CDBC0 paddub     $s2, $a0, $zero */
    .word 0x70A08E28 /* 001CDBC4 paddub     $s1, $a1, $zero */
    .word 0x24040001 /* 001CDBC8 addiu      $a0, $zero, 0x1 */
    .word 0x34059158 /* 001CDBCC ori        $a1, $zero, 0x9158 */
    jal func_1143F8
    .word 0x7FB00000 /* 001CDBD4 sq        $s0, 0x0($sp) */
    .word 0x70408628 /* 001CDBD8 paddub     $s0, $v0, $zero */
    .word 0x72002628 /* 001CDBDC paddub     $a0, $s0, $zero */
    .word 0x72402E28 /* 001CDBE0 paddub     $a1, $s2, $zero */
    jal func_117AF8
    .word 0x34069158 /* 001CDBE8 ori       $a2, $zero, 0x9158 */
    .word 0x2403FFFF /* 001CDBEC addiu      $v1, $zero, -0x1 */
    .word 0x10000014 /* 001CDBF0 b          .L001CDC44 */
    .word 0x70002E28 /* 001CDBF4 paddub    $a1, $zero, $zero */
    .word 0x00051040 /* 001CDBF8 sll        $v0, $a1, 1 */
    .word 0x00451021 /* 001CDBFC addu       $v0, $v0, $a1 */
    .word 0x00021080 /* 001CDC00 sll        $v0, $v0, 2 */
    .word 0x00451021 /* 001CDC04 addu       $v0, $v0, $a1 */
    .word 0x00023140 /* 001CDC08 sll        $a2, $v0, 5 */
    .word 0x02462021 /* 001CDC0C addu       $a0, $s2, $a2 */
    .word 0x9082008C /* 001CDC10 lbu        $v0, 0x8C($a0) */
    .word 0x5040000B /* 001CDC14 beql       $v0, $zero, .L001CDC44 */
    .word 0x24A50001 /* 001CDC18 addiu     $a1, $a1, 0x1 */
    .word 0x8C8200B0 /* 001CDC1C lw         $v0, 0xB0($a0) */
    .word 0x50400006 /* 001CDC20 beql       $v0, $zero, .L001CDC3C */
    .word 0x02061021 /* 001CDC24 addu      $v0, $s0, $a2 */
    .word 0x84440008 /* 001CDC28 lh         $a0, 0x8($v0) */
    .word 0x02061021 /* 001CDC2C addu       $v0, $s0, $a2 */
    .word 0x10000003 /* 001CDC30 b          .L001CDC40 */
    .word 0xAC4400B0 /* 001CDC34 sw        $a0, 0xB0($v0) */
    .word 0x02061021 /* 001CDC38 addu       $v0, $s0, $a2 */
    .word 0xAC4300B0 /* 001CDC3C sw         $v1, 0xB0($v0) */
    .word 0x24A50001 /* 001CDC40 addiu      $a1, $a1, 0x1 */
    .word 0x28A20020 /* 001CDC44 slti       $v0, $a1, 0x20 */
    .word 0x1440FFEC /* 001CDC48 bnez       $v0, .L001CDBFC */
    .word 0x00051040 /* 001CDC4C sll       $v0, $a1, 1 */
    .word 0x2403FFFF /* 001CDC50 addiu      $v1, $zero, -0x1 */
    .word 0x10000014 /* 001CDC54 b          .L001CDCA8 */
    .word 0x70003628 /* 001CDC58 paddub    $a2, $zero, $zero */
    .word 0x00061100 /* 001CDC5C sll        $v0, $a2, 4 */
    .word 0x00462023 /* 001CDC60 subu       $a0, $v0, $a2 */
    .word 0x00041080 /* 001CDC64 sll        $v0, $a0, 2 */
    .word 0x00441023 /* 001CDC68 subu       $v0, $v0, $a0 */
    .word 0x00022940 /* 001CDC6C sll        $a1, $v0, 5 */
    .word 0x02451021 /* 001CDC70 addu       $v0, $s2, $a1 */
    .word 0x8C4434B0 /* 001CDC74 lw         $a0, 0x34B0($v0) */
    .word 0x50800009 /* 001CDC78 beql       $a0, $zero, .L001CDCA0 */
    .word 0x02051021 /* 001CDC7C addu      $v0, $s0, $a1 */
    .word 0x9042348C /* 001CDC80 lbu        $v0, 0x348C($v0) */
    .word 0x10400005 /* 001CDC84 beqz       $v0, .L001CDC9C */
    .word 0x00000000 /* 001CDC88 nop */
    .word 0x84840008 /* 001CDC8C lh         $a0, 0x8($a0) */
    .word 0x02051021 /* 001CDC90 addu       $v0, $s0, $a1 */
    .word 0x10000003 /* 001CDC94 b          .L001CDCA4 */
    .word 0xAC4434B0 /* 001CDC98 sw        $a0, 0x34B0($v0) */
    .word 0x02051021 /* 001CDC9C addu       $v0, $s0, $a1 */
    .word 0xAC4334B0 /* 001CDCA0 sw         $v1, 0x34B0($v0) */
    .word 0x24C60001 /* 001CDCA4 addiu      $a2, $a2, 0x1 */
    .word 0x28C20010 /* 001CDCA8 slti       $v0, $a2, 0x10 */
    .word 0x1440FFEC /* 001CDCAC bnez       $v0, .L001CDC60 */
    .word 0x00061100 /* 001CDCB0 sll       $v0, $a2, 4 */
    .word 0x72202628 /* 001CDCB4 paddub     $a0, $s1, $zero */
    .word 0x72002E28 /* 001CDCB8 paddub     $a1, $s0, $zero */
    jal func_226F70
    .word 0x34069158 /* 001CDCC0 ori       $a2, $zero, 0x9158 */
    .word 0x3C010001 /* 001CDCC4 lui        $at, (0x10000 >> 16) */
    .word 0x02410821 /* 001CDCC8 addu       $at, $s2, $at */
    .word 0x8C248EE4 /* 001CDCCC lw         $a0, -0x711C($at) */
    jal func_229940
    .word 0x72202E28 /* 001CDCD4 paddub    $a1, $s1, $zero */
    jal func_116F68
    .word 0x72002628 /* 001CDCDC paddub    $a0, $s0, $zero */
    .word 0x7BBF0030 /* 001CDCE0 lq         $ra, 0x30($sp) */
    .word 0x7BB20020 /* 001CDCE4 lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001CDCE8 lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001CDCEC lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001CDCF0 jr         $ra */
    .word 0x27BD0040 /* 001CDCF4 addiu     $sp, $sp, 0x40 */
}
#else
struct EntityRef {
    char pad_0[8];
    short id;
};

struct ZoneLayout {
    char pad_0[0x8EE4];
    void *f_8EE4;
};

void func_001CDBB0(void *self, void *stream) {
    char *snapshot = (char *)func_1143F8(1, 0x9158);
    func_117AF8(snapshot, self, 0x9158);

    for (int i = 0; i < 32; i++) {
        int offset = i * 416;
        char *src_entry = (char *)self + offset;
        char *dst_entry = snapshot + offset;

        if (*(unsigned char *)(src_entry + 0x8C) != 0) {
            EntityRef *entity = *(EntityRef **)(src_entry + 0xB0);
            if (entity != 0) {
                *(int *)(dst_entry + 0xB0) = (int)entity->id;
            } else {
                *(int *)(dst_entry + 0xB0) = -1;
            }
        }
    }

    for (int j = 0; j < 16; j++) {
        int offset = j * 1440;
        char *src_entry = (char *)self + offset;
        char *dst_entry = snapshot + offset;

        EntityRef *entity = *(EntityRef **)(src_entry + 0x34B0);
        if (entity != 0) {
            if (*(unsigned char *)(dst_entry + 0x348C) != 0) {
                *(int *)(dst_entry + 0x34B0) = (int)entity->id;
            } else {
                *(int *)(dst_entry + 0x34B0) = -1;
            }
        }
    }

    func_226F70(stream, snapshot, 0x9158);

    ZoneLayout *zm = (ZoneLayout *)self;
    func_229940(zm->f_8EE4, stream);

    func_116F68(snapshot);
}
#endif
}
