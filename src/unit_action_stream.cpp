#pragma exceptions off
#include "unit_action_stream.h"

void func_0026AE00(ActionRebind *self, void *stream) {
    if (self == 0 || stream == 0) {
        return;
    }
    func_00116F68(stream, &self->m_field39, 1);
    func_00116F68(stream, &self->m_field30, 4);
    func_00116F68(stream, &self->m_x, 12);
}

int func_0026AEC0(const char *str) {
    if (str == 0) {
        return 0;
    }
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void func_0026AF90(ActionRebind *self, void *stream) {
    if (self == 0 || stream == 0) {
        return;
    }
    func_0011AA78(stream, &self->m_field39, 1);
    func_0011AA78(stream, &self->m_field30, 4);
    func_0011AA78(stream, &self->m_x, 12);
}

void func_0026B0A0(ActionRebind *self, void *log) {
    if (self == 0 || log == 0) {
        return;
    }
    func_0011AA78(log, &self->m_field39, 1);
}
