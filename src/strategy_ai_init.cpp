#include "sub_list.h"

struct SlotEntry {
    short m_id;
    short m_status;
    int m_val1;
    int m_val2;
    int m_val3;
    int m_val4;
};

struct SlotTable {
    short m_header1;
    short m_header2;
    char m_flags[4];
    SlotEntry m_slots[16];
};

struct StrategyAI {
    void *m_vtable;
};

struct TacAI {
    void *m_vtable;
};

struct MatrixTable {
    int m_count;
    int m_grid[8][10];
};

extern "C" {

extern char D_4D78B0[];
extern char D_4D7900[];
extern char D_490FF8[];
extern char D_491008[];

void *func_001452B0(void *self, const char *name, int id, void *p2, void *p1);
void func_00145350(void *self, int flag);
void func_00100670(void *ptr);

void *func_001456CC(void *self) {
    return self;
}

void *func_001456E0(void *self, int flag) {
    if (self != 0) {
        short f = (short)flag;
        if (f > 0) {
            func_00100670(self);
        }
    }
    return self;
}

void func_00145730(SlotTable *self) {
    short val = -1;
    self->m_flags[0] = 0;
    self->m_flags[1] = 0;
    self->m_header1 = val;
    self->m_header2 = val;
    self->m_flags[2] = 0;
    self->m_flags[3] = 0;

    for (int i = 0; i < 16; i++) {
        self->m_slots[i].m_id = 0;
        self->m_slots[i].m_status = val;
        self->m_slots[i].m_val1 = 0;
        self->m_slots[i].m_val2 = 0;
        self->m_slots[i].m_val3 = 0;
        self->m_slots[i].m_val4 = 0;
    }
}

StrategyAI *func_001457A0(StrategyAI *self, void *p1, void *p2) {
    StrategyAI *s = self;
    func_001452B0(s, D_490FF8, 1008, p2, p1);
    s->m_vtable = D_4D78B0;
    return s;
}

StrategyAI *func_001457F0(StrategyAI *self, int flag) {
    if (self != 0) {
        self->m_vtable = D_4D78B0;
        func_00145350(self, 0);
        short f = (short)flag;
        if (f > 0) {
            func_00100670(self);
        }
    }
    return self;
}

TacAI *func_00145850(TacAI *self, void *p1, void *p2) {
    TacAI *s = self;
    func_001452B0(s, D_491008, 1009, p2, p1);
    s->m_vtable = D_4D7900;
    return s;
}

TacAI *func_001458A0(TacAI *self, int flag) {
    if (self != 0) {
        self->m_vtable = D_4D7900;
        func_00145350(self, 0);
        short f = (short)flag;
        if (f > 0) {
            func_00100670(self);
        }
    }
    return self;
}

MatrixTable *func_00145900(MatrixTable *self, int count) {
    self->m_count = count;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 10; j++) {
            self->m_grid[i][j] = -1;
        }
    }
    return self;
}

}
