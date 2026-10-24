#pragma exceptions off
#include "unit_action_collision.h"

int func_002697C0(ActionRebind *self, int arg1) {
    float coord_x[32];
    float coord_y[32];
    float ext_x[32];
    float ext_y[32];

    coord_x[1] = *(float*)((char*)self + 0x44);
    coord_y[1] = *(float*)((char*)self + 0x48);
    void *field4 = self->m_field4;
    ext_x[1] = *(float*)((char*)field4 + 0x20);
    ext_y[1] = *(float*)((char*)field4 + 0x24);

    if (func_00268500(self) == 0) {
        return 0;
    }

    int coord_count = 1;
    unsigned char success_count = 0;

    int child_count = func_00268530(self);
    for (int child_idx = child_count - 1; child_idx >= 0; --child_idx) {
        ActionRebind *child = func_00268590(self, child_idx);
        for (int c = coord_count; c > 0; --c) {
            float out_x = 0.0f;
            float out_y = 0.0f;
            void *child_f4 = child->m_field4;

            if (func_002699A0(self, arg1, &out_x, &out_y, child_f4, child,
                             coord_x[c], coord_y[c], ext_x[c], ext_y[c]) == 0) {
                continue;
            }

            func_002697B0(child, *(float*)((char*)self + 0x44), *(float*)((char*)self + 0x48), *(float*)((char*)self + 0x4C));
            child->Method58();
            child->Method15(out_x, out_y, *(float*)((char*)self + 0x4C));

            if (child->Method87() != 0) {
                void *target_obj = (void*)child->Method87();
                void *inner = *(void**)target_obj;
                *(float*)((char*)inner + 0x154) = out_x;
                *(float*)((char*)inner + 0x158) = out_y;
            }

            success_count++;
            if (coord_count < 29) {
                coord_count++;
                coord_x[coord_count] = out_x;
                coord_y[coord_count] = out_y;
                void *cf4 = child->m_field4;
                ext_x[coord_count] = *(float*)((char*)cf4 + 0x20);
                ext_y[coord_count] = *(float*)((char*)cf4 + 0x24);
            }
            break;
        }
    }

    return (int)success_count;
}
