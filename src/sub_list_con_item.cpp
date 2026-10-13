#include "sub_list.h"

extern "C" {

struct SubListItemBase {
    void *m_vtable;
    int m_field4;
    int m_field8;
    int m_fieldC;
    float m_x;
    float m_y;
    float m_field18;
    float m_field1C;
    float m_field20;
    float m_field24;
    int m_field28;
    char m_name[64];
};

struct SubListConItem : public SubListItemBase {
    int m_field6C;
    int m_field70;
    int m_field74;
    int m_field78;
    int m_field7C;
};

extern char D_4D7640[];

SubListItemBase* func_0013C660(SubListItemBase *self);
void func_0013C6D0(SubListItemBase *self, int a1, int a2, int a3,
                   float f1, float f2, float f3, float f4, float f5, float f6,
                   const char *str);
void func_0013C710(SubListItemBase *self, SubListItemBase *src);
SubListItemBase* func_0013C770(SubListItemBase *self, int flag);
void __vec_ctor(void *ptr);

SubListConItem* func_0013DFB0(SubListConItem *self) {
    func_0013C660((SubListItemBase*)self);
    *(void**)self = D_4D7640;
    self->m_field6C = 0;
    self->m_field70 = 0;
    self->m_field74 = 0;
    self->m_field78 = 0;
    self->m_field7C = 0;
    return self;
}

void func_0013E000(SubListConItem *self, int a1, const char *str,
                   float f12, float f13, float f14,
                   float f15, float f16, float f17) {
    func_0013C6D0((SubListItemBase*)self, a1, -1, -1,
                  f12, f13, f14, f15, f16, f17, str);
    self->m_field74 = 0;
    self->m_field78 = 0;
    self->m_field7C = 0;
    self->m_field6C = 0;
    self->m_field70 = 0;
}

void func_0013E050(SubListConItem *self, SubListConItem *src) {
    func_0013C710((SubListItemBase*)self, (SubListItemBase*)src);
    self->m_field74 = src->m_field74;
    self->m_field78 = src->m_field78;
    self->m_field7C = src->m_field7C;
    self->m_field6C = 0;
    self->m_field70 = 0;
}

SubListConItem* func_0013E0A0(SubListConItem *self, int flag) {
    if (self) {
        *(void**)self = D_4D7640;
        self->m_field6C = 0;
        self->m_field70 = 0;
        func_0013C770((SubListItemBase*)self, 0);
        if ((short)flag > 0) {
            __vec_ctor(self);
        }
    }
    return self;
}

int func_0013E110(SubListConItem *self, SubListConItem *other) {
    if (self->m_x == other->m_x && self->m_y == other->m_y) {
        return 1;
    }
    return 0;
}

int func_0013E160(SubListConItem *self) {
    return self->m_field74;
}

int func_0013E170(SubListConItem *self) {
    return self->m_field78;
}

int func_0013E180(SubListConItem *self) {
    return self->m_field7C;
}

void func_0013E190(SubListConItem *self, int val) {
    self->m_field74 = val;
}

void func_0013E1A0(SubListConItem *self, int val) {
    self->m_field78 = val;
}

void func_0013E1B0(SubListConItem *self) {
    self->m_field7C++;
}

void func_0013E1C0(SubListConItem *self) {
    self->m_field7C--;
    if (self->m_field7C < 0) {
        self->m_field7C = 0;
    }
}

void func_0013E1F0(SubListConItem *self, int val) {
    self->m_field7C = val;
}

}
