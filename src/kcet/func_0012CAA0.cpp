/* Function: func_0012CAA0 (0x0012CAA0 - 0x0012CABC)
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
asm void func_0012CAA0(void) {
    .word 0x27bdfff0 // 0012CAA0:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012CAA4:  sd $ra, ($sp)
    .word 0x0c04afee // 0012CAA8:  jal 0x12bfb8
    .word 0x00000000 // 0012CAAC:  nop 
    .word 0xdfbf0000 // 0012CAB0:  ld $ra, ($sp)
    .word 0x03e00008 // 0012CAB4:  jr $ra
    .word 0x27bd0010 // 0012CAB8:  addiu $sp, $sp, 0x10
}
#else

s32 func_0012BFB8(void);

void func_0012CAA0(void) {
    func_0012BFB8();
}

#endif

}
