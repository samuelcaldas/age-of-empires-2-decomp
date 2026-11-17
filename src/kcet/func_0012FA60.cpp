#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012FA60(s32 a0, void *a1) {
    .word 0x3c020050 // lui $v0, 0x50
    .word 0xac4097fc // sw $zero, -0x6804($v0)
    .word 0x14800003 // bnez $a0, 0x12fa78
    .word 0x0000102d // move $v0, $zero
    .word 0xaca00008 // sw $zero, 8($a1)
    .word 0x2402ff81 // addiu $v0, $zero, -0x7f
    .word 0x03e00008 // jr $ra
    .word 0x00000000 // nop
}
#else
extern u32 D_004F97FC;

s32 func_0012FA60(s32 a0, s32 *a1) {
    D_004F97FC = 0;
    if (a0 == 0) {
        a1[2] = 0;
        return -0x7f;
    }
    return 0;
}
#endif

}
