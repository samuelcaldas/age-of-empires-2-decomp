/* Function: func_0012C538 (0x0012C538 - 0x0012C594)
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
asm s32 func_0012C538(s32 a0, s32 a1) {
    .word 0x27bdffc0 // 0012C538:  addiu $sp, $sp, -0x40
    .word 0xffb20020 // 0012C53C:  sd $s2, 0x20($sp)
    .word 0xffb00000 // 0012C540:  sd $s0, ($sp)
    .word 0x00a0902d // 0012C544:  move $s2, $a1
    .word 0xffb10010 // 0012C548:  sd $s1, 0x10($sp)
    .word 0xffbf0030 // 0012C54C:  sd $ra, 0x30($sp)
    .word 0x0c04a7d6 // 0012C550:  jal 0x129f58
    .word 0x0080802d // 0012C554:  move $s0, $a0
    .word 0x0c04a7f4 // 0012C558:  jal 0x129fd0
    .word 0x0040882d // 0012C55C:  move $s1, $v0
    .word 0x0200202d // 0012C560:  move $a0, $s0
    .word 0x0240282d // 0012C564:  move $a1, $s2
    .word 0x0220402d // 0012C568:  move $t0, $s1
    .word 0x0040482d // 0012C56C:  move $t1, $v0
    .word 0x0000302d // 0012C570:  move $a2, $zero
    .word 0x0c04b114 // 0012C574:  jal 0x12c450
    .word 0x24070001 // 0012C578:  addiu $a3, $zero, 1
    .word 0xdfbf0030 // 0012C57C:  ld $ra, 0x30($sp)
    .word 0xdfb20020 // 0012C580:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012C584:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012C588:  ld $s0, ($sp)
    .word 0x03e00008 // 0012C58C:  jr $ra
    .word 0x27bd0040 // 0012C590:  addiu $sp, $sp, 0x40
}
#else

s32 func_00129F58(void);
s32 func_00129FD0(void);
s32 func_0012C450(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1);

s32 func_0012C538(s32 a0, s32 a1) {
    s32 v1 = func_00129F58();
    s32 v2 = func_00129FD0();
    return func_0012C450(a0, a1, 0, 1, v1, v2);
}

#endif

}
