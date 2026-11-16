/* Function: func_0012C6D0 (0x0012C6D0 - 0x0012C754)
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
asm s32 func_0012C6D0(s32 a0, s32 a1) {
    .word 0x27bdffc0 // 0012C6D0:  addiu $sp, $sp, -0x40
    .word 0xffb10010 // 0012C6D4:  sd $s1, 0x10($sp)
    .word 0xffb20020 // 0012C6D8:  sd $s2, 0x20($sp)
    .word 0x0080882d // 0012C6DC:  move $s1, $a0
    .word 0xffb00000 // 0012C6E0:  sd $s0, ($sp)
    .word 0xffbf0030 // 0012C6E4:  sd $ra, 0x30($sp)
    .word 0x0c04afb0 // 0012C6E8:  jal 0x12bec0
    .word 0x00a0902d // 0012C6EC:  move $s2, $a1
    .word 0x0040802d // 0012C6F0:  move $s0, $v0
    .word 0x12000011 // 0012C6F4:  beqz $s0, 0x12c73c
    .word 0x0010102b // 0012C6F8:  sltu $v0, $zero, $s0
    .word 0x0c04b018 // 0012C6FC:  jal 0x12c060
    .word 0x0220202d // 0012C700:  move $a0, $s1
    .word 0xae110014 // 0012C704:  sw $s1, 0x14($s0)
    .word 0xae00000c // 0012C708:  sw $zero, 0xc($s0)
    .word 0xae000010 // 0012C70C:  sw $zero, 0x10($s0)
    .word 0xae000018 // 0012C710:  sw $zero, 0x18($s0)
    .word 0x0c04a7d6 // 0012C714:  jal 0x129f58
    .word 0xae00001c // 0012C718:  sw $zero, 0x1c($s0)
    .word 0x0c04a7f4 // 0012C71c:  jal 0x129fd0
    .word 0xae020020 // 0012C720:  sw $v0, 0x20($s0)
    .word 0xae020024 // 0012C724:  sw $v0, 0x24($s0)
    .word 0x0240302d // 0012C728:  move $a2, $s2
    .word 0x0200202d // 0012C72c:  move $a0, $s0
    .word 0x0c04affc // 0012C730:  jal 0x12bff0
    .word 0x24050003 // 0012C734:  addiu $a1, $zero, 3
    .word 0x0010102b // 0012C738:  sltu $v0, $zero, $s0
    .word 0xdfbf0030 // 0012C73c:  ld $ra, 0x30($sp)
    .word 0xdfb20020 // 0012C740:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012C744:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012C748:  ld $s0, ($sp)
    .word 0x03e00008 // 0012C74c:  jr $ra
    .word 0x27bd0040 // 0012C750:  addiu $sp, $sp, 0x40
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

s32 func_0012C6D0(s32 a0, s32 a1) {
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
        func_0012BFF0(req, 3, a1);
    }
    return req != 0;
}

#endif

}
