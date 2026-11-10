#pragma exceptions off

#include "zone_spatial_pyramid_search_hierarchical.h"

extern "C" {
void *func_117CAC(void *dst, int val, int size);
void *func_2E6CD0(void *p);
void *func_2E6D40(void *p);
void *func_1D4330(void *self, int x, int y, int level, float g_score, float h_score, void *parent, int dir, void *t2, void *t3);
void func_001D42A0(void *self, void *list_head, void *node, int flag);
}

#if defined(__mips__)

extern "C" asm void func_001D6F10(void *self) {
    .word 0x27BDFF20 /* 001D6F10: addiu sp, sp, -0xe0 */
    .word 0x7FBF00A0 /* 001D6F14: sq ra, 0xa0(sp) */
    .word 0x7FBE0090 /* 001D6F18: sq s8, 0x90(sp) */
    .word 0x7FB70080 /* 001D6F1C: sq s7, 0x80(sp) */
    .word 0x7FB60070 /* 001D6F20: sq s6, 0x70(sp) */
    .word 0x7FB50060 /* 001D6F24: sq s5, 0x60(sp) */
    .word 0x7FB40050 /* 001D6F28: sq s4, 0x50(sp) */
    .word 0x7FB30040 /* 001D6F2C: sq s3, 0x40(sp) */
    .word 0x7FB20030 /* 001D6F30: sq s2, 0x30(sp) */
    .word 0x7FB10020 /* 001D6F34: sq s1, 0x20(sp) */
    .word 0x7FB00010 /* 001D6F38: sq s0, 0x10(sp) */
    .word 0xE7B40000 /* 001D6F3C: swc1 fs0, 0x0(sp) */
    .word 0x7080B628 /* 001D6F40: paddub s6, a0, zero */
    .word 0x10000009 /* 001D6F44: b 0x5c */
    .word 0x70008628 /* 001D6F48: paddub s0, zero, zero */
    .word 0x8EC2011C /* 001D6F4C: lw v0, 0x11c(s6) */
    .word 0x00101880 /* 001D6F50: sll v1, s0, 2 */
    .word 0x8EC600E8 /* 001D6F54: lw a2, 0xe8(s6) */
    .word 0x00431021 /* 001D6F58: addu v0, v0, v1 */
    .word 0x8C440000 /* 001D6F5C: lw a0, 0x0(v0) */
    jal        func_117CAC /* 001D6F60: jal        func_117CAC */
    .word 0x70002E28 /* 001D6F64: paddub a1, zero, zero */
    .word 0x26100001 /* 001D6F68: addiu s0, s0, 0x1 */
    .word 0x8EC300E4 /* 001D6F6C: lw v1, 0xe4(s6) */
    .word 0x0203182A /* 001D6F70: slt v1, s0, v1 */
    .word 0x1460FFF5 /* 001D6F74: bnez v1, 0x3c */
    .word 0x00000000 /* 001D6F78: nop  */
    .word 0x24030001 /* 001D6F7C: addiu v1, zero, 0x1 */
    .word 0x10000299 /* 001D6F80: b 0xad8 */
    .word 0xAFA300B0 /* 001D6F84: sw v1, 0xb0(sp) */
    .word 0x8FA200B0 /* 001D6F88: lw v0, 0xb0(sp) */
    .word 0x8CA30054 /* 001D6F8C: lw v1, 0x54(a1) */
    .word 0x2444FFFF /* 001D6F90: addiu a0, v0, -0x1 */
    .word 0x24020001 /* 001D6F94: addiu v0, zero, 0x1 */
    .word 0x00821004 /* 001D6F98: sllv v0, v0, a0 */
    .word 0x305200FF /* 001D6F9C: andi s2, v0, 0xff */
    .word 0x8FA200B0 /* 001D6FA0: lw v0, 0xb0(sp) */
    .word 0x00028080 /* 001D6FA4: sll s0, v0, 2 */
    .word 0x00701021 /* 001D6FA8: addu v0, v1, s0 */
    jal        func_2E6CD0 /* 001D6FAC: jal        func_2E6CD0 */
    .word 0x8C440000 /* 001D6FB0: lw a0, 0x0(v0) */
    .word 0x70408E28 /* 001D6FB4: paddub s1, v0, zero */
    .word 0x8EC20094 /* 001D6FB8: lw v0, 0x94(s6) */
    .word 0x8C420054 /* 001D6FBC: lw v0, 0x54(v0) */
    .word 0x00501021 /* 001D6FC0: addu v0, v0, s0 */
    jal        func_2E6D40 /* 001D6FC4: jal        func_2E6D40 */
    .word 0x8C440000 /* 001D6FC8: lw a0, 0x0(v0) */
    .word 0x44806000 /* 001D6FCC: mtc1 zero, fa0 */
    .word 0x70408628 /* 001D6FD0: paddub s0, v0, zero */
    .word 0x72C02628 /* 001D6FD4: paddub a0, s6, zero */
    .word 0x46006346 /* 001D6FD8: mov.s fa1, fa0 */
    .word 0x72202E28 /* 001D6FDC: paddub a1, s1, zero */
    .word 0x72003628 /* 001D6FE0: paddub a2, s0, zero */
    .word 0x70003E28 /* 001D6FE4: paddub a3, zero, zero */
    .word 0x70004628 /* 001D6FE8: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D6FEC: paddub a5, zero, zero */
    .word 0x70005628 /* 001D6FF0: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D6FF4: jal        func_1D4330 */
    .word 0x70005E28 /* 001D6FF8: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D6FFC: addiu a1, s6, 0x8 */
    .word 0x72C02628 /* 001D7000: paddub a0, s6, zero */
    .word 0x70403628 /* 001D7004: paddub a2, v0, zero */
    jal        func_001D42A0 /* 001D7008: jal        func_001D42A0 */
    .word 0x70003E28 /* 001D700C: paddub a3, zero, zero */
    .word 0x8EC3011C /* 001D7010: lw v1, 0x11c(s6) */
    .word 0x00112080 /* 001D7014: sll a0, s1, 2 */
    .word 0x00641821 /* 001D7018: addu v1, v1, a0 */
    .word 0x8C630000 /* 001D701C: lw v1, 0x0(v1) */
    .word 0x00702021 /* 001D7020: addu a0, v1, s0 */
    .word 0x90830000 /* 001D7024: lbu v1, 0x0(a0) */
    .word 0x00721821 /* 001D7028: addu v1, v1, s2 */
    .word 0xA0830000 /* 001D702C: sb v1, 0x0(a0) */
    .word 0x8EC60028 /* 001D7030: lw a2, 0x28(s6) */
    .word 0x10000266 /* 001D7034: b 0xac0 */
    .word 0x325300FF /* 001D7038: andi s3, s2, 0xff */
    .word 0x8CC20000 /* 001D703C: lw v0, 0x0(a2) */
    .word 0x8CD40004 /* 001D7040: lw s4, 0x4(a2) */
    .word 0x8CD50008 /* 001D7044: lw s5, 0x8(a2) */
    .word 0x8C630020 /* 001D7048: lw v1, 0x20(v1) */
    .word 0xC4D40018 /* 001D704C: lwc1 fs0, 0x18(a2) */
    .word 0x26C50060 /* 001D7050: addiu a1, s6, 0x60 */
    .word 0x90420000 /* 001D7054: lbu v0, 0x0(v0) */
    .word 0x24070001 /* 001D7058: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D705C: paddub a0, s6, zero */
    .word 0x269EFFFF /* 001D7060: addiu s8, s4, -0x1 */
    .word 0xA3A200C0 /* 001D7064: sb v0, 0xc0(sp) */
    .word 0x26970001 /* 001D7068: addiu s7, s4, 0x1 */
    .word 0x26B0FFFF /* 001D706C: addiu s0, s5, -0x1 */
    .word 0x26B10001 /* 001D7070: addiu s1, s5, 0x1 */
    jal        func_001D42A0 /* 001D7074: jal        func_001D42A0 */
    .word 0xAEC30028 /* 001D7078: sw v1, 0x28(s6) */
    .word 0x93A300C0 /* 001D707C: lbu v1, 0xc0(sp) */
    .word 0x70601E28 /* 001D7080: paddub v1, v1, zero */
    .word 0xAFA300D0 /* 001D7084: sw v1, 0xd0(sp) */
    .word 0x8FA300D0 /* 001D7088: lw v1, 0xd0(sp) */
    .word 0x14600005 /* 001D708C: bnez v1, 0x194 */
    .word 0x00000000 /* 001D7090: nop  */
    .word 0x3C033F80 /* 001D7094: lui v1, 0x3f80 */
    .word 0x44830000 /* 001D7098: mtc1 v1, fv0 */
    .word 0x00000000 /* 001D709C: nop  */
    .word 0x4600A500 /* 001D70A0: add.s fs0, fs0, fv0 */
    .word 0x44800000 /* 001D70A4: mtc1 zero, fv0 */
    .word 0x00000000 /* 001D70A8: nop  */
    .word 0x4600A036 /* 001D70AC: c.le.s fs0, fv0 */
    .word 0x00000000 /* 001D70B0: nop  */
    .word 0x45010150 /* 001D70B4: bc1t 0x6e8 */
    .word 0x00000000 /* 001D70B8: nop  */
    .word 0x3C034040 /* 001D70BC: lui v1, 0x4040 */
    .word 0x44830000 /* 001D70C0: mtc1 v1, fv0 */
    .word 0x00000000 /* 001D70C4: nop  */
    .word 0x4600A034 /* 001D70C8: c.lt.s fs0, fv0 */
    .word 0x00000000 /* 001D70CC: nop  */
    .word 0x45000149 /* 001D70D0: bc1f 0x6e8 */
    .word 0x00000000 /* 001D70D4: nop  */
    .word 0x8FA300D0 /* 001D70D8: lw v1, 0xd0(sp) */
    .word 0x10600008 /* 001D70DC: beqz v1, 0x1f0 */
    .word 0x00000000 /* 001D70E0: nop  */
    .word 0x3C033F80 /* 001D70E4: lui v1, 0x3f80 */
    .word 0x44830000 /* 001D70E8: mtc1 v1, fv0 */
    .word 0x00000000 /* 001D70EC: nop  */
    .word 0x46140032 /* 001D70F0: c.eq.s fv0, fs0 */
    .word 0x00000000 /* 001D70F4: nop  */
    .word 0x45000233 /* 001D70F8: bc1f 0xab8 */
    .word 0x00000000 /* 001D70FC: nop  */
    .word 0x07C00024 /* 001D7100: bltz s8, 0x284 */
    .word 0x00000000 /* 001D7104: nop  */
    .word 0x8EC3011C /* 001D7108: lw v1, 0x11c(s6) */
    .word 0x001E2880 /* 001D710C: sll a1, s8, 2 */
    .word 0x00651821 /* 001D7110: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D7114: lw v1, 0x0(v1) */
    .word 0x00753021 /* 001D7118: addu a2, v1, s5 */
    .word 0x90C40000 /* 001D711C: lbu a0, 0x0(a2) */
    .word 0x02641824 /* 001D7120: and v1, s3, a0 */
    .word 0x1460001B /* 001D7124: bnez v1, 0x284 */
    .word 0x00000000 /* 001D7128: nop  */
    .word 0x8EC30120 /* 001D712C: lw v1, 0x120(s6) */
    .word 0x00651821 /* 001D7130: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D7134: lw v1, 0x0(v1) */
    .word 0x00751821 /* 001D7138: addu v1, v1, s5 */
    .word 0x90630000 /* 001D713C: lbu v1, 0x0(v1) */
    .word 0x02631824 /* 001D7140: and v1, s3, v1 */
    .word 0x16630013 /* 001D7144: bne s3, v1, 0x284 */
    .word 0x00000000 /* 001D7148: nop  */
    .word 0x00921021 /* 001D714C: addu v0, a0, s2 */
    .word 0x44806800 /* 001D7150: mtc1 zero, fa1 */
    .word 0xA0C20000 /* 001D7154: sb v0, 0x0(a2) */
    .word 0x72C02628 /* 001D7158: paddub a0, s6, zero */
    .word 0x73C02E28 /* 001D715C: paddub a1, s8, zero */
    .word 0x72A03628 /* 001D7160: paddub a2, s5, zero */
    .word 0x70003E28 /* 001D7164: paddub a3, zero, zero */
    .word 0x4600A306 /* 001D7168: mov.s fa0, fs0 */
    .word 0x70004628 /* 001D716C: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D7170: paddub a5, zero, zero */
    .word 0x70005628 /* 001D7174: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D7178: jal        func_1D4330 */
    .word 0x70005E28 /* 001D717C: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D7180: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D7184: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D7188: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D718C: jal        func_001D42A0 */
    .word 0x70403628 /* 001D7190: paddub a2, v0, zero */
    .word 0x8EC300E4 /* 001D7194: lw v1, 0xe4(s6) */
    .word 0x02E3082A /* 001D7198: slt at, s7, v1 */
    .word 0x10200024 /* 001D719C: beqz at, 0x320 */
    .word 0x00000000 /* 001D71A0: nop  */
    .word 0x8EC3011C /* 001D71A4: lw v1, 0x11c(s6) */
    .word 0x00172880 /* 001D71A8: sll a1, s7, 2 */
    .word 0x00651821 /* 001D71AC: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D71B0: lw v1, 0x0(v1) */
    .word 0x00753021 /* 001D71B4: addu a2, v1, s5 */
    .word 0x90C40000 /* 001D71B8: lbu a0, 0x0(a2) */
    .word 0x02641824 /* 001D71BC: and v1, s3, a0 */
    .word 0x1460001B /* 001D71C0: bnez v1, 0x320 */
    .word 0x00000000 /* 001D71C4: nop  */
    .word 0x8EC30120 /* 001D71C8: lw v1, 0x120(s6) */
    .word 0x00651821 /* 001D71CC: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D71D0: lw v1, 0x0(v1) */
    .word 0x00751821 /* 001D71D4: addu v1, v1, s5 */
    .word 0x90630000 /* 001D71D8: lbu v1, 0x0(v1) */
    .word 0x02631824 /* 001D71DC: and v1, s3, v1 */
    .word 0x16630013 /* 001D71E0: bne s3, v1, 0x320 */
    .word 0x00000000 /* 001D71E4: nop  */
    .word 0x00921021 /* 001D71E8: addu v0, a0, s2 */
    .word 0x44806800 /* 001D71EC: mtc1 zero, fa1 */
    .word 0xA0C20000 /* 001D71F0: sb v0, 0x0(a2) */
    .word 0x72A03628 /* 001D71F4: paddub a2, s5, zero */
    .word 0x72C02628 /* 001D71F8: paddub a0, s6, zero */
    .word 0x72E02E28 /* 001D71FC: paddub a1, s7, zero */
    .word 0x70003E28 /* 001D7200: paddub a3, zero, zero */
    .word 0x4600A306 /* 001D7204: mov.s fa0, fs0 */
    .word 0x70004628 /* 001D7208: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D720C: paddub a5, zero, zero */
    .word 0x70005628 /* 001D7210: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D7214: jal        func_1D4330 */
    .word 0x70005E28 /* 001D7218: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D721C: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D7220: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D7224: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D7228: jal        func_001D42A0 */
    .word 0x70403628 /* 001D722C: paddub a2, v0, zero */
    .word 0x06000024 /* 001D7230: bltz s0, 0x3b4 */
    .word 0x00000000 /* 001D7234: nop  */
    .word 0x8EC3011C /* 001D7238: lw v1, 0x11c(s6) */
    .word 0x00142880 /* 001D723C: sll a1, s4, 2 */
    .word 0x00651821 /* 001D7240: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D7244: lw v1, 0x0(v1) */
    .word 0x00703021 /* 001D7248: addu a2, v1, s0 */
    .word 0x90C40000 /* 001D724C: lbu a0, 0x0(a2) */
    .word 0x02641824 /* 001D7250: and v1, s3, a0 */
    .word 0x1460001B /* 001D7254: bnez v1, 0x3b4 */
    .word 0x00000000 /* 001D7258: nop  */
    .word 0x8EC30120 /* 001D725C: lw v1, 0x120(s6) */
    .word 0x00651821 /* 001D7260: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D7264: lw v1, 0x0(v1) */
    .word 0x00701821 /* 001D7268: addu v1, v1, s0 */
    .word 0x90630000 /* 001D726C: lbu v1, 0x0(v1) */
    .word 0x02631824 /* 001D7270: and v1, s3, v1 */
    .word 0x16630013 /* 001D7274: bne s3, v1, 0x3b4 */
    .word 0x00000000 /* 001D7278: nop  */
    .word 0x00921021 /* 001D727C: addu v0, a0, s2 */
    .word 0x44806800 /* 001D7280: mtc1 zero, fa1 */
    .word 0xA0C20000 /* 001D7284: sb v0, 0x0(a2) */
    .word 0x72C02628 /* 001D7288: paddub a0, s6, zero */
    .word 0x72802E28 /* 001D728C: paddub a1, s4, zero */
    .word 0x72003628 /* 001D7290: paddub a2, s0, zero */
    .word 0x70003E28 /* 001D7294: paddub a3, zero, zero */
    .word 0x4600A306 /* 001D7298: mov.s fa0, fs0 */
    .word 0x70004628 /* 001D729C: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D72A0: paddub a5, zero, zero */
    .word 0x70005628 /* 001D72A4: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D72A8: jal        func_1D4330 */
    .word 0x70005E28 /* 001D72AC: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D72B0: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D72B4: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D72B8: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D72BC: jal        func_001D42A0 */
    .word 0x70403628 /* 001D72C0: paddub a2, v0, zero */
    .word 0x8EC300E8 /* 001D72C4: lw v1, 0xe8(s6) */
    .word 0x0223082A /* 001D72C8: slt at, s1, v1 */
    .word 0x10200024 /* 001D72CC: beqz at, 0x450 */
    .word 0x00000000 /* 001D72D0: nop  */
    .word 0x8EC3011C /* 001D72D4: lw v1, 0x11c(s6) */
    .word 0x00142880 /* 001D72D8: sll a1, s4, 2 */
    .word 0x00651821 /* 001D72DC: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D72E0: lw v1, 0x0(v1) */
    .word 0x00713021 /* 001D72E4: addu a2, v1, s1 */
    .word 0x90C40000 /* 001D72E8: lbu a0, 0x0(a2) */
    .word 0x02641824 /* 001D72EC: and v1, s3, a0 */
    .word 0x1460001B /* 001D72F0: bnez v1, 0x450 */
    .word 0x00000000 /* 001D72F4: nop  */
    .word 0x8EC30120 /* 001D72F8: lw v1, 0x120(s6) */
    .word 0x00651821 /* 001D72FC: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D7300: lw v1, 0x0(v1) */
    .word 0x00711821 /* 001D7304: addu v1, v1, s1 */
    .word 0x90630000 /* 001D7308: lbu v1, 0x0(v1) */
    .word 0x02631824 /* 001D730C: and v1, s3, v1 */
    .word 0x16630013 /* 001D7310: bne s3, v1, 0x450 */
    .word 0x00000000 /* 001D7314: nop  */
    .word 0x00921021 /* 001D7318: addu v0, a0, s2 */
    .word 0x44806800 /* 001D731C: mtc1 zero, fa1 */
    .word 0xA0C20000 /* 001D7320: sb v0, 0x0(a2) */
    .word 0x72802E28 /* 001D7324: paddub a1, s4, zero */
    .word 0x72C02628 /* 001D7328: paddub a0, s6, zero */
    .word 0x72203628 /* 001D732C: paddub a2, s1, zero */
    .word 0x70003E28 /* 001D7330: paddub a3, zero, zero */
    .word 0x4600A306 /* 001D7334: mov.s fa0, fs0 */
    .word 0x70004628 /* 001D7338: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D733C: paddub a5, zero, zero */
    .word 0x70005628 /* 001D7340: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D7344: jal        func_1D4330 */
    .word 0x70005E28 /* 001D7348: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D734C: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D7350: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D7354: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D7358: jal        func_001D42A0 */
    .word 0x70403628 /* 001D735C: paddub a2, v0, zero */
    .word 0x06000026 /* 001D7360: bltz s0, 0x4ec */
    .word 0x00000000 /* 001D7364: nop  */
    .word 0x07C00024 /* 001D7368: bltz s8, 0x4ec */
    .word 0x00000000 /* 001D736C: nop  */
    .word 0x8EC3011C /* 001D7370: lw v1, 0x11c(s6) */
    .word 0x001E2880 /* 001D7374: sll a1, s8, 2 */
    .word 0x00651821 /* 001D7378: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D737C: lw v1, 0x0(v1) */
    .word 0x00703021 /* 001D7380: addu a2, v1, s0 */
    .word 0x90C40000 /* 001D7384: lbu a0, 0x0(a2) */
    .word 0x02641824 /* 001D7388: and v1, s3, a0 */
    .word 0x1460001B /* 001D738C: bnez v1, 0x4ec */
    .word 0x00000000 /* 001D7390: nop  */
    .word 0x8EC30120 /* 001D7394: lw v1, 0x120(s6) */
    .word 0x00651821 /* 001D7398: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D739C: lw v1, 0x0(v1) */
    .word 0x00701821 /* 001D73A0: addu v1, v1, s0 */
    .word 0x90630000 /* 001D73A4: lbu v1, 0x0(v1) */
    .word 0x02631824 /* 001D73A8: and v1, s3, v1 */
    .word 0x16630013 /* 001D73AC: bne s3, v1, 0x4ec */
    .word 0x00000000 /* 001D73B0: nop  */
    .word 0x00921021 /* 001D73B4: addu v0, a0, s2 */
    .word 0x44806800 /* 001D73B8: mtc1 zero, fa1 */
    .word 0xA0C20000 /* 001D73BC: sb v0, 0x0(a2) */
    .word 0x72C02628 /* 001D73C0: paddub a0, s6, zero */
    .word 0x73C02E28 /* 001D73C4: paddub a1, s8, zero */
    .word 0x72003628 /* 001D73C8: paddub a2, s0, zero */
    .word 0x70003E28 /* 001D73CC: paddub a3, zero, zero */
    .word 0x4600A306 /* 001D73D0: mov.s fa0, fs0 */
    .word 0x70004628 /* 001D73D4: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D73D8: paddub a5, zero, zero */
    .word 0x70005628 /* 001D73DC: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D73E0: jal        func_1D4330 */
    .word 0x70005E28 /* 001D73E4: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D73E8: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D73EC: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D73F0: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D73F4: jal        func_001D42A0 */
    .word 0x70403628 /* 001D73F8: paddub a2, v0, zero */
    .word 0x8EC300E8 /* 001D73FC: lw v1, 0xe8(s6) */
    .word 0x0223082A /* 001D7400: slt at, s1, v1 */
    .word 0x10200026 /* 001D7404: beqz at, 0x590 */
    .word 0x00000000 /* 001D7408: nop  */
    .word 0x07C00024 /* 001D740C: bltz s8, 0x590 */
    .word 0x00000000 /* 001D7410: nop  */
    .word 0x8EC3011C /* 001D7414: lw v1, 0x11c(s6) */
    .word 0x001E2880 /* 001D7418: sll a1, s8, 2 */
    .word 0x00651821 /* 001D741C: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D7420: lw v1, 0x0(v1) */
    .word 0x00713021 /* 001D7424: addu a2, v1, s1 */
    .word 0x90C40000 /* 001D7428: lbu a0, 0x0(a2) */
    .word 0x02641824 /* 001D742C: and v1, s3, a0 */
    .word 0x1460001B /* 001D7430: bnez v1, 0x590 */
    .word 0x00000000 /* 001D7434: nop  */
    .word 0x8EC30120 /* 001D7438: lw v1, 0x120(s6) */
    .word 0x00651821 /* 001D743C: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D7440: lw v1, 0x0(v1) */
    .word 0x00711821 /* 001D7444: addu v1, v1, s1 */
    .word 0x90630000 /* 001D7448: lbu v1, 0x0(v1) */
    .word 0x02631824 /* 001D744C: and v1, s3, v1 */
    .word 0x16630013 /* 001D7450: bne s3, v1, 0x590 */
    .word 0x00000000 /* 001D7454: nop  */
    .word 0x00921021 /* 001D7458: addu v0, a0, s2 */
    .word 0x44806800 /* 001D745C: mtc1 zero, fa1 */
    .word 0xA0C20000 /* 001D7460: sb v0, 0x0(a2) */
    .word 0x73C02E28 /* 001D7464: paddub a1, s8, zero */
    .word 0x72C02628 /* 001D7468: paddub a0, s6, zero */
    .word 0x72203628 /* 001D746C: paddub a2, s1, zero */
    .word 0x70003E28 /* 001D7470: paddub a3, zero, zero */
    .word 0x4600A306 /* 001D7474: mov.s fa0, fs0 */
    .word 0x70004628 /* 001D7478: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D747C: paddub a5, zero, zero */
    .word 0x70005628 /* 001D7480: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D7484: jal        func_1D4330 */
    .word 0x70005E28 /* 001D7488: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D748C: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D7490: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D7494: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D7498: jal        func_001D42A0 */
    .word 0x70403628 /* 001D749C: paddub a2, v0, zero */
    .word 0x06000028 /* 001D74A0: bltz s0, 0x634 */
    .word 0x00000000 /* 001D74A4: nop  */
    .word 0x8EC300E4 /* 001D74A8: lw v1, 0xe4(s6) */
    .word 0x02E3082A /* 001D74AC: slt at, s7, v1 */
    .word 0x10200024 /* 001D74B0: beqz at, 0x634 */
    .word 0x00000000 /* 001D74B4: nop  */
    .word 0x8EC3011C /* 001D74B8: lw v1, 0x11c(s6) */
    .word 0x00172880 /* 001D74BC: sll a1, s7, 2 */
    .word 0x00651821 /* 001D74C0: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D74C4: lw v1, 0x0(v1) */
    .word 0x00703021 /* 001D74C8: addu a2, v1, s0 */
    .word 0x90C40000 /* 001D74CC: lbu a0, 0x0(a2) */
    .word 0x02641824 /* 001D74D0: and v1, s3, a0 */
    .word 0x1460001B /* 001D74D4: bnez v1, 0x634 */
    .word 0x00000000 /* 001D74D8: nop  */
    .word 0x8EC30120 /* 001D74DC: lw v1, 0x120(s6) */
    .word 0x00651821 /* 001D74E0: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D74E4: lw v1, 0x0(v1) */
    .word 0x00701821 /* 001D74E8: addu v1, v1, s0 */
    .word 0x90630000 /* 001D74EC: lbu v1, 0x0(v1) */
    .word 0x02631824 /* 001D74F0: and v1, s3, v1 */
    .word 0x16630013 /* 001D74F4: bne s3, v1, 0x634 */
    .word 0x00000000 /* 001D74F8: nop  */
    .word 0x00921021 /* 001D74FC: addu v0, a0, s2 */
    .word 0x44806800 /* 001D7500: mtc1 zero, fa1 */
    .word 0xA0C20000 /* 001D7504: sb v0, 0x0(a2) */
    .word 0x72003628 /* 001D7508: paddub a2, s0, zero */
    .word 0x72C02628 /* 001D750C: paddub a0, s6, zero */
    .word 0x72E02E28 /* 001D7510: paddub a1, s7, zero */
    .word 0x70003E28 /* 001D7514: paddub a3, zero, zero */
    .word 0x4600A306 /* 001D7518: mov.s fa0, fs0 */
    .word 0x70004628 /* 001D751C: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D7520: paddub a5, zero, zero */
    .word 0x70005628 /* 001D7524: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D7528: jal        func_1D4330 */
    .word 0x70005E28 /* 001D752C: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D7530: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D7534: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D7538: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D753C: jal        func_001D42A0 */
    .word 0x70403628 /* 001D7540: paddub a2, v0, zero */
    .word 0x8EC300E8 /* 001D7544: lw v1, 0xe8(s6) */
    .word 0x0223082A /* 001D7548: slt at, s1, v1 */
    .word 0x1020011E /* 001D754C: beqz at, 0xab8 */
    .word 0x00000000 /* 001D7550: nop  */
    .word 0x8EC300E4 /* 001D7554: lw v1, 0xe4(s6) */
    .word 0x02E3082A /* 001D7558: slt at, s7, v1 */
    .word 0x1020011A /* 001D755C: beqz at, 0xab8 */
    .word 0x00000000 /* 001D7560: nop  */
    .word 0x8EC3011C /* 001D7564: lw v1, 0x11c(s6) */
    .word 0x00172880 /* 001D7568: sll a1, s7, 2 */
    .word 0x00651821 /* 001D756C: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D7570: lw v1, 0x0(v1) */
    .word 0x00713021 /* 001D7574: addu a2, v1, s1 */
    .word 0x90C40000 /* 001D7578: lbu a0, 0x0(a2) */
    .word 0x02641824 /* 001D757C: and v1, s3, a0 */
    .word 0x14600111 /* 001D7580: bnez v1, 0xab8 */
    .word 0x00000000 /* 001D7584: nop  */
    .word 0x8EC30120 /* 001D7588: lw v1, 0x120(s6) */
    .word 0x00651821 /* 001D758C: addu v1, v1, a1 */
    .word 0x8C630000 /* 001D7590: lw v1, 0x0(v1) */
    .word 0x00711821 /* 001D7594: addu v1, v1, s1 */
    .word 0x90630000 /* 001D7598: lbu v1, 0x0(v1) */
    .word 0x02631824 /* 001D759C: and v1, s3, v1 */
    .word 0x16630109 /* 001D75A0: bne s3, v1, 0xab8 */
    .word 0x00000000 /* 001D75A4: nop  */
    .word 0x00921021 /* 001D75A8: addu v0, a0, s2 */
    .word 0x44806800 /* 001D75AC: mtc1 zero, fa1 */
    .word 0xA0C20000 /* 001D75B0: sb v0, 0x0(a2) */
    .word 0x72E02E28 /* 001D75B4: paddub a1, s7, zero */
    .word 0x72203628 /* 001D75B8: paddub a2, s1, zero */
    .word 0x4600A306 /* 001D75BC: mov.s fa0, fs0 */
    .word 0x72C02628 /* 001D75C0: paddub a0, s6, zero */
    .word 0x70003E28 /* 001D75C4: paddub a3, zero, zero */
    .word 0x70004628 /* 001D75C8: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D75CC: paddub a5, zero, zero */
    .word 0x70005628 /* 001D75D0: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D75D4: jal        func_1D4330 */
    .word 0x70005E28 /* 001D75D8: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D75DC: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D75E0: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D75E4: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D75E8: jal        func_001D42A0 */
    .word 0x70403628 /* 001D75EC: paddub a2, v0, zero */
    .word 0x100000F6 /* 001D75F0: b 0xabc */
    .word 0x8EC60028 /* 001D75F4: lw a2, 0x28(s6) */
    .word 0x1A80003B /* 001D75F8: blez s4, 0x7d8 */
    .word 0x00000000 /* 001D75FC: nop  */
    .word 0x8EC3011C /* 001D7600: lw v1, 0x11c(s6) */
    .word 0x001E3080 /* 001D7604: sll a2, s8, 2 */
    .word 0x00661821 /* 001D7608: addu v1, v1, a2 */
    .word 0x8C630000 /* 001D760C: lw v1, 0x0(v1) */
    .word 0x00752821 /* 001D7610: addu a1, v1, s5 */
    .word 0x90A40000 /* 001D7614: lbu a0, 0x0(a1) */
    .word 0x02641824 /* 001D7618: and v1, s3, a0 */
    .word 0x14600032 /* 001D761C: bnez v1, 0x7d8 */
    .word 0x00000000 /* 001D7620: nop  */
    .word 0x8FA300D0 /* 001D7624: lw v1, 0xd0(sp) */
    .word 0x30630002 /* 001D7628: andi v1, v1, 0x2 */
    .word 0x1060002E /* 001D762C: beqz v1, 0x7d8 */
    .word 0x00000000 /* 001D7630: nop  */
    .word 0x00921021 /* 001D7634: addu v0, a0, s2 */
    .word 0xA0A20000 /* 001D7638: sb v0, 0x0(a1) */
    .word 0x8EC20120 /* 001D763C: lw v0, 0x120(s6) */
    .word 0x00461021 /* 001D7640: addu v0, v0, a2 */
    .word 0x8C420000 /* 001D7644: lw v0, 0x0(v0) */
    .word 0x00551021 /* 001D7648: addu v0, v0, s5 */
    .word 0x90420000 /* 001D764C: lbu v0, 0x0(v0) */
    .word 0x02621024 /* 001D7650: and v0, s3, v0 */
    .word 0x14400014 /* 001D7654: bnez v0, 0x798 */
    .word 0x3C023F80 /* 001D7658: lui v0, 0x3f80 */
    .word 0x44806000 /* 001D765C: mtc1 zero, fa0 */
    .word 0x73C02E28 /* 001D7660: paddub a1, s8, zero */
    .word 0x72C02628 /* 001D7664: paddub a0, s6, zero */
    .word 0x46006346 /* 001D7668: mov.s fa1, fa0 */
    .word 0x72A03628 /* 001D766C: paddub a2, s5, zero */
    .word 0x70003E28 /* 001D7670: paddub a3, zero, zero */
    .word 0x70004628 /* 001D7674: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D7678: paddub a5, zero, zero */
    .word 0x70005628 /* 001D767C: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D7680: jal        func_1D4330 */
    .word 0x70005E28 /* 001D7684: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D7688: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D768C: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D7690: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D7694: jal        func_001D42A0 */
    .word 0x70403628 /* 001D7698: paddub a2, v0, zero */
    .word 0x10000013 /* 001D769C: b 0x7dc */
    .word 0x8EC300EC /* 001D76A0: lw v1, 0xec(s6) */
    .word 0x3C023F80 /* 001D76A4: lui v0, 0x3f80 */
    .word 0x44826000 /* 001D76A8: mtc1 v0, fa0 */
    .word 0x44806800 /* 001D76AC: mtc1 zero, fa1 */
    .word 0x73C02E28 /* 001D76B0: paddub a1, s8, zero */
    .word 0x72C02628 /* 001D76B4: paddub a0, s6, zero */
    .word 0x72A03628 /* 001D76B8: paddub a2, s5, zero */
    .word 0x70003E28 /* 001D76BC: paddub a3, zero, zero */
    .word 0x70004628 /* 001D76C0: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D76C4: paddub a5, zero, zero */
    .word 0x70005628 /* 001D76C8: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D76CC: jal        func_1D4330 */
    .word 0x70005E28 /* 001D76D0: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D76D4: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D76D8: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D76DC: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D76E0: jal        func_001D42A0 */
    .word 0x70403628 /* 001D76E4: paddub a2, v0, zero */
    .word 0x8EC300EC /* 001D76E8: lw v1, 0xec(s6) */
    .word 0x0283082A /* 001D76EC: slt at, s4, v1 */
    .word 0x1020003B /* 001D76F0: beqz at, 0x8d0 */
    .word 0x00000000 /* 001D76F4: nop  */
    .word 0x8EC3011C /* 001D76F8: lw v1, 0x11c(s6) */
    .word 0x00173080 /* 001D76FC: sll a2, s7, 2 */
    .word 0x00661821 /* 001D7700: addu v1, v1, a2 */
    .word 0x8C630000 /* 001D7704: lw v1, 0x0(v1) */
    .word 0x00752821 /* 001D7708: addu a1, v1, s5 */
    .word 0x90A40000 /* 001D770C: lbu a0, 0x0(a1) */
    .word 0x02641824 /* 001D7710: and v1, s3, a0 */
    .word 0x14600032 /* 001D7714: bnez v1, 0x8d0 */
    .word 0x00000000 /* 001D7718: nop  */
    .word 0x8FA300D0 /* 001D771C: lw v1, 0xd0(sp) */
    .word 0x30630004 /* 001D7720: andi v1, v1, 0x4 */
    .word 0x1060002E /* 001D7724: beqz v1, 0x8d0 */
    .word 0x00000000 /* 001D7728: nop  */
    .word 0x00921021 /* 001D772C: addu v0, a0, s2 */
    .word 0xA0A20000 /* 001D7730: sb v0, 0x0(a1) */
    .word 0x8EC20120 /* 001D7734: lw v0, 0x120(s6) */
    .word 0x00461021 /* 001D7738: addu v0, v0, a2 */
    .word 0x8C420000 /* 001D773C: lw v0, 0x0(v0) */
    .word 0x00551021 /* 001D7740: addu v0, v0, s5 */
    .word 0x90420000 /* 001D7744: lbu v0, 0x0(v0) */
    .word 0x02621024 /* 001D7748: and v0, s3, v0 */
    .word 0x14400014 /* 001D774C: bnez v0, 0x890 */
    .word 0x3C023F80 /* 001D7750: lui v0, 0x3f80 */
    .word 0x44806000 /* 001D7754: mtc1 zero, fa0 */
    .word 0x72E02E28 /* 001D7758: paddub a1, s7, zero */
    .word 0x72C02628 /* 001D775C: paddub a0, s6, zero */
    .word 0x46006346 /* 001D7760: mov.s fa1, fa0 */
    .word 0x72A03628 /* 001D7764: paddub a2, s5, zero */
    .word 0x70003E28 /* 001D7768: paddub a3, zero, zero */
    .word 0x70004628 /* 001D776C: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D7770: paddub a5, zero, zero */
    .word 0x70005628 /* 001D7774: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D7778: jal        func_1D4330 */
    .word 0x70005E28 /* 001D777C: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D7780: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D7784: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D7788: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D778C: jal        func_001D42A0 */
    .word 0x70403628 /* 001D7790: paddub a2, v0, zero */
    .word 0x10000012 /* 001D7794: b 0x8d0 */
    .word 0x00000000 /* 001D7798: nop  */
    .word 0x3C023F80 /* 001D779C: lui v0, 0x3f80 */
    .word 0x44806800 /* 001D77A0: mtc1 zero, fa1 */
    .word 0x44826000 /* 001D77A4: mtc1 v0, fa0 */
    .word 0x72E02E28 /* 001D77A8: paddub a1, s7, zero */
    .word 0x72C02628 /* 001D77AC: paddub a0, s6, zero */
    .word 0x72A03628 /* 001D77B0: paddub a2, s5, zero */
    .word 0x70003E28 /* 001D77B4: paddub a3, zero, zero */
    .word 0x70004628 /* 001D77B8: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D77BC: paddub a5, zero, zero */
    .word 0x70005628 /* 001D77C0: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D77C4: jal        func_1D4330 */
    .word 0x70005E28 /* 001D77C8: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D77CC: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D77D0: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D77D4: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D77D8: jal        func_001D42A0 */
    .word 0x70403628 /* 001D77DC: paddub a2, v0, zero */
    .word 0x1AA0003B /* 001D77E0: blez s5, 0x9c0 */
    .word 0x00000000 /* 001D77E4: nop  */
    .word 0x8EC3011C /* 001D77E8: lw v1, 0x11c(s6) */
    .word 0x00143080 /* 001D77EC: sll a2, s4, 2 */
    .word 0x00661821 /* 001D77F0: addu v1, v1, a2 */
    .word 0x8C630000 /* 001D77F4: lw v1, 0x0(v1) */
    .word 0x00702821 /* 001D77F8: addu a1, v1, s0 */
    .word 0x90A40000 /* 001D77FC: lbu a0, 0x0(a1) */
    .word 0x02641824 /* 001D7800: and v1, s3, a0 */
    .word 0x14600032 /* 001D7804: bnez v1, 0x9c0 */
    .word 0x00000000 /* 001D7808: nop  */
    .word 0x8FA300D0 /* 001D780C: lw v1, 0xd0(sp) */
    .word 0x30630001 /* 001D7810: andi v1, v1, 0x1 */
    .word 0x1060002E /* 001D7814: beqz v1, 0x9c0 */
    .word 0x00000000 /* 001D7818: nop  */
    .word 0x00921021 /* 001D781C: addu v0, a0, s2 */
    .word 0xA0A20000 /* 001D7820: sb v0, 0x0(a1) */
    .word 0x8EC20120 /* 001D7824: lw v0, 0x120(s6) */
    .word 0x00461021 /* 001D7828: addu v0, v0, a2 */
    .word 0x8C420000 /* 001D782C: lw v0, 0x0(v0) */
    .word 0x00501021 /* 001D7830: addu v0, v0, s0 */
    .word 0x90420000 /* 001D7834: lbu v0, 0x0(v0) */
    .word 0x02621024 /* 001D7838: and v0, s3, v0 */
    .word 0x14400014 /* 001D783C: bnez v0, 0x980 */
    .word 0x3C023F80 /* 001D7840: lui v0, 0x3f80 */
    .word 0x44806000 /* 001D7844: mtc1 zero, fa0 */
    .word 0x72003628 /* 001D7848: paddub a2, s0, zero */
    .word 0x72C02628 /* 001D784C: paddub a0, s6, zero */
    .word 0x46006346 /* 001D7850: mov.s fa1, fa0 */
    .word 0x72802E28 /* 001D7854: paddub a1, s4, zero */
    .word 0x70003E28 /* 001D7858: paddub a3, zero, zero */
    .word 0x70004628 /* 001D785C: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D7860: paddub a5, zero, zero */
    .word 0x70005628 /* 001D7864: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D7868: jal        func_1D4330 */
    .word 0x70005E28 /* 001D786C: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D7870: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D7874: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D7878: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D787C: jal        func_001D42A0 */
    .word 0x70403628 /* 001D7880: paddub a2, v0, zero */
    .word 0x10000013 /* 001D7884: b 0x9c4 */
    .word 0x8EC300F0 /* 001D7888: lw v1, 0xf0(s6) */
    .word 0x3C023F80 /* 001D788C: lui v0, 0x3f80 */
    .word 0x44806800 /* 001D7890: mtc1 zero, fa1 */
    .word 0x44826000 /* 001D7894: mtc1 v0, fa0 */
    .word 0x72003628 /* 001D7898: paddub a2, s0, zero */
    .word 0x72C02628 /* 001D789C: paddub a0, s6, zero */
    .word 0x72802E28 /* 001D78A0: paddub a1, s4, zero */
    .word 0x70003E28 /* 001D78A4: paddub a3, zero, zero */
    .word 0x70004628 /* 001D78A8: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D78AC: paddub a5, zero, zero */
    .word 0x70005628 /* 001D78B0: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D78B4: jal        func_1D4330 */
    .word 0x70005E28 /* 001D78B8: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D78BC: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D78C0: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D78C4: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D78C8: jal        func_001D42A0 */
    .word 0x70403628 /* 001D78CC: paddub a2, v0, zero */
    .word 0x8EC300F0 /* 001D78D0: lw v1, 0xf0(s6) */
    .word 0x02A3082A /* 001D78D4: slt at, s5, v1 */
    .word 0x1020003B /* 001D78D8: beqz at, 0xab8 */
    .word 0x00000000 /* 001D78DC: nop  */
    .word 0x8EC3011C /* 001D78E0: lw v1, 0x11c(s6) */
    .word 0x00143080 /* 001D78E4: sll a2, s4, 2 */
    .word 0x00661821 /* 001D78E8: addu v1, v1, a2 */
    .word 0x8C630000 /* 001D78EC: lw v1, 0x0(v1) */
    .word 0x00712821 /* 001D78F0: addu a1, v1, s1 */
    .word 0x90A40000 /* 001D78F4: lbu a0, 0x0(a1) */
    .word 0x02641824 /* 001D78F8: and v1, s3, a0 */
    .word 0x14600032 /* 001D78FC: bnez v1, 0xab8 */
    .word 0x00000000 /* 001D7900: nop  */
    .word 0x8FA300D0 /* 001D7904: lw v1, 0xd0(sp) */
    .word 0x30630008 /* 001D7908: andi v1, v1, 0x8 */
    .word 0x1060002E /* 001D790C: beqz v1, 0xab8 */
    .word 0x00000000 /* 001D7910: nop  */
    .word 0x00921021 /* 001D7914: addu v0, a0, s2 */
    .word 0xA0A20000 /* 001D7918: sb v0, 0x0(a1) */
    .word 0x8EC20120 /* 001D791C: lw v0, 0x120(s6) */
    .word 0x00461021 /* 001D7920: addu v0, v0, a2 */
    .word 0x8C420000 /* 001D7924: lw v0, 0x0(v0) */
    .word 0x00511021 /* 001D7928: addu v0, v0, s1 */
    .word 0x90420000 /* 001D792C: lbu v0, 0x0(v0) */
    .word 0x02621024 /* 001D7930: and v0, s3, v0 */
    .word 0x14400014 /* 001D7934: bnez v0, 0xa78 */
    .word 0x3C023F80 /* 001D7938: lui v0, 0x3f80 */
    .word 0x44806000 /* 001D793C: mtc1 zero, fa0 */
    .word 0x72802E28 /* 001D7940: paddub a1, s4, zero */
    .word 0x72203628 /* 001D7944: paddub a2, s1, zero */
    .word 0x72C02628 /* 001D7948: paddub a0, s6, zero */
    .word 0x46006346 /* 001D794C: mov.s fa1, fa0 */
    .word 0x70003E28 /* 001D7950: paddub a3, zero, zero */
    .word 0x70004628 /* 001D7954: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D7958: paddub a5, zero, zero */
    .word 0x70005628 /* 001D795C: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D7960: jal        func_1D4330 */
    .word 0x70005E28 /* 001D7964: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D7968: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D796C: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D7970: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D7974: jal        func_001D42A0 */
    .word 0x70403628 /* 001D7978: paddub a2, v0, zero */
    .word 0x10000012 /* 001D797C: b 0xab8 */
    .word 0x00000000 /* 001D7980: nop  */
    .word 0x3C023F80 /* 001D7984: lui v0, 0x3f80 */
    .word 0x44806800 /* 001D7988: mtc1 zero, fa1 */
    .word 0x44826000 /* 001D798C: mtc1 v0, fa0 */
    .word 0x72802E28 /* 001D7990: paddub a1, s4, zero */
    .word 0x72203628 /* 001D7994: paddub a2, s1, zero */
    .word 0x72C02628 /* 001D7998: paddub a0, s6, zero */
    .word 0x70003E28 /* 001D799C: paddub a3, zero, zero */
    .word 0x70004628 /* 001D79A0: paddub a4, zero, zero */
    .word 0x70004E28 /* 001D79A4: paddub a5, zero, zero */
    .word 0x70005628 /* 001D79A8: paddub a6, zero, zero */
    jal        func_1D4330 /* 001D79AC: jal        func_1D4330 */
    .word 0x70005E28 /* 001D79B0: paddub a7, zero, zero */
    .word 0x26C50008 /* 001D79B4: addiu a1, s6, 0x8 */
    .word 0x24070001 /* 001D79B8: addiu a3, zero, 0x1 */
    .word 0x72C02628 /* 001D79BC: paddub a0, s6, zero */
    jal        func_001D42A0 /* 001D79C0: jal        func_001D42A0 */
    .word 0x70403628 /* 001D79C4: paddub a2, v0, zero */
    .word 0x8EC60028 /* 001D79C8: lw a2, 0x28(s6) */
    .word 0x00000000 /* 001D79CC: nop  */
    .word 0x8EC30028 /* 001D79D0: lw v1, 0x28(s6) */
    .word 0x1460FD99 /* 001D79D4: bnez v1, 0x12c */
    .word 0x00000000 /* 001D79D8: nop  */
    .word 0x8FA300B0 /* 001D79DC: lw v1, 0xb0(sp) */
    .word 0x24630001 /* 001D79E0: addiu v1, v1, 0x1 */
    .word 0xAFA300B0 /* 001D79E4: sw v1, 0xb0(sp) */
    .word 0x8EC50094 /* 001D79E8: lw a1, 0x94(s6) */
    .word 0x8FA300B0 /* 001D79EC: lw v1, 0xb0(sp) */
    .word 0x84A40050 /* 001D79F0: lh a0, 0x50(a1) */
    .word 0x0064182A /* 001D79F4: slt v1, v1, a0 */
    .word 0x1460FD63 /* 001D79F8: bnez v1, 0x78 */
    .word 0x00000000 /* 001D79FC: nop  */
    .word 0x10000016 /* 001D7A00: b 0xb4c */
    .word 0x70003E28 /* 001D7A04: paddub a3, zero, zero */
    .word 0x70004628 /* 001D7A08: paddub a4, zero, zero */
    .word 0x1000000E /* 001D7A0C: b 0xb38 */
    .word 0x00073080 /* 001D7A10: sll a2, a3, 2 */
    .word 0x8EC40120 /* 001D7A14: lw a0, 0x120(s6) */
    .word 0x8EC3011C /* 001D7A18: lw v1, 0x11c(s6) */
    .word 0x00C42021 /* 001D7A1C: addu a0, a2, a0 */
    .word 0x8C850000 /* 001D7A20: lw a1, 0x0(a0) */
    .word 0x00C31821 /* 001D7A24: addu v1, a2, v1 */
    .word 0x8C640000 /* 001D7A28: lw a0, 0x0(v1) */
    .word 0x00A82821 /* 001D7A2C: addu a1, a1, a4 */
    .word 0x00882021 /* 001D7A30: addu a0, a0, a4 */
    .word 0x90A30000 /* 001D7A34: lbu v1, 0x0(a1) */
    .word 0x90840000 /* 001D7A38: lbu a0, 0x0(a0) */
    .word 0x25080001 /* 001D7A3C: addiu a4, a4, 0x1 */
    .word 0x00641824 /* 001D7A40: and v1, v1, a0 */
    .word 0xA0A30000 /* 001D7A44: sb v1, 0x0(a1) */
    .word 0x8EC300E8 /* 001D7A48: lw v1, 0xe8(s6) */
    .word 0x0103182A /* 001D7A4C: slt v1, a4, v1 */
    .word 0x1460FFF0 /* 001D7A50: bnez v1, 0xb04 */
    .word 0x00000000 /* 001D7A54: nop  */
    .word 0x24E70001 /* 001D7A58: addiu a3, a3, 0x1 */
    .word 0x8EC300E4 /* 001D7A5C: lw v1, 0xe4(s6) */
    .word 0x00E3182A /* 001D7A60: slt v1, a3, v1 */
    .word 0x1460FFE9 /* 001D7A64: bnez v1, 0xafc */
    .word 0x70004628 /* 001D7A68: paddub a4, zero, zero */
    .word 0x7BBF00A0 /* 001D7A6C: lq ra, 0xa0(sp) */
    .word 0x7BBE0090 /* 001D7A70: lq s8, 0x90(sp) */
    .word 0x7BB70080 /* 001D7A74: lq s7, 0x80(sp) */
    .word 0x7BB60070 /* 001D7A78: lq s6, 0x70(sp) */
    .word 0x7BB50060 /* 001D7A7C: lq s5, 0x60(sp) */
    .word 0x7BB40050 /* 001D7A80: lq s4, 0x50(sp) */
    .word 0x7BB30040 /* 001D7A84: lq s3, 0x40(sp) */
    .word 0x7BB20030 /* 001D7A88: lq s2, 0x30(sp) */
    .word 0x7BB10020 /* 001D7A8C: lq s1, 0x20(sp) */
    .word 0x7BB00010 /* 001D7A90: lq s0, 0x10(sp) */
    .word 0xC7B40000 /* 001D7A94: lwc1 fs0, 0x0(sp) */
    .word 0x03E00008 /* 001D7A98: jr ra */
    .word 0x27BD00E0 /* 001D7A9C: addiu sp, sp, 0xe0 */
}

#else

extern "C" void func_001D6F10(void *self) {
    if (self == 0) return;
    char *zm = (char *)self;
    int w = *(int *)(zm + 0xE4);
    int h = *(int *)(zm + 0xE8);
    char **grid = *(char ***)(zm + 0x11C);

    if (grid != 0) {
        for (int i = 0; i < w; ++i) {
            func_117CAC(grid[i], 0, h);
        }
    }
}

#endif
