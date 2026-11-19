extern "C" {

#if defined(__mips__)
asm void func_00105948(void) {
    .word 0x27bdfff0 // 00105948:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0010594C:  sd $ra, ($sp)
    .word 0x0c0412bc // 00105950:  jal 0x104af0
    .word 0x00000000 // 00105954:  nop 
    .word 0x0000000f // 00105958:  sync 
    .word 0xdfbf0000 // 0010595C:  ld $ra, ($sp)
    .word 0x03e00008 // 00105960:  jr $ra
    .word 0x27bd0010 // 00105964:  addiu $sp, $sp, 0x10
}
#else
void func_00104AF0(void);

void func_00105948(void) {
    func_00104AF0();
}
#endif

}
