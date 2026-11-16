/* Function: func_0012A2A0 (0x0012A2A0 - 0x0012A31C)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm int func_0012A2A0(void *a0) {
    .word 0x27bdffd0 // addiu $sp, $sp, -0x30
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0xffbf0020 // sd $ra, 0x20($sp)
    .word 0x0c04a8a2 // jal 0x12a288
    .word 0x0080802d // move $s0, $a0
    .word 0x0040882d // move $s1, $v0
    .word 0x8e02006c // lw $v0, 0x6c($s0)
    .word 0xac51000c // sw $s1, 0xc($v0)
    .word 0xac400008 // sw $zero, 8($v0)
    .word 0x10000005 // b 0x12a2e0
    .word 0x3c100049 // lui $s0, 0x49
    .word 0x0c046378 // jal 0x118de0
    .word 0x2604f9c8 // addiu $a0, $s0, -0x638
    .word 0x0c04aaa8 // jal 0x12aaa0
    .word 0x00000000 // nop
    .word 0x0c04b708 // jal 0x12dc20
    .word 0x0220202d // move $a0, $s1
    .word 0x1040fff9 // beqz $v0, 0x12a2d0
    .word 0x00000000 // nop
    .word 0x0c04aaa8 // jal 0x12aaa0
    .word 0x00000000 // nop
    .word 0x0c04b664 // jal 0x12d990
    .word 0x00000000 // nop
    .word 0x1440fffb // bnez $v0, 0x12a2f0
    .word 0xdfbf0020 // ld $ra, 0x20($sp)
    .word 0x24020001 // addiu $v0, $zero, 1
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0030 // addiu $sp, $sp, 0x30
}
#else

struct TargetSub {
    char pad0[8];
    int field_8;
    int field_C;
};

struct TargetStruct {
    char pad0[0x6C];
    TargetSub *sub;
};

int func_0012A288(TargetStruct *target);
void func_118de0(const char *fmt, ...);
void func_0012AAA0(void);
int func_0012DC20(int);
int func_0012D990(void);

extern const char D_0048F9C8[];

int func_0012A2A0(TargetStruct *target) {
    int s1 = func_0012A288(target);
    TargetSub *sub = target->sub;
    sub->field_C = s1;
    sub->field_8 = 0;

    while (func_0012DC20(s1) == 0) {
        func_118de0(D_0048F9C8);
        func_0012AAA0();
    }

    do {
        func_0012AAA0();
    } while (func_0012D990() != 0);

    return 1;
}

#endif

}
