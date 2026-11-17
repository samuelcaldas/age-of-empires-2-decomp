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
};

extern "C" {

void func_0012FA20(void);
void func_001300D8(void* a0, void* a1, void* a2);

#if defined(__mips__)
asm void func_00130108(void* a0, void* a1, void* a2) {
    .word 0x27bdffc0 // addiu $sp, $sp, -0x40
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x00c0902d // move $s2, $a2
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x0080882d // move $s1, $a0
    .word 0xffbf0030 // sd $ra, 0x30($sp)
    .word 0x0c04be88 // jal 0x12fa20
    .word 0x00a0802d // move $s0, $a1
    .word 0x3c020050 // lui $v0, 0x50
    .word 0x0220202d // move $a0, $s1
    .word 0x244297d8 // addiu $v0, $v0, -0x6828
    .word 0x0200282d // move $a1, $s0
    .word 0xac500030 // sw $s0, 0x30($v0)
    .word 0x0240302d // move $a2, $s2
    .word 0x0c04c036 // jal 0x1300d8
    .word 0xac51002c // sw $s1, 0x2c($v0)
    .word 0xdfbf0030 // ld $ra, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0040 // addiu $sp, $sp, 0x40
}
#else
extern KtFileContext D_004F97D8;

void func_00130108(void* a0, void* a1, void* a2) {
    func_0012FA20();
    D_004F97D8.field_30 = (s32)a1;
    D_004F97D8.field_2C = (s32)a0;
    func_001300D8(a0, a1, a2);
}
#endif

}
