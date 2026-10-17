#pragma once

struct ActionRebind;

extern "C" {
    void *func_001EBA00(void *slot);
    void *func_00367230(int type);
    void *func_002718D0(ActionRebind *self, void *other,
                        float x, float y, float z);
}
