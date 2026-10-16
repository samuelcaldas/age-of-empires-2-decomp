#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_00332da0(void *a0, int a1);
int func_00188070(void *a0, int a1);
int func_00123350(void *a0, float a1, int a2);
int func_002a0b30(void *a0, int a1);
int func_0029df60(void *a0, int a1);

int func_002B6220(void *self, int index, int value) {
    if (!self) {
        return -1;
    }
    char *base = static_cast<char *>(self);
    if (index < 0 || index >= 239) {
        return -1;
    }

    int *table_slot = reinterpret_cast<int *>(base + 0x858 + index * 4);
    if (value > 0) {
        *table_slot = value;
    }

    int field_bec = *reinterpret_cast<int *>(base + 0x0BEC);
    void *mgr = base;
    if (field_bec != 1) {
        void *p1 = *reinterpret_cast<void **>(base + 0xB0);
        if (p1) {
            void *p2 = *reinterpret_cast<void **>(static_cast<char *>(p1) + 0xAC);
            if (p2) {
                mgr = *reinterpret_cast<void **>(static_cast<char *>(p2) + 0xB98);
            }
        }
    }

    void *target = func_00332da0(mgr, 0);
    if (target) {
        func_00188070(target, 0x10);
    }

    func_00123350(self, 1.0f, 0);
    func_002a0b30(base + 0xB0, 0x14);
    func_0029df60(base + 0xB0, 0x1E);

    return *table_slot;
}
}
