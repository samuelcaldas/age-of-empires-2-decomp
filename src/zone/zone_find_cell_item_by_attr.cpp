#pragma exceptions off

#include "zone_find_cell_item_by_attr.h"

#if defined(__mips__)
extern "C" asm void *func_001D1100(void *self, void *cell, int target_attr) {
    .word 0x90A7000D /* 00: lbu $a3, 0xd($a1) */
    .word 0x1000000C /* 04: b 0x38 */
    .word 0x70002628 /* 08: paddub $a0, $zero, $zero */
    .word 0x8CA20014 /* 0C: lw $v0, 0x14($a1) */
    .word 0x00041880 /* 10: sll $v1, $a0, 2 */
    .word 0x00431021 /* 14: addu $v0, $v0, $v1 */
    .word 0x8C420000 /* 18: lw $v0, 0x0($v0) */
    .word 0x8C430004 /* 1C: lw $v1, 0x4($v0) */
    .word 0x8463000E /* 20: lh $v1, 0xe($v1) */
    .word 0x54C30004 /* 24: bnel $a2, $v1, 0x38 */
    .word 0x24840001 /* 28: addiu $a0, $a0, 0x1 */
    .word 0x10000006 /* 2C: b 0x48 */
    .word 0x00000000 /* 30: nop  */
    .word 0x24840001 /* 34: addiu $a0, $a0, 0x1 */
    .word 0x0087102A /* 38: slt $v0, $a0, $a3 */
    .word 0x1440FFF3 /* 3C: bnez $v0, 0xc */
    .word 0x00000000 /* 40: nop  */
    .word 0x70001628 /* 44: paddub $v0, $zero, $zero */
    .word 0x03E00008 /* 48: jr $ra */
    .word 0x00000000 /* 4C: nop  */
}
#else
extern "C" void *func_001D1100(void *self, void *cell, int target_attr) {
    int i = 0;
    while (i < *(unsigned char *)((char *)cell + 0xD)) {
        void *item = *(void **)(*(char **)((char *)cell + 0x14) + (i << 2));
        if (*(short *)(*(char **)((char *)item + 0x4) + 0xE) == target_attr) {
            return item;
        }
        i++;
    }
    return 0;
}
#endif
