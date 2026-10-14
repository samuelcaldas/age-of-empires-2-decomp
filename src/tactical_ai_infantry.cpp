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

asm void func_00144AB0(void *self, void *p1) {
    .set noreorder
    .set noat
    .word 0x0300A014 // bnez a1, .L00144AC0
    .word 0x00000000 // nop
    .word 0x26000010 // b .L00144B54
    .word 0x28160070 // paddub v0, zero, zero
  // .L00144AC0:
    .word 0x2400A584 // lh a1, 0x24(a1)
    .word 0xB400878C // lw a3, 0xB4(a0)
    .word 0x0A000010 // b .L00144AF4
    .word 0x28360070 // paddub a2, zero, zero
  // .L00144AD0:
    .word 0xB000828C // lw v0, 0xB0(a0)
    .word 0x80180600 // sll v1, a2, 2
    .word 0x21104300 // addu v0, v0, v1
    .word 0x0000428C // lw v0, 0x0(v0)
    .word 0x04008254 // bnel a1, v0, .L00144AF4
    .word 0x0100C624 // addiu a2, a2, 0x1
    .word 0x0A000010 // b .L00144B14
    .word 0x01000324 // addiu v1, zero, 0x1
    .word 0x0100C624 // addiu a2, a2, 0x1
  // .L00144AF4:
    .word 0x2A08C700 // slt at, a2, a3
    .word 0x06002010 // beqz at, .L00144B14
    .word 0x281E0070 // paddub v1, zero, zero
    .word 0xBC00828C // lw v0, 0xBC(a0)
    .word 0x2A10C200 // slt v0, a2, v0
    .word 0xF1FF4014 // bnez v0, .L00144AD0
    .word 0x00000000 // nop
    .word 0x281E0070 // paddub v1, zero, zero
  // .L00144B14:
    .word 0x01000224 // addiu v0, zero, 0x1
    .word 0x0E006210 // beq v1, v0, .L00144B54
    .word 0x01000224 // addiu v0, zero, 0x1
    .word 0xBC00828C // lw v0, 0xBC(a0)
    .word 0xFFFF4224 // addiu v0, v0, -0x1
    .word 0x2A084700 // slt at, v0, a3
    .word 0x08002014 // bnez at, .L00144B50
    .word 0x00000000 // nop
    .word 0xB000828C // lw v0, 0xB0(a0)
    .word 0x80180700 // sll v1, a3, 2
    .word 0x21104300 // addu v0, v0, v1
    .word 0x000045AC // sw a1, 0x0(v0)
    .word 0xB400828C // lw v0, 0xB4(a0)
    .word 0x01004224 // addiu v0, v0, 0x1
    .word 0xB40082AC // sw v0, 0xB4(a0)
  // .L00144B50:
    .word 0x01000224 // addiu v0, zero, 0x1
  // .L00144B54:
    .word 0x0800E003 // jr ra
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_00144B60(void *self, void *p1) {
    .set noreorder
    .set noat
    .word 0xBC00878C // lw a3, 0xBC(a0)
    .word 0x02000010 // b .L00144B70
    .word 0x28360070 // paddub a2, zero, zero
    .word 0x0100C624 // addiu a2, a2, 0x1
  // .L00144B70:
    .word 0x2A08C700 // slt at, a2, a3
    .word 0x08002010 // beqz at, .L00144B98
    .word 0x2A10C700 // slt v0, a2, a3
    .word 0xB000828C // lw v0, 0xB0(a0)
    .word 0x80180600 // sll v1, a2, 2
    .word 0x21104300 // addu v0, v0, v1
    .word 0x0000428C // lw v0, 0x0(v0)
    .word 0xF8FFA254 // bnel a1, v0, .L00144B70
    .word 0x0100C624 // addiu a2, a2, 0x1
    .word 0x2A10C700 // slt v0, a2, a3
  // .L00144B98:
    .word 0x09004014 // bnez v0, .L00144BC0
    .word 0x00000000 // nop
    .word 0x14000010 // b .L00144BF4
    .word 0x28160070 // paddub v0, zero, zero
  // .L00144BA8:
    .word 0xB000828C // lw v0, 0xB0(a0)
    .word 0x80180600 // sll v1, a2, 2
    .word 0x0100C624 // addiu a2, a2, 0x1
    .word 0x21184300 // addu v1, v0, v1
    .word 0x0400628C // lw v0, 0x4(v1)
    .word 0x000062AC // sw v0, 0x0(v1)
  // .L00144BC0:
    .word 0xBC00828C // lw v0, 0xBC(a0)
    .word 0xFFFF4224 // addiu v0, v0, -0x1
    .word 0x2A10C200 // slt v0, a2, v0
    .word 0xF6FF4014 // bnez v0, .L00144BA8
    .word 0x00000000 // nop
    .word 0xB400828C // lw v0, 0xB4(a0)
    .word 0xFFFF4224 // addiu v0, v0, -0x1
    .word 0xB40082AC // sw v0, 0xB4(a0)
    .word 0xB400828C // lw v0, 0xB4(a0)
    .word 0x03004104 // bgez v0, .L00144BF4
    .word 0x01000224 // addiu v0, zero, 0x1
    .word 0xB40080AC // sw zero, 0xB4(a0)
    .word 0x01000224 // addiu v0, zero, 0x1
  // .L00144BF4:
    .word 0x0800E003 // jr ra
    .word 0x00000000 // nop
    .set reorder
    .set at
}

asm void func_00144C00(void *self, void *p1) {
    .set noreorder
    .set noat
    .word 0xA0FFBD27 // addiu sp, sp, -0x60
    .word 0x5000BF7F // sq ra, 0x50(sp)
    .word 0x4000B47F // sq s4, 0x40(sp)
    .word 0x3000B37F // sq s3, 0x30(sp)
    .word 0x2000B27F // sq s2, 0x20(sp)
    .word 0x1000B17F // sq s1, 0x10(sp)
    .word 0x0000B07F // sq s0, 0x0(sp)
    .word 0x289E8070 // paddub s3, a0, zero
    .word 0x2896A070 // paddub s2, a1, zero
    .word 0x28860070 // paddub s0, zero, zero
    .word 0x21000010 // b .L00144CB0
    .word 0x288E0070 // paddub s1, zero, zero
  // .L00144C30:
    .word 0xBC00628E // lw v0, 0xBC(s3)
    .word 0xFFFF4224 // addiu v0, v0, -0x1
    .word 0x2A085100 // slt at, v0, s1
    .word 0x03002010 // beqz at, .L00144C4C
    .word 0xAC00648E // lw a0, 0xAC(s3)
    .word 0x04000010 // b .L00144C58
    .word 0xB000628E // lw v0, 0xB0(s3)
  // .L00144C4C:
    .word 0xB000628E // lw v0, 0xB0(s3)
    .word 0x80181100 // sll v1, s1, 2
    .word 0x21104300 // addu v0, v0, v1
  // .L00144C58:
    .word 0x0000458C // lw a1, 0x0(v0)
    .word 0x98CB0C0C // jal func_332e60
    .word 0x980B848C // lw a0, 0xB98(a0)
    .word 0x28A64070 // paddub s4, v0, zero
    .word 0x11008052 // beql s4, zero, .L00144CB0
    .word 0x01003126 // addiu s1, s1, 0x1
    .word 0x0000998E // lw t9, 0x0(s4)
    .word 0x6401398F // lw t9, 0x164(t9)
    .word 0x09F82003 // jalr t9
    .word 0x28268072 // paddub a0, s4, zero
    .word 0x0A004010 // beqz v0, .L00144CAC
    .word 0x00000000 // nop
    .word 0x0000998E // lw t9, 0x0(s4)
    .word 0x6401398F // lw t9, 0x164(t9)
    .word 0x09F82003 // jalr t9
    .word 0x28268072 // paddub a0, s4, zero
    .word 0x681C050C // jal func_1471A0
    .word 0x0000448C // lw a0, 0x0(v0)
    .word 0x02004216 // bne s2, v0, .L00144CAC
    .word 0x00000000 // nop
    .word 0x01001026 // addiu s0, s0, 0x1
  // .L00144CAC:
    .word 0x01003126 // addiu s1, s1, 0x1
  // .L00144CB0:
    .word 0xB400628E // lw v0, 0xB4(s3)
    .word 0x2A102202 // slt v0, s1, v0
    .word 0xDDFF4014 // bnez v0, .L00144C30
    .word 0x00000000 // nop
    .word 0x28160072 // paddub v0, s0, zero
    .word 0x5000BF7B // lq ra, 0x50(sp)
    .word 0x4000B47B // lq s4, 0x40(sp)
    .word 0x3000B37B // lq s3, 0x30(sp)
    .word 0x2000B27B // lq s2, 0x20(sp)
    .word 0x1000B17B // lq s1, 0x10(sp)
    .word 0x0000B07B // lq s0, 0x0(sp)
    .word 0x0800E003 // jr ra
    .word 0x6000BD27 // addiu sp, sp, 0x60
    .set reorder
    .set at
}

asm void func_00144CF0(void) {
    .set noreorder
    .set noat
    .word 0x0800E003 // jr ra
    .word 0x28160070 // paddub v0, zero, zero
    .set reorder
    .set at
}

asm void func_00144D00(void *self) {
    .set noreorder
    .set noat
    .word 0xAC00828C // lw v0, 0xAC(a0)
    .word 0x98CB0C08 // j func_332e60
    .word 0x980B448C // lw a0, 0xB98(v0)
    .set reorder
    .set at
}

asm void func_00144D10(void *self, void *p1, void *p2, void *p3) {
    .set noreorder
    .set noat
    .word 0x50FFBD27 // addiu sp, sp, -0xB0
    .word 0x9000BF7F // sq ra, 0x90(sp)
    .word 0x8000BE7F // sq fp, 0x80(sp)
    .word 0x7000B77F // sq s7, 0x70(sp)
    .word 0x6000B67F // sq s6, 0x60(sp)
    .word 0x5000B57F // sq s5, 0x50(sp)
    .word 0x4000B47F // sq s4, 0x40(sp)
    .word 0x3000B37F // sq s3, 0x30(sp)
    .word 0x2000B27F // sq s2, 0x20(sp)
    .word 0x1000B17F // sq s1, 0x10(sp)
    .word 0x0000B07F // sq s0, 0x0(sp)
    .word 0x28B68070 // paddub s6, a0, zero
    .word 0x28AEA070 // paddub s5, a1, zero
    .word 0x28A6C070 // paddub s4, a2, zero
    .word 0x289EE070 // paddub s3, a3, zero
    .word 0x28960071 // paddub s2, t0, zero
    .word 0x28BE2071 // paddub s7, t1, zero
    .word 0x28F64071 // paddub fp, t2, zero
    .word 0xAC00ABAF // sw t3, 0xAC(sp)
    .word 0x79000010 // b .L00144F44
    .word 0x28860070 // paddub s0, zero, zero
  // .L00144D64:
    .word 0xBC00C28E // lw v0, 0xBC(s6)
    .word 0xFFFF4224 // addiu v0, v0, -0x1
    .word 0x2A085000 // slt at, v0, s0
    .word 0x03002010 // beqz at, .L00144D80
    .word 0xAC00C48E // lw a0, 0xAC(s6)
    .word 0x04000010 // b .L00144D8C
    .word 0xB000C28E // lw v0, 0xB0(s6)
  // .L00144D80:
    .word 0xB000C28E // lw v0, 0xB0(s6)
    .word 0x80181000 // sll v1, s0, 2
    .word 0x21104300 // addu v0, v0, v1
  // .L00144D8C:
    .word 0x0000458C // lw a1, 0x0(v0)
    .word 0x98CB0C0C // jal func_332e60
    .word 0x980B848C // lw a0, 0xB98(a0)
    .word 0x288E4070 // paddub s1, v0, zero
    .word 0x69002052 // beql s1, zero, .L00144F44
    .word 0x01001026 // addiu s0, s0, 0x1
    .word 0x0000398E // lw t9, 0x0(s1)
    .word 0x6401398F // lw t9, 0x164(t9)
    .word 0x09F82003 // jalr t9
    .word 0x28262072 // paddub a0, s1, zero
    .word 0x62004010 // beqz v0, .L00144F40
    .word 0x00000000 // nop
    .word 0xFFFF0224 // addiu v0, zero, -0x1
    .word 0x0500A212 // beq s5, v0, .L00144DD8
    .word 0xFFFF0224 // addiu v0, zero, -0x1
    .word 0x24002286 // lh v0, 0x24(s1)
    .word 0x5C005514 // bne v0, s5, .L00144F40
    .word 0x00000000 // nop
    .word 0xFFFF0224 // addiu v0, zero, -0x1
  // .L00144DD8:
    .word 0x06008212 // beq s4, v0, .L00144DF4
    .word 0xFFFF0224 // addiu v0, zero, -0x1
    .word 0x0400228E // lw v0, 0x4(s1)
    .word 0x08004284 // lh v0, 0x8(v0)
    .word 0x55005414 // bne v0, s4, .L00144F40
    .word 0x00000000 // nop
    .word 0xFFFF0224 // addiu v0, zero, -0x1
  // .L00144DF4:
    .word 0x06006212 // beq s3, v0, .L00144E10
    .word 0xFFFF0224 // addiu v0, zero, -0x1
    .word 0x0400228E // lw v0, 0x4(s1)
    .word 0x0E004284 // lh v0, 0xE(v0)
    .word 0x4E005314 // bne v0, s3, .L00144F40
    .word 0x00000000 // nop
    .word 0xFFFF0224 // addiu v0, zero, -0x1
  // .L00144E10:
    .word 0x0A004212 // beq s2, v0, .L00144E3C
    .word 0xFFFF0224 // addiu v0, zero, -0x1
    .word 0x0000398E // lw t9, 0x0(s1)
    .word 0x6401398F // lw t9, 0x164(t9)
    .word 0x09F82003 // jalr t9
    .word 0x28262072 // paddub a0, s1, zero
    .word 0x681C050C // jal func_1471A0
    .word 0x0000448C // lw a0, 0x0(v0)
    .word 0x43004216 // bne s2, v0, .L00144F40
    .word 0x00000000 // nop
    .word 0xFFFF0224 // addiu v0, zero, -0x1
  // .L00144E3C:
    .word 0x1400E212 // beq s7, v0, .L00144E90
    .word 0xFFFF0224 // addiu v0, zero, -0x1
    .word 0xBC00C28E // lw v0, 0xBC(s6)
    .word 0xFFFF4224 // addiu v0, v0, -0x1
    .word 0x2A085000 // slt at, v0, s0
    .word 0x03002010 // beqz at, .L00144E60
    .word 0x00000000 // nop
    .word 0x04000010 // b .L00144E6C
    .word 0xB000C28E // lw v0, 0xB0(s6)
  // .L00144E60:
    .word 0xB000C28E // lw v0, 0xB0(s6)
    .word 0x80181000 // sll v1, s0, 2
    .word 0x21104300 // addu v0, v0, v1
  // .L00144E6C:
    .word 0x0000D98E // lw t9, 0x0(s6)
    .word 0x0000458C // lw a1, 0x0(v0)
    .word 0x2826C072 // paddub a0, s6, zero
    .word 0x5800398F // lw t9, 0x58(t9)
    .word 0x09F82003 // jalr t9
    .word 0x2836E072 // paddub a2, s7, zero
    .word 0x2E004010 // beqz v0, .L00144F40
    .word 0x00000000 // nop
    .word 0xFFFF0224 // addiu v0, zero, -0x1
  // .L00144E90:
    .word 0x0900C213 // beq fp, v0, .L00144EB8
    .word 0x00000000 // nop
    .word 0x0000398E // lw t9, 0x0(s1)
    .word 0x6401398F // lw t9, 0x164(t9)
    .word 0x09F82003 // jalr t9
    .word 0x28262072 // paddub a0, s1, zero
    .word 0x701C050C // jal func_1471C0
    .word 0x0000448C // lw a0, 0x0(v0)
    .word 0x2300C217 // bne fp, v0, .L00144F40
    .word 0x00000000 // nop
  // .L00144EB8:
    .word 0xAC00A28F // lw v0, 0xAC(sp)
    .word 0xFFFF0324 // addiu v1, zero, -0x1
    .word 0x0A004310 // beq v0, v1, .L00144EEC
    .word 0x00000000 // nop
    .word 0x0000398E // lw t9, 0x0(s1)
    .word 0x6401398F // lw t9, 0x164(t9)
    .word 0x09F82003 // jalr t9
    .word 0x28262072 // paddub a0, s1, zero
    .word 0x741C050C // jal func_1471D0
    .word 0x0000448C // lw a0, 0x0(v0)
    .word 0xAC00A38F // lw v1, 0xAC(sp)
    .word 0x16006214 // bne v1, v0, .L00144F40
    .word 0x00000000 // nop
  // .L00144EEC:
    .word 0xB800A28F // lw v0, 0xB8(sp)
    .word 0xFFFF0324 // addiu v1, zero, -0x1
    .word 0x04004310 // beq v0, v1, .L00144F08
    .word 0x00000000 // nop
    .word 0x39002392 // lbu v1, 0x39(s1)
    .word 0x0F006214 // bne v1, v0, .L00144F40
    .word 0x00000000 // nop
  // .L00144F08:
    .word 0xC000A28F // lw v0, 0xC0(sp)
    .word 0xFFFF0324 // addiu v1, zero, -0x1
    .word 0x09004350 // beql v0, v1, .L00144F38
    .word 0x28162072 // paddub v0, s1, zero
    .word 0x00008244 // mtc1 v0, f0
    .word 0x400021C6 // lwc1 f1, 0x40(s1)
    .word 0x20008046 // cvt.s.w f0, f0
    .word 0x36080046 // c.le.s f1, f0
    .word 0x00000000 // nop
    .word 0x04000045 // bc1f .L00144F40
    .word 0x00000000 // nop
    .word 0x28162072 // paddub v0, s1, zero
  // .L00144F38:
    .word 0x08000010 // b .L00144F5C
    .word 0x9000BF7B // lq ra, 0x90(sp)
  // .L00144F40:
    .word 0x01001026 // addiu s0, s0, 0x1
  // .L00144F44:
    .word 0xB400C28E // lw v0, 0xB4(s6)
    .word 0x2A100202 // slt v0, s0, v0
    .word 0x85FF4014 // bnez v0, .L00144D64
    .word 0x00000000 // nop
    .word 0x28160070 // paddub v0, zero, zero
    .word 0x9000BF7B // lq ra, 0x90(sp)
  // .L00144F5C:
    .word 0x8000BE7B // lq fp, 0x80(sp)
    .word 0x7000B77B // lq s7, 0x70(sp)
    .word 0x6000B67B // lq s6, 0x60(sp)
    .word 0x5000B57B // lq s5, 0x50(sp)
    .word 0x4000B47B // lq s4, 0x40(sp)
    .word 0x3000B37B // lq s3, 0x30(sp)
    .word 0x2000B27B // lq s2, 0x20(sp)
    .word 0x1000B17B // lq s1, 0x10(sp)
    .word 0x0000B07B // lq s0, 0x0(sp)
    .word 0x0800E003 // jr ra
    .word 0xB000BD27 // addiu sp, sp, 0xB0
    .set reorder
    .set at
}

asm void func_00144F90(void *self, void *p1) {
    .set noreorder
    .set noat
    .word 0xF0FFBD27 // addiu sp, sp, -0x10
    .word 0x2836A070 // paddub a2, a1, zero
    .word 0x4900023C // lui v0, %hi(D_490FC0)
    .word 0x0000BF7F // sq ra, 0x0(sp)
    .word 0x3015050C // jal func_001454C0
    .word 0xC00F4524 // addiu a1, v0, %lo(D_490FC0)
    .word 0x0000BF7B // lq ra, 0x0(sp)
    .word 0xFFFF0224 // addiu v0, zero, -0x1
    .word 0x0800E003 // jr ra
    .word 0x1000BD27 // addiu sp, sp, 0x10
    .set reorder
    .set at
}

asm void func_00144FC0(void) {
    .set noreorder
    .set noat
    .word 0x0800E003 // jr ra
    .word 0x28160070 // paddub v0, zero, zero
    .set reorder
    .set at
}


asm void *func_00144FD0(void *self, void *p1, void *p2, void *p3) {
    .set noreorder
    .set noat
    .word 0x60FFBD27 // addiu sp, sp, -0xA0
    .word 0x9000BF7F // sq ra, 0x90(sp)
    .word 0x8000BE7F // sq fp, 0x80(sp)
    .word 0x7000B77F // sq s7, 0x70(sp)
    .word 0x6000B67F // sq s6, 0x60(sp)
    .word 0x5000B57F // sq s5, 0x50(sp)
    .word 0x4000B47F // sq s4, 0x40(sp)
    .word 0x3000B37F // sq s3, 0x30(sp)
    .word 0x2000B27F // sq s2, 0x20(sp)
    .word 0x1000B17F // sq s1, 0x10(sp)
    .word 0x0000B07F // sq s0, 0x0(sp)
    .word 0x28BE8070 // paddub s7, a0, zero
    .word 0x28B6A070 // paddub s6, a1, zero
    .word 0x28AEC070 // paddub s5, a2, zero
    .word 0x28F6E070 // paddub fp, a3, zero
    .word 0x28860070 // paddub s0, zero, zero
    .word 0x288E0070 // paddub s1, zero, zero
    .word 0x60000010 // b .L00145198
    .word 0x28960070 // paddub s2, zero, zero
  // .L0014501C:
    .word 0xBC00E28E // lw v0, 0xBC(s7)
    .word 0xFFFF4224 // addiu v0, v0, -0x1
    .word 0x2A085200 // slt at, v0, s2
    .word 0x03002010 // beqz at, .L00145038
    .word 0xAC00E48E // lw a0, 0xAC(s7)
    .word 0x04000010 // b .L00145044
    .word 0xB000E28E // lw v0, 0xB0(s7)
  // .L00145038:
    .word 0xB000E28E // lw v0, 0xB0(s7)
    .word 0x80181200 // sll v1, s2, 2
    .word 0x21104300 // addu v0, v0, v1
  // .L00145044:
    .word 0x0000458C // lw a1, 0x0(v0)
    .word 0x98CB0C0C // jal func_332e60
    .word 0x980B848C // lw a0, 0xB98(a0)
    .word 0x289E4070 // paddub s3, v0, zero
    .word 0x50006052 // beql s3, zero, .L00145198
    .word 0x01005226 // addiu s2, s2, 0x1
    .word 0x0000798E // lw t9, 0x0(s3)
    .word 0x6401398F // lw t9, 0x164(t9)
    .word 0x09F82003 // jalr t9
    .word 0x28266072 // paddub a0, s3, zero
    .word 0x49004010 // beqz v0, .L00145194
    .word 0x00000000 // nop
    .word 0x39006292 // lbu v0, 0x39(s3)
    .word 0x46004010 // beqz v0, .L00145194
    .word 0x00000000 // nop
    .word 0x38006392 // lbu v1, 0x38(s3)
    .word 0x50000224 // addiu v0, zero, 0x50
    .word 0x05006214 // bne v1, v0, .L001450A0
    .word 0x00000000 // nop
    .word 0x3001628E // lw v0, 0x130(s3)
    .word 0x02004010 // beqz v0, .L001450A0
    .word 0x00000000 // nop
    .word 0x289E4070 // paddub s3, v0, zero
  // .L001450A0:
    .word 0x0600C017 // bnez fp, .L001450BC
    .word 0x00000000 // nop
    .word 0x10000524 // addiu a1, zero, 0x10
    .word 0x48AB090C // jal func_26AD20
    .word 0x28266072 // paddub a0, s3, zero
    .word 0x37004014 // bnez v0, .L00145194
    .word 0x00000000 // nop
  // .L001450BC:
    .word 0x0400638E // lw v1, 0x4(s3)
    .word 0x0E006284 // lh v0, 0xE(v1)
    .word 0x33005614 // bne v0, s6, .L00145194
    .word 0x00000000 // nop
    .word 0x3E006284 // lh v0, 0x3E(v1)
    .word 0x300061C6 // lwc1 f1, 0x30(s3)
    .word 0x00008244 // mtc1 v0, f0
    .word 0x00000000 // nop
    .word 0x20008046 // cvt.s.w f0, f0
    .word 0x34080046 // c.lt.s f1, f0
    .word 0x00000000 // nop
    .word 0x2A000045 // bc1f .L00145194
    .word 0x00000000 // nop
    .word 0x0000798E // lw t9, 0x0(s3)
    .word 0x9C00398F // lw t9, 0x9C(t9)
    .word 0x09F82003 // jalr t9
    .word 0x28266072 // paddub a0, s3, zero
    .word 0x01000324 // addiu v1, zero, 0x1
    .word 0x23004314 // bne v0, v1, .L00145194
    .word 0x00000000 // nop
    .word 0xFFFF0224 // addiu v0, zero, -0x1
    .word 0x0500A212 // beq s5, v0, .L00145128
    .word 0x00000000 // nop
    .word 0x0400628E // lw v0, 0x4(s3)
    .word 0x08004284 // lh v0, 0x8(v0)
    .word 0x1C00A216 // bne s5, v0, .L00145194
    .word 0x00000000 // nop
  // .L00145128:
    .word 0x3B006292 // lbu v0, 0x3B(s3)
    .word 0x19004014 // bnez v0, .L00145194
    .word 0x00000000 // nop
    .word 0x0400628E // lw v0, 0x4(s3)
    .word 0x300060C6 // lwc1 f0, 0x30(s3)
    .word 0x3E005484 // lh s4, 0x3E(v0)
    .word 0x00089444 // mtc1 s4, f1
    .word 0x00000000 // nop
    .word 0x60088046 // cvt.s.w f1, f1
    .word 0xD48C040C // jal func_123350
    .word 0x010B0046 // sub.s f12, f1, f0
    .word 0x80200200 // sll a0, v0, 2
    .word 0x21208200 // addu a0, a0, v0
    .word 0x80100400 // sll v0, a0, 2
    .word 0x21108200 // addu v0, a0, v0
    .word 0x3C1C1400 // dsll32 v1, s4, 16
    .word 0x3F1C0300 // dsra32 v1, v1, 16
    .word 0x80100200 // sll v0, v0, 2
    .word 0x02006014 // bnez v1, .L0014517C
    .word 0x1A004300 // div zero, v0, v1
    .word 0xCD010000 // break 0, 7
  // .L0014517C:
    .word 0x12100000 // mflo v0
    .word 0x2A082202 // slt at, s1, v0
    .word 0x03002010 // beqz at, .L00145194
    .word 0x00000000 // nop
    .word 0x28866072 // paddub s0, s3, zero
    .word 0x288E4070 // paddub s1, v0, zero
  // .L00145194:
    .word 0x01005226 // addiu s2, s2, 0x1
  // .L00145198:
    .word 0xB400E28E // lw v0, 0xB4(s7)
    .word 0x2A104202 // slt v0, s2, v0
    .word 0x9EFF4014 // bnez v0, .L0014501C
    .word 0x00000000 // nop
    .word 0x28160072 // paddub v0, s0, zero
    .word 0x9000BF7B // lq ra, 0x90(sp)
    .word 0x8000BE7B // lq fp, 0x80(sp)
    .word 0x7000B77B // lq s7, 0x70(sp)
    .word 0x6000B67B // lq s6, 0x60(sp)
    .word 0x5000B57B // lq s5, 0x50(sp)
    .word 0x4000B47B // lq s4, 0x40(sp)
    .word 0x3000B37B // lq s3, 0x30(sp)
    .word 0x2000B27B // lq s2, 0x20(sp)
    .word 0x1000B17B // lq s1, 0x10(sp)
    .word 0x0000B07B // lq s0, 0x0(sp)
    .word 0x0800E003 // jr ra
    .word 0xA000BD27 // addiu sp, sp, 0xA0
    .set reorder
    .set at
}

asm void func_001451E0(void) {
    .set noreorder
    .set noat
    .word 0x0800E003 // jr ra
    .word 0x28160070 // paddub v0, zero, zero
    .set reorder
    .set at
}

asm void func_001451F0(void) {
    .set noreorder
    .set noat
    .word 0xE0FFBD27 // addiu sp, sp, -0x20
    .word 0x4D00023C // lui v0, (0x4D0000 >> 16)
    .word 0x1000BF7F // sq ra, 0x10(sp)
    .word 0x0000B07F // sq s0, 0x0(sp)
    .set reorder
    .set at
}

asm void *func_00145200(void *self, void *p1, void *p2) {
    .set noreorder
    .set noat
    .word 0x88784224 // addiu v0, v0, 0x7888
    .word 0x000082AC // sw v0, 0x0(a0)
    .word 0x28868070 // paddub s0, a0, zero
    .word 0x0600A010 // beqz a1, .L00145228
    .word 0x040086AC // sw a2, 0x4(a0)
    .word 0x08000426 // addiu a0, s0, 0x8
    .word 0x5C6C040C // jal func_0011B170
    .word 0x3F000624 // addiu a2, zero, 0x3F
    .word 0x06000010 // b .L0014523C
    .word 0x28160072 // paddub v0, s0, zero
  // .L00145228:
    .word 0x4900023C // lui v0, %hi(D_490FEC)
    .word 0x08000426 // addiu a0, s0, 0x8
    .word 0xEF6A040C // jal func_0011ABBC
    .word 0xEC0F4524 // addiu a1, v0, %lo(D_490FEC)
    .word 0x28160072 // paddub v0, s0, zero
  // .L0014523C:
    .word 0x1000BF7B // lq ra, 0x10(sp)
    .word 0x0000B07B // lq s0, 0x0(sp)
    .word 0x0800E003 // jr ra
    .word 0x2000BD27 // addiu sp, sp, 0x20
    .set reorder
    .set at
}

asm void func_00145250(void *self) {
    .set noreorder
    .set noat
    .word 0xE0FFBD27 // addiu sp, sp, -0x20
    .word 0x1000BF7F // sq ra, 0x10(sp)
    .word 0x0000B07F // sq s0, 0x0(sp)
    .word 0x28868070 // paddub s0, a0, zero
    .set reorder
    .set at
}

}
