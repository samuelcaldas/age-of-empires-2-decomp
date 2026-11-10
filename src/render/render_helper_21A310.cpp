#pragma exceptions off

#if defined(__mips__)

extern "C" {
extern char D_00C5C2BA[];
int func_0021BC30(void *arg0, void *buf, int arg2, int capacity, int arg4);
int func_0011C888(int c);
int strcmp(const char *s1, const char *s2);

asm void func_0021A310(int index) {
    .word 0x27BDFFE0 /* addiu      $sp, $sp, -0x20 */
    .word 0x7FBF0010 /* sq         $ra, 0x10($sp) */
    .word 0x27828690 /* addiu      $v0, $gp, -0x7970 */
    .word 0x00041880 /* sll        $v1, $a0, 2 */
    .word 0x00431021 /* addu       $v0, $v0, $v1 */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x8C440000 /* lw         $a0, 0x0($v0) */
    .word 0x24080001 /* addiu      $t0, $zero, 0x1 */
    .word 0x70003628 /* paddub     $a2, $zero, $zero */
    .word 0x3C020039 /* lui        $v0, 0x39 */
    .word 0x244321D0 /* addiu      $v1, $v0, (0x3921D0 & 0xFFFF) */
    .word 0x3C0201E9 /* lui        $v0, (0x1E98000 >> 16) */
    .word 0x34508000 /* ori        $s0, $v0, (0x1E98000 & 0xFFFF) */
    .word 0x00041040 /* sll        $v0, $a0, 1 */
    .word 0x00441021 /* addu       $v0, $v0, $a0 */
    .word 0x00021080 /* sll        $v0, $v0, 2 */
    .word 0x00622021 /* addu       $a0, $v1, $v0 */
    .word 0x8C870000 /* lw         $a3, 0x0($a0) */
    jal        func_0021BC30
    .word 0x72002E28 /* paddub    $a1, $s0, $zero */
    .word 0x3C0301E9 /* lui        $v1, (0x1E98004 >> 16) */
    .word 0x34648000 /* ori        $a0, $v1, (0x1E98000 & 0xFFFF) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC24C2C0 /* sw         $a0, -0x3D40($at) */
    .word 0x34638004 /* ori        $v1, $v1, (0x1E98004 & 0xFFFF) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC23C2C4 /* sw         $v1, -0x3D3C($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0x8C23C2C0 /* lw         $v1, -0x3D40($at) */
    .word 0x84630000 /* lh         $v1, 0x0($v1) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC23C2C8 /* sw         $v1, -0x3D38($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0x8C23C2C0 /* lw         $v1, -0x3D40($at) */
    .word 0x84630002 /* lh         $v1, 0x2($v1) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0xAC23C2CC /* sw         $v1, -0x3D34($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0x8C24C2C4 /* lw         $a0, -0x3D3C($at) */
    .word 0x10000006 /* b          .L0021A3C8 */
    .word 0x70002E28 /* paddub    $a1, $zero, $zero */
    .word 0x8C830020 /* lw         $v1, 0x20($a0) */
    .word 0x24A50001 /* addiu      $a1, $a1, 0x1 */
    .word 0x00701821 /* addu       $v1, $v1, $s0 */
    .word 0xAC830020 /* sw         $v1, 0x20($a0) */
    .word 0x24840024 /* addiu      $a0, $a0, 0x24 */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0x8C23C2C8 /* lw         $v1, -0x3D38($at) */
    .word 0x00A3182A /* slt        $v1, $a1, $v1 */
    .word 0x1460FFF7 /* bnez       $v1, .L0021A3B4 */
    .word 0x00000000 /* nop */
    .word 0x7BBF0010 /* lq         $ra, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0020 /* addiu     $sp, $sp, 0x20 */
}

asm void *func_0021A3F0(const char *name) {
    .word 0x27BDFF90 /* addiu      $sp, $sp, -0x70 */
    .word 0x7FBF0020 /* sq         $ra, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x27B00030 /* addiu      $s0, $sp, 0x30 */
    .word 0x10000006 /* b          .L0021A420 */
    .word 0x70808E28 /* paddub    $s1, $a0, $zero */
    .word 0x82240000 /* lb         $a0, 0x0($s1) */
    jal        func_0011C888
    .word 0x26310001 /* addiu     $s1, $s1, 0x1 */
    .word 0xA2020000 /* sb         $v0, 0x0($s0) */
    .word 0x26100001 /* addiu      $s0, $s0, 0x1 */
    .word 0x82220000 /* lb         $v0, 0x0($s1) */
    .word 0x1440FFF9 /* bnez       $v0, .L0021A40C */
    .word 0x00000000 /* nop */
    .word 0xA2000000 /* sb         $zero, 0x0($s0) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0x8C31C2C4 /* lw         $s1, -0x3D3C($at) */
    .word 0x1000000A /* b          .L0021A464 */
    .word 0x70008628 /* paddub    $s0, $zero, $zero */
    .word 0x27A40030 /* addiu      $a0, $sp, 0x30 */
    jal        strcmp
    .word 0x72202E28 /* paddub    $a1, $s1, $zero */
    .word 0x54400004 /* bnel       $v0, $zero, .L0021A460 */
    .word 0x26100001 /* addiu     $s0, $s0, 0x1 */
    .word 0x1000000A /* b          .L0021A480 */
    .word 0x8E220020 /* lw        $v0, 0x20($s1) */
    .word 0x26100001 /* addiu      $s0, $s0, 0x1 */
    .word 0x26310024 /* addiu      $s1, $s1, 0x24 */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0x8C22C2C8 /* lw         $v0, -0x3D38($at) */
    .word 0x2442FFFF /* addiu      $v0, $v0, -0x1 */
    .word 0x0202102A /* slt        $v0, $s0, $v0 */
    .word 0x1440FFF3 /* bnez       $v0, .L0021A444 */
    .word 0x27A40030 /* addiu     $a0, $sp, 0x30 */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x7BBF0020 /* lq         $ra, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0070 /* addiu     $sp, $sp, 0x70 */
}

asm int func_0021A4A0(int index) {
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0x8C26C2C4 /* lw         $a2, -0x3D3C($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0x8C25C2C8 /* lw         $a1, -0x3D38($at) */
    .word 0x3C0100C6 /* lui        $at, (0xC60000 >> 16) */
    .word 0x8C22C2CC /* lw         $v0, -0x3D34($at) */
    .word 0x000518C0 /* sll        $v1, $a1, 3 */
    .word 0x00652821 /* addu       $a1, $v1, $a1 */
    .word 0x00821818 /* mult       $v1, $a0, $v0 */
    .word 0x00051080 /* sll        $v0, $a1, 2 */
    .word 0x00461021 /* addu       $v0, $v0, $a2 */
    .word 0x8C42FFFC /* lw         $v0, -0x4($v0) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x00431021 /* addu      $v0, $v0, $v1 */
}

char func_0021A4E0(int index) {
    return D_00C5C2BA[index];
}

void func_0021A500(int index, char val) {
    D_00C5C2BA[index] = val;
}
}

#else

#include "sub_list.h"

extern "C" {
extern int D_004E2E50[];
extern char D_003921D0[];
extern char D_01E98000;
extern char D_00C5C2BA[];

extern void *D_00C5C2C0;
extern char *D_00C5C2C4;
extern int D_00C5C2C8;
extern int D_00C5C2CC;

int func_0021BC30(void *arg0, void *buf, int arg2, int capacity, int arg4);
int func_0011C888(int c);
int strcmp(const char *s1, const char *s2);

void func_0021A310(int index) {
    int id = D_004E2E50[index];
    void *record = D_003921D0 + id * 12;
    int capacity = *(int *)record;

    func_0021BC30(record, &D_01E98000, 0, capacity, 1);

    D_00C5C2C0 = &D_01E98000;
    D_00C5C2C4 = &D_01E98000 + 4;

    short count = *(short *)D_00C5C2C0;
    D_00C5C2C8 = (int)count;

    short stride = *(short *)((char *)D_00C5C2C0 + 2);
    D_00C5C2CC = (int)stride;

    char *item = D_00C5C2C4;
    for (int i = 0; i < count; i++) {
        char *rel_ptr = *(char **)(item + 0x20);
        *(char **)(item + 0x20) = &D_01E98000 + (long)rel_ptr;
        item += 0x24;
    }
}

void *func_0021A3F0(const char *name) {
    char lower_buf[64];
    int idx = 0;

    const char *p = name;
    while (*p != 0) {
        lower_buf[idx] = (char)func_0011C888((unsigned char)*p);
        idx++;
        p++;
    }
    lower_buf[idx] = 0;

    char *item = D_00C5C2C4;
    int max_count = D_00C5C2C8 - 1;

    for (int i = 0; i < max_count; i++) {
        if (strcmp(lower_buf, item) == 0) {
            return *(void **)(item + 0x20);
        }
        item += 0x24;
    }

    return 0;
}

int func_0021A4A0(int index) {
    int count = D_00C5C2C8;
    int stride = D_00C5C2CC;
    char *end_item = D_00C5C2C4 + count * 36;
    int base = *(int *)(end_item - 4);
    return base + index * stride;
}

char func_0021A4E0(int index) {
    return D_00C5C2BA[index];
}

void func_0021A500(int index, char val) {
    D_00C5C2BA[index] = val;
}

}

#endif
