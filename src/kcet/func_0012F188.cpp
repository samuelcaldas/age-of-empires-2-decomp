#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void *func_0012F188(const char *name, void *entries, int count) {
    .word 0x27bdffa0 // 0012F188:  addiu $sp, $sp, -0x60
    .word 0xffb40040 // 0012F18C:  sd $s4, 0x40($sp)
    .word 0xffb30030 // 0012F190:  sd $s3, 0x30($sp)
    .word 0x0080a02d // 0012F194:  move $s4, $a0
    .word 0xffb20020 // 0012F198:  sd $s2, 0x20($sp)
    .word 0x00c0982d // 0012F19C:  move $s3, $a2
    .word 0xffb10010 // 0012F1A0:  sd $s1, 0x10($sp)
    .word 0x0000902d // 0012F1A4:  move $s2, $zero
    .word 0xffb00000 // 0012F1A8:  sd $s0, ($sp)
    .word 0x0000882d // 0012F1AC:  move $s1, $zero
    .word 0xffbf0050 // 0012F1B0:  sd $ra, 0x50($sp)
    .word 0x10000003 // 0012F1B4:  b 0x12f1c4
    .word 0x00a0802d // 0012F1B8:  move $s0, $a1
    .word 0x00000000 // 0012F1BC:  nop 
    .word 0x26100040 // 0012F1C0:  addiu $s0, $s0, 0x40
    .word 0x0233102a // 0012F1C4:  slt $v0, $s1, $s3
    .word 0x10400006 // 0012F1C8:  beqz $v0, 0x12f1e4
    .word 0x0280202d // 0012F1CC:  move $a0, $s4
    .word 0x0c046a9e // 0012F1D0:  jal 0x11aa78
    .word 0x26050020 // 0012F1D4:  addiu $a1, $s0, 0x20
    .word 0x1440fff9 // 0012F1D8:  bnez $v0, 0x12f1c0
    .word 0x26310001 // 0012F1DC:  addiu $s1, $s1, 1
    .word 0x0200902d // 0012F1E0:  move $s2, $s0
    .word 0x0240102d // 0012F1E4:  move $v0, $s2
    .word 0xdfbf0050 // 0012F1E8:  ld $ra, 0x50($sp)
    .word 0xdfb40040 // 0012F1EC:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 0012F1F0:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012F1F4:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012F1F8:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012F1FC:  ld $s0, ($sp)
    .word 0x03e00008 // 0012F200:  jr $ra
    .word 0x27bd0060 // 0012F204:  addiu $sp, $sp, 0x60
}
#else
int strcmp(const char *s1, const char *s2);

void *func_0012F188(const char *name, char *entries, int count) {
    int i;
    for (i = 0; i < count; i++, entries += 0x40) {
        if (strcmp(name, entries + 0x20) == 0) {
            return entries;
        }
    }
    return 0;
}
#endif

}
