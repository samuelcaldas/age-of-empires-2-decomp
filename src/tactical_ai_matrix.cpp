#include "sub_list.h"

#pragma exceptions off

extern "C" {
    void* func_100730(unsigned int size);
    void* func_1004E0(void *ptr, void (*ctor)(void*), void (*dtor)(void*), unsigned int size, int count);
    void func_1002A0(void *ptr, void (*dtor)(void*));
    void func_00100630(void *ptr);
    void func_145680(void *ptr);
    void func_1456F0(void *ptr);
    int func_00141A20(void *self, int index);
    void func_00144530(void *node);
    int func_00141C70(void *self);

    int func_00141500(void *self, int size);
    int func_00141630(void *self, int index);
    int func_00141760(void *self, int index, short *out);
    int func_001418B0(void *self);
}

struct SubElement {
    char pad_0[5];
    char field_5;
    char pad_6[0x148 - 6];
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
    char pad_4[8];
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
};

int func_00141500(void *self, int size) {
    TacticalAI *ai = (TacticalAI*)self;
    for (int i = 0; i < (int)ai->m_field1C; i++) {
        Field20Elem *e = &ai->m_field20[i];
        if (e->field_0 == 0) {
            e->field_0 = 1;
            long long s = (short)size;
            e->field_4 = i;
            e->field_8 = size;
            void *mem = func_100730((unsigned int)(s * 0x148 + 0x10));
            e->field_A = 0;
            e->field_C = (SubElement*)func_1004E0(mem, func_145680, func_1456F0, 0x148, (int)s);

            Field24Elem *f = &ai->m_field24[i];
            f->field_0 = 100;
            short *arr = (short*)func_100730(200);
            f->field_2 = 0;
            f->field_4 = arr;
            for (int k = 0; k < 100; k++) {
                arr[k] = -1;
            }
            return e->field_4;
        }
    }
    return -1;
}

int func_00141630(void *self, int index) {
    TacticalAI *ai = (TacticalAI*)self;
    if (!func_00141A20(ai, index)) {
        return 0;
    }
    Field20Elem *e = &ai->m_field20[index];
    if (e->field_C) {
        func_1002A0(e->field_C, func_1456F0);
    }
    e->field_A = 0;
    long long s = (short)e->field_8;
    void *mem = func_100730((unsigned int)(s * 0x148 + 0x10));
    e->field_C = (SubElement*)func_1004E0(mem, func_145680, func_1456F0, 0x148, (int)s);

    Field24Elem *f = &ai->m_field24[index];
    if (f->field_4) {
        func_00100630(f->field_4);
    }
    f->field_0 = 100;
    short *arr = (short*)func_100730(200);
    f->field_2 = 0;
    f->field_4 = arr;
    for (int k = 0; k < 100; k++) {
        arr[k] = -1;
    }
    return 1;
}

int func_00141760(void *self, int index, short *out) {
    TacticalAI *ai = (TacticalAI*)self;
    if (!func_00141A20(ai, index)) {
        return 0;
    }
    ai->m_field2C = &ai->m_field20[index];
    ai->m_field30 = &ai->m_field24[index];
    for (int i = 0; i < (int)ai->m_fieldE; i++) {
        func_00144530(&ai->m_field10[i]);
    }
    short count = 0;
    short cap = ai->m_field2C->field_A;
    for (int i = 0; i < (int)ai->m_field2C->field_A; i++) {
        SubElement *sub = &ai->m_field2C->field_C[i];
        if (sub->field_5 != 0) {
            ai->m_active_node = sub;
            if (func_00141C70(ai) != 0) {
                count++;
            }
        }
    }
    if (out) {
        out[0] = cap;
        out[1] = count;
    }
    ai->m_active_node = 0;
    ai->m_field2C = 0;
    ai->m_field30 = 0;
    return 1;
}

int func_001418B0(void *self) {
    TacticalAI *ai = (TacticalAI*)self;
    if (ai->m_active_node) goto is_active;
    return 0;
is_active:
    ai->m_active_node->field_5 = 0;
    return 1;
}
