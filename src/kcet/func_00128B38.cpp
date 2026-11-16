typedef signed int s32;

extern "C" {

#if defined(__mips__)
asm void func_00128B38(void) {
    .word 0x27bdfff0
    .word 0x10000004
    .word 0xffbf0000
    .word 0x00000000
    .word 0x0c040cd6
    .word 0x0000202d
    .word 0x0c04a2a4
    .word 0x00000000
    .word 0x1040fffb
    .word 0xdfbf0000
    .word 0x03e00008
    .word 0x27bd0010
}
#else
s32 func_00128A90(void);
void func_00103358(s32);

void func_00128B38(void) {
    while (!func_00128A90()) {
        func_00103358(0);
    }
}
#endif

}
