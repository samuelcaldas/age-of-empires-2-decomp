#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_001ABA00(void *arg0);
int func_002257A0(void *arg0, int arg1);
int func_001ABA70(void *arg0);

typedef void (*VFn2)(void *, int);
typedef void (*VFn5)(void *, void *, void *, void *, void *);

static int signed_low16(int value) {
    unsigned int low = static_cast<unsigned int>(value) & 0xFFFFU;
    return low < 0x8000U ? static_cast<int>(low) : static_cast<int>(low) - 0x10000;
}

static int field_value(char *self, unsigned int offset) {
    return *reinterpret_cast<int *>(self + offset);
}

static void *pointer_from_int(int value) {
    return reinterpret_cast<void *>(static_cast<unsigned int>(value));
}

static void run_callback(char *self, int handle, int index, int sequence, int mode) {
    void **vtable = *reinterpret_cast<void ***>(self);
    VFn5 callback = reinterpret_cast<VFn5>(vtable[0x120 / sizeof(void *)]);
    callback(self, pointer_from_int(handle), pointer_from_int(index),
             pointer_from_int(sequence), pointer_from_int(mode));
}

void func_002181F0(void *object) {
    char *self = static_cast<char *>(object);
    *reinterpret_cast<int *>(self + 0x38) = 0;
    if (*reinterpret_cast<void **>(self + 0x20) == 0) return;
    if (*reinterpret_cast<void **>(self + 0x88) == 0) return;

    void **vtable = *reinterpret_cast<void ***>(self);
    VFn2 begin = reinterpret_cast<VFn2>(vtable[0x30 / sizeof(void *)]);
    begin(self, 0);

    int handle = func_001ABA00(*reinterpret_cast<void **>(self + 0x20));
    if (handle == 0) {
        vtable = *reinterpret_cast<void ***>(self);
        reinterpret_cast<void (*)(void *)>(vtable[0x34 / sizeof(void *)])(self);
        return;
    }

    int first = func_002257A0(pointer_from_int(handle),
                              field_value(self, 0x12C));
    int sequence = *reinterpret_cast<short *>(self + 0x124);
    int index = 0;
    while (*reinterpret_cast<short *>(self + 0x126) >= sequence) {
        int gate8c = field_value(self, 0x8C);
        int gate90 = field_value(self, 0x90);
        int gate80 = field_value(self, 0x80);
        if (gate8c != 0 && gate90 != 0) run_callback(self, handle, index, sequence, 1);
        if (!(gate8c != 0 && gate90 != 0) && gate80 != 0) {
            run_callback(self, handle, index, sequence, 0);
        }
        sequence = signed_low16(sequence + 1);
        index = signed_low16(index + 1);
    }

    func_002257A0(pointer_from_int(handle), first);
    func_001ABA70(*reinterpret_cast<void **>(self + 0x20));
    vtable = *reinterpret_cast<void ***>(self);
    reinterpret_cast<void (*)(void *)>(vtable[0x34 / sizeof(void *)])(self);
}
}
