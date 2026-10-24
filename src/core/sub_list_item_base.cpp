#include "sub_list.h"

#pragma exceptions off

extern "C" {

struct SubListItemBase {
    void *m_vtable;
    int m_field4;
    int m_field8;
    int m_fieldC;
    float m_field10;
    float m_field14;
    float m_field18;
    float m_field1C;
    float m_field20;
    float m_field24;
    int m_field28;
    char m_name[64];
};

extern char D_4D75D0[];
extern char D_00490C10[];

char* func_0011ABBC(char *dest, const char *src);
char* func_0011B170(char *dest, const char *src, int count);
void __vec_ctor(void *self);

SubListItemBase* func_0013C660(SubListItemBase *self) {
    *(void**)self = D_4D75D0;
    self->m_field4 = -1;
    self->m_field8 = -1;
    self->m_fieldC = -1;
    self->m_field10 = 0.0f;
    self->m_field14 = 0.0f;
    self->m_field18 = 0.0f;
    self->m_field1C = 0.0f;
    self->m_field20 = 0.0f;
    self->m_field24 = 0.0f;
    self->m_field28 = 0;
    func_0011ABBC((char*)self + 0x2C, D_00490C10);
    return self;
}

char* func_0013C6D0(SubListItemBase *self, int a1, int a2, int a3,
                    float f1, float f2, float f3, float f4, float f5, float f6,
                    const char *str) {
    self->m_field4 = a1;
    self->m_field8 = a2;
    self->m_fieldC = a3;
    self->m_field10 = f1;
    self->m_field14 = f2;
    self->m_field18 = f3;
    self->m_field1C = f4;
    self->m_field20 = f5;
    self->m_field24 = f6;
    self->m_field28 = 0;
    return func_0011B170(self->m_name, str, 63);
}

char* func_0013C710(SubListItemBase *self, SubListItemBase *other) {
    self->m_field4 = other->m_field4;
    self->m_field8 = other->m_field8;
    self->m_fieldC = other->m_fieldC;
    self->m_field10 = other->m_field10;
    self->m_field14 = other->m_field14;
    self->m_field18 = other->m_field18;
    self->m_field1C = other->m_field1C;
    self->m_field20 = other->m_field20;
    self->m_field24 = other->m_field24;
    self->m_field28 = other->m_field28;
    return func_0011ABBC(self->m_name, other->m_name);
}

SubListItemBase* func_0013C770(SubListItemBase *self, int flag) {
    if (self) {
        *(void**)self = D_4D75D0;
        if ((short)flag > 0) {
            __vec_ctor(self);
        }
    }
    return self;
}

int func_0013C7C0(SubListItemBase *self) {
    return self->m_field4;
}

int func_0013C7D0(SubListItemBase *self) {
    return self->m_field8;
}

int func_0013C7E0(SubListItemBase *self) {
    return self->m_fieldC;
}

char* func_0013C7F0(SubListItemBase *self) {
    return (char*)self + 0x2C;
}

float func_0013C800(SubListItemBase *self) {
    return self->m_field10;
}

float func_0013C810(SubListItemBase *self) {
    return self->m_field14;
}

float func_0013C820(SubListItemBase *self) {
    return self->m_field18;
}

float func_0013C830(SubListItemBase *self) {
    return self->m_field1C;
}

float func_0013C840(SubListItemBase *self) {
    return self->m_field20;
}

float func_0013C850(SubListItemBase *self) {
    return self->m_field24;
}

int func_0013C860(SubListItemBase *self) {
    return self->m_field28;
}

void func_0013C870(SubListItemBase *self, int val) {
    self->m_field4 = val;
}

void func_0013C880(SubListItemBase *self, int val) {
    self->m_field8 = val;
}

void func_0013C890(SubListItemBase *self, int val) {
    self->m_fieldC = val;
}

void func_0013C8A0(SubListItemBase *self, float val) {
    self->m_field10 = val;
}

void func_0013C8B0(SubListItemBase *self, float val) {
    self->m_field14 = val;
}

void func_0013C8C0(SubListItemBase *self, float val) {
    self->m_field18 = val;
}

void func_0013C8D0(SubListItemBase *self, int val) {
    self->m_field28 = val;
}

}
