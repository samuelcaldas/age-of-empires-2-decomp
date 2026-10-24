#pragma exceptions off
#include "sub_list.h"

extern "C" {

void func_002BE570(void *self, int val);

void func_002B6160(void *self) {
    func_002BE570(self, 0x65);
}

int func_002B6170(void *self) {
    return *(int *)((char *)self + 0x108);
}

}
