/* Function: func_0012B570 (0x0012B570 - 0x0012B648)
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
asm s32 func_0012B570(void *a0, void *a1, void *a2) {
    .word 0x27bdffd0 // 0012B570: addiu $sp, $sp, -0x30
    .word 0x3c03004f // 0012B574: lui $v1, 0x4f
    .word 0xffb00000 // 0012B578: sd $s0, ($sp)
    .word 0xffb10010 // 0012B57C: sd $s1, 0x10($sp)
    .word 0x0080802d // 0012B580: move $s0, $a0
    .word 0xffbf0020 // 0012B584: sd $ra, 0x20($sp)
    .word 0x00c0882d // 0012B588: move $s1, $a2
    .word 0xae000028 // 0012B58C: sw $zero, 0x28($s0)
    .word 0xae000030 // 0012B590: sw $zero, 0x30($s0)
    .word 0x8c62d30c // 0012B594: lw $v0, -0x2cf4($v1)
    .word 0xae000038 // 0012B598: sw $zero, 0x38($s0)
    .word 0xae02001c // 0012B59C: sw $v0, 0x1c($s0)
    .word 0x10a0001f // 0012B5A0: beqz $a1, 0x12b620
    .word 0xae00003c // 0012B5A4: sw $zero, 0x3c($s0)
    .word 0x24020002 // 0012B5A8: addiu $v0, $zero, 2
    .word 0xae05002c // 0012B5AC: sw $a1, 0x2c($s0)
    .word 0xae000018 // 0012B5B0: sw $zero, 0x18($s0)
    .word 0xae020014 // 0012B5B4: sw $v0, 0x14($s0)
    .word 0x0c04aa02 // 0012B5B8: jal 0x12a808
    .word 0x2405ffff // 0012B5BC: addiu $a1, $zero, -1
    .word 0x0040282d // 0012B5C0: move $a1, $v0
    .word 0x24020001 // 0012B5C4: addiu $v0, $zero, 1
    .word 0x54a20017 // 0012B5C8: bnel $a1, $v0, 0x12b628
    .word 0x8e03006c // 0012B5CC: lw $v1, 0x6c($s0)
    .word 0x6a02004f // 0012B5D0: ldl $v0, 0x4f($s0)
    .word 0x6e020048 // 0012B5D4: ldr $v0, 0x48($s0)
    .word 0x6a030057 // 0012B5D8: ldl $v1, 0x57($s0)
    .word 0x6e030050 // 0012B5DC: ldr $v1, 0x50($s0)
    .word 0x6a04005f // 0012B5E0: ldl $a0, 0x5f($s0)
    .word 0x6e040058 // 0012B5E4: ldr $a0, 0x58($s0)
    .word 0x6a060067 // 0012B5E8: ldl $a2, 0x67($s0)
    .word 0x6e060060 // 0012B5EC: ldr $a2, 0x60($s0)
    .word 0xb2220007 // 0012B5F0: sdl $v0, 7($s1)
    .word 0xb6220000 // 0012B5F4: sdr $v0, ($s1)
    .word 0xb223000f // 0012B5F8: sdl $v1, 0xf($s1)
    .word 0xb6230008 // 0012B5FC: sdr $v1, 8($s1)
    .word 0xb2240017 // 0012B600: sdl $a0, 0x17($s1)
    .word 0xb6240010 // 0012B604: sdr $a0, 0x10($s1)
    .word 0xb226001f // 0012B608: sdl $a2, 0x1f($s1)
    .word 0xb6260018 // 0012B60C: sdr $a2, 0x18($s1)
    .word 0x8e020068 // 0012B610: lw $v0, 0x68($s0)
    .word 0xae220020 // 0012B614: sw $v0, 0x20($s1)
    .word 0x10000003 // 0012B618: b 0x12b628
    .word 0x8e03006c // 0012B61C: lw $v1, 0x6c($s0)
    .word 0x24050009 // 0012B620: addiu $a1, $zero, 9
    .word 0x8e03006c // 0012B624: lw $v1, 0x6c($s0)
    .word 0x00a0102d // 0012B628: move $v0, $a1
    .word 0xdfbf0020 // 0012B62C: ld $ra, 0x20($sp)
    .word 0xac71000c // 0012B630: sw $s1, 0xc($v1)
    .word 0xdfb10010 // 0012B634: ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012B638: ld $s0, ($sp)
    .word 0xac600008 // 0012B63C: sw $zero, 8($v1)
    .word 0x03e00008 // 0012B640: jr $ra
    .word 0x27bd0030 // 0012B644: addiu $sp, $sp, 0x30
}
#else

struct CdvdSubStruct {
    u8 pad0[8];
    s32 f_8;
    void *f_c;
};

struct CdvdRequest {
    u8 pad0[0x14];
    s32 f_14;
    s32 f_18;
    s32 f_1c;
    u8 pad20[8];
    s32 f_28;
    void *f_2c;
    s32 f_30;
    u8 pad34[4];
    s32 f_38;
    s32 f_3c;
    u8 pad40[8];
    u8 f_48[36];
    CdvdSubStruct *sub;
};

struct CdvdGlobalState {
    u8 pad0[0xc];
    s32 f_c;
};

extern CdvdGlobalState D_004ED300;

s32 func_0012A808(CdvdRequest *req, s32 code);

struct BufferInfo {
    u8 data[36];
};

s32 func_0012B570(CdvdRequest *req, void *param1, BufferInfo *buf) {
    req->f_28 = 0;
    req->f_30 = 0;
    req->f_1c = D_004ED300.f_c;
    req->f_38 = 0;
    req->f_3c = 0;
    if (param1 == 0) {
        req->sub->f_c = buf;
        req->sub->f_8 = 0;
        return 9;
    }
    req->f_14 = 2;
    req->f_2c = param1;
    req->f_18 = 0;
    s32 res = func_0012A808(req, -1);
    if (res == 1) {
        *buf = *(BufferInfo *)req->f_48;
    }
    req->sub->f_c = buf;
    req->sub->f_8 = 0;
    return res;
}

#endif

}
