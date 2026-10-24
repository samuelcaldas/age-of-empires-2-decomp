#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern int D_004E2E50[];
extern char D_003921D0[];
extern char D_01E98000;
extern char D_00C5C2BA[];

extern void *D_00C5C2C0;
extern char *D_00C5C2C4;
extern int D_00C5C2C8;
extern int D_00C5C2CC;

int func_0021BC30(void *arg0, void *buf, int arg2, int capacity, int arg4);
int func_0011C888(int c);
int strcmp(const char *s1, const char *s2);

void func_0021A310(int index) {
    int id = D_004E2E50[index];
    void *record = D_003921D0 + id * 12;
    int capacity = *(int *)record;

    func_0021BC30(record, &D_01E98000, 0, capacity, 1);

    D_00C5C2C0 = &D_01E98000;
    D_00C5C2C4 = &D_01E98000 + 4;

    short count = *(short *)D_00C5C2C0;
    D_00C5C2C8 = (int)count;

    short stride = *(short *)((char *)D_00C5C2C0 + 2);
    D_00C5C2CC = (int)stride;

    char *item = D_00C5C2C4;
    for (int i = 0; i < count; i++) {
        char *rel_ptr = *(char **)(item + 0x20);
        *(char **)(item + 0x20) = &D_01E98000 + (long)rel_ptr;
        item += 0x24;
    }
}

void *func_0021A3F0(const char *name) {
    char lower_buf[64];
    int idx = 0;

    const char *p = name;
    while (*p != '\0') {
        lower_buf[idx] = (char)func_0011C888((unsigned char)*p);
        idx++;
        p++;
    }
    lower_buf[idx] = '\0';

    char *item = D_00C5C2C4;
    int max_count = D_00C5C2C8 - 1;

    for (int i = 0; i < max_count; i++) {
        if (strcmp(lower_buf, item) == 0) {
            return *(void **)(item + 0x20);
        }
        item += 0x24;
    }

    return 0;
}

int func_0021A4A0(int index) {
    int count = D_00C5C2C8;
    int stride = D_00C5C2CC;
    char *end_item = D_00C5C2C4 + count * 36;
    int base = *(int *)(end_item - 4);
    return base + index * stride;
}

char func_0021A4E0(int index) {
    return D_00C5C2BA[index];
}

void func_0021A500(int index, char val) {
    D_00C5C2BA[index] = val;
}
}
