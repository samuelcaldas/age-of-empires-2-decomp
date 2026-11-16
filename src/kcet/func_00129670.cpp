/* Function: func_00129670 (0x00129670 - 0x0012976C)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00129670(void) {
    .word 0x27bdffc0 // addiu $sp, $sp, -0x40
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x0080902d // move $s2, $a0
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0xffbf0030 // sd $ra, 0x30($sp)
    .word 0x0c04a4d2 // jal 0x129348
    .word 0x00a0802d // move $s0, $a1
    .word 0x0c04b336 // jal 0x12ccd8
    .word 0x3c110039 // lui $s1, 0x39
    .word 0x0c04a574 // jal 0x1295d0
    .word 0x0200202d // move $a0, $s0
    .word 0x0040282d // move $a1, $v0
    .word 0x2631c7d8 // addiu $s1, $s1, -0x3828
    .word 0x0c04a588 // jal 0x129620
    .word 0x0220202d // move $a0, $s1
    .word 0x0220202d // move $a0, $s1
    .word 0x0240282d // move $a1, $s2
    .word 0x0200302d // move $a2, $s0
    .word 0xdfbf0030 // ld $ra, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x0804a66a // j 0x1299a8
    .word 0x27bd0040 // addiu $sp, $sp, 0x40
    .word 0x00000000 // nop
    .word 0x0804a59c // j 0x129670
    .word 0x00000000 // nop
    .word 0x27bdfff0 // addiu $sp, $sp, -0x10
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c060049 // lui $a2, 0x49
    .word 0xffbf0000 // sd $ra, ($sp)
    .word 0x24c6f518 // addiu $a2, $a2, -0xae8
    .word 0x2484f500 // addiu $a0, $a0, -0xb00
    .word 0x0c0450c8 // jal 0x114320
    .word 0x24050130 // addiu $a1, $zero, 0x130
    .word 0xdfbf0000 // ld $ra, ($sp)
    .word 0x0000202d // move $a0, $zero
    .word 0x2405ffff // addiu $a1, $zero, -1
    .word 0x0804a59c // j 0x129670
    .word 0x27bd0010 // addiu $sp, $sp, 0x10
    .word 0x00000000 // nop
    .word 0x27bdfff0 // addiu $sp, $sp, -0x10
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c060049 // lui $a2, 0x49
    .word 0xffbf0000 // sd $ra, ($sp)
    .word 0x24c6f518 // addiu $a2, $a2, -0xae8
    .word 0x2484f500 // addiu $a0, $a0, -0xb00
    .word 0x0c0450c8 // jal 0x114320
    .word 0x24050136 // addiu $a1, $zero, 0x136
    .word 0xdfbf0000 // ld $ra, ($sp)
    .word 0x24040001 // addiu $a0, $zero, 1
    .word 0x2405ffff // addiu $a1, $zero, -1
    .word 0x0804a59c // j 0x129670
    .word 0x27bd0010 // addiu $sp, $sp, 0x10
    .word 0x00000000 // nop
    .word 0x27bdfff0 // addiu $sp, $sp, -0x10
    .word 0xffbf0000 // sd $ra, ($sp)
    .word 0x0c04aec8 // jal 0x12bb20
    .word 0x00000000 // nop
    .word 0xdfbf0000 // ld $ra, ($sp)
    .word 0x0804a4e2 // j 0x129388
    .word 0x27bd0010 // addiu $sp, $sp, 0x10
}
#else
void func_00129348(void);
void func_0012CCD8(void);
int func_001295D0(int a0);
void func_00129620(void *a0, int a1);
void *func_001299A8(void *a0, void *a1, int a2);
void func_114320(const char *a0, int a1, const char *a2);
void func_0012BB20(void);
void *func_00129388(void);

extern void *D_38C7D8;
extern const char D_48F500[];
extern const char D_48F518[];

void *func_00129670(void *a0, int a1) {
    func_00129348();
    func_0012CCD8();
    int v = func_001295D0(a1);
    func_00129620(&D_38C7D8, v);
    return func_001299A8(&D_38C7D8, a0, a1);
}

void *func_001296D8(void *a0, int a1) {
    return func_00129670(a0, a1);
}

void *func_001296E0(void) {
    func_114320(D_48F500, 0x130, D_48F518);
    return func_00129670(0, -1);
}

void *func_00129718(void) {
    func_114320(D_48F500, 0x136, D_48F518);
    return func_00129670((void *)1, -1);
}

void *func_00129750(void) {
    func_0012BB20();
    return func_00129388();
}
#endif

}
