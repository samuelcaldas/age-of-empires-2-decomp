/* Function: func_0012BB50 (0x0012BB50 - 0x0012BBA0)
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
asm s32 func_0012BB50(s32 a0, s32 a1) {
    .word 0x27bdffb0 // 0012BB50:  addiu $sp, $sp, -0x50
    .word 0x2402ffff // 0012BB54:  addiu $v0, $zero, -1
    .word 0xffb00030 // 0012BB58:  sd $s0, 0x30($sp)
    .word 0xffbf0040 // 0012BB5C:  sd $ra, 0x40($sp)
    .word 0x14a20006 // 0012BB60:  bne $a1, $v0, 0x12bb7c
    .word 0x0080802d // 0012BB64:  move $s0, $a0
    .word 0x0c04a842 // 0012BB68:  jal 0x12a108
    .word 0x03a0282d // 0012BB6C:  move $a1, $sp
    .word 0x8fa30000 // 0012BB70:  lw $v1, ($sp)
    .word 0x0000282d // 0012BB74:  move $a1, $zero
    .word 0x0062280b // 0012BB78:  movn $a1, $v1, $v0
    .word 0x3c03004f // 0012BB7C:  lui $v1, 0x4f
    .word 0xdfbf0040 // 0012BB80:  ld $ra, 0x40($sp)
    .word 0x2463d300 // 0012BB84:  addiu $v1, $v1, -0x2d00
    .word 0x00a0102d // 0012BB88:  move $v0, $a1
    .word 0xac700028 // 0012BB8C:  sw $s0, 0x28($v1)
    .word 0xdfb00030 // 0012BB90:  ld $s0, 0x30($sp)
    .word 0xac65002c // 0012BB94:  sw $a1, 0x2c($v1)
    .word 0x03e00008 // 0012BB98:  jr $ra
    .word 0x27bd0050 // 0012BB9C:  addiu $sp, $sp, 0x50
}
#else

struct CdvdServerData {
    u8 pad0[0x28];
    s32 f_28;
    s32 f_2c;
};

extern CdvdServerData D_004ED300;

s32 func_0012A108(s32 a0, s32 *a1);

s32 func_0012BB50(s32 a0, s32 a1) {
    if (a1 == -1) {
        s32 v1 = 0;
        if (func_0012A108(a0, &v1)) {
            a1 = v1;
        } else {
            a1 = 0;
        }
    }
    D_004ED300.f_28 = a0;
    D_004ED300.f_2c = a1;
    return a1;
}

#endif

}
