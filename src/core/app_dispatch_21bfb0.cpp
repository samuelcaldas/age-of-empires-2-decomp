#pragma exceptions off
#include "sub_list.h"

struct AppDispatchClass {
    virtual void M0() = 0;
    virtual void MethodC();
};

extern "C" {
extern void *D_004E32E4;

void func_0021BFB0() {
    ((AppDispatchClass *)D_004E32E4)->MethodC();
}
}
