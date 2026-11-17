/* Function: func_0012DA00 (0x0012DA00 - 0x0012DA38)
 * Origin: SLES-50282, KCET kt_file module (originally compiled with ee-gcc -O2 -G0)
 */

#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct CdStreamStatus {
    s32 field0;
    s32 active;
    s32 bytes_remaining;
};

extern "C" {

#if defined(__mips__)
asm s32 func_0012DA00(void) {
    .word 0x3c03004f // 0012DA00:  lui $v1, 0x4f
    .word 0xaf808858 // 0012DA04:  sw $zero, -0x77a8($gp)
    .word 0x246316c0 // 0012DA08:  addiu $v1, $v1, 0x16c0
    .word 0x8c620004 // 0012DA0C:  lw $v0, 4($v1)
    .word 0x10400007 // 0012DA10:  beqz $v0, 0x12da30
    .word 0x8f828878 // 0012DA14:  lw $v0, -0x7788($gp)
    .word 0x8c630008 // 0012DA18:  lw $v1, 8($v1)
    .word 0x00431023 // 0012DA1C:  subu $v0, $v0, $v1
    .word 0x000212c2 // 0012DA20:  srl $v0, $v0, 0xb
    .word 0x04410002 // 0012DA24:  bgez $v0, 0x12da30
    .word 0xaf828858 // 0012DA28:  sw $v0, -0x77a8($gp)
    .word 0xaf808858 // 0012DA2C:  sw $zero, -0x77a8($gp)
    .word 0x03e00008 // 0012DA30:  jr $ra
    .word 0x8f828858 // 0012DA34:  lw $v0, -0x77a8($gp)
}
#else

extern CdStreamStatus D_004F16C0;
extern s32 D_004F3018;
extern s32 D_004F3038;

s32 func_0012DA00(void) {
    D_004F3018 = 0;
    if (D_004F16C0.active != 0) {
        s32 v = (u32)(D_004F3038 - D_004F16C0.bytes_remaining) >> 11;
        if (v >= 0) {
            D_004F3018 = v;
        } else {
            D_004F3018 = 0;
        }
    }
    return D_004F3018;
}

#endif

}
