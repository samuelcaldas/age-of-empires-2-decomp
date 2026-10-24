#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_00217B50(void *self, int arg3);

typedef void (*Fn)(void *, int);

static inline void call_vtable_28(void *self) {
    void **vtable = *(void ***)self;
    Fn fn = (Fn)*(void **)((char *)vtable + 0x28);
    fn(self, 1);
}

void func_00217DD0(void *self, int arg1, int arg2, int arg3) {
    char *s0 = (char *)self;
    int index = arg1 & 0xFF;

    switch (index) {
        case 0:
            break;
        case 1: {
            short val = *(short *)(s0 + 0x124) + (short)arg2;
            *(short *)(s0 + 0x124) = val;
            break;
        }
        case 2:
            *(short *)(s0 + 0x124) = (short)arg2;
            break;
        case 3: {
            short val = *(short *)(s0 + 0x124) + 1;
            *(short *)(s0 + 0x124) = val;
            break;
        }
        case 4: {
            short val = *(short *)(s0 + 0x124) - 1;
            *(short *)(s0 + 0x124) = val;
            break;
        }
        case 5: {
            short v1 = *(short *)(s0 + 0x122) - 1;
            short val = *(short *)(s0 + 0x124) + v1;
            *(short *)(s0 + 0x124) = val;
            break;
        }
        case 6: {
            short v1 = *(short *)(s0 + 0x122) - 1;
            short val = *(short *)(s0 + 0x124) - v1;
            *(short *)(s0 + 0x124) = val;
            break;
        }
        case 7:
            *(short *)(s0 + 0x124) = 0;
            break;
        default: {
            short base = *(short *)(s0 + 0x120);
            *(short *)(s0 + 0x124) = base - 1;
            break;
        }
    }

    func_00217B50(self, arg3);
    call_vtable_28(self);
}
}
