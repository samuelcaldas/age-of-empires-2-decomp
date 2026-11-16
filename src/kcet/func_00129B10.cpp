/* Function: func_00129B10 (0x00129B10 - 0x00129BDC)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00129B10(void) {
    .word 0x27bdffa0 // 0x129b10: addiu $sp, $sp, -0x60
    .word 0xffb40040 // 0x129b14: sd $s4, 0x40($sp)
    .word 0xffb20020 // 0x129b18: sd $s2, 0x20($sp)
    .word 0x24140001 // 0x129b1c: addiu $s4, $zero, 1
    .word 0xffb00000 // 0x129b20: sd $s0, ($sp)
    .word 0x0080902d // 0x129b24: move $s2, $a0
    .word 0xffbf0050 // 0x129b28: sd $ra, 0x50($sp)
    .word 0x0000802d // 0x129b2c: move $s0, $zero
    .word 0xffb10010 // 0x129b30: sd $s1, 0x10($sp)
    .word 0xffb30030 // 0x129b34: sd $s3, 0x30($sp)
    .word 0x0c04a7f4 // 0x129b38: jal 0x129fd0
    .word 0x8e530000 // 0x129b3c: lw $s3, ($s2)
    .word 0x1054001b // 0x129b40: beq $v0, $s4, 0x129bb0
    .word 0x0000882d // 0x129b44: move $s1, $zero
    .word 0x0c04b6f0 // 0x129b48: jal 0x12dbc0
    .word 0x00000000 // 0x129b4c: nop 
    .word 0x0040882d // 0x129b50: move $s1, $v0
    .word 0x3c040049 // 0x129b54: lui $a0, 0x49
    .word 0x2484f858 // 0x129b58: addiu $a0, $a0, -0x7a8
    .word 0x24050007 // 0x129b5c: addiu $a1, $zero, 7
    .word 0x0220302d // 0x129b60: move $a2, $s1
    .word 0x0c04a562 // 0x129b64: jal 0x129588
    .word 0x2407ffff // 0x129b68: addiu $a3, $zero, -1
    .word 0x04400004 // 0x129b6c: bltz $v0, 0x129b80
    .word 0x02621024 // 0x129b70: and $v0, $s3, $v0
    .word 0x24100003 // 0x129b74: addiu $s0, $zero, 3
    .word 0x1000000d // 0x129b78: b 0x129bb0
    .word 0x0002800b // 0x129b7c: movn $s0, $zero, $v0
    .word 0x1234000a // 0x129b80: beq $s1, $s4, 0x129bac
    .word 0x2a220002 // 0x129b84: slti $v0, $s1, 2
    .word 0x14400009 // 0x129b88: bnez $v0, 0x129bb0
    .word 0x24100002 // 0x129b8c: addiu $s0, $zero, 2
    .word 0x24020005 // 0x129b90: addiu $v0, $zero, 5
    .word 0x12220003 // 0x129b94: beq $s1, $v0, 0x129ba4
    .word 0x240200ff // 0x129b98: addiu $v0, $zero, 0xff
    .word 0x56220005 // 0x129b9c: bnel $s1, $v0, 0x129bb4
    .word 0xae510004 // 0x129ba0: sw $s1, 4($s2)
    .word 0x10000002 // 0x129ba4: b 0x129bb0
    .word 0x24100003 // 0x129ba8: addiu $s0, $zero, 3
    .word 0x24100001 // 0x129bac: addiu $s0, $zero, 1
    .word 0xae510004 // 0x129bb0: sw $s1, 4($s2)
    .word 0x0200102d // 0x129bb4: move $v0, $s0
    .word 0xae500008 // 0x129bb8: sw $s0, 8($s2)
    .word 0xdfbf0050 // 0x129bbc: ld $ra, 0x50($sp)
    .word 0xdfb40040 // 0x129bc0: ld $s4, 0x40($sp)
    .word 0xdfb30030 // 0x129bc4: ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0x129bc8: ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0x129bcc: ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0x129bd0: ld $s0, ($sp)
    .word 0x03e00008 // 0x129bd4: jr $ra
    .word 0x27bd0060 // 0x129bd8: addiu $sp, $sp, 0x60
}
#else

int func_00129FD0(void);
int func_0012DBC0(void);
int func_00129588(void *a0, int a1, int a2, int a3);

extern char D_0048F858[];

struct Context {
    int field_0;
    int field_4;
    int field_8;
};

int func_00129B10(Context *ctx) {
    int s0 = 0;
    int s3 = ctx->field_0;
    if (func_00129FD0() == 1) {
        ctx->field_4 = 0;
        ctx->field_8 = 0;
        return 0;
    }

    int s1 = func_0012DBC0();
    int r = func_00129588(D_0048F858, 7, s1, -1);
    if (r >= 0) {
        if ((s3 & r) == 0) {
            s0 = 3;
        } else {
            s0 = 0;
        }
        ctx->field_4 = s1;
        ctx->field_8 = s0;
        return s0;
    }

    if (s1 == 1) {
        s0 = 1;
    } else if (s1 < 2) {
        s0 = 0;
    } else if (s1 == 5) {
        s0 = 3;
    } else if (s1 != 0xff) {
        s0 = 2;
        ctx->field_8 = 2;
        return 2;
    } else {
        s0 = 2;
    }

    ctx->field_4 = s1;
    ctx->field_8 = s0;
    return s0;
}

#endif

}
