#pragma exceptions off
#include "sub_list.h"

extern "C" {
extern void *D_004E32E4;

void func_0021BFB0() {
    void *obj = D_004E32E4;
    void (**vtable)(void *) = *(void (***)(void *))obj;
    vtable[3](obj);
}
}
