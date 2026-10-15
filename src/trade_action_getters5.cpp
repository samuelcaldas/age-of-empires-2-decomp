#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern const char D_4D0570[];
void *func_001454C0(void *a0, const char *a1, int a2);
int func_2BBCD0(void);
int func_2B9770(void *a0, int a1, int a2);

void func_002B6180(void *self, int index) {
    if (index == -1) {
        func_001454C0(self, D_4D0570, index);
    } else {
        func_2BBCD0();
        func_2B9770(self, index, 100);
    }
}

}
