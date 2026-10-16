#pragma exceptions off
#include "unit_action_build_state.h"

void func_0026E1E0(ActionRebind *self, int arg1, float arg2) {
    if ((arg1 & 0xFF) == 0x11) {
        *(char*)((char*)self + 0x35) = (char)func_1233E0(arg2);
        return;
    }
    func_273810(self);
}

void func_0026E230(ActionRebind *self, void *zone) {
    if (self == 0 || zone == 0 || self->m_field4 == 0) {
        return;
    }

    int tile_x = func_123350(self->m_x);
    int tile_y = func_123350(self->m_y);

    void *f4 = self->m_field4;
    float ext_x = *(float*)((char*)f4 + 0x20);
    float ext_y = *(float*)((char*)f4 + 0x24);

    int start_x = tile_x - (int)ext_x;
    int end_x = tile_x + (int)ext_x;
    int start_y = tile_y - (int)ext_y;
    int end_y = tile_y + (int)ext_y;

    for (int y = start_y; y <= end_y; ++y) {
        for (int x = start_x; x <= end_x; ++x) {
            func_1D0F00(zone, x, y, 1, 0);
            func_1D1100(zone, x, y);
        }
    }
}
