#pragma exceptions off
#include "unit_action_build_3130.h"

extern "C" {
    void func_0026AD60(void *self, int flag);
    void func_00194F00(void *self, void *target, void *stream);
    void func_0026AD30(void *self, int flag);
    void func_00226D90(void *stream, void *dst, int size);
}

typedef void (*VtableCallMethod)(void *self);

static void read_initial_fields(void *self, void *stream) {
    func_00226D90(stream, (char *)self + 0x100, 12);
    func_00226D90(stream, (char *)self + 0x10C, 2);

    func_0026AD30(self, 0x80);
    func_00226D90(stream, (char *)self + 0x10E, 2);

    int dummy = 0;
    func_00226D90(stream, &dummy, 4);

    func_00226D90(stream, (char *)self + 0x110, 4);
    func_00226D90(stream, (char *)self + 0x114, 4);
    func_00226D90(stream, (char *)self + 0x118, 1);
    func_00226D90(stream, (char *)self + 0x120, 4);
}

static void read_final_fields(void *self, void *stream) {
    func_00226D90(stream, (char *)self + 0x11A, 1);
    func_0026AD30(self, 0x100);
    func_00226D90(stream, (char *)self + 0x119, 1);
    func_00226D90(stream, (char *)self + 0x124, 2);

    int dummy1 = 0;
    int dummy2 = 0;
    func_00226D90(stream, &dummy1, 4);
    func_00226D90(stream, &dummy2, 4);

    func_00226D90(stream, (char *)self + 0x11C, 4);
}

int func_00273130(void *self, void *target, void *stream) {
    func_0026AD60(self, 0x200);
    func_00194F00(self, target, stream);

    read_initial_fields(self, stream);

    void **self_vtbl = *(void ***)self;
    VtableCallMethod v374 = (VtableCallMethod)self_vtbl[221];
    v374(self);

#if defined(__LP64__) || defined(_LP64)
    void *owner = *(void **)((char *)self + 0x10);
#else
    void *owner = *(void **)((char *)self + 0x8);
#endif
    void **owner_vtbl = *(void ***)owner;
    VtableCallMethod owner_fn = (VtableCallMethod)owner_vtbl[34];
    owner_fn(owner);

    read_final_fields(self, stream);

    return 1;
}
