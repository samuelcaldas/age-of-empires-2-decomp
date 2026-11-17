#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Struct_12F6F8 {
    u8 pad0[0x34];
    void *field34;
    u8 pad38[0xb0 - 0x38];
    struct Inner {
        u8 pad0[4];
        s32 val;
    } *fieldB0;
};

extern "C" {

s32 func_0012F7A0(void *a0, s32 a1);

#if defined(__mips__)
asm s32 func_0012F6F8(Struct_12F6F8 *a0, s32 a1, s32 a2, s32 a3) {
    .word 0x27bdffb0 // addiu $sp, $sp, -0x50
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0x00e0982d // move $s3, $a3
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x0080902d // move $s2, $a0
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x00c0882d // move $s1, $a2
    .word 0xffbf0040 // sd $ra, 0x40($sp)
    .word 0x00a0802d // move $s0, $a1
    .word 0x24050032 // addiu $a1, $zero, 0x32
    .word 0x0c04bde8 // jal 0x12f7a0
    .word 0x8e440034 // lw $a0, 0x34($s2)
    .word 0x10400006 // beqz $v0, 0x12f748
    .word 0x26030001 // addiu $v1, $s0, 1
    .word 0x8e4200b0 // lw $v0, 0xb0($s2)
    .word 0x0073800b // movn $s0, $v1, $s3
    .word 0x24040001 // addiu $a0, $zero, 1
    .word 0xac500004 // sw $s0, 4($v0)
    .word 0x0091880a // movz $s1, $a0, $s1
    .word 0x0220102d // move $v0, $s1
    .word 0xdfbf0040 // ld $ra, 0x40($sp)
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0050 // addiu $sp, $sp, 0x50
}
#else
s32 func_0012F6F8(Struct_12F6F8 *a0, s32 a1, s32 a2, s32 a3) {
    s32 ret = a2;
    if (func_0012F7A0(a0->field34, 0x32)) {
        if (a3 != 0) {
            a1++;
        }
        a0->fieldB0->val = a1;
        if (a2 == 0) {
            ret = 1;
        }
    }
    return ret;
}
#endif

}
