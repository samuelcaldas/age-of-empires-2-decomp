#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_00217DD0(void *self, int arg1, int arg2, int arg3);

typedef void (*VirtualFn)(void *, void *, void *, void *, void *, void *);

int func_00217EC0(void *self, int arg1, int arg2, int arg3, int arg4, int arg5) {
    char *s0 = (char *)self;
    void *ptr16C = *(void **)(s0 + 0x16C);
    if (ptr16C != 0) {
        unsigned char byte16C = *(unsigned char *)((char *)ptr16C + 0x16C);
        if (byte16C != 0) {
            return (int)byte16C;
        }
    }

    int switch_val = arg1 - 33;
    if (switch_val < 0 || switch_val >= 8) {
        return 0;
    }

    int target_id = -1;
    switch (switch_val) {
        case 0: target_id = 5; break;
        case 1: target_id = 4; break;
        case 2: target_id = 7; break;
        case 3: target_id = 6; break;
        case 4: target_id = -1; break;
        case 5: target_id = 3; break;
        case 6: target_id = -1; break;
        case 7: target_id = 2; break;
        default: target_id = -1; break;
    }

    if (target_id == -1) {
        return 0;
    }

    // A2 is always 0 per original delay slot (A2 = 0)
    func_00217DD0(self, target_id, 0, 1);

    void *obj40 = *(void **)(s0 + 0x40);
    if (obj40 != 0) {
        int flag8C = *(int *)(s0 + 0x8C);
        if (flag8C != 0) {
            void **vtable = *(void ***)obj40;
            if (vtable != 0) {
                VirtualFn fn = (VirtualFn)*(void **)((char *)vtable + 0xC8);
                if (fn != 0) {
                    fn(obj40, (void *)(unsigned long)arg1, (void *)(unsigned long)arg2, (void *)(unsigned long)arg3, (void *)(unsigned long)arg4, (void *)(unsigned long)arg5);
                }
            }
        }
    }

    return 1;
}
}
