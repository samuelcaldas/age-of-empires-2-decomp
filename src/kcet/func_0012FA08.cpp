typedef signed int s32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012FA08(s32 a0) {
    .word 0x2403fff5 // addiu $v1, $zero, -0xb
    .word 0x2402fff6 // addiu $v0, $zero, -0xa
    .word 0x0064182a // slt $v1, $v1, $a0
    .word 0x03e00008 // jr $ra
    .word 0x0083100b // movn $v0, $a0, $v1
}
#else
s32 func_0012FA08(s32 a0) {
    if (a0 > -11) {
        return a0;
    }
    return -10;
}
#endif

}
