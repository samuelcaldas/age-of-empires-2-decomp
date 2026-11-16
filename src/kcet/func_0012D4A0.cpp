/* Function: func_0012D4A0 (0x0012D4A0 - 0x0012D4C4)
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
asm void func_0012D4A0(void) {
    .word 0x27bdfff0 // 0012D4A0:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012D4A4:  sd $ra, ($sp)
    .word 0x0c04b2c8 // 0012D4A8:  jal 0x12cb20
    .word 0x00000000 // 0012D4AC:  nop 
    .word 0x0c04b2c2 // 0012D4B0:  jal 0x12cb08
    .word 0x0040202d // 0012D4B4:  move $a0, $v0
    .word 0xdfbf0000 // 0012D4B8:  ld $ra, ($sp)
    .word 0x03e00008 // 0012D4BC:  jr $ra
    .word 0x27bd0010 // 0012D4C0:  addiu $sp, $sp, 0x10
}
#else

void *func_0012CB20(void);
void func_0012CB08(void *);

void func_0012D4A0(void) {
    func_0012CB08(func_0012CB20());
}

#endif

}
