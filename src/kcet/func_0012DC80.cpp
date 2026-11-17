/* Function: func_0012DC80 (0x0012DC80 - 0x0012DC9C)
 * Origin: SLES-50282, KCET kt_file module (originally compiled with ee-gcc -O2 -G0)
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
asm void func_0012DC80(void) {
    .word 0x27bdfff0 // 0012DC80:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012DC84:  sd $ra, ($sp)
    .word 0x0c043c90 // 0012DC88:  jal 0x10f240
    .word 0x00000000 // 0012DC8C:  nop 
    .word 0xdfbf0000 // 0012DC90:  ld $ra, ($sp)
    .word 0x03e00008 // 0012DC94:  jr $ra
    .word 0x27bd0010 // 0012DC98:  addiu $sp, $sp, 0x10
}
#else

void func_0010F240(void);

void func_0012DC80(void) {
    func_0010F240();
}

#endif

}
