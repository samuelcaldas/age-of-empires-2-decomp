/* Function: func_0012CC20 (0x0012CC20 - 0x0012CC48)
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
asm void func_0012CC20(void) {
    .word 0x27bdfff0 // 0012CC20:  addiu $sp, $sp, -0x10
    .word 0x0000102d // 0012CC24:  move $v0, $zero
    .word 0x10800004 // 0012CC28:  beqz $a0, 0x12cc3c
    .word 0xffbf0000 // 0012CC2C:  sd $ra, ($sp)
    .word 0x0c046b34 // 0012CC30:  jal 0x11acd0
    .word 0x24840004 // 0012CC34:  addiu $a0, $a0, 4
    .word 0x24420005 // 0012CC38:  addiu $v0, $v0, 5
    .word 0xdfbf0000 // 0012CC3C:  ld $ra, ($sp)
    .word 0x03e00008 // 0012CC40:  jr $ra
    .word 0x27bd0010 // 0012CC44:  addiu $sp, $sp, 0x10
}
#else

int func_0011ACD0(const char *);

void *func_0012CC20(void *a0) {
    if (a0 == 0) {
        return 0;
    }
    return (void *)(long)(func_0011ACD0((char *)a0 + 4) + 5);
}

#endif

}
