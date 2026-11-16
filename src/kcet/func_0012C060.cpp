/* Function: func_0012C060 (0x0012C060 - 0x0012C068)
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
asm void func_0012C060(void *arg0) {
    .word 0x080450f0 // 0012C060:  j 0x1143c0
    .word 0x24050018 // 0012C064:  addiu $a1, $zero, 0x18
}
#else

void func_001143C0(void *ptr, s32 size);

void func_0012C060(void *arg0) {
    func_001143C0(arg0, 0x18);
}

#endif

}
