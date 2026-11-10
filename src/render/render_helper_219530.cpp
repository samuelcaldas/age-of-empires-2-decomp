#pragma exceptions off
#include "sub_list.h"

struct BaseRenderHelper219530 {
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
    virtual int method11C(short arg1, int arg2, int arg3, int arg4, int arg5);
};

extern "C" {
int func_002198A0(void *self, short arg1, int arg2, int arg3, int arg4);
int func_002195A0(void *self, short arg1, int arg2, int arg3, int arg4);

int func_00219530(void *self, int arg1, int arg2, int arg3) {
    short f120 = *(short *)((char *)self + 0x120);
    return func_002195A0(self, f120, arg1, arg2, arg3);
}

int func_00219550(void *self, int arg1, int arg2, int arg3) {
    short f120 = *(short *)((char *)self + 0x120);
    return ((BaseRenderHelper219530 *)self)->method11C(f120, arg1, arg2, arg3, 0);
}

int func_00219580(void *self, int arg1, int arg2) {
    short f120 = *(short *)((char *)self + 0x120);
    return func_002198A0(self, f120, arg1, arg2, 0);
}

int func_002195A0(void *self, short arg1, int arg2, int arg3, int arg4) {
    return ((BaseRenderHelper219530 *)self)->method11C(arg1, arg2, 0, arg3, arg4);
}
}
