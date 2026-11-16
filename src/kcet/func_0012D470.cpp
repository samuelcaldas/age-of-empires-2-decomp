/* Function: func_0012D470 (0x0012D470 - 0x0012D49C)
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
asm u32 func_0012D470(void) {
    .word 0x27bdfff0 // 0012D470:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012D474:  sd $ra, ($sp)
    .word 0x0c04b47c // 0012D478:  jal 0x12d1f0
    .word 0x00000000 // 0012D47C:  nop 
    .word 0x0c04b2c8 // 0012D480:  jal 0x12cb20
    .word 0x0040202d // 0012D484:  move $a0, $v0
    .word 0x0c04b2c2 // 0012D488:  jal 0x12cb08
    .word 0x0040202d // 0012D48C:  move $a0, $v0
    .word 0xdfbf0000 // 0012D490:  ld $ra, ($sp)
    .word 0x03e00008 // 0012D494:  jr $ra
    .word 0x27bd0010 // 0012D498:  addiu $sp, $sp, 0x10
}
#else

const u16 *func_0012D1F0(void);
u32 func_0012CB20(const u16 *);
u32 func_0012CB08(u32);

u32 func_0012D470(void) {
    return func_0012CB08(func_0012CB20(func_0012D1F0()));
}

#endif

}
