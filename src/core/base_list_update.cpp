#include "base_list.h"

int BaseList::Update() {
    if (!this->m_head) {
        return 1;
    }
    int res = ((ListItem*)this->m_head->item)->Method10();
    ListNode *node = this->m_head->next;
    while (node) {
        ((ListItem*)node->item)->Method11();
        node = node->next;
    }
    if ((unsigned char)res == 1) {
        func_139580(this);
    }
    return res;
}

int BaseList::Update2() {
    if (!this->m_head) {
        return 1;
    }
    int res = ((ListItem*)this->m_head->item)->Method12();
    if (!this->m_head) {
        return res;
    }
    ListNode *node = this->m_head->next;
    while (node) {
        ((ListItem*)node->item)->Method11();
        node = node->next;
    }
    if ((unsigned char)res == 1) {
        func_139580(this);
    }
    return res;
}
