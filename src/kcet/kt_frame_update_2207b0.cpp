#pragma exceptions off
#include "kt_frame_update_2207b0.h"

extern "C" {
int func_3741D0(void);
int func_123920(void);
int func_123908(void);
int func_221550(void *a0);
int func_123888(void);
int func_123818(void);
int func_133E10(void);
int func_221440(void);
int func_220420(void *a0, int a1, void *a2, int a3);
int func_00220D50(void);
int func_00220DA0(void);

#ifdef __MWERKS__
asm void func_002207B0(void) {
    addiu $sp, $sp, -0x20
    sq $ra, 0x10($sp)
    sq $s0, 0($sp)
    lui $v0, 0xCA
    jal func_3741D0
    addiu $s0, $v0, 0x15B0
    .word 0x3C0100CA // lui $at, 0xCA
    .word 0x9022157C // lbu $v0, 0x157C($at)
    .word 0x0002177C // sll
    .word 0x000217FE // sra
    .word 0x1040002E // beq $v0, $zero, +0x2e
    .word 0x00000000 // nop
    .word 0x3C0100CA // lui $at, 0xCA
    .word 0x8C261590 // lw $a2, 0x1590($at)
    .word 0x8F848B54 // lw $a0, -0x74AC($gp)
    .word 0x2405F000 // addiu $a1, $zero, -0x1000
    .word 0x2403FFFE // addiu $v1, $zero, -2
    .word 0x3C0100CA // lui $at, 0xCA
    .word 0x8C221598 // lw $v0, 0x1598($at)
    .word 0x00063080
    .word 0x00461021
    .word 0x30460FFF
    .word 0x00041080
    .word 0x00441021
    .word 0x000210C0
    .word 0x02024021
    .word 0x95070018 // lhu $a3, 0x18($t0)
    .word 0x3C02FF80 // lui $v0, 0xFF80
    .word 0x3C0100CA // lui $at, 0xCA
    .word 0x34420FFF
    .word 0x70002628 // por $a0, $zero, $zero
    .word 0x00E52824
    .word 0x00A62825
    .word 0xA5050018 // sh $a1, 0x18($t0)
    .word 0x8C27159C // lw $a3, 0x159C($at)
    .word 0x8F868B54 // lw $a2, -0x74AC($gp)
    .word 0x3C0100CA // lui $at, 0xCA
    .word 0x8C251594 // lw $a1, 0x1594($at)
    .word 0x00E52821
    .word 0x00A31824
    .word 0x00062880
    .word 0x00A62821
    .word 0x000528C0
    .word 0x02053021
    .word 0x8CC50018 // lw $a1, 0x18($a2)
    .word 0x306307FF
    .word 0x00031B00
    .word 0x00A21024
    .word 0x00431025
    jal func_123920
    .word 0xACC20018 // sw $v0, 0x18($a2)
    jal func_123908
    .word 0x70002628 // por $a0, $zero, $zero
    jal func_221550
    .word 0x70402628 // por $a0, $v0, $zero
    .word 0x10000008 // beq $zero, $zero, +8
    .word 0x00000000 // nop
    .word 0x3C0200C8 // lui $v0, 0xC8
    .word 0x24462510 // addiu $a2, $v0, 0x2510
    .word 0x3C0200C8 // lui $v0, 0xC8
    .word 0x24472510 // addiu $a3, $v0, 0x2510
    .word 0x70002628 // por $a0, $zero, $zero
    jal func_123888
    .word 0x3C050001 // lui $a1, 1
    jal func_123818
    nop
    jal func_133E10
    nop
    jal func_123818
    nop
    jal func_221440
    nop
    addiu $v1, $zero, 1
    .word 0xAF838B50 // sw $v1, -0x74B0($gp)
    lq $ra, 0x10($sp)
    lq $s0, 0($sp)
    jr $ra
    addiu $sp, $sp, 0x20
}

asm void func_002208F0(void) {
    lui $v0, 0xC9
    addiu $a0, $v0, 0x2D10
    addiu $sp, $sp, -0x10
    lui $v0, 0x22
    addiu $a1, $zero, 2
    addiu $a2, $v0, 0x0D50
    sq $ra, 0($sp)
    jal func_220420
    addiu $a3, $zero, -1
    lui $v0, 0xC9
    addiu $a0, $v0, 0x2D20
    lui $v0, 0x22
    addiu $a1, $zero, 3
    addiu $a2, $v0, 0x0DA0
    jal func_220420
    addiu $a3, $zero, -1
    lq $ra, 0($sp)
    jr $ra
    addiu $sp, $sp, 0x10
}
#else
void func_002207B0(void) {
    func_3741D0();
    if ((char)D_00CA157C != 0) {
        func_123920();
        func_123908();
        func_221550(0);
    } else {
        func_123888();
        func_123818();
        func_133E10();
        func_123818();
        func_221440();
    }
    D_004E3310 = 1;
}

void func_002208F0(void) {
    func_220420(&D_00C92D10, 2, (void *)func_00220D50, -1);
    func_220420(&D_00C92D20, 3, (void *)func_00220DA0, -1);
}
#endif
}
