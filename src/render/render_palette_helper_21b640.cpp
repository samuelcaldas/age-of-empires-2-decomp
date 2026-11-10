#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern char D_00C5C2D0[1056];

void *func_0021A520(void *self);
void func_0021A550(void *self);
void *func_0021B3E0(void *self);
void func_0021B420(void *self);
void func_0021B6A0(void *self);

void *func_1003B0(void *array, void *ctor_fn, void *dtor_fn, int elem_size, int count);

struct ElementA {
    char data[0xA8];
    ElementA();
};

struct ElementB {
    char data[8];
    ElementB();
};

struct RenderPaletteManager {
    ElementA elems[6];
    ElementB slots[6];
    RenderPaletteManager();
};

RenderPaletteManager::RenderPaletteManager() {
    func_0021B6A0(this);
}

void func_0021B6A0(void *self) {
    for (int i = 0; i < 6; i++) {
        func_0021B420((char *)self + i * 8 + 0x3F0);
    }
    for (int i = 0; i < 6; i++) {
        func_0021A550((char *)self + i * 168);
    }
}

int func_0021B730(void *unused, void **out_ptr) {
    *out_ptr = &D_00C5C2D0;
    func_0021B6A0(&D_00C5C2D0);
    return 0;
}

void *func_0021B760(void *self) {
    char *slot = (char *)self + 0x3F0;
    for (int i = 0; i < 6; i++, slot += 8) {
        if (*(unsigned short *)slot == 0) {
            *(unsigned short *)slot = 1;
            return slot;
        }
    }
    return 0;
}
}
