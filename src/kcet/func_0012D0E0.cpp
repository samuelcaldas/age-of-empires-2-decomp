/* Function: func_0012D0E0 (0x0012D0E0 - 0x0012D124)
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
asm void func_0012D0E0(void *a0) {
    .word 0x27bdffd0 // 0012d0e0:  addiu $sp, $sp, -0x30
    .word 0xffb10010 // 0012d0e4:  sd $s1, 0x10($sp)
    .word 0xffb00000 // 0012d0e8:  sd $s0, ($sp)
    .word 0xffbf0020 // 0012d0ec:  sd $ra, 0x20($sp)
    .word 0x0c04b2b0 // 0012d0f0:  jal 0x12cac0
    .word 0x0080882d // 0012d0f4:  move $s1, $a0
    .word 0x0c04b2b4 // 0012d0f8:  jal 0x12cad0
    .word 0x0040802d // 0012d0fc:  move $s0, $v0
    .word 0x0220202d // 0012d100:  move $a0, $s1
    .word 0x0200282d // 0012d104:  move $a1, $s0
    .word 0x0c04b44a // 0012d108:  jal 0x12d128
    .word 0x0040302d // 0012d10c:  move $a2, $v0
    .word 0xdfbf0020 // 0012d110:  ld $ra, 0x20($sp)
    .word 0xdfb10010 // 0012d114:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012d118:  ld $s0, ($sp)
    .word 0x03e00008 // 0012d11c:  jr $ra
    .word 0x27bd0030 // 0012d120:  addiu $sp, $sp, 0x30
}
#else

void func_0012CAC0(void *);
void *func_0012CAD0(void);
void func_0012D128(void *, void *, void *);

void func_0012D0E0(void *a0) {
    func_0012CAC0(a0);
    void *s0 = func_0012CAD0();
    func_0012D128(a0, s0, s0);
}

#endif

}
