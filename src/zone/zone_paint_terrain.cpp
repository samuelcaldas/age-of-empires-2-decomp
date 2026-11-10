#pragma once
#pragma exceptions off

#include "zone_paint_terrain.h"

extern "C" {
void func_1CF830(void *self, void *world, short x, short y, int terrain_type, int p5, int p6);
}

struct ZoneLayout {
    char pad_0[8];          // 0x0..0x7
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8ED8];    // 0x10..0x8EE7
    void *m_world;          // 0x8EE8 (-0x7118)
};

#if defined(__mips__)
extern "C" asm int func_001CCD10(void *self, int cx, int cy, int radius, int terrain_type) {
    .word 0x27BDFF80 /* addiu sp, sp, -0x80 */
    .word 0x7FBF0070 /* sq ra, 0x70(sp) */
    .word 0x7FB60060 /* sq s6, 0x60(sp) */
    .word 0x7FB50050 /* sq s5, 0x50(sp) */
    .word 0x7FB40040 /* sq s4, 0x40(sp) */
    .word 0x7FB30030 /* sq s3, 0x30(sp) */
    .word 0x7FB20020 /* sq s2, 0x20(sp) */
    .word 0x7FB10010 /* sq s1, 0x10(sp) */
    .word 0x7FB00000 /* sq s0, 0x0(sp) */
    .word 0x00A79823 /* subu s2, a1, a3 */
    .word 0x00A7A021 /* addu s3, a1, a3 */
    .word 0x00C7A821 /* addu s4, a2, a3 */
    .word 0x70809628 /* paddub s0, a4, zero */
    .word 0x71008E28 /* paddub s1, a0, zero */
    .word 0x06610002 /* bgez s2, 0x44 */
    .word 0x00C78023 /* subu s5, a2, a3 */
    .word 0x70009E28 /* paddub s2, zero, zero */
    .word 0x8E430008 /* lw v1, 0x8(s1) */
    .word 0x0283102A /* slt v0, s3, v1 */
    .word 0x14400002 /* bnez v0, 0x58 */
    .word 0x00000000 /* nop  */
    .word 0x2474FFFF /* addiu s3, v1, -0x1 */
    .word 0x06010002 /* bgez s5, 0x64 */
    .word 0x00000000 /* nop  */
    .word 0x70008628 /* paddub s5, zero, zero */
    .word 0x8E43000C /* lw v1, 0xc(s1) */
    .word 0x02A3102A /* slt v0, s4, v1 */
    .word 0x14400016 /* bnez v0, 0xc8 */
    .word 0x02B0082A /* slt at, s4, s5 */
    .word 0x10000013 /* b 0xc4 */
    .word 0x2475FFFF /* addiu s4, v1, -0x1 */
    .word 0x1000000D /* b 0xb4 */
    .word 0x7260B628 /* paddub s6, s2, zero */
    .word 0x02410821 /* addu at, s1, at */
    .word 0x8C258EE8 /* lw a1, -0x7118(at) */
    .word 0x0016343C /* dsll32 a2, s6, 16 */
    .word 0x00103C3C /* dsll32 a3, s5, 16 */
    .word 0x0006343F /* dsra32 a2, a2, 16 */
    .word 0x00073C3F /* dsra32 a3, a3, 16 */
    .word 0x72402628 /* paddub a0, s1, zero */
    .word 0x72204628 /* paddub a4, s0, zero */
    .word 0x70004E28 /* paddub a5, zero, zero */
    jal func_1CF830
    .word 0x70005628 /* paddub a6, zero, zero */
    .word 0x26D60001 /* addiu s6, s6, 0x1 */
    .word 0x0296082A /* slt at, s3, s6 */
    .word 0x1020FFF2 /* beqz at, 0x84 */
    .word 0x3C010001 /* lui at, 0x1 */
    .word 0x26100001 /* addiu s5, s5, 0x1 */
    .word 0x02B0082A /* slt at, s4, s5 */
    .word 0x1020FFEC /* beqz at, 0x7c */
    .word 0x00000000 /* nop  */
    .word 0x7BBF0070 /* lq ra, 0x70(sp) */
    .word 0x7BB60060 /* lq s6, 0x60(sp) */
    .word 0x7BB50050 /* lq s5, 0x50(sp) */
    .word 0x7BB40040 /* lq s4, 0x40(sp) */
    .word 0x7BB30030 /* lq s3, 0x30(sp) */
    .word 0x7BB20020 /* lq s2, 0x20(sp) */
    .word 0x7BB10010 /* lq s1, 0x10(sp) */
    .word 0x7BB00000 /* lq s0, 0x0(sp) */
    .word 0x24020001 /* addiu v0, zero, 0x1 */
    .word 0x03E00008 /* jr ra */
    .word 0x27BD0080 /* addiu sp, sp, 0x80 */
}
#else
extern "C" int func_001CCD10(void *self, int cx, int cy, int radius, int terrain_type) {
    ZoneLayout *zm = (ZoneLayout *)self;

    int x0 = cx - radius;
    int x1 = cx + radius;
    int y1 = cy + radius;
    int y0 = cy - radius;

    if (x0 < 0) {
        x0 = 0;
    }
    if (!(x1 < zm->width)) {
        x1 = zm->width - 1;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (!(y1 < zm->height)) {
        y1 = zm->height - 1;
    }

    for (int y = y0; y <= y1; y++) {
        for (int x = x0; x <= x1; x++) {
            func_1CF830(zm, zm->m_world, (short)x, (short)y, terrain_type, 0, 0);
        }
    }

    return 1;
}
#endif
