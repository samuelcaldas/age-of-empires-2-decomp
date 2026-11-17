#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s16 func_0012E3C8(u32 a0) {
    .word 0x27bdffe0 // 0012E3C8:  addiu $sp, $sp, -0x20
    .word 0x3c02ffff // 0012E3CC:  lui $v0, 0xffff
    .word 0x0002103e // 0012E3D0:  dsrl32 $v0, $v0, 0
    .word 0xafa40000 // 0012E3D4:  sw $a0, ($sp)
    .word 0xffbf0010 // 0012E3D8:  sd $ra, 0x10($sp)
    .word 0x8fa40000 // 0012E3DC:  lw $a0, ($sp)
    .word 0x0c04b93a // 0012E3E0:  jal 0x12e4e8
    .word 0x00822024 // 0012E3E4:  and $a0, $a0, $v0
    .word 0x10400002 // 0012E3E8:  beqz $v0, 0x12e3f4
    .word 0x0000182d // 0012E3EC:  move $v1, $zero
    .word 0x84430004 // 0012E3F0:  lh $v1, 4($v0)
    .word 0xdfbf0010 // 0012E3F4:  ld $ra, 0x10($sp)
    .word 0x0060102d // 0012E3F8:  move $v0, $v1
    .word 0x03e00008 // 0012E3FC:  jr $ra
    .word 0x27bd0020 // 0012E400:  addiu $sp, $sp, 0x20
}
#else

struct TargetStruct {
    u8 pad[4];
    s16 val;
};

void *func_0012E4E8(u32 a0);

s16 func_0012E3C8(u32 a0) {
    TargetStruct *entry = (TargetStruct *)func_0012E4E8(a0 & 0xffff0000);
    if (entry != 0) {
        return entry->val;
    }
    return 0;
}

#endif

}
