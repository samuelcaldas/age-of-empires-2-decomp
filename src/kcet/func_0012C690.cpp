/* Function: func_0012C690 (0x0012C690 - 0x0012C6AC)
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
asm void func_0012C690(s32 a0) {
    .word 0x27bdfff0 // 0012C690:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012C694:  sd $ra, ($sp)
    .word 0x0c04b1b4 // 0012C698:  jal 0x12c6d0
    .word 0x0000282d // 0012C69C:  move $a1, $zero
    .word 0xdfbf0000 // 0012C6A0:  ld $ra, ($sp)
    .word 0x03e00008 // 0012C6A4:  jr $ra
    .word 0x27bd0010 // 0012C6A8:  addiu $sp, $sp, 0x10
}
#else

void func_0012C6D0(s32 a0, s32 a1);

void func_0012C690(s32 a0) {
    func_0012C6D0(a0, 0);
}

#endif

}
