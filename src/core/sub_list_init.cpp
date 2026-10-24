#include "sub_list.h"

void SubList::func_0013B710(void *param1, void *param2, int do_setup) {
    this->m_field18 = -1;
    this->m_field1C = -1;
    this->m_field3D = 0;
    if (do_setup) {
        func_0013B8A0(this, param1, param2);
    }
}

void SubList::func_0013B740(void *param1, int do_setup) {
    this->m_field18 = -1;
    this->m_field1C = -1;
    this->m_field3D = 0;
    if (do_setup) {
        func_0013BA60(this, param1);
    }
}
