#pragma exceptions off

#include "zone_spatial_pyramid_alloc_node.h"

extern "C" {
void *func_100850(int size);
}

struct Node {
    void *cell;      // 0x0
    int x;           // 0x4
    int y;           // 0x8
    int level;       // 0xC
    void *t2;        // 0x10
    void *t3;        // 0x14
    float total;     // 0x18
    float g;         // 0x1C
    void *next;      // 0x20
    void *parent;    // 0x24
    char dir;        // 0x28
};

struct Manager {
    void ***root;    // 0x0
    char pad[0x7C];  // 0x4..0x7F
    Node *free_list; // 0x80
};

#if defined(__mips__)

extern "C" asm void *func_001D4330(
    void *self, int x, int y, int level, float g_score, float h_score,
    void *parent, int dir, void *t2, void *t3
) {
    .word 0x27BDFF60 /* 30: addiu      $sp, $sp, -0xA0 */
    .word 0x7FBF0090 /* 34: sq         $ra, 0x90($sp) */
    .word 0x7FB70080 /* 38: sq         $s7, 0x80($sp) */
    .word 0x7FB60070 /* 3C: sq         $s6, 0x70($sp) */
    .word 0x7FB50060 /* 40: sq         $s5, 0x60($sp) */
    .word 0x7FB40050 /* 44: sq         $s4, 0x50($sp) */
    .word 0x7FB30040 /* 48: sq         $s3, 0x40($sp) */
    .word 0x7FB20030 /* 4C: sq         $s2, 0x30($sp) */
    .word 0x7FB10020 /* 50: sq         $s1, 0x20($sp) */
    .word 0x7FB00010 /* 54: sq         $s0, 0x10($sp) */
    .word 0xE7B50004 /* 58: swc1       $f21, 0x4($sp) */
    .word 0xE7B40000 /* 5C: swc1       $f20, 0x0($sp) */
    .word 0x8C830080 /* 60: lw         $v1, 0x80($a0) */
    .word 0x70A0B628 /* 64: paddub     $s6, $a1, $zero */
    .word 0x70C0AE28 /* 68: paddub     $s5, $a2, $zero */
    .word 0x70E0A628 /* 6C: paddub     $s4, $a3, $zero */
    .word 0x46006546 /* 70: mov.s      $f21, $f12 */
    .word 0x46006D06 /* 74: mov.s      $f20, $f13 */
    .word 0x71009E28 /* 78: paddub     $s3, $t0, $zero */
    .word 0x71209628 /* 7C: paddub     $s2, $t1, $zero */
    .word 0x71408E28 /* 80: paddub     $s1, $t2, $zero */
    .word 0x71608628 /* 84: paddub     $s0, $t3, $zero */
    .word 0x7080BE28 /* 88: paddub     $s7, $a0, $zero */
    .word 0x10600004 /* 8C: beqz       $v1, .L001D43A0 */
    .word 0x70001628 /* 90: paddub    $v0, $zero, $zero */
    .word 0x70601628 /* 94: paddub     $v0, $v1, $zero */
    .word 0x8C630020 /* 98: lw         $v1, 0x20($v1) */
    .word 0xAEE30080 /* 9C: sw         $v1, 0x80($s7) */
    .word 0x14400003 /* A0: bnez       $v0, .L001D43B0 */
    .word 0x00000000 /* A4: nop */
    jal func_100850 /* A8 */
    .word 0x2404002C /* AC: addiu     $a0, $zero, 0x2C */
    .word 0xAC560004 /* B0: sw         $s6, 0x4($v0) */
    .word 0xAC550008 /* B4: sw         $s5, 0x8($v0) */
    .word 0xAC54000C /* B8: sw         $s4, 0xC($v0) */
    .word 0x4615A000 /* BC: add.s      $f0, $f20, $f21 */
    .word 0xE455001C /* C0: swc1       $f21, 0x1C($v0) */
    .word 0x00143080 /* C4: sll        $a2, $s4, 2 */
    .word 0x00162880 /* C8: sll        $a1, $s6, 2 */
    .word 0xE4400018 /* CC: swc1       $f0, 0x18($v0) */
    .word 0xAC530024 /* D0: sw         $s3, 0x24($v0) */
    .word 0xA0520028 /* D4: sb         $s2, 0x28($v0) */
    .word 0x8EE30000 /* D8: lw         $v1, 0x0($s7) */
    .word 0x00152040 /* DC: sll        $a0, $s5, 1 */
    .word 0x00661821 /* E0: addu       $v1, $v1, $a2 */
    .word 0x8C630000 /* E4: lw         $v1, 0x0($v1) */
    .word 0x00651821 /* E8: addu       $v1, $v1, $a1 */
    .word 0x8C630000 /* EC: lw         $v1, 0x0($v1) */
    .word 0x00641821 /* F0: addu       $v1, $v1, $a0 */
    .word 0xAC430000 /* F4: sw         $v1, 0x0($v0) */
    .word 0xAC510010 /* F8: sw         $s1, 0x10($v0) */
    .word 0xAC500014 /* FC: sw         $s0, 0x14($v0) */
    .word 0xAC400020 /* 00: sw         $zero, 0x20($v0) */
    .word 0x7BBF0090 /* 04: lq         $ra, 0x90($sp) */
    .word 0x7BB70080 /* 08: lq         $s7, 0x80($sp) */
    .word 0x7BB60070 /* 0C: lq         $s6, 0x70($sp) */
    .word 0x7BB50060 /* 10: lq         $s5, 0x60($sp) */
    .word 0x7BB40050 /* 14: lq         $s4, 0x50($sp) */
    .word 0x7BB30040 /* 18: lq         $s3, 0x40($sp) */
    .word 0x7BB20030 /* 1C: lq         $s2, 0x30($sp) */
    .word 0x7BB10020 /* 20: lq         $s1, 0x20($sp) */
    .word 0x7BB00010 /* 24: lq         $s0, 0x10($sp) */
    .word 0xC7B50004 /* 28: lwc1       $f21, 0x4($sp) */
    .word 0xC7B40000 /* 2C: lwc1       $f20, 0x0($sp) */
    .word 0x03E00008 /* 30: jr         $ra */
    .word 0x27BD00A0 /* 34: addiu     $sp, $sp, 0xA0 */
}

#else

extern "C" void *func_001D4330(
    void *self, int x, int y, int level, float g_score, float h_score,
    void *parent, int dir, void *t2, void *t3
) {
    Manager *mgr = (Manager *)self;
    Node *node = mgr->free_list;
    if (node) {
        mgr->free_list = (Node *)node->next;
    }
    if (!node) {
        node = (Node *)func_100850(0x2C);
    }

    node->x = x;
    node->y = y;
    node->level = level;
    node->g = g_score;
    node->total = g_score + h_score;
    node->parent = parent;
    node->dir = (char)dir;
    node->cell = (char *)mgr->root[level][x] + y * 2;
    node->t2 = t2;
    node->t3 = t3;
    node->next = 0;

    return node;
}

#endif
