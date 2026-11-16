/* Function: func_0012C368 (0x0012C368 - 0x0012C384)
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
asm s32 func_0012C368(s32 a0, s32 a1, s32 a2, s32 a3) {
    .word 0x27bdfff0 // 0012C368:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012C36C:  sd $ra, ($sp)
    .word 0x0c04b0ac // 0012C370:  jal 0x12c2b0
    .word 0x0000402d // 0012C374:  move $t0, $zero
    .word 0xdfbf0000 // 0012C378:  ld $ra, ($sp)
    .word 0x03e00008 // 0012C37C:  jr $ra
    .word 0x27bd0010 // 0012C380:  addiu $sp, $sp, 0x10
}
#else

s32 func_0012C2B0(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0);

s32 func_0012C368(s32 a0, s32 a1, s32 a2, s32 a3) {
    return func_0012C2B0(a0, a1, a2, a3, 0);
}

#endif

}
