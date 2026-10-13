#include "sub_list.h"

extern "C" {

float func_0013C430(SubList *self) {
    return self->m_field20_float;
}

float func_0013C440(SubList *self) {
    return self->m_field24_float;
}

float func_0013C450(SubList *self) {
    return self->m_field28_float;
}

void func_0013C460(SubList *self, unsigned char val) {
    self->m_field3C = val;
}

}
