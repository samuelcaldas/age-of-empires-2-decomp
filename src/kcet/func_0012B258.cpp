/* Function: func_0012B258 (0x0012B258 - 0x0012B334)
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
asm void func_0012B258(void) {
    .word 0x27bdff60 // addiu $sp, $sp, -0xa0
    .word 0xffbe0080 // sd $fp, 0x80($sp)
    .word 0xffb70070 // sd $s7, 0x70($sp)
    .word 0x00e0f02d // move $fp, $a3
    .word 0xffb60060 // sd $s6, 0x60($sp)
    .word 0x0160b82d // move $s7, $t3
    .word 0xffb50050 // sd $s5, 0x50($sp)
    .word 0x0140b02d // move $s6, $t2
    .word 0xffb40040 // sd $s4, 0x40($sp)
    .word 0x0120a82d // move $s5, $t1
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0x0100a02d // move $s4, $t0
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0x00a0982d // move $s3, $a1
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x00c0902d // move $s2, $a2
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0xffbf0090 // sd $ra, 0x90($sp)
    .word 0x0c04ab9c // jal 0x12ae70
    .word 0x0080802d // move $s0, $a0
    .word 0xae120030 // sw $s2, 0x30($s0)
    .word 0x0040882d // move $s1, $v0
    .word 0x0c04ac88 // jal 0x12b220
    .word 0x0260202d // move $a0, $s3
    .word 0x24040001 // addiu $a0, $zero, 1
    .word 0xa2000034 // sb $zero, 0x34($s0)
    .word 0xa2040035 // sb $a0, 0x35($s0)
    .word 0x3c03004f // lui $v1, 0x4f
    .word 0xae020028 // sw $v0, 0x28($s0)
    .word 0x2463d300 // addiu $v1, $v1, -0x2d00
    .word 0x0220202d // move $a0, $s1
    .word 0x90620014 // lbu $v0, 0x14($v1)
    .word 0xa2020036 // sb $v0, 0x36($s0)
    .word 0xae300000 // sw $s0, ($s1)
    .word 0x8c62000c // lw $v0, 0xc($v1)
    .word 0xae140038 // sw $s4, 0x38($s0)
    .word 0xae15003c // sw $s5, 0x3c($s0)
    .word 0xae160014 // sw $s6, 0x14($s0)
    .word 0xae170018 // sw $s7, 0x18($s0)
    .word 0xae330004 // sw $s3, 4($s1)
    .word 0xae3e0008 // sw $fp, 8($s1)
    .word 0x0c04ac3e // jal 0x12b0f8
    .word 0xae02001c // sw $v0, 0x1c($s0)
    .word 0xdfbf0090 // ld $ra, 0x90($sp)
    .word 0xdfbe0080 // ld $fp, 0x80($sp)
    .word 0xdfb70070 // ld $s7, 0x70($sp)
    .word 0xdfb60060 // ld $s6, 0x60($sp)
    .word 0xdfb50050 // ld $s5, 0x50($sp)
    .word 0xdfb40040 // ld $s4, 0x40($sp)
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd00a0 // addiu $sp, $sp, 0xa0
}
#else

struct CdvdRequest {
    u8 pad0[0x14];
    s32 f_14;
    s32 f_18;
    s32 f_1c;
    u8 pad20[0x8];
    s32 f_28;
    u8 pad2c[0x4];
    s32 f_30;
    u8 f_34;
    u8 f_35;
    u8 f_36;
    u8 pad37;
    s32 f_38;
    s32 f_3c;
};

struct CdvdGlobalState {
    u8 pad0[0xc];
    s32 f_c;
    u8 pad10[0x4];
    u8 f_14;
};

struct CdvdServerTask {
    CdvdRequest *req;
    void *param1;
    void *param2;
};

extern CdvdGlobalState D_004ED300;

CdvdServerTask *func_0012AE70(void);
s32 func_0012B220(void *param1);
void func_0012B0F8(CdvdServerTask *task);

void func_0012B258(CdvdRequest *req, void *param1, s32 param2, void *param3,
                   s32 t0, s32 t1, s32 t2, s32 t3) {
    CdvdServerTask *task = func_0012AE70();
    req->f_30 = param2;
    s32 v0_b220 = func_0012B220(param1);
    req->f_34 = 0;
    req->f_35 = 1;
    req->f_28 = v0_b220;
    req->f_36 = D_004ED300.f_14;
    task->req = req;
    req->f_38 = t0;
    req->f_3c = t1;
    req->f_14 = t2;
    req->f_18 = t3;
    task->param1 = param1;
    task->param2 = param3;
    req->f_1c = D_004ED300.f_c;
    func_0012B0F8(task);
}

#endif

}
