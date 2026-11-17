#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct KtFileContext {
    u8 pad[0x2c];
    s32 field_2C;
    s32 field_30;
    s32 field_34;
    s32 field_38;
    s32 field_3C;
};

extern "C" {

void func_0012FA20(void);
s32 func_0012FA80(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1);

#if defined(__mips__)
asm void func_0012FAC8(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1) {
    .word 0x27bdff90 // addiu $sp, $sp, -0x70
    .word 0xffb50050 // sd $s5, 0x50($sp)
    .word 0xffb40040 // sd $s4, 0x40($sp)
    .word 0x00e0a82d // move $s5, $a3
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0x00c0a02d // move $s4, $a2
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0x00a0982d // move $s3, $a1
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x0080902d // move $s2, $a0
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x0120882d // move $s1, $t1
    .word 0xffbf0060 // sd $ra, 0x60($sp)
    .word 0x0c04be88 // jal 0x12fa20
    .word 0x0100802d // move $s0, $t0
    .word 0x3c020050 // lui $v0, 0x50
    .word 0x0240202d // move $a0, $s2
    .word 0x244297d8 // addiu $v0, $v0, -0x6828
    .word 0x0260282d // move $a1, $s3
    .word 0xac50003c // sw $s0, 0x3c($v0)
    .word 0x0280302d // move $a2, $s4
    .word 0x02a0382d // move $a3, $s5
    .word 0x0200402d // move $t0, $s0
    .word 0x0220482d // move $t1, $s1
    .word 0xac52002c // sw $s2, 0x2c($v0)
    .word 0xac530030 // sw $s3, 0x30($v0)
    .word 0xac540034 // sw $s4, 0x34($v0)
    .word 0x0c04bea0 // jal 0x12fa80
    .word 0xac550038 // sw $s5, 0x38($v0)
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
extern KtFileContext D_004F97D8;

void func_0012FAC8(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1) {
    func_0012FA20();
    D_004F97D8.field_3C = t0;
    D_004F97D8.field_2C = a0;
    D_004F97D8.field_30 = a1;
    D_004F97D8.field_34 = a2;
    D_004F97D8.field_38 = a3;
    func_0012FA80(a0, a1, a2, a3, t0, t1);
}
#endif

}
