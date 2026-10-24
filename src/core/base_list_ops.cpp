#include "base_list.h"

#pragma exceptions off

extern "C" {
void func_366af0(void*, void*);
void FreeNode__8BaseListFP8ListNode(void*, void*);
extern int D_4E35DC;
}

struct ListItemSimple {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int Action();
    virtual void Save(void *stream);
    virtual short v8();
    virtual void Method9(void *a = 0);
    virtual bool Method10();
    virtual void Method11();
    virtual bool Method12();
    virtual int Method13();
    virtual int Method14();
    virtual int Method15();
};

void* BaseList::RemoveHead() {
    void *item = 0;
    ListNode *head = this->m_head;
    if (head) {
        this->m_head = head->next;
        item = head->item;
        this->FreeNode(head);
        if (this->m_head && ((WorldObj*)this->m_field4)->field_39 < 3) {
            ((ListItemSimple*)this->m_head->item)->Method9(0);
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
    for (ListNode *curr = this->m_head; curr; curr = curr->next) {
        if (((ListItemSimple*)curr->item)->v8() == type) {
            return 1;
        }
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
        return ((ListItemSimple*)this->m_head->item)->Method15();
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
    for (ListNode *curr = this->m_head; curr; curr = curr->next) {
        if (((ListItemSimple*)curr->item)->v8() == type) {
            return curr->item;
        }
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
