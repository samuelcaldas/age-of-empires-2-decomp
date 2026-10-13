#include "sub_list.h"

extern "C" {
void func_0013EEF0(void *self, int a1, int a2, float f12, float f13, float f14);
void func_0013F650(void *self);
void func_0013F6C0(void *self);
void func_0011B170(char *dst, const char *src, int n);
int func_0011AA78(const char *s1, const char *s2);
void func_0011ABBC(char *dst, const char *src);
void func_001454C0(void *self, const char *fmt, ...);

extern const char D_00490DA8[];
extern const char D_00490DB0[];
extern const char D_00490DC0[];
}

struct ConAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
    char pad_B0[0x18];
    char m_name[64];

    int LoadPlan(const char *name, int a2, int a3, float f12, float f13, float f14);
};

extern "C" int func_0013EE20(ConAI *self, const char *name, int a2, int a3, float f12, float f13, float f14) {
    func_0013EEF0(self, a2, a3, f12, f13, f14);
    if (self->m_fieldAC > 0) {
        func_0013F650(self);
    }
    func_0013F6C0(self);
    func_0011B170(self->m_name, name, 0x3F);
    if (func_0011AA78(self->m_name, D_00490DA8) == 0 || self->m_name[0] == 0) {
        if (self->m_name[0] == 0) {
            func_0011ABBC(self->m_name, D_00490DB0);
        }
        func_001454C0(self, D_00490DC0);
        return 1;
    }
    return 1;
}
