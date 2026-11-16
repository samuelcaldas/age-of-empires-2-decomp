extern "C" {

#if defined(__mips__)
asm void func_00129F58(void) {
    .word 0x3c03004f // lui $v1, 0x4f
    .word 0x03e00008 // jr $ra
    .word 0x8c62d310 // lw $v0, -0x2cf0($v1)
}
#else
extern int D_004ED310;

int func_00129F58(void) {
    return D_004ED310;
}
#endif

}
