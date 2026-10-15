#include "sub_list.h"

extern "C" {
    int func_1dd700();
    void func_1dd780(void *self);
    void func_00267530(void *self, int arg1);
    void func_1df2c0(void *self, int msg);
    void* func_333b30(void *container, int id);
    float func_13c430(void *item);
}

struct VBaseList {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* CreateItem(void *s0, void *other, float x, float y, float z);
    virtual void Update();
    virtual int Update2();
    virtual void Method7(char *out);
    virtual void Broadcast(int msg);
    virtual void Broadcast4(int a, int b, int c);
};

int SubList::func_0013AA80() {
    int s0 = (unsigned char)func_1dd700();
    if (this->m_field39 >= 3) {
        if (this->m_fieldCC->m_head) {
            this->m_fieldCC->Free();
        }
    } else if (!this->m_fieldCC->m_head) {
        if (this->m_field39 == 2 && this->m_field4->m_fieldCC_short != -1) {
            this->v193(this->m_field4->m_fieldCC_short);
        }
    } else if (this->m_field1C) {
        ((VBaseList*)this->m_fieldCC)->Update();
    } else {
        int res = ((VBaseList*)this->m_fieldCC)->Update2();
        if ((unsigned char)res == 3 || (unsigned char)res == 1) {
            this->m_fieldCC->DeleteHead();
        }
    }
    func_1dd780(this);
    return s0;
}

void SubList::func_0013AB90(int arg1) {
    this->v46();
    func_00267530(this, arg1);
    this->v196(0);
}

void SubList::func_0013ABF0(int msg) {
    ((VBaseList*)this->m_fieldCC)->Broadcast(msg);
    func_1df2c0(this, msg);
}

int SubList::func_0013AC40() {
    return this->m_fieldCC->HasItems() != 0;
}

int SubList::func_0013AC70() {
    SpatialObj1 *item = (SpatialObj1*)this->m_fieldCC->GetHeadItem();
    return item ? item->m_field4 : -1;
}

int SubList::func_0013ACA0() {
    if (this->m_field64 != -1) {
        void *res = func_333b30(this->m_field8->m_fieldB98, this->m_field64);
        if (res) {
            return *(int*)((char*)res + 0x298) == -1 ? 1 : 0;
        }
    }
    SpatialObj1 *head = (SpatialObj1*)this->m_fieldCC->GetHeadItem();
    if (!head) {
        return 1;
    }
    unsigned char c = head->m_fieldC;
    if (c < 4 || (unsigned char)(c - 13) < 2) {
        return 1;
    }
    if (head->m_field4 != 0x6B) {
        return 0;
    }
    if (head->v21()) {
        return 1;
    }
    return func_13c430(head) != -1.0f;
}

void* SubList::func_0013ADC0() {
    SpatialObj1 *head = (SpatialObj1*)this->m_fieldCC->GetHeadItem();
    if (head) {
        return head->v21();
    }
    return 0;
}
