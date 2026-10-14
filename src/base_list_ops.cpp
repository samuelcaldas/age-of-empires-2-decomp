#include "base_list.h"

extern "C" {
void func_366af0(void*, void*);
extern int D_4E35DC;
}

void* BaseList::RemoveHead() {
    ListNode *node = this->m_head;
    void *item = 0;
    if (node) {
        this->m_head = node->next;
        item = node->item;
        this->FreeNode(node);
        if (this->m_head) {
            if (((WorldObj*)this->m_field4)->field_39 < 3) {
                ((ListItem*)this->m_head->item)->Method9(0);
            }
        }
    }
    return item;
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

int BaseList::Contains(int type) {
    ListNode *curr = this->m_head;
    while (curr) {
        if (((ListItem*)curr->item)->v8() == type) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
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
