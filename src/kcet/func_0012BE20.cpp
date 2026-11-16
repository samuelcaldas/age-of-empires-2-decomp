/* Function: func_0012BE20 (0x0012BE20 - 0x0012BE30)
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
asm void func_0012BE20(void) {
    .word 0x3c04004f // 0012BE20:  lui $a0, 0x4f
    .word 0x24050108 // 0012BE24:  addiu $a1, $zero, 0x108
    .word 0x080450f0 // 0012BE28:  j 0x1143c0
    .word 0x24841400 // 0012BE2C:  addiu $a0, $a0, 0x1400
}
#else

extern u8 D_004F1400[];
void func_001143C0(void *ptr, s32 size);

void func_0012BE20(void) {
    func_001143C0(D_004F1400, 0x108);
}

#endif

}
