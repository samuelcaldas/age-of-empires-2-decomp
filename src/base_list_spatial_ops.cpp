#include "base_list.h"

extern "C" {
void func_1DBEA0(void*, void*, void*, int, float, float, float);
void func_139C80(void*, void*, void*, float, float, float);
void func_1DBFC0(void*, void*, void*, int);
void func_139CC0(void*, void*, void*);
void func_3669F0(void*, void*);
void func_2C2DC0(int);
void func_1DC0B0(void*, int);
extern char D_10B68F0[];
}

void BaseList::SetupSpatial(void *obj1, void *obj2, int flag, float x, float y, float z) {
    this->m_fieldC8 = 0;
    func_1DBEA0(this, obj1, obj2, 0, x, y, z);
    if (flag) {
        func_139C80(this, obj1, obj2, x, y, z);
    }
}

void BaseList::Setup(void *obj1, void *obj2, int flag) {
    this->m_fieldC8 = 0;
    func_1DBFC0(this, obj1, obj2, 0);
    if (flag) {
        func_139CC0(this, obj1, obj2);
    }
}

void BaseList::Cleanup(int flag) {
    if (this->m_fieldCC) {
        func_3669F0(D_10B68F0, this->m_fieldCC);
        ((ListItem*)this->m_fieldCC)->Method11();
        this->m_fieldCC = 0;
    }
    if (this->m_fieldC8) {
        func_2C2DC0(this->m_fieldC8);
        this->m_fieldC8 = 0;
    }
    if (flag) {
        func_1DC0B0(this, flag);
    }
}
