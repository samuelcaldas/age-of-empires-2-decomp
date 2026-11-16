/* Function: func_0012D2E0 (0x0012D2E0 - 0x0012D304)
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
asm void *func_0012D2E0(void) {
    .word 0x27bdfff0 // 0012d2e0:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012d2e4:  sd $ra, ($sp)
    .word 0x0c04b2ce // 0012d2e8:  jal 0x12cb38
    .word 0x00000000 // 0012d2ec:  nop
    .word 0x0c04b48a // 0012d2f0:  jal 0x12d228
    .word 0x0040202d // 0012d2f4:  move $a0, $v0
    .word 0xdfbf0000 // 0012d2f8:  ld $ra, ($sp)
    .word 0x03e00008 // 0012d2fc:  jr $ra
    .word 0x27bd0010 // 0012d300:  addiu $sp, $sp, 0x10
}
#else

u32 func_0012CB38(void);
void *func_0012D228(u32);

void *func_0012D2E0(void) {
    return func_0012D228(func_0012CB38());
}

#endif

}
