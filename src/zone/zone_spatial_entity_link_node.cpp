#pragma exceptions off

#include "zone_spatial_entity_link_node.h"

extern "C" {
void func_1FE340(void *p0, void *p1, void *p2, void *p3, int p4, int p5, int p6, int p7);

#if defined(__mips__)
asm void func_001DDB70(SpatialEntity *self, void *node) {
    .word 0x27BDFFC0 /* 001DDB70: addiu $sp, $sp, -0x40 */
    .word 0x7FBF0010 /* 001DDB74: sq $ra, 0x10($sp) */
    .word 0xC4A20000 /* 001DDB78: lwc1 $f2, 0x0($a1) */
    .word 0xC4A10004 /* 001DDB7C: lwc1 $f1, 0x4($a1) */
    .word 0xC4A00008 /* 001DDB80: lwc1 $f0, 0x8($a1) */
    .word 0x71801628 /* 001DDB84: paddub $v0, $t0, $zero */
    .word 0x71A01E28 /* 001DDB88: paddub $v1, $t1, $zero */
    .word 0x70404E28 /* 001DDB8C: paddub $t1, $v0, $zero */
    .word 0x27A20020 /* 001DDB90: addiu $v0, $sp, 0x20 */
    .word 0xE4420000 /* 001DDB94: swc1 $f2, 0x0($v0) */
    .word 0xE4410004 /* 001DDB98: swc1 $f1, 0x4($v0) */
    .word 0xE4400008 /* 001DDB9C: swc1 $f0, 0x8($v0) */
    .word 0xC7A10020 /* 001DDBA0: lwc1 $f1, 0x20($sp) */
    .word 0xC7A00024 /* 001DDBA4: lwc1 $f0, 0x24($sp) */
    .word 0x70E04628 /* 001DDBA8: paddub $t0, $a3, $zero */
    .word 0x70C02E28 /* 001DDBAC: paddub $a1, $a2, $zero */
    .word 0x27A70030 /* 001DDBB0: addiu $a3, $sp, 0x30 */
    .word 0x46800860 /* 001DDBB4: cvt.s.w $f1, $f1 */
    .word 0x240B0001 /* 001DDBB8: addiu $t3, $zero, 0x1 */
    .word 0x24860090 /* 001DDBBC: addiu $a2, $a0, 0x90 */
    .word 0xE7A10030 /* 001DDBC0: swc1 $f1, 0x30($sp) */
    .word 0x46800020 /* 001DDBC4: cvt.s.w $f0, $f0 */
    .word 0xAFAC0034 /* 001DDBC8: sw $zero, 0x34($sp) */
    .word 0xE7A00038 /* 001DDBCC: swc1 $f0, 0x38($sp) */
    .word 0xFFAC0000 /* 001DDBD0: sd $t2, 0x0($sp) */
    .word 0x70605628 /* 001DDBD4: paddub $t2, $v1, $zero */
    jal func_1FE340
    .word 0xFFA00008 /* 001DDBDC: sd $zero, 0x8($sp) */
    .word 0x7BBD0010 /* 001DDBE0: lq $ra, 0x10($sp) */
    .word 0x03E00008 /* 001DDBE4: jr $ra */
    .word 0x27BD0040 /* 001DDBE8: addiu $sp, $sp, 0x40 */
}
#else
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Point2i {
    int x;
    int y;
    int z;
};

struct SpatialEntity {
    char pad[0x90];
    Vector3 pos;
};

void func_001DDB70(SpatialEntity *self, void *node) {
    Point2i *pt = (Point2i *)node;
    Vector3 converted;
    converted.x = (float)pt->x;
    converted.y = 0.0f;
    converted.z = (float)pt->y;

    func_1FE340(self, 0, (char *)self + 0x90, &converted, 0, 0, 0, 0);
}
#endif
}
