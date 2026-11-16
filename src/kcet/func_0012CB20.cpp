/* Function: func_0012CB20 (0x0012CB20 - 0x0012CB34)
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
asm u32 func_0012CB20(const u16* ptr) {
    .word 0x10800002 // 0012CB20:  beqz $a0, 0x12cb2c
    .word 0x0000102d // 0012CB24:  move $v0, $zero
    .word 0x94820000 // 0012CB28:  lhu $v0, ($a0)
    .word 0x03e00008 // 0012CB2C:  jr $ra
    .word 0x00000000 // 0012CB30:  nop 
}
#else

u32 func_0012CB20(const u16* ptr) {
    if (!ptr) {
        return 0;
    }
    return *ptr;
}

#endif

}
