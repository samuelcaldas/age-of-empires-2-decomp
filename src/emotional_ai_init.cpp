#include "sub_list.h"

struct EmotionalAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
    int m_fieldB0[6];
    char m_buf1[30];
    char m_buf2[30];
    char m_buf3[30];
    char m_buf4[30];
    char m_buf5[30];
    char m_buf6[30];
};

extern "C" {

extern char D_4D7710[];
extern char D_00490DF8[];
extern char D_00490E08[];
extern char D_00490E18[];
extern char D_00490E28[];
extern char D_00490E38[];
extern char D_00490E48[];
extern char D_00490E50[];

void *func_001452B0(void *self, const char *name, int id, void *p2, void *p1);
void func_00145350(void *self, int flag);
void func_00226D90(void *stream, void *dst, int size);
void func_00100670(void *ptr);
char *func_0011ABBC(char *dst, const char *src);

EmotionalAI *func_00140370(EmotionalAI *self, void *p1, void *p2) {
    (void)&self;
    func_001452B0(self, D_00490DF8, 1004, p2, p1);
    self->m_vtable = D_4D7710;
    self->m_fieldAC = 0;

    for (int i = 0; i < 6; i++) {
        self->m_fieldB0[i] = 49;
    }
    func_0011ABBC(self->m_buf1, D_00490E08);
    func_0011ABBC(self->m_buf2, D_00490E18);
    func_0011ABBC(self->m_buf3, D_00490E28);
    func_0011ABBC(self->m_buf4, D_00490E38);
    func_0011ABBC(self->m_buf5, D_00490E48);
    func_0011ABBC(self->m_buf6, D_00490E50);
    return self;
}

EmotionalAI *func_00140470(EmotionalAI *self, void *p1, void *p2) {
    (void)&self;
    func_001452B0(self, D_00490DF8, 1004, p1, 0);
    self->m_vtable = D_4D7710;
    self->m_fieldAC = 0;

    for (int i = 0; i < 6; i++) {
        func_00226D90(p2, &self->m_fieldB0[i], 4);
    }
    func_0011ABBC(self->m_buf1, D_00490E08);
    func_0011ABBC(self->m_buf2, D_00490E18);
    func_0011ABBC(self->m_buf3, D_00490E28);
    func_0011ABBC(self->m_buf4, D_00490E38);
    func_0011ABBC(self->m_buf5, D_00490E48);
    func_0011ABBC(self->m_buf6, D_00490E50);
    return self;
}

EmotionalAI *func_00140580(EmotionalAI *self, int flag) {
    if (self != 0) {
        self->m_vtable = D_4D7710;
        self->m_fieldAC = 0;
        func_00145350(self, 0);
        short f = (short)flag;
        if (f > 0) {
            func_00100670(self);
        }
    }
    return self;
}

void func_001405F0(EmotionalAI *self, int val) {
    self->m_fieldAC = val;
}
}
