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

int BaseList::CallMethod15() {
    if (this->m_head) {
        return ((ListItem*)this->m_head->item)->Method15();
    }
    return 0;
}

void* BaseList::GetHeadItem() {
    if (this->m_head) {
        return this->m_head->item;
    }
    return 0;
}

void* BaseList::FindItem(int type) {
    ListNode *curr = this->m_head;
    while (curr) {
        if (((ListItem*)curr->item)->v8() == type) {
            return curr->item;
        }
        curr = curr->next;
    }
    return 0;
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
