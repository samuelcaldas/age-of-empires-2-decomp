extern "C" {

#if defined(__mips__)
asm void func_00129EE0(void) {
    .word 0x3c03004f // lui $v1, 0x4f
    .word 0x03e00008 // jr $ra
    .word 0x8c62d314 // lw $v0, -0x2cec($v1)
}
#else
extern int D_004ED314;

int func_00129EE0(void) {
    return D_004ED314;
}
#endif

}
