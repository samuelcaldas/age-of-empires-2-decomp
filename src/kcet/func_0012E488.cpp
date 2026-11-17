#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm u32 func_0012E488(u32 a0) {
    .word 0x27bdffd0 // 0012E488:  addiu $sp, $sp, -0x30
    .word 0x3c02ffff // 0012E48C:  lui $v0, 0xffff
    .word 0x0002103e // 0012E490:  dsrl32 $v0, $v0, 0
    .word 0xffb00010 // 0012E494:  sd $s0, 0x10($sp)
    .word 0xafa40000 // 0012E498:  sw $a0, ($sp)
    .word 0x0000802d // 0012E49C:  move $s0, $zero
    .word 0xffbf0020 // 0012E4A0:  sd $ra, 0x20($sp)
    .word 0x8fa40000 // 0012E4A4:  lw $a0, ($sp)
    .word 0x0c04b93a // 0012E4A8:  jal 0x12e4e8
    .word 0x00822024 // 0012E4AC:  and $a0, $a0, $v0
    .word 0x0040182d // 0012E4B0:  move $v1, $v0
    .word 0x10600007 // 0012E4B4:  beqz $v1, 0x12e4d4
    .word 0x0200102d // 0012E4B8:  move $v0, $s0
    .word 0x8c62000c // 0012E4BC:  lw $v0, 0xc($v1)
    .word 0x30500003 // 0012E4C0:  andi $s0, $v0, 3
    .word 0x34420003 // 0012E4C4:  ori $v0, $v0, 3
    .word 0x38420003 // 0012E4C8:  xori $v0, $v0, 3
    .word 0xac62000c // 0012E4CC:  sw $v0, 0xc($v1)
    .word 0x0200102d // 0012E4D0:  move $v0, $s0
    .word 0xdfbf0020 // 0012E4D4:  ld $ra, 0x20($sp)
    .word 0xdfb00010 // 0012E4D8:  ld $s0, 0x10($sp)
    .word 0x03e00008 // 0012E4DC:  jr $ra
    .word 0x27bd0030 // 0012E4E0:  addiu $sp, $sp, 0x30
}
#else

struct TargetStruct {
    u8 pad[12];
    u32 val;
};

void *func_0012E4E8(u32 a0);

u32 func_0012E488(u32 a0) {
    TargetStruct *entry = (TargetStruct *)func_0012E4E8(a0 & 0xffff0000);
    u32 ret = 0;
    if (entry != 0) {
        ret = entry->val & 3;
        entry->val = (entry->val | 3) ^ 3;
    }
    return ret;
}

#endif

}
