#pragma once
#pragma exceptions off

#include "zone_alloc_cell_items_buffer.h"

extern "C" {
void func_1D08E0(void *self, void *bucket, int size);
}

#if defined(__mips__)

extern "C" asm void *func_001D0DC0(void *self, int size_level) {
    sll        $v0, $a1, 4
    addu       $v0, $v0, $a1
    addiu      $sp, $sp, -0x20
    sll        $v0, $v0, 2
    sq         $ra, 0x10($sp)
    addu       $v0, $a0, $v0
    sq         $s0, 0x0($sp)
    addiu      $s0, $v0, 0xF2C
    addiu      $s0, $s0, 0x7FF8
    lw         $v0, 0x28($s0)
    bnez       $v0, lbl_1D0DFC
    nop
    lw         $a2, 0x2C($s0)
    jal        func_1D08E0
    paddub     $a1, $s0, $zero
lbl_1D0DFC:
    lw         $v0, 0x18($s0)
    beqz       $v0, lbl_1D0E20
    nop
    lw         $v1, 0x0($v0)
    sw         $v1, 0x18($s0)
    lw         $v1, 0x28($s0)
    addiu      $v1, $v1, -0x1
    b          lbl_1D0EA4
    sw         $v1, 0x28($s0)
lbl_1D0E20:
    lw         $a0, 0x20($s0)
    lw         $v0, 0x30($s0)
    lw         $a2, 0x1C($s0)
    lw         $a1, 0x0($s0)
    lw         $v1, 0x28($s0)
    mult       $a0, $a0, $v0
    sll        $a2, $a2, 2
    addu       $a1, $a1, $a2
    lw         $v0, 0x0($a1)
    addiu      $v1, $v1, -0x1
    sll        $a0, $a0, 2
    sw         $v1, 0x28($s0)
    lw         $v1, 0x20($s0)
    addu       $v0, $v0, $a0
    addiu      $v1, $v1, 0x1
    sw         $v1, 0x20($s0)
    lw         $a1, 0x1C($s0)
    lw         $v1, 0x8($s0)
    lw         $a2, 0x20($s0)
    sll        $a0, $a1, 2
    addu       $v1, $v1, $a0
    lw         $v1, 0x0($v1)
    bne        $a2, $v1, lbl_1D0EA4
    nop
    addiu      $v1, $a1, 0x1
    sw         $v1, 0x1C($s0)
    sw         $zero, 0x20($s0)
    lw         $a0, 0x1C($s0)
    lw         $v1, 0x10($s0)
    bne        $a0, $v1, lbl_1D0EA4
    nop
    addiu      $v1, $zero, -0x1
    sw         $v1, 0x1C($s0)
lbl_1D0EA4:
    lq         $ra, 0x10($sp)
    lq         $s0, 0x0($sp)
    jr         $ra
    addiu      $sp, $sp, 0x20
}

#else

struct SpatialBucketLayout {
    void **buffers;    // 0x0
    char pad_4[4];     // 0x4
    int *sizes;        // 0x8
    char pad_C[4];     // 0xC
    int max_chunks;    // 0x10
    char pad_14[4];    // 0x14
    void *free_list;   // 0x18
    int chunk_idx;     // 0x1C
    int cur_idx;       // 0x20
    char pad_24[4];    // 0x24
    int remaining;     // 0x28
    int alloc_size;    // 0x2C
    int factor;        // 0x30
};

extern "C" void *func_001D0DC0(void *self, int size_level) {
    char *zm = (char *)self;
    SpatialBucketLayout *b = (SpatialBucketLayout *)(zm + 0xF2C + 0x7FF8 + size_level * 68);

    if (b->remaining == 0) {
        func_1D08E0(self, b, b->alloc_size);
    }

    void *free_node = b->free_list;
    if (free_node != 0) {
        b->free_list = *(void **)free_node;
        b->remaining -= 1;
        return free_node;
    }

    int cur = b->cur_idx;
    int chunk = b->chunk_idx;
    void *slot = (char *)b->buffers[chunk] + (cur * b->factor) * 4;

    b->remaining -= 1;
    b->cur_idx++;

    int next_chunk = b->chunk_idx;
    if (b->cur_idx == b->sizes[next_chunk]) {
        b->chunk_idx = next_chunk + 1;
        b->cur_idx = 0;
        if (b->chunk_idx == b->max_chunks) {
            b->chunk_idx = -1;
        }
    }

    return slot;
}

#endif
