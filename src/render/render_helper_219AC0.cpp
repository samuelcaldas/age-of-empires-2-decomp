#pragma exceptions off
#include "sub_list.h"

struct BaseRenderHelper219AC0 {
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
    virtual void *method120(short arg1);
};

extern "C" {
int strcmp(const char *s1, const char *s2);
extern char D_004E32D0;

short func_00219AC0(void *self) {
    char *s = (char *)self;
    short count = *(short *)(s + 0x120);
    if (count == 0) {
        return -1;
    }
    return *(short *)(s + 0x128);
}

int func_00219AF0(void *self, int arg1) {
    char *s = (char *)self;
    void *node = *(void **)(s + 0x11C);
    int index = 0;

    while (node != 0) {
        if (*(int *)((char *)node + 0x8) == arg1) {
            return index;
        }
        node = *(void **)((char *)node + 0x28);
        index++;
    }

    return -1;
}

int func_00219B30(void *self, const char *arg1) {
    int index = 0;
    void *node = *(void **)((char *)self + 0x11C);

    while (node != 0) {
        char *str = *(char **)node;
        if (strcmp(str, arg1) == 0) {
            return index;
        }
        node = *(void **)((char *)node + 0x28);
        index++;
    }

    return -1;
}

void *func_00219BA0(void *self) {
    short f128 = *(short *)((char *)self + 0x128);
    return ((BaseRenderHelper219AC0 *)self)->method120(f128);
}

const char *func_00219BC0(void *self, int index) {
    int idx = 0;
    void *node = *(void **)((char *)self + 0x11C);

    while (node != 0) {
        if (idx == index) {
            return *(const char **)node;
        }
        node = *(void **)((char *)node + 0x28);
        idx++;
    }

    D_004E32D0 = '\0';
    return &D_004E32D0;
}
}
