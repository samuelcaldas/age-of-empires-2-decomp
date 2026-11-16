/* Function: func_0012A320 (0x0012A320 - 0x0012A388)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm int func_0012A320(void *a0) {
    .word 0x27bdffe0 // addiu $sp, $sp, -0x20
    .word 0xffbf0010 // sd $ra, 0x10($sp)
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x8c82006c // lw $v0, 0x6c($a0)
    .word 0xac400008 // sw $zero, 8($v0)
    .word 0x10000006 // b 0x12a350
    .word 0x3c100049 // lui $s0, 0x49
    .word 0x00000000 // nop
    .word 0x0c046378 // jal 0x118de0
    .word 0x2604f9c8 // addiu $a0, $s0, -0x638
    .word 0x0c04aaa8 // jal 0x12aaa0
    .word 0x00000000 // nop
    .word 0x0c04b6c2 // jal 0x12db08
    .word 0x00000000 // nop
    .word 0x1040fff9 // beqz $v0, 0x12a340
    .word 0x00000000 // nop
    .word 0x0c04aaa8 // jal 0x12aaa0
    .word 0x00000000 // nop
    .word 0x0c04b664 // jal 0x12d990
    .word 0x00000000 // nop
    .word 0x1440fffb // bnez $v0, 0x12a360
    .word 0xdfbf0010 // ld $ra, 0x10($sp)
    .word 0x24020001 // addiu $v0, $zero, 1
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0020 // addiu $sp, $sp, 0x20
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

void func_118de0(const char *fmt, ...);
void func_0012AAA0(void);
int func_0012DB08(void);
int func_0012D990(void);

extern const char D_0048F9C8[];

int func_0012A320(TargetStruct *target) {
    TargetSub *sub = target->sub;
    sub->field_8 = 0;

    while (func_0012DB08() == 0) {
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
