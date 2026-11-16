extern "C" {

#if defined(__mips__)
asm void func_001294A0(void) {
    .word 0x8f848428
    .word 0x2402ffff
    .word 0x10820003
    .word 0x00000000
    .word 0x0804d110
    .word 0x00000000
    .word 0x03e00008
    .word 0x00000000
}
#else
extern int D_004E8428;
void func_00134440(int);

void func_001294A0(void) {
    if (D_004E8428 != -1) {
        func_00134440(D_004E8428);
    }
}
#endif

}
