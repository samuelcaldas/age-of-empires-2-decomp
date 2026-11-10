#pragma once
#pragma exceptions off

#include "zone_spatial_grid_set_string.h"

extern "C" {
int func_0011ACD0(const char *str);
void *func_1143F8(int count, int elem_size);
void func_116F68(void *ptr);
char *func_117AF8(char *dst, const char *src);

#if defined(__mips__)
asm void func_001EB850(void *self_ptr, const char *new_str) {
    .word 0x27BDFFC0 /* 001EB850 addiu      $sp, $sp, -0x40 */
    .word 0x7FBF0030 /* 001EB854 sq         $ra, 0x30($sp) */
    .word 0x7FB20020 /* 001EB858 sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* 001EB85C sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* 001EB860 sq         $s0, 0x0($sp) */
    .word 0x70809628 /* 001EB864 paddub     $s2, $a0, $zero */
    .word 0x8C840000 /* 001EB868 lw         $a0, 0x0($a0) */
    .word 0x10800004 /* 001EB86C beqz       $a0, .L001EB880 */
    .word 0x70A08E28 /* 001EB870 paddub     $s1, $a1, $zero */
    jal func_116F68
    .word 0x00000000 /* 001EB878 nop */
    .word 0xAE400000 /* 001EB87C sw         $zero, 0x0($s2) */
/* .L001EB880: */
    .word 0x1220000C /* 001EB880 beqz       $s1, .L001EB8B4 */
    .word 0x00000000 /* 001EB884 nop */
    jal func_0011ACD0
    .word 0x72202628 /* 001EB88C paddub     $a0, $s1, $zero */
    .word 0x24500001 /* 001EB890 addiu      $s0, $v0, 0x1 */
    .word 0x24050001 /* 001EB894 addiu      $a1, $zero, 0x1 */
    jal func_1143F8
    .word 0x72002628 /* 001EB89C paddub     $a0, $s0, $zero */
    .word 0xAE420000 /* 001EB8A0 sw         $v0, 0x0($s2) */
    .word 0x8E440000 /* 001EB8A4 lw         $a0, 0x0($s2) */
    .word 0x72202E28 /* 001EB8A8 paddub     $a1, $s1, $zero */
    jal func_117AF8
    .word 0x72003628 /* 001EB8B0 paddub     $a2, $s0, $zero */
/* .L001EB8B4: */
    .word 0x7BBF0030 /* 001EB8B4 lq         $ra, 0x30($sp) */
    .word 0x7BB20020 /* 001EB8B8 lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* 001EB8BC lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 001EB8C0 lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 001EB8C4 jr         $ra */
    .word 0x27BD0040 /* 001EB8C8 addiu      $sp, $sp, 0x40 */
}
#else
struct StringContainer {
    char *str;
};

void func_001EB850(void *self_ptr, const char *new_str) {
    StringContainer *self = (StringContainer *)self_ptr;
    if (self->str != 0) {
        func_116F68(self->str);
        self->str = 0;
    }
    if (new_str != 0) {
        int len = func_0011ACD0(new_str) + 1;
        self->str = (char *)func_1143F8(len, 1);
        func_117AF8(self->str, new_str);
    }
}
#endif
}
