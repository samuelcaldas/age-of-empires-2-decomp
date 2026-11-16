/* Function: func_0012C9C8 (0x0012C9C8 - 0x0012CAA0)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012C9C8(s32 a0) {
    .word 0x27bdffa0 // 0012C9C8:  addiu $sp, $sp, -0x60
    .word 0xffb00000 // 0012C9CC:  sd $s0, ($sp)
    .word 0x0080802d // 0012C9D0:  move $s0, $a0
    .word 0xffb20020 // 0012C9D4:  sd $s2, 0x20($sp)
    .word 0xffb10010 // 0012C9D8:  sd $s1, 0x10($sp)
    .word 0xffbf0050 // 0012C9DC:  sd $ra, 0x50($sp)
    .word 0x0000882d // 0012C9E0:  move $s1, $zero
    .word 0xffb40040 // 0012C9E4:  sd $s4, 0x40($sp)
    .word 0x0c04b3d6 // 0012C9E8:  jal 0x12cf58
    .word 0xffb30030 // 0012C9EC:  sd $s3, 0x30($sp)
    .word 0x0200202d // 0012C9F0:  move $a0, $s0
    .word 0x0c04b3f2 // 0012C9F4:  jal 0x12cfc8
    .word 0x0040902d // 0012C9F8:  move $s2, $v0
    .word 0x0c04a7f4 // 0012C9FC:  jal 0x129fd0
    .word 0x0040802d // 0012CA00:  move $s0, $v0
    .word 0x14400002 // 0012CA04:  bnez $v0, 0x12ca10
    .word 0x0000102d // 0012CA08:  move $v0, $zero
    .word 0x24020001 // 0012CA0C:  addiu $v0, $zero, 1
    .word 0x0040982d // 0012CA10:  move $s3, $v0
    .word 0x24140001 // 0012CA14:  addiu $s4, $zero, 1
    .word 0x10400005 // 0012CA18:  beqz $v0, 0x12ca30
    .word 0x00000000 // 0012CA1C:  nop 
    .word 0x1054000c // 0012CA20:  beq $v0, $s4, 0x12ca54
    .word 0x00000000 // 0012CA24:  nop 
    .word 0x10000010 // 0012CA28:  b 0x12ca6c
    .word 0x00000000 // 0012CA2C:  nop 
    .word 0x5200000e // 0012CA30:  beql $s0, $zero, 0x12ca6c
    .word 0x24020001 // 0012CA34:  addiu $v0, $zero, 1
    .word 0x0c04b312 // 0012CA38:  jal 0x12cc48
    .word 0x0200202d // 0012CA3C:  move $a0, $s0
    .word 0x0c04a3b2 // 0012CA40:  jal 0x128ec8
    .word 0x0040202d // 0012CA44:  move $a0, $v0
    .word 0x0040882d // 0012CA48:  move $s1, $v0
    .word 0x10000007 // 0012CA4C:  b 0x12ca6c
    .word 0x24020001 // 0012CA50:  addiu $v0, $zero, 1
    .word 0x12400005 // 0012CA54:  beqz $s2, 0x12ca6c
    .word 0x0000102d // 0012CA58:  move $v0, $zero
    .word 0x0c04b2e4 // 0012CA5C:  jal 0x12cb90
    .word 0x0240202d // 0012CA60:  move $a0, $s2
    .word 0x00028ac0 // 0012CA64:  sll $s1, $v0, 0xb
    .word 0x0000102d // 0012CA68:  move $v0, $zero
    .word 0x56200004 // 0012CA6C:  bnel $s1, $zero, 0x12ca80
    .word 0x0220102d // 0012CA70:  move $v0, $s1
    .word 0x1453ffe8 // 0012CA74:  bne $v0, $s3, 0x12ca18
    .word 0x00000000 // 0012CA78:  nop 
    .word 0x0220102d // 0012CA7C:  move $v0, $s1
    .word 0xdfbf0050 // 0012CA80:  ld $ra, 0x50($sp)
    .word 0xdfb40040 // 0012CA84:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 0012CA88:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012CA8C:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012CA90:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012CA94:  ld $s0, ($sp)
    .word 0x03e00008 // 0012CA98:  jr $ra
    .word 0x27bd0060 // 0012CA9C:  addiu $sp, $sp, 0x60
}
#else

s32 func_0012CF58(s32 a0);
s32 func_0012CFC8(s32 a0);
s32 func_00129FD0(void);
s32 func_0012CC48(s32 a0);
s32 func_00128EC8(s32 a0);
s32 func_0012CB90(s32 a0);

s32 func_0012C9C8(s32 a0) {
    s32 s2 = func_0012CF58(a0);
    s32 s0 = func_0012CFC8(a0);
    s32 mode = func_00129FD0() == 0 ? 1 : 0;
    s32 s1 = 0;

    for (s32 cur = mode; ; cur = 1) {
        if (cur == 0) {
            if (s0 != 0) {
                s1 = func_00128EC8(func_0012CC48(s0));
            }
        } else if (cur == 1) {
            if (s2 != 0) {
                s1 = func_0012CB90(s2) << 11;
            }
        }
        if (s1 != 0) {
            return s1;
        }
        if (s1 == mode) {
            break;
        }
    }
    return s1;
}

#endif

}
