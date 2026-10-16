#pragma exceptions off
#include "sub_list.h"

extern "C" {
void func_00217B50(void *self, int arg1);
void func_00219BA0(void *self, short arg1);
void func_00219430(void *self, short arg1);

short func_002193D0(void *self) {
    return *(short *)((char *)self + 0x120);
}

short func_002193E0(void *self) {
    return *(short *)((char *)self + 0x122);
}

short func_002193F0(void *self) {
    return *(short *)((char *)self + 0x128);
}

void func_00219400(void *self, short arg1) {
    func_00219430(self, arg1);
}

void func_00219410(void *self, short arg1) {
    func_00219BA0(self, arg1);
}

void func_00219420(void *self, short arg1) {
    *(short *)((char *)self + 0x128) = arg1;
}

void func_00219430(void *self, short arg1) {
    *(short *)((char *)self + 0x128) = arg1;
    func_00217B50(self, 1);
}
}
