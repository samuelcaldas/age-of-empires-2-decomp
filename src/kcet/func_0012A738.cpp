#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012A738(void *a0) {
    .word 0x27bdffa0 // addiu $sp, $sp, -0x60
    .word 0xffb40040 // sd $s4, 0x40($sp)
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0x24140001 // addiu $s4, $zero, 1
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0x3c130049 // lui $s3, 0x49
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x0080902d // move $s2, $a0
    .word 0xffbf0050 // sd $ra, 0x50($sp)
    .word 0x0000882d // move $s1, $zero
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x10000004 // b 0x12a778
    .word 0x0000802d // move $s0, $zero
    .word 0x00000000 // nop
    .word 0x0c04aaa8 // jal 0x12aaa0
    .word 0x00000000 // nop
    .word 0x0c04a916 // jal 0x12a458
    .word 0x0240202d // move $a0, $s2
    .word 0x10540008 // beq $v0, $s4, 0x12a7a4
    .word 0x2664fbb8 // addiu $a0, $s3, -0x448
    .word 0x26100001 // addiu $s0, $s0, 1
    .word 0x0c046378 // jal 0x118de0
    .word 0x0200282d // move $a1, $s0
    .word 0x2a030005 // slti $v1, $s0, 5
    .word 0x1460fff5 // bnez $v1, 0x12a770
    .word 0x00000000 // nop
    .word 0x24110005 // addiu $s1, $zero, 5
    .word 0x0c04a944 // jal 0x12a510
    .word 0x00000000 // nop
    .word 0x24040003 // addiu $a0, $zero, 3
    .word 0x0040182d // move $v1, $v0
    .word 0x14640007 // bne $v1, $a0, 0x12a7d4
    .word 0x2a220005 // slti $v0, $s1, 5
    .word 0x26310001 // addiu $s1, $s1, 1
    .word 0x2a220005 // slti $v0, $s1, 5
    .word 0x5440ffec // bnel $v0, $zero, 0x12a778
    .word 0x0000802d // move $s0, $zero
    .word 0x50640004 // beql $v1, $a0, 0x12a7e0
    .word 0x24030002 // addiu $v1, $zero, 2
    .word 0x14400003 // bnez $v0, 0x12a7e4
    .word 0xdfbf0050 // ld $ra, 0x50($sp)
    .word 0x24030002 // addiu $v1, $zero, 2
    .word 0xdfbf0050 // ld $ra, 0x50($sp)
    .word 0x0060102d // move $v0, $v1
    .word 0xdfb40040 // ld $s4, 0x40($sp)
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0060 // addiu $sp, $sp, 0x60
}
#else

void func_0012AAA0(void);
s32 func_0012A458(void *);
void func_118de0(const char *, ...);
s32 func_0012A510(void);

extern const char D_48FBB8[];

s32 func_0012A738(void *a0) {
    s32 s1 = 0;

    for (;;) {
        for (s32 s0 = 0; ; ) {
            if (func_0012A458(a0) == 1) {
                break;
            }
            s0++;
            func_118de0(D_48FBB8, s0);
            if (s0 >= 5) {
                s1 = 5;
                break;
            }
            func_0012AAA0();
        }

        s32 v1 = func_0012A510();
        if (v1 != 3) {
            if (s1 < 5) {
                return v1;
            }
            return 2;
        }

        s1++;
        if (s1 >= 5) {
            return 2;
        }
    }
}

#endif

}
