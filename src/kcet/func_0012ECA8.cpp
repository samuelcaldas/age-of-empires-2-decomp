
#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm const char *func_0012ECA8(s32 number) {
    .word 0x27bdffe0 // 0012ECA8:  addiu $sp, $sp, -0x20
    .word 0xffb00000 // 0012ECAC:  sd $s0, ($sp)
    .word 0x2490ffff // 0012ECB0:  addiu $s0, $a0, -1
    .word 0x2e020004 // 0012ECB4:  sltiu $v0, $s0, 4
    .word 0x14400009 // 0012ECB8:  bnez $v0, 0x12ece0
    .word 0xffbf0010 // 0012ECBC:  sd $ra, 0x10($sp)
    .word 0x3c040049 // 0012ECC0:  lui $a0, 0x49
    .word 0x3c050049 // 0012ECC4:  lui $a1, 0x49
    .word 0x3c070049 // 0012ECC8:  lui $a3, 0x49
    .word 0x24840210 // 0012ECCC:  addiu $a0, $a0, 0x210
    .word 0x24a50068 // 0012ECD0:  addiu $a1, $a1, 0x68
    .word 0x24e70250 // 0012ECD4:  addiu $a3, $a3, 0x250
    .word 0x0c048de4 // 0012ECD8:  jal 0x123790
    .word 0x240604bf // 0012ECDC:  addiu $a2, $zero, 0x4bf
    .word 0x3c020039 // 0012ECE0:  lui $v0, 0x39
    .word 0x00101880 // 0012ECE4:  sll $v1, $s0, 2
    .word 0x2442c8b0 // 0012ECE8:  addiu $v0, $v0, -0x3750
    .word 0xdfbf0010 // 0012ECEC:  ld $ra, 0x10($sp)
    .word 0x00621821 // 0012ECF0:  addu $v1, $v1, $v0
    .word 0xdfb00000 // 0012ECF4:  ld $s0, ($sp)
    .word 0x8c620000 // 0012ECF8:  lw $v0, ($v1)
    .word 0x03e00008 // 0012ECFC:  jr $ra
    .word 0x27bd0020 // 0012ED00:  addiu $sp, $sp, 0x20
}
#else
extern const char *D_38C8B0[];
void func_123790(const char *expr, const char *file, s32 line, const char *func);
const char *func_0012ECA8(s32 number) {
    if ((u32)(number - 1) >= 4) {
        func_123790((const char *)0x490210, (const char *)0x490068, 0x4BF, (const char *)0x490250);
    }
    return D_38C8B0[number - 1];
}
#endif

}
