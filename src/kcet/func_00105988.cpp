extern "C" {

#if defined(__mips__)
asm void func_00105988(void) {
    .word 0x00063082 // 00105988:  srl $a2, $a2, 2
    .word 0x10c0000a // 0010598C:  beqz $a2, 0x1059b8
    .word 0x0000382d // 00105990:  move $a3, $zero
    .word 0x00000000 // 00105994:  nop 
    .word 0x8ca30000 // 00105998:  lw $v1, ($a1)
    .word 0x24e70001 // 0010599C:  addiu $a3, $a3, 1
    .word 0x24a50004 // 001059A0:  addiu $a1, $a1, 4
    .word 0x00e6102b // 001059A4:  sltu $v0, $a3, $a2
    .word 0xac830000 // 001059A8:  sw $v1, ($a0)
    .word 0x24840004 // 001059AC:  addiu $a0, $a0, 4
    .word 0x1440fff9 // 001059B0:  bnez $v0, 0x105998
    .word 0x00000000 // 001059B4:  nop 
    .word 0x03e00008 // 001059B8:  jr $ra
    .word 0x0000102d // 001059BC:  move $v0, $zero
}
#else
void *func_00105988(void *dst, const void *src, unsigned int size) {
    unsigned int words = size >> 2;
    if (words != 0) {
        unsigned int *d = (unsigned int *)dst;
        const unsigned int *s = (const unsigned int *)src;
        for (unsigned int i = 0; i < words; i++) {
            *d++ = *s++;
        }
    }
    return 0;
}
#endif

}
