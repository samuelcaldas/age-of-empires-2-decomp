#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_00213FA0(void *arg0, int arg1, int arg2);
int func_001F3B20(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);

typedef void (*VFn)(void *);
typedef void (*VFnArg)(void *, void *);

enum { kBreakCode = 7 };

#ifdef TRADE_ACTION_HELPER_217B50_TEST_SHIM
class BreakException {
public:
    int code;
    void *self;
    BreakException(int c, void *s) : code(c), self(s) {}
};

static inline void trigger_break_7() {
    extern void *current_test_self;
    throw BreakException((int)kBreakCode, current_test_self);
}
#else
static inline void trigger_break_7() {
#ifdef __MWERKS__
    __I_break(kBreakCode);
#else
    __builtin_trap();
#endif
}
#endif

#ifdef TRADE_ACTION_HELPER_217B50_TEST_SHIM
void *current_test_self = nullptr;
#endif

void func_00217B50(void *self, int arg3) {
#ifdef TRADE_ACTION_HELPER_217B50_TEST_SHIM
    current_test_self = self;
#endif
    char *s0 = (char *)self;
    int f140 = *(int *)(s0 + 0x140);
    int v1 = f140 + 2;
    *(int *)(s0 + 0x17C) = v1;

    if (f140 == 0) {
        *(short *)(s0 + 0x122) = 1;
    } else {
        int f18 = *(int *)(s0 + 0x18);
        int f1bc = *(int *)(s0 + 0x1BC);
        int f1c0 = *(int *)(s0 + 0x1C0);
        int denom = v1 + (f1c0 != 0 ? (2 * f1c0 - 1) : 0);
        if (denom == 0) {
            trigger_break_7();
        }
        int div_res = (f18 - (2 * f1bc)) / denom;
        *(short *)(s0 + 0x122) = (short)div_res;
    }

    short val122 = *(short *)(s0 + 0x122);
    if (val122 <= 0) {
        *(short *)(s0 + 0x122) = 1;
    }

    short f120 = *(short *)(s0 + 0x120);
    short f124 = *(short *)(s0 + 0x124);
    if (f124 >= f120) {
        f124 = f120 - 1;
    }
    if ((f120 - f124) < *(short *)(s0 + 0x122)) {
        f124 = f120 - *(short *)(s0 + 0x122);
    }
    if (f124 < 0) f124 = 0;
    *(short *)(s0 + 0x124) = f124;

    short f126 = f124 + *(short *)(s0 + 0x122) - 1;
    if (f126 < 0) f126 = 0;
    if (f126 >= f120) f126 = f120 - 1;
    *(short *)(s0 + 0x126) = f126;

    short f128 = *(short *)(s0 + 0x128);
    if (f128 < 0) {
        f128 = 0;
    }
    if (f128 >= f120) {
        f128 = f120 - 1;
    }
    *(short *)(s0 + 0x128) = f128;

    void *p = *(void **)(s0 + 0x16C);
    if (p == 0) {
        *(int *)(s0 + 0x178) = *(int *)(s0 + 0x14);
        return;
    }

    if (arg3 != 0) {
        func_00213FA0(p, (f120 - *(short *)(s0 + 0x122)) + 1, f124);
    }

    int f170 = *(int *)(s0 + 0x170);
    if (f170 != 0) {
        short f122_val = *(short *)(s0 + 0x122);
        short f120_val = *(short *)(s0 + 0x120);
        int f1a8 = *(int *)(s0 + 0x1A8);

        if (f122_val < f120_val && f1a8 == 0) {
            void *f0c = *(void **)(s0 + 0xC);
            void *f10 = *(void **)(s0 + 0x10);
            void *f1a0 = *(void **)(s0 + 0x1A0);
            void *f1a4 = *(void **)(s0 + 0x1A4);
            void *f18 = *(void **)(s0 + 0x18);
            void *computed_1a0 = (void *)((char *)f1a0 - (char *)f1a4);
            func_001F3B20(self, f0c, f10, computed_1a0, f18);
            *(int *)(s0 + 0x1A8) = 1;

            void *f84 = *(void **)(s0 + 0x84);
            if (f84 != 0) {
                p = *(void **)(s0 + 0x16C);
                void **vtable = *(void ***)p;
                VFn fn1C = (VFn)*(void **)((char *)vtable + 0x1C);
                fn1C(p);
            }
        } else if (f122_val >= f120_val && f1a8 != 0) {
            void *f0c = *(void **)(s0 + 0xC);
            void *f10 = *(void **)(s0 + 0x10);
            void *f1a0 = *(void **)(s0 + 0x1A0);
            void *f18 = *(void **)(s0 + 0x18);
            func_001F3B20(self, f0c, f10, f1a0, f18);
            *(int *)(s0 + 0x1A8) = 0;

            void *f84 = *(void **)(s0 + 0x84);
            if (f84 != 0) {
                p = *(void **)(s0 + 0x16C);
                void **vtable = *(void ***)p;
                VFnArg fn1C = (VFnArg)*(void **)((char *)vtable + 0x1C);
                fn1C(p, 0);
            }
        }
    }

    *(int *)(s0 + 0x178) = *(int *)(s0 + 0x14);
}
}
