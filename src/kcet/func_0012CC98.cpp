/* Function: func_0012CC98 (0x0012CC98 - 0x0012CCD4)
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
asm void func_0012CC98(void *p, u32 a1, u32 a2) {
    .word 0x0080382d // 0012CC98:  move $a3, $a0
    .word 0x10e0000b // 0012CC9C:  beqz $a3, 0x12cccc
    .word 0x24020040 // 0012CCA0:  addiu $v0, $zero, 0x40
    .word 0x3c0300ff // 0012CCA4:  lui $v1, 0xff
    .word 0x3463ffff // 0012CCA8:  ori $v1, $v1, 0xffff
    .word 0xa4e20000 // 0012CCAC:  sh $v0, ($a3)
    .word 0x00a31824 // 0012CCB0:  and $v1, $a1, $v1
    .word 0x00031c38 // 0012CCB4:  dsll $v1, $v1, 0x10
    .word 0x0006223c // 0012CCB8:  dsll32 $a0, $a2, 8
    .word 0x3042ffff // 0012CCBC:  andi $v0, $v0, 0xffff
    .word 0x00431025 // 0012CCC0:  or $v0, $v0, $v1
    .word 0x00441025 // 0012CCC4:  or $v0, $v0, $a0
    .word 0xfce20000 // 0012CCC8:  sd $v0, ($a3)
    .word 0x03e00008 // 0012CCCC:  jr $ra
    .word 0x00000000 // 0012CCD0:  nop
}
#else

void func_0012CC98(u64 *p, u32 a1, u32 a2) {
    if (!p) {
        return;
    }
    *(u16 *)p = 0x40;
    *p = ((u64)(a2) << 40) | (((u64)(a1 & 0x00ffffff)) << 16) | 0x40;
}

#endif

}
