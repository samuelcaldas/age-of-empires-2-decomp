#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern char D_00C5C2D0;

void *func_0021A520(void *self);
void func_0021A550(void *self);
void *func_0021B3E0(void *self);
void func_0021B420(void *self);
void func_0021B6A0(void *self);

void *func_1003B0(void *array, void *ctor_fn, void *dtor_fn, int elem_size, int count);

void *func_0021B640(void *self) {
    func_1003B0(self, (void *)func_0021A520, 0, 0xA8, 6);
    char *palette_slots = (char *)self + 0x3F0;
    func_1003B0(palette_slots, (void *)func_0021B3E0, 0, 8, 6);
    func_0021B6A0(self);
    return self;
}

void func_0021B6A0(void *self) {
    char *palette_slots = (char *)self + 0x3F0;
    for (int i = 0; i < 6; i++) {
        func_0021B420(palette_slots + i * 8);
    }
    char *viewport_slots = (char *)self;
    for (int i = 0; i < 6; i++) {
        func_0021A550(viewport_slots + i * 168);
    }
}

int func_0021B730(void *unused, void **out_ptr) {
    *out_ptr = &D_00C5C2D0;
    func_0021B6A0(&D_00C5C2D0);
    return 0;
}

void *func_0021B760(void *self) {
    char *slot = (char *)self + 0x3F0;
    for (int i = 0; i < 6; i++) {
        if (*(short *)slot == 0) {
            *(short *)slot = 1;
            return slot;
        }
        slot += 8;
    }
    return 0;
}
}
