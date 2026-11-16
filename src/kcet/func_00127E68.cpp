typedef signed int s32;

extern "C" {

#if defined(__mips__)
asm s32 func_00127E68(s32 a0, s32 a1) {
    .word 0x27bdff40 /* addiu , , -0xc0 */
    .word 0x3c020039 /* lui , 0x39 */
    .word 0xffb10030 /* sd , 0x30() */
    .word 0x2442c7c8 /* addiu , , -0x3838 */
    .word 0xffbe00a0 /* sd , 0xa0() */
    .word 0x0080882d /* move ,  */
    .word 0xffb20040 /* sd , 0x40() */
    .word 0x0000f02d /* move ,  */
    .word 0xffb00020 /* sd , 0x20() */
    .word 0x0000902d /* move ,  */
    .word 0xffbf00b0 /* sd , 0xb0() */
    .word 0x263000c4 /* addiu , , 0xc4 */
    .word 0xffb70090 /* sd , 0x90() */
    .word 0xffb60080 /* sd , 0x80() */
    .word 0xffb50070 /* sd , 0x70() */
    .word 0xffb40060 /* sd , 0x60() */
    .word 0xffb30050 /* sd , 0x50() */
    .word 0xafa20018 /* sw , 0x18() */
    .word 0xafa00000 /* sw , () */
    .word 0xafa00008 /* sw , 8() */
    .word 0xafa0000c /* sw , 0xc() */
    .word 0xafa00010 /* sw , 0x10() */
    .word 0x10a00075 /* beqz , 0x128098 */
    .word 0xafa00014 /* sw , 0x14() */
    .word 0x922200c4 /* lbu , 0xc4() */
    .word 0x54400074 /* bnel , , 0x1280a0 */
    .word 0x8e220098 /* lw , 0x98() */
    .word 0x92020001 /* lbu , 1() */
    .word 0xafa20004 /* sw , 4() */
    .word 0x8e220068 /* lw , 0x68() */
    .word 0x8fa30004 /* lw , 4() */
    .word 0x00031902 /* srl , , 4 */
    .word 0x00621007 /* srav , ,  */
    .word 0x30420001 /* andi , , 1 */
    .word 0x10400073 /* beqz , 0x1280c0 */
    .word 0xafa30000 /* sw , () */
    .word 0x92020002 /* lbu , 2() */
    .word 0xafb2000c /* sw , 0xc() */
    .word 0x00021200 /* sll , , 8 */
    .word 0x92040003 /* lbu , 3() */
    .word 0x96230000 /* lhu , () */
    .word 0x00441025 /* or , ,  */
    .word 0x385effff /* xori , , 0xffff */
    .word 0x03c31826 /* xor , ,  */
    .word 0x03c31824 /* and , ,  */
    .word 0x13c00023 /* beqz , 0x127fac */
    .word 0xafa30008 /* sw , 8() */
    .word 0x262400cc /* addiu , , 0xcc */
    .word 0x26250038 /* addiu , , 0x38 */
    .word 0xafa4001c /* sw , 0x1c() */
    .word 0x24070002 /* addiu , , 2 */
    .word 0x00000000 /* nop  */
    .word 0x94a30000 /* lhu , () */
    .word 0x90a20002 /* lbu , 2() */
    .word 0x007e2024 /* and , ,  */
    .word 0x10800014 /* beqz , 0x127f98 */
    .word 0x90a60003 /* lbu , 3() */
    .word 0x8fa80008 /* lw , 8() */
    .word 0x00681824 /* and , ,  */
    .word 0x10600009 /* beqz , 0x127f7c */
    .word 0x00000000 /* nop  */
    .word 0x8fa2000c /* lw , 0xc() */
    .word 0x00431025 /* or , ,  */
    .word 0xafa2000c /* sw , 0xc() */
    .word 0x30c200f0 /* andi , , 0xf0 */
    .word 0x50400009 /* beql , , 0x127f94 */
    .word 0x30c2000f /* andi , , 0xf */
    .word 0x10000008 /* b 0x127f98 */
    .word 0xa0a20002 /* sb , 2() */
    .word 0x14400005 /* bnez , 0x127f94 */
    .word 0x2442ffff /* addiu , , -1 */
    .word 0x8fa3000c /* lw , 0xc() */
    .word 0x00641825 /* or , ,  */
    .word 0xafa3000c /* sw , 0xc() */
    .word 0x30c2000f /* andi , , 0xf */
    .word 0xa0a20002 /* sb , 2() */
    .word 0x24e7ffff /* addiu , , -1 */
    .word 0x04e1ffe6 /* bgez , 0x127f38 */
    .word 0x24a50004 /* addiu , , 4 */
    .word 0x10000003 /* b 0x127fb4 */
    .word 0x00000000 /* nop  */
    .word 0x262400cc /* addiu , , 0xcc */
    .word 0xafa4001c /* sw , 0x1c() */
    .word 0x0c049f1a /* jal 0x127c68 */
    .word 0x0220202d /* move ,  */
    .word 0x50400023 /* beql , , 0x12804c */
    .word 0xafa00010 /* sw , 0x10() */
    .word 0x0c049f1e /* jal 0x127c78 */
    .word 0x8fa40000 /* lw , () */
    .word 0x1040001e /* beqz , 0x128048 */
    .word 0x26160007 /* addiu , , 7 */
    .word 0x26350047 /* addiu , , 0x47 */
    .word 0x26340046 /* addiu , , 0x46 */
    .word 0x26330045 /* addiu , , 0x45 */
    .word 0x26320044 /* addiu , , 0x44 */
    .word 0x24170003 /* addiu , , 3 */
    .word 0x92d00000 /* lbu , () */
    .word 0x26f7ffff /* addiu , , -1 */
    .word 0x92450000 /* lbu , () */
    .word 0x26d6ffff /* addiu , , -1 */
    .word 0x92660000 /* lbu , () */
    .word 0x0200202d /* move ,  */
    .word 0x92870000 /* lbu , () */
    .word 0x26730004 /* addiu , , 4 */
    .word 0x92a80000 /* lbu , () */
    .word 0x26940004 /* addiu , , 4 */
    .word 0x26b50004 /* addiu , , 4 */
    .word 0x0c049f4c /* jal 0x127d30 */
    .word 0x26520004 /* addiu , , 4 */
    .word 0x8fa50010 /* lw , 0x10() */
    .word 0x8fa80014 /* lw , 0x14() */
    .word 0x00051a00 /* sll , , 8 */
    .word 0x00082200 /* sll , , 8 */
    .word 0x00701825 /* or , ,  */
    .word 0x00822025 /* or , ,  */
    .word 0xafa30010 /* sw , 0x10() */
    .word 0x06e1ffeb /* bgez , 0x127fe8 */
    .word 0xafa40014 /* sw , 0x14() */
    .word 0x10000003 /* b 0x128050 */
    .word 0x00000000 /* nop  */
    .word 0xafa00010 /* sw , 0x10() */
    .word 0xafa00014 /* sw , 0x14() */
    .word 0x0c04a21a /* jal 0x128868 */
    .word 0x8fa40004 /* lw , 4() */
    .word 0x8fa40018 /* lw , 0x18() */
    .word 0x8fa3001c /* lw , 0x1c() */
    .word 0x0082180a /* movz , ,  */
    .word 0xafa30018 /* sw , 0x18() */
    .word 0x0c049e04 /* jal 0x127810 */
    .word 0x0220202d /* move ,  */
    .word 0x10400004 /* beqz , 0x128084 */
    .word 0x00000000 /* nop  */
    .word 0xafa00008 /* sw , 8() */
    .word 0x0c049dfe /* jal 0x1277f8 */
    .word 0x0220202d /* move ,  */
    .word 0x0c049e04 /* jal 0x127810 */
    .word 0x0220202d /* move ,  */
    .word 0x2c520001 /* sltiu , , 1 */
    .word 0x1000000b /* b 0x1280c0 */
    .word 0xae200098 /* sw , 0x98() */
    .word 0x8e220098 /* lw , 0x98() */
    .word 0x0000f02d /* move ,  */
    .word 0xafa00008 /* sw , 8() */
    .word 0x0220202d /* move ,  */
    .word 0xafa0000c /* sw , 0xc() */
    .word 0x24420001 /* addiu , , 1 */
    .word 0xafa00010 /* sw , 0x10() */
    .word 0xae220098 /* sw , 0x98() */
    .word 0x0c049df8 /* jal 0x1277e0 */
    .word 0xafa00014 /* sw , 0x14() */
    .word 0x8fa60008 /* lw , 8() */
    .word 0x03c0282d /* move ,  */
    .word 0x8fa7000c /* lw , 0xc() */
    .word 0x0c049f22 /* jal 0x127c88 */
    .word 0x0220202d /* move ,  */
    .word 0x8fa50018 /* lw , 0x18() */
    .word 0x0220202d /* move ,  */
    .word 0x0c049f26 /* jal 0x127c98 */
    .word 0x2406000c /* addiu , , 0xc */
    .word 0x8fa50000 /* lw , () */
    .word 0x0240102d /* move ,  */
    .word 0xdfbf00b0 /* ld , 0xb0() */
    .word 0xae250094 /* sw , 0x94() */
    .word 0xdfbe00a0 /* ld , 0xa0() */
    .word 0x8fa80010 /* lw , 0x10() */
    .word 0xdfb70090 /* ld , 0x90() */
    .word 0xae28000c /* sw , 0xc() */
    .word 0xdfb60080 /* ld , 0x80() */
    .word 0x8fa30014 /* lw , 0x14() */
    .word 0xdfb50070 /* ld , 0x70() */
    .word 0xae230008 /* sw , 8() */
    .word 0xdfb40060 /* ld , 0x60() */
    .word 0xdfb30050 /* ld , 0x50() */
    .word 0xdfb20040 /* ld , 0x40() */
    .word 0xdfb10030 /* ld , 0x30() */
    .word 0xdfb00020 /* ld , 0x20() */
    .word 0x03e00008 /* jr  */
    .word 0x27bd00c0 /* addiu , , 0xc0 */
};
#else
s32 func_00127E68(s32 a0, s32 a1) {
    return 0;
}
#endif

}
