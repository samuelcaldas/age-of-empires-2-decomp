#pragma exceptions off
#include "unit_action_build_7a1d0.h"

extern "C" {
    void *memcpy(void *dest, const void *src, unsigned int n);
    void *func_117CAC(void *dest, int val, unsigned int size);
    int func_123350(float val);
    void func_27A810(void *self, int param);
}

#if defined(__LP64__) || defined(_LP64)
#define OWNER_PROPS_OFFSET 0x1758
#define MGR_OWNER_OFFSET   0x5D8
#else
#define OWNER_PROPS_OFFSET 0xBAC
#define MGR_OWNER_OFFSET   0x5D4
#endif

static void clear_manager_fields(void *self) {
    *(int *)((char *)self + 0x1E0) = 0;
    func_117CAC((char *)self + 0x1E4, 0, 0x3F0);
    func_117CAC((char *)self + 0x5D4, 0, 0x58);
    func_117CAC((char *)self + 0x68C, 0, 0x10);
    for (int i = 0; i < 8; ++i) {
        *(short *)((char *)self + 0x62C + (i * 2)) = 0;
        *(int *)((char *)self + 0x63C + (i * 4)) = 0;
        *(short *)((char *)self + 0x65C + (i * 2)) = 0;
        *(int *)((char *)self + 0x66C + (i * 4)) = 0;
    }
}

static void copy_owner_tactical_properties(void *self, void *owner) {
    *(void **)((char *)self + MGR_OWNER_OFFSET) = owner;
    void *props = *(void **)((char *)owner + OWNER_PROPS_OFFSET);
    *(int *)((char *)self + 0x5FC) = func_123350(*(float *)((char *)props + 0x50));
    *(int *)((char *)self + 0x600) = func_123350(*(float *)((char *)props + 0x2A8));
    *(int *)((char *)self + 0x5EC) = func_123350(*(float *)((char *)props + 0xAC));
    *(int *)((char *)self + 0x5F0) = func_123350(*(float *)((char *)props + 0x2B0));
    *(int *)((char *)self + 0x604) = func_123350(*(float *)((char *)props + 0x268));
    *(int *)((char *)self + 0x608) = func_123350(*(float *)((char *)props + 0x260));
    *(int *)((char *)self + 0x5F4) = func_123350(*(float *)((char *)props + 0x26C));
    *(int *)((char *)self + 0x5F8) = func_123350(*(float *)((char *)props + 0x264));
}

void *func_0027A1D0(void *self, void *owner, int param_s0) {
    clear_manager_fields(self);
    copy_owner_tactical_properties(self, owner);
    if (param_s0 >= 0) {
        func_27A810(self, param_s0);
    }
    return self;
}
