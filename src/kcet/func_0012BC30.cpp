extern "C" {

#if defined(__mips__)
asm void func_0012BC30(void) {
    .word 0x3c03004f // lui $v1, 0x4f
    .word 0x24020016 // addiu $v0, $zero, 0x16
    .word 0x03e00008 // jr $ra
    .word 0xac62d368 // sw $v0, -0x2c98($v1)
}
#else
extern int D_004ED368;

void func_0012BC30(void) {
    D_004ED368 = 0x16;
}
#endif

}
