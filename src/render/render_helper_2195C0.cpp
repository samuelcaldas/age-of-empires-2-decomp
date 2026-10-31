#pragma exceptions off
#include "sub_list.h"

#if defined(__mips__)

/* 0x002195C0 */
extern "C" {
void func_1143F8();
void func_0011ACD0();
void func_116F68();
void func_0011B170();
void strcpy();
void strcmp();
void func_00217B50();

asm int func_002195C0(void *self, int arg1, const char *arg2, const char *arg3, int arg4, int arg5) {

    .word 0x27BDFF80 /* addiu      $sp, $sp, -0x80 */
    .word 0x7FBF0070 /* sq         $ra, 0x70($sp) */
    .word 0x7FB60060 /* sq         $s6, 0x60($sp) */
    .word 0x7FB50050 /* sq         $s5, 0x50($sp) */
    .word 0x7FB40040 /* sq         $s4, 0x40($sp) */
    .word 0x7FB30030 /* sq         $s3, 0x30($sp) */
    .word 0x7FB20020 /* sq         $s2, 0x20($sp) */
    .word 0x7FB10010 /* sq         $s1, 0x10($sp) */
    .word 0x7080B628 /* paddub     $s6, $a0, $zero */
    .word 0x70A0AE28 /* paddub     $s5, $a1, $zero */
    .word 0x24040001 /* addiu      $a0, $zero, 0x1 */
    .word 0x2405002C /* addiu      $a1, $zero, 0x2C */
    .word 0x70C0A628 /* paddub     $s4, $a2, $zero */
    .word 0x70E09E28 /* paddub     $s3, $a3, $zero */
    .word 0x71009628 /* paddub     $s2, $t0, $zero */
    .word 0x71208E28 /* paddub     $s1, $t1, $zero */
    jal func_1143F8
    .word 0x7FB00000 /* sq        $s0, 0x0($sp) */
    .word 0x70408628 /* paddub     $s0, $v0, $zero */
    .word 0x16000003 /* bnez       $s0, .L0021961C */
    .word 0x00000000 /* nop */
    .word 0x10000096 /* b          .L00219870 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x86C20174 /* lh         $v0, 0x174($s6) */
    .word 0x10400008 /* beqz       $v0, .L00219644 */
    .word 0x00000000 /* nop */
    .word 0x0002143C /* dsll32     $v0, $v0, 16 */
    .word 0x0002143F /* dsra32     $v0, $v0, 16 */
    .word 0x24440001 /* addiu      $a0, $v0, 0x1 */
    jal func_1143F8
    .word 0x24050001 /* addiu     $a1, $zero, 0x1 */
    .word 0x1000000F /* b          .L0021967C */
    .word 0xAE020000 /* sw        $v0, 0x0($s0) */
    .word 0x16800007 /* bnez       $s4, .L00219664 */
    .word 0x72802628 /* paddub    $a0, $s4, $zero */
    .word 0x24040001 /* addiu      $a0, $zero, 0x1 */
    jal func_1143F8
    .word 0x70802E28 /* paddub    $a1, $a0, $zero */
    .word 0x10000008 /* b          .L0021967C */
    .word 0xAE020000 /* sw        $v0, 0x0($s0) */
    .word 0x72802628 /* paddub     $a0, $s4, $zero */
    jal func_0011ACD0
    .word 0x00000000 /* nop */
    .word 0x24440001 /* addiu      $a0, $v0, 0x1 */
    jal func_1143F8
    .word 0x24050001 /* addiu     $a1, $zero, 0x1 */
    .word 0xAE020000 /* sw         $v0, 0x0($s0) */
    .word 0x8E020000 /* lw         $v0, 0x0($s0) */
    .word 0x14400005 /* bnez       $v0, .L00219698 */
    .word 0x00000000 /* nop */
    jal func_116F68
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x10000077 /* b          .L00219870 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x12600010 /* beqz       $s3, .L002196DC */
    .word 0x00000000 /* nop */
    jal func_0011ACD0
    .word 0x72602628 /* paddub    $a0, $s3, $zero */
    .word 0x24440001 /* addiu      $a0, $v0, 0x1 */
    jal func_1143F8
    .word 0x24050001 /* addiu     $a1, $zero, 0x1 */
    .word 0xAE020004 /* sw         $v0, 0x4($s0) */
    .word 0x8E020004 /* lw         $v0, 0x4($s0) */
    .word 0x14400007 /* bnez       $v0, .L002196DC */
    .word 0x00000000 /* nop */
    jal func_116F68
    .word 0x8E040000 /* lw        $a0, 0x0($s0) */
    jal func_116F68
    .word 0x72002628 /* paddub    $a0, $s0, $zero */
    .word 0x10000066 /* b          .L00219870 */
    .word 0x70001628 /* paddub    $v0, $zero, $zero */
    .word 0x16800004 /* bnez       $s4, .L002196F0 */
    .word 0x00000000 /* nop */
    .word 0x8E020000 /* lw         $v0, 0x0($s0) */
    .word 0x10000011 /* b          .L00219730 */
    .word 0xA0400000 /* sb        $zero, 0x0($v0) */
    .word 0x86C20174 /* lh         $v0, 0x174($s6) */
    .word 0x1040000B /* beqz       $v0, .L00219724 */
    .word 0x00000000 /* nop */
    .word 0x8E040000 /* lw         $a0, 0x0($s0) */
    .word 0x0002343C /* dsll32     $a2, $v0, 16 */
    .word 0x0006343F /* dsra32     $a2, $a2, 16 */
    jal func_0011B170
    .word 0x72802E28 /* paddub    $a1, $s4, $zero */
    .word 0x86C30174 /* lh         $v1, 0x174($s6) */
    .word 0x8E020000 /* lw         $v0, 0x0($s0) */
    .word 0x00431021 /* addu       $v0, $v0, $v1 */
    .word 0x10000004 /* b          .L00219730 */
    .word 0xA0400000 /* sb        $zero, 0x0($v0) */
    .word 0x8E040000 /* lw         $a0, 0x0($s0) */
    jal strcpy
    .word 0x72802E28 /* paddub    $a1, $s4, $zero */
    .word 0x12600004 /* beqz       $s3, .L00219744 */
    .word 0x00000000 /* nop */
    .word 0x8E040004 /* lw         $a0, 0x4($s0) */
    jal strcpy
    .word 0x72602E28 /* paddub    $a1, $s3, $zero */
    .word 0xAE120008 /* sw         $s2, 0x8($s0) */
    .word 0xAE000028 /* sw         $zero, 0x28($s0) */
    .word 0xAE11000C /* sw         $s1, 0xC($s0) */
    .word 0xA2000010 /* sb         $zero, 0x10($s0) */
    .word 0xA2000024 /* sb         $zero, 0x24($s0) */
    .word 0x8ED1011C /* lw         $s1, 0x11C($s6) */
    .word 0x16200003 /* bnez       $s1, .L0021976C */
    .word 0x00000000 /* nop */
    .word 0x10000036 /* b          .L00219840 */
    .word 0xAED0011C /* sw        $s0, 0x11C($s6) */
    .word 0x8EC20198 /* lw         $v0, 0x198($s6) */
    .word 0x10400017 /* beqz       $v0, .L002197D0 */
    .word 0x00000000 /* nop */
    .word 0x1000000F /* b          .L002197B8 */
    .word 0x70009628 /* paddub    $s2, $zero, $zero */
    .word 0x8E250000 /* lw         $a1, 0x0($s1) */
    jal strcmp
    .word 0x8E040000 /* lw        $a0, 0x0($s0) */
    .word 0x04430008 /* bgezl      $v0, .L002197B0 */
    .word 0x72209628 /* paddub    $s2, $s1, $zero */
    .word 0x12400003 /* beqz       $s2, .L002197A4 */
    .word 0xAE110028 /* sw        $s1, 0x28($s0) */
    .word 0x10000008 /* b          .L002197C0 */
    .word 0xAE500028 /* sw        $s0, 0x28($s2) */
    .word 0x10000006 /* b          .L002197C0 */
    .word 0xAED0011C /* sw        $s0, 0x11C($s6) */
    .word 0x72209628 /* paddub     $s2, $s1, $zero */
    .word 0x8E310028 /* lw         $s1, 0x28($s1) */
    .word 0x00000000 /* nop */
    .word 0x1620FFF1 /* bnez       $s1, .L00219780 */
    .word 0x00000000 /* nop */
    .word 0x1620001F /* bnez       $s1, .L00219840 */
    .word 0x00000000 /* nop */
    .word 0x1000001D /* b          .L00219840 */
    .word 0xAE500028 /* sw        $s0, 0x28($s2) */
    .word 0x16A00004 /* bnez       $s5, .L002197E4 */
    .word 0x00000000 /* nop */
    .word 0xAE110028 /* sw         $s1, 0x28($s0) */
    .word 0x10000018 /* b          .L00219840 */
    .word 0xAED0011C /* sw        $s0, 0x11C($s6) */
    .word 0x86C20120 /* lh         $v0, 0x120($s6) */
    .word 0x02A2102A /* slt        $v0, $s5, $v0 */
    .word 0x1440000A /* bnez       $v0, .L00219818 */
    .word 0x70001E28 /* paddub    $v1, $zero, $zero */
    .word 0x8E220028 /* lw         $v0, 0x28($s1) */
    .word 0x54400004 /* bnel       $v0, $zero, .L0021980C */
    .word 0x70408E28 /* paddub    $s1, $v0, $zero */
    .word 0x1000000F /* b          .L00219840 */
    .word 0xAE300028 /* sw        $s0, 0x28($s1) */
    .word 0x70408E28 /* paddub     $s1, $v0, $zero */
    .word 0x1000FFFA /* b          .L002197F8 */
    .word 0x8E220028 /* lw        $v0, 0x28($s1) */
    .word 0x70001E28 /* paddub     $v1, $zero, $zero */
    .word 0x26A2FFFF /* addiu      $v0, $s5, -0x1 */
    .word 0x14620005 /* bne        $v1, $v0, .L00219834 */
    .word 0x00000000 /* nop */
    .word 0x8E220028 /* lw         $v0, 0x28($s1) */
    .word 0xAE020028 /* sw         $v0, 0x28($s0) */
    .word 0x10000004 /* b          .L00219840 */
    .word 0xAE300028 /* sw        $s0, 0x28($s1) */
    .word 0x8E310028 /* lw         $s1, 0x28($s1) */
    .word 0x1000FFF8 /* b          .L0021981C */
    .word 0x24630001 /* addiu     $v1, $v1, 0x1 */
    .word 0x86C20120 /* lh         $v0, 0x120($s6) */
    .word 0x24050001 /* addiu      $a1, $zero, 0x1 */
    .word 0x72C02628 /* paddub     $a0, $s6, $zero */
    .word 0x24420001 /* addiu      $v0, $v0, 0x1 */
    jal func_00217B50
    .word 0xA6C20120 /* sh        $v0, 0x120($s6) */
    .word 0x8ED90000 /* lw         $t9, 0x0($s6) */
    .word 0x24050001 /* addiu      $a1, $zero, 0x1 */
    .word 0x8F390028 /* lw         $t9, 0x28($t9) */
    .word 0x0320F809 /* jalr       $t9 */
    .word 0x72C02628 /* paddub    $a0, $s6, $zero */
    .word 0x24020001 /* addiu      $v0, $zero, 0x1 */
    .word 0x7BBF0070 /* lq         $ra, 0x70($sp) */
    .word 0x7BB60060 /* lq         $s6, 0x60($sp) */
    .word 0x7BB50050 /* lq         $s5, 0x50($sp) */
    .word 0x7BB40040 /* lq         $s4, 0x40($sp) */
    .word 0x7BB30030 /* lq         $s3, 0x30($sp) */
    .word 0x7BB20020 /* lq         $s2, 0x20($sp) */
    .word 0x7BB10010 /* lq         $s1, 0x10($sp) */
    .word 0x7BB00000 /* lq         $s0, 0x0($sp) */
    .word 0x03E00008 /* jr         $ra */
    .word 0x27BD0080 /* addiu     $sp, $sp, 0x80 */
}
}


#else

/* 0x002195C0 */
extern "C" {
void *func_001143F8(int n, int size);
void func_00116F68(void *ptr);
int func_0011ACD0(const char *str);
char *strcpy(char *dest, const char *src);
void *memcpy(void *dest, const void *src, unsigned int n);
int strcmp(const char *s1, const char *s2);
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

static ActionListItem *create_node(void *self, const char *str_s4, const char *str_s3, int val_s2, int val_s1) {
    ActionListItem *node = (ActionListItem *)func_001143F8(1, 0x2C);
    if (node == 0) {
        return 0;
    }

    char *self_bytes = (char *)self;
    short len_174 = *(short *)(self_bytes + 0x174);
    if (len_174 != 0) {
        node->text = (char *)func_001143F8(len_174 + 1, 1);
    } else if (str_s4 == 0) {
        node->text = (char *)func_001143F8(1, 1);
    } else {
        int len_s4 = func_0011ACD0(str_s4);
        node->text = (char *)func_001143F8(len_s4 + 1, 1);
    }

    if (node->text == 0) {
        func_00116F68(node);
        return 0;
    }

    if (str_s3 != 0) {
        int len_s3 = func_0011ACD0(str_s3);
        node->extra_text = (char *)func_001143F8(len_s3 + 1, 1);
        if (node->extra_text == 0) {
            func_00116F68(node->text);
            func_00116F68(node);
            return 0;
        }
    }

    if (str_s4 == 0) {
        node->text[0] = '\0';
    } else if (len_174 != 0) {
        memcpy(node->text, str_s4, len_174);
        node->text[len_174] = '\0';
    } else {
        strcpy(node->text, str_s4);
    }

    if (str_s3 != 0) {
        strcpy(node->extra_text, str_s3);
    }

    node->val_8 = val_s2;
    node->next = 0;
    node->val_c = val_s1;
    node->byte_10 = 0;
    node->byte_24 = 0;
    return node;
}

static void insert_sorted(void *self, ActionListItem *node) {
    char *self_bytes = (char *)self;
    ActionListItem *curr = *(ActionListItem **)(self_bytes + 0x11C);
    ActionListItem *prev = 0;

    while (curr != 0) {
        if (strcmp(curr->text, node->text) >= 0) {
            if (prev == 0) {
                node->next = curr;
                *(ActionListItem **)(self_bytes + 0x11C) = node;
            } else {
                node->next = curr;
                prev->next = node;
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    if (prev != 0) {
        prev->next = node;
    }
}

static void insert_at_index(void *self, ActionListItem *node, int target_index) {
    char *self_bytes = (char *)self;
    ActionListItem *curr = *(ActionListItem **)(self_bytes + 0x11C);

    if (target_index == 0) {
        node->next = curr;
        *(ActionListItem **)(self_bytes + 0x11C) = node;
        return;
    }

    short total_count = *(short *)(self_bytes + 0x120);
    if (target_index < total_count) {
        int idx = 0;
        while (curr != 0) {
            if (idx == target_index - 1) {
                node->next = curr->next;
                curr->next = node;
                return;
            }
            curr = curr->next;
            idx++;
        }
    } else {
        while (curr->next != 0) {
            curr = curr->next;
        }
        curr->next = node;
    }
}

int func_002195C0(void *self, int insert_pos, const char *str_s4, const char *str_s3, int val_s2, int val_s1) {
    ActionListItem *node = create_node(self, str_s4, str_s3, val_s2, val_s1);
    if (node == 0) {
        return 0;
    }

    char *self_bytes = (char *)self;
    ActionListItem *head = *(ActionListItem **)(self_bytes + 0x11C);

    if (head == 0) {
        *(ActionListItem **)(self_bytes + 0x11C) = node;
    } else if (*(int *)(self_bytes + 0x198) != 0) {
        insert_sorted(self, node);
    } else {
        insert_at_index(self, node, insert_pos);
    }

    short new_count = *(short *)(self_bytes + 0x120) + 1;
    *(short *)(self_bytes + 0x120) = new_count;
    func_00217B50(self, 1);

    void **vtable = *(void ***)self;
    VMethod28 method28 = (VMethod28)*(void **)((char *)vtable + 0x28);
    method28(self, 1);

    return 1;
}
}


#endif
