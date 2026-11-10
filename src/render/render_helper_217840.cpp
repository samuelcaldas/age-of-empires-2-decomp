#pragma exceptions off
#include "sub_list.h"

extern "C" {
struct BaseRenderHelper217840 {
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void method28(int arg1);
};

static inline void call_vtable_28(void *self) {
    ((BaseRenderHelper217840 *)self)->method28(1);
}

void func_00217840(void *self, int arg1, int arg2) {
    char *s0 = (char *)self;
    *(int *)(s0 + 0x144) = arg1;
    *(int *)(s0 + 0x148) = arg2;
    call_vtable_28(self);
}

void func_00217860(void *self, int arg1) {
    char *s0 = (char *)self;
    *(int *)(s0 + 0x14C) = arg1;
    call_vtable_28(self);
}

void func_00217880(void *self, int arg1) {
    char *s0 = (char *)self;
    *(int *)(s0 + 0x150) = arg1;
    call_vtable_28(self);
}

void func_002178A0(void *self, int arg1) {
    char *s0 = (char *)self;
    *(int *)(s0 + 0x154) = arg1;
    call_vtable_28(self);
}

void func_002178C0(void *self, int arg1) {
    char *s0 = (char *)self;
    *(int *)(s0 + 0x158) = arg1;
    call_vtable_28(self);
}

void func_002178E0(void *self, int arg1, int arg2) {
    char *s0 = (char *)self;
    *(int *)(s0 + 0x15C) = arg1;
    *(int *)(s0 + 0x160) = arg2;
    call_vtable_28(self);
}

void func_00217900(void *self, int arg1, int arg2) {
    char *s0 = (char *)self;
    *(int *)(s0 + 0x164) = arg1;
    *(int *)(s0 + 0x168) = arg2;
    call_vtable_28(self);
}

void func_00217920(void *self, int arg1, int arg2) {
    char *s0 = (char *)self;
    *(int *)(s0 + 0x188) = arg1;
    *(char *)(s0 + 0x18C) = (char)arg2;
}
}
