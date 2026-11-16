/* Function: func_0012CC78 (0x0012CC78 - 0x0012CC94)
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
asm int func_0012CC78(const char *str) {
    .word 0x10800004 // 0012CC78:  beqz $a0, 0x12cc8c
    .word 0x0000102d // 0012CC7C:  move $v0, $zero
    .word 0x80820000 // 0012CC80:  lb $v0, ($a0)
    .word 0x38420040 // 0012CC84:  xori $v0, $v0, 0x40
    .word 0x2c420001 // 0012CC88:  sltiu $v0, $v0, 1
    .word 0x03e00008 // 0012CC8C:  jr $ra
    .word 0x00000000 // 0012CC90:  nop
}
#else

int func_0012CC78(const char *str) {
    if (!str) {
        return 0;
    }
    return *str == '@';
}

#endif

}
