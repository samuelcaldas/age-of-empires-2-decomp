#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_0021E350(unsigned short val);

void func_0021A680(void *self) {
    char *s1 = (char *)self;
    unsigned int flags = *(unsigned int *)(s1 + 0x98);
    int s2 = *(int *)(s1 + 0x3C);
    int s3 = *(int *)(s1 + 0x54);
    unsigned short s0 = 0;

    if ((flags & 0x800) != 0) {
        s2 = 640;
        s3 = 0xA3000;
    }

    void *ptr14 = *(void **)(s1 + 0x14);
    if (ptr14 != 0) {
        s0 = *(unsigned short *)((char *)ptr14 + 2);
    }

    int v0_res = func_0021E350(s0);
    int f1c = *(int *)(s1 + 0x1C);

    unsigned long long val = 0;
    val |= (unsigned long long)(unsigned int)(s3 >> 6);
    val |= ((unsigned long long)(unsigned int)(s2 >> 6)) << 14;
    val |= ((unsigned long long)(unsigned int)f1c) << 20;
    val |= 0xA8000000ULL;
    val |= 6ULL << 32;
    val |= ((unsigned long long)(unsigned int)(v0_res >> 6)) << 37;
    val |= 0x200000000000ULL;
    val |= ((unsigned long long)(s0 & 0xF)) << 56;

    *(unsigned long long *)(s1 + 0x20) = val;
}
}
