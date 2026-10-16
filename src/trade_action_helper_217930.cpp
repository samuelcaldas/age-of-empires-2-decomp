#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_25DE30(void *arg, int val);
void *func_25F2B0(int val);
void func_25D6D0(void *target, void *arg1, int arg2);
void func_25DF80(void *target, int *out1, int *out2, int *out3, int *out4, int extra);

static inline void *get_target180(char *s0) {
    unsigned int val;
    const char *src = s0 + 0x180;
    char *dst = (char *)&val;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    return (void *)(unsigned long)val;
}

static inline void set_target180(char *s0, void *ptr) {
    unsigned int val = (unsigned int)(unsigned long)ptr;
    const char *src = (char *)&val;
    char *dst = s0 + 0x180;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

void func_00217930(void *self, void *arg1, int arg2) {
    char *s0 = (char *)self;
    void *field180 = get_target180(s0);
    void *s3 = arg1;
    int s2 = arg2;

    if (field180 != 0) {
        func_25DE30(field180, 1);
        set_target180(s0, 0);
        *(short *)(s0 + 0x184) = 0;
        *(short *)(s0 + 0x186) = 0;
    }

    if (s2 == -1 && (s3 == 0 || *(char *)s3 == 0)) {
        return;
    }

    void *s1 = func_25F2B0(0x14);
    if (s1 != 0) {
        func_25D6D0(s1, s3, s2);
    }
    set_target180(s0, s1);

    void *target180 = get_target180(s0);
    int out0, out1, out2, out3;
    func_25DF80(target180, &out0, &out1, &out2, &out3, 0);
    *(short *)(s0 + 0x184) = (short)out2 - (short)out0;
    *(short *)(s0 + 0x186) = (short)out3 - (short)out1;
}
}
