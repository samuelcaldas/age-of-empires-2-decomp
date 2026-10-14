#include "base_list.h"

extern "C" {
void func_366af0(void*, void*);
extern int D_4E35DC;
}

asm void* BaseList::RemoveHead() {
    .set noreorder
    .set noat
    .word 0x27BDFFD0
    .word 0x7FBF0020
    .word 0x7FB10010
    .word 0x7FB00000
    .word 0x8C850008
    .word 0x70808E28
    .word 0x10A00012
    .word 0x70000628
    .word 0x8CA20004
    .word 0xAE220008
    .word 0x0C04E2D4
    .word 0x8CB00000
    .word 0x8E230008
    .word 0x1060000C
    .word 0x72001628
    .word 0x8E220004
    .word 0x90420039
    .word 0x28410003
    .word 0x10200006
    .word 0x00000000
    .word 0x8C640000
    .word 0x8C990000
    .word 0x8F390024
    .word 0x0320F809
    .word 0x70002E28
    .word 0x72001628
    .word 0x7FBF0020
    .word 0x7BB10010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0030
    .set reorder
    .set at
}

void BaseList::PushHead(void *item) {
    if (((WorldObj*)this->m_field4)->field_39 > 2) {
        func_366af0(&D_4E35DC, item);
        ((ListItem*)item)->Method26();
        return;
    }
    ListNode *node = this->AllocNode();
    node->item = item;
    node->next = this->m_head;
    this->m_head = node;
}

int BaseList::HasItems() {
    return this->m_head ? 1 : 0;
}

asm int BaseList::Contains(int type) {
    .set noreorder
    .set noat
    .word 0x27BDFFD0
    .word 0x7BBF0020
    .word 0x7BB10010
    .word 0x7BB00000
    .word 0x8C900008
    .word 0x1000000E
    .word 0x70A08E28
    .word 0x8E040000
    .word 0x8C990000
    .word 0x8F390020
    .word 0x0320F809
    .word 0x00000000
    .word 0x0002143C
    .word 0x0002143F
    .word 0x16220003
    .word 0x00000000
    .word 0x10000006
    .word 0x24020001
    .word 0x8E100004
    .word 0x00000000
    .word 0x1600FFF2
    .word 0x00000000
    .word 0x70001628
    .word 0x7BBF0020
    .word 0x7BB10010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0030
    .set reorder
    .set at
}

int BaseList::CallMethod13() {
    if (this->m_head) {
        return ((ListItem*)this->m_head->item)->Method13();
    }
    return 0;
}

int BaseList::CallMethod14() {
    if (this->m_head) {
        return ((ListItem*)this->m_head->item)->Method14();
    }
    return 0;
}

asm int BaseList::CallMethod15() {
    .set noreorder
    .set noat
    .word 0x27BDFFF0
    .word 0x7FBF0000
    .word 0x8C820008
    .word 0x50400009
    .word 0x70001628
    .word 0x8C440000
    .word 0x8C990000
    .word 0x8F39003C
    .word 0x0320F809
    .word 0x00000000
    .word 0x10000003
    .word 0x7BBF0000
    .word 0x70001628
    .word 0x7BBF0000
    .word 0x03E00008
    .word 0x27BD0010
    .set reorder
    .set at
}

void* BaseList::GetHeadItem() {
    if (this->m_head) {
        return this->m_head->item;
    }
    return 0;
}

asm void* BaseList::FindItem(int type) {
    .set noreorder
    .set noat
    .word 0x27BDFFD0
    .word 0x7FBF0020
    .word 0x7FB10010
    .word 0x7FB00000
    .word 0x8C900008
    .word 0x1000000E
    .word 0x70A08E28
    .word 0x8E040000
    .word 0x8C990000
    .word 0x8F390020
    .word 0x0320F809
    .word 0x00000000
    .word 0x0002143C
    .word 0x0002143F
    .word 0x16220003
    .word 0x00000000
    .word 0x10000006
    .word 0x8E020000
    .word 0x8E100004
    .word 0x00000000
    .word 0x1600FFF2
    .word 0x00000000
    .word 0x70001628
    .word 0x7BBF0020
    .word 0x7BB10010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0030
    .set reorder
    .set at
}

int BaseList::GetHeadItemField30() {
    if (this->m_head) {
        return ((ListItem*)this->m_head->item)->field_30;
    }
    return 0;
}

void BaseList::Broadcast(int msg) {
    ListNode *curr = this->m_head;
    while (curr) {
        ((ListItem*)curr->item)->Method18(msg);
        curr = curr->next;
    }
}

void BaseList::Broadcast4(int a, int b, int c) {
    ListNode *curr = this->m_head;
    while (curr) {
        ((ListItem*)curr->item)->Method19(a, b, c);
        curr = curr->next;
    }
}

void BaseList::Method7(char *out) {
    *out = 0;
}
