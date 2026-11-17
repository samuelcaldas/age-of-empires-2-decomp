#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s16 func_0012E448(u32 a0) {
    .word 0x27bdffe0 // 0012E448:  addiu $sp, $sp, -0x20
    .word 0x3c02ffff // 0012E44C:  lui $v0, 0xffff
    .word 0x0002103e // 0012E450:  dsrl32 $v0, $v0, 0
    .word 0xafa40000 // 0012E454:  sw $a0, ($sp)
    .word 0xffbf0010 // 0012E458:  sd $ra, 0x10($sp)
    .word 0x8fa40000 // 0012E45C:  lw $a0, ($sp)
    .word 0x0c04b93a // 0012E460:  jal 0x12e4e8
    .word 0x00822024 // 0012E464:  and $a0, $a0, $v0
    .word 0x10400002 // 0012E468:  beqz $v0, 0x12e474
    .word 0x2403ffff // 0012E46C:  addiu $v1, $zero, -1
    .word 0x84430006 // 0012E470:  lh $v1, 6($v0)
    .word 0xdfbf0010 // 0012E474:  ld $ra, 0x10($sp)
    .word 0x0060102d // 0012E478:  move $v0, $v1
    .word 0x03e00008 // 0012E47C:  jr $ra
    .word 0x27bd0020 // 0012E480:  addiu $sp, $sp, 0x20
}
#else

struct TargetStruct {
    u8 pad[6];
    s16 val;
};

void *func_0012E4E8(u32 a0);

s16 func_0012E448(u32 a0) {
    TargetStruct *entry = (TargetStruct *)func_0012E4E8(a0 & 0xffff0000);
    if (entry != 0) {
        return entry->val;
    }
    return -1;
}

#endif

}
