#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_00217DD0(void *self, int arg1, int arg2, int arg3);

struct TargetObjC8 {
    virtual void m00(); virtual void m04(); virtual void m08(); virtual void m0C();
    virtual void m10(); virtual void m14(); virtual void m18(); virtual void m1C();
    virtual void m20(); virtual void m24(); virtual void m28(); virtual void m2C();
    virtual void m30(); virtual void m34(); virtual void m38(); virtual void m3C();
    virtual void m40(); virtual void m44(); virtual void m48(); virtual void m4C();
    virtual void m50(); virtual void m54(); virtual void m58(); virtual void m5C();
    virtual void m60(); virtual void m64(); virtual void m68(); virtual void m6C();
    virtual void m70(); virtual void m74(); virtual void m78(); virtual void m7C();
    virtual void m80(); virtual void m84(); virtual void m88(); virtual void m8C();
    virtual void m90(); virtual void m94(); virtual void m98(); virtual void m9C();
    virtual void mA0(); virtual void mA4(); virtual void mA8(); virtual void mAC();
    virtual void mB0(); virtual void mB4(); virtual void mB8(); virtual void mBC();
    virtual int MethodC8(int a1, int a2, int a3, int a4, int a5);
};

/* 0x00217EC0 */
int func_00217EC0(void *self, int arg1, int arg2, int arg3, int arg4, int arg5) {
    char *v0 = *(char **)((char *)self + 0x16C);
    if (v0 == 0 || *(unsigned char *)(v0 + 0x16C) == 0) {
        switch (arg1) {
        case 40:
            func_00217DD0(self, 2, 0, 1);
            {
                TargetObjC8 *a0 = *(TargetObjC8 **)((char *)self + 0x40);
                if (a0 != 0 && *(int *)((char *)self + 0x8C) != 0) {
                    a0->MethodC8(arg1, arg2, arg3, arg4, arg5);
                }
            }
            return 1;
        case 38:
            func_00217DD0(self, 3, 0, 1);
            {
                TargetObjC8 *a0 = *(TargetObjC8 **)((char *)self + 0x40);
                if (a0 != 0 && *(int *)((char *)self + 0x8C) != 0) {
                    a0->MethodC8(arg1, arg2, arg3, arg4, arg5);
                }
            }
            return 1;
        case 34:
            func_00217DD0(self, 4, 0, 1);
            {
                TargetObjC8 *a0 = *(TargetObjC8 **)((char *)self + 0x40);
                if (a0 != 0 && *(int *)((char *)self + 0x8C) != 0) {
                    a0->MethodC8(arg1, arg2, arg3, arg4, arg5);
                }
            }
            return 1;
        case 33:
            func_00217DD0(self, 5, 0, 1);
            {
                TargetObjC8 *a0 = *(TargetObjC8 **)((char *)self + 0x40);
                if (a0 != 0 && *(int *)((char *)self + 0x8C) != 0) {
                    a0->MethodC8(arg1, arg2, arg3, arg4, arg5);
                }
            }
            return 1;
        case 36:
            func_00217DD0(self, 6, 0, 1);
            return 1;
        case 35:
            func_00217DD0(self, 7, 0, 1);
            return 1;
        default:
            break;
        }
    }
    return 0;
}
}
