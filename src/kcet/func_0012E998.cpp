#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012E998(void) {
    .word 0x27bdffe0 // 0012E998:  addiu $sp, $sp, -0x20
    .word 0xffb00000 // 0012E99C:  sd $s0, ($sp)
    .word 0xffbf0010 // 0012E9A0:  sd $ra, 0x10($sp)
    .word 0x0c04bca6 // 0012E9A4:  jal 0x12f298
    .word 0x00c0802d // 0012E9A8:  move $s0, $a2
    .word 0x0200282d // 0012E9AC:  move $a1, $s0
    .word 0xdfbf0010 // 0012E9B0:  ld $ra, 0x10($sp)
    .word 0xdfb00000 // 0012E9B4:  ld $s0, ($sp)
    .word 0x0040202d // 0012E9B8:  move $a0, $v0
    .word 0x0804ba72 // 0012E9BC:  j 0x12e9c8
    .word 0x27bd0020 // 0012E9C0:  addiu $sp, $sp, 0x20
    .word 0x00000000 // 0012E9C4:  nop 
    .word 0x54800001 // 0012E9C8:  bnel $a0, $zero, 0x12e9d0
    .word 0xac85001c // 0012E9CC:  sw $a1, 0x1c($a0)
    .word 0x03e00008 // 0012E9D0:  jr $ra
    .word 0x00000000 // 0012E9D4:  nop 
}
#else

struct TargetStruct {
    char pad[28];
    s32 field_1c;
};

void *func_0012F298(void *a0, void *a1, s32 a2);

void func_0012E998(void *a0, void *a1, s32 a2) {
    TargetStruct *res = (TargetStruct *)func_0012F298(a0, a1, a2);
    if (res != 0) {
        res->field_1c = a2;
    }
}

#endif

}
