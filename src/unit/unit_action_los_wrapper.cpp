#pragma exceptions off
#include "unit_action_los_wrapper.h"

void func_0026D960(ActionRebind *self, void *zone, int arg2, int arg3, int arg4) {
    if (func_26AD20(self, 0x4000) == 0) {
        func_00268A60(self, zone, 1, arg3, arg4);
        return;
    }
    void *f4 = self->m_field4;
    float ext_x = *(float*)((char*)f4 + 0x20);
    float ext_y = *(float*)((char*)f4 + 0x24);
    int sum = func_123350(ext_x + ext_y);
    if ((sum & 1) == 0) {
        arg4 = 1;
    }
    func_00268A60(self, zone, arg2, arg3, arg4);
}

void func_0026DA20(ActionRebind *self, void *zone, int arg2, int arg3, int arg4) {
    if (func_26AD20(self, 0x4000) != 0) {
        void *f4 = self->m_field4;
        float ext_x = *(float*)((char*)f4 + 0x20);
        float ext_y = *(float*)((char*)f4 + 0x24);
        int sum = func_123350(ext_x + ext_y);
        if ((sum & 1) == 0) {
            arg4 = 1;
        }
    }
    func_00268C30(self, zone, arg2, arg3, arg4);
}
