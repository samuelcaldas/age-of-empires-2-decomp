#pragma exceptions off

#include "zone_spatial_allocator_pop.h"

extern "C" {
void *func_100730(unsigned int size);
void *func_00100730(unsigned int size);
void *func_117AF8(void *dst, const void *src, unsigned int size);
void func_100630(void *ptr);
void *func_100850(unsigned int size);
void func_001D8120(void *root, void *node);
int func_1D80D0(void *node, unsigned int w, unsigned int h);
void *func_117CAC(void *dst, int val, unsigned int size);
}

struct SpatialTreeNode {
    void *buffer;
    SpatialTreeNode *child;
};

struct SpatialChunkAllocator {
    SpatialTreeNode *root;    // 0x0
    int elem_size;            // 0x4
    int chunk_capacity;       // 0x8
    int count;                // 0xC
    int capacity;             // 0x10
    void **items;             // 0x14
    unsigned char clear_flag; // 0x18
};

#if defined(__mips__)

extern "C" asm void *func_001D81E0(SpatialChunkAllocator *self) {
    .word 0x27BDFFD0 /* E0: addiu      $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* E4: sq         $ra, 0x20($sp) */
    .word 0x7FB10010 /* E8: sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* EC: sq         $s0, 0x0($sp) */
    .word 0x8C82000C /* F0: lw         $v0, 0xC($a0) */
    .word 0x1440003E /* F4: bnez       $v0, .L001D82F0 */
    .word 0x70808628 /* F8: paddub    $s0, $a0, $zero */
    .word 0x8E040008 /* FC: lw         $a0, 0x8($s0) */
    .word 0x8E030010 /* 00: lw         $v1, 0x10($s0) */
    .word 0x00441021 /* 04: addu       $v0, $v0, $a0 */
    .word 0x0043082B /* 08: sltu       $at, $v0, $v1 */
    .word 0x54200014 /* 0C: bnel       $at, $zero, .L001D8260 */
    .word 0x24040008 /* 10: addiu     $a0, $zero, 0x8 */
    .word 0x00041040 /* 14: sll        $v0, $a0, 1 */
    .word 0x00621021 /* 18: addu       $v0, $v1, $v0 */
    .word 0xAE020010 /* 1C: sw         $v0, 0x10($s0) */
    .word 0x9E020010 /* 20: lwu        $v0, 0x10($s0) */
    .word 0x000210B8 /* 24: dsll       $v0, $v0, 2 */
    .word 0x0002203C /* 28: dsll32     $a0, $v0, 0 */
    jal func_100730 /* 2C */
    .word 0x0004203F /* 30: dsra32    $a0, $a0, 0 */
    .word 0x8E050014 /* 34: lw         $a1, 0x14($s0) */
    .word 0x10A00005 /* 38: beqz       $a1, .L001D8250 */
    .word 0x70408E28 /* 3C: paddub    $s1, $v0, $zero */
    .word 0x8E02000C /* 40: lw         $v0, 0xC($s0) */
    .word 0x72202628 /* 44: paddub     $a0, $s1, $zero */
    jal func_117AF8 /* 48 */
    .word 0x00023080 /* 4C: sll       $a2, $v0, 2 */
    jal func_100630 /* 50 */
    .word 0x8E040014 /* 54: lw        $a0, 0x14($s0) */
    .word 0xAE110014 /* 58: sw         $s1, 0x14($s0) */
    .word 0x24040008 /* 5C: addiu      $a0, $zero, 0x8 */
    jal func_100850 /* 60 */
    .word 0x00000000 /* 64: nop */
    .word 0x10400003 /* 68: beqz       $v0, .L001D8278 */
    .word 0x70408E28 /* 6C: paddub    $s1, $v0, $zero */
    .word 0xAE200000 /* 70: sw         $zero, 0x0($s1) */
    .word 0xAE200004 /* 74: sw         $zero, 0x4($s1) */
    .word 0x8E040000 /* 78: lw         $a0, 0x0($s0) */
    .word 0x14800004 /* 7C: bnez       $a0, .L001D8290 */
    .word 0x72202E28 /* 80: paddub    $a1, $s1, $zero */
    .word 0x10000004 /* 84: b          .L001D8298 */
    .word 0xAE110000 /* 88: sw        $s1, 0x0($s0) */
    .word 0x72202E28 /* 8C: paddub     $a1, $s1, $zero */
    jal func_001D8120 /* 90 */
    .word 0x00000000 /* 94: nop */
    .word 0x8E050004 /* 98: lw         $a1, 0x4($s0) */
    .word 0x8E060008 /* 9C: lw         $a2, 0x8($s0) */
    jal func_1D80D0 /* A0 */
    .word 0x72202628 /* A4: paddub    $a0, $s1, $zero */
    .word 0x8E240000 /* A8: lw         $a0, 0x0($s1) */
    .word 0x1000000C /* AC: b          .L001D82E0 */
    .word 0x70002E28 /* B0: paddub    $a1, $zero, $zero */
    .word 0x8E03000C /* B4: lw         $v1, 0xC($s0) */
    .word 0x8E020014 /* B8: lw         $v0, 0x14($s0) */
    .word 0x24A50001 /* BC: addiu      $a1, $a1, 0x1 */
    .word 0x00031880 /* C0: sll        $v1, $v1, 2 */
    .word 0x00431021 /* C4: addu       $v0, $v0, $v1 */
    .word 0xAC440000 /* C8: sw         $a0, 0x0($v0) */
    .word 0x8E02000C /* CC: lw         $v0, 0xC($s0) */
    .word 0x24420001 /* D0: addiu      $v0, $v0, 0x1 */
    .word 0xAE02000C /* D4: sw         $v0, 0xC($s0) */
    .word 0x8E020004 /* D8: lw         $v0, 0x4($s0) */
    .word 0x00822021 /* DC: addu       $a0, $a0, $v0 */
    .word 0x8E020008 /* E0: lw         $v0, 0x8($s0) */
    .word 0x00A2102B /* E4: sltu       $v0, $a1, $v0 */
    .word 0x1440FFF2 /* E8: bnez       $v0, .L001D82B4 */
    .word 0x00000000 /* EC: nop */
    .word 0x8E02000C /* F0: lw         $v0, 0xC($s0) */
    .word 0x2442FFFF /* F4: addiu      $v0, $v0, -0x1 */
    .word 0xAE02000C /* F8: sw         $v0, 0xC($s0) */
    .word 0x8E04000C /* FC: lw         $a0, 0xC($s0) */
    .word 0x8E030014 /* 00: lw         $v1, 0x14($s0) */
    .word 0x92020018 /* 04: lbu        $v0, 0x18($s0) */
    .word 0x00042080 /* 08: sll        $a0, $a0, 2 */
    .word 0x00641821 /* 0C: addu       $v1, $v1, $a0 */
    .word 0x10400005 /* 10: beqz       $v0, .L001D8328 */
    .word 0x8C710000 /* 14: lw        $s1, 0x0($v1) */
    .word 0x8E060004 /* 18: lw         $a2, 0x4($s0) */
    .word 0x72202628 /* 1C: paddub     $a0, $s1, $zero */
    jal func_117CAC /* 20 */
    .word 0x70002E28 /* 24: paddub    $a1, $zero, $zero */
    .word 0x72201628 /* 28: paddub     $v0, $s1, $zero */
    .word 0x7BBF0020 /* 2C: lq         $ra, 0x20($sp) */
    .word 0x7BB10010 /* 30: lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* 34: lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* 38: jr         $ra */
    .word 0x27BD0030 /* 3C: addiu     $sp, $sp, 0x30 */
}

#else

extern "C" void *func_001D81E0(SpatialChunkAllocator *self) {
    if (self->count == 0) {
        if ((unsigned int)(self->count + self->chunk_capacity) >= (unsigned int)self->capacity) {
            self->capacity += self->chunk_capacity * 2;
            void **new_items = (void **)func_100730((unsigned int)self->capacity * 4);
            if (self->items != 0) {
                func_117AF8(new_items, self->items, self->count * 4);
            }
            func_100630(self->items);
            self->items = new_items;
        }

        SpatialTreeNode *node = (SpatialTreeNode *)func_100850(8);
        if (node != 0) {
            node->buffer = 0;
            node->child = 0;
        }

        if (self->root == 0) {
            self->root = node;
        } else {
            func_001D8120(self->root, node);
        }

        func_1D80D0(node, self->elem_size, self->chunk_capacity);

        char *buf = (char *)node->buffer;
        unsigned int i = 0;
        while (i < (unsigned int)self->chunk_capacity) {
            self->items[self->count] = buf;
            self->count++;
            buf += self->elem_size;
            i++;
        }
    }

    self->count--;
    void *item = self->items[self->count];
    if (self->clear_flag != 0) {
        func_117CAC(item, 0, self->elem_size);
    }
    return item;
}

#endif
