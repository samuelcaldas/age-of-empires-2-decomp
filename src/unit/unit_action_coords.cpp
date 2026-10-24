#pragma exceptions off
#include "unit_action_coords.h"

int func_00269290(ActionRebind *self, int *out_dir, int *out_frame, int *out_x, int *out_y, int *out_extra) {
    if (self->m_field10 == 0) {
        return 0;
    }

    int dir = 0;
    if (self->m_fieldC != 0) {
        typedef int (*Method12Fn)(void *fieldC, int target);
        void *sub = *(void**)((char*)self->m_fieldC + 8);
        Method12Fn m12 = *(Method12Fn*)((char*)sub + 12);
        dir = m12(self->m_fieldC, self->m_field10);
    }

    short val28 = self->m_field28;
    short val2A = self->m_field2A;
    int frame = self->m_field35;
    int target = self->m_field10;

    int dx = (int)val28;
    int dy = (int)val2A;

    int ox = 0, oy = 0;
    if (func_00263020(target, frame, dir, &ox, &oy) != 0) {
        dx += ox;
        dy += oy;
    }

    if (out_dir != 0) {
        *out_dir = dir;
    }
    if (out_frame != 0) {
        *out_frame = frame;
    }
    if (out_x != 0) {
        *out_x = dx;
    }
    if (out_y != 0) {
        *out_y = dy;
    }
    if (out_extra != 0) {
        *out_extra = 0;
    }
    return 1;
}

int func_00269450(ActionRebind *self, void *renderer, int arg2, int arg3, int arg4, int arg5, int arg6) {
    (void)renderer; (void)arg2; (void)arg3; (void)arg4; (void)arg5; (void)arg6;
    if (self->m_field10 == 0) {
        return 0;
    }

    int dir = 0;
    if (self->m_fieldC != 0) {
        typedef int (*Method13Fn)(void *fieldC, int target, int frame);
        void *sub = *(void**)((char*)self->m_fieldC + 8);
        Method13Fn m13 = *(Method13Fn*)((char*)sub + 52);
        dir = m13(self->m_fieldC, self->m_field10, self->m_field35);
    }

    int frame = self->m_field35;
    int target = self->m_field10;

    func_002621E0(target, frame, dir);
    func_00268410(self);

    return 1;
}

void func_002697B0(ActionRebind *self, float x, float y, float z) {
    self->m_x = x;
    self->m_y = y;
    self->m_z = z;
}
