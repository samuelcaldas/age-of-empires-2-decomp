#pragma exceptions off

typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct KtTarget {
    u8 pad[0xc];
    s16 field_0C;
    s16 field_0E;
    u8 pad2[0x14];
    s32 field_24;
    s32 field_28;
    s32 field_2C;
};

struct KtFileContext {
    u8 pad[0x24];
    s32 field_24;
};

extern "C" {

s32 func_00110A78(s32 a0, s32 a1, void *a2, void *a3, void *t0);

#if defined(__mips__)
asm s32 func_001305D0(KtTarget *a0) {
    .word 0x27bdffe0 // addiu $sp, $sp, -0x20
    .word 0x3c030050 // lui $v1, 0x50
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x246397d8 // addiu $v1, $v1, -0x6828
    .word 0xffbf0010 // sd $ra, 0x10($sp)
    .word 0x0080382d // move $a3, $a0
    .word 0x8c620024 // lw $v0, 0x24($v1)
    .word 0x24420001 // addiu $v0, $v0, 1
    .word 0xac620024 // sw $v0, 0x24($v1)
    .word 0x28420004 // slti $v0, $v0, 4
    .word 0x10400008 // beqz $v0, 0x13061c
    .word 0x2410ff82 // addiu $s0, $zero, -0x7e
    .word 0x84e4000c // lh $a0, 0xc($a3)
    .word 0x24e8002c // addiu $t0, $a3, 0x2c
    .word 0x84e5000e // lh $a1, 0xe($a3)
    .word 0x24e60024 // addiu $a2, $a3, 0x24
    .word 0x0c04429e // jal 0x110a78
    .word 0x24e70028 // addiu $a3, $a3, 0x28
    .word 0x0002800a // movz $s0, $zero, $v0
    .word 0x0200102d // move $v0, $s0
    .word 0xdfbf0010 // ld $ra, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0020 // addiu $sp, $sp, 0x20
}
#else
extern KtFileContext D_004F97D8;

s32 func_001305D0(KtTarget *a0) {
    s32 s0 = -0x7e;
    D_004F97D8.field_24++;
    if (D_004F97D8.field_24 < 4) {
        if (!func_00110A78(a0->field_0C, a0->field_0E, &a0->field_24, &a0->field_28, &a0->field_2C)) {
            s0 = 0;
        }
    }
    return s0;
}
#endif

}
