#include "sub_list.h"

struct SubListConItem {
    char pad_00[0x6C];
    SubListConItem *m_next;
    SubListConItem *m_prev;
    int m_field74;
    int m_field78;
    int m_field7C;
};

struct ConAI {
    void *m_vtable;
    char pad_04[0xA8];
    int m_fieldAC;
    int m_fieldB0;
    int m_fieldB4;
    int m_fieldB8;
    float m_fieldBC;
    float m_fieldC0;
    float m_fieldC4;
    char pad_C8[0x104];
    SubListConItem m_sentinel1;
    SubListConItem m_sentinel2;

    SubListConItem *GetSentinel1() { return &this->m_sentinel1; }
    SubListConItem *GetSentinel2() { return &this->m_sentinel2; }
};

extern "C" {
float func_0013C800(void *item);
float func_0013C810(void *item);
void func_0013E250(void *self, void *item);

SubListConItem *func_0013F4B0(ConAI *self, float f12, float f13);
SubListConItem *func_0013F5B0(ConAI *self, float f12, float f13);
void func_0013F650(ConAI *self);
void func_0013F6C0(ConAI *self);
}

SubListConItem *func_0013F4B0(ConAI *self, float f12, float f13) {
    SubListConItem *item;

    for (item = self->m_sentinel1.m_next;
         item != self->GetSentinel1() && item != 0;
         item = item->m_next) {
        if (f12 == func_0013C800(item) && f13 == func_0013C810(item)) {
            return item;
        }
    }

    for (item = self->m_sentinel2.m_next;
         item != self->GetSentinel2() && item != 0;
         item = item->m_next) {
        if (f12 == func_0013C800(item) && f13 == func_0013C810(item)) {
            return item;
        }
    }

    return 0;
}

SubListConItem *func_0013F5B0(ConAI *self, float f12, float f13) {
    SubListConItem *item;

    for (item = self->m_sentinel2.m_next;
         item != self->GetSentinel2() && item != 0;
         item = item->m_next) {
        if (f12 == func_0013C800(item) && f13 == func_0013C810(item)) {
            return item;
        }
    }

    return 0;
}

void func_0013F650(ConAI *self) {
    SubListConItem *item = self->m_sentinel1.m_next;

    while (item != &self->m_sentinel1 && item != 0) {
        SubListConItem *next = item->m_next;
        func_0013E250(self, item);
        item = next;
    }

    self->m_sentinel1.m_next = &self->m_sentinel1;
    self->m_sentinel1.m_prev = &self->m_sentinel1;
    self->m_fieldAC = 0;
}

void func_0013F6C0(ConAI *self) {
    if (self->m_fieldB0 == 0) {
        return;
    }

    SubListConItem *item = self->m_sentinel2.m_next;

    while (item != &self->m_sentinel2 && item != 0) {
        SubListConItem *next = item->m_next;
        func_0013E250(self, item);
        item = next;
    }

    self->m_sentinel2.m_next = &self->m_sentinel2;
    self->m_sentinel2.m_prev = &self->m_sentinel2;
    self->m_fieldB0 = 0;
}
