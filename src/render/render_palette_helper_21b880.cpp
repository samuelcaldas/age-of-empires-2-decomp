#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

/* 0x0021B880 */
extern "C" {
void *func_0021B830(void *manager);

asm int func_0021B880(void *manager, void *config, void **out_viewport, int unused, void *extra_ptr) {
    .word 0x27BDFF80 /* addiu      $sp, $sp, -0x80 */
    .word 0x7FBF0070 /* sq         $ra, 0x70($sp) */
    .word 0x7FB60060 /* sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x8CB10004 /* lw         $s1, 0x4($a1) */
    .word 0x70A0AE28 /* paddub     $s5, $a1, $zero */
    .word 0x70C0A628 /* paddub     $s4, $a2, $zero */
    .word 0x71009E28 /* paddub     $s3, $t0, $zero */
    .word 0x7080B628 /* paddub     $s6, $a0, $zero */
    .word 0x26B00068 /* addiu      $s0, $s5, 0x68 */
    jal func_0021B830
    .word 0x70009628 /* paddub     $s2, $zero, $zero */
    .word 0x14400004 /* bnez       $v0, .L0021B8D8 */
    .word 0x3C038080 /* lui        $v1, (0x80808080 >> 16) */
    .word 0x10000077 /* b          .L0021BAAC */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x3C038080 /* lui        $v1, (0x80808080 >> 16) */
    .word 0x34638080 /* ori        $v1, $v1, (0x80808080 & 0xFFFF) */
    .word 0x24450030 /* addiu      $a1, $v0, 0x30 */
    .word 0x2404001B /* addiu      $a0, $zero, 0x1B */
    .word 0xAC430028 /* sw         $v1, 0x28($v0) */
    .word 0x72A03628 /* paddub     $a2, $s5, $zero */
    .word 0x8CC30000 /* lw         $v1, 0x0($a2) */
    .word 0x2484FFFF /* addiu      $a0, $a0, -0x1 */
    .word 0xACA30000 /* sw         $v1, 0x0($a1) */
    .word 0x24C60004 /* addiu      $a2, $a2, 0x4 */
    .word 0x1C80FFFB /* bgtz       $a0, .L0021B8EC */
    .word 0x24A50004 /* addiu      $a1, $a1, 0x4 */
    .word 0x0011183C /* dsll32     $v1, $s1, 0 */
    .word 0x0003183E /* dsrl32     $v1, $v1, 0 */
    .word 0x30640004 /* andi       $a0, $v1, 0x4 */
    .word 0x10800007 /* beqz       $a0, .L0021B930 */
    .word 0x30640002 /* andi       $a0, $v1, 0x2 */
    .word 0x8C450004 /* lw         $a1, 0x4($v0) */
    .word 0x8EA4000C /* lw         $a0, 0xC($s5) */
    .word 0x00A42021 /* addu       $a0, $a1, $a0 */
    .word 0x2484FFFF /* addiu      $a0, $a0, -0x1 */
    .word 0xAC44000C /* sw         $a0, 0xC($v0) */
    .word 0x30640002 /* andi       $a0, $v1, 0x2 */
    .word 0x10800007 /* beqz       $a0, .L0021B950 */
    .word 0x30640001 /* andi       $a0, $v1, 0x1 */
    .word 0x8C450008 /* lw         $a1, 0x8($v0) */
    .word 0x8EA40008 /* lw         $a0, 0x8($s5) */
    .word 0x00A42021 /* addu       $a0, $a1, $a0 */
    .word 0x2484FFFF /* addiu      $a0, $a0, -0x1 */
    .word 0xAC440010 /* sw         $a0, 0x10($v0) */
    .word 0x30640001 /* andi       $a0, $v1, 0x1 */
    .word 0x5080001C /* beql       $a0, $zero, .L0021B9C4 */
    .word 0x30631000 /* andi       $v1, $v1, 0x1000 */
    .word 0x9E040000 /* lwu        $a0, 0x0($s0) */
    .word 0x30840200 /* andi       $a0, $a0, 0x200 */
    .word 0x10800017 /* beqz       $a0, .L0021B9C0 */
    .word 0x00000000 /* nop */
    .word 0xAE820000 /* sw         $v0, 0x0($s4) */
    .word 0x2404027F /* addiu      $a0, $zero, 0x27F */
    .word 0xAC400004 /* sw         $zero, 0x4($v0) */
    .word 0xAC44000C /* sw         $a0, 0xC($v0) */
    .word 0x240401FF /* addiu      $a0, $zero, 0x1FF */
    .word 0xAC400008 /* sw         $zero, 0x8($v0) */
    .word 0xAC440010 /* sw         $a0, 0x10($v0) */
    .word 0x24040280 /* addiu      $a0, $zero, 0x280 */
    .word 0xAC44003C /* sw         $a0, 0x3C($v0) */
    .word 0x24040200 /* addiu      $a0, $zero, 0x200 */
    .word 0xAC440038 /* sw         $a0, 0x38($v0) */
    .word 0x24040010 /* addiu      $a0, $zero, 0x10 */
    .word 0xAC440084 /* sw         $a0, 0x84($v0) */
    .word 0x24040002 /* addiu      $a0, $zero, 0x2 */
    .word 0xAC44001C /* sw         $a0, 0x1C($v0) */
    .word 0x24040001 /* addiu      $a0, $zero, 0x1 */
    .word 0xAC440044 /* sw         $a0, 0x44($v0) */
    .word 0xAC400054 /* sw         $zero, 0x54($v0) */
    .word 0x8C440098 /* lw         $a0, 0x98($v0) */
    .word 0x34844000 /* ori        $a0, $a0, 0x4000 */
    .word 0xAC440098 /* sw         $a0, 0x98($v0) */
    .word 0xAEC20420 /* sw         $v0, 0x420($s6) */
    .word 0x30631000 /* andi       $v1, $v1, 0x1000 */
    .word 0x10600029 /* beqz       $v1, .L0021BA6C */
    .word 0x00000000 /* nop */
    .word 0x9EA4004C /* lwu        $a0, 0x4C($s5) */
    .word 0x30830040 /* andi       $v1, $a0, 0x40 */
    .word 0x10600004 /* beqz       $v1, .L0021B9E8 */
    .word 0x30830020 /* andi       $v1, $a0, 0x20 */
    .word 0x8EB20054 /* lw         $s2, 0x54($s5) */
    .word 0x00000000 /* nop */
    .word 0x30830020 /* andi       $v1, $a0, 0x20 */
    .word 0x10600004 /* beqz       $v1, .L0021B9FC */
    .word 0x30830008 /* andi       $v1, $a0, 0x8 */
    .word 0x24120008 /* addiu      $s2, $zero, 0x8 */
    .word 0xAC520084 /* sw         $s2, 0x84($v0) */
    .word 0x30830008 /* andi       $v1, $a0, 0x8 */
    .word 0x10600004 /* beqz       $v1, .L0021BA10 */
    .word 0x24040002 /* addiu      $a0, $zero, 0x2 */
    .word 0x24120004 /* addiu      $s2, $zero, 0x4 */
    .word 0xAC520084 /* sw         $s2, 0x84($v0) */
    .word 0x24040002 /* addiu      $a0, $zero, 0x2 */
    .word 0x24030020 /* addiu      $v1, $zero, 0x20 */
    .word 0x12430014 /* beq        $s2, $v1, .L0021BA68 */
    .word 0xAC44001C /* sw         $a0, 0x1C($v0) */
    .word 0x24030010 /* addiu      $v1, $zero, 0x10 */
    .word 0x1243000F /* beq        $s2, $v1, .L0021BA60 */
    .word 0x00000000 /* nop */
    .word 0x24030008 /* addiu      $v1, $zero, 0x8 */
    .word 0x1243000A /* beq        $s2, $v1, .L0021BA58 */
    .word 0x24030013 /* addiu      $v1, $zero, 0x13 */
    .word 0x24030004 /* addiu      $v1, $zero, 0x4 */
    .word 0x12430004 /* beq        $s2, $v1, .L0021BA4C */
    .word 0x24030014 /* addiu      $v1, $zero, 0x14 */
    .word 0x1000000B /* b          .L0021BA70 */
    .word 0x9E030000 /* lwu        $v1, 0x0($s0) */
    .word 0x24030014 /* addiu      $v1, $zero, 0x14 */
    .word 0x10000007 /* b          .L0021BA6C */
    .word 0xAC43001C /* sw         $v1, 0x1C($v0) */
    .word 0x24030013 /* addiu      $v1, $zero, 0x13 */
    .word 0x10000004 /* b          .L0021BA6C */
    .word 0xAC43001C /* sw         $v1, 0x1C($v0) */
    .word 0x10000002 /* b          .L0021BA6C */
    .word 0xAC44001C /* sw         $a0, 0x1C($v0) */
    .word 0xAC40001C /* sw         $zero, 0x1C($v0) */
    .word 0x9E030000 /* lwu        $v1, 0x0($s0) */
    .word 0x30630200 /* andi       $v1, $v1, 0x200 */
    .word 0x14600002 /* bnez       $v1, .L0021BA80 */
    .word 0x00000000 /* nop */
    .word 0xAC530054 /* sw         $s3, 0x54($v0) */
    .word 0x8C45003C /* lw         $a1, 0x3C($v0) */
    .word 0x8C430084 /* lw         $v1, 0x84($v0) */
    .word 0x2404FFFC /* addiu      $a0, $zero, -0x4 */
    .word 0x24A50003 /* addiu      $a1, $a1, 0x3 */
    .word 0x00A42024 /* and        $a0, $a1, $a0 */
    .word 0x00831818 /* mult       $v1, $a0, $v1 */
    .word 0x000318C2 /* srl        $v1, $v1, 3 */
    .word 0xAC430040 /* sw         $v1, 0x40($v0) */
    .word 0xAC560018 /* sw         $s6, 0x18($v0) */
    .word 0xAE820000 /* sw         $v0, 0x0($s4) */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x7BBF0070 /* lq         $ra, 0x70($sp) */
    .word 0x7BB60060 /* lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0080 /* addiu      $sp, $sp, 0x80 */
}
}

#else

extern "C" {
void *func_0021B830(void *manager);

static void CopyConfigWords(void *viewport, void *config) {
    int *src = (int *)config;
    int *dst = (int *)((char *)viewport + 48);
    for (int i = 0; i < 27; ++i) {
        dst[i] = src[i];
    }
}

static void ApplyConfigRect(void *viewport, void *config, int flags) {
    char *vp = (char *)viewport;
    char *cfg = (char *)config;

    if (flags & 4) {
        int x1 = *(int *)(vp + 4);
        int w = *(int *)(cfg + 12);
        *(int *)(vp + 12) = x1 + w - 1;
    }

    if (flags & 2) {
        int y1 = *(int *)(vp + 8);
        int h = *(int *)(cfg + 8);
        *(int *)(vp + 16) = y1 + h - 1;
    }
}

static void ApplyFullscreenOverride(void *viewport, void *manager) {
    char *vp = (char *)viewport;
    *(int *)(vp + 4) = 0;
    *(int *)(vp + 12) = 639;
    *(int *)(vp + 8) = 0;
    *(int *)(vp + 16) = 511;
    *(int *)(vp + 60) = 640;
    *(int *)(vp + 56) = 512;
    *(int *)(vp + 132) = 16;
    *(int *)(vp + 28) = 2;
    *(int *)(vp + 68) = 1;
    *(int *)(vp + 84) = 0;
    *(int *)(vp + 152) |= 0x4000;
    *(void **)((char *)manager + 1056) = viewport;
}

static int ResolveFormatCode(int bpp) {
    if (bpp == 32) {
        return 0;
    }
    if (bpp == 16) {
        return 2;
    }
    if (bpp == 8) {
        return 19;
    }
    if (bpp == 4) {
        return 20;
    }
    return 2;
}

static void ApplyPixelFormat(void *viewport, void *config) {
    char *vp = (char *)viewport;
    char *cfg = (char *)config;
    unsigned short flags_76 = *(unsigned short *)(cfg + 76);
    int bpp = 0;

    if (flags_76 & 0x40) {
        bpp = *(int *)(cfg + 84);
    }
    if (flags_76 & 0x20) {
        bpp = 8;
        *(int *)(vp + 132) = 8;
    }
    if (flags_76 & 0x8) {
        bpp = 4;
        *(int *)(vp + 132) = 4;
    }

    *(int *)(vp + 28) = ResolveFormatCode(bpp);
}

int func_0021B880(void *manager, void *config, void **out_viewport, int unused, void *extra_ptr) {
    int flags = *(int *)((char *)config + 4);
    void *viewport = func_0021B830(manager);
    if (viewport == 0) {
        return 1;
    }

    char *vp = (char *)viewport;
    *(int *)(vp + 40) = (int)0x80808080;
    CopyConfigWords(viewport, config);
    ApplyConfigRect(viewport, config, flags);

    unsigned short flags_68 = *(unsigned short *)((char *)config + 104);
    if ((flags & 1) && (flags_68 & 0x200)) {
        *out_viewport = viewport;
        ApplyFullscreenOverride(viewport, manager);
    }

    if (flags & 0x1000) {
        ApplyPixelFormat(viewport, config);
    }

    if (!(flags_68 & 0x200)) {
        *(void **)(vp + 84) = extra_ptr;
    }

    int bpp = *(int *)(vp + 132);
    *(int *)(vp + 64) = bpp >> 3;
    *(void **)(vp + 24) = manager;
    *out_viewport = viewport;

    return 0;
}
}

#endif
