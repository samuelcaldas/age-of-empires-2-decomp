#pragma exceptions off
#include "sub_list.h"

extern "C" {
int strcmp(const char *s1, const char *s2);
void func_00217B50(void *self, int arg1);

void func_00219440(void *self, const char *arg1) {
    char *s4 = (char *)self;
    int s0 = *(short *)(s4 + 0x128);
    int index = 0;
    void *node = *(void **)(s4 + 0x11C);

    while (node != 0) {
        char *str = *(char **)node;
        if (strcmp(str, arg1) == 0) {
            s0 = index;
            break;
        }
        node = *(void **)((char *)node + 0x28);
        index++;
    }

    *(short *)(s4 + 0x128) = s0;
    func_00217B50(self, 1);
}
}
