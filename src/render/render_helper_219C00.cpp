#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern char D_004E32D4;

struct ActionListItem {
    char *text;
    char *extra_text;
    int val_8;
    void *val_c;
    unsigned char byte_10;
    char pad_11[3];
    void *val_14;
    void *val_18;
    void *val_1c;
    void *val_20;
    char byte_24;
    char pad_25[3];
    ActionListItem *next;
};

int func_00219CE0(void *self, int index);

void func_00219C00(void *self, int index, void **loc120, void **loc124, void **loc128, void **loc12C, int selector) {
    *loc120 = 0;
    *loc124 = 0;

    int idx = 0;
    ActionListItem *curr = *(ActionListItem **)((char *)self + 0x11C);

    while (curr != 0) {
        if (idx == index) {
            *loc120 = curr->text;
            *loc124 = curr->val_c;
            if (curr->byte_10 != 0 && loc128 != 0 && loc12C != 0) {
                if (selector != 0) {
                    *loc128 = curr->val_1c;
                    *loc12C = curr->val_20;
                } else {
                    *loc128 = curr->val_14;
                    *loc12C = curr->val_18;
                }
            }
        }
        curr = curr->next;
        idx++;
    }
}

const char *func_00219C90(void *self, int index) {
    int idx = 0;
    ActionListItem *curr = *(ActionListItem **)((char *)self + 0x11C);

    while (curr != 0) {
        if (idx == index) {
            return curr->extra_text;
        }
        curr = curr->next;
        idx++;
    }

    D_004E32D4 = '\0';
    return &D_004E32D4;
}

int func_00219CD0(void *self) {
    char *self_bytes = (char *)self;
    short cur_128 = *(short *)(self_bytes + 0x128);
    return func_00219CE0(self, (int)cur_128);
}

int func_00219CE0(void *self, int index) {
    int idx = 0;
    ActionListItem *curr = *(ActionListItem **)((char *)self + 0x11C);

    while (curr != 0) {
        if (idx == index) {
            return curr->val_8;
        }
        curr = curr->next;
        idx++;
    }

    return -1;
}

struct BaseRenderHelper219C00 {
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEC();
    virtual void vF0();
    virtual void vF4();
    virtual void vF8();
    virtual void vFC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void method124();
};

void func_00219D20(void *self) {
    ((BaseRenderHelper219C00 *)self)->method124();
}
}
