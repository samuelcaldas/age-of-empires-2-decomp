/* Function: func_0012CAC0 (0x0012CAC0 - 0x0012CACC)
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
asm void func_0012CAC0(void) {
    .word 0x3c03004f // 0012CAC0:  lui $v1, 0x4f
    .word 0x03e00008 // 0012CAC4:  jr $ra
    .word 0x8c621508 // 0012CAC8:  lw $v0, 0x1508($v1)
}
#else

extern s32 D_004F1508;

s32 func_0012CAC0(void) {
    return D_004F1508;
}

#endif

}
