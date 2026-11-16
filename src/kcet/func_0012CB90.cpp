/* Function: func_0012CB90 (0x0012CB90 - 0x0012CBA8)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" {

#if defined(__mips__)
asm u32 func_0012CB90(const u64 *ptr) {
    .word 0x10800003 // 0012CB90:  beqz $a0, 0x12cba0
    .word 0x0000102d // 0012CB94:  move $v0, $zero
    .word 0xdc820000 // 0012CB98:  ld $v0, ($a0)
    .word 0x0002123e // 0012CB9C:  dsrl32 $v0, $v0, 8
    .word 0x03e00008 // 0012CBA0:  jr $ra
    .word 0x00000000 // 0012CBA4:  nop
}
#else

u32 func_0012CB90(const u64 *ptr) {
    if (!ptr) {
        return 0;
    }
    return (u32)(*ptr >> 40);
}

#endif

}
