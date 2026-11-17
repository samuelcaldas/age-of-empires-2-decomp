#pragma exceptions off

typedef signed int s32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012F7C8(s32 a0) {
    .word 0x10800005 // beqz $a0, 0x12f7e0
    .word 0x0000282d // move $a1, $zero
    .word 0x28830004 // slti $v1, $a0, 4
    .word 0x24050001 // addiu $a1, $zero, 1
    .word 0x24020002 // addiu $v0, $zero, 2
    .word 0x0043280a // movz $a1, $v0, $v1
    .word 0x03e00008 // jr $ra
    .word 0x00a0102d // move $v0, $a1
}
#else
s32 func_0012F7C8(s32 a0) {
    if (a0 == 0) return 0;
    return (a0 < 4) ? 1 : 2;
}
#endif

}
