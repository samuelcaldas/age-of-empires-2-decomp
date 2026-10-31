#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern void *D_00C5C2A0[2];
extern int D_00C5C2A8[2];
extern int D_00C5C2B0[2];
extern char D_00C5C2B8[2];
extern char D_00C5C2BA[2];

void func_00219F60(void) {
    char *cp;
    int *p = (int *)D_00C5C2A0;
    cp = (char *)D_00C5C2A0;
    for (int i = 0; i < 2; i++) {
        p[i] = 0;
        p[i + 2] = 0;
        p[i + 4] = 0;
        cp[i + 24] = 0;
        cp[i + 26] = 0;
    }
}

int func_00219FB0(void *buf, int capacity, char flag1, char flag2) {
    int i = 0;
    do {
        if (D_00C5C2A0[i] == 0) {
            goto found;
        }
        i++;
    } while (i != 2);
    return -1;
found:
    D_00C5C2A0[i] = buf;
    D_00C5C2A8[i] = capacity;
    D_00C5C2B0[i] = 0;
    D_00C5C2B8[i] = flag1;
    D_00C5C2BA[i] = flag2;
    return i;
}

void func_0021A040(int index) {
    D_00C5C2A0[index] = 0;
    D_00C5C2A8[index] = 0;
    D_00C5C2B0[index] = 0;
    D_00C5C2B8[index] = 0;
    D_00C5C2BA[index] = 0;
}
}
