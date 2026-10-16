#ifndef UNIT_ACTION_STREAM_H
#define UNIT_ACTION_STREAM_H

#include "unit_action_flags.h"

extern "C" {
    void func_00116F68(void *stream, void *data, int size);
    void func_00116F40(void *stream, void *data, int size);
    void func_0011AA78(void *stream, void *data, int size);
    void func_0011ACD0(void *stream, void *data, int size);
    void func_0011ABBC(void *stream, void *data, int size);
    void* func_00100850(void *dst, const void *src, int n);

    void func_0026AE00(ActionRebind *self, void *stream);
    int func_0026AEC0(const char *str);
    void func_0026AF90(ActionRebind *self, void *stream);
    void func_0026B0A0(ActionRebind *self, void *log);
}

#endif // UNIT_ACTION_STREAM_H
