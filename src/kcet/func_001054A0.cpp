typedef signed int s32;

extern "C" {

#if defined(__mips__)
asm s32 func_001054A0(void) {
    .word 0x27bdfff0 // 001054A0:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 001054A4:  sd $ra, ($sp)
    .word 0x0c04564a // 001054A8:  jal 0x115928
    .word 0x00000000 // 001054AC:  nop 
    .word 0x24030005 // 001054B0:  addiu $v1, $zero, 5
    .word 0xdfbf0000 // 001054B4:  ld $ra, ($sp)
    .word 0xac430000 // 001054B8:  sw $v1, ($v0)
    .word 0x2402ffff // 001054BC:  addiu $v0, $zero, -1
    .word 0x03e00008 // 001054C0:  jr $ra
    .word 0x27bd0010 // 001054C4:  addiu $sp, $sp, 0x10
}
#else
s32 *func_00115928(void);

s32 func_001054A0(void) {
    s32 *ptr = func_00115928();
    *ptr = 5;
    return -1;
}
#endif

}
