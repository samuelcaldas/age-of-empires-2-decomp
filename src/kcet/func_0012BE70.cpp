/* Function: func_0012BE70 (0x0012BE70 - 0x0012BEC0)
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
asm void *func_0012BE70(void) {
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0x0000302d // move $a2, $zero
    .word 0x8c431400 // lw $v1, 0x1400($v0)
    .word 0x24441400 // addiu $a0, $v0, 0x1400
    .word 0x14600009 // bnez $v1, 0x12bea8
    .word 0x0000282d // move $a1, $zero
    .word 0x24a50001 // addiu $a1, $a1, 1
    .word 0x00000000 // nop
    .word 0x28a20004 // slti $v0, $a1, 4
    .word 0x10400008 // beqz $v0, 0x12beb8
    .word 0x24840038 // addiu $a0, $a0, 0x38
    .word 0x8c820000 // lw $v0, ($a0)
    .word 0x5040fffb // beql $v0, $zero, 0x12be90
    .word 0x24a50001 // addiu $a1, $a1, 1
    .word 0x8c820004 // lw $v0, 4($a0)
    .word 0x1440fff8 // bnez $v0, 0x12be90
    .word 0x24a50001 // addiu $a1, $a1, 1
    .word 0x0080302d // move $a2, $a0
    .word 0x03e00008 // jr $ra
    .word 0x00c0102d // move $v0, $a2
}
#else

struct CdvdRequest {
    s32 state;
    s32 in_use;
    u8 pad[0x30];
};

extern CdvdRequest D_004F1400[4];

CdvdRequest *func_0012BE70(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (D_004F1400[i].state != 0 && D_004F1400[i].in_use == 0) {
            return &D_004F1400[i];
        }
    }
    return 0;
}

#endif

}
