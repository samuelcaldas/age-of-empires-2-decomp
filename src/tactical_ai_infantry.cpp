#include "sub_list.h"

extern "C" {

asm void func_001446EC(void) {
    .set noreorder
    .set noat
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void *func_001446F0(void *self, void *p1) {
    .set noreorder
    .set noat
    .word 0xD0FFBD27 // addiu sp, sp, -0x30
    .word 0x2000BF7F // sq ra, 0x20(sp)
    .word 0x1000B17F // sq s1, 0x10(sp)
    .word 0x0000B07F // sq s0, 0x0(sp)
    .word 0x288E8070 // paddub s1, a0, zero
    .word 0x0C002012 // beqz s1, .L00144738
    .word 0x2886A070 // paddub s0, a1, zero
    .word 0x4D00023C // lui v0, %hi(D_4D7780)
    .word 0x80774224 // addiu v0, v0, %lo(D_4D7780)
    .word 0x000022AE // sw v0, 0x0(s1)
    .word 0xD414050C // jal func_00145350
    .word 0x282E0070 // paddub a1, zero, zero
    .word 0x3C141000 // dsll32 v0, s0, 16
    .word 0x3F140200 // dsra32 v0, v0, 16
    .word 0x04004018 // blez v0, .L0014473C
    .word 0x28162072 // paddub v0, s1, zero
    .word 0x9C01040C // jal func_00100670
    .word 0x28262072 // paddub a0, s1, zero
  // .L00144738:
    .word 0x28162072 // paddub v0, s1, zero
  // .L0014473C:
    .word 0x2000BF7B // lq ra, 0x20(sp)
    .word 0x1000B17B // lq s1, 0x10(sp)
    .word 0x0000B07B // lq s0, 0x0(sp)
    .word 0x0800E003 // jr ra
    .word 0x3000BD27 // addiu sp, sp, 0x30
    .set reorder
    .set at
}

asm void func_00144750(void *self, void *p1, void *p2, void *p3) {
    .set noreorder
    .set noat
    .word 0xD0FFBD27 // addiu sp, sp, -0x30
    .word 0x1000BF7F // sq ra, 0x10(sp)
    .word 0x0000B07F // sq s0, 0x0(sp)
    .word 0x2C00A4AF // sw a0, 0x2C(sp)
    .word 0x2C00A48F // lw a0, 0x2C(sp)
    .word 0x2886E070 // paddub s0, a3, zero
    .word 0x283EC070 // paddub a3, a2, zero
    .word 0x2846A070 // paddub t0, a1, zero
    .word 0x4900023C // lui v0, %hi(D_490FA0)
    .word 0xA00F4524 // addiu a1, v0, %lo(D_490FA0)
    .word 0xAC14050C // jal func_001452B0
    .word 0xE8030624 // addiu a2, zero, 0x3E8
    .word 0x4D00023C // lui v0, %hi(D_4D77D0)
    .word 0xD0774524 // addiu a1, v0, %lo(D_4D77D0)
    .word 0x2C00A28F // lw v0, 0x2C(sp)
    .word 0x2C010324 // addiu v1, zero, 0x12C
    .word 0xB0040424 // addiu a0, zero, 0x4B0
    .word 0x000045AC // sw a1, 0x0(v0)
    .word 0x2C00A28F // lw v0, 0x2C(sp)
    .word 0xAC0050AC // sw s0, 0xAC(v0)
    .word 0x2C00A28F // lw v0, 0x2C(sp)
    .word 0xB00040AC // sw zero, 0xB0(v0)
    .word 0x2C00A28F // lw v0, 0x2C(sp)
    .word 0xB40040AC // sw zero, 0xB4(v0)
    .word 0x2C00A28F // lw v0, 0x2C(sp)
    .word 0xB80040AC // sw zero, 0xB8(v0)
    .word 0x2C00A28F // lw v0, 0x2C(sp)
    .word 0xCC01040C // jal func_100730
    .word 0xBC0043AC // sw v1, 0xBC(v0)
    .word 0x2C00A38F // lw v1, 0x2C(sp)
    .word 0xB00062AC // sw v0, 0xB0(v1)
    .word 0x2C00A28F // lw v0, 0x2C(sp)
    .word 0x1000BF7B // lq ra, 0x10(sp)
    .word 0x0000B07B // lq s0, 0x0(sp)
    .word 0x0800E003 // jr ra
    .word 0x3000BD27 // addiu sp, sp, 0x30
    .set reorder
    .set at
}

asm void func_001447E0(void *self, void *p1, void *p2, void *p3) {
    .set noreorder
    .set noat
    .word 0xC0FFBD27 // addiu sp, sp, -0x40
    .word 0x2000BF7F // sq ra, 0x20(sp)
    .word 0x1000B17F // sq s1, 0x10(sp)
    .word 0x0000B07F // sq s0, 0x0(sp)
    .word 0x3400A4AF // sw a0, 0x34(sp)
    .word 0x3400A48F // lw a0, 0x34(sp)
    .word 0x288EE070 // paddub s1, a3, zero
    .word 0x2886C070 // paddub s0, a2, zero
    .word 0x283EA070 // paddub a3, a1, zero
    .word 0x4900023C // lui v0, %hi(D_490FA0)
    .word 0xA00F4524 // addiu a1, v0, %lo(D_490FA0)
    .word 0xE8030624 // addiu a2, zero, 0x3E8
    .word 0xAC14050C // jal func_001452B0
    .word 0x28460070 // paddub t0, zero, zero
    .word 0x4D00023C // lui v0, %hi(D_4D77D0)
    .word 0xD0774524 // addiu a1, v0, %lo(D_4D77D0)
    .word 0x3400A28F // lw v0, 0x34(sp)
    .word 0x2C010324 // addiu v1, zero, 0x12C
    .word 0xB0040424 // addiu a0, zero, 0x4B0
    .word 0x000045AC // sw a1, 0x0(v0)
    .word 0x3400A28F // lw v0, 0x34(sp)
    .word 0xAC0050AC // sw s0, 0xAC(v0)
    .word 0x3400A28F // lw v0, 0x34(sp)
    .word 0xB00040AC // sw zero, 0xB0(v0)
    .word 0x3400A28F // lw v0, 0x34(sp)
    .word 0xB40040AC // sw zero, 0xB4(v0)
    .word 0x3400A28F // lw v0, 0x34(sp)
    .word 0xB80040AC // sw zero, 0xB8(v0)
    .word 0x3400A28F // lw v0, 0x34(sp)
    .word 0xCC01040C // jal func_100730
    .word 0xBC0043AC // sw v1, 0xBC(v0)
    .word 0x3400A38F // lw v1, 0x34(sp)
    .word 0x3800A527 // addiu a1, sp, 0x38
    .word 0x04000624 // addiu a2, zero, 0x4
    .word 0x28262072 // paddub a0, s1, zero
    .word 0x649B080C // jal func_00226D90
    .word 0xB00062AC // sw v0, 0xB0(v1)
    .word 0x2C000010 // b .L00144928
    .word 0x28860070 // paddub s0, zero, zero
  // .L00144880:
    .word 0x3C00A527 // addiu a1, sp, 0x3C
    .word 0x04000624 // addiu a2, zero, 0x4
    .word 0x649B080C // jal func_00226D90
    .word 0x28262072 // paddub a0, s1, zero
    .word 0x3400A68F // lw a2, 0x34(sp)
    .word 0x3C00A48F // lw a0, 0x3C(sp)
    .word 0xB400C78C // lw a3, 0xB4(a2)
    .word 0x0A000010 // b .L001448C4
    .word 0x282E0070 // paddub a1, zero, zero
  // .L001448A0:
    .word 0xB000C28C // lw v0, 0xB0(a2)
    .word 0x80180500 // sll v1, a1, 2
    .word 0x21104300 // addu v0, v0, v1
    .word 0x0000428C // lw v0, 0x0(v0)
    .word 0x04008254 // bnel a0, v0, .L001448C4
    .word 0x0100A524 // addiu a1, a1, 0x1
    .word 0x0A000010 // b .L001448E4
    .word 0x01000324 // addiu v1, zero, 0x1
  // .L001448C4:
    .word 0x0100A524 // addiu a1, a1, 0x1
    .word 0x2A08A700 // slt at, a1, a3
    .word 0x06002010 // beqz at, .L001448E4
    .word 0x281E0070 // paddub v1, zero, zero
    .word 0xBC00C28C // lw v0, 0xBC(a2)
    .word 0x2A10A200 // slt v0, a1, v0
    .word 0xF1FF4014 // bnez v0, .L001448A0
    .word 0x00000000 // nop
    .word 0x281E0070 // paddub v1, zero, zero
  // .L001448E4:
    .word 0x01000224 // addiu v0, zero, 0x1
    .word 0x0F006250 // beql v1, v0, .L00144928
    .word 0x01001026 // addiu s0, s0, 0x1
    .word 0xBC00C28C // lw v0, 0xBC(a2)
    .word 0xFFFF4224 // addiu v0, v0, -0x1
    .word 0x2A084700 // slt at, v0, a3
    .word 0x09002014 // bnez at, .L00144924
    .word 0x00000000 // nop
    .word 0xB000C28C // lw v0, 0xB0(a2)
    .word 0x80180700 // sll v1, a3, 2
    .word 0x21104300 // addu v0, v0, v1
    .word 0x000044AC // sw a0, 0x0(v0)
    .word 0x3400A38F // lw v1, 0x34(sp)
    .word 0xB400628C // lw v0, 0xB4(v1)
    .word 0x01004224 // addiu v0, v0, 0x1
    .word 0xB40062AC // sw v0, 0xB4(v1)
  // .L00144924:
    .word 0x01001026 // addiu s0, s0, 0x1
  // .L00144928:
    .word 0x3800A28F // lw v0, 0x38(sp)
    .word 0x2A100202 // slt v0, s0, v0
    .word 0xD3FF4014 // bnez v0, .L00144880
    .word 0x3C00A527 // addiu a1, sp, 0x3C
    .word 0x3400A28F // lw v0, 0x34(sp)
    .word 0x2000BF7B // lq ra, 0x20(sp)
    .word 0x1000B17B // lq s1, 0x10(sp)
    .word 0x0000B07B // lq s0, 0x0(sp)
    .word 0x0800E003 // jr ra
    .word 0x4000BD27 // addiu sp, sp, 0x40
    .set reorder
    .set at
}

asm void *func_00144950(void *self, void *p1) {
    .set noreorder
    .set noat
    .word 0xD0FFBD27 // addiu sp, sp, -0x30
    .word 0x2000BF7F // sq ra, 0x20(sp)
    .word 0x1000B17F // sq s1, 0x10(sp)
    .word 0x0000B07F // sq s0, 0x0(sp)
    .word 0x288E8070 // paddub s1, a0, zero
    .word 0x19002012 // beqz s1, .L001449CC
    .word 0x2886A070 // paddub s0, a1, zero
    .word 0x4D00023C // lui v0, %hi(D_4D77D0)
    .word 0xD0774224 // addiu v0, v0, %lo(D_4D77D0)
    .word 0x000022AE // sw v0, 0x0(s1)
    .word 0xB0002226 // addiu v0, s1, 0xB0
    .word 0x0A004010 // beqz v0, .L001449A8
    .word 0xAC0020AE // sw zero, 0xAC(s1)
    .word 0xB000248E // lw a0, 0xB0(s1)
    .word 0x04008010 // beqz a0, .L0014499C
    .word 0x00000000 // nop
    .word 0x8C01040C // jal func_00100630
    .word 0x00000000 // nop
    .word 0xB00020AE // sw zero, 0xB0(s1)
  // .L0014499C:
    .word 0xB40020AE // sw zero, 0xB4(s1)
    .word 0xB80020AE // sw zero, 0xB8(s1)
    .word 0xBC0020AE // sw zero, 0xBC(s1)
  // .L001449A8:
    .word 0x28262072 // paddub a0, s1, zero
    .word 0xD414050C // jal func_00145350
    .word 0x282E0070 // paddub a1, zero, zero
    .word 0x3C141000 // dsll32 v0, s0, 16
    .word 0x3F140200 // dsra32 v0, v0, 16
    .word 0x04004018 // blez v0, .L001449D0
    .word 0x28162072 // paddub v0, s1, zero
    .word 0x9C01040C // jal func_00100670
    .word 0x28262072 // paddub a0, s1, zero
  // .L001449CC:
    .word 0x28162072 // paddub v0, s1, zero
  // .L001449D0:
    .word 0x2000BF7B // lq ra, 0x20(sp)
    .word 0x1000B17B // lq s1, 0x10(sp)
    .word 0x0000B07B // lq s0, 0x0(sp)
    .word 0x0800E003 // jr ra
    .word 0x3000BD27 // addiu sp, sp, 0x30
    .set reorder
    .set at
}

asm void func_001449F0(void) {
    .set noreorder
    .set noat
    .word 0x0800E003 // jr ra
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_00144A00(void *self, void *p1) {
    .set noreorder
    .set noat
    .word 0xB0FFBD27 // addiu sp, sp, -0x50
    .word 0x3000BF7F // sq ra, 0x30(sp)
    .word 0x2000B27F // sq s2, 0x20(sp)
    .word 0x1000B17F // sq s1, 0x10(sp)
    .word 0x0000B07F // sq s0, 0x0(sp)
    .word 0xB400828C // lw v0, 0xB4(a0)
    .word 0x288EA070 // paddub s1, a1, zero
    .word 0x28968070 // paddub s2, a0, zero
    .word 0x4C00A527 // addiu a1, sp, 0x4C
    .word 0x04000624 // addiu a2, zero, 0x4
    .word 0x4C00A2AF // sw v0, 0x4C(sp)
    .word 0xDC9B080C // jal func_00226F70
    .word 0x28262072 // paddub a0, s1, zero
    .word 0x12000010 // b .L00144A80
    .word 0x28860070 // paddub s0, zero, zero
  // .L00144A3C:
    .word 0xBC00428E // lw v0, 0xBC(s2)
    .word 0xFFFF4224 // addiu v0, v0, -0x1
    .word 0x2A085000 // slt at, v0, s0
    .word 0x03002010 // beqz at, .L00144A58
    .word 0x00000000 // nop
    .word 0x04000010 // b .L00144A64
    .word 0xB000428E // lw v0, 0xB0(s2)
  // .L00144A58:
    .word 0xB000428E // lw v0, 0xB0(s2)
    .word 0x80181000 // sll v1, s0, 2
    .word 0x21104300 // addu v0, v0, v1
  // .L00144A64:
    .word 0x0000428C // lw v0, 0x0(v0)
    .word 0x4C00A527 // addiu a1, sp, 0x4C
    .word 0x04000624 // addiu a2, zero, 0x4
    .word 0x28262072 // paddub a0, s1, zero
    .word 0xDC9B080C // jal func_00226F70
    .word 0x4C00A2AF // sw v0, 0x4C(sp)
    .word 0x01001026 // addiu s0, s0, 0x1
  // .L00144A80:
    .word 0xB400428E // lw v0, 0xB4(s2)
    .word 0x2A100202 // slt v0, s0, v0
    .word 0xECFF4014 // bnez v0, .L00144A3C
    .word 0x00000000 // nop
    .word 0x3000BF7B // lq ra, 0x30(sp)
    .word 0x2000B27B // lq s2, 0x20(sp)
    .word 0x1000B17B // lq s1, 0x10(sp)
    .word 0x0000B07B // lq s0, 0x0(sp)
    .word 0x01000224 // addiu v0, zero, 0x1
    .word 0x0800E003 // jr ra
    .word 0x5000BD27 // addiu sp, sp, 0x50
    .set reorder
    .set at
}

}
