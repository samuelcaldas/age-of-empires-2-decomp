extern "C" {

#if defined(__mips__)
asm void func_00105928(void) {
    .word 0x27bdfff0 // 00105928:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0010592C:  sd $ra, ($sp)
    .word 0x0c0412b8 // 00105930:  jal 0x104ae0
    .word 0x00000000 // 00105934:  nop 
    .word 0x0000000f // 00105938:  sync 
    .word 0xdfbf0000 // 0010593C:  ld $ra, ($sp)
    .word 0x03e00008 // 00105940:  jr $ra
    .word 0x27bd0010 // 00105944:  addiu $sp, $sp, 0x10
}
#else
void func_00104ae0(void);

void func_00105928(void) {
    func_00104ae0();
}
#endif

}
