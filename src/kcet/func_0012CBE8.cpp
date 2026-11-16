/* Function: func_0012CBE8 (0x0012CBE8 - 0x0012CBF4)
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
asm void func_0012CBE8(void) {
    .word 0x3c03004f // 0012CBE8:  lui $v1, 0x4f
    .word 0x03e00008 // 0012CBEC:  jr $ra
    .word 0x8c621510 // 0012CBF0:  lw $v0, 0x1510($v1)
}
#else

extern s32 D_004F1510;

s32 func_0012CBE8(void) {
    return D_004F1510;
}

#endif

}
