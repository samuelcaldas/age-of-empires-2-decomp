#include "sub_list.h"

extern "C" {

struct CallbackItem {
    unsigned char m_type;
    void *m_func;
    unsigned char m_arg1;
    unsigned char m_arg2;
    unsigned char m_arg3;
    unsigned char m_arg4;
};

void __vec_ctor(void *self);

CallbackItem* func_0013C4F0(CallbackItem *self) {
    self->m_type = 0;
    self->m_func = 0;
    self->m_arg1 = 0;
    self->m_arg2 = 0;
    self->m_arg3 = 0;
    self->m_arg4 = 0;
    return self;
}

CallbackItem* func_0013C510(CallbackItem *self, int flag) {
    if (self) {
        self->m_func = 0;
        if ((short)flag > 0) {
            __vec_ctor(self);
        }
    }
    return self;
}

void func_0013C560(CallbackItem *self, unsigned char type, void *func,
                   unsigned char a1, unsigned char a2, unsigned char a3, unsigned char a4) {
    self->m_type = type;
    self->m_func = func;
    self->m_arg1 = a1;
    self->m_arg2 = a2;
    self->m_arg3 = a3;
    self->m_arg4 = a4;
}

void func_0013C580(CallbackItem *self, int a1, int a2, int a3, int a4) {
    switch (self->m_type) {
    case 0:
        ((void(*)())self->m_func)();
        break;
    case 1:
        ((void(*)(int))self->m_func)(a1);
        break;
    case 2:
        ((void(*)(int, int))self->m_func)(a1, a2);
        break;
    case 3:
        ((void(*)(int, int, int))self->m_func)(a1, a2, a3);
        break;
    case 4:
        ((void(*)(int, int, int, int))self->m_func)(a1, a2, a3, a4);
        break;
    }
}

unsigned char func_0013C650(CallbackItem *self) {
    return self->m_type;
}

}
