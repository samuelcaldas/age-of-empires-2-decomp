#pragma exceptions off
#include "map_zone_los.h"

#if defined(__mips__)

extern "C" {
extern SightEntry *D_0038FAA0[];
extern SightEntry *D_0038FA40[];
extern int *D_50A5A0[];

asm void func_00137E90(void *self) {
    .word 0x03E00008
    .word 0x00000000
}

asm void func_00137EA0(MapZone *self, int x, int y, int radius, int mode, int flag) {
    .word 0x8F838898 /* lw         $v1, -0x7768($gp) */
    .word 0x14600061 /* bnez       $v1, .L0013802C */
    .word 0x70006628 /* paddub    $t4, $zero, $zero */
    .word 0x28E10015 /* slti       $at, $a3, 0x15 */
    .word 0x14200002 /* bnez       $at, .L00137EBC */
    .word 0x00000000 /* nop */
    .word 0x24070014 /* addiu      $a3, $zero, 0x14 */
    .word 0x11000007 /* beqz       $t0, .L00137EDC */
    .word 0x00000000 /* nop */
    la v1, D_0038FAA0
    .word 0x00073880 /* sll        $a3, $a3, 2 */
    .word 0x00671821 /* addu       $v1, $v1, $a3 */
    .word 0x10000051 /* b          .L0013801C */
    .word 0x8C6B0000 /* lw        $t3, 0x0($v1) */
    la v1, D_0038FA40
    .word 0x00073880 /* sll        $a3, $a3, 2 */
    .word 0x00671821 /* addu       $v1, $v1, $a3 */
    .word 0x1000004B /* b          .L0013801C */
    .word 0x8C6B0000 /* lw        $t3, 0x0($v1) */
    .word 0x00C75021 /* addu       $t2, $a2, $a3 */
    .word 0x05420048 /* bltzl      $t2, .L0013801C */
    .word 0x256B000C /* addiu     $t3, $t3, 0xC */
    .word 0x8C830018 /* lw         $v1, 0x18($a0) */
    .word 0x0143082A /* slt        $at, $t2, $v1 */
    .word 0x10200043 /* beqz       $at, .L00138018 */
    .word 0x00000000 /* nop */
    .word 0x8D630004 /* lw         $v1, 0x4($t3) */
    .word 0x00A31821 /* addu       $v1, $a1, $v1 */
    .word 0x04610002 /* bgez       $v1, .L00137F24 */
    .word 0x00000000 /* nop */
    .word 0x70001E28 /* paddub     $v1, $zero, $zero */
    .word 0x8D670008 /* lw         $a3, 0x8($t3) */
    .word 0x8C8D0014 /* lw         $t5, 0x14($a0) */
    .word 0x00A73821 /* addu       $a3, $a1, $a3 */
    .word 0x00ED402A /* slt        $t0, $a3, $t5 */
    .word 0x15000003 /* bnez       $t0, .L00137F44 */
    .word 0x000A7880 /* sll       $t7, $t2, 2 */
    .word 0x25A7FFFF /* addiu      $a3, $t5, -0x1 */
    .word 0x000A7880 /* sll        $t7, $t2, 2 */
    .word 0x8C8A0000 /* lw         $t2, 0x0($a0) */
    la t0, D_50A5A0
    .word 0x010F4021 /* addu       $t0, $t0, $t7 */
    .word 0x014F5021 /* addu       $t2, $t2, $t7 */
    .word 0x8D080000 /* lw         $t0, 0x0($t0) */
    .word 0x8D4D0000 /* lw         $t5, 0x0($t2) */
    .word 0x00035080 /* sll        $t2, $v1, 2 */
    .word 0x010A5021 /* addu       $t2, $t0, $t2 */
    .word 0x11200028 /* beqz       $t1, .L0013800C */
    .word 0x01A34021 /* addu      $t0, $t5, $v1 */
    .word 0x8C8E000C /* lw         $t6, 0xC($a0) */
    .word 0x000360C0 /* sll        $t4, $v1, 3 */
    .word 0x3C010001 /* lui        $at, (0x10000 >> 16) */
    .word 0x01836023 /* subu       $t4, $t4, $v1 */
    .word 0x000C6880 /* sll        $t5, $t4, 2 */
    .word 0x01C10821 /* addu       $at, $t6, $at */
    .word 0x8C2C8E8C /* lw         $t4, -0x7174($at) */
    .word 0x018F6021 /* addu       $t4, $t4, $t7 */
    .word 0x8D8C0000 /* lw         $t4, 0x0($t4) */
    .word 0x1000001D /* b          .L0013800C */
    .word 0x018D6021 /* addu      $t4, $t4, $t5 */
    .word 0x910E0000 /* lbu        $t6, 0x0($t0) */
    .word 0x240D00FF /* addiu      $t5, $zero, 0xFF */
    .word 0x25CEFFFF /* addiu      $t6, $t6, -0x1 */
    .word 0x31CF00FF /* andi       $t7, $t6, 0xFF */
    .word 0x15ED0003 /* bne        $t7, $t5, .L00137FBC */
    .word 0x240D00FE /* addiu     $t5, $zero, 0xFE */
    .word 0x70007E28 /* paddub     $t7, $zero, $zero */
    .word 0x240D00FE /* addiu      $t5, $zero, 0xFE */
    .word 0x31EE00FF /* andi       $t6, $t7, 0xFF */
    .word 0x15CD0003 /* bne        $t6, $t5, .L00137FD0 */
    .word 0x31ED00FF /* andi      $t5, $t7, 0xFF */
    .word 0x640F00FF /* daddiu     $t7, $zero, 0xFF */
    .word 0x31ED00FF /* andi       $t5, $t7, 0xFF */
    .word 0x15A00009 /* bnez       $t5, .L00137FF8 */
    .word 0x00000000 /* nop */
    .word 0x11200003 /* beqz       $t1, .L00137FE8 */
    .word 0x00000000 /* nop */
    .word 0x240D0080 /* addiu      $t5, $zero, 0x80 */
    .word 0xA18D0009 /* sb         $t5, 0x9($t4) */
    .word 0x8D4E0000 /* lw         $t6, 0x0($t2) */
    .word 0x8C8D0028 /* lw         $t5, 0x28($a0) */
    .word 0x01CD6824 /* and        $t5, $t6, $t5 */
    .word 0xAD4D0000 /* sw         $t5, 0x0($t2) */
    .word 0xA10F0000 /* sb         $t7, 0x0($t0) */
    .word 0x25080001 /* addiu      $t0, $t0, 0x1 */
    .word 0x254A0004 /* addiu      $t2, $t2, 0x4 */
    .word 0x24630001 /* addiu      $v1, $v1, 0x1 */
    .word 0x258C001C /* addiu      $t4, $t4, 0x1C */
    .word 0x00E3082A /* slt        $at, $a3, $v1 */
    .word 0x1020FFE2 /* beqz       $at, .L00137F9C */
    .word 0x00000000 /* nop */
    .word 0x256B000C /* addiu      $t3, $t3, 0xC */
    .word 0x8D670000 /* lw         $a3, 0x0($t3) */
    .word 0x240303E7 /* addiu      $v1, $zero, 0x3E7 */
    .word 0x14E3FFB4 /* bne        $a3, $v1, .L00137EF8 */
    .word 0x00C75021 /* addu      $t2, $a2, $a3 */
    .word 0x03E00008 /* jr         $ra */
    .word 0x00000000 /* nop */
}

}

#else


extern "C" {
extern int D_004E3058;
extern SightEntry *D_0038FA40[];
extern SightEntry *D_0038FAA0[];
extern int *D_50A5A0[];

void func_00137E90(void *self) {
    (void)self;
}

void func_00137EA0(MapZone *self, int x, int y, int radius, int mode, int flag) {
    if (D_004E3058) {
        return;
    }
    char *tile28 = 0;
    if (radius > 20) {
        radius = 20;
    }
    SightEntry *entry;
    if (mode) {
        entry = D_0038FAA0[radius];
    } else {
        entry = D_0038FA40[radius];
    }

    int dy = entry->dy;
    while (dy != 999) {
        int ty = y + dy;
        if (ty >= 0) {
            if (ty < self->m_height) {
                int min_x = x + entry->min_dx;
                if (min_x < 0) {
                    min_x = 0;
                }
                int max_x = x + entry->max_dx;
                if (max_x >= self->m_width) {
                    max_x = self->m_width - 1;
                }
                unsigned char *tile_ptr = self->m_row_ptrs[ty] + min_x;
                int *flag_ptr = D_50A5A0[ty] + min_x;
                if (flag) {
                    tile28 = ((ZoneFieldC *)self->pad_0C)->m_grid[ty] + min_x * 28;
                }
                while (min_x <= max_x) {
                    int val = *tile_ptr - 1;
                    int t7 = (unsigned char)val;
                    if (t7 == 255) {
                        t7 = 0;
                    }
                    if ((unsigned char)val == 254) {
                        t7 = 255;
                    }
                    if (!t7) {
                        if (flag) {
                            tile28[9] = 128;
                        }
                        *flag_ptr &= self->pad_28;
                    }
                    *tile_ptr = t7;
                    tile_ptr++;
                    flag_ptr++;
                    min_x++;
                    tile28 += 28;
                }
            }
        }
        entry++;
        dy = entry->dy;
    }
}
}

#endif