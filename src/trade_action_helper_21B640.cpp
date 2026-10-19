#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern char D_00C5C2D0[0x420];

void *func_0021A520(void *self);
void func_0021A550(void *self);
void *func_0021B3E0(void *self);
void func_0021B420(void *self);
void func_0021B6A0(void *self);

void *func_1003B0(void *array, void *ctor_fn, void *dtor_fn, int elem_size, int count);

void *func_0021B640(void *self) {
    func_1003B0(self, (void *)func_0021A520, 0, 0xA8, 6);
    func_1003B0((void *)((char *)self + 0x3F0), (void *)func_0021B3E0, 0, 8, 6);
    func_0021B6A0(self);
    return self;
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
    int i = 0;
    while (i < 6) {
        if (*(unsigned short *)slot == 0) {
            *(unsigned short *)slot = 1;
            return slot;
        }
        i++;
        slot += 8;
    }
    return 0;
}
}
