#pragma exceptions off
#include "unit_action_build_3330.h"

extern "C" {
    void func_00195000(void *self, void *stream);
    void func_00226F70(void *stream, void *data, int size);
    int func_0026AD20(void *self, int flag);
}

typedef void (*Vtable10Method)(void *self, void *stream);

static void write_initial_fields(void *self, void *stream) {
    func_00226F70(stream, (char *)self + 0x11A, 1);

    char flag_byte = (char)func_0026AD20(self, 0x100);
    func_00226F70(stream, &flag_byte, 1);

    char zero_byte = 0;
    func_00226F70(stream, &zero_byte, 1);

    for (int i = 0; i < 6; ++i) {
        func_00226F70(stream, (char *)self + 0x100 + i * 2, 2);
    }

    func_00226F70(stream, (char *)self + 0x10C, 2);

    int field_118 = *(unsigned char *)((char *)self + 0x118);
    func_00226F70(stream, &field_118, 4);

    int field_124 = *(short *)((char *)self + 0x124);
    func_00226F70(stream, &field_124, 4);
}

static void write_target_object(void *self, void *stream) {
    void *c8 = *(void **)((char *)self + 0xC8);
    if (c8 != nullptr) {
        int one_val = 1;
        func_00226F70(stream, &one_val, 4);
        void *obj = *(void **)c8;
        void **vtbl = *(void ***)obj;
        Vtable10Method fn = (Vtable10Method)vtbl[4];
        fn(obj, stream);
        return;
    }

    int zero_val = 0;
    func_00226F70(stream, &zero_val, 4);
}

static void write_final_fields(void *self, void *stream) {
    char flag_400 = (char)func_0026AD20(self, 0x400);
    func_00226F70(stream, &flag_400, 1);

    int field_10E = *(short *)((char *)self + 0x10E);
    func_00226F70(stream, &field_10E, 4);

    func_00226F70(stream, (char *)self + 0x110, 4);
    func_00226F70(stream, (char *)self + 0x114, 4);
    func_00226F70(stream, (char *)self + 0x11C, 4);
    func_00226F70(stream, (char *)self + 0x119, 1);
}

void func_273330(void *self, void *stream) {
    func_00195000(self, stream);
    write_initial_fields(self, stream);
    write_target_object(self, stream);
    write_final_fields(self, stream);
}
