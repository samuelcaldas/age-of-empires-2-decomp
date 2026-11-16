/* Function: func_0012C908 (0x0012C908 - 0x0012C924)
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
asm void func_0012C908(s32 a0, s32 a1, s32 a2) {
    .word 0x27bdfff0 // 0012C908:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012C90C:  sd $ra, ($sp)
    .word 0x0c04b24a // 0012C910:  jal 0x12c928
    .word 0x24070001 // 0012C914:  addiu $a3, $zero, 1
    .word 0xdfbf0000 // 0012C918:  ld $ra, ($sp)
    .word 0x03e00008 // 0012C91C:  jr $ra
    .word 0x27bd0010 // 0012C920:  addiu $sp, $sp, 0x10
}
#else

void func_0012C928(s32 a0, s32 a1, s32 a2, s32 a3);

void func_0012C908(s32 a0, s32 a1, s32 a2) {
    func_0012C928(a0, a1, a2, 1);
}

#endif

}
