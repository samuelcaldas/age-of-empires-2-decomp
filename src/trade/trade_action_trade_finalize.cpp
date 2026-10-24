#pragma exceptions off
#include "trade_action_trade_finalize.h"

int func_00151C70(TradeAction *self) {
    int res = func_2660C0(self) & 0xFF;

    if (self->m_field39 == 4) {
        void *a0 = *(void**)((char*)self + 12);
        typedef int (*Fn)(void*, int);
        Fn fn = *(Fn*)(*(char**)a0 + 32);
        if ((fn(a0, *(int*)((char*)self + 16)) & 0xFF) == 0) {
            self->m_field39 = 5;
            *(int*)((char*)self + 104) = 0;
        }
    } else if (self->m_field39 == 3) {
        void *v0 = *(void**)((char*)self + 4);
        if (*(int*)((char*)v0 + 24) != 0) {
            self->Method70(5);
        } else {
            self->Method70(0);
        }
    }

    void *a0 = *(void**)((char*)self + 12);
    void *v0 = *(void**)((char*)self + 8);
    void *timer = *(void**)((char*)v0 + 2968);
    typedef void (*FnFloat)(void*, float, float);
    FnFloat fn_float = *(FnFloat*)(*(char**)a0 + 16);
    fn_float(a0, *(float*)((char*)timer + 172), *(float*)((char*)self + 104));

    func_001AAB30();
    return res;
}

void func_00151E10(TradeAction *self, void *a1) {
    func_266920(self);
    func_00226F70(a1, &self->m_field68, 4);
}

void func_00151E60(TradeAction *self) {
    if (self->m_field3A > 0) {
        self->m_field3A--;
    }
}

void func_00151E80(void *self) {
}
