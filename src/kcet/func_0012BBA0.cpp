/* Function: func_0012BBA0 (0x0012BBA0 - 0x0012BC0C)
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
asm s32 func_0012BBA0(void *a0) {
    .word 0x27bdffc0 // 0012BBA0:  addiu $sp, $sp, -0x40
    .word 0xffb00000 // 0012BBA4:  sd $s0, ($sp)
    .word 0xffb20020 // 0012BBA8:  sd $s2, 0x20($sp)
    .word 0xffb10010 // 0012BBAC:  sd $s1, 0x10($sp)
    .word 0xffbf0030 // 0012BBB0:  sd $ra, 0x30($sp)
    .word 0x0c04b3d6 // 0012BBB4:  jal 0x12cf58
    .word 0x0080802d // 0012BBB8:  move $s0, $a0
    .word 0x0040902d // 0012BBBC:  move $s2, $v0
    .word 0x0c04b40e // 0012BBC0:  jal 0x12d038
    .word 0x0200202d // 0012BBC4:  move $a0, $s0
    .word 0x16400005 // 0012BBC8:  bnez $s2, 0x12bbe0
    .word 0x0040882d // 0012BBCC:  move $s1, $v0
    .word 0x0051800b // 0012BBD0:  movn $s0, $v0, $s1
    .word 0x0200882d // 0012BBD4:  move $s1, $s0
    .word 0x10000003 // 0012BBD8:  b 0x12bbe8
    .word 0x2402ffff // 0012BBDC:  addiu $v0, $zero, -1
    .word 0x0c04b2d8 // 0012BBE0:  jal 0x12cb60
    .word 0x0240202d // 0012BBE4:  move $a0, $s2
    .word 0x0220202d // 0012BBE8:  move $a0, $s1
    .word 0x0c04aed4 // 0012BBEC:  jal 0x12bb50
    .word 0x0040282d // 0012BBF0:  move $a1, $v0
    .word 0xdfbf0030 // 0012BBF4:  ld $ra, 0x30($sp)
    .word 0xdfb20020 // 0012BBF8:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012BBFC:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012BC00:  ld $s0, ($sp)
    .word 0x03e00008 // 0012BC04:  jr $ra
    .word 0x27bd0040 // 0012BC08:  addiu $sp, $sp, 0x40
}
#else

s32 func_0012CF58(void *);
s32 func_0012D038(void *);
s32 func_0012CB60(s32);
s32 func_0012BB50(s32, s32);

s32 func_0012BBA0(void *a0) {
    s32 s2 = func_0012CF58(a0);
    s32 v0 = func_0012D038(a0);
    s32 s1;
    s32 a1;
    if (s2 != 0) {
        s1 = v0;
        a1 = func_0012CB60(s2);
    } else {
        s1 = (v0 != 0) ? v0 : (s32)a0;
        a1 = -1;
    }
    return func_0012BB50(s1, a1);
}

#endif

}
