#include "sub_list.h"

extern "C" {

struct BuildAIBuffer {
    void *m_data;
    int m_size;
    int m_cap;
    int m_flags;
};

extern char D_4D75F0[];
extern char D_00490C18[];
extern char D_00490C24[];
extern char D_00490C28[];

void *func_001452B0(void *self, const char *name, int id, void *p2, void *p1);
void *func_0013C8E0(void *self);
void *func_0013CA40(void *self, int flag);
void func_001003B0(void *list, void *ctor, void *dtor, int elem_size, int count);
void func_0011ABBC(char *dst, const char *src);
void func_00100630(void *ptr);
void func_00100670(void *ptr);

void *func_0013CC60(void *self, void *p1, void *p2) {
    (void)&self;
    func_001452B0(self, D_00490C18, 1001, p2, p1);
    *(void**)self = D_4D75F0;
    func_0013C8E0((char*)self + 0xAC);
    *(int*)((char*)self + 0x160) = 0;
    *(int*)((char*)self + 0x568) = 0;
    *(int*)((char*)self + 0x56C) = 0;
    *(int*)((char*)self + 0x570) = 0;
    *(int*)((char*)self + 0x574) = 0;
    *(int*)((char*)self + 0x578) = 0;
    func_001003B0((char*)self + 0x57C, (void*)func_0013C8E0, (void*)func_0013CA40, 0xB4, 50);
    *(void**)((char*)self + 0x118) = (char*)self + 0xAC;
    *(void**)((char*)self + 0x11C) = (char*)self + 0xAC;
    func_0011ABBC((char*)self + 0x164, D_00490C24);
    func_0011ABBC((char*)self + 0x265, D_00490C28);
    func_0011ABBC((char*)self + 0x366, D_00490C28);
    func_0011ABBC((char*)self + 0x467, D_00490C28);
    return self;
}

BuildAIBuffer *func_0013CD70(BuildAIBuffer *self, int flag) {
    if (self != 0) {
        if (self->m_data != 0) {
            func_00100630(self->m_data);
            self->m_data = 0;
        }
        self->m_size = 0;
        short f = (short)flag;
        self->m_cap = 0;
        self->m_flags = 0;
        if (f > 0) {
            func_00100670(self);
        }
    }
    return self;
}

}
