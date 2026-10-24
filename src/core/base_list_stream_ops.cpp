#include "sub_list.h"

#pragma exceptions off

extern "C" {
    extern char D_10B68F0[];
    void func_1DC180(void *self);
    void func_1DC2E0(void *self, void *stream);
    void func_1DC6B0(void *self, void *stream);
    void func_1DCAA0(void *self);
    void func_266840(void *self);
    void func_267DD0(void *self);
    void* func_3668C0(void *obj, void *item);
    void func_00226D90(void *stream, void *dst, int size);
    void func_00226F70(void *stream, void *src, int size);
}

int SubList::SetupSpatial() {
    func_1DC180(this);
    this->m_fieldC5 = 0;
    this->m_fieldCC = this->v201();
    return 1;
}

int SubList::Setup(void *stream) {
    char dummy;
    func_1DC2E0(this, stream);
    func_00226D90(stream, &dummy, 1);
    func_00226D90(stream, &this->m_fieldC5, 1);
    this->m_fieldCC = this->v201();
    this->m_fieldCC->Load(stream);
    return 1;
}

void* SubList::CreateSubList() {
    return func_3668C0(D_10B68F0, this);
}

void SubList::Action() {
    func_266840(this);
    this->m_fieldCC->Action();
}

void SubList::Save(void *stream) {
    char dummy;
    func_1DC6B0(this, stream);
    func_00226F70(stream, &(dummy = 0), 1);
    func_00226F70(stream, &this->m_fieldC5, 1);
    this->m_fieldCC->Save(stream);
}

void SubList::Free() {
    func_1DCAA0(this);
    this->m_fieldCC->Free();
}

void SubList::Teardown() {
    this->m_fieldCC->Free();
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
