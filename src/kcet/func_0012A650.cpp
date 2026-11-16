#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012A650(void) {
    .word 0x27bdffb0 // addiu $sp, $sp, -0x50
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x0000982d // move $s3, $zero
    .word 0xffbf0040 // sd $ra, 0x40($sp)
    .word 0x24110001 // addiu $s1, $zero, 1
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0x10000004 // b 0x12a680
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x00000000 // nop
    .word 0x0c04aaa8 // jal 0x12aaa0
    .word 0x00000000 // nop
    .word 0x0c04b68e // jal 0x12da38
    .word 0x24120001 // addiu $s2, $zero, 1
    .word 0x1052001a // beq $v0, $s2, 0x12a6f4
    .word 0x00000000 // nop
    .word 0x0c04b6e0 // jal 0x12db80
    .word 0x24040001 // addiu $a0, $zero, 1
    .word 0x0040802d // move $s0, $v0
    .word 0x24020002 // addiu $v0, $zero, 2
    .word 0x16020014 // bne $s0, $v0, 0x12a6f4
    .word 0x3c04004f // lui $a0, 0x4f
    .word 0x0c04a6c4 // jal 0x129b10
    .word 0x2484d300 // addiu $a0, $a0, -0x2d00
    .word 0x0040182d // move $v1, $v0
    .word 0x1072000f // beq $v1, $s2, 0x12a6f4
    .word 0x28620002 // slti $v0, $v1, 2
    .word 0x10400005 // beqz $v0, 0x12a6d4
    .word 0x00000000 // nop
    .word 0x10600007 // beqz $v1, 0x12a6e4
    .word 0x0000882d // move $s1, $zero
    .word 0x10000009 // b 0x12a6f4
    .word 0x0000982d // move $s3, $zero
    .word 0x54700005 // bnel $v1, $s0, 0x12a6ec
    .word 0x24020003 // addiu $v0, $zero, 3
    .word 0x10000004 // b 0x12a6f0
    .word 0x0000882d // move $s1, $zero
    .word 0x10000003 // b 0x12a6f4
    .word 0x24130001 // addiu $s3, $zero, 1
    .word 0x0000882d // move $s1, $zero
    .word 0x0000982d // move $s3, $zero
    .word 0x1620ffe0 // bnez $s1, 0x12a678
    .word 0x00000000 // nop
    .word 0x16600005 // bnez $s3, 0x12a714
    .word 0x0260102d // move $v0, $s3
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484fba0 // addiu $a0, $a0, -0x460
    .word 0x0260102d // move $v0, $s3
    .word 0xdfbf0040 // ld $ra, 0x40($sp)
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0050 // addiu $sp, $sp, 0x50
}
#else

void func_0012AAA0(void);
s32 func_0012DA38(void);
s32 func_0012DB80(s32);
s32 func_00129B10(void *);
void func_118de0(const char *, ...);

extern char D_004ED300[];
extern const char D_0048FBA0[];

s32 func_0012A650(void) {
    s32 s3 = 0;
    s32 s1 = 1;

    do {
        s32 v0 = func_0012DA38();
        if (v0 != 1) {
            s32 s0 = func_0012DB80(1);
            if (s0 == 2) {
                s32 v1 = func_00129B10(D_004ED300);
                if (v1 != 1) {
                    if (v1 < 2) {
                        if (v1 == 0) {
                            s3 = 1;
                            break;
                        }
                        s1 = 0;
                        s3 = 0;
                        break;
                    } else {
                        if (v1 != s0) {
                            s1 = 0;
                            s3 = 0;
                            break;
                        } else {
                            s1 = 0;
                            s3 = 0;
                            break;
                        }
                    }
                }
            }
        }
        func_0012AAA0();
    } while (s1 != 0);

    if (s3 == 0) {
        func_118de0(D_0048FBA0);
    }
    return s3;
}

#endif

}
