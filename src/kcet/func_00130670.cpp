#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_00130670(u32 a0, void *a1) {
    .word 0x27bdff80 // addiu $sp, $sp, -0x80
    .word 0x3c030050 // lui $v1, 0x50
    .word 0xffb40060 // sd $s4, 0x60($sp)
    .word 0x3c020050 // lui $v0, 0x50
    .word 0xffb20040 // sd $s2, 0x40($sp)
    .word 0xffb10030 // sd $s1, 0x30($sp)
    .word 0x24529700 // addiu $s2, $v0, -0x6900
    .word 0xffbf0070 // sd $ra, 0x70($sp)
    .word 0x00a0882d // move $s1, $a1
    .word 0xffb00020 // sd $s0, 0x20($sp)
    .word 0x8c7497d8 // lw $s4, -0x6828($v1)
    .word 0xffb30050 // sd $s3, 0x50($sp)
    .word 0x246397d8 // addiu $v1, $v1, -0x6828
    .word 0x8c469700 // lw $a2, -0x6900($v0)
    .word 0x8c730004 // lw $s3, 4($v1)
    .word 0x0000102d // move $v0, $zero
    .word 0x14c0001c // bnez $a2, 0x130724
    .word 0xafa40000 // sw $a0, ($sp)
    .word 0x0c04bbc6 // jal 0x12ef18
    .word 0x0220202d // move $a0, $s1
    .word 0x3c100013 // lui $s0, 0x13
    .word 0x0c04a264 // jal 0x128990
    .word 0x26100748 // addiu $s0, $s0, 0x748
    .word 0x3c0a0039 // lui $t2, 0x39
    .word 0x00021c3a // dsrl $v1, $v0, 0x10
    .word 0xa7a20010 // sh $v0, 0x10($sp)
    .word 0xa7a30012 // sh $v1, 0x12($sp)
    .word 0x3c02ffff // lui $v0, 0xffff
    .word 0x0002103e // dsrl32 $v0, $v0, 0
    .word 0x0200282d // move $a1, $s0
    .word 0x0220302d // move $a2, $s1
    .word 0x8fa70010 // lw $a3, 0x10($sp)
    .word 0x254ac980 // addiu $t2, $t2, -0x3680
    .word 0x0240202d // move $a0, $s2
    .word 0x0000402d // move $t0, $zero
    .word 0x00e23824 // and $a3, $a3, $v0
    .word 0x0c04bbce // jal 0x12ef38
    .word 0x0000482d // move $t1, $zero
    .word 0xae5400c4 // sw $s4, 0xc4($s2)
    .word 0x24020001 // addiu $v0, $zero, 1
    .word 0xae5300bc // sw $s3, 0xbc($s2)
    .word 0x8ba30003 // lwl $v1, 3($sp)
    .word 0x9ba30000 // lwr $v1, ($sp)
    .word 0xaa4300b7 // swl $v1, 0xb7($s2)
    .word 0xba4300b4 // swr $v1, 0xb4($s2)
    .word 0xdfbf0070 // ld $ra, 0x70($sp)
    .word 0xdfb40060 // ld $s4, 0x60($sp)
    .word 0xdfb30050 // ld $s3, 0x50($sp)
    .word 0xdfb20040 // ld $s2, 0x40($sp)
    .word 0xdfb10030 // ld $s1, 0x30($sp)
    .word 0xdfb00020 // ld $s0, 0x20($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0080 // addiu $sp, $sp, 0x80
}
#else

void func_0012EF18(void *a0);
u32 func_00128990(void);
void *func_0012EF38(void *a0, void *a1, void *a2, u32 a3, u32 t0, u32 t1, u32 t2);

struct KtContext9700 {
    u32 active;
    u8 pad[0xb0];
    u32 unaligned_val;
    u8 pad_b8[4];
    u32 field_bc;
    u8 pad_c0[4];
    u32 field_c4;
};

struct KtFileContext {
    u32 field_00;
    u32 field_04;
};

extern KtContext9700 D_004F9700;
extern KtFileContext D_004F97D8;
extern void *D_00130748[];
extern void *D_0038C980[];

s32 func_00130670(u32 a0, void *a1) {
    u32 magic = a0;
    u32 s4_val = D_004F97D8.field_00;
    u32 s3_val = D_004F97D8.field_04;

    if (D_004F9700.active != 0) {
        return 0;
    }

    func_0012EF18(a1);
    u32 vibe = func_00128990();
    u16 vibe_low = (u16)vibe;
    u16 vibe_high = (u16)(vibe >> 16);
    u32 combined = vibe_low | ((u32)vibe_high << 16);

    func_0012EF38(&D_004F9700, D_00130748, a1, combined & 0xFFFF0000, 0, 0, (u32)D_0038C980);

    D_004F9700.field_c4 = s4_val;
    D_004F9700.field_bc = s3_val;
    D_004F9700.unaligned_val = magic;

    return 1;
}

#endif

}
