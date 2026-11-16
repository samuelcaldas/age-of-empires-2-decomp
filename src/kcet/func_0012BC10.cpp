extern "C" {

#if defined(__mips__)
asm int func_0012BC10(void) {
    .word 0x3c03004f // lui $v1, 0x4f
    .word 0x03e00008 // jr $ra
    .word 0x8c62d348 // lw $v0, -0x2cb8($v1)
}
#else
extern int D_004ED348;

int func_0012BC10(void) {
    return D_004ED348;
}
#endif

}
