/* Function: func_0012C068 (0x0012C068 - 0x0012C124)
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
asm s32 func_0012C068(s32 a0, s32 a1, void *a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, void *req) {
    .word 0x27bdff60 // 0012C068:  addiu $sp, $sp, -0xa0
    .word 0xffb00000 // 0012C06C:  sd $s0, ($sp)
    .word 0xffbe0080 // 0012C070:  sd $fp, 0x80($sp)
    .word 0xffb70070 // 0012C074:  sd $s7, 0x70($sp)
    .word 0x0140f02d // 0012C078:  move $fp, $t2
    .word 0xffb60060 // 0012C07C:  sd $s6, 0x60($sp)
    .word 0x0120b82d // 0012C080:  move $s7, $t1
    .word 0xffb50050 // 0012C084:  sd $s5, 0x50($sp)
    .word 0x0100b02d // 0012C088:  move $s6, $t0
    .word 0xffb40040 // 0012C08C:  sd $s4, 0x40($sp)
    .word 0x00e0a82d // 0012C090:  move $s5, $a3
    .word 0xffb30030 // 0012C094:  sd $s3, 0x30($sp)
    .word 0x00a0a02d // 0012C098:  move $s4, $a1
    .word 0xffb20020 // 0012C09C:  sd $s2, 0x20($sp)
    .word 0x0080982d // 0012C0A0:  move $s3, $a0
    .word 0xffb10010 // 0012C0A4:  sd $s1, 0x10($sp)
    .word 0x00c0902d // 0012C0A8:  move $s2, $a2
    .word 0x8fb000a0 // 0012C0AC:  lw $s0, 0xa0($sp)
    .word 0x0160882d // 0012C0B0:  move $s1, $t3
    .word 0x1200000e // 0012C0B4:  beqz $s0, 0x12c0f0
    .word 0xffbf0090 // 0012C0B8:  sd $ra, 0x90($sp)
    .word 0x0c04b018 // 0012C0BC:  jal 0x12c060
    .word 0x0240202d // 0012C0C0:  move $a0, $s2
    .word 0xae13000c // 0012C0C4:  sw $s3, 0xc($s0)
    .word 0x0220302d // 0012C0C8:  move $a2, $s1
    .word 0xae140010 // 0012C0CC:  sw $s4, 0x10($s0)
    .word 0x0200202d // 0012C0D0:  move $a0, $s0
    .word 0xae120014 // 0012C0D4:  sw $s2, 0x14($s0)
    .word 0x24050001 // 0012C0D8:  addiu $a1, $zero, 1
    .word 0xae150018 // 0012C0DC:  sw $s5, 0x18($s0)
    .word 0xae16001c // 0012C0E0:  sw $s6, 0x1c($s0)
    .word 0xae170020 // 0012C0E4:  sw $s7, 0x20($s0)
    .word 0x0c04affc // 0012C0E8:  jal 0x12bff0
    .word 0xae1e0024 // 0012C0EC:  sw $fp, 0x24($s0)
    .word 0x0010102b // 0012C0F0:  sltu $v0, $zero, $s0
    .word 0xdfbf0090 // 0012C0F4:  ld $ra, 0x90($sp)
    .word 0xdfbe0080 // 0012C0F8:  ld $fp, 0x80($sp)
    .word 0xdfb70070 // 0012C0FC:  ld $s7, 0x70($sp)
    .word 0xdfb60060 // 0012C100:  ld $s6, 0x60($sp)
    .word 0xdfb50050 // 0012C104:  ld $s5, 0x50($sp)
    .word 0xdfb40040 // 0012C108:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 0012C10C:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012C110:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012C114:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012C118:  ld $s0, ($sp)
    .word 0x03e00008 // 0012C11C:  jr $ra
    .word 0x27bd00a0 // 0012C120:  addiu $sp, $sp, 0xa0
}
#else

void func_0012C060(void *arg0);
void func_0012BFF0(void *arg0, s32 arg1, s32 arg2);

struct CdvdRequest {
    u8 pad_00[0x0c];
    s32 field_0c;
    s32 field_10;
    void *field_14;
    s32 field_18;
    s32 field_1c;
    s32 field_20;
    s32 field_24;
};

int func_0012C068(s32 a0, s32 a1, void *a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, CdvdRequest *req) {
    if (req != 0) {
        func_0012C060(a2);
        req->field_0c = a0;
        req->field_10 = a1;
        req->field_14 = a2;
        req->field_18 = a3;
        req->field_1c = t0;
        req->field_20 = t1;
        req->field_24 = t2;
        func_0012BFF0(req, 1, t3);
    }
    return req != 0;
}

#endif

}
