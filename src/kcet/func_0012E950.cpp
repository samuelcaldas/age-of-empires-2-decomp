#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012E950(void) {
    .word 0x0804bdfe // 0012E950:  j 0x12f7f8
    .word 0x00000000 // 0012E954:  nop 
    .word 0x27bdffe0 // 0012E958:  addiu $sp, $sp, -0x20
    .word 0xffb00000 // 0012E95C:  sd $s0, ($sp)
    .word 0xffbf0010 // 0012E960:  sd $ra, 0x10($sp)
    .word 0x0c04bca6 // 0012E964:  jal 0x12f298
    .word 0x00c0802d // 0012E968:  move $s0, $a2
    .word 0x0200282d // 0012E96C:  move $a1, $s0
    .word 0xdfbf0010 // 0012E970:  ld $ra, 0x10($sp)
    .word 0xdfb00000 // 0012E974:  ld $s0, ($sp)
    .word 0x0040202d // 0012E978:  move $a0, $v0
    .word 0x0804ba62 // 0012E97C:  j 0x12e988
    .word 0x27bd0020 // 0012E980:  addiu $sp, $sp, 0x20
    .word 0x00000000 // 0012E984:  nop 
    .word 0x54800001 // 0012E988:  bnel $a0, $zero, 0x12e990
    .word 0xac850018 // 0012E98C:  sw $a1, 0x18($a0)
    .word 0x03e00008 // 0012E990:  jr $ra
    .word 0x00000000 // 0012E994:  nop 
}
#else

struct TargetStruct {
    char pad[24];
    s32 field_18;
};

void *func_0012F298(void *a0, void *a1, s32 a2);

void func_0012E950(void *a0, void *a1, s32 a2) {
    TargetStruct *res = (TargetStruct *)func_0012F298(a0, a1, a2);
    if (res != 0) {
        res->field_18 = a2;
    }
}

#endif

}
