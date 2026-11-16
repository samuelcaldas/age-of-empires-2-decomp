/* Function: func_00129778 (0x00129778 - 0x00129800)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00129778(void) {
    .word 0x27bdffd0 // addiu $sp, $sp, -0x30
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0xffbf0020 // sd $ra, 0x20($sp)
    .word 0x0c043b28 // jal 0x10eca0
    .word 0x00a0802d // move $s0, $a1
    .word 0x0040882d // move $s1, $v0
    .word 0x24020001 // addiu $v0, $zero, 1
    .word 0x56220011 // bnel $s1, $v0, 0x1297e0
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x0c043c5e // jal 0x10f178
    .word 0x0200202d // move $a0, $s0
    .word 0x0200202d // move $a0, $s0
    .word 0x0c04a574 // jal 0x1295d0
    .word 0x0040882d // move $s1, $v0
    .word 0x0040802d // move $s0, $v0
    .word 0x3c040039 // lui $a0, 0x39
    .word 0x2484c7d8 // addiu $a0, $a0, -0x3828
    .word 0x0c04a588 // jal 0x129620
    .word 0x0200282d // move $a1, $s0
    .word 0x3c04004f // lui $a0, 0x4f
    .word 0x0200282d // move $a1, $s0
    .word 0x0c04a588 // jal 0x129620
    .word 0x2484d300 // addiu $a0, $a0, -0x2d00
    .word 0x10000004 // b 0x1297ec
    .word 0x0220102d // move $v0, $s1
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484f540 // addiu $a0, $a0, -0xac0
    .word 0x0220102d // move $v0, $s1
    .word 0xdfbf0020 // ld $ra, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0030 // addiu $sp, $sp, 0x30
}
#else
int func_10ECA0(int a0, int a1);
int func_10F178(int a0);
int func_001295D0(int a0);
void func_00129620(void *a0, int a1);
void func_118de0(const char *fmt, ...);

extern int D_0038C7D8;
extern const char D_0048F540[];
extern int D_004ED300;

int func_00129778(int a0, int a1) {
    int s0 = a1;
    int s1 = func_10ECA0(a0, a1);
    if (s1 != 1) {
        func_118de0(D_0048F540);
        return s1;
    }
    s1 = func_10F178(s0);
    s0 = func_001295D0(s0);
    func_00129620(&D_0038C7D8, s0);
    func_00129620(&D_004ED300, s0);
    return s1;
}
#endif

}
