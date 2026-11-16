/* Function: func_0012D038 (0x0012D038 - 0x0012D05C)
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
asm void *func_0012D038(void *arg) {
    .word 0x27bdfff0 // 0012d038:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012d03c:  sd $ra, ($sp)
    .word 0x0c04b3f2 // 0012d040:  jal 0x12cfc8
    .word 0x00000000 // 0012d044:  nop
    .word 0x0c04b312 // 0012d048:  jal 0x12cc48
    .word 0x0040202d // 0012d04c:  move $a0, $v0
    .word 0xdfbf0000 // 0012d050:  ld $ra, ($sp)
    .word 0x03e00008 // 0012d054:  jr $ra
    .word 0x27bd0010 // 0012d058:  addiu $sp, $sp, 0x10
}
#else

void *func_0012CFC8(void *arg);
void *func_0012CC48(void *arg);

void *func_0012D038(void *arg) {
    return func_0012CC48(func_0012CFC8(arg));
}

#endif

}
