extern "C" {

#if defined(__mips__)
asm int func_00105450(int a0, void *a1) {
    .word 0x27bdfff0 // addiu $sp, $sp, -0x10
    .word 0x24020001 // addiu $v0, $zero, 1
    .word 0x14820003 // bne   $a0, $v0, 0x105468
    .word 0xffbf0000 // sd    $ra, ($sp)
    .word 0x0c041250 // jal   0x104940
    .word 0x00a0202d // move  $a0, $a1
    .word 0xdfbf0000 // ld    $ra, ($sp)
    .word 0x0000102d // move  $v0, $zero
    .word 0x03e00008 // jr    $ra
    .word 0x27bd0010 // addiu $sp, $sp, 0x10
}
#else
void func_00104940(void *a0);

int func_00105450(int a0, void *a1) {
    if (a0 == 1) {
        func_00104940(a1);
    }
    return 0;
}
#endif

}
