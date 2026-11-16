/* Function: func_0012A9B0 (0x0012A9B0 - 0x0012AA9C)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
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
asm s32 func_0012A9B0(void *a0) {
    .word 0x27bdffa0 // addiu $sp, $sp, -0x60
    .word 0x24020001 // addiu $v0, $zero, 1
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffbf0050 // sd $ra, 0x50($sp)
    .word 0x0080802d // move $s0, $a0
    .word 0xffb40040 // sd $s4, 0x40($sp)
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x8e030014 // lw $v1, 0x14($s0)
    .word 0x8e140030 // lw $s4, 0x30($s0)
    .word 0x8e120038 // lw $s2, 0x38($s0)
    .word 0x1062000e // beq $v1, $v0, 0x12aa1c
    .word 0x8e13003c // lw $s3, 0x3c($s0)
    .word 0x24020002 // addiu $v0, $zero, 2
    .word 0x10620009 // beq $v1, $v0, 0x12aa14
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484fbe0 // addiu $a0, $a0, -0x420
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c06004e // lui $a2, 0x4e
    .word 0x2484f500 // addiu $a0, $a0, -0xb00
    .word 0x24c62c58 // addiu $a2, $a2, 0x2c58
    .word 0x0c0450c8 // jal 0x114320
    .word 0x2405070c // addiu $a1, $zero, 0x70c
    .word 0x1000000b // b 0x12aa44
    .word 0x8e11002c // lw $s1, 0x2c($s0)
    .word 0x0c04a834 // jal 0x12a0d0
    .word 0x00000000 // nop
    .word 0x16400002 // bnez $s2, 0x12aa30
    .word 0x0040882d // move $s1, $v0
    .word 0x8e120024 // lw $s2, 0x24($s0)
    .word 0x0c04b2fa // jal 0x12cbe8
    .word 0x00000000 // nop
    .word 0x8e030020 // lw $v1, 0x20($s0)
    .word 0x00621823 // subu $v1, $v1, $v0
    .word 0x02639821 // addu $s3, $s3, $v1
    .word 0x0220202d // move $a0, $s1
    .word 0x001232c0 // sll $a2, $s2, 0xb
    .word 0x00133ac0 // sll $a3, $s3, 0xb
    .word 0x0c04a344 // jal 0x128d10
    .word 0x0280282d // move $a1, $s4
    .word 0x8e03006c // lw $v1, 0x6c($s0)
    .word 0x0040282d // move $a1, $v0
    .word 0x24040001 // addiu $a0, $zero, 1
    .word 0x24020009 // addiu $v0, $zero, 9
    .word 0xac74000c // sw $s4, 0xc($v1)
    .word 0x0085100b // movn $v0, $a0, $a1
    .word 0xdfbf0050 // ld $ra, 0x50($sp)
    .word 0xdfb40040 // ld $s4, 0x40($sp)
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0xac600014 // sw $zero, 0x14($v1)
    .word 0xac640008 // sw $a0, 8($v1)
    .word 0xac650010 // sw $a1, 0x10($v1)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0060 // addiu $sp, $sp, 0x60
}
#else

struct SubStruct {
    u8 pad0[0x8];
    s32 f_8;
    s32 f_c;
    s32 f_10;
    s32 f_14;
};

struct TargetStruct {
    u8 pad0[0x14];
    s32 f_14;
    u8 pad18[0x8];
    s32 f_20;
    s32 f_24;
    u8 pad28[0x4];
    s32 f_2c;
    s32 f_30;
    u8 pad34[0x4];
    s32 f_38;
    s32 f_3c;
    u8 pad40[0x2c];
    SubStruct *f_6c;
};

void func_118de0(const char *, ...);
void func_114320(const char *, int, const char *);
s32 func_0012A0D0(void);
s32 func_0012CBE8(void);
s32 func_00128D10(s32, s32, s32, s32);

extern const char D_48FBE0[];
extern const char D_48F500[];
extern const char D_4E2C58[];

s32 func_0012A9B0(TargetStruct *a0) {
    s32 v1 = a0->f_14;
    s32 s4 = a0->f_30;
    s32 s2 = a0->f_38;
    s32 s3 = a0->f_3c;
    s32 s1;

    if (v1 == 1) {
        s1 = func_0012A0D0();
        if (s2 == 0) {
            s2 = a0->f_24;
        }
        s3 += a0->f_20 - func_0012CBE8();
    } else {
        if (v1 != 2) {
            func_118de0(D_48FBE0);
            func_114320(D_48F500, 0x70c, D_4E2C58);
        }
        s1 = a0->f_2c;
    }

    s32 v0 = func_00128D10(s1, s4, s2 << 11, s3 << 11);
    SubStruct *sub = a0->f_6c;
    sub->f_c = s4;
    sub->f_14 = 0;
    sub->f_8 = 1;
    sub->f_10 = v0;
    if (v0 != 0) {
        return 1;
    }
    return 9;
}

#endif

}
