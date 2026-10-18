#pragma exceptions off
#include "unit_action_build_7ba90.h"

extern "C" {
    void *func_1C0F30(void *self);
    void func_1C1520(void *self, int id, int size, int offset);
    void func_1C13C0(void *self, int index, int code);
    void func_27C390(void *self);
    void func_27BC50(void *self);
}

struct BufferDescriptor {
    int id;
    int size;
};

static const BufferDescriptor s_descriptors[14] = {
    { 0, 15 },
    { 1, 56 },
    { 2, 16 },
    { 3, 28 },
    { 4, 8 },
    { 5, 9 },
    { 6, 2 },
    { 7, 4 },
    { 8, 3 },
    { 9, 4 },
    { 10, 1 },
    { 11, 1 },
    { 12, 12 },
    { 13, 2 }
};

static const int s_codes[14] = {
    0x4E20, 0x4E21, 0x4E22, 0x4E23, 0x4E24,
    0x4E27, 0x4E28, 0x4E29, 0x4E2A, 0x4E2B,
    0x4E2C, 0x4E2D, 0x4E2E, 0x4E2F
};

void *func_0027BA90(void *self) {
    func_1C0F30(self);
    return self;
}

void func_0027BAD0(void *self) {
    int offset = 0;
    for (int i = 0; i < 14; ++i) {
        int id = s_descriptors[i].id;
        int size = s_descriptors[i].size;
        func_1C1520(self, id, size, offset);
        offset += size;
    }

    for (int i = 0; i < 14; ++i) {
        func_1C13C0(self, i, s_codes[i]);
    }

    func_27C390(self);
    func_27BC50(self);
}

void func_0027BAC0(void *self) {
    func_0027BAD0(self);
}

// Aliases
void *func_0027BAB0(void *self) {
    return func_0027BA90(self);
}

void func_0027BAE0(void *self) {
    func_0027BAC0(self);
}

void func_0027BAF0(void *self) {
    func_0027BAD0(self);
}

void func_27BAD0(void *self) {
    func_0027BAD0(self);
}
