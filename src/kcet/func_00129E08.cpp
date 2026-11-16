extern "C" {

#if defined(__mips__)
asm void func_00129E08(void) {
    .word 0x27bdffb0
    .word 0xffb30030
    .word 0xffb20020
    .word 0x00c0982d
    .word 0xffb10010
    .word 0x0080902d
    .word 0xffb00000
    .word 0xffbf0040
    .word 0x0c04a828
    .word 0x00a0882d
    .word 0x0c04a82c
    .word 0x0040802d
    .word 0x0220202d
    .word 0x0240282d
    .word 0x0200302d
    .word 0x0260402d
    .word 0xdfbf0040
    .word 0x0040382d
    .word 0xdfb30030
    .word 0xdfb20020
    .word 0xdfb10010
    .word 0xdfb00000
    .word 0x0804a6f8
    .word 0x27bd0050
}
#else
int func_0012A0A0(void);
int func_0012A0B0(void);
int func_00129BE0(int a0, int a1, int a2, int a3, int t0);

int func_00129E08(int a0, int a1, int a2) {
    int v0_1 = func_0012A0A0();
    int v0_2 = func_0012A0B0();
    return func_00129BE0(a1, a0, v0_1, v0_2, a2);
}
#endif

}
