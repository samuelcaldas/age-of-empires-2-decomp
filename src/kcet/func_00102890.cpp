#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct sceGsDispEnv {
    u64 pmode;
    u64 smode2;
    u64 dispfb;
    u64 display;
    u64 pad;
};

struct GsModeInfo {
    s16 field_0;
    s16 field_2;
    s16 field_4;
    s16 field_6;
};

extern "C" {

GsModeInfo *func_00102818(void);
void func_118de0(const char *fmt, ...);
extern const char D_0048D3E8[];

#if defined(__mips__)
asm void func_00102890(sceGsDispEnv *env, s16 psm, s16 w, s16 h, s16 dx, s16 dy) {
    .word 0x27bdff90 // 00102890:  addiu $sp, $sp, -0x70
    .word 0x00052c00 // 00102894:  sll $a1, $a1, 0x10
    .word 0xffb50050 // 00102898:  sd $s5, 0x50($sp)
    .word 0x00063400 // 0010289C:  sll $a2, $a2, 0x10
    .word 0xffb40040 // 001028A0:  sd $s4, 0x40($sp)
    .word 0x00073c00 // 001028A4:  sll $a3, $a3, 0x10
    .word 0xffb30030 // 001028A8:  sd $s3, 0x30($sp)
    .word 0x00084400 // 001028AC:  sll $t0, $t0, 0x10
    .word 0xffb20020 // 001028B0:  sd $s2, 0x20($sp)
    .word 0x00094c00 // 001028B4:  sll $t1, $t1, 0x10
    .word 0xffb10010 // 001028B8:  sd $s1, 0x10($sp)
    .word 0x0005ac03 // 001028BC:  sra $s5, $a1, 0x10
    .word 0xffb00000 // 001028C0:  sd $s0, ($sp)
    .word 0x0080882d // 001028C4:  move $s1, $a0
    .word 0xffbf0060 // 001028C8:  sd $ra, 0x60($sp)
    .word 0x00068403 // 001028CC:  sra $s0, $a2, 0x10
    .word 0x00079c03 // 001028D0:  sra $s3, $a3, 0x10
    .word 0x0008a403 // 001028D4:  sra $s4, $t0, 0x10
    .word 0x0c040a06 // 001028D8:  jal 0x102818
    .word 0x00099403 // 001028DC:  sra $s2, $t1, 0x10
    .word 0x24030066 // 001028E0:  addiu $v1, $zero, 0x66
    .word 0x0040302d // 001028E4:  move $a2, $v0
    .word 0xfe230000 // 001028E8:  sd $v1, ($s1)
    .word 0x84c20000 // 001028EC:  lh $v0, ($a2)
    .word 0x10400006 // 001028F0:  beqz $v0, 0x10290c
    .word 0x94c70000 // 001028F4:  lhu $a3, ($a2)
    .word 0x84c20004 // 001028F8:  lh $v0, 4($a2)
    .word 0x14400004 // 001028FC:  bnez $v0, 0x102910
    .word 0x24020003 // 00102900:  addiu $v0, $zero, 3
    .word 0x10000002 // 00102904:  b 0x102910
    .word 0x24020001 // 00102908:  addiu $v0, $zero, 1
    .word 0x24020002 // 0010290C:  addiu $v0, $zero, 2
    .word 0xfe220008 // 00102910:  sd $v0, 8($s1)
    .word 0x2602003f // 00102914:  addiu $v0, $s0, 0x3f
    .word 0x32a3000f // 00102918:  andi $v1, $s5, 0xf
    .word 0x00021183 // 0010291C:  sra $v0, $v0, 6
    .word 0x00031bf8 // 00102920:  dsll $v1, $v1, 0xf
    .word 0x3042003f // 00102924:  andi $v0, $v0, 0x3f
    .word 0x24040002 // 00102928:  addiu $a0, $zero, 2
    .word 0x00021278 // 0010292C:  dsll $v0, $v0, 9
    .word 0x00621825 // 00102930:  or $v1, $v1, $v0
    .word 0xfe230010 // 00102934:  sd $v1, 0x10($s1)
    .word 0x84c50002 // 00102938:  lh $a1, 2($a2)
    .word 0x14a40029 // 0010293C:  bne $a1, $a0, 0x1029e4
    .word 0x24020003 // 00102940:  addiu $v0, $zero, 3
    .word 0x00071400 // 00102944:  sll $v0, $a3, 0x10
    .word 0x24030001 // 00102948:  addiu $v1, $zero, 1
    .word 0x00021403 // 0010294C:  sra $v0, $v0, 0x10
    .word 0x14430016 // 00102950:  bne $v0, $v1, 0x1029ac
    .word 0x260209ff // 00102954:  addiu $v0, $s0, 0x9ff
    .word 0x26430032 // 00102958:  addiu $v1, $s2, 0x32
    .word 0x0050001a // 0010295C:  div $zero, $v0, $s0
    .word 0x30630fff // 00102960:  andi $v1, $v1, 0xfff
    .word 0x52000001 // 00102964:  beql $s0, $zero, 0x10296c
    .word 0x000001cd // 00102968:  break 0, 7
    .word 0x00033b38 // 0010296C:  dsll $a3, $v1, 0xc
    .word 0x84c60004 // 00102970:  lh $a2, 4($a2)
    .word 0x00001012 // 00102974:  mflo $v0
    .word 0x72822818 // 00102978:  .word
    .word 0x00502018 // 0010297C:  .word
    .word 0x2442ffff // 00102980:  addiu $v0, $v0, -1
    .word 0x64a3027c // 00102984:  daddiu $v1, $a1, 0x27c
    .word 0x000255f8 // 00102988:  dsll $t2, $v0, 0x17
    .word 0x30650fff // 0010298C:  andi $a1, $v1, 0xfff
    .word 0x2484ffff // 00102990:  addiu $a0, $a0, -1
    .word 0x10c0002f // 00102994:  beqz $a2, 0x102a54
    .word 0x0004183c // 00102998:  dsll32 $v1, $a0, 0
    .word 0x00131040 // 0010299C:  sll $v0, $s3, 1
    .word 0x01431825 // 001029A0:  or $v1, $t2, $v1
    .word 0x1000002d // 001029A4:  b 0x102a5c
    .word 0x2442ffff // 001029A8:  addiu $v0, $v0, -1
    .word 0x2666ffff // 001029AC:  addiu $a2, $s3, -1
    .word 0x0050001a // 001029B0:  div $zero, $v0, $s0
    .word 0x0006333c // 001029B4:  dsll32 $a2, $a2, 0xc
    .word 0x26450019 // 001029B8:  addiu $a1, $s2, 0x19
    .word 0x52000001 // 001029BC:  beql $s0, $zero, 0x1029c4
    .word 0x000001cd // 001029C0:  break 0, 7
    .word 0x30a50fff // 001029C4:  andi $a1, $a1, 0xfff
    .word 0x00052b38 // 001029C8:  dsll $a1, $a1, 0xc
    .word 0x00001012 // 001029CC:  mflo $v0
    .word 0x02823818 // 001029D0:  .word
    .word 0x70502018 // 001029D4:  .word
    .word 0x2442ffff // 001029D8:  addiu $v0, $v0, -1
    .word 0x10000032 // 001029DC:  b 0x102aa8
    .word 0x64e3027c // 001029E0:  daddiu $v1, $a3, 0x27c
    .word 0x14a2003a // 001029E4:  bne $a1, $v0, 0x102ad0
    .word 0x3c040049 // 001029E8:  lui $a0, 0x49
    .word 0x00071400 // 001029EC:  sll $v0, $a3, 0x10
    .word 0x24030001 // 001029F0:  addiu $v1, $zero, 1
    .word 0x00021403 // 001029F4:  sra $v0, $v0, 0x10
    .word 0x1443001e // 001029F8:  bne $v0, $v1, 0x102a74
    .word 0x260209ff // 001029FC:  addiu $v0, $s0, 0x9ff
    .word 0x26430048 // 00102A00:  addiu $v1, $s2, 0x48
    .word 0x0050001a // 00102A04:  div $zero, $v0, $s0
    .word 0x30630fff // 00102A08:  andi $v1, $v1, 0xfff
    .word 0x52000001 // 00102A0C:  beql $s0, $zero, 0x102a14
    .word 0x000001cd // 00102A10:  break 0, 7
    .word 0x00033b38 // 00102A14:  dsll $a3, $v1, 0xc
    .word 0x84c60004 // 00102A18:  lh $a2, 4($a2)
    .word 0x00001012 // 00102A1C:  mflo $v0
    .word 0x72822818 // 00102A20:  .word
    .word 0x00502018 // 00102A24:  .word
    .word 0x2442ffff // 00102A28:  addiu $v0, $v0, -1
    .word 0x64a30290 // 00102A2C:  daddiu $v1, $a1, 0x290
    .word 0x000255f8 // 00102A30:  dsll $t2, $v0, 0x17
    .word 0x30650fff // 00102A34:  andi $a1, $v1, 0xfff
    .word 0x2484ffff // 00102A38:  addiu $a0, $a0, -1
    .word 0x10c00005 // 00102A3C:  beqz $a2, 0x102a54
    .word 0x0004183c // 00102A40:  dsll32 $v1, $a0, 0
    .word 0x00131040 // 00102A44:  sll $v0, $s3, 1
    .word 0x01431825 // 00102A48:  or $v1, $t2, $v1
    .word 0x10000003 // 00102A4C:  b 0x102a5c
    .word 0x2442ffff // 00102A50:  addiu $v0, $v0, -1
    .word 0x2662ffff // 00102A54:  addiu $v0, $s3, -1
    .word 0x01431825 // 00102A58:  or $v1, $t2, $v1
    .word 0x0002133c // 00102A5C:  dsll32 $v0, $v0, 0xc
    .word 0x00a21025 // 00102A60:  or $v0, $a1, $v0
    .word 0x00621825 // 00102A64:  or $v1, $v1, $v0
    .word 0x00671025 // 00102A68:  or $v0, $v1, $a3
    .word 0x1000001a // 00102A6C:  b 0x102ad8
    .word 0xfe220018 // 00102A70:  sd $v0, 0x18($s1)
    .word 0x2666ffff // 00102A74:  addiu $a2, $s3, -1
    .word 0x0050001a // 00102A78:  div $zero, $v0, $s0
    .word 0x0006333c // 00102A7C:  dsll32 $a2, $a2, 0xc
    .word 0x26450024 // 00102A80:  addiu $a1, $s2, 0x24
    .word 0x52000001 // 00102A84:  beql $s0, $zero, 0x102a8c
    .word 0x000001cd // 00102A88:  break 0, 7
    .word 0x30a50fff // 00102A8C:  andi $a1, $a1, 0xfff
    .word 0x00052b38 // 00102A90:  dsll $a1, $a1, 0xc
    .word 0x00001012 // 00102A94:  mflo $v0
    .word 0x02823818 // 00102A98:  .word
    .word 0x70502018 // 00102A9C:  .word
    .word 0x2442ffff // 00102AA0:  addiu $v0, $v0, -1
    .word 0x64e30290 // 00102AA4:  daddiu $v1, $a3, 0x290
    .word 0x000215f8 // 00102AA8:  dsll $v0, $v0, 0x17
    .word 0x30630fff // 00102AAC:  andi $v1, $v1, 0xfff
    .word 0x2484ffff // 00102AB0:  addiu $a0, $a0, -1
    .word 0x00661825 // 00102AB4:  or $v1, $v1, $a2
    .word 0x0004203c // 00102AB8:  dsll32 $a0, $a0, 0
    .word 0x00441025 // 00102ABC:  or $v0, $v0, $a0
    .word 0x00431025 // 00102AC0:  or $v0, $v0, $v1
    .word 0x00451025 // 00102AC4:  or $v0, $v0, $a1
    .word 0x10000003 // 00102AC8:  b 0x102ad8
    .word 0xfe220018 // 00102ACC:  sd $v0, 0x18($s1)
    .word 0x0c046378 // 00102AD0:  jal 0x118de0
    .word 0x2484d3e8 // 00102AD4:  addiu $a0, $a0, -0x2c18
    .word 0xfe200020 // 00102AD8:  sd $zero, 0x20($s1)
    .word 0xdfbf0060 // 00102ADC:  ld $ra, 0x60($sp)
    .word 0xdfb50050 // 00102AE0:  ld $s5, 0x50($sp)
    .word 0xdfb40040 // 00102AE4:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 00102AE8:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 00102AEC:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 00102AF0:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 00102AF4:  ld $s0, ($sp)
    .word 0x03e00008 // 00102AF8:  jr $ra
    .word 0x27bd0070 // 00102AFC:  addiu $sp, $sp, 0x70
}
#else
void func_00102890(sceGsDispEnv *env, s16 psm, s16 w, s16 h, s16 dx, s16 dy) {
    GsModeInfo *mode = func_00102818();
    env->pmode = 0x66;

    if (mode->field_0 == 0) {
        env->smode2 = 2;
    } else if (mode->field_4 != 0) {
        env->smode2 = 3;
    } else {
        env->smode2 = 1;
    }

    env->dispfb = ((u64)(psm & 0xF) << 15) | ((u64)(((w + 0x3F) >> 6) & 0x3F) << 9);

    if (mode->field_2 == 2) {
        u64 dw = 0x9FF / w - 1;
        u64 v_dx = (u64)(dy + 0x32) & 0xFFF;
        u64 v_a1 = (u64)(dx + 0x27C) & 0xFFF;
        u64 dh;
        if (mode->field_4 == 0) {
            dh = (u64)(h - 1);
        } else {
            dh = (u64)(2 * h - 1);
        }
        env->display = (dw << 23) | ((u64)1 << 32) | (dh << 44) | v_a1 | (v_dx << 12);
    } else if (mode->field_2 == 3) {
        u64 dw = 0x9FF / w - 1;
        u64 v_dx = (u64)(dy + 0x48) & 0xFFF;
        u64 v_a1 = (u64)(dx + 0x290) & 0xFFF;
        u64 dh;
        if (mode->field_4 == 0) {
            dh = (u64)(h - 1);
        } else {
            dh = (u64)(2 * h - 1);
        }
        env->display = (dw << 23) | ((u64)1 << 32) | (dh << 44) | v_a1 | (v_dx << 12);
    } else {
        func_118de0(D_0048D3E8, mode->field_2);
    }

    env->pad = 0;
}
#endif

}
