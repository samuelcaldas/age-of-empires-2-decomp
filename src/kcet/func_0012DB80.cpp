/* Function: func_0012DB80 (0x0012DB80 - 0x0012DB9C)
 * Origin: SLES-50282, KCET kt_file module
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
asm void func_0012DB80(void) {
    .word 0x27bdfff0 // 0012DB80:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012DB84:  sd $ra, ($sp)
    .word 0x0c043be0 // 0012DB88:  jal 0x10ef80
    .word 0x00000000 // 0012DB8C:  nop 
    .word 0xdfbf0000 // 0012DB90:  ld $ra, ($sp)
    .word 0x03e00008 // 0012DB94:  jr $ra
    .word 0x27bd0010 // 0012DB98:  addiu $sp, $sp, 0x10
}
#else

void func_0010EF80(void);

void func_0012DB80(void) {
    func_0010EF80();
}

#endif

}
