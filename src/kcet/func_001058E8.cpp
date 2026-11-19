extern "C" {

#if defined(__mips__)
asm void func_001058E8(void) {
    .word 0x27bdfff0 // 001058E8:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 001058EC:  sd $ra, ($sp)
    .word 0x0c0412b0 // 001058F0:  jal 0x104ac0
    .word 0x00000000 // 001058F4:  nop 
    .word 0x0000000f // 001058F8:  sync 
    .word 0xdfbf0000 // 001058FC:  ld $ra, ($sp)
    .word 0x03e00008 // 00105900:  jr $ra
    .word 0x27bd0010 // 00105904:  addiu $sp, $sp, 0x10
}
#else
void func_00104AC0(void);

void func_001058E8(void) {
    func_00104AC0();
}
#endif

}
