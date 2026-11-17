#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

struct Struct_12F208_arg1 {
    char pad[0x1c];
    char *ptr;
};

extern "C" {

#if defined(__mips__)
asm void *func_0012F208(const char *name, Struct_12F208_arg1 *arg1, int count) {
    .word 0x27bdffa0 // addiu $sp, $sp, -0x60
    .word 0xffb40040 // sd $s4, 0x40($sp)
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0x00c0a02d // move $s4, $a2
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0x0000982d // move $s3, $zero
    .word 0xffbf0050 // sd $ra, 0x50($sp)
    .word 0x0080902d // move $s2, $a0
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x12400010 // beqz $s2, 0x12f270
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x10a0000e // beqz $a1, 0x12f270
    .word 0x0000882d // move $s1, $zero
    .word 0x10000003 // b 0x12f24c
    .word 0x8cb0001c // lw $s0, 0x1c($a1)
    .word 0x00000000 // nop
    .word 0x26100020 // addiu $s0, $s0, 0x20
    .word 0x0234102a // slt $v0, $s1, $s4
    .word 0x10400007 // beqz $v0, 0x12f270
    .word 0x0240202d // move $a0, $s2
    .word 0x00112940 // sll $a1, $s1, 5
    .word 0x0c046a9e // jal 0x11aa78
    .word 0x02052821 // addu $a1, $s0, $a1
    .word 0x1440fff8 // bnez $v0, 0x12f248
    .word 0x26310001 // addiu $s1, $s1, 1
    .word 0x0200982d // move $s3, $s0
    .word 0x0260102d // move $v0, $s3
    .word 0xdfbf0050 // ld $ra, 0x50($sp)
    .word 0xdfb40040 // ld $s4, 0x40($sp)
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0060 // addiu $sp, $sp, 0x60
}
#else
int strcmp(const char *s1, const char *s2);

void *func_0012F208(const char *name, Struct_12F208_arg1 *arg1, int count) {
    if (name == 0 || arg1 == 0) {
        return 0;
    }
    char *entry = arg1->ptr;
    for (int i = 0; i < count; i++, entry += 0x20) {
        if (strcmp(name, entry) == 0) {
            return entry;
        }
    }
    return 0;
}
#endif

}
