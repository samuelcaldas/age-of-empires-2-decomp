#include "base_list.h"

void BaseList::Reset(int val) {
    this->m_capacity = val;
    this->m_head = 0;
}

BaseList::BaseList(int capacity) {
    if (this) {
        this->vtable = (void*)&__vt__8BaseList;
        this->Free();
        this->m_capacity = 0;
        this->m_head = 0;
        if ((short)capacity > 0) {
            __vec_ctor(this);
        }
    }
}

void BaseList::Clear() {
    this->Free();
    this->m_capacity = 0;
    this->m_head = 0;
}

ListNode* BaseList::AllocNode() {
    for (int i = 0; i < 1000; i++) {
        ListNode *node = &s_node_pool[i];
        if (node->item) {
            continue;
        }
        memset(node, 0, 8);
        return node;
    }
    return 0;
}

void BaseList::FreeNode(ListNode *node) {
    int high = 4200;
    int low = 0;
    while (1) {
        int mid = (low + high) / 2;
        ListNode *mid_node = &s_node_pool[mid];
        if (node < mid_node) {
            high = mid - 1;
        } else if (node > mid_node) {
            low = mid + 1;
        } else {
            mid_node->item = 0;
            return;
        }
    }
}

void BaseList::Load(void *stream) {
    void *item;
    short count;

    if (this->m_head) {
        this->Free();
    }
    ListNode *prev = 0;
    while (1) {
        func_226d90(stream, &count, 2);
        if (count == 0) {
            break;
        }
        item = ((BaseItemCreator*)this)->CreateItem(stream, count);
        ListNode *node = this->AllocNode();
        node->item = item;
        node->next = 0;
        if (prev) {
            prev->next = node;
        } else {
            this->m_head = node;
        }
        prev = node;
    }
}

void BaseList::Action() {
    for (ListNode *node = this->m_head; node; node = node->next) {
        ((ListItem*)node->item)->Action();
    }
}

void BaseList::Save(void *stream) {
    for (ListNode *node = this->m_head; node; node = node->next) {
        ((ListItem*)node->item)->Save(stream);
    }
    short term = 0;
    func_226f70(stream, &term, 2);
}

void BaseList::Free() {
    while (this->m_head) {
        func_139580(this);
    }
}
