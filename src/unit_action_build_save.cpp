#pragma exceptions off
#include "unit_action_build_save.h"

static void write_header_fields(ActionRebind *self, void *stream) {
    char flag4000 = func_26AD20(self, 0x4000);
    func_00226F70(stream, &flag4000, 1);
    func_00226F70(stream, (char*)self + 0x170, 4);
    func_00226F70(stream, (char*)self + 0x178, 4);

    char byte_ba5 = 0;
    if (self->m_world != 0) {
        byte_ba5 = *(char*)((char*)self->m_world + 0xBA5);
    }
    func_00226F70(stream, &byte_ba5, 1);

    char zero_byte = 0;
    func_00226F70(stream, &zero_byte, 1);
    func_00226F70(stream, (char*)self + 0x148, 4);
    func_00226F70(stream, (char*)self + 0x144, 4);
}

static void write_state_fields(ActionRebind *self, void *stream) {
    int val_16c = (int)*(short*)((char*)self + 0x16C);
    func_00226F70(stream, &val_16c, 4);
    int zero_int = 0;
    func_00226F70(stream, &zero_int, 4);

    int val_15b = (int)*(unsigned char*)((char*)self + 0x15B);
    func_00226F70(stream, &val_15b, 4);
    func_00226F70(stream, (char*)self + 0x15C, 4);
    func_00226F70(stream, (char*)self + 0x160, 4);
    func_00226F70(stream, (char*)self + 0x164, 4);

    int val_168 = (int)*(short*)((char*)self + 0x168);
    func_00226F70(stream, &val_168, 4);
    func_00226F70(stream, (char*)self + 0x16A, 2);

    char flag800 = func_26AD20(self, 0x800);
    func_00226F70(stream, &flag800, 1);
    int flag1000 = (int)func_26AD20(self, 0x1000);
    func_00226F70(stream, &flag1000, 4);
}

static void write_items_and_trailing(ActionRebind *self, void *stream) {
    func_00226F70(stream, (char*)self + 0x127, 1);
    void *item1 = *(void**)((char*)self + 0x128);
    if (item1 != 0) Save__8BaseListFPv(item1, stream);
    void *item2 = *(void**)((char*)self + 0x12C);
    if (item2 != 0) Save__8BaseListFPv(item2, stream);

    short val_156 = (short)*(unsigned char*)((char*)self + 0x156);
    func_00226F70(stream, &val_156, 2);
    short val_157 = (short)*(unsigned char*)((char*)self + 0x157);
    func_00226F70(stream, &val_157, 2);
    short val_158 = (short)*(unsigned char*)((char*)self + 0x158);
    func_00226F70(stream, &val_158, 2);

    char zero_byte = 0;
    func_00226F70(stream, &zero_byte, 1);
    void *item3 = *(void**)((char*)self + 0x14C);
    if (item3 != 0) Save__8BaseListFPv(item3, stream);

    char pad12[12] = {0};
    func_00226F70(stream, pad12, 12);
    func_00226F70(stream, pad12, 12);

    int flag2000 = (int)func_26AD20(self, 0x2000);
    func_00226F70(stream, &flag2000, 4);
    int zero_int = 0;
    func_00226F70(stream, &zero_int, 4);

    func_00226F70(stream, (char*)self + 0x174, 4);
    func_00226F70(stream, (char*)self + 0x15A, 1);
    func_00226F70(stream, &zero_byte, 1);
}

void func_0026DAC0(ActionRebind *self, void *stream) {
    if (self == 0 || stream == 0) {
        return;
    }
    func_273330(self, stream);
    write_header_fields(self, stream);
    write_state_fields(self, stream);
    write_items_and_trailing(self, stream);
}
