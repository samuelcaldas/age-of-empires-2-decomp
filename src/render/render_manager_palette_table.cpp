#pragma exceptions off
#pragma divbyzerocheck on
#pragma inline_depth(8)

#if defined(__mips__)

extern "C" {
int func_226D90(void *stream, void *dst, int size);
void *func_100730(int size);
int func_0021BC30(const void *arg0, void *buf, int arg2, int capacity, int arg4);
void *func_117AF8(void *dst, const void *src, int len);
void func_1AE350(void *sub, void *dest_palette);
void func_00189260(const unsigned char *source, unsigned char *destination, void *color, int percent, int skip_first, int skip_second);
void func_100630(void *ptr);
void func_100670(void *ptr);

void *__ct__18RenderPaletteTableFPv(void *this_ptr, void *stream);
void *__ct__18RenderPaletteTableFP8SubObj6CiPC18RenderPaletteColorPCUc(void *this_ptr, void *sub, int percent, const void *color, const unsigned char *palette);
void *__dt__18RenderPaletteTableFv(void *this_ptr, int flag);

asm void *__ct__18RenderPaletteTableFPv(void *this_ptr, void *stream) {
    .word 0x27BDFFD0 /* addiu      $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* sq         $ra, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x3C02004D /* lui        $v0, 0x4D */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x24427EE8 /* addiu      $v0, $v0, (0x4D7EE8 & 0xFFFF) */
    .word 0x70808628 /* paddub     $s0, $a0, $zero */
    .word 0x70A08E28 /* paddub     $s1, $a1, $zero */
    .word 0xAC820034 /* sw         $v0, 0x34($a0) */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    .word 0x72202628 /* paddub     $a0, $s1, $zero */
    jal func_226D90
    .word 0x72002E28 /* paddub    $a1, $s0, $zero */
    .word 0x26050008 /* addiu      $a1, $s0, 0x8 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal func_226D90
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x2605000C /* addiu      $a1, $s0, 0xC */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal func_226D90
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x26050010 /* addiu      $a1, $s0, 0x10 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal func_226D90
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x26050014 /* addiu      $a1, $s0, 0x14 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal func_226D90
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x26050018 /* addiu      $a1, $s0, 0x18 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal func_226D90
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x2605001C /* addiu      $a1, $s0, 0x1C */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal func_226D90
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x26050020 /* addiu      $a1, $s0, 0x20 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal func_226D90
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x26050024 /* addiu      $a1, $s0, 0x24 */
    .word 0x24060004 /* addiu      $a2, $zero, 0x4 */
    jal func_226D90
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0xAE000004 /* sw         $zero, 0x4($s0) */
    .word 0x8E030000 /* lw         $v1, 0x0($s0) */
    .word 0x2402000A /* addiu      $v0, $zero, 0xA */
    .word 0x14620011 /* bne        $v1, $v0, .L00189588 */
    .word 0x00000000 /* nop */
    jal func_100730
    .word 0x24040100 /* addiu     $a0, $zero, 0x100 */
    .word 0xAE020004 /* sw         $v0, 0x4($s0) */
    .word 0x3C020039 /* lui        $v0, 0x39 */
    .word 0x244421F4 /* addiu      $a0, $v0, (0x3921F4 & 0xFFFF) */
    .word 0x3C0201ED /* lui        $v0, (0x1ED7000 >> 16) */
    .word 0x24070100 /* addiu      $a3, $zero, 0x100 */
    .word 0x24080001 /* addiu      $t0, $zero, 0x1 */
    .word 0x34457000 /* ori        $a1, $v0, (0x1ED7000 & 0xFFFF) */
    jal func_0021BC30
    .word 0x70003628 /* paddub    $a2, $zero, $zero */
    .word 0x8E040004 /* lw         $a0, 0x4($s0) */
    .word 0x3C0201ED /* lui        $v0, (0x1ED7000 >> 16) */
    .word 0x24060100 /* addiu      $a2, $zero, 0x100 */
    jal func_117AF8
    .word 0x34457000 /* ori       $a1, $v0, (0x1ED7000 & 0xFFFF) */
    .word 0xAE000028 /* sw         $zero, 0x28($s0) */
    .word 0xAE00002C /* sw         $zero, 0x2C($s0) */
    .word 0xA2000030 /* sb         $zero, 0x30($s0) */
    .word 0xA2000031 /* sb         $zero, 0x31($s0) */
    .word 0xA2000032 /* sb         $zero, 0x32($s0) */
    .word 0xA2000033 /* sb         $zero, 0x33($s0) */
    .word 0x72001628 /* paddub     $v0, $s0, $zero */
    .word 0x7BBF0020 /* lq         $ra, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0030 /* addiu     $sp, $sp, 0x30 */
}

asm void *__ct__18RenderPaletteTableFP8SubObj6CiPC18RenderPaletteColorPCUc(void *this_ptr, void *sub, int percent, const void *color, const unsigned char *palette) {
    .word 0x27BDF7A0 /* addiu      $sp, $sp, -0x860 */
    .word 0x7FBF0040 /* sq         $ra, 0x40($sp) */
    .word 0x7FB20030 /* sq         $s2, 0x30($sp) */
    .word 0x7FB10020 /* sq         $s1, 0x20($sp) */
    .word 0x3C02004D /* lui        $v0, 0x4D */
    .word 0x7FB00010 /* sq         $s0, 0x10($sp) */
    .word 0x24427EE8 /* addiu      $v0, $v0, (0x4D7EE8 & 0xFFFF) */
    .word 0x70C08E28 /* paddub     $s1, $a2, $zero */
    .word 0x70E08628 /* paddub     $s0, $a3, $zero */
    .word 0x70809628 /* paddub     $s2, $a0, $zero */
    .word 0x15000006 /* bnez       $t0, .L00189604 */
    .word 0xAC820034 /* sw        $v0, 0x34($a0) */
    .word 0x70A02628 /* paddub     $a0, $a1, $zero */
    jal func_1AE350
    .word 0x27A50450 /* addiu     $a1, $sp, 0x450 */
    .word 0x10000013 /* b          .L0018964C */
    .word 0x00000000 /* nop */
    .word 0x1000000E /* b          .L00189640 */
    .word 0x70002628 /* paddub    $a0, $zero, $zero */
    .word 0x00041080 /* sll        $v0, $a0, 2 */
    .word 0x01022821 /* addu       $a1, $t0, $v0 */
    .word 0x90A30000 /* lbu        $v1, 0x0($a1) */
    .word 0x005D1021 /* addu       $v0, $v0, $sp */
    .word 0x24460450 /* addiu      $a2, $v0, 0x450 */
    .word 0x24840001 /* addiu      $a0, $a0, 0x1 */
    .word 0xA0C30000 /* sb         $v1, 0x0($a2) */
    .word 0x90A20001 /* lbu        $v0, 0x1($a1) */
    .word 0xA0C20001 /* sb         $v0, 0x1($a2) */
    .word 0x90A20002 /* lbu        $v0, 0x2($a1) */
    .word 0xA0C20002 /* sb         $v0, 0x2($a2) */
    .word 0x90A20003 /* lbu        $v0, 0x3($a1) */
    .word 0xA0C20003 /* sb         $v0, 0x3($a2) */
    .word 0x28810100 /* slti       $at, $a0, 0x100 */
    .word 0x1420FFF2 /* bnez       $at, .L00189610 */
    .word 0x00041080 /* sll       $v0, $a0, 2 */
    .word 0x16000006 /* bnez       $s0, .L00189668 */
    .word 0x00000000 /* nop */
    .word 0xA3A0085C /* sb         $zero, 0x85C($sp) */
    .word 0xA3A0085E /* sb         $zero, 0x85E($sp) */
    .word 0xA3A0085D /* sb         $zero, 0x85D($sp) */
    .word 0x10000009 /* b          .L00189688 */
    .word 0xA3A0085F /* sb        $zero, 0x85F($sp) */
    .word 0x92020000 /* lbu        $v0, 0x0($s0) */
    .word 0xA3A2085C /* sb         $v0, 0x85C($sp) */
    .word 0x92020002 /* lbu        $v0, 0x2($s0) */
    .word 0xA3A2085E /* sb         $v0, 0x85E($sp) */
    .word 0x92020001 /* lbu        $v0, 0x1($s0) */
    .word 0xA3A2085D /* sb         $v0, 0x85D($sp) */
    .word 0x92020003 /* lbu        $v0, 0x3($s0) */
    .word 0xA3A2085F /* sb         $v0, 0x85F($sp) */
    .word 0x2402FFFF /* addiu      $v0, $zero, -0x1 */
    .word 0xAE420000 /* sw         $v0, 0x0($s2) */
    .word 0xAE420008 /* sw         $v0, 0x8($s2) */
    .word 0xAE42000C /* sw         $v0, 0xC($s2) */
    .word 0xAE420010 /* sw         $v0, 0x10($s2) */
    .word 0xAE420014 /* sw         $v0, 0x14($s2) */
    .word 0xAE420018 /* sw         $v0, 0x18($s2) */
    .word 0xAE42001C /* sw         $v0, 0x1C($s2) */
    .word 0xAE420020 /* sw         $v0, 0x20($s2) */
    .word 0xAE420024 /* sw         $v0, 0x24($s2) */
    .word 0xAE420028 /* sw         $v0, 0x28($s2) */
    .word 0xAE42002C /* sw         $v0, 0x2C($s2) */
    .word 0x240200FF /* addiu      $v0, $zero, 0xFF */
    .word 0xA2420030 /* sb         $v0, 0x30($s2) */
    .word 0xA2420031 /* sb         $v0, 0x31($s2) */
    .word 0xA2420032 /* sb         $v0, 0x32($s2) */
    .word 0x24040100 /* addiu      $a0, $zero, 0x100 */
    jal func_100730
    .word 0xA2420033 /* sb        $v0, 0x33($s2) */
    .word 0xAE420004 /* sw         $v0, 0x4($s2) */
    .word 0x8FA6085C /* lw         $a2, 0x85C($sp) */
    .word 0x2408FFFF /* addiu      $t0, $zero, -0x1 */
    .word 0x27A40450 /* addiu      $a0, $sp, 0x450 */
    .word 0x27A50050 /* addiu      $a1, $sp, 0x50 */
    .word 0x72203E28 /* paddub     $a3, $s1, $zero */
    jal func_00189260
    .word 0x71004E28 /* paddub    $t1, $t0, $zero */
    .word 0x10000026 /* b          .L00189790 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x00021880 /* sll        $v1, $v0, 2 */
    .word 0x007D1821 /* addu       $v1, $v1, $sp */
    .word 0x24630050 /* addiu      $v1, $v1, 0x50 */
    .word 0x90690000 /* lbu        $t1, 0x0($v1) */
    .word 0x906A0001 /* lbu        $t2, 0x1($v1) */
    .word 0x906B0002 /* lbu        $t3, 0x2($v1) */
    .word 0x24084E20 /* addiu      $t0, $zero, 0x4E20 */
    .word 0x70003628 /* paddub     $a2, $zero, $zero */
    .word 0x10000015 /* b          .L00189774 */
    .word 0x70003E28 /* paddub    $a3, $zero, $zero */
    .word 0x00071880 /* sll        $v1, $a3, 2 */
    .word 0x007D1821 /* addu       $v1, $v1, $sp */
    .word 0x24650450 /* addiu      $a1, $v1, 0x450 */
    .word 0x90A30000 /* lbu        $v1, 0x0($a1) */
    .word 0x90A40001 /* lbu        $a0, 0x1($a1) */
    .word 0x01231823 /* subu       $v1, $t1, $v1 */
    .word 0x00631818 /* mult       $v1, $v1, $v1 */
    .word 0x90A50002 /* lbu        $a1, 0x2($a1) */
    .word 0x01441823 /* subu       $v1, $t2, $a0 */
    .word 0x70632018 /* mult1      $a0, $v1, $v1 */
    .word 0x01651823 /* subu       $v1, $t3, $a1 */
    .word 0x00000000 /* nop */
    .word 0x70631801 /* maddu      $v1, $v1, $v1 */
    .word 0x00641821 /* addu       $v1, $v1, $a0 */
    .word 0x0068082A /* slt        $at, $v1, $t0 */
    .word 0x50200004 /* beql       $at, $zero, .L00189774 */
    .word 0x24E70001 /* addiu     $a3, $a3, 0x1 */
    .word 0x70604628 /* paddub     $t0, $v1, $zero */
    .word 0x70E03628 /* paddub     $a2, $a3, $zero */
    .word 0x24E70001 /* addiu      $a3, $a3, 0x1 */
    .word 0x28E10100 /* slti       $at, $a3, 0x100 */
    .word 0x1420FFEB /* bnez       $at, .L00189728 */
    .word 0x00071880 /* sll       $v1, $a3, 2 */
    .word 0x8E430004 /* lw         $v1, 0x4($s2) */
    .word 0x00621821 /* addu       $v1, $v1, $v0 */
    .word 0x24420001 /* addiu      $v0, $v0, 0x1 */
    .word 0xA0660000 /* sb         $a2, 0x0($v1) */
    .word 0x28410100 /* slti       $at, $v0, 0x100 */
    .word 0x1420FFDA /* bnez       $at, .L00189700 */
    .word 0x00021880 /* sll       $v1, $v0, 2 */
    .word 0x72401628 /* paddub     $v0, $s2, $zero */
    .word 0x7BBF0040 /* lq         $ra, 0x40($sp) */
    .word 0x7BB20030 /* lq         $s2, 0x30($sp) */
    .word 0x7BB10020 /* lq         $s1, 0x20($sp) */
    .word 0x7BB00010 /* lq         $s0, 0x10($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0860 /* addiu     $sp, $sp, 0x860 */
}

asm void *__dt__18RenderPaletteTableFv(void *this_ptr, int flag) {
    .word 0x27BDFFD0 /* addiu      $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* sq         $ra, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x70808E28 /* paddub     $s1, $a0, $zero */
    .word 0x12200010 /* beqz       $s1, .L00189818 */
    .word 0x70A08628 /* paddub    $s0, $a1, $zero */
    .word 0x3C02004D /* lui        $v0, 0x4D */
    .word 0x24427EE8 /* addiu      $v0, $v0, (0x4D7EE8 & 0xFFFF) */
    .word 0xAE220034 /* sw         $v0, 0x34($s1) */
    .word 0x8E240004 /* lw         $a0, 0x4($s1) */
    .word 0x10800005 /* beqz       $a0, .L00189804 */
    .word 0x0010143C /* dsll32    $v0, $s0, 16 */
    jal func_100630
    .word 0x00000000 /* nop */
    .word 0xAE200004 /* sw         $zero, 0x4($s1) */
    .word 0x0010143C /* dsll32     $v0, $s0, 16 */
    .word 0x0002143F /* dsra32     $v0, $v0, 16 */
    .word 0x18400004 /* blez       $v0, .L0018981C */
    .word 0x72201628 /* paddub    $v0, $s1, $zero */
    jal func_100670
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    .word 0x72201628 /* paddub     $v0, $s1, $zero */
    .word 0x7BBF0020 /* lq         $ra, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0030 /* addiu     $sp, $sp, 0x30 */
}
}

#else

#include "render_manager_palette_table.h"

extern "C" {
extern const unsigned char D_003921F4[];

int func_226D90(void *stream, void *dst, int size);
void *func_100730(int size);
void func_100630(void *ptr);
void func_100670(void *ptr);
int func_21BC30(const void *arg0, void *buf, int arg2, int capacity, int arg4);
void *func_117AF8(void *dst, const void *src, int len);
void func_1AE350(SubObj6C *sub, void *dest_palette);
void func_00189260(const unsigned char *source, unsigned char *destination,
                   RenderPaletteColor color, int percent,
                   int skip_first, int skip_second);
}

enum {
    PALETTE_COUNT = 256,
    PALETTE_ENTRY_BYTES = 4,
    PALETTE_BUFFER_BYTES = 1024,
    COLOR_DEFAULT_COMPONENT = 255,
    REMAP_MAX_DIST = 20000
};

RenderPaletteTable::RenderPaletteTable(void *stream) {
    func_226D90(stream, &field_0, 4);
    func_226D90(stream, &field_8, 4);
    func_226D90(stream, &field_C, 4);
    func_226D90(stream, &field_10, 4);
    func_226D90(stream, &field_14, 4);
    func_226D90(stream, &field_18, 4);
    func_226D90(stream, &field_1C, 4);
    func_226D90(stream, &field_20, 4);
    func_226D90(stream, &field_24, 4);
    table = 0;
    if (field_0 == 10) {
        table = static_cast<unsigned char *>(func_100730(PALETTE_COUNT));
        func_21BC30(D_003921F4, reinterpret_cast<void *>(0x01ED7000), 0, PALETTE_COUNT, 1);
        func_117AF8(table, reinterpret_cast<void *>(0x01ED7000), PALETTE_COUNT);
    }
    field_28 = 0;
    field_2C = 0;
    field_30 = 0;
    field_31 = 0;
    field_32 = 0;
    field_33 = 0;
}

RenderPaletteTable::RenderPaletteTable(SubObj6C *sub, int percent,
                                       const RenderPaletteColor *color, const unsigned char *palette) {
    unsigned char blended_palette[PALETTE_BUFFER_BYTES];
    unsigned char local_palette[PALETTE_BUFFER_BYTES];
    if (palette == 0) {
        func_1AE350(sub, local_palette);
    } else {
        for (int i = 0; i < PALETTE_COUNT; i++) {
            local_palette[i * PALETTE_ENTRY_BYTES + 0] = palette[i * PALETTE_ENTRY_BYTES + 0];
            local_palette[i * PALETTE_ENTRY_BYTES + 1] = palette[i * PALETTE_ENTRY_BYTES + 1];
            local_palette[i * PALETTE_ENTRY_BYTES + 2] = palette[i * PALETTE_ENTRY_BYTES + 2];
            local_palette[i * PALETTE_ENTRY_BYTES + 3] = palette[i * PALETTE_ENTRY_BYTES + 3];
        }
    }

    RenderPaletteColor blend_color;
    if (!color) {
        blend_color.red = 0;
        blend_color.blue = 0;
        blend_color.green = 0;
        blend_color.alpha = 0;
    } else {
        blend_color.red = color->red;
        blend_color.blue = color->blue;
        blend_color.green = color->green;
        blend_color.alpha = color->alpha;
    }

    field_0 = -1;
    field_8 = -1;
    field_C = -1;
    field_10 = -1;
    field_14 = -1;
    field_18 = -1;
    field_1C = -1;
    field_20 = -1;
    field_24 = -1;
    field_28 = -1;
    field_2C = -1;
    field_30 = COLOR_DEFAULT_COMPONENT;
    field_31 = COLOR_DEFAULT_COMPONENT;
    field_32 = COLOR_DEFAULT_COMPONENT;
    field_33 = COLOR_DEFAULT_COMPONENT;
    table = static_cast<unsigned char *>(func_100730(PALETTE_COUNT));

    func_00189260(local_palette, blended_palette, blend_color, percent, -1, -1);

    for (int i = 0; i < PALETTE_COUNT; i++) {
        unsigned char tr = blended_palette[i * PALETTE_ENTRY_BYTES + 0];
        unsigned char tg = blended_palette[i * PALETTE_ENTRY_BYTES + 1];
        unsigned char tb = blended_palette[i * PALETTE_ENTRY_BYTES + 2];
        int min_dist = REMAP_MAX_DIST;
        int best_idx = 0;
        for (int j = 0; j < PALETTE_COUNT; j++) {
            int dr = tr - local_palette[j * PALETTE_ENTRY_BYTES + 0];
            int dg = tg - local_palette[j * PALETTE_ENTRY_BYTES + 1];
            int db = tb - local_palette[j * PALETTE_ENTRY_BYTES + 2];
            int dist = dr * dr + dg * dg + db * db;
            if (dist < min_dist) {
                min_dist = dist;
                best_idx = j;
            }
        }
        table[i] = static_cast<unsigned char>(best_idx);
    }
}

RenderPaletteTable::~RenderPaletteTable() {
    if (table != 0) {
        func_100630(table);
        table = 0;
    }
}

#endif
