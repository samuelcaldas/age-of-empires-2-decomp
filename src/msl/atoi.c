#ifndef NULL
#define NULL 0
#endif

#ifdef __MWERKS__
extern void func_11C5F8(void);

asm int atoi(const char *str) {
    addiu $sp, $sp, -0x10
    daddu $a1, $zero, $zero
    sd $ra, 0x0($sp)
    jal func_11C5F8
    addiu $a2, $zero, 0xA
    ld $ra, 0x0($sp)
    dsll32 $v0, $v0, 0
    dsra32 $v0, $v0, 0
    jr $ra
    addiu $sp, $sp, 0x10
}
#else
#include <stdlib.h>
int atoi(const char *str) {
    return (int)strtol(str, NULL, 10);
}
#endif

int msl_atoi(const char *str) {
    return atoi(str);
}
