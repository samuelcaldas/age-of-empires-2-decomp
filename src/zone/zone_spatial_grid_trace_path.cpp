#pragma exceptions off

#include "zone_spatial_grid_trace_path.h"

extern "C" {
int func_1E5380(void *self, int index);

#if defined(__mips__)
asm void func_001E5230(GridBuffer *self, void *point, int insert_idx, int val) {
    .word 0x27BDFFB0 /* 001E5230: addiu $sp, $sp, -0x50 */
    .word 0x7FBF0040 /* 001E5234: sq $ra, 0x40($sp) */
    .word 0x7FB30030 /* 001E5238: sq $s3, 0x30($sp) */
    .word 0x7FB20020 /* 001E523C: sq $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001E5240: sq $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001E5244: sq $s0, 0x0($sp) */
    .word 0x8C820000 /* 001E5248: lw $v0, 0x0($a0) */
    .word 0x70A09628 /* 001E524C: paddub $s2, $a1, $zero */
    .word 0x70C08E28 /* 001E5250: paddub $s1, $a2, $zero */
    .word 0x70E08628 /* 001E5254: paddub $s0, $a3, $zero */
    .word 0x70809E28 /* 001E5258: paddub $s3, $a0, $zero */
    jal func_1E5380
    .word 0x24450001 /* 001E5260: addiu $a1, $v0, 0x1 */
    .word 0x16200003 /* 001E5264: bnez $s1, lbl_1E5274 */
    .word 0x00000000 /* 001E5268: nop */
    .word 0x8E630000 /* 001E526C: lw $v1, 0x0($s3) */
    .word 0x2471FFFF /* 001E5270: addiu $s1, $v1, -0x1 */
lbl_1E5274:
    .word 0x8E630000 /* 001E5274: lw $v1, 0x0($s3) */
    .word 0x1000000E /* 001E5278: b lbl_1E52B4 */
    .word 0x2466FFFF /* 001E527C: addiu $a2, $v1, -0x1 */
lbl_1E5280:
    .word 0x8E630004 /* 001E5280: lw $v1, 0x4($s3) */
    .word 0x000628C0 /* 001E5284: sll $a1, $a2, 3 */
    .word 0x00062080 /* 001E5288: sll $a0, $a2, 2 */
    .word 0x24C6FFFF /* 001E528C: addiu $a2, $a2, -0x1 */
    .word 0x00651821 /* 001E5290: addu $v1, $v1, $a1 */
    .word 0xC461FFF8 /* 001E5294: lwc1 $f1, -0x8($v1) */
    .word 0xC460FFFC /* 001E5298: lwc1 $f0, -0x4($v1) */
    .word 0xE4610000 /* 001E529C: swc1 $f1, 0x0($v1) */
    .word 0xE4600004 /* 001E52A0: swc1 $f0, 0x4($v1) */
    .word 0x8E63000C /* 001E52A4: lw $v1, 0xC($s3) */
    .word 0x00642021 /* 001E52A8: addu $a0, $v1, $a0 */
    .word 0x8C83FFFC /* 001E52AC: lw $v1, -0x4($a0) */
    .word 0xAC830000 /* 001E52B0: sw $v1, 0x0($a0) */
lbl_1E52B4:
    .word 0x0226082A /* 001E52B4: slt $at, $s1, $a2 */
    .word 0x1420FFF1 /* 001E52B8: bnez $at, lbl_1E5280 */
    .word 0x00000000 /* 001E52BC: nop */
    .word 0x8E630004 /* 001E52C0: lw $v1, 0x4($s3) */
    .word 0x001128C0 /* 001E52C4: sll $a1, $s1, 3 */
    .word 0xC6410000 /* 001E52C8: lwc1 $f1, 0x0($s2) */
    .word 0xC6400004 /* 001E52CC: lwc1 $f0, 0x4($s2) */
    .word 0x00112080 /* 001E52D0: sll $a0, $s1, 2 */
    .word 0x00651821 /* 001E52D4: addu $v1, $v1, $a1 */
    .word 0xE4610000 /* 001E52D8: swc1 $f1, 0x0($v1) */
    .word 0xE4600004 /* 001E52DC: swc1 $f0, 0x4($v1) */
    .word 0x8E63000C /* 001E52E0: lw $v1, 0xC($s3) */
    .word 0x00641821 /* 001E52E4: addu $v1, $v1, $a0 */
    .word 0xAC620000 /* 001E52E8: sw $s0, 0x0($v1) */
    .word 0x7BBD0040 /* 001E52EC: lq $ra, 0x40($sp) */
    .word 0x7BB30030 /* 001E52F0: lq $s3, 0x30($sp) */
    .word 0x7BB20020 /* 001E52F4: lq $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001E52F8: lq $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001E52FC: lq $s0, 0x0($sp) */
    .word 0x03E00008 /* 001E5300: jr $ra */
    .word 0x27BD0050 /* 001E5304: addiu $sp, $sp, 0x50 */
}
#else
struct Vec2f {
    float x;
    float y;
};

struct GridBuffer {
    int count;          // 0x00
    Vec2f *buf_vec;     // 0x04
    int capacity;       // 0x08
    int *buf_int;       // 0x0C
};

void func_001E5230(GridBuffer *self, void *point, int insert_idx, int val) {
    func_1E5380(self, self->count + 1);
    if (insert_idx == 0) {
        insert_idx = self->count - 1;
    }

    int j = self->count - 1;
    while (insert_idx < j) {
        self->buf_vec[j] = self->buf_vec[j - 1];
        self->buf_int[j] = self->buf_int[j - 1];
        j--;
    }

    self->buf_vec[insert_idx] = *(Vec2f *)point;
    self->buf_int[insert_idx] = val;
}
#endif
}
