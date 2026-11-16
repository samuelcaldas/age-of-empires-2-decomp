/* Function: func_0012A1B0 (0x0012A1B0 - 0x0012A288)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm int func_0012A1B0(void *a0) {
    .word 0x27bdffa0 // addiu $sp, $sp, -0x60
    .word 0x0080102d // move $v0, $a0
    .word 0xffb40040 // sd $s4, 0x40($sp)
    .word 0x0000202d // move $a0, $zero
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x24540034 // addiu $s4, $v0, 0x34
    .word 0xffbf0050 // sd $ra, 0x50($sp)
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x8c50006c // lw $s0, 0x6c($v0)
    .word 0x8c430028 // lw $v1, 0x28($v0)
    .word 0x8c46003c // lw $a2, 0x3c($v0)
    .word 0x8c530030 // lw $s3, 0x30($v0)
    .word 0x8c470020 // lw $a3, 0x20($v0)
    .word 0x00661821 // addu $v1, $v1, $a2
    .word 0x8c520024 // lw $s2, 0x24($v0)
    .word 0x8c450038 // lw $a1, 0x38($v0)
    .word 0x00e38821 // addu $s1, $a3, $v1
    .word 0xae000008 // sw $zero, 8($s0)
    .word 0xae13000c // sw $s3, 0xc($s0)
    .word 0x0c04a7bc // jal 0x129ef0
    .word 0x00a5900b // movn $s2, $a1, $a1
    .word 0x02421018 // mult $ac2, $s2, $v0
    .word 0xae110014 // sw $s1, 0x14($s0)
    .word 0xae020010 // sw $v0, 0x10($s0)
    .word 0x10000005 // b 0x12a230
    .word 0x3c100049 // lui $s0, 0x49
    .word 0x0c046378 // jal 0x118de0
    .word 0x2604f9c8 // addiu $a0, $s0, -0x638
    .word 0x0c04aaa8 // jal 0x12aaa0
    .word 0x00000000 // nop
    .word 0x0220202d // move $a0, $s1
    .word 0x0240282d // move $a1, $s2
    .word 0x0260302d // move $a2, $s3
    .word 0x0c04b636 // jal 0x12d8d8
    .word 0x0280382d // move $a3, $s4
    .word 0x1040fff6 // beqz $v0, 0x12a220
    .word 0x00000000 // nop
    .word 0x00000000 // nop
    .word 0x0c04aaa8 // jal 0x12aaa0
    .word 0x00000000 // nop
    .word 0x0c04b664 // jal 0x12d990
    .word 0x00000000 // nop
    .word 0x1440fffb // bnez $v0, 0x12a250
    .word 0xdfbf0050 // ld $ra, 0x50($sp)
    .word 0x24020001 // addiu $v0, $zero, 1
    .word 0xdfb40040 // ld $s4, 0x40($sp)
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0060 // addiu $sp, $sp, 0x60
}
#else

struct TargetSub {
    char pad0[8];
    int field_8;
    int field_C;
    int field_10;
    int field_14;
};

struct TargetStruct {
    char pad0[0x20];
    int field_20;
    int field_24;
    int field_28;
    char pad2C[4];
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    char pad40[0x6C - 0x40];
    TargetSub *sub;
};

int func_00129EF0(void);
void func_118de0(const char *fmt, ...);
void func_0012AAA0(void);
int func_0012D8D8(int, int, int, void *);
int func_0012D990(void);

extern const char D_0048F9C8[];

int func_0012A1B0(TargetStruct *target) {
    TargetSub *s0 = target->sub;
    int s3 = target->field_30;
    int s1 = target->field_20 + target->field_28 + target->field_3C;
    int s2 = target->field_24;
    int a1 = target->field_38;
    if (a1 != 0) {
        s2 = a1;
    }

    s0->field_8 = 0;
    s0->field_C = s3;

    int v0 = func_00129EF0();
    s0->field_14 = s1;
    s0->field_10 = v0;

    while (func_0012D8D8(s1, s2, s3, &target->field_34) == 0) {
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
