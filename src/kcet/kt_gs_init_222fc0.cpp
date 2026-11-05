#include "kt_gs_init_222fc0.h"

extern "C" {
void func_00222310(void);
void func_002222D0(void);

#if defined(__MWERKS__) && defined(__MIPS__)
asm void *func_00222FC0(void) {
    .word 0x3C0100C9
    .word 0x8C242D44
    .word 0x70001628
    .word 0x3C0100C9
    .word 0x94252D40
    .word 0x00000000
    .word 0x90830000
    .word 0x54600004
    .word 0x24A5FFFF
    .word 0x10000004
    .word 0x70801628
    .word 0x24A5FFFF
    .word 0x14A0FFF9
    .word 0x2484000C
    .word 0x03E00008
    .word 0x00000000
}

asm unsigned char func_00223000(int idx) {
    .word 0x00041040
    .word 0x00441021
    .word 0x00021880
    .word 0x3C02003B
    .word 0x24429EE8
    .word 0x00431021
    .word 0x8C430000
    .word 0x3C020048
    .word 0x2442BDF0
    .word 0x00031940
    .word 0x00431021
    .word 0x03E00008
    .word 0x90420000
}

asm unsigned char func_00223040(int idx) {
    .word 0x00041040
    .word 0x00441021
    .word 0x00021880
    .word 0x3C02003B
    .word 0x24429EE8
    .word 0x00431021
    .word 0x8C430000
    .word 0x3C020048
    .word 0x2442BDF1
    .word 0x00031940
    .word 0x00431021
    .word 0x03E00008
    .word 0x90420000
}

asm void func_00223080(void *p0, short p1, short p2) {
    .word 0x00061080
    .word 0x00461021
    .word 0x3C0100C9
    .word 0x00021080
    .word 0xAC242D48
    .word 0x00821021
    .word 0x3C0100C9
    .word 0xAC222D44
    .word 0x3C0100C9
    .word 0xA4262D42
    .word 0x3C0100C9
    j func_00222310
    .word 0xA4252D40
}

asm void func_002230C0(void) {
    j func_002222D0
    .word 0x00000000
}
#else
void *func_00222FC0(void) {
    return (void *)0;
}

unsigned char func_00223000(int idx) {
    return 0;
}

unsigned char func_00223040(int idx) {
    return 0;
}

void func_00223080(void *p0, short p1, short p2) {
}

void func_002230C0(void) {
}
#endif
}
