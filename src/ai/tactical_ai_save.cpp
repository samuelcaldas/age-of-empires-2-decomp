#include "sub_list.h"

#pragma exceptions off

extern "C" {
    int func_00226F70(void *stream, void *buf, int size);
    int func_0011ACD0(const char *str);
    void* func_116F40(int size);
    char* func_0011ABBC(char *dst, const char *src);
    void func_001444C0(void *node, int a1, char a2, int (*a3)(), char t0, char t1, char t2, char t3);
    void func_0013C560(void *elem, int a1, int a2, int a3, int t0, int t1, int t2);

    int func_001410E0(void *self, const char *str);
    int func_00141170(void *self, int a1, char a2, int (*a3)());
    int func_001411E0(void *self, int a1, int a2);
}

struct SubElement {
    char data[0x148];
};

struct Field20Elem {
    int field_0;
    char pad_4[6];
    short field_A;
    SubElement *field_C;
};

struct Field24Elem {
    char pad_0[2];
    short field_2;
    void *field_4;
};

struct TacticalNodeRecord {
    char data[24];
};

struct TacticalElem18 {
    char data[12];
};

struct TacticalAI {
    void *vtable;
    short m_field4;
    short m_field6;
    char **m_field8;
    short m_fieldC;
    short m_fieldE;
    TacticalNodeRecord *m_field10;
    short m_field14;
    short m_field16;
    TacticalElem18 *m_field18;
    short m_field1C;
    short pad_1E;
    Field20Elem *m_field20;
    Field24Elem *m_field24;

    int Save(void *stream);
};

int TacticalAI::Save(void *stream) {
    int len;
    func_00226F70(stream, &this->m_field4, 8);
    for (int i = 0; i < this->m_field6; i++) {
        len = func_0011ACD0(this->m_field8[i]);
        func_00226F70(stream, &len, 4);
        func_00226F70(stream, this->m_field8[i], len);
    }
    func_00226F70(stream, &this->m_fieldC, 2);
    func_00226F70(stream, &this->m_field14, 2);
    func_00226F70(stream, &this->m_field1C, 2);
    for (int i = 0; i < this->m_field1C; i++) {
        Field20Elem *e = &this->m_field20[i];
        func_00226F70(stream, e, 0x10);
        if (e->field_0 != 0 && e->field_C != 0) {
            for (int j = 0; j < e->field_A; j++) {
                func_00226F70(stream, &e->field_C[j], 0x148);
            }
        }
    }
    for (int i = 0; i < this->m_field1C; i++) {
        Field24Elem *e = &this->m_field24[i];
        func_00226F70(stream, e, 8);
        if (this->m_field20[i].field_0 != 0 && e->field_4 != 0) {
            func_00226F70(stream, e->field_4, (int)e->field_2 * 2);
        }
    }
    return 1;
}

int func_001410E0(void *self, const char *str) {
    TacticalAI *ai = (TacticalAI*)self;
    if (ai->m_field6 >= ai->m_field4) {
        return -1;
    }
    int len = func_0011ACD0(str);
    char *buf = (char*)func_116F40(len + 1);
    ai->m_field8[ai->m_field6] = buf;
    func_0011ABBC(ai->m_field8[ai->m_field6], str);
    int old = ai->m_field6;
    ai->m_field6 = old + 1;
    return old;
}

int func_00141170(void *self, int a1, char a2, int (*a3)()) {
    TacticalAI *ai = (TacticalAI*)self;
    if (ai->m_fieldE >= ai->m_fieldC) {
        return -1;
    }
    func_001444C0(&ai->m_field10[ai->m_fieldE], a1, a2, a3, 0, 0, 0, 0);
    int old = ai->m_fieldE;
    ai->m_fieldE = old + 1;
    return old;
}

int func_001411E0(void *self, int a1, int a2) {
    TacticalAI *ai = (TacticalAI*)self;
    if (ai->m_field16 >= ai->m_field14) {
        return -1;
    }
    func_0013C560(&ai->m_field18[ai->m_field16], a1, a2, 0, 0, 0, 0);
    int old = ai->m_field16;
    ai->m_field16 = old + 1;
    return old;
}
