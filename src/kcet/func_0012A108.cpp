extern "C" {

#if defined(__mips__)
asm int func_0012A108(int a0, int a1) {
    .word 0x27bdffc0 // addiu $sp, $sp, -0x40
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x0000902d // move $s2, $zero
    .word 0xffbf0030 // sd $ra, 0x30($sp)
    .word 0x00a0802d // move $s0, $a1
    .word 0x1200000f // beqz $s0, 0x12a160
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x0c04a756 // jal 0x129d58
    .word 0x00000000 // nop
    .word 0x0040882d // move $s1, $v0
    .word 0x0200202d // move $a0, $s0
    .word 0x0c04b700 // jal 0x12dc00
    .word 0x0220282d // move $a1, $s1
    .word 0x54400007 // bnel $v0, $zero, 0x12a160
    .word 0x24120001 // addiu $s2, $zero, 1
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x0220282d // move $a1, $s1
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484f9a0 // addiu $a0, $a0, -0x660
    .word 0x10000002 // b 0x12a164
    .word 0x0240102d // move $v0, $s2
    .word 0x0240102d // move $v0, $s2
    .word 0xdfbf0030 // ld $ra, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0040 // addiu $sp, $sp, 0x40
}
#else
int func_00129D58(void);
int func_0012DC00(int, int);
void func_118de0(const char *, ...);
extern const char D_0048F9A0[];

int func_0012A108(int a0, int a1) {
    int s2 = 0;
    if (a1 != 0) {
        int s1 = func_00129D58();
        if (func_0012DC00(a1, s1) == 0) {
            s2 = 1;
            func_118de0(D_0048F9A0, s1);
        } else {
            s2 = 1;
        }
    }
    return s2;
}
#endif

}
