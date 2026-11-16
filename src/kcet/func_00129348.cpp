extern "C" {

#if defined(__mips__)
asm void func_00129348(void) {
    .word 0x27bdffe0
    .word 0x8f82842c
    .word 0xffbf0010
    .word 0x14400007
    .word 0xffb00000
    .word 0xaf80882c
    .word 0x24100001
    .word 0xaf908830
    .word 0x0c04a4ea
    .word 0x00000000
    .word 0xaf90842c
    .word 0xdfbf0010
    .word 0xdfb00000
    .word 0x03e00008
    .word 0x27bd0020
}
#else
extern int D_004E842C;
extern int D_004E882C;
extern int D_004E8830;
void func_001293A8();

void func_00129348() {
    if (!D_004E842C) {
        D_004E882C = 0;
        D_004E8830 = 1;
        func_001293A8();
        D_004E842C = 1;
    }
}
#endif

}
