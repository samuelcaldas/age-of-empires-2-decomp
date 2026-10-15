#include "sub_list.h"

#pragma exceptions off

extern "C" {
    extern void* D_4D7758[];
    void D_00144440(void*);
    void D_00144470(void*);
    void func_0013C4F0(void*);
    void func_0013C510(void*);
    void func_145680(void*);
    void func_1456F0(void*);

    int func_00226D90(void *stream, void *buf, int size);
    void* func_100730(unsigned int size);
    void* func_1004E0(void *ptr, void (*ctor)(void*), void (*dtor)(void*), unsigned int size, int count);
    void* func_116F40(int size);
    void func_116F68(void *ptr);
    void func_00100630(void *ptr);
    void func_1002A0(void *ptr, void (*dtor)(void*));
    void func_00100670(void *ptr);

    void* func_001409B0(void *self, void *stream);
    void* func_00140D40(void *self, int flag);
}

struct SubElement {
    char data[0x148];
};

struct Field20Elem {
    int field_0;
    int field_4;
    short field_8;
    short field_A;
    SubElement *field_C;
};

struct Field24Elem {
    short field_0;
    short field_2;
    short *field_4;
};

struct TacticalNodeRecord {
    char data[24];
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
    void *m_field18;
    short m_field1C;
    short pad_1E;
    Field20Elem *m_field20;
    Field24Elem *m_field24;
    SubElement *m_active_node;
    Field20Elem *m_field2C;
    Field24Elem *m_field30;

    TacticalAI* Load(void *stream);
    TacticalAI* Destroy(int flag);
};

void* func_001409B0(void *self, void *stream) {
    TacticalAI *ai = (TacticalAI*)self;
    ai->vtable = D_4D7758;
    func_00226D90(stream, &ai->m_field4, 8);
    long long bytes = (long long)ai->m_field4 * 4;
    ai->m_field8 = (char**)func_100730((unsigned int)bytes);
    for (int i = 0; i < ai->m_field6; i++) {
        int len;
        func_00226D90(stream, &len, 4);
        char *buf = (char*)func_116F40(len + 1);
        ai->m_field8[i] = buf;
        func_00226D90(stream, buf, len);
        buf[len] = 0;
    }
    func_00226D90(stream, &ai->m_fieldC, 2);
    ai->m_fieldE = 0;
    long long c = ai->m_fieldC;
    void *mem10 = func_100730((unsigned int)(c * 24 + 16));
    ai->m_field10 = (TacticalNodeRecord*)func_1004E0(mem10, D_00144440, D_00144470, 24, (int)c);

    func_00226D90(stream, &ai->m_field14, 2);
    ai->m_field16 = 0;
    long long c14 = ai->m_field14;
    void *mem18 = func_100730((unsigned int)(c14 * 12 + 16));
    ai->m_field18 = func_1004E0(mem18, func_0013C4F0, func_0013C510, 12, (int)c14);

    func_00226D90(stream, &ai->m_field1C, 2);
    long long c1C_bytes = (long long)ai->m_field1C * 16;
    ai->m_field20 = (Field20Elem*)func_100730((unsigned int)c1C_bytes);
    for (int i = 0; i < ai->m_field1C; i++) {
        Field20Elem *e = &ai->m_field20[i];
        func_00226D90(stream, e, 16);
        if (e->field_0 != 0) {
            long long s = e->field_8;
            void *mem = func_100730((unsigned int)(s * 0x148 + 16));
            e->field_C = (SubElement*)func_1004E0(mem, func_145680, func_1456F0, 0x148, (int)s);
            for (int j = 0; j < e->field_A; j++) {
                func_00226D90(stream, &e->field_C[j], 0x148);
            }
        } else {
            e->field_C = 0;
        }
    }

    long long c24_bytes = (long long)ai->m_field1C * 8;
    ai->m_field24 = (Field24Elem*)func_100730((unsigned int)c24_bytes);
    for (int i = 0; i < ai->m_field1C; i++) {
        Field24Elem *f = &ai->m_field24[i];
        func_00226D90(stream, f, 8);
        if (ai->m_field20[i].field_0 != 0) {
            long long f0_bytes = (long long)f->field_0 * 2;
            f->field_4 = (short*)func_100730((unsigned int)f0_bytes);
            func_00226D90(stream, f->field_4, f->field_2 * 2);
            for (int j = f->field_2; j < f->field_0; j++) {
                f->field_4[j] = -1;
            }
        } else {
            f->field_4 = 0;
        }
    }

    ai->m_active_node = 0;
    ai->m_field2C = 0;
    ai->m_field30 = 0;
    return ai;
}

void* func_00140D40(void *self, int flag) {
    TacticalAI *ai = (TacticalAI*)self;
    if (ai) {
        ai->vtable = D_4D7758;
        for (int i = 0; i < ai->m_field6; i++) {
            func_116F68(ai->m_field8[i]);
        }
        if (ai->m_field8) {
            func_00100630(ai->m_field8);
        }
        if (ai->m_field10) {
            func_1002A0(ai->m_field10, D_00144470);
        }
        if (ai->m_field18) {
            func_1002A0(ai->m_field18, func_0013C510);
        }
        for (int i = 0; i < ai->m_field1C; i++) {
            Field20Elem *e = &ai->m_field20[i];
            if (e->field_0 != 0) {
                if (e->field_C) {
                    func_1002A0(e->field_C, func_1456F0);
                }
            }
        }
        for (int i = 0; i < ai->m_field1C; i++) {
            Field20Elem *e = &ai->m_field20[i];
            if (e->field_0 != 0) {
                if (ai->m_field24[i].field_4) {
                    func_00100630(ai->m_field24[i].field_4);
                }
            }
        }
        if (ai->m_field24) {
            func_00100630(ai->m_field24);
        }
        if (ai->m_field20) {
            func_00100630(ai->m_field20);
        }
        ai->m_active_node = 0;
        ai->m_field2C = 0;
        ai->m_field30 = 0;
        if ((short)flag > 0) {
            func_00100670(ai);
        }
    }
    return self;
}
