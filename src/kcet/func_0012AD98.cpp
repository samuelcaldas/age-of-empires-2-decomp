/* Function: func_0012AD98 (0x0012AD98 - 0x0012ADC4)
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
asm void *func_0012AD98(void) {
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0x27bdfff0 // addiu $sp, $sp, -0x10
    .word 0x8c44d354 // lw $a0, -0x2cac($v0)
    .word 0xffbf0000 // sd $ra, ($sp)
    .word 0x0c04d140 // jal 0x134500
    .word 0x00000000 // nop
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0xdfbf0000 // ld $ra, ($sp)
    .word 0x2442d370 // addiu $v0, $v0, -0x2c90
    .word 0x03e00008 // jr $ra
    .word 0x27bd0010 // addiu $sp, $sp, 0x10
}
#else

extern s32 D_004ED354;
extern u8 D_004ED370[];

void func_00134500(s32);

void *func_0012AD98(void) {
    func_00134500(D_004ED354);
    return D_004ED370;
}

#endif

}
