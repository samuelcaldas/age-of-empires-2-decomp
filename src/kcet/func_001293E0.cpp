extern "C" {

#if defined(__mips__)
asm void func_001293E0(void) {
    .word 0x27bdffd0
    .word 0xffb10010
    .word 0xffb00000
    .word 0x8f918428
    .word 0x2410ffff
    .word 0x12300006
    .word 0xffbf0020
    .word 0x0c04a50a
    .word 0x24040001
    .word 0x0c04d130
    .word 0x0220202d
    .word 0xaf908428
    .word 0xdfbf0020
    .word 0xdfb10010
    .word 0xdfb00000
    .word 0x03e00008
    .word 0x27bd0030
}
#else
extern int D_004E8428;
void func_00129428(int);
void func_001344C0(int);

void func_001293E0(void) {
    if (D_004E8428 != -1) {
        func_00129428(1);
        func_001344C0(D_004E8428);
        D_004E8428 = -1;
    }
}
#endif

}
