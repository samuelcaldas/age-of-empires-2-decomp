/* Function: func_0012BFB8 (0x0012BFB8 - 0x0012BFEC)
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
asm s32 func_0012BFB8(void) {
    .word 0x3c02004f // 0012BFB8:  lui $v0, 0x4f
    .word 0x0000302d // 0012BFBC:  move $a2, $zero
    .word 0x24451400 // 0012BFC0:  addiu $a1, $v0, 0x1400
    .word 0x24a700e0 // 0012BFC4:  addiu $a3, $a1, 0xe0
loop:
    .word 0x8ca40000 // 0012BFC8:  lw $a0, ($a1)
    .word 0x24c30001 // 0012BFCC:  addiu $v1, $a2, 1
    .word 0x24a50038 // 0012BFD0:  addiu $a1, $a1, 0x38
    .word 0x0064300b // 0012BFD4:  movn $a2, $v1, $a0
    .word 0x00a7102a // 0012BFD8:  slt $v0, $a1, $a3
    bnez $v0, loop
    .word 0x00000000 // 0012BFE0:  nop 
    .word 0x03e00008 // 0012BFE4:  jr $ra
    .word 0x00c0102d // 0012BFE8:  move $v0, $a2
}
#else

struct CdvdNode {
    s32 active;
    u8 rest[0x34];
};

extern CdvdNode D_004F1400[4];

s32 func_0012BFB8(void) {
    s32 count = 0;
    for (s32 i = 0; i < 4; i++) {
        if (D_004F1400[i].active != 0) {
            count++;
        }
    }
    return count;
}

#endif

}
