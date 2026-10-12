#include "base_list.h"

extern "C" {
void func_366af0(void*, void*);
extern int D_4E35DC;
}

void BaseList::AddHead(void *item) {
    if (((WorldObj*)this->m_field4)->field_39 > 2) {
        func_366af0(&D_4E35DC, item);
        ((ListItem*)item)->Method26();
        return;
    }
    ListNode *node = this->AllocNode();
    node->item = item;
    node->next = this->m_head;
    this->m_head = node;
    ((ListItem*)item)->Method9(1);
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
    ((ListItem*)item)->Method9(1);
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
            ((ListItem*)this->m_head->item)->Method9(0);
        }
    }
}
