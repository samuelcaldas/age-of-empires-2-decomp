/* Function: func_0012C450 (0x0012C450 - 0x0012C4D4)
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
asm s32 func_0012C450(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1) {
    .word 0x27bdff90 // 0012C450:  addiu $sp, $sp, -0x70
    .word 0xffb20020 // 0012C454:  sd $s2, 0x20($sp)
    .word 0xffb00000 // 0012C458:  sd $s0, ($sp)
    .word 0x0080902d // 0012C45C:  move $s2, $a0
    .word 0x00a0802d // 0012C460:  move $s0, $a1
    .word 0xffb50050 // 0012C464:  sd $s5, 0x50($sp)
    .word 0xffb40040 // 0012C468:  sd $s4, 0x40($sp)
    .word 0x0100a82d // 0012C46C:  move $s5, $t0
    .word 0xffb30030 // 0012C470:  sd $s3, 0x30($sp)
    .word 0x00e0a02d // 0012C474:  move $s4, $a3
    .word 0xffb10010 // 0012C478:  sd $s1, 0x10($sp)
    .word 0x00c0982d // 0012C47C:  move $s3, $a2
    .word 0x0120882d // 0012C480:  move $s1, $t1
    .word 0xffbf0060 // 0012C484:  sd $ra, 0x60($sp)
    .word 0x0c04afb0 // 0012C488:  jal 0x12bec0
    .word 0x0200202d // 0012C48C:  move $a0, $s0
    .word 0x0240202d // 0012C490:  move $a0, $s2
    .word 0x0200282d // 0012C494:  move $a1, $s0
    .word 0x0260302d // 0012C498:  move $a2, $s3
    .word 0x0220382d // 0012C49C:  move $a3, $s1
    .word 0x0280402d // 0012C4A0:  move $t0, $s4
    .word 0x02a0482d // 0012C4A4:  move $t1, $s5
    .word 0x0c04b0ea // 0012C4A8:  jal 0x12c3a8
    .word 0x0040502d // 0012C4AC:  move $t2, $v0
    .word 0xdfbf0060 // 0012C4B0:  ld $ra, 0x60($sp)
    .word 0xdfb50050 // 0012C4B4:  ld $s5, 0x50($sp)
    .word 0xdfb40040 // 0012C4B8:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 0012C4BC:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012C4C0:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012C4C4:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012C4C8:  ld $s0, ($sp)
    .word 0x03e00008 // 0012C4CC:  jr $ra
    .word 0x27bd0070 // 0012C4D0:  addiu $sp, $sp, 0x70
}
#else

void *func_0012BEC0(s32 a0);
s32 func_0012C3A8(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, void *t2);

s32 func_0012C450(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1) {
    void *req = func_0012BEC0(a1);
    return func_0012C3A8(a0, a1, a2, t1, a3, t0, req);
}

#endif

}
