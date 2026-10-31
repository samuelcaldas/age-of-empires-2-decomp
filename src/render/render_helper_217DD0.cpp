#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_00217B50(void *self, int arg3);

struct BaseObj {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void Method28(int);
};

void func_00217DD0(void *self, int arg1, int arg2, int arg3) {
    char *s0 = (char *)self;
    int index = arg1 & 0xFF;

    switch (index) {
        case 0: {
            short val = *(short *)(s0 + 0x124) + (short)arg2;
            *(short *)(s0 + 0x124) = val;
            break;
        }
        case 1:
            *(short *)(s0 + 0x124) = (short)arg2;
            break;
        case 2: {
            short val = *(short *)(s0 + 0x124) + 1;
            *(short *)(s0 + 0x124) = val;
            break;
        }
        case 3: {
            short val = *(short *)(s0 + 0x124) - 1;
            *(short *)(s0 + 0x124) = val;
            break;
        }
        case 4: {
            short v1 = *(short *)(s0 + 0x122) - 1;
            short val = *(short *)(s0 + 0x124) + v1;
            *(short *)(s0 + 0x124) = val;
            break;
        }
        case 5: {
            short v1 = *(short *)(s0 + 0x122) - 1;
            short val = *(short *)(s0 + 0x124) - v1;
            *(short *)(s0 + 0x124) = val;
            break;
        }
        case 6:
            *(short *)(s0 + 0x124) = 0;
            break;
        case 7: {
            short base = *(short *)(s0 + 0x120);
            *(short *)(s0 + 0x124) = base - 1;
            break;
        }
    }

    func_00217B50(self, arg3);
    ((BaseObj *)self)->Method28(1);
}
}
