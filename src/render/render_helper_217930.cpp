#pragma exceptions off

extern "C" {
void func_25DE30(void *arg, int val);
void *func_25F2B0(int val);
void func_25D6D0(void *target, void *arg1, int arg2);
void func_25DF80(void *target, int *out1, int *out2, int *out3, int *out4, int extra);

void func_00217930(void *self, void *arg1, int arg2) {
    char *s0 = (char *)self;
    void *field180 = *(void **)(s0 + 0x180);

    if (field180 != 0) {
        func_25DE30(field180, 1);
        *(void **)(s0 + 0x180) = 0;
        *(short *)(s0 + 0x184) = 0;
        *(short *)(s0 + 0x186) = 0;
    }

    if (arg2 != -1 || (arg1 != 0 && *(char *)arg1 != 0)) {
        void *s1;
        if ((s1 = func_25F2B0(0x14)) != 0) {
            func_25D6D0(s1, arg1, arg2);
        }
        *(void **)(s0 + 0x180) = s1;

        int out0, out1, out2, out3;
        func_25DF80(*(void **)(s0 + 0x180), &out0, &out1, &out2, &out3, 0);
        *(short *)(s0 + 0x184) = (short)out2 - (short)out0;
        *(short *)(s0 + 0x186) = (short)out3 - (short)out1;
    }
}
}
