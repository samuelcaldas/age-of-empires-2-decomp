#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern void *D_00C5C2A0[];
extern int D_00C5C2A8[];
extern int D_00C5C2B0[];

#define BUFFER_01E98000 ((void *)0x01E98000)

int func_0021BC30(void *arg0, void *buf, int arg2, int capacity, int arg4);
int func_00219FB0(void *buf, int capacity, char flag1, char flag2);
void func_0021A040(int index);
void *func_117AF8(void *dst, const void *src, int len);

int func_0021A0A0(void *arg0, int arg1, int capacity) {
    func_0021BC30(arg0, BUFFER_01E98000, arg1, capacity, 1);
    return func_00219FB0(BUFFER_01E98000, capacity, 0, 0);
}

void func_0021A0F0(int index) {
    func_0021A040(index);
}

int func_0021A100(int slot, void *user_dest, int len) {
    int cur_size = D_00C5C2B0[slot];
    int overflow = D_00C5C2A8[slot] < cur_size + len;
    if (overflow) {
        return -1;
    }

    char *src = (char *)D_00C5C2A0[slot];
    src += cur_size;
    func_117AF8(user_dest, src, len);
    D_00C5C2B0[slot] += len;
    return len;
}
}
