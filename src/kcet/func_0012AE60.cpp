/* Function: func_0012AE60 (0x0012AE60 - 0x0012AE7C)
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
asm void func_0012AE60(void) {
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0x0804d130 // j 0x1344c0
    .word 0x8c44d354 // lw $a0, -0x2cac($v0)
    .word 0x00000000 // nop
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0x03e00008 // jr $ra
    .word 0x2442d3e0 // addiu $v0, $v0, -0x2c20
}
#else

extern s32 D_004ED354;
extern u8 D_004ED3E0[];

void func_001344C0(s32);

void func_0012AE60(void) {
    func_001344C0(D_004ED354);
}

void *func_0012AE70(void) {
    return D_004ED3E0;
}

#endif

}
