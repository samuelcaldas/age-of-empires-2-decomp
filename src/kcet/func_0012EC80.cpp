#pragma exceptions off

typedef signed int s32;
typedef unsigned char u8;

extern "C" {
#if defined(__mips__)
asm s32 func_0012EC80(void *a0) {
    .word 0x8c83001c // lw $v1, 0x1c($a0)
    .word 0x2402fffe // addiu $v0, $zero, -2
    .word 0x2404ff82 // addiu $a0, $zero, -0x7e
    .word 0x38630001 // xori $v1, $v1, 1
    .word 0x03e00008 // jr $ra
    .word 0x0083100b // movn $v0, $a0, $v1
}
#else
s32 func_0012EC80(u8 *a0) {
    s32 v1 = *(s32*)(a0 + 0x1c);
    return (v1 == 1) ? -2 : -0x7e;
}
#endif
}
