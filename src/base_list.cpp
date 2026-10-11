#include "base_list.h"

void BaseList::Reset(int val) {
    this->m_capacity = val;
    this->m_count = 0;
}

BaseList::BaseList(int capacity) {
    if (this) {
        this->Free();
        this->m_capacity = 0;
        this->m_count = 0;
        if ((short)capacity > 0) {
            __vec_ctor(this);
        }
    }
}

void BaseList::Clear() {
    this->Free();
    this->m_capacity = 0;
    this->m_count = 0;
}
