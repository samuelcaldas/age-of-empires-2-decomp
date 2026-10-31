#pragma exceptions off
#pragma divbyzerocheck on

#ifdef TRADE_ACTION_HELPER_217B50_TEST_SHIM
#define func_213FA0 func_00213FA0
#define func_1F3B20 func_001F3B20

enum { kBreakCode = 7 };

class BreakException {
public:
    int code;
    void *self;
    BreakException(int c, void *s) : code(c), self(s) {}
};

static inline void trigger_break_7(void *self) {
    throw BreakException((int)kBreakCode, self);
}
#endif

struct BaseObj1C {
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void method1C(int arg);
};

extern "C" {
int func_213FA0(void *arg0, int arg1, int arg2);
int func_1F3B20(void *arg0, void *arg1, void *arg2, int arg3, void *arg4);

/* 0x00217B50 */
void func_00217B50(void *self, int arg3) {
    char *s0 = (char *)self;
    *(int *)(s0 + 0x17C) = *(int *)(s0 + 0x140) + 2;

    if (*(int *)(s0 + 0x140) == 0) {
        *(short *)(s0 + 0x122) = 1;
    } else {
        int f1c0 = *(int *)(s0 + 0x1C0);
        if (f1c0 == 0) {
            int denom = *(int *)(s0 + 0x17C);
#ifdef TRADE_ACTION_HELPER_217B50_TEST_SHIM
            if (denom == 0) trigger_break_7(self);
#endif
            int num = *(int *)(s0 + 0x18) - *(int *)(s0 + 0x1BC) * 2;
            *(short *)(s0 + 0x122) = (short)(num / denom);
        } else {
            int denom = *(int *)(s0 + 0x17C) + f1c0 * 2 - 1;
#ifdef TRADE_ACTION_HELPER_217B50_TEST_SHIM
            if (denom == 0) trigger_break_7(self);
#endif
            int num = *(int *)(s0 + 0x18) - *(int *)(s0 + 0x1BC) * 2;
            *(short *)(s0 + 0x122) = (short)(num / denom);
        }
    }

    if (*(short *)(s0 + 0x122) <= 0) {
        *(short *)(s0 + 0x122) = 1;
    }

    if (*(short *)(s0 + 0x124) >= *(short *)(s0 + 0x120)) {
        *(short *)(s0 + 0x124) = *(short *)(s0 + 0x120) - 1;
    }

    if (*(short *)(s0 + 0x120) - *(short *)(s0 + 0x124) < *(short *)(s0 + 0x122)) {
        *(short *)(s0 + 0x124) = *(short *)(s0 + 0x120) - *(short *)(s0 + 0x122);
    }

    if (*(short *)(s0 + 0x124) < 0) {
        *(short *)(s0 + 0x124) = 0;
    }

    *(short *)(s0 + 0x126) = *(short *)(s0 + 0x124) + *(short *)(s0 + 0x122) - 1;
    if (*(short *)(s0 + 0x126) < 0) {
        *(short *)(s0 + 0x126) = 0;
    }
    if (*(short *)(s0 + 0x126) >= *(short *)(s0 + 0x120)) {
        *(short *)(s0 + 0x126) = *(short *)(s0 + 0x120) - 1;
    }

    if (*(short *)(s0 + 0x128) < 0) {
        *(short *)(s0 + 0x128) = 0;
    }
    if (*(short *)(s0 + 0x128) >= *(short *)(s0 + 0x120)) {
        *(short *)(s0 + 0x128) = *(short *)(s0 + 0x120) - 1;
    }

    if (*(void **)(s0 + 0x16C) != 0) {
        if (arg3 != 0) {
            func_213FA0(*(void **)(s0 + 0x16C), *(short *)(s0 + 0x120) - *(short *)(s0 + 0x122) + 1, *(short *)(s0 + 0x124));
        }

        if (*(int *)(s0 + 0x170) != 0) {
            if (*(short *)(s0 + 0x120) > *(short *)(s0 + 0x122)) {
                if (*(int *)(s0 + 0x1A8) == 0) {
                    func_1F3B20(self, *(void **)(s0 + 0xC), *(void **)(s0 + 0x10), *(int *)(s0 + 0x1A0) - *(int *)(s0 + 0x1A4), *(void **)(s0 + 0x18));
                    *(int *)(s0 + 0x1A8) = 1;
                    if (*(int *)(s0 + 0x84) != 0) {
                        ((BaseObj1C *)*(void **)(s0 + 0x16C))->method1C(1);
                    }
                }
            } else {
                if (*(int *)(s0 + 0x1A8) != 0) {
                    func_1F3B20(self, *(void **)(s0 + 0xC), *(void **)(s0 + 0x10), *(int *)(s0 + 0x1A0), *(void **)(s0 + 0x18));
                    *(int *)(s0 + 0x1A8) = 0;
                    if (*(int *)(s0 + 0x84) != 0) {
                        ((BaseObj1C *)*(void **)(s0 + 0x16C))->method1C(0);
                    }
                }
            }
        }
    }

    *(int *)(s0 + 0x178) = *(int *)(s0 + 0x14);
}
}
