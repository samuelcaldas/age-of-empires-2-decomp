#include "sub_list.h"

extern "C" {
void func_0013F650(void *self);
float func_0013C800(void *item);
float func_0013C810(void *item);
float func_0013C820(void *item);
float func_0013C830(void *item);
float func_0013C840(void *item);
void func_0013C8A0(void *item, float val);
void func_0013C8B0(void *item, float val);
void func_0013C8C0(void *item, float val);
void func_0013E250(void *self, void *item);

void func_0013EEF0(void *self_ptr, int a1, int a2, float f12, float f13, float f14);
int func_0013F180(void *self);
}

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
    char pad_2CC[0x4];
    SubListConItem m_items[10];

    SubListConItem *GetSentinel1() { return &this->m_sentinel1; }
};

extern "C" void func_0013EEF0(void *self_ptr, int a1, int a2, float f12, float f13, float f14) {
    SubListConItem *item;
    ConAI *self = (ConAI *)self_ptr;
    self->m_fieldB4 = a1;
    self->m_fieldB8 = a2;
    self->m_fieldBC = f12;
    self->m_fieldC0 = f13;
    self->m_fieldC4 = f14;

    if (self->m_fieldBC <= 0.0f || self->m_fieldC0 <= 0.0f ||
        self->m_fieldBC >= (float)self->m_fieldB4 ||
        self->m_fieldC0 >= (float)self->m_fieldB8) {
        func_0013F650(self);
        return;
    }

    for (item = *(SubListConItem **)((char *)self + 0x238);
         item != self->GetSentinel1() && item != 0;) {
        func_0013C8A0(item, f12 + func_0013C800(item));
        func_0013C8B0(item, f13 + func_0013C810(item));
        func_0013C8C0(item, f14 + func_0013C820(item));

        if (func_0013C800(item) - func_0013C830(item) / 2.0f < 0.0f ||
            func_0013C810(item) - func_0013C840(item) / 2.0f < 0.0f ||
            func_0013C800(item) + func_0013C830(item) / 2.0f > (float)(self->m_fieldB4 - 1) ||
            func_0013C810(item) + func_0013C840(item) / 2.0f > (float)(self->m_fieldB8 - 1)) {
            self->m_fieldAC--;
            SubListConItem *next = item->m_next;
            item->m_prev->m_next = item->m_next;
            item->m_next->m_prev = item->m_prev;
            func_0013E250(self, item);
            item = next;
            continue;
        }
        item = item->m_next;
    }
}

extern "C" int func_0013F180(void *self) {
    return 0;
}
