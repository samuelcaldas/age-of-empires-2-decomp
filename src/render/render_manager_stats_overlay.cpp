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

/*
 * func_00187c40:
 * Section padding / alignment callback stub.
 * In the original AOK.ELF binary (VRAM 0x00187C40, 8 bytes),
 * this routine consists of `jr $ra; nop` (08 00 e0 03 00 00 00 00) emitted
 * by the compiler/linker for alignment / empty stub.
 */
void func_00187c40() {}

/*
 * func_00187c50:
 * Section padding / alignment callback stub.
 * In the original AOK.ELF binary (VRAM 0x00187C50, 8 bytes),
 * this routine consists of `jr $ra; nop` (08 00 e0 03 00 00 00 00) emitted
 * by the compiler/linker for alignment / empty stub.
 */
void func_00187c50() {}

/*
 * func_00187c60:
 * Section padding / alignment callback stub.
 * In the original AOK.ELF binary (VRAM 0x00187C60, 8 bytes),
 * this routine consists of `jr $ra; nop` (08 00 e0 03 00 00 00 00) emitted
 * by the compiler/linker for alignment / empty stub.
 */
void func_00187c60() {}

void func_00187c70(RenderManagerStatsOverlay *self) {
    void *v1 = self->field_1AC;
    if (v1) {
        func_192B30(v1, (void *)((char *)self + 0x90C), 0xB0);
    }
}

}
