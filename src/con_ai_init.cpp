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

struct ConAI {
    void *m_vtable;
    char pad_04[0x1C8];
    SubListConItem m_sentinel1;
    char pad_248[0x4];
    SubListConItem m_sentinel2;
    char pad_2C8[0x8];
    SubListConItem m_items[10];
};

extern char D_4D7650[];
extern char D_00490D98[];
extern char D_00490DA0[];

void *func_001452B0(void *self, const char *name, int id, void *p2, void *p1);
SubListConItem *func_0013DFB0(SubListConItem *self);
SubListConItem *func_0013E0A0(SubListConItem *self, int flag);
void func_001003B0(void *list, void *ctor, void *dtor, int elem_size, int count);
void func_0011ABBC(char *dst, const char *src);

SubListConItem* func_0013E200(ConAI *self) {
    SubListConItem *item = (SubListConItem *)((char *)self + 0x2D0);
    for (int i = 0; i < 10; i++, item = (SubListConItem *)((char *)item + 0x80)) {
        if (item->m_field6C == 0 && item->m_field70 == 0) {
            return item;
        }
    }
    return 0;
}

void func_0013E250(ConAI *self, SubListConItem *item) {
    item->m_field6C = 0;
    item->m_field70 = 0;
}

void *func_0013E260(void *self, void *p1, void *p2) {
    (void)&self;
    func_001452B0(self, D_00490D98, 1002, p2, p1);
    *(void**)self = D_4D7650;
    *(int*)((char*)self + 0xAC) = 0;
    *(int*)((char*)self + 0xB0) = 0;
    *(int*)((char*)self + 0xB4) = -1;
    *(int*)((char*)self + 0xB8) = -1;
    *(float*)((char*)self + 0xBC) = -1.0f;
    *(float*)((char*)self + 0xC0) = -1.0f;
    *(float*)((char*)self + 0xC4) = -1.0f;
    func_0013DFB0((SubListConItem*)((char*)self + 0x1CC));
    func_0013DFB0((SubListConItem*)((char*)self + 0x24C));
    *(int*)((char*)self + 0x2CC) = 0;
    func_001003B0((char*)self + 0x2D0, (void*)func_0013DFB0, (void*)func_0013E0A0, 0x80, 10);
    *(void**)((char*)self + 0x238) = (char*)self + 0x1CC;
    *(void**)((char*)self + 0x23C) = (char*)self + 0x1CC;
    *(void**)((char*)self + 0x2B8) = (char*)self + 0x24C;
    *(void**)((char*)self + 0x2BC) = (char*)self + 0x24C;
    func_0011ABBC((char*)self + 0xC8, D_00490DA0);
    return self;
}

}
