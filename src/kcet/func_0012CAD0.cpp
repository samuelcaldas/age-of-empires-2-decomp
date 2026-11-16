/* Function: func_0012CAD0 (0x0012CAD0 - 0x0012CADC)
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
asm void func_0012CAD0(void) {
    .word 0x3c03004f // 0012CAD0:  lui $v1, 0x4f
    .word 0x03e00008 // 0012CAD4:  jr $ra
    .word 0x8c62150c // 0012CAD8:  lw $v0, 0x150c($v1)
}
#else

extern s32 D_004F150C;

s32 func_0012CAD0(void) {
    return D_004F150C;
}

#endif

}
