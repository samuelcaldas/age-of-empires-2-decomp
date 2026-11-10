#include "trade_action_load.h"

extern "C" {

void func_00146A40(TradeAction *self, void *stream) {
    ActionItem1Packed item;
    ActionItem1 item_unpacked;
    ActionItem2Packed item2;
    ActionItem2 item2_unpacked;
    int ival;
    float fval;
    int has164;
    Vector16 vec;
    int ival2;

    func_00226D90(stream, &ival, 4);

    func_00226D90(stream, &ival, 4);
    self->m_field44 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field46 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field48 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field4A = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field4C = ival;

    func_00226D90(stream, &self->m_float50, 4);
    func_00226D90(stream, &self->m_float54, 4);
    func_00226D90(stream, &self->m_float58, 4);
    func_00226D90(stream, &self->m_float5C, 4);

    func_00226D90(stream, &ival, 4);
    self->m_field62 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field60 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field64 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field66 = ival;

    func_00226D90(stream, &self->m_field138, 4);
    func_00226D90(stream, &self->m_field13C, 4);
    func_00226D90(stream, &self->m_field144, 4);
    func_00226D90(stream, &self->m_field140, 4);
    func_00226D90(stream, &self->m_field148, 4);
    func_00226D90(stream, &self->m_field14C, 4);
    func_00226D90(stream, &self->m_field150, 4);

    func_00226D90(stream, &ival, 4);
    self->m_field4E = ival;

    func_00226D90(stream, &fval, 4);

    func_00226D90(stream, &vec, 16);

    func_00226D90(stream, &ival, 4);
    int count1 = (unsigned char)ival;

    for (int i = 0; i < count1; i++) {
        func_00226D90(stream, &item, 36);
        item_unpacked.m_s0 = item.m_s0;
        item_unpacked.m_s2 = item.m_s2;
        item_unpacked.m_s4 = item.m_s4;
        item_unpacked.m_s6 = item.m_s6;
        item_unpacked.m_f8 = item.m_f8;
        item_unpacked.m_fC = item.m_fC;
        item_unpacked.m_f10 = item.m_f10;
        item_unpacked.m_f14 = item.m_f14;
        func_001508F0(self, &item_unpacked, 0);
    }

    func_00226D90(stream, &ival, 4);
    int count2 = (unsigned char)ival;

    for (int j = 0; j < count2; j++) {
        func_00226D90(stream, &item2, 24);
        item2_unpacked.m_s0 = item2.m_s0;
        item2_unpacked.m_s2 = item2.m_s2;
        item2_unpacked.m_s4 = item2.m_s4;
        item2_unpacked.m_i8 = item2.m_i8;
        item2_unpacked.m_iC = item2.m_iC;
        item2_unpacked.m_i10 = item2.m_i10;
        func_00150CC0(self, &item2_unpacked);
    }

    func_00226D90(stream, &ival2, 4);

    for (int k = 0; k < ival2; k++) {
        func_00226D90(stream, &ival, 4);
        self->m_fieldA4[k] = ival;
    }

    func_00226D90(stream, &self->m_field2D, 1);
    func_00226D90(stream, &self->m_field2E, 1);
    func_00226D90(stream, &self->m_float154, 4);
    func_00226D90(stream, &self->m_float158, 4);
    func_00226D90(stream, &self->m_field15C, 4);
    func_00226D90(stream, &self->m_field2F, 1);
    func_00226D90(stream, &self->m_field160, 4);

    func_00226D90(stream, &has164, 4);
    if (has164 != 0) {
        self->m_field164 = func_001FC6C0();
        func_001FDCC0(self->m_field164, stream);
    }
    func_00226D90(stream, &self->m_field168, 4);

    func_00226D90(stream, &ival, 4);

    func_00226D90(stream, &ival, 4);
    self->m_field68 = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field6A = ival;

    func_00226D90(stream, &self->m_field70, 4);
    func_00226D90(stream, self->m_field74, 12);

    func_00226D90(stream, &ival, 4);
    self->m_field6C = ival;
    func_00226D90(stream, &ival, 4);
    self->m_field6E = ival;

    func_00226D90(stream, self->m_field80, 12);
    func_00226D90(stream, &self->m_field8C, 4);
    func_00226D90(stream, &self->m_field16C, 4);

    func_00226D90(stream, &ival, 4);
    int count3 = (unsigned char)ival;

    for (int m = 0; m < count3; m++) {
        func_00150770(self, m);
        func_00226D90(stream, &self->m_field174[m].m_p1, 4);
        func_00226D90(stream, &self->m_field174[m].m_p2, 4);
    }

    func_00226D90(stream, &ival, 4);
    self->m_field170 = ival;
    func_00226D90(stream, &self->m_field30, 1);
}

}
