#include "sub_list.h"

struct TradeAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
};

extern "C" {

extern char D_4D7950[];
extern char D_491010[];
extern char D_512C00[];
extern char D_514500[];

void *func_001452B0(void *self, const char *name, int id, void *p2, void *p1);
void func_00145350(void *self, int flag);
void func_00100670(void *ptr);
int func_001FC8C0(void *bitset, int max_count, void *val);
void *func_00117CAC(void *dst, int val, int size);

TradeAI *func_00145BC0(TradeAI *self, void *p1, void *p2) {
    TradeAI *s = self;
    func_001452B0(s, D_491010, 1010, p2, p1);
    s->m_vtable = D_4D7950;
    s->m_fieldAC = 0;
    return s;
}

TradeAI *func_00145C10(TradeAI *self, void *p1) {
    TradeAI *s = self;
    func_001452B0(s, D_491010, 1010, p1, 0);
    s->m_vtable = D_4D7950;
    s->m_fieldAC = 0;
    return s;
}

TradeAI *func_00145C60(TradeAI *self, int flag) {
    if (self != 0) {
        self->m_vtable = D_4D7950;
        self->m_fieldAC = 0;
        func_00145350(self, 0);
        short f = (short)flag;
        if (f > 0) {
            func_00100670(self);
        }
    }
    return self;
}

void func_00145CD0(TradeAI *self, int val) {
    self->m_fieldAC = val;
}

int func_00145CE0(TradeAI *self) {
    return 1;
}

void *func_00145CF0(void *val) {
    int idx = func_001FC8C0(D_514500, 100, val);
    if (idx >= 0) {
        return (void *)(D_512C00 + idx * 8);
    }
    return 0;
}

void func_00145D40(void *ptr) {
    if (ptr == 0) {
        return;
    }
    for (int i = 0; i < 800; i++) {
        if (&D_512C00[i * 8] == (char *)ptr) {
            unsigned char mask = 1 << (i % 8);
            unsigned char *byte_ptr = (unsigned char *)&D_514500[i / 8];
            if (*byte_ptr & mask) {
                *byte_ptr &= ~mask;
                return;
            }
        }
    }
}

void func_00145DD0() {
    func_00117CAC(D_512C00, 0, 0x1900);
    for (int i = 0; i < 100; i++) {
        D_514500[i] = 0;
    }
}

}
