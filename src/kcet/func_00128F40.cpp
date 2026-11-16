extern "C" {

#if defined(__mips__)
asm void func_00128F40(void) {
    .word 0x10800003
    .word 0x24020001
    .word 0x50820002
    .word 0xaf848838
    .word 0xaf808838
    .word 0x8f828838
    .word 0xaf82883c
    .word 0x03e00008
    .word 0x00000000
}
#else
extern int D_004E2FF8;
extern int D_004E2FFC;

void func_00128F40(int a0) {
    if (a0 == 0) {
        D_004E2FF8 = 0;
    } else if (a0 == 1) {
        D_004E2FF8 = a0;
    }
    D_004E2FFC = D_004E2FF8;
}
#endif

}
