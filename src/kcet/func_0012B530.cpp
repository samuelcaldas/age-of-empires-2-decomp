/* Function: func_0012B530 (0x0012B530 - 0x0012B54C)
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
asm void func_0012B530(void) {
    .word 0x27bdfff0 // addiu $sp, $sp, -0x10
    .word 0xffbf0000 // sd $ra, ($sp)
    .word 0x0c04ad1c // jal 0x12b470
    .word 0x24080006 // addiu $t0, $zero, 6
    .word 0xdfbf0000 // ld $ra, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0010 // addiu $sp, $sp, 0x10
}
#else

void func_0012B470(void);

void func_0012B530(void) {
    func_0012B470();
}

#endif

}
