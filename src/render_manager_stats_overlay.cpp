#pragma exceptions off
#include "render_manager_stats_overlay.h"

extern "C" {

#pragma divbyzerocheck on
void func_00187b40(RenderManagerStatsOverlay *self) {
    int v1 = self->field_518;
    if (!v1) {
        v1 = 1;
    }

    func_11A498(
        self->field_418,
        D_00491AE0,
        self->field_530,
        (unsigned int)self->timers[2].frame_time / v1,
        (unsigned int)self->timers[6].frame_time / v1,
        (unsigned int)self->timers[7].frame_time / v1,
        (unsigned int)self->timers[3].frame_time / v1,
        (unsigned int)self->timers[1].frame_time / v1,
        (unsigned int)self->timers[10].frame_time / v1,
        (unsigned int)self->timers[13].frame_time / v1,
        (unsigned int)self->timers[4].frame_time / v1,
        (unsigned int)self->timers[0].frame_time / v1
    );
}
#pragma divbyzerocheck reset

void func_00187c40() {}

void func_00187c50() {}

void func_00187c60() {}

void func_00187c70(RenderManagerStatsOverlay *self) {
    void *v1 = self->field_1AC;
    if (v1) {
        func_192B30(v1, (void *)((char *)self + 0x90C), 0xB0);
    }
}

}
