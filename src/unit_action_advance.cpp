#pragma exceptions off
#include "unit_action_advance.h"

void func_00268DE0(ActionRebind *self) {
    float elapsed = self->Method32();
    float val = self->m_field30 - elapsed;
    if (val < 1.0f) {
        self->m_field30 = val;
        func_0026A540(self, 0);
        self->m_field30 = 0.0f;
    }

    void *field4 = self->m_field4;
    void *field38 = *(void**)((char*)field4 + 0x38);
    if (field38 != 0) {
        int obj = func_001AAB30();
        int arg1, arg2;
        int res = func_26A700(self, &arg1, &arg2);
        if (res != 0) {
            void *f4 = self->m_field4;
            void *f38 = *(void**)((char*)f4 + 0x38);
            func_25F6E0(f38, 1, arg1, arg2, -1, -1);
        }
        func_001AAB70(obj);
    }
}

float func_00268EB0(int count, void *arr, float scale) {
    float sum = 0.0f;
    if (arr != 0) {
        for (int i = 0; i < count; i++) {
            short val = *(short*)((char*)arr + i * 4 + 2);
            sum += scale * (float)val;
        }
    }
    return sum;
}

void func_00268F00(ActionRebind *self, int delta) {
    void *field10 = (void*)self->m_field10;
    int cur = self->m_field35;
    int total = *(unsigned char*)((char*)field10 + 0x3A);
    cur += delta;
    while (cur < 0) {
        cur += total;
    }
    while (cur >= total) {
        cur -= total;
    }
    func_26A680(self, (unsigned char)cur);
}

void func_00268F40(ActionRebind *self, short val, float fval) {
    self->m_field3C = val;
    *(float*)((char*)self + 0x40) = fval;
}

void func_00268F50(ActionRebind *self, int add_flag, int clamp_flag, float delta) {
    if (add_flag != 0) {
        *(float*)((char*)self + 0x40) += delta;
    } else {
        *(float*)((char*)self + 0x40) = delta;
    }
    if (clamp_flag != 0) {
        void *field4 = self->m_field4;
        float limit = (float)*(short*)((char*)field4 + 0x54);
        if (*(float*)((char*)self + 0x40) > limit) {
            *(float*)((char*)self + 0x40) = limit;
        }
    }
}

int func_00268FB0(ActionRebind *self, float delta) {
    float f1 = self->m_field30;
    if (delta < 0.0f) {
        self->m_field30 = f1 + delta;
        if (self->m_field30 < 1.0f) {
            self->m_field30 = 1.0f;
        }
    } else {
        self->m_field30 = f1 + delta;
    }

    void *field4 = self->m_field4;
    float limit = (float)*(short*)((char*)field4 + 0x3E);
    if (self->m_field30 < limit) {
        return 0;
    }
    self->m_field30 = limit;
    return 1;
}
