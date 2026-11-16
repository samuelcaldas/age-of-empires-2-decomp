extern "C" {

#if defined(__mips__)
asm int func_0012A0F8(void) {
    .word 0x3c03004f // lui $v1, 0x4f
    .word 0x03e00008 // jr $ra
    .word 0x8c62d330 // lw $v0, -0x2cd0($v1)
}
#else
extern int D_004ED330;

int func_0012A0F8(void) {
    return D_004ED330;
}
#endif

}
