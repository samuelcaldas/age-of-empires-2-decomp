/* Function: func_0012C8E8 (0x0012C8E8 - 0x0012C904)
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
asm void func_0012C8E8(s32 a0, s32 a1, s32 a2) {
    .word 0x27bdfff0 // 0012C8E8:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012C8EC:  sd $ra, ($sp)
    .word 0x0c04b24a // 0012C8F0:  jal 0x12c928
    .word 0x0000382d // 0012C8F4:  move $a3, $zero
    .word 0xdfbf0000 // 0012C8F8:  ld $ra, ($sp)
    .word 0x03e00008 // 0012C8FC:  jr $ra
    .word 0x27bd0010 // 0012C900:  addiu $sp, $sp, 0x10
}
#else

void func_0012C928(s32 a0, s32 a1, s32 a2, s32 a3);

void func_0012C8E8(s32 a0, s32 a1, s32 a2) {
    func_0012C928(a0, a1, a2, 0);
}

#endif

}
