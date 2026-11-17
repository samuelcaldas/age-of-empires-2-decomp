typedef signed int s32;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012F4C8(s32 a0, s32 a1) {
    .word 0x2484ffff // addiu $a0, $a0, -1
    .word 0x2403ffff // addiu $v1, $zero, -1
    .word 0x00852021 // addu $a0, $a0, $a1
    .word 0x0065182a // slt $v1, $v1, $a1
    .word 0x0085001a // div $zero, $a0, $a1
    .word 0x24a203ff // addiu $v0, $a1, 0x3ff
    .word 0x00a3100b // movn $v0, $a1, $v1
    .word 0x50a00001 // beql $a1, $zero, 0x12f4ec
    .word 0x000001cd // break 0, 7
    .word 0x00021283 // sra $v0, $v0, 0xa
    .word 0x00002012 // mflo $a0
    .word 0x03e00008 // jr $ra
    .word 0x00821018 // mult $ac2, $a0, $v0
}
#else
s32 func_0012F4C8(s32 a0, s32 a1) {
    s32 quotient = (a0 - 1 + a1) / a1;
    s32 factor;
    if (a1 >= 0) {
        factor = a1;
    } else {
        factor = a1 + 1023;
    }
    factor >>= 10;
    return quotient * factor;
}
#endif

}
