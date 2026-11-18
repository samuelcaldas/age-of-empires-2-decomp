#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct GsModeInfo {
    s16 field_0;
    s16 field_2;
    s16 field_4;
    s16 field_6;
};

extern "C" {

GsModeInfo *func_00102818(void);

#if defined(__mips__)
asm s32 func_00102BC0(s16 a0, s16 a1, s16 a2) {
    .word 0x27bdffc0 // addiu $sp, $sp, -0x40
    .word 0x00063400 // sll $a2, $a2, 0x10
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x00048c00 // sll $s1, $a0, 0x10
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0x00058400 // sll $s0, $a1, 0x10
    .word 0x00108403 // sra $s0, $s0, 0x10
    .word 0x00118c03 // sra $s1, $s1, 0x10
    .word 0xffbf0030 // sd $ra, 0x30($sp)
    .word 0x0c040a06 // jal 0x102818
    .word 0x00069403 // sra $s2, $a2, 0x10
    .word 0x2603003f // addiu $v1, $s0, 0x3f
    .word 0x0040282d // move $a1, $v0
    .word 0x2404ffff // addiu $a0, $zero, -1
    .word 0x2610007e // addiu $s0, $s0, 0x7e
    .word 0x0083102a // slt $v0, $a0, $v1
    .word 0x32310002 // andi $s1, $s1, 2
    .word 0x0062800b // movn $s0, $v1, $v0
    .word 0x12200007 // beqz $s1, 0x102c2c
    .word 0x00108183 // sra $s0, $s0, 6
    .word 0x2642003f // addiu $v0, $s2, 0x3f
    .word 0x2643007e // addiu $v1, $s2, 0x7e
    .word 0x0082202a // slt $a0, $a0, $v0
    .word 0x0044180b // movn $v1, $v0, $a0
    .word 0x10000006 // b 0x102c40
    .word 0x00033183 // sra $a2, $v1, 6
    .word 0x2642001f // addiu $v0, $s2, 0x1f
    .word 0x2643003e // addiu $v1, $s2, 0x3e
    .word 0x0082202a // slt $a0, $a0, $v0
    .word 0x0044180b // movn $v1, $v0, $a0
    .word 0x00033143 // sra $a2, $v1, 5
    .word 0xdca20000 // ld $v0, ($a1)
    .word 0x3403ffff // ori $v1, $zero, 0xffff
    .word 0x0003183c // dsll32 $v1, $v1, 0
    .word 0x3463ffff // ori $v1, $v1, 0xffff
    .word 0x24040001 // addiu $a0, $zero, 1
    .word 0x00431024 // and $v0, $v0, $v1
    .word 0x14440003 // bne $v0, $a0, 0x102c68
    .word 0x02061018 // mult $ac2, $s0, $a2
    .word 0x10000002 // b 0x102c6c
    .word 0x00021400 // sll $v0, $v0, 0x10
    .word 0x00021440 // sll $v0, $v0, 0x11
    .word 0x00021403 // sra $v0, $v0, 0x10
    .word 0xdfbf0030 // ld $ra, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0040 // addiu $sp, $sp, 0x40
}
#else
s32 func_00102BC0(s16 a0, s16 a1, s16 a2) {
    GsModeInfo *mode = func_00102818();
    s32 w;
    s32 h;

    if (a1 >= 0) {
        w = (a1 + 0x3F) >> 6;
    } else {
        w = (a1 + 0x7E) >> 6;
    }

    if (a0 & 2) {
        if (a2 >= 0) {
            h = (a2 + 0x3F) >> 6;
        } else {
            h = (a2 + 0x7E) >> 6;
        }
    } else {
        if (a2 >= 0) {
            h = (a2 + 0x1F) >> 5;
        } else {
            h = (a2 + 0x3E) >> 5;
        }
    }

    u64 val = *(u64 *)mode;
    if ((val & 0xFFFFFFFFULL) == 1) {
        return (w * h) << 16;
    } else {
        return (w * h) << 17;
    }
}
#endif

}
