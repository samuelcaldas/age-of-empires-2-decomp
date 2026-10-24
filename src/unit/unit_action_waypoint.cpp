#pragma exceptions off
#include "unit_action_waypoint.h"

int func_0026A700(ActionRebind *self, int *out_x, int *out_y) {
    if (self == 0 || self->m_world == 0) {
        return 0;
    }
    int tx = func_123350(self->m_x);
    int ty = func_123350(self->m_y);

    if (func_186010(self->m_world, tx, ty) == 0) {
        return 0;
    }

    void *zone = *(void**)((char*)self->m_world + 0xB94);
    if (func_001378C0(zone, tx, ty) == 0) {
        return 0;
    }

    if (out_x != 0) {
        *out_x = tx;
    }
    if (out_y != 0) {
        *out_y = ty;
    }
    return 1;
}

void* func_0026A9E0(void *out, ActionRebind *other) {
    *(float*)((char*)out + 0) = other->m_x;
    *(float*)((char*)out + 4) = other->m_z;
    *(float*)((char*)out + 8) = other->m_y;
    return out;
}

int func_0026AA00(ActionRebind *self, float *target_pos, float speed) {
    (void)speed;
    if (self == 0 || target_pos == 0) {
        return 0;
    }
    float dx = target_pos[0] - self->m_x;
    float dy = target_pos[1] - self->m_y;
    float angle = func_00113FB8(dy, dx);
    int dir = func_123350(angle);
    func_0026A680(self, (unsigned char)dir);
    return 1;
}

float func_0026AC30(ActionRebind *self) {
    void *field4 = self->m_field4;
    return *(float*)((char*)field4 + 0x1C);
}
