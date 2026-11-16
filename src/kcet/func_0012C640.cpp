/* Function: func_0012C640 (0x0012C640 - 0x0012C664)
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
asm void func_0012C640(s32 a0, s32 a1) {
    .word 0x27bdfff0 // 0012C640:  addiu $sp, $sp, -0x10
    .word 0x00a0302d // 0012C644:  move $a2, $a1
    .word 0xffbf0000 // 0012C648:  sd $ra, ($sp)
    .word 0x0000282d // 0012C64C:  move $a1, $zero
    .word 0x0c04b166 // 0012C650:  jal 0x12c598
    .word 0x0000382d // 0012C654:  move $a3, $zero
    .word 0xdfbf0000 // 0012C658:  ld $ra, ($sp)
    .word 0x03e00008 // 0012C65C:  jr $ra
    .word 0x27bd0010 // 0012C660:  addiu $sp, $sp, 0x10
}
#else

void func_0012C598(s32 a0, s32 a1, s32 a2, s32 a3);

void func_0012C640(s32 a0, s32 a1) {
    func_0012C598(a0, 0, a1, 0);
}

#endif

}
