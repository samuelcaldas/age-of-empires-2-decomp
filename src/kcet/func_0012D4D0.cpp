/* Function: func_0012D4D0 (0x0012D4D0 - 0x0012D540)
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
asm void func_0012D4D0(void *arg) {
    .word 0x27bdffd0 // 0012D4D0:  addiu $sp, $sp, -0x30
    .word 0xffb10010 // 0012D4D4:  sd $s1, 0x10($sp)
    .word 0xffb00000 // 0012D4D8:  sd $s0, ($sp)
    .word 0xffbf0020 // 0012D4DC:  sd $ra, 0x20($sp)
    .word 0x0c04b3a8 // 0012D4E0:  jal 0x12cea0
    .word 0x0080882d // 0012D4E4:  move $s1, $a0
    .word 0x0040802d // 0012D4E8:  move $s0, $v0
    .word 0x2e020004 // 0012D4EC:  sltiu $v0, $s0, 4
    .word 0x14400008 // 0012D4F0:  bnez $v0, 0x12d514
    .word 0x3c020039 // 0012D4F4:  lui $v0, 0x39
    .word 0x3c040049 // 0012D4F8:  lui $a0, 0x49
    .word 0x3c060049 // 0012D4FC:  lui $a2, 0x49
    .word 0x2484fea0 // 0012D500:  addiu $a0, $a0, -0x160
    .word 0x24c6feb0 // 0012D504:  addiu $a2, $a2, -0x150
    .word 0x0c0450c8 // 0012D508:  jal 0x114320
    .word 0x240502b1 // 0012D50C:  addiu $a1, $zero, 0x2b1
    .word 0x3c020039 // 0012D510:  lui $v0, 0x39
    .word 0x00101880 // 0012D514:  sll $v1, $s0, 2
    .word 0x2442c838 // 0012D518:  addiu $v0, $v0, -0x37c8
    .word 0x00621821 // 0012D51C:  addu $v1, $v1, $v0
    .word 0x8c620000 // 0012D520:  lw $v0, ($v1)
    .word 0x0040f809 // 0012D524:  jalr $v0
    .word 0x0220202d // 0012D528:  move $a0, $s1
    .word 0xdfbf0020 // 0012D52C:  ld $ra, 0x20($sp)
    .word 0xdfb10010 // 0012D530:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012D534:  ld $s0, ($sp)
    .word 0x03e00008 // 0012D538:  jr $ra
    .word 0x27bd0030 // 0012D53C:  addiu $sp, $sp, 0x30
}
#else

typedef void (*HandlerFunc)(void *);
extern HandlerFunc D_0038C838[];
u32 func_0012CEA0(void *);
void func_114320(const char *, int, const char *);
extern const char D_48FEA0[];
extern const char D_48FEB0[];

void func_0012D4D0(void *arg) {
    u32 mode = func_0012CEA0(arg);
    if (mode >= 4) {
        func_114320(D_48FEA0, 0x2b1, D_48FEB0);
    }
    D_0038C838[mode](arg);
}

#endif

}
