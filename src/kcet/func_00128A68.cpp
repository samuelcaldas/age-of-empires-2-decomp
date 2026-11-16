extern "C" {

#if defined(__mips__)
asm void func_00128A68(void) {
    .word 0x27bdfff0
    .word 0x8f848834
    .word 0x10800004
    .word 0xffbf0000
    .word 0x0c045bda
    .word 0x00000000
    .word 0xaf808834
    .word 0xdfbf0000
    .word 0x03e00008
    .word 0x27bd0010
}
#else
extern int s_state_77cc;
int func_116F68(int);

void func_00128A68(void) {
    if (s_state_77cc != 0) {
        func_116F68(s_state_77cc);
        s_state_77cc = 0;
    }
}
#endif

}
