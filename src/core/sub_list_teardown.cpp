#include "sub_list.h"

extern "C" {
    extern char D_4D7560[];
    extern char D_10B68F0[];
    void func_3669F0(void *obj, void *item);
    void __vec_ctor(void *self);
    void* func_0013B770(SubList *self, int flag);
}

static inline void do_teardown(SubList *self) {
    self->v21(0);
    self->v22(0);
    if (self->m_field34) {
        func_3669F0(D_10B68F0, self->m_field34);
        ((ListItem*)self->m_field34)->Method11();
        self->m_field34 = 0;
    }
}

void* func_0013B770(SubList *self, int flag) {
    if (self) {
        *(void**)self = D_4D7560;
        do_teardown(self);
        if ((short)flag > 0) {
            __vec_ctor(self);
        }
    }
    return self;
}

void SubList::func_0013B820() {
    do_teardown(this);
}
