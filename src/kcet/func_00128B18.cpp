extern "C" {

#if defined(__mips__)
asm void func_00128B18(void) {
    .word 0x27bdfff0
    .word 0xffbf0000
    .word 0x0c04a2a4
    .word 0x00000000
    .word 0xdfbf0000
    .word 0x03e00008
    .word 0x27bd0010
}
#else
void func_00128A90(void);

void func_00128B18(void) {
    func_00128A90();
}
#endif

}
