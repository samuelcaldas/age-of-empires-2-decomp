#pragma exceptions off
#include "sub_list.h"
#include "zone_destructor.h"

extern char D_4D9270[];
extern void *D_4E35DC;

extern "C" {

void func_335560(void *allocator, void *ptr);
void func_00100670(void *ptr); // operator delete

void *func_001C8FF0(void *self, int flag) {
    if (!self) {
        return 0;
    }

    *(void **)self = D_4D9270;

    void *field_8EEC = *(void **)((char *)self + 0x8EEC);
    if (field_8EEC) {
        func_335560(D_4E35DC, field_8EEC);
    }

    if ((short)flag > 0) {
        func_00100670(self);
    }

    return self;
}

}
