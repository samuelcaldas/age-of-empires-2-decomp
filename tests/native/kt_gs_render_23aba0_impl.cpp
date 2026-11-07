#include "kt_gs_render_23aba0.h"
#include <cstdint>

extern "C" {
    void* func_11ACD0(void*, void*);
    void* func_100730(void*);
    void* func_117CAC(void*);
    int func_117AF8(void*, void*);
    void* func_116F68(void*);
}

void func_0023ABA0(void* obj, void* a1, void* a2) {
}

void* func_0023AD20(void* obj, int index) {
    if (index >= 0 && index <= 4) {
        uint32_t* slots = (uint32_t*)((u8*)obj + 0x1054);
        return (void*)(uintptr_t)slots[index];
    }
    return 0;
}

void* func_0023ADA0(void) {
    return 0;
}

void func_0023ADB0(void) {
}
