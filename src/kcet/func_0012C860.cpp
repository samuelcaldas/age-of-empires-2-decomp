/* Function: func_0012C860 (0x0012C860 - 0x0012C8E4)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012C860(s32 a0, s32 a1) {
    .word 0x27bdffc0 // 0012C860:  addiu $sp, $sp, -0x40
    .word 0xffb10010 // 0012C864:  sd $s1, 0x10($sp)
    .word 0xffb20020 // 0012C868:  sd $s2, 0x20($sp)
    .word 0x0080882d // 0012C86C:  move $s1, $a0
    .word 0xffb00000 // 0012C870:  sd $s0, ($sp)
    .word 0xffbf0030 // 0012C874:  sd $ra, 0x30($sp)
    .word 0x0c04afb0 // 0012C878:  jal 0x12bec0
    .word 0x00a0902d // 0012C87C:  move $s2, $a1
    .word 0x0040802d // 0012C880:  move $s0, $v0
    .word 0x12000011 // 0012C884:  beqz $s0, 0x12c8cc
    .word 0x0010102b // 0012C888:  sltu $v0, $zero, $s0
    .word 0x0c04b018 // 0012C88C:  jal 0x12c060
    .word 0x0220202d // 0012C890:  move $a0, $s1
    .word 0xae110014 // 0012C894:  sw $s1, 0x14($s0)
    .word 0xae00000c // 0012C898:  sw $zero, 0xc($s0)
    .word 0xae000010 // 0012C89C:  sw $zero, 0x10($s0)
    .word 0xae000018 // 0012C8A0:  sw $zero, 0x18($s0)
    .word 0x0c04a7d6 // 0012C8A4:  jal 0x129f58
    .word 0xae00001c // 0012C8A8:  sw $zero, 0x1c($s0)
    .word 0x0c04a7f4 // 0012C8AC:  jal 0x129fd0
    .word 0xae020020 // 0012C8B0:  sw $v0, 0x20($s0)
    .word 0xae020024 // 0012C8B4:  sw $v0, 0x24($s0)
    .word 0x0240302d // 0012C8B8:  move $a2, $s2
    .word 0x0200202d // 0012C8BC:  move $a0, $s0
    .word 0x0c04affc // 0012C8C0:  jal 0x12bff0
    .word 0x24050005 // 0012C8C4:  addiu $a1, $zero, 5
    .word 0x0010102b // 0012C8C8:  sltu $v0, $zero, $s0
    .word 0xdfbf0030 // 0012C8CC:  ld $ra, 0x30($sp)
    .word 0xdfb20020 // 0012C8D0:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012C8D4:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012C8D8:  ld $s0, ($sp)
    .word 0x03e00008 // 0012C8DC:  jr $ra
    .word 0x27bd0040 // 0012C8E0:  addiu $sp, $sp, 0x40
}
#else

struct CdvdRequest {
    u8 pad_00[0x0c];
    s32 field_0c;
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1c;
    s32 field_20;
    s32 field_24;
};

CdvdRequest *func_0012BEC0(s32 a0);
void func_0012C060(s32 a0);
s32 func_00129F58(void);
s32 func_00129FD0(void);
void func_0012BFF0(void *req, s32 type, s32 mode);

s32 func_0012C860(s32 a0, s32 a1) {
    CdvdRequest *req = func_0012BEC0(a0);
    if (req != 0) {
        func_0012C060(a0);
        req->field_14 = a0;
        req->field_0c = 0;
        req->field_10 = 0;
        req->field_18 = 0;
        req->field_1c = 0;
        func_00129F58();
        s32 v0 = func_00129FD0();
        req->field_20 = v0;
        req->field_24 = v0;
        func_0012BFF0(req, 5, a1);
    }
    return req != 0;
}

#endif

}
