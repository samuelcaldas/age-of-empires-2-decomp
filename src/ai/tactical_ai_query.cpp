#include "sub_list.h"

extern "C" {
int func_00141A20(void *self, int a1);
void *func_100730(int size);
void func_117AF8(void *dest, const void *src, int n);
void func_00100630(void *ptr);
void func_001444F0(void *node);
}

struct Node328 {
    union {
        struct {
            short f0;
            short f2;
            char f4;
        };
        int words[82];
    };
};

struct Item16 {
    int f0;
    int f4;
    short f8;
    short fA;
    Node328 *nodes;
};

struct Item8 {
    short f0;
    short f2;
    short *table;
};

struct TacticalNode24 {
    char pad[24];
};

struct TacticalAI {
    void *m_vtable;
    char pad_04[0x8];
    short field_C;
    short field_E;
    TacticalNode24 *field_10;
    char pad_14[0xC];
    Item16 *field_20;
    Item8 *field_24;
    short *field_28;
    int field_2C;
    int field_30;
};

extern "C" {

int func_00141250(TacticalAI *self, int a1, int a2, Node328 *a3) {
    Item16 *it = &self->field_20[a1];
    if (it->fA < it->f8) goto ok;
    return -1;
ok:
    it->nodes[it->fA] = *a3;
    it->nodes[it->fA].f4 = 1;
    it->nodes[it->fA].f0 = it->fA;
    if (a2 != -1) {
        short *slot = &self->field_24[a1].table[a2];
        it->nodes[it->fA].f2 = *slot;
        *slot = it->fA;
    }
    return it->fA++;
}

int func_00141370(TacticalAI *self, int a1) {
    if (!func_00141A20(self, a1)) {
        return -1;
    }
    Item8 *it = &self->field_24[a1];
    if (it->f2 < it->f0) goto done;
    {
        short *old_table = it->table;
        it->f0 += 100;
        if (it->f0 > 2000) {
            return -1;
        }
        it->table = (short *)func_100730((long)it->f0 * 2);
        func_117AF8(it->table, old_table, it->f2 * 2);
        for (int i = it->f2; i < it->f0; i++) {
            it->table[i] = -1;
        }
        func_00100630(old_table);
    }
done:
    int ret = it->f2;
    it->f2++;
    return ret;
}

int func_00141470(TacticalAI *self) {
    if (self->field_28) goto ok;
    return -1;
ok:
    return *self->field_28;
}

void func_001414A0(TacticalAI *self) {
    for (int i = 0; i < self->field_E; i++) {
        func_001444F0(&self->field_10[i]);
    }
}

}
