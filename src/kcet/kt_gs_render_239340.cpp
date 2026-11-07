#include "kt_gs_render_239340.h"

extern "C" {
void func_00100850(...);
void func_00239E90(...);
void func_002D4D90(...);
void memset(...);
}

// func_00239340 (0x239340, size 0xC8)
asm int func_00239340(void* a0, void* a1, void* a2, void* a3) {
    .word 0x27bdffd0
    .word 0x7fbf0020
    .word 0x3c02004e
    .word 0x7fb10010
    .word 0x7fb00000
    .word 0x2442afc0
    .word 0xac82000c
    .word 0x70808628
    .word 0xac850004
    jal func_00100850
    .word 0x24040014
    .word 0x10400004
    .word 0x70408e28
    .word 0x8e050004
    jal func_002D4D90
    .word 0x72202628
    .word 0x2402ffff
    .word 0xae110000
    .word 0xae021068
    .word 0xae02106c
    .word 0xae021070
    .word 0xae021074
    .word 0xae021078
    jal func_00239E90
    .word 0x72002628
    .word 0x24020001
    .word 0xa2020008
    .word 0xae0019f0
    .word 0x1000000c
    .word 0x70008e28
    .word 0x00111200
    .word 0x02021021
    .word 0x24440010
    .word 0x24060100
    jal memset
    .word 0x70002e28
    .word 0x00111080
    .word 0x2403ffff
    .word 0x02021021
    .word 0x26310001
    .word 0xac431010
    .word 0x2a220010
    .word 0x1440fff4
    .word 0x00111200
    .word 0x72001628
    .word 0x7bbf0020
    .word 0x7bb10010
    .word 0x7bb00000
    .word 0x03e00008
    .word 0x27bd0030
}
