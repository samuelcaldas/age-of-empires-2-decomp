#include "sub_list.h"

extern "C" {
void *func_100730(int size);
void *func_1004E0(void *ptr, void *ctor, void *dtor, int elem_size, int count);
extern char D_4D7758[];
extern char D_00144440[];
extern char D_00144470[];
void func_0013C4F0(void *self);
void func_0013C510(void *self);
}

struct Item16 {
    int f0;
    int f4;
    short f8;
    short fA;
    int fC;
};

struct Item8 {
    short f0;
    short f2;
    int f4;
};

struct TacticalAI {
    void *m_vtable;
    short field_4;
    short field_6;
    void **field_8;
    short field_C;
    short field_E;
    void *field_10;
    short field_14;
    short field_16;
    void *field_18;
    short field_1C;
    short pad_1E;
    Item16 *field_20;
    Item8 *field_24;
    int field_28;
    int field_2C;
    int field_30;
};

extern "C" {

TacticalAI *func_001407B0(TacticalAI *self, int a1, int a2, int a3, int t0) {
    self->m_vtable = D_4D7758;
    self->field_1C = t0;
    self->field_28 = 0;
    self->field_2C = 0;
    self->field_30 = 0;
    self->field_4 = a1;
    self->field_6 = 0;

    self->field_8 = (void **)func_100730((long)(short)a1 * 4);

    self->field_C = a2;
    self->field_E = 0;
    a2 = (short)a2;
    void *p2 = func_100730((long)a2 * 24 + 16);
    self->field_10 = func_1004E0(p2, D_00144440, D_00144470, 24, a2);

    self->field_14 = a3;
    self->field_16 = 0;
    a3 = (short)a3;
    void *p3 = func_100730((long)a3 * 12 + 16);
    self->field_18 = func_1004E0(p3, (void *)func_0013C4F0, (void *)func_0013C510, 12, a3);

    self->field_20 = (Item16 *)func_100730((long)self->field_1C * 16);
    for (int i = 0; i < self->field_1C; i++) {
        self->field_20[i].f0 = 0;
        self->field_20[i].f4 = -1;
        self->field_20[i].f8 = 0;
        self->field_20[i].fA = 0;
        self->field_20[i].fC = 0;
    }

    self->field_24 = (Item8 *)func_100730((long)self->field_1C * 8);
    for (int i = 0; i < self->field_1C; i++) {
        self->field_24[i].f0 = 0;
        self->field_24[i].f2 = 0;
        self->field_24[i].f4 = 0;
    }

    return self;
}

}
