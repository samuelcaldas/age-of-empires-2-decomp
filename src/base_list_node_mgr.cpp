#include "base_list.h"

extern "C" {
void func_366af0(void*, void*);
void AllocNode__8BaseListFPv(void*);
extern int D_4E35DC;
}

asm void BaseList::AddHead(void *item) {
    .set noreorder
    .set noat
    .word 0x27BDFFD0
    .word 0x7FBF0020
    .word 0x7FB10010
    .word 0x7FB00000
    .word 0x8C820004
    .word 0x70808E28
    .word 0x90420039
    .word 0x28410003
    .word 0x14200009
    .word 0x70A08628
    jal func_366af0
    .word 0x27848E1C
    .word 0x8E190000
    .word 0x8F390068
    .word 0x0320F809
    .word 0x72002628
    .word 0x1000000D
    .word 0x7BBF0020
    jal AllocNode__8BaseListFPv
    .word 0x00000000
    .word 0xAC500000
    .word 0x8E230008
    .word 0x24050001
    .word 0xAC430004
    .word 0xAE220008
    .word 0x8E190000
    .word 0x8F390024
    .word 0x0320F809
    .word 0x72002628
    .word 0x7BBF0020
    .word 0x7BB10010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0030
    .set reorder
    .set at
}

void BaseList::AddTail(void *item) {
    if (((WorldObj*)this->m_field4)->field_39 > 2) {
        func_366af0(&D_4E35DC, item);
        ((ListItem*)item)->Method26();
        return;
    }
    ListNode *node = this->AllocNode();
    node->item = item;
    node->next = 0;
    ListNode *curr = this->m_head;
    if (curr) {
        while (curr) {
            if (!curr->next) {
                curr->next = node;
                break;
            }
            curr = curr->next;
        }
    } else {
        this->m_head = node;
    }
    ((ListItem*)item)->Method9((void*)1);
}

void BaseList::DeleteHead() {
    ListNode *node = this->m_head;
    if (!node) {
        return;
    }
    this->m_head = node->next;
    func_366af0(&D_4E35DC, node->item);
    ((ListItem*)node->item)->Method26();
    this->FreeNode(node);
    if (this->m_head) {
        if (((WorldObj*)this->m_field4)->field_39 < 3) {
            ((ListItem*)this->m_head->item)->Method9((void*)0);
        }
    }
}
