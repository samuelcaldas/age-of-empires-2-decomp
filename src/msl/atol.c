#ifndef NULL
#define NULL 0
#endif

#ifdef __MWERKS__
extern void func_11C5F8(void);

asm long atol(const char *str) {
    addiu $sp, $sp, -0x10
    daddu $a1, $zero, $zero
    sd $ra, 0x0($sp)
    jal func_11C5F8
    addiu $a2, $zero, 0xA
    ld $ra, 0x0($sp)
    jr $ra
    addiu $sp, $sp, 0x10
}
#else
#include <stdlib.h>
long atol(const char *str) {
    return strtol(str, NULL, 10);
}
#endif

long msl_atol(const char *str) {
    return atol(str);
}
