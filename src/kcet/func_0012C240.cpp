/* Function: func_0012C240 (0x0012C240 - 0x0012C2B0)
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
asm s32 func_0012C240(s32 a0, s32 a1, s32 a2) {
    .word 0x27bdffb0 // 0012C240:  addiu $sp, $sp, -0x50
    .word 0xffb30030 // 0012C244:  sd $s3, 0x30($sp)
    .word 0xffb20020 // 0012C248:  sd $s2, 0x20($sp)
    .word 0x00c0982d // 0012C24C:  move $s3, $a2
    .word 0xffb10010 // 0012C250:  sd $s1, 0x10($sp)
    .word 0x00a0902d // 0012C254:  move $s2, $a1
    .word 0xffb00000 // 0012C258:  sd $s0, ($sp)
    .word 0xffbf0040 // 0012C25C:  sd $ra, 0x40($sp)
    .word 0x0c04a7d6 // 0012C260:  jal 0x129f58
    .word 0x0080882d // 0012C264:  move $s1, $a0
    .word 0x0c04a7f4 // 0012C268:  jal 0x129fd0
    .word 0x0040802d // 0012C26C:  move $s0, $v0
    .word 0x0220202d // 0012C270:  move $a0, $s1
    .word 0x0240282d // 0012C274:  move $a1, $s2
    .word 0x0260302d // 0012C278:  move $a2, $s3
    .word 0x0200482d // 0012C27C:  move $t1, $s0
    .word 0x0040502d // 0012C280:  move $t2, $v0
    .word 0x0000382d // 0012C284:  move $a3, $zero
    .word 0x0000402d // 0012C288:  move $t0, $zero
    .word 0x0c04b04a // 0012C28C:  jal 0x12c128
    .word 0x0000582d // 0012C290:  move $t3, $zero
    .word 0xdfbf0040 // 0012C294:  ld $ra, 0x40($sp)
    .word 0xdfb30030 // 0012C298:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012C29C:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012C2A0:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012C2A4:  ld $s0, ($sp)
    .word 0x03e00008 // 0012C2A8:  jr $ra
    .word 0x27bd0050 // 0012C2AC:  addiu $sp, $sp, 0x50
}
#else

s32 func_00129F58(void);
s32 func_00129FD0(void);
s32 func_0012C128(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3);

s32 func_0012C240(s32 a0, s32 a1, s32 a2) {
    s32 s0 = func_00129F58();
    s32 v0 = func_00129FD0();
    return func_0012C128(a0, a1, a2, 0, 0, s0, v0, 0);
}

#endif

}
