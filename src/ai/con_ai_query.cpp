#include "sub_list.h"

extern "C" {
int func_0013E110(void *item, int val);
void func_0013E190(void *item, int val);
void func_0013E1A0(void *item, int val);
void func_0013E1C0(void *item);
int func_0013C7E0(void *item);
void func_0013C890(void *item, int val);
float func_0013C800(void *item);
float func_0013C810(void *item);
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
    char pad_04[0x1C8];
    SubListConItem m_sentinel1;

    SubListConItem *GetSentinel1() { return &this->m_sentinel1; }
};

extern "C" void func_0013F190(ConAI *self, int a1, int a2) {
    SubListConItem *item;

    for (item = *(SubListConItem **)((char *)self + 0x238);
         item != self->GetSentinel1() && item != 0;
         item = item->m_next) {
        if (func_0013E110(item, a1)) {
            func_0013E1A0(item, a2);
            return;
        }
    }
}

extern "C" int func_0013F220(ConAI *self, int a1, int a2) {
    SubListConItem *item;

    for (item = *(SubListConItem **)((char *)self + 0x238);
         item != self->GetSentinel1() && item != 0;
         item = item->m_next) {
        if (func_0013E110(item, a1)) {
            func_0013E190(item, 0);
            func_0013E1A0(item, 0);
            int res = func_0013C7E0(item);
            func_0013C890(item, -1);
            if (a2 == 1) {
                func_0013E1C0(item);
            }
            return res;
        }
    }
    return -1;
}

extern "C" int func_0013F2F0(ConAI *self, float f12, float f13, int a1) {
    SubListConItem *item;

    for (item = *(SubListConItem **)((char *)self + 0x238);
         item != self->GetSentinel1() && item != 0;
         item = item->m_next) {
        if (f12 == func_0013C800(item) && f13 == func_0013C810(item)) {
            func_0013E190(item, 0);
            func_0013E1A0(item, 0);
            int res = func_0013C7E0(item);
            func_0013C890(item, -1);
            if (a1 == 1) {
                func_0013E1C0(item);
            }
            return res;
        }
    }
    return -1;
}
