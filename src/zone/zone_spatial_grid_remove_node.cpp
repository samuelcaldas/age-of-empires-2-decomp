#pragma once
#pragma exceptions off

#include "zone_spatial_grid_remove_node.h"

extern "C" {
void func_1F24A0(void *pool);
}

#if defined(__mips__)

extern "C" asm void func_001EE790(SpatialGrid *self, Node *node) {
    addiu      $sp, $sp, -0x10
    beqz       $a1, lbl_1EE848
    sq         $ra, 0x0($sp)
    lw         $a3, 0x10($a1)
    lui        $at, 0x13
    addu       $at, $a0, $at
    lw         $t0, 0x14($a1)
    lw         $v1, -0x4BB8($at)
    sll        $a2, $a3, 1
    addu       $a2, $a2, $a3
    sll        $a2, $a2, 2
    addu       $a2, $v1, $a2
    lw         $v1, 0x4($a2)
    addiu      $v0, $t0, 0x1
    slt        $at, $v0, $v1
    beqz       $at, lbl_1EE800
    nop
    lw         $a3, 0x0($a2)
    sll        $v0, $v1, 2
    sll        $t1, $t0, 2
    addu       $v0, $v0, $a3
    lw         $v1, -0x4($v0)
    addu       $v0, $a3, $t1
    sw         $v1, 0x0($v0)
    lw         $v0, 0x0($a2)
    addu       $v0, $v0, $t1
    lw         $v0, 0x0($v0)
    sw         $t0, 0x14($v0)
lbl_1EE800:
    lw         $v1, 0x4($a2)
    addiu      $v0, $zero, 0xED
    addiu      $v1, $v1, -0x1
    sw         $v1, 0x4($a2)
    lbu        $v1, 0x7($a1)
    bne        $v1, $v0, lbl_1EE83C
    lui        $at, 0x13
    lui        $at, 0x13
    addu       $at, $a0, $at
    lw         $v0, -0x4BC0($at)
    lui        $at, 0x13
    addiu      $v0, $v0, -0x1
    addu       $at, $a0, $at
    sw         $v0, -0x4BC0($at)
    lui        $at, 0x13
lbl_1EE83C:
    addu       $at, $a0, $at
    jal        func_1F24A0
    lw         $a0, -0x4A88($at)
lbl_1EE848:
    lq         $ra, 0x0($sp)
    jr         $ra
    addiu      $sp, $sp, 0x10
}

#else

struct Node {
    char pad_00[7];
    unsigned char field_7;
    char pad_08[8];
    int cell_idx;
    int list_idx;
};

struct PyramidCell {
    Node **items;
    int count;
    int capacity;
};

struct SpatialGrid {
    char pad_00[0x12B440];
    int field_12B440;
    char pad_after[0x12B448 - 0x12B440 - 4];
    PyramidCell *cells;
    char pad_after2[0x12B578 - 0x12B448 - 4];
    void *pool;
};

extern "C" void func_001EE790(SpatialGrid *self, Node *node) {
    if (node == 0) {
        return;
    }

    int cell_idx = node->cell_idx;
    int list_idx = node->list_idx;
    PyramidCell *cell = &self->cells[cell_idx];

    if (list_idx + 1 < cell->count) {
        Node *last_node = cell->items[cell->count - 1];
        cell->items[list_idx] = last_node;
        last_node->list_idx = list_idx;
    }

    cell->count--;

    if (node->field_7 == 0xED) {
        self->field_12B440--;
    }

    func_1F24A0(self->pool);
}

#endif
