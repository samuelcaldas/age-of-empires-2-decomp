#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

extern "C" {

void func_0012F6B0(void);
void func_0012EFD8(void *a0, s32 a1, s32 a2);

#if defined(__mips__)
asm void func_0012F0A0(void *a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    .word 0x27bdffc0 // 0012F0A0:  addiu $sp, $sp, -0x40
    .word 0xffb20020 // 0012F0A4:  sd $s2, 0x20($sp)
    .word 0xffb10010 // 0012F0A8:  sd $s1, 0x10($sp)
    .word 0x00e0902d // 0012F0AC:  move $s2, $a3
    .word 0xffb00000 // 0012F0B0:  sd $s0, ($sp)
    .word 0x0100882d // 0012F0B4:  move $s1, $t0
    .word 0x0080802d // 0012F0B8:  move $s0, $a0
    .word 0x1200000c // 0012F0BC:  beqz $s0, 0x12f0f0
    .word 0xffbf0030 // 0012F0C0:  sd $ra, 0x30($sp)
    .word 0x0c04bdac // 0012F0C4:  jal 0x12f6b0
    .word 0x00000000 // 0012F0C8:  nop
    .word 0x0200202d // 0012F0CC:  move $a0, $s0
    .word 0x0220282d // 0012F0D0:  move $a1, $s1
    .word 0x0240302d // 0012F0D4:  move $a2, $s2
    .word 0xdfbf0030 // 0012F0D8:  ld $ra, 0x30($sp)
    .word 0xdfb20020 // 0012F0DC:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012F0E0:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012F0E4:  ld $s0, ($sp)
    .word 0x0804bbf6 // 0012F0E8:  j 0x12efd8
    .word 0x27bd0040 // 0012F0EC:  addiu $sp, $sp, 0x40
    .word 0xdfbf0030 // 0012F0F0:  ld $ra, 0x30($sp)
    .word 0xdfb20020 // 0012F0F4:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012F0F8:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012F0FC:  ld $s0, ($sp)
    .word 0x03e00008 // 0012F100:  jr $ra
    .word 0x27bd0040 // 0012F104:  addiu $sp, $sp, 0x40
}
#else
void func_0012F0A0(void *a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    if (a0 != 0) {
        func_0012F6B0();
        func_0012EFD8(a0, t0, a3);
    }
}
#endif

}
