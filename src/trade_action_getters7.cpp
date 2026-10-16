#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_00332da0(int id);
int func_00188070(void *ctx, int id);
int func_00123350(float val);
int func_002a0b30(void *mgr, int id);
int func_0029df60(void *mgr, int id);

void func_002B6220(void *self, int index, int value) {
    if (!self) {
        return;
    }
    char *base = static_cast<char *>(self);
    if (index < 0 || index >= 239) {
        return;
    }

    int *table_slot = reinterpret_cast<int *>(base + 0x858 + index * 4);
    if (value > 0) {
        *table_slot = value;
    }

    int field_bec = *reinterpret_cast<int *>(base + 0x0BEC);
    if (field_bec == 1) {
        return;
    }

    void *mgr = nullptr;
    void *p1 = *reinterpret_cast<void **>(base + 0xB0);
    if (p1) {
        void *p2 = *reinterpret_cast<void **>(static_cast<char *>(p1) + 0xAC);
        if (p2) {
            mgr = *reinterpret_cast<void **>(static_cast<char *>(p2) + 0xB98);
        }
    }

    if (mgr) {
        void *target = func_00332da0(0);
        if (target) {
            func_00188070(mgr, 0x10);
        }
    }

    func_00123350(1.0f);
    if (p1) {
        func_002a0b30(static_cast<char *>(p1) + 0x3624, 0x14);
        func_0029df60(static_cast<char *>(p1) + 0x3624, 0x1E);
    }
}
}
