#include "sub_list.h"

struct Item16 {
    void *field_0;
    int pad[3];
};

struct Node328 {
    char pad_0[2];
    short next;
    char pad_4;
    char field_5;
    char pad_6[322];
};

struct Obj2C {
    char pad_0[0xC];
    Node328 *nodes;
};

struct Obj30 {
    char pad_0[2];
    short count;
    short *table;
};

struct TacticalAI {
    void *m_vtable;
    char pad_04[0x18];
    short field_1C;
    short pad_1E;
    Item16 *field_20;
    char pad_24[0x8];
    Obj2C *field_2C;
    Obj30 *field_30;
};

extern "C" {

int func_001418E0(TacticalAI *self, int a1) {
    Obj30 *obj30 = self->field_30;
    if (!obj30) {
        return 0;
    }
    if (a1 < 0) goto ret0;
    if (a1 < obj30->count) goto valid;
ret0:
    return 0;
valid:
    int idx = obj30->table[a1];
    while (idx != -1) {
        self->field_2C->nodes[idx].field_5 = 0;
        idx = self->field_2C->nodes[idx].next;
    }
    return 1;
}

int func_00141980(TacticalAI *self, int a1) {
    Obj30 *obj30 = self->field_30;
    if (!obj30) {
        return 0;
    }
    if (a1 < 0) goto ret0;
    if (a1 < obj30->count) goto valid;
ret0:
    return 0;
valid:
    int idx = obj30->table[a1];
    while (idx != -1) {
        self->field_2C->nodes[idx].field_5 = 1;
        idx = self->field_2C->nodes[idx].next;
    }
    return 1;
}

int func_00141A20(TacticalAI *self, int a1) {
    if (a1 < 0) goto ret0;
    if (a1 < self->field_1C) goto valid;
ret0:
    return 0;
valid:
    return self->field_20[a1].field_0 ? 1 : 0;
}

}
