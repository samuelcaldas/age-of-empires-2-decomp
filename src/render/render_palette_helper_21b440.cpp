#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

/* 0x0021B440 */
extern "C" {
int func_0021B560(void *palette_obj, const char *palette_data);
int func_0021DE90(int a0, int a1, int a2, void *clut_buf, int t0, int t1, int t2, int t3);

asm int func_0021B440(void *palette_obj, int unused, int start_idx, int count, void *dst_buf) {
    .word 0x11000019 /* beqz       $t0, .L0021B4A8 */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x00C75821 /* addu       $t3, $a2, $a3 */
    .word 0x10000010 /* b          .L0021B490 */
    .word 0x70005628 /* paddub     $t2, $zero, $zero */
    .word 0x8C830004 /* lw         $v1, 0x4($a0) */
    .word 0x000A1080 /* sll        $v0, $t2, 2 */
    .word 0x00062880 /* sll        $a1, $a2, 2 */
    .word 0x01024821 /* addu       $t1, $t0, $v0 */
    .word 0x24C60001 /* addiu      $a2, $a2, 0x1 */
    .word 0x00651021 /* addu       $v0, $v1, $a1 */
    .word 0x90470000 /* lbu        $a3, 0x0($v0) */
    .word 0x90450001 /* lbu        $a1, 0x1($v0) */
    .word 0x90430002 /* lbu        $v1, 0x2($v0) */
    .word 0x254A0001 /* addiu      $t2, $t2, 0x1 */
    .word 0x90420003 /* lbu        $v0, 0x3($v0) */
    .word 0xA1270000 /* sb         $a3, 0x0($t1) */
    .word 0xA1250001 /* sb         $a1, 0x1($t1) */
    .word 0xA1230002 /* sb         $v1, 0x2($t1) */
    .word 0xA1220003 /* sb         $v0, 0x3($t1) */
    .word 0x00CB102B /* sltu       $v0, $a2, $t3 */
    .word 0x1440FFEF /* bnez       $v0, .L0021B454 */
    .word 0x00000000 /* nop */
    .word 0x10000005 /* b          .L0021B4B4 */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x10000002 /* b          .L0021B4B4 */
    .word 0x00000000 /* nop */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* jr         $ra */
    .word 0x00000000 /* nop */
}

asm int func_0021B4C0(void *palette_obj, int unused, int start_idx, int count, void *src_buf, int trans_idx) {
    .word 0x27BDFFF0 /* addiu      $sp, $sp, -0x10 */
    .word 0x11000020 /* beqz       $t0, .L0021B548 */
    .word 0x7FBF0000 /* sq         $ra, 0x0($sp) */
    .word 0x24030080 /* addiu      $v1, $zero, 0x80 */
    .word 0x10000018 /* b          .L0021B534 */
    .word 0x70006E28 /* paddub     $t5, $zero, $zero */
    .word 0x000D1080 /* sll        $v0, $t5, 2 */
    .word 0x01021021 /* addu       $v0, $t0, $v0 */
    .word 0x8C8C0004 /* lw         $t4, 0x4($a0) */
    .word 0x904B0000 /* lbu        $t3, 0x0($v0) */
    .word 0x904A0001 /* lbu        $t2, 0x1($v0) */
    .word 0x90450002 /* lbu        $a1, 0x2($v0) */
    .word 0x00067080 /* sll        $t6, $a2, 2 */
    .word 0x018E6021 /* addu       $t4, $t4, $t6 */
    .word 0x90420003 /* lbu        $v0, 0x3($v0) */
    .word 0xA18B0000 /* sb         $t3, 0x0($t4) */
    .word 0xA18A0001 /* sb         $t2, 0x1($t4) */
    .word 0xA1850002 /* sb         $a1, 0x2($t4) */
    .word 0x14C90005 /* bne        $a2, $t1, .L0021B520 */
    .word 0xA1820003 /* sb         $v0, 0x3($t4) */
    .word 0x8C820004 /* lw         $v0, 0x4($a0) */
    .word 0x004E1021 /* addu       $v0, $v0, $t6 */
    .word 0x10000004 /* b          .L0021B52C */
    .word 0xA0400003 /* sb         $zero, 0x3($v0) */
    .word 0x8C820004 /* lw         $v0, 0x4($a0) */
    .word 0x004E1021 /* addu       $v0, $v0, $t6 */
    .word 0xA0430003 /* sb         $v1, 0x3($v0) */
    .word 0x24C60001 /* addiu      $a2, $a2, 0x1 */
    .word 0x25AD0001 /* addiu      $t5, $t5, 0x1 */
    .word 0x01A7102B /* sltu       $v0, $t5, $a3 */
    .word 0x1440FFE8 /* bnez       $v0, .L0021B4DC */
    .word 0x000D1080 /* sll        $v0, $t5, 2 */
    jal func_0021B560
    .word 0x8C850004 /* lw         $a1, 0x4($a0) */
    .word 0x7BBF0000 /* lq         $ra, 0x0($sp) */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0010 /* addiu      $sp, $sp, 0x10 */
}

asm int func_0021B560(void *palette_obj, const char *palette_data) {
    .word 0x10A00021 /* beqz       $a1, .L0021B5E8 */
    .word 0x00000000 /* nop */
    .word 0x3C0200C6 /* lui        $v0, 0xC6 */
    .word 0x2449DF00 /* addiu      $t1, $v0, -0x2100 */
    .word 0x1000001A /* b          .L0021B5DC */
    .word 0x70005628 /* paddub     $t2, $zero, $zero */
    .word 0x000A1142 /* srl        $v0, $t2, 5 */
    .word 0x00021940 /* sll        $v1, $v0, 5 */
    .word 0x000A1102 /* srl        $v0, $t2, 4 */
    .word 0x30420001 /* andi       $v0, $v0, 0x1 */
    .word 0x000210C0 /* sll        $v0, $v0, 3 */
    .word 0x00621821 /* addu       $v1, $v1, $v0 */
    .word 0x000A10C2 /* srl        $v0, $t2, 3 */
    .word 0x30420001 /* andi       $v0, $v0, 0x1 */
    .word 0x00021100 /* sll        $v0, $v0, 4 */
    .word 0x00431821 /* addu       $v1, $v0, $v1 */
    .word 0x31420007 /* andi       $v0, $t2, 0x7 */
    .word 0x00431021 /* addu       $v0, $v0, $v1 */
    .word 0x00021080 /* sll        $v0, $v0, 2 */
    .word 0x01224021 /* addu       $t0, $t1, $v0 */
    .word 0x000A1080 /* sll        $v0, $t2, 2 */
    .word 0x00A21021 /* addu       $v0, $a1, $v0 */
    .word 0x90470000 /* lbu        $a3, 0x0($v0) */
    .word 0x90460001 /* lbu        $a2, 0x1($v0) */
    .word 0x90430002 /* lbu        $v1, 0x2($v0) */
    .word 0x254A0001 /* addiu      $t2, $t2, 0x1 */
    .word 0x90420003 /* lbu        $v0, 0x3($v0) */
    .word 0xA1070000 /* sb         $a3, 0x0($t0) */
    .word 0xA1060001 /* sb         $a2, 0x1($t0) */
    .word 0xA1030002 /* sb         $v1, 0x2($t0) */
    .word 0xA1020003 /* sb         $v0, 0x3($t0) */
    .word 0x29420100 /* slti       $v0, $t2, 0x100 */
    .word 0x1440FFE6 /* bnez       $v0, .L0021B57C */
    .word 0x000A1142 /* srl        $v0, $t2, 5 */
    .word 0x94830002 /* lhu        $v1, 0x2($a0) */
    .word 0x3C0200C6 /* lui        $v0, 0xC6 */
    .word 0x240A0010 /* addiu      $t2, $zero, 0x10 */
    .word 0x2447DF00 /* addiu      $a3, $v0, -0x2100 */
    .word 0x00032103 /* sra        $a0, $v1, 4 */
    .word 0x00041082 /* srl        $v0, $a0, 2 */
    .word 0x00021940 /* sll        $v1, $v0, 5 */
    .word 0x30820001 /* andi       $v0, $a0, 0x1 */
    .word 0x00021100 /* sll        $v0, $v0, 4 */
    .word 0x00621821 /* addu       $v1, $v1, $v0 */
    .word 0x30820002 /* andi       $v0, $a0, 0x2 */
    .word 0x000210C0 /* sll        $v0, $v0, 3 */
    .word 0x0003443C /* dsll32     $t0, $v1, 16 */
    .word 0x00024C3C /* dsll32     $t1, $v0, 16 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    .word 0x24041F00 /* addiu      $a0, $zero, 0x1F00 */
    .word 0x70002E28 /* paddub     $a1, $zero, $zero */
    .word 0x0008443F /* dsra32     $t0, $t0, 16 */
    .word 0x00094C3F /* dsra32     $t1, $t1, 16 */
    j func_0021DE90
    .word 0x71405E28 /* paddub     $t3, $t2, $zero */
}
}

#else

extern "C" {
extern char D_00C5DF00[1024];

int func_0021DE90(int a0, int a1, int a2, void *clut_buf, int t0, int t1, int t2, int t3);

int func_0021B440(void *palette_obj, int unused, int start_idx, int count, void *dst_buf) {
    if (dst_buf == 0) {
        return 1;
    }

    char *palette_data = *(char **)((char *)palette_obj + 4);
    char *dst = (char *)dst_buf;
    int end_idx = start_idx + count;

    int i = 0;
    while (start_idx < end_idx) {
        char *src = palette_data + start_idx * 4;
        char *out = dst + i * 4;
        out[0] = src[0];
        out[1] = src[1];
        out[2] = src[2];
        out[3] = src[3];
        start_idx++;
        i++;
    }

    return 0;
}

int func_0021B560(void *palette_obj, const char *palette_data) {
    if (palette_data == 0) {
        return 0;
    }

    for (int i = 0; i < 256; i++) {
        int swizzled_idx = ((i >> 5) << 5) | (((i >> 4) & 1) << 3) | (((i >> 3) & 1) << 4) | (i & 7);
        const char *src = palette_data + i * 4;
        char *dst = D_00C5DF00 + swizzled_idx * 4;
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
    }

    unsigned short clut_offset = *(unsigned short *)((char *)palette_obj + 2);
    int clut_base = clut_offset >> 4;
    int v1 = ((clut_base >> 2) << 5) | ((clut_base & 1) << 4);
    int v0 = (clut_base & 2) << 3;

    int t0 = (short)v1;
    int t1 = (short)v0;

    return func_0021DE90(0x1F00, 0, 4, D_00C5DF00, t0, t1, 0, 16);
}

int func_0021B4C0(void *palette_obj, int unused, int start_idx, int count, void *src_buf, int trans_idx) {
    if (src_buf == 0) {
        return 0;
    }

    char *palette_data = *(char **)((char *)palette_obj + 4);
    const char *src = (const char *)src_buf;

    for (int i = 0; i < count; i++) {
        const char *in_col = src + i * 4;
        char *dst_col = palette_data + start_idx * 4;

        dst_col[0] = in_col[0];
        dst_col[1] = in_col[1];
        dst_col[2] = in_col[2];

        if (start_idx == trans_idx) {
            dst_col[3] = 0;
        }
        if (start_idx != trans_idx) {
            dst_col[3] = (char)0x80;
        }

        start_idx++;
    }

    func_0021B560(palette_obj, palette_data);
    return 0;
}
}

#endif
