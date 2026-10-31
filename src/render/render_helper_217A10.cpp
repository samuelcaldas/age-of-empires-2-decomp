#pragma exceptions off
#include "sub_list.h"

struct BaseRenderHelper217A10 {
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void method28(int arg);
};

struct BaseObj1C {
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void method1C(int arg);
};

extern "C" {
void func_00217B50(void *self, int arg1);
void func_1F3DC0(void *self);

void func_00217A10(void *self, int arg1, char arg2) {
    char *s0 = (char *)self;
    *(int *)(s0 + 0x190) = arg1;
    if (*(int *)(s0 + 0x190) != 0) {
        *(int *)(s0 + 0x1AC) = 1;
    } else {
        *(int *)(s0 + 0x1AC) = 0;
    }
    *(char *)(s0 + 0x194) = arg2;
    ((BaseRenderHelper217A10 *)self)->method28(1);
}

void func_00217A50(void *self, int a1, char a2, char a3, char a4, char a5, char a6, char a7) {
    char *s0 = (char *)self;
    *(int *)(s0 + 0x1AC) = a1;
    *(char *)(s0 + 0x1B0) = a2;
    *(char *)(s0 + 0x1B1) = a3;
    *(char *)(s0 + 0x1B2) = a4;
    *(char *)(s0 + 0x1B3) = a5;
    *(char *)(s0 + 0x1B4) = a6;
    *(char *)(s0 + 0x1B5) = a7;

    switch (*(int *)(s0 + 0x1AC)) {
    case 1:
    case 2:
    case 5:
        *(int *)(s0 + 0x1BC) = 1;
        break;
    case 3:
    case 6:
        *(int *)(s0 + 0x1BC) = 2;
        break;
    case 4:
    case 7:
        *(int *)(s0 + 0x1BC) = 3;
        break;
    case 0:
    default:
        *(int *)(s0 + 0x1BC) = 0;
        break;
    }
    func_00217B50(self, 1);
}

void func_00217AD0(void *self, int a1) {
    *(int *)((char *)self + 0x1C0) = a1;
    func_00217B50(self, 1);
}

void func_00217AE0(void *self) {
    char *s0 = (char *)self;
    func_1F3DC0(self);
    if (*(int *)(s0 + 0x170) == 0) {
        return;
    }
    BaseObj1C *obj = *(BaseObj1C **)(s0 + 0x16C);
    if (obj == 0) {
        return;
    }
    if (*(int *)(s0 + 0x84) != 0) {
        obj->method1C(*(int *)(s0 + 0x1A8));
    } else {
        obj->method1C(0);
    }
}
}
