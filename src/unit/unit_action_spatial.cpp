#pragma exceptions off
#include "unit_action_spatial.h"

void func_00268800(ActionRebind *self, ActionRebind *parent, int force) {
    if (force == 0) {
        typedef int (*Method56Fn)(void *p);
        Method56Fn method56 = *(Method56Fn*)((char*)*(void***)parent + 224);
        if (method56(parent) == 0) {
            return;
        }
    }

    if (self->m_field1C != 0) {
        self->Method58();
    }

    if (self->m_field18 != 0) {
        self->Method62(self->m_world, 0, -1, 0);
        void *sub = *(void**)((char*)*(void**)((char*)D_004E3180 + 0x404) + 0x3C);
        func_1D0B40(sub, self->m_field18, self);
        self->m_field18 = 0;
    }

    func_1EDF20(D_004E3244, self);

    if (*(int*)((char*)self + 84) != 0) {
        func_1EE720(D_004E3244, self);
    }

    int field64 = *(int*)((char*)self + 100);
    if (field64 != -1) {
        void *obj = func_333B30(*(void**)((char*)self->m_world + 2968), field64);
        if (obj != 0) {
            func_1B8910(obj, self->m_field24);
        }
        typedef void (*Method143Fn)(void *s);
        Method143Fn method143 = *(Method143Fn*)((char*)*(void***)self + 572);
        method143(self);
    }

    typedef void (*Method59Fn)(void *p, void *s);
    Method59Fn method59 = *(Method59Fn*)((char*)*(void***)parent + 236);
    method59(parent, self);

    if ((self->m_field36 & 1) != 0) {
        func_205F70(self->m_world, self);
    }
}

void func_00268940(ActionRebind *self) {
    ActionRebind *parent = (ActionRebind*)self->m_field1C;
    if (parent != 0) {
        typedef void (*Method60Fn)(void *p, void *s);
        Method60Fn method60 = *(Method60Fn*)((char*)*(void***)parent + 240);
        method60(parent, self);
    }
}

void func_00268970(ActionRebind *self, ActionRebind *target) {
    target->m_x = self->m_x;
    target->m_y = self->m_y;
    *(void**)((char*)target + 32) = *(void**)((char*)self + 32);
    *(void**)((char*)self + 32) = target;
}

void func_002689B0(ActionRebind *self, ActionRebind *child) {
    if (child == 0) {
        return;
    }

    ActionRebind *prev = self;
    ActionRebind *curr = *(ActionRebind**)((char*)self + 32);
    while (curr != 0) {
        if (curr == child) {
            break;
        }
        prev = curr;
        curr = *(ActionRebind**)((char*)curr + 32);
    }

    if (curr == 0) {
        return;
    }

    *(void**)((char*)prev + 32) = *(void**)((char*)child + 32);
    child->m_field1C = 0;
    *(void**)((char*)child + 32) = 0;
}

void* func_00268A10(ActionRebind *self) {
    if (self->m_world == 0) {
        return 0;
    }
    float f28 = *(float*)((char*)self->m_field4 + 28);
    int res = func_123350(f28);
    typedef void* (*GetSightFn)(void *world_b94, int range, int zero);
    GetSightFn get_sight = (GetSightFn)func_00137A40;
    return get_sight(*(void**)((char*)self->m_world + 2964), res, 0);
}
