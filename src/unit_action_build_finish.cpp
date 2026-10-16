#pragma exceptions off
#include "unit_action_build_finish.h"

static void process_construction_audio(ActionRebind *self, float ratio) {
    if (ratio <= 0.0f || self->m_field4 == 0 || self->m_world == 0) {
        return;
    }
    void *f4 = self->m_field4;
    for (int i = 0; i < 3; ++i) {
        short val_12c = *(short*)((char*)f4 + 0x12C + i * 6);
        if (val_12c >= 0 && *(unsigned char*)((char*)f4 + 0x130 + i * 6) != 0) {
            short val_12e = *(short*)((char*)f4 + 0x12E + i * 6);
            void *sub = *(void**)((char*)self->m_world + 0x1B30);
            typedef void (*AudioNotifyFn)(void *world, short id, int a2, float delta);
            AudioNotifyFn fn = *(AudioNotifyFn*)((char*)sub + 0x7C);
            if (fn != 0) {
                fn(self->m_world, val_12c, 0, (float)val_12e * ratio);
            }
        }
    }
}

void func_0026E750(ActionRebind *self) {
    if (self == 0) {
        return;
    }
    func_0026A540(self, 0);
    if ((self->m_field36 & 1) != 0 && self->m_world != 0) {
        func_205F70(self->m_world, self);
    }

    float ratio = 0.0f;
    if (self->m_field39 < 2 && self->m_field4 != 0) {
        if (self->m_field30 >= 1.0f) {
            float work = *(float*)((char*)self + 0x170);
            short max_work = *(short*)((char*)self->m_field4 + 0x13E);
            if (max_work > 0) {
                ratio = ((float)max_work - work) / (float)max_work;
                if (ratio > 1.0f) ratio = 1.0f;
            }
        }
    }

    if (func_26AD20(self, 0x800) != 0 && self->m_field30 > 0.0f) {
        ratio = 1.0f;
    }

    process_construction_audio(self, ratio);

    if (func_26AD20(self, 0x4000) != 0) {
        typedef void (*Method184Fn)(void *action);
        void **vtable = *(void***)self;
        Method184Fn m184 = (Method184Fn)vtable[184];
        if (m184 != 0) {
            m184(self);
        }
    }
}

void func_0026E940(ActionRebind *self) {
    if (self == 0) {
        return;
    }
    if (*(float*)((char*)self + 0x170) == 0.0f) {
        if (func_26AD20(self, 0x800) == 0) {
            void *f98 = (void*)((char*)self->m_world + 0x98);
            func_1EDF20(self, self);
            func_1ECD00(f98, self);
            func_26AD60(self, 0x8000);
            func_26AD30(self, 0x800);
        }
    }
}
