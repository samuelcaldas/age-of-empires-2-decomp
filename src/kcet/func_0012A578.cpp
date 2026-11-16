/* Function: func_0012A578 (0x0012A578 - 0x0012A648)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm int func_0012A578(void) {
    .word 0x27bdff90 // addiu $sp, $sp, -0x70
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffb50050 // sd $s5, 0x50($sp)
    .word 0x0000802d // move $s0, $zero
    .word 0xffb40040 // sd $s4, 0x40($sp)
    .word 0x3c150049 // lui $s5, 0x49
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0x2414ffff // addiu $s4, $zero, -1
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0x24130001 // addiu $s3, $zero, 1
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x24120002 // addiu $s2, $zero, 2
    .word 0xffbf0060 // sd $ra, 0x60($sp)
    .word 0x10000005 // b 0x12a5c4
    .word 0x0200882d // move $s1, $s0
    .word 0x00000000 // nop
    .word 0x0c04aaa8 // jal 0x12aaa0
    .word 0x24100002 // addiu $s0, $zero, 2
    .word 0x26310001 // addiu $s1, $s1, 1
    .word 0x2a22003c // slti $v0, $s1, 0x3c
    .word 0x10400016 // beqz $v0, 0x12a624
    .word 0x0200102d // move $v0, $s0
    .word 0x0c04b68e // jal 0x12da38
    .word 0x00000000 // nop
    .word 0x0040302d // move $a2, $v0
    .word 0x26a4fb68 // addiu $a0, $s5, -0x498
    .word 0x24050007 // addiu $a1, $zero, 7
    .word 0x0c04a562 // jal 0x129588
    .word 0x0000382d // move $a3, $zero
    .word 0x0040802d // move $s0, $v0
    .word 0x16140003 // bne $s0, $s4, 0x12a600
    .word 0x00000000 // nop
    .word 0x10000009 // b 0x12a620
    .word 0x24100005 // addiu $s0, $zero, 5
    .word 0x52130007 // beql $s0, $s3, 0x12a620
    .word 0x0000802d // move $s0, $zero
    .word 0x1612ffeb // bne $s0, $s2, 0x12a5b8
    .word 0x00000000 // nop
    .word 0x0c04b6e0 // jal 0x12db80
    .word 0x24040001 // addiu $a0, $zero, 1
    .word 0x1450ffe7 // bne $v0, $s0, 0x12a5b8
    .word 0x0000802d // move $s0, $zero
    .word 0x0200102d // move $v0, $s0
    .word 0xdfbf0060 // ld $ra, 0x60($sp)
    .word 0xdfb50050 // ld $s5, 0x50($sp)
    .word 0xdfb40040 // ld $s4, 0x40($sp)
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0070 // addiu $sp, $sp, 0x70
}
#else

void func_0012AAA0(void);
int func_0012DA38(void);
int func_00129588(void *a0, int a1, int a2, int a3);
int func_0012DB80(int a0);

extern char D_0048FB68[];

int func_0012A578(void) {
    int s0 = 0;
    int s1 = 0;

    for (s1 = 0; s1 < 60; ) {
        int v0 = func_0012DA38();
        s0 = func_00129588(D_0048FB68, 7, v0, 0);
        if (s0 == -1) {
            return 5;
        }
        if (s0 == 1) {
            return 0;
        }
        if (s0 == 2) {
            if (func_0012DB80(1) == 2) {
                return 0;
            }
        }
        func_0012AAA0();
        s0 = 2;
        s1++;
    }
    return s0;
}

#endif

}
