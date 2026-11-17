#pragma exceptions off

typedef signed int s32;

extern "C" {

s32 func_0012FA08(s32 a0);
s32 func_001305D0(s32 a0, s32 a1);

#if defined(__mips__)
asm s32 func_00130630(s32 a0, s32 a1) {
    .word 0x27bdffe0 // addiu $sp, $sp, -0x20
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffbf0010 // sd $ra, 0x10($sp)
    .word 0x0c04be82 // jal 0x12fa08
    .word 0x00a0802d // move $s0, $a1
    .word 0x2403fff6 // addiu $v1, $zero, -0xa
    .word 0x14430004 // bne $v0, $v1, 0x13065c
    .word 0x2402ff82 // addiu $v0, $zero, -0x7e
    .word 0x0200202d // move $a0, $s0
    .word 0x0c04c174 // jal 0x1305d0
    .word 0x2405fff6 // addiu $a1, $zero, -0xa
    .word 0xdfbf0010 // ld $ra, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0020 // addiu $sp, $sp, 0x20
}
#else
s32 func_00130630(s32 a0, s32 a1) {
    if (func_0012FA08(a0) == -10) {
        return func_001305D0(a1, -10);
    }
    return -126;
}
#endif

}
