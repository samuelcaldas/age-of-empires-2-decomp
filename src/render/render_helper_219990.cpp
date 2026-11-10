#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

/* 0x00219990 */
extern "C" {
void func_116F68();
void func_00217B50();

asm int func_00219990(void *self, int index) {

    .word 0x27BDFFD0 /* addiu      $sp, $sp, -0x30 */
    .word 0x7FBF0020 /* sq         $ra, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7FB00000 /* sq         $s0, 0x0($sp) */
    .word 0x04A00006 /* bltz       $a1, .L002199BC */
    .word 0x70808628 /* paddub    $s0, $a0, $zero */
    .word 0x86020120 /* lh         $v0, 0x120($s0) */
    .word 0x2442FFFF /* addiu      $v0, $v0, -0x1 */
    .word 0x0045082A /* slt        $at, $v0, $a1 */
    .word 0x10200003 /* beqz       $at, .L002199C4 */
    .word 0x00000000 /* nop */
    .word 0x1000003B /* b          .L00219AAC */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x14A00005 /* bnez       $a1, .L002199DC */
    .word 0x00000000 /* nop */
    .word 0x8E11011C /* lw         $s1, 0x11C($s0) */
    .word 0x8E220028 /* lw         $v0, 0x28($s1) */
    .word 0x1000000D /* b          .L00219A0C */
    .word 0xAE02011C /* sw        $v0, 0x11C($s0) */
    .word 0x8E03011C /* lw         $v1, 0x11C($s0) */
    .word 0x70002628 /* paddub     $a0, $zero, $zero */
    .word 0x24A2FFFF /* addiu      $v0, $a1, -0x1 */
    .word 0x14820005 /* bne        $a0, $v0, .L00219A00 */
    .word 0x00000000 /* nop */
    .word 0x8C710028 /* lw         $s1, 0x28($v1) */
    .word 0x8E220028 /* lw         $v0, 0x28($s1) */
    .word 0x10000004 /* b          .L00219A0C */
    .word 0xAC620028 /* sw        $v0, 0x28($v1) */
    .word 0x8C630028 /* lw         $v1, 0x28($v1) */
    .word 0x1000FFF8 /* b          .L002199E8 */
    .word 0x24840001 /* addiu     $a0, $a0, 0x1 */
    .word 0x12200027 /* beqz       $s1, .L00219AAC */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x8E240000 /* lw         $a0, 0x0($s1) */
    .word 0x10800003 /* beqz       $a0, .L00219A28 */
    .word 0x00000000 /* nop */
    jal func_116F68
    .word 0x00000000 /* nop */
    .word 0x8E240004 /* lw         $a0, 0x4($s1) */
    .word 0x50800004 /* beql       $a0, $zero, .L00219A40 */
    .word 0x72202628 /* paddub    $a0, $s1, $zero */
    jal func_116F68
    .word 0x00000000 /* nop */
    .word 0x72202628 /* paddub     $a0, $s1, $zero */
    jal func_116F68
    .word 0x00000000 /* nop */
    .word 0x86020120 /* lh         $v0, 0x120($s0) */
    .word 0x2442FFFF /* addiu      $v0, $v0, -0x1 */
    .word 0xA6020120 /* sh         $v0, 0x120($s0) */
    .word 0x86030120 /* lh         $v1, 0x120($s0) */
    .word 0x14600003 /* bnez       $v1, .L00219A68 */
    .word 0x00000000 /* nop */
    .word 0x10000007 /* b          .L00219A80 */
    .word 0xA6000128 /* sh        $zero, 0x128($s0) */
    .word 0x86020128 /* lh         $v0, 0x128($s0) */
    .word 0x0043102A /* slt        $v0, $v0, $v1 */
    .word 0x14400004 /* bnez       $v0, .L00219A84 */
    .word 0x24050001 /* addiu     $a1, $zero, 0x1 */
    .word 0x2462FFFF /* addiu      $v0, $v1, -0x1 */
    .word 0xA6020128 /* sh         $v0, 0x128($s0) */
    .word 0x24050001 /* addiu      $a1, $zero, 0x1 */
    jal func_00217B50
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x8E190000 /* lw         $t9, 0x0($s0) */
    .word 0x24050001 /* addiu      $a1, $zero, 0x1 */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x10000002 /* b          .L00219AAC */
    .word 0x24020001 /* addiu     $v0, $zero, 0x1 */
    .word 0x70001628 /* paddub     $v0, $zero, $zero */
    .word 0x7BBF0020 /* lq         $ra, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0030 /* addiu     $sp, $sp, 0x30 */
}
}


#else

/* 0x00219990 */
extern "C" {
void func_00116F68(void *ptr);
void func_00217B50(void *self, int arg1);

typedef void (*VMethod28)(void *, int);

struct ActionListItem {
    char *text;
    char *extra_text;
    int val_8;
    int val_c;
    char byte_10;
    char pad_11[0x13];
    char byte_24;
    char pad_25[3];
    ActionListItem *next;
};

static ActionListItem *unlink_node(char *self_bytes, int index) {
    if (index == 0) {
        ActionListItem *node = *(ActionListItem **)(self_bytes + 0x11C);
        *(ActionListItem **)(self_bytes + 0x11C) = node->next;
        return node;
    }

    ActionListItem *curr = *(ActionListItem **)(self_bytes + 0x11C);
    int idx = 0;
    int target = index - 1;
    while (idx != target) {
        curr = curr->next;
        idx++;
    }
    ActionListItem *node = curr->next;
    curr->next = node->next;
    return node;
}

static void free_node(ActionListItem *node) {
    if (node->text != 0) {
        func_00116F68(node->text);
    }
    if (node->extra_text != 0) {
        func_00116F68(node->extra_text);
    }
    func_00116F68(node);
}

int func_00219990(void *self, int index) {
    char *self_bytes = (char *)self;
    short count = *(short *)(self_bytes + 0x120);

    if (index < 0 || index >= (int)count) {
        return 0;
    }

    ActionListItem *node = unlink_node(self_bytes, index);
    if (node == 0) {
        return 0;
    }

    free_node(node);

    short new_count = *(short *)(self_bytes + 0x120) - 1;
    *(short *)(self_bytes + 0x120) = new_count;

    if (new_count == 0) {
        *(short *)(self_bytes + 0x128) = 0;
    }
    if (new_count != 0) {
        short cur_128 = *(short *)(self_bytes + 0x128);
        if (cur_128 >= new_count) {
            *(short *)(self_bytes + 0x128) = new_count - 1;
        }
    }

    func_00217B50(self, 1);

    void **vtable = *(void ***)self;
    VMethod28 method28 = (VMethod28)*(void **)((char *)vtable + 0x28);
    method28(self, 1);

    return 1;
}
}


#endif
