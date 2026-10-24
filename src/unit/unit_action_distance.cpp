#pragma exceptions off
#include "unit_action_distance.h"

extern "C" {
    float fabsf(float);
    float sqrtf(float);
}

void func_00269030(ActionRebind *self) {
    if ((unsigned char)self->m_field3A < 250) {
        self->m_field3A++;
    }
    func_0026A540(self, 0);
}

void func_00269060(ActionRebind *self) {
    if ((char)self->m_field3A > 0) {
        self->m_field3A--;
    }
    if (self->m_field3A == 0 && self->m_field39 == 2 && self->m_field30 >= 0.0f) {
        func_0026A540(self, 1);
    }
}

float func_002690D0(ActionRebind *self, void *other) {
    return func_002690E0(self, other, self->m_x, self->m_y);
}

float func_002690E0(ActionRebind *self, void *other, float x, float y) {
    if (other == 0) {
        return 3.4028235e+38F;
    }
    void *self_field4 = self->m_field4;
    float other_x = *(float*)((char*)other + 0x44);
    float other_y = *(float*)((char*)other + 0x48);
    void *other_field4 = *(void**)((char*)other + 0x4);

    float dx = fabsf(other_x - x) - *(float*)((char*)self_field4 + 0x20) - *(float*)((char*)other_field4 + 0x20);
    if (dx < 0.0f) {
        dx = 0.0f;
    }
    float dy = fabsf(other_y - y) - *(float*)((char*)self_field4 + 0x24) - *(float*)((char*)other_field4 + 0x24);
    if (dy < 0.0f) {
        dy = 0.0f;
    }

    float d = sqrtf(dx * dx + dy * dy);
    if (d <= 0.0f) {
        return 0.0f;
    }
    return d;
}

float func_00269190(ActionRebind *self, float target_x, float target_y) {
    void *field4 = self->m_field4;
    float dx = fabsf(target_x - self->m_x) - *(float*)((char*)field4 + 0x20);
    if (dx < 0.0f) {
        dx = 0.0f;
    }
    float dy = fabsf(target_y - self->m_y) - *(float*)((char*)field4 + 0x24);
    if (dy < 0.0f) {
        dy = 0.0f;
    }

    float d = sqrtf(dx * dx + dy * dy);
    if (d <= 0.0f) {
        return 0.0f;
    }
    return d;
}

float func_00269220(ActionRebind *self, float target_x, float target_y) {
    void *field4 = self->m_field4;
    float dx = fabsf(target_x - self->m_x) - *(float*)((char*)field4 + 0x20);
    if (dx < 0.0f) {
        dx = 0.0f;
    }
    float dy = fabsf(target_y - self->m_y) - *(float*)((char*)field4 + 0x24);
    if (dy < 0.0f) {
        dy = 0.0f;
    }

    return dx * dx + dy * dy;
}
