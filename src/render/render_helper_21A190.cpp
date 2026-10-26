#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern void *D_00C5C2A0[2];
extern int D_00C5C2A8[2];
extern int D_00C5C2B0[2];

extern int D_004E32D8;
extern char D_01DC8000;

int func_00219FB0(void *buf, int capacity, char flag1, char flag2);
void func_0021A040(int index);
void *func_117AF8(void *dst, const void *src, int len);

void func_0021A190(void) {
    D_004E32D8 = func_00219FB0(&D_01DC8000, 0, 0, 1);
}

int func_0021A1C0(void) {
    func_0021A040(D_004E32D8);
    return 0;
}

void func_0021A1E0(void) {
    int slot = D_004E32D8;
    int cap = D_00C5C2A8[slot];
    char *ptr = (char *)D_00C5C2A0[slot];
    *(int *)(ptr + 0x40) = cap;
}

void *func_0021A210(void) {
    void *ptr = D_00C5C2A0[D_004E32D8];
    if (ptr != 0) {
        return ptr;
    }
    return (void *)(long)-1;
}

int func_0021A240(void) {
    return D_00C5C2A8[D_004E32D8];
}

int func_0021A260(const void *src, int len) {
    int slot = D_004E32D8;
    int cur_size = D_00C5C2B0[slot];
    int new_size = cur_size + len;

    if (new_size >= 0x7D001) {
        return -1;
    }

    char *dst = &D_01DC8000 + cur_size;
    func_117AF8(dst, src, len);

    D_00C5C2B0[slot] = new_size;
    D_00C5C2A8[slot] += len;
    return len;
}
}
