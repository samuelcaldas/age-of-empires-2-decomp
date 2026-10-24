#pragma exceptions off
#include "unit_action_build_7b700.h"

extern "C" {
    extern void *D_004E3180;
    void *func_27B6B0(void *self);
    void *func_117CAC(void *dest, int val, unsigned int size);
    void func_27B950(void *self, void *entry);
}

void func_0027B700(void *self, int type, int param, float val1, float val2) {
    int count = *(int *)((char *)self + 0x5DC);
    if (count <= 0) {
        return;
    }

    void *entry = func_27B6B0(self);
    if (entry == 0) {
        return;
    }

    func_117CAC(entry, 0, 0x1C);

    void *list_head = *(void **)((char *)self + 0x1E0);
    *(void **)((char *)entry + 0x18) = list_head;
    *(int *)((char *)entry + 0x4) = count;

    int timestamp = 0;
    if (D_004E3180 != 0) {
        void *p = *(void **)((char *)D_004E3180 + 0x404);
        if (p != 0) {
            timestamp = *(int *)((char *)p + 0x18);
        }
    }
    *(int *)((char *)entry + 0x8) = timestamp;

    *(char *)((char *)entry + 0x0) = (char)type;
    *(float *)((char *)entry + 0xC) = val1;
    *(float *)((char *)entry + 0x10) = val2;
    *(float *)((char *)entry + 0x14) = (float)(unsigned int)param;

    *(void **)((char *)self + 0x1E0) = entry;

    int type_byte = type & 0xFF;
    if (type_byte == 0xC) {
        return;
    }
    if (type_byte == 0xB) {
        func_27B950(self, entry);
    }
}
