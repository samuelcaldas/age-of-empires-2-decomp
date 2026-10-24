#include "sub_list.h"

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

struct SubListBuildItem : public SubListItemBase {
    int m_field6C;
    int m_field70;
    int m_field74;
    int m_field78;
    int m_field7C;
    int m_field80;
    int m_field84;
    int m_targets[3];
    int m_field94;
    int m_field98;
    int m_field9C;
    int m_fieldA0;
    int m_fieldA4;
    int m_fieldA8;
    int pad_AC;
    unsigned char m_fieldB0;
};

extern char D_4D75E0[];

SubListItemBase* func_0013C660(SubListItemBase *self);
void func_0013C6D0(SubListItemBase *self, int a1, int a2, int a3,
                   float f1, float f2, float f3, float f4, float f5, float f6,
                   const char *str);
SubListItemBase* func_0013C770(SubListItemBase *self, int flag);
void __vec_ctor(void *self);

SubListBuildItem* func_0013C8E0(SubListBuildItem *self) {
    func_0013C660((SubListItemBase*)self);
    *(void**)self = D_4D75E0;
    self->m_field6C = 0;
    self->m_field70 = 0;
    self->m_field74 = -1;
    self->m_field78 = 0;
    self->m_field7C = 0;
    self->m_field80 = 0;
    self->m_field84 = -1;
    self->m_targets[0] = -1;
    self->m_field94 = 0;
    self->m_field98 = -1;
    self->m_field9C = 0;
    self->m_fieldA0 = 0;
    self->m_fieldA4 = 0;
    self->m_fieldA8 = 0;
    self->m_fieldB0 = 0;
    self->m_targets[1] = -1;
    self->m_targets[2] = -1;
    return self;
}

void func_0013C960(SubListBuildItem *self, int p74, int a1, int a3,
                   int p78, int p7C, int p84, const char *str,
                   float f12, float f13, float f14,
                   int p88, int p8C, int p90, int pA8) {
    float m = -1.0f; float n = -1.0f; func_0013C6D0((SubListItemBase*)self, a1, -1, a3, -1.0f, -1.0f, -1.0f, f12, f13, f14, str);
    self->m_field74 = p74;
    self->m_field78 = p78;
    self->m_field7C = p7C;
    self->m_fieldA0 = 0;
    self->m_fieldA4 = 0;
    self->m_field80 = 0;
    self->m_field84 = p84;
    self->m_targets[0] = p88;
    self->m_fieldA8 = pA8;
    self->m_field6C = 0;
    self->m_field70 = 0;
    self->m_field94 = 0;
    self->m_field98 = -1;
    self->m_field9C = 0;
    self->m_fieldB0 = 0;
    self->m_targets[1] = p8C;
    self->m_targets[2] = p90;
}

SubListBuildItem* func_0013CA40(SubListBuildItem *self, int flag) {
    if (self) {
        *(void**)self = D_4D75E0;
        self->m_field6C = 0;
        self->m_field70 = 0;
        func_0013C770((SubListItemBase*)self, 0);
        if ((short)flag > 0) {
            __vec_ctor(self);
        }
    }
    return self;
}

int func_0013CAB0(SubListBuildItem *self) {
    return self->m_field74;
}

int func_0013CAC0(SubListBuildItem *self) {
    return self->m_fieldA0;
}

int func_0013CAD0(SubListBuildItem *self) {
    return self->m_fieldA4;
}

int func_0013CAE0(SubListBuildItem *self) {
    return self->m_field80;
}

int func_0013CAF0(SubListBuildItem *self) {
    return self->m_field84;
}

int func_0013CB00(SubListBuildItem *self) {
    return self->m_targets[0];
}

int func_0013CB10(SubListBuildItem *self, int idx) {
    if (idx <= 0 || idx > 2) {
        return -1;
    }
    return self->m_targets[idx];
}

int func_0013CB50(SubListBuildItem *self) {
    return self->m_fieldA8;
}

void func_0013CB60(SubListBuildItem *self, int val) {
    self->m_fieldA0 = val;
}

void func_0013CB70(SubListBuildItem *self, int val) {
    self->m_fieldA4 = val;
}

void func_0013CB80(SubListBuildItem *self, int val) {
    self->m_field80 = val;
}

void func_0013CB90(SubListBuildItem *self) {
    self->m_field80++;
}

void func_0013CBA0(SubListBuildItem *self) {
    self->m_field80--;
    if (self->m_field80 < 0) {
        self->m_field80 = 0;
    }
}

int func_0013CBD0(SubListBuildItem *self) {
    return self->m_field94;
}

void func_0013CBE0(SubListBuildItem *self) {
    self->m_field94++;
}

void func_0013CBF0(SubListBuildItem *self, int val) {
    self->m_field94 = val;
}

int func_0013CC00(SubListBuildItem *self) {
    return self->m_field98;
}

void func_0013CC10(SubListBuildItem *self, int val) {
    self->m_field98 = val;
}

int func_0013CC20(SubListBuildItem *self) {
    return self->m_field9C;
}

void func_0013CC30(SubListBuildItem *self, int val) {
    self->m_field9C = val;
}

unsigned char func_0013CC40(SubListBuildItem *self) {
    return self->m_fieldB0;
}

void func_0013CC50(SubListBuildItem *self, unsigned char val) {
    self->m_fieldB0 = val;
}

}
