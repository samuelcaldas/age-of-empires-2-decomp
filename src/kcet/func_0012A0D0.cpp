extern "C" {

#if defined(__mips__)
asm int func_0012A0D0(void) {
    .word 0x3c03004f // lui $v1, 0x4f
    .word 0x03e00008 // jr $ra
    .word 0x8c62d328 // lw $v0, -0x2cd8($v1)
}
#else
extern int D_004ED328;

int func_0012A0D0(void) {
    return D_004ED328;
}
#endif

}
