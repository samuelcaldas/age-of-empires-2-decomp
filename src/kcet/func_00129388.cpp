extern "C" {

#if defined(__mips__)
asm void func_00129388(void) {
    .word 0x27bdfff0
    .word 0xffbf0000
    .word 0x0c04a4f8
    .word 0x00000000
    .word 0xaf80842c
    .word 0xdfbf0000
    .word 0x03e00008
    .word 0x27bd0010
}
#else
extern int D_004E842C;
void func_001293E0(void);

void func_00129388(void) {
    func_001293E0();
    D_004E842C = 0;
}
#endif

}
