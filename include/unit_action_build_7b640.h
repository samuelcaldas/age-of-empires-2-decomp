#pragma once

extern "C" {
    // True ELF function entry points (0x27B620, 0x27B630, 0x27B6B0)
    int func_0027B620(void *self);
    int func_0027B630(void *self, int flag, int index, float *out_x, float *out_y);
    void *func_0027B6B0(void *self);

    // Backward-compatible milestone aliases
    int func_0027B640(void *self);
    int func_0027B650(void *self, int flag, int index, float *out_x, float *out_y);
    void *func_0027B6D0(void *self);
}
