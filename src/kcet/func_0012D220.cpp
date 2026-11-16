/* Function: func_0012D220 (0x0012D220 - 0x0012D228)
 * Origin: SLES-50282, KCET kt_file module (originally compiled with ee-gcc -O2 -G0)
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
asm void *func_0012D220(void) {
    .word 0x03e00008 // 0012d220:  jr $ra
    .word 0x0000102d // 0012d224:  move $v0, $zero
}
#else

void *func_0012D220(void) {
    return 0;
}

#endif

}
