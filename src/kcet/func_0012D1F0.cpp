/* Function: func_0012D1F0 (0x0012D1F0 - 0x0012D214)
 * Origin: SLES-50282, KCET kt_file module (originally compiled with ee-gcc -O2 -G0)
 */

#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" {

#if defined(__mips__)
asm void func_0012D1F0(void) {
    .word 0x27bdfff0 // 0012d1f0:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012d1f4:  sd $ra, ($sp)
    .word 0x0c04b4c4 // 0012d1f8:  jal 0x12d310
    .word 0x00000000 // 0012d1fc:  nop
    .word 0x0c04b438 // 0012d200:  jal 0x12d0e0
    .word 0x0040202d // 0012d204:  move $a0, $v0
    .word 0xdfbf0000 // 0012d208:  ld $ra, ($sp)
    .word 0x03e00008 // 0012d20c:  jr $ra
    .word 0x27bd0010 // 0012d210:  addiu $sp, $sp, 0x10
}
#else

void *func_0012D310(void);
void func_0012D0E0(void *);

void func_0012D1F0(void) {
    func_0012D0E0(func_0012D310());
}

#endif

}
