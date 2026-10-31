#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_001ABA00(void *arg0);
int func_2257A0(void *arg0, int arg1);
int func_001ABA70(void *arg0);
void func_002184D0(void *self);
void func_00218820(void *self);

struct RenderHelper218350Base {
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24(); // 9
    virtual void method30(int arg); // 10 -> 0x30
    virtual void method34(); // 11 -> 0x34
    virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8(); virtual void vBC();
    virtual void vC0(); virtual void vC4(); virtual void vC8(); virtual void vCC();
    virtual void vD0(); virtual void vD4(); virtual void vD8(); virtual void vDC();
    virtual void vE0(); virtual void vE4(); virtual void vE8(); virtual void vEC();
    virtual void vF0(); virtual void vF4(); virtual void vF8(); virtual void vFC();
    virtual void v100(); virtual void v104(); virtual void v108(); virtual void v10C();
    virtual void v110(); virtual void v114(); virtual void v118(); virtual void v11C();
    virtual void method120(void *arg1, short arg2, short arg3, int arg4); // index 70 -> 0x120
};

void func_00218350(void *self) {
    char *s4 = (char *)self;
    *(int *)(s4 + 0x38) = 0;

    if (*(void **)(s4 + 0x20) == 0 || *(void **)(s4 + 0x88) == 0 || *(void **)(s4 + 0x84) == 0) {
        return;
    }

    RenderHelper218350Base *base = (RenderHelper218350Base *)self;
            base->method30(0);

            func_002184D0(self);

            void *s0_res = (void *)func_001ABA00(*(void **)(s4 + 0x20));
            if (s0_res != 0) {
                int s1_res = func_2257A0(s0_res, *(int *)(s4 + 0x12C));

                short s2 = *(short *)(s4 + 0x124);
                short s3 = 0;

                for (; s2 <= *(short *)(s4 + 0x126); s2++, s3++) {
                    if ((*(int *)(s4 + 0x8C) != 0 && *(int *)(s4 + 0x90) != 0) || *(int *)(s4 + 0x80) != 0) {
                        base->method120(s0_res, s3, s2, 1);
                    } else {
                        base->method120(s0_res, s3, s2, 0);
                    }
                }

                func_2257A0(s0_res, s1_res);
                func_001ABA70(*(void **)(s4 + 0x20));
            }

            func_00218820(self);
            base->method34();
}
}
