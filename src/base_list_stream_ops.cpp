#include "sub_list.h"

extern "C" {
void func_1DC180(void*);
void func_1DC2E0(void*, void*);
void func_226d90(void*, void*, int);
void Load__8BaseListFPv(void*, void*);
void* func_3668C0(void*, void*);
void func_266840(void*);
void Action__8BaseListFv(void*);
void func_1DC6B0(void*, void*);
void func_226f70(void*, void*, int);
void Save__8BaseListFPv(void*, void*);
void func_1DCAA0(void*);
void Free__8BaseListFv(void*);
void func_267DD0(void*);
}

int SubList::SetupSpatial() {
    func_1DC180(this);
    this->m_fieldC5 = 0;
    this->m_fieldCC = (BaseList*)this->v199();
    return 1;
}

int SubList::Setup(void *stream) {
    func_1DC2E0(this, stream);
    char temp;
    func_226d90(stream, &temp, 1);
    func_226d90(stream, &this->m_fieldC5, 1);
    this->m_fieldCC = (BaseList*)this->v199();
    Load__8BaseListFPv(this->m_fieldCC, stream);
    return 1;
}

extern "C" char D_10B68F0[1024];

void* SubList::CreateSubList() {
    return func_3668C0(D_10B68F0, this);
}

void SubList::Action() {
    func_266840(this);
    Action__8BaseListFv(this->m_fieldCC);
}

void SubList::Save(void *stream) {
    func_1DC6B0(this, stream);
    char zero = 0;
    func_226f70(stream, &zero, 1);
    func_226f70(stream, &this->m_fieldC5, 1);
    Save__8BaseListFPv(this->m_fieldCC, stream);
}

void SubList::Free() {
    func_1DCAA0(this);
    Free__8BaseListFv(this->m_fieldCC);
}

void SubList::Teardown() {
    Free__8BaseListFv(this->m_fieldCC);
    func_267DD0(this);
}

void SubList::Noop() {
}

void SubList::Notify(void *other) {
    if (other != this) {
        this->v190(other, 0, -1);
        this->m_fieldC5++;
    }
}
