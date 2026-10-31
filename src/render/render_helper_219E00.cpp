#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_00217DD0(void *self, int arg1, int arg2, int arg3);

typedef void (*VMethod28)(void *, int);

struct ActionListItem {
    char *text;
    char *extra_text;
    int val_8;
    void *val_c;
    char byte_10;
    char pad_11[3];
    void *val_14;
    void *val_18;
    void *val_1c;
    void *val_20;
    char byte_24;
    char pad_25[3];
    ActionListItem *next;
};

struct BaseRenderHelper219E00 {
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

void func_00219E00(void *self, int arg1) {
    char *s = (char *)self;
    *(int *)(s + 0x19C) = arg1;

    ((BaseRenderHelper219E00 *)self)->method28(1);
}

void func_00219E20(void *self, int index, void *arg2, void *arg3, void *arg4, void *arg5) {
    char *s = (char *)self;
    ActionListItem *curr = *(ActionListItem **)(s + 0x11C);
    int idx = 0;

    while (curr != 0) {
        if (idx == index) {
            break;
        }
        curr = curr->next;
        idx++;
    }

    if (curr == 0) {
        return;
    }

    curr->val_14 = arg2;
    curr->val_18 = arg3;
    curr->val_1c = arg4;
    curr->val_20 = arg5;
    curr->byte_10 = 1;

    ((BaseRenderHelper219E00 *)self)->method28(1);
}

int func_00219E90(void *self, int arg1, int arg2) {
    short hi = (short)(((unsigned int)arg2 >> 16) & 0xFFFF);
    if (hi > 0) {
        func_00217DD0(self, 3, 0, 1);
        return 1;
    }
    if (hi < 0) {
        func_00217DD0(self, 2, 0, 1);
        return 1;
    }
    return 0;
}

void func_00219F00(void *self, int arg1) {
    char *s = (char *)self;
    *(int *)(s + 0x1C8) = arg1;

    ((BaseRenderHelper219E00 *)self)->method28(1);
}

int func_00219F20(void *self, int index) {
    char *s = (char *)self;
    ActionListItem *curr = *(ActionListItem **)(s + 0x11C);
    int idx = 0;

    while (curr != 0) {
        if (idx == index) {
            goto found;
        }
        curr = curr->next;
        idx++;
    }

found:
    if (curr != 0) {
        return (unsigned char)curr->byte_24;
    }
    return 1;
}
}
