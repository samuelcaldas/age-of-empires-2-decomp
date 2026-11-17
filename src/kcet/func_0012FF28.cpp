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
};

extern "C" {

void func_0012FA20(void);
void func_0012FEF8(s32 a0, s32 a1, s32 a2, s32 a3);

#if defined(__mips__)
asm void func_0012FF28(s32 a0, s32 a1, s32 a2, s32 a3) {
    .word 0x27bdffb0 // addiu $sp, $sp, -0x50
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0x00e0982d // move $s3, $a3
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x00a0902d // move $s2, $a1
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x0080882d // move $s1, $a0
    .word 0xffbf0040 // sd $ra, 0x40($sp)
    .word 0x0c04be88 // jal 0x12fa20
    .word 0x00c0802d // move $s0, $a2
    .word 0x3c020050 // lui $v0, 0x50
    .word 0x0220202d // move $a0, $s1
    .word 0x244297d8 // addiu $v0, $v0, -0x6828
    .word 0x0240282d // move $a1, $s2
    .word 0xac500034 // sw $s0, 0x34($v0)
    .word 0x0200302d // move $a2, $s0
    .word 0x0260382d // move $a3, $s3
    .word 0xac51002c // sw $s1, 0x2c($v0)
    .word 0x0c04bfbe // jal 0x12fef8
    .word 0xac520030 // sw $s2, 0x30($v0)
    .word 0xdfbf0040 // ld $ra, 0x40($sp)
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0050 // addiu $sp, $sp, 0x50
}
#else
extern KtFileContext D_004F97D8;

void func_0012FF28(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_0012FA20();
    D_004F97D8.field_34 = a2;
    D_004F97D8.field_2C = a0;
    D_004F97D8.field_30 = a1;
    func_0012FEF8(a0, a1, a2, a3);
}
#endif

}
