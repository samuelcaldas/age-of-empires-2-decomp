#include "base_list.h"

#pragma exceptions off

extern "C" {
void func_366af0(void*, void*);
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
    virtual void Method9(int a = 0);
    virtual bool Method10();
    virtual void Method11();
    virtual bool Method12();
    virtual int Method13();
    virtual int Method14();
    virtual int Method15();
    virtual void v16();
    virtual void v17();
    virtual void Method18(int msg);
    virtual void Method19(int a, int b, int c);
    virtual void v20();
    virtual void* v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void Method26();
};

void BaseList::AddHead(void *item) {
    if (((WorldObj*)this->m_field4)->field_39 > 2) {
        func_366af0(&D_4E35DC, item);
        ((ListItemSimple*)item)->Method26();
        return;
    }
    ListNode *node = this->AllocNode();
    node->item = item;
    node->next = this->m_head;
    this->m_head = node;
    ((ListItemSimple*)item)->Method9(1);
}

void BaseList::AddTail(void *item) {
    if (((WorldObj*)this->m_field4)->field_39 > 2) {
        func_366af0(&D_4E35DC, item);
        ((ListItemSimple*)item)->Method26();
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
    ((ListItemSimple*)item)->Method9(1);
}

void BaseList::DeleteHead() {
    ListNode *node = this->m_head;
    if (!node) {
        return;
    }
    this->m_head = node->next;
    func_366af0(&D_4E35DC, node->item);
    ((ListItemSimple*)node->item)->Method26();
    this->FreeNode(node);
    if (this->m_head) {
        if (((WorldObj*)this->m_field4)->field_39 < 3) {
            ((ListItemSimple*)this->m_head->item)->Method9(0);
        }
    }
}
