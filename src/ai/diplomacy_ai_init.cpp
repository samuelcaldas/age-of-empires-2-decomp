#include "sub_list.h"

struct DiplomacyAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
    int m_fieldB0[10];
    int m_fieldD8[10];
    char m_field100[10];
};

extern "C" {

extern char D_4D76C0[];
extern char D_00490DE8[];

void *func_001452B0(void *self, const char *name, int id, void *p2, void *p1);
void func_00145350(void *self, int flag);
void func_00226D90(void *stream, void *dst, int size);
void func_00100670(void *ptr);

DiplomacyAI *func_0013F730(DiplomacyAI *self, void *p1, void *p2);
DiplomacyAI *func_0013F7C0(DiplomacyAI *self, void *p1, void *p2);
DiplomacyAI *func_0013F890(DiplomacyAI *self, int flag);
void func_0013F900(DiplomacyAI *self, int val);

DiplomacyAI *func_0013F730(DiplomacyAI *self, void *p1, void *p2) {
    func_001452B0(self, D_00490DE8, 1003, p2, p1);
    self->m_vtable = D_4D76C0;
    self->m_fieldAC = 0;

    for (int i = 0; i <= 9; i++) {
        self->m_fieldB0[i] = 49;
        self->m_fieldD8[i] = 49;
        self->m_field100[i] = 1;
    }
    return self;
}

DiplomacyAI *func_0013F7C0(DiplomacyAI *self, void *p1, void *p2) {
    (void)&self;
    func_001452B0(self, D_00490DE8, 1003, p1, 0);
    self->m_vtable = D_4D76C0;
    self->m_fieldAC = 0;

    for (int i = 0; i <= 9; i++) {
        func_00226D90(p2, &self->m_fieldB0[i], 4);
        func_00226D90(p2, &self->m_fieldD8[i], 4);
        func_00226D90(p2, &self->m_field100[i], 1);
    }
    return self;
}

DiplomacyAI *func_0013F890(DiplomacyAI *self, int flag) {
    if (self != 0) {
        self->m_vtable = D_4D76C0;
        self->m_fieldAC = 0;
        func_00145350(self, 0);
        short f = (short)flag;
        if (f > 0) {
            func_00100670(self);
        }
    }
    return self;
}

void func_0013F900(DiplomacyAI *self, int val) {
    self->m_fieldAC = val;
}

}
