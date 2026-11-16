/* Function: func_0012CBA8 (0x0012CBA8 - 0x0012CBE4)
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
asm u32 func_0012CBA8(const u64 *ptr, u32 *out1, u32 *out2) {
    .word 0x1080000c // 0012CBA8:  beqz $a0, 0x12cbdc
    .word 0x00000000 // 0012CBAC:  nop
    .word 0xdc820000 // 0012CBB0:  ld $v0, ($a0)
    .word 0x3c0300ff // 0012CBB4:  lui $v1, 0xff
    .word 0x3463ffff // 0012CBB8:  ori $v1, $v1, 0xffff
    .word 0x0002143a // 0012CBBC:  dsrl $v0, $v0, 0x10
    .word 0x00431024 // 0012CBC0:  and $v0, $v0, $v1
    .word 0x0002103c // 0012CBC4:  dsll32 $v0, $v0, 0
    .word 0x0002103f // 0012CBC8:  dsra32 $v0, $v0, 0
    .word 0xaca20000 // 0012CBCC:  sw $v0, ($a1)
    .word 0xdc830000 // 0012CBD0:  ld $v1, ($a0)
    .word 0x00031a3e // 0012CBD4:  dsrl32 $v1, $v1, 8
    .word 0xacc30000 // 0012CBD8:  sw $v1, ($a2)
    .word 0x03e00008 // 0012CBDC:  jr $ra
    .word 0x0004102b // 0012CBE0:  sltu $v0, $zero, $a0
}
#else

u32 func_0012CBA8(const u64 *ptr, u32 *out1, u32 *out2) {
    if (ptr) {
        *out1 = (u32)((*ptr >> 16) & 0x00FFFFFF);
        *out2 = (u32)(*ptr >> 40);
        return 1;
    }
    return 0;
}

#endif

}
