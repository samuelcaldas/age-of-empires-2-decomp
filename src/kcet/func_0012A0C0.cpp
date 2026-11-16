extern "C" {

#if defined(__mips__)
asm int func_0012A0C0(void) {
    .word 0x3c03004f // lui $v1, 0x4f
    .word 0x03e00008 // jr $ra
    .word 0x8c62d32c // lw $v0, -0x2cd4($v1)
}
#else
extern int D_004ED32C;

int func_0012A0C0(void) {
    return D_004ED32C;
}
#endif

}
