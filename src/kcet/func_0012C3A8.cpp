/* Function: func_0012C3A8 (0x0012C3A8 - 0x0012C44C)
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
asm s32 func_0012C3A8(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, void *t2) {
    .word 0x27bdff80 // 0012C3A8:  addiu $sp, $sp, -0x80
    .word 0xffb60060 // 0012C3AC:  sd $s6, 0x60($sp)
    .word 0xffb50050 // 0012C3B0:  sd $s5, 0x50($sp)
    .word 0x0100b02d // 0012C3B4:  move $s6, $t0
    .word 0xffb40040 // 0012C3B8:  sd $s4, 0x40($sp)
    .word 0x00e0a82d // 0012C3BC:  move $s5, $a3
    .word 0xffb30030 // 0012C3C0:  sd $s3, 0x30($sp)
    .word 0x00c0a02d // 0012C3C4:  move $s4, $a2
    .word 0xffb20020 // 0012C3C8:  sd $s2, 0x20($sp)
    .word 0x0080982d // 0012C3CC:  move $s3, $a0
    .word 0xffb10010 // 0012C3D0:  sd $s1, 0x10($sp)
    .word 0x00a0902d // 0012C3D4:  move $s2, $a1
    .word 0xffb00000 // 0012C3D8:  sd $s0, ($sp)
    .word 0x0120882d // 0012C3DC:  move $s1, $t1
    .word 0x0140802d // 0012C3E0:  move $s0, $t2
    .word 0x1200000e // 0012C3E4:  beqz $s0, 0x12c420
    .word 0xffbf0070 // 0012C3E8:  sd $ra, 0x70($sp)
    .word 0x0c04b018 // 0012C3EC:  jal 0x12c060
    .word 0x0240202d // 0012C3F0:  move $a0, $s2
    .word 0xae13000c // 0012C3F4:  sw $s3, 0xc($s0)
    .word 0x0220302d // 0012C3F8:  move $a2, $s1
    .word 0xae120014 // 0012C3FC:  sw $s2, 0x14($s0)
    .word 0x0200202d // 0012C400:  move $a0, $s0
    .word 0xae14001c // 0012C404:  sw $s4, 0x1c($s0)
    .word 0x24050002 // 0012C408:  addiu $a1, $zero, 2
    .word 0xae150020 // 0012C40C:  sw $s5, 0x20($s0)
    .word 0xae160024 // 0012C410:  sw $s6, 0x24($s0)
    .word 0xae000010 // 0012C414:  sw $zero, 0x10($s0)
    .word 0x0c04affc // 0012C418:  jal 0x12bff0
    .word 0xae000018 // 0012C41C:  sw $zero, 0x18($s0)
    .word 0x0010102b // 0012C420:  sltu $v0, $zero, $s0
    .word 0xdfbf0070 // 0012C424:  ld $ra, 0x70($sp)
    .word 0xdfb60060 // 0012C428:  ld $s6, 0x60($sp)
    .word 0xdfb50050 // 0012C42C:  ld $s5, 0x50($sp)
    .word 0xdfb40040 // 0012C430:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 0012C434:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012C438:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012C43C:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012C440:  ld $s0, ($sp)
    .word 0x03e00008 // 0012C444:  jr $ra
    .word 0x27bd0080 // 0012C448:  addiu $sp, $sp, 0x80
}
#else

void func_0012C060(s32 arg0);
void func_0012BFF0(void *arg0, s32 arg1, s32 arg2);

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

int func_0012C3A8(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, CdvdRequest *req) {
    if (req != 0) {
        func_0012C060(a1);
        req->field_0c = a0;
        req->field_14 = a1;
        req->field_1c = a2;
        req->field_20 = a3;
        req->field_24 = t0;
        req->field_10 = 0;
        req->field_18 = 0;
        func_0012BFF0(req, 2, t1);
    }
    return req != 0;
}

#endif

}
