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
    char pad_04[0xC4];
    char m_name[64];
    char pad_108[0xC4];
    SubListConItem m_sentinel1;
    char pad_248[0x4];
    SubListConItem m_sentinel2;
    char pad_2C8[0x8];
    SubListConItem m_items[10];
};

extern char D_4D7650[];
extern char D_00490D98[];

void *func_001452B0(void *self, const char *name, int id, void *p2, void *p1);
SubListConItem *func_0013DFB0(SubListConItem *self);
SubListConItem *func_0013E0A0(SubListConItem *self, int flag);
void func_001003B0(void *list, void *ctor, void *dtor, int elem_size, int count);
void func_00226D90(void *stream, void *dst, int size);
SubListConItem *func_0013E200(ConAI *self);

void func_0013E000(SubListConItem *self,
                   float f12, float f13, float f14,
                   float f15, float f16, float f17,
                   int a1, const char *str);
void func_0013E190(SubListConItem *self, int val);
void func_0013E1A0(SubListConItem *self, int val);
void func_0013E1F0(SubListConItem *self, int val);
void func_0013C880(void *item, int val);
void func_0013C890(void *item, int val);
void func_0013C8D0(void *item, int val);

void func_0013F650(void *self);
void func_0013F6C0(void *self);
void func_00100340(void *list, void *dtor, int elem_size, int count);
void func_00145350(void *self, int flag);
void func_00100670(void *ptr);

void *func_0013E370(ConAI *self, void *p1, void *stream) {
    (void)&self;
    func_001452B0(self, D_00490D98, 1002, p1, 0);
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

    func_00226D90(stream, (char*)self + 0xAC, 4);

    int len;
    func_00226D90(stream, &len, 4);
    func_00226D90(stream, (char*)self + 0xC8, len);
    self->m_name[len] = 0;

    func_00226D90(stream, (char*)self + 0xBC, 4);
    func_00226D90(stream, (char*)self + 0xC0, 4);
    func_00226D90(stream, (char*)self + 0xC4, 4);
    func_00226D90(stream, (char*)self + 0xB4, 4);
    func_00226D90(stream, (char*)self + 0xB8, 4);

    char name_buf1[272];
    int v1_a1;
    int v1_c880;
    int v1_c890;
    float v1_f12;
    float v1_f13;
    float v1_f14;
    float v1_f15;
    float v1_f16;
    float v1_f17;
    int v1_c8d0;
    int v1_e190;
    int v1_e1a0;
    int v1_e1f0;

    char name_buf2[260];
    int v2_a1;
    int v2_c880;
    int v2_c890;
    float v2_f12;
    float v2_f13;
    float v2_f14;
    float v2_f15;
    float v2_f16;
    float v2_f17;
    int v2_c8d0;
    int v2_e190;
    int v2_e1a0;
    int v2_e1f0;

    for (int i = 0; i < *(int*)((char*)self + 0xAC); i++) {
        func_00226D90(stream, &len, 4);
        func_00226D90(stream, name_buf1, len);
        name_buf1[len] = 0;
        func_00226D90(stream, &v1_a1, 4);
        func_00226D90(stream, &v1_c880, 4);
        func_00226D90(stream, &v1_c890, 4);
        func_00226D90(stream, &v1_f12, 4);
        func_00226D90(stream, &v1_f13, 4);
        func_00226D90(stream, &v1_f14, 4);
        func_00226D90(stream, &v1_f15, 4);
        func_00226D90(stream, &v1_f16, 4);
        func_00226D90(stream, &v1_f17, 4);
        func_00226D90(stream, &v1_c8d0, 4);
        func_00226D90(stream, &v1_e190, 4);
        func_00226D90(stream, &v1_e1a0, 4);
        func_00226D90(stream, &v1_e1f0, 4);

        SubListConItem *item = func_0013E200(self);
        if (item != 0) {
            func_0013E000(item, v1_f12, v1_f13, v1_f14, v1_f15, v1_f16, v1_f17, v1_a1, name_buf1);
        }
        func_0013E190(item, v1_e190);
        func_0013E1A0(item, v1_e1a0);
        func_0013E1F0(item, v1_e1f0);
        func_0013C880(item, v1_c880);
        func_0013C890(item, v1_c890);
        func_0013C8D0(item, v1_c8d0);
        item->m_field6C = (int)((char*)self + 0x1CC);
        item->m_field70 = *(int*)((char*)self + 0x23C);
        *(int*)(item->m_field70 + 0x6C) = (int)item;
        *(int*)((char*)self + 0x23C) = (int)item;
    }

    func_00226D90(stream, (char*)self + 0xB0, 4);

    for (int j = 0; j < *(int*)((char*)self + 0xB0); j++) {
        func_00226D90(stream, &len, 4);
        func_00226D90(stream, name_buf2, len);
        name_buf2[len] = 0;
        func_00226D90(stream, &v2_a1, 4);
        func_00226D90(stream, &v2_c880, 4);
        func_00226D90(stream, &v2_c890, 4);
        func_00226D90(stream, &v2_f12, 4);
        func_00226D90(stream, &v2_f13, 4);
        func_00226D90(stream, &v2_f14, 4);
        func_00226D90(stream, &v2_f15, 4);
        func_00226D90(stream, &v2_f16, 4);
        func_00226D90(stream, &v2_f17, 4);
        func_00226D90(stream, &v2_c8d0, 4);
        func_00226D90(stream, &v2_e190, 4);
        func_00226D90(stream, &v2_e1a0, 4);
        func_00226D90(stream, &v2_e1f0, 4);

        SubListConItem *item = func_0013E200(self);
        if (item != 0) {
            func_0013E000(item, v2_f12, v2_f13, v2_f14, v2_f15, v2_f16, v2_f17, v2_a1, name_buf2);
        }
        func_0013E190(item, v2_e190);
        func_0013E1A0(item, v2_e1a0);
        func_0013E1F0(item, v2_e1f0);
        func_0013C880(item, v2_c880);
        func_0013C890(item, v2_c890);
        func_0013C8D0(item, v2_c8d0);
        item->m_field6C = (int)((char*)self + 0x24C);
        item->m_field70 = *(int*)((char*)self + 0x2BC);
        *(int*)(item->m_field70 + 0x6C) = (int)item;
        *(int*)((char*)self + 0x2BC) = (int)item;
    }

    return self;
}

void *func_0013E8D0(ConAI *self, int flag) {
    if (self != 0) {
        self->m_vtable = D_4D7650;
        if (*(int*)((char*)self + 0xAC) > 0) {
            func_0013F650(self);
        }
        func_0013F6C0(self);
        func_00100340((SubListConItem*)((char*)self + 0x2D0), (void*)func_0013E0A0, 0x80, 10);
        func_0013E0A0((SubListConItem*)((char*)self + 0x24C), -1);
        func_0013E0A0((SubListConItem*)((char*)self + 0x1CC), -1);
        func_00145350(self, 0);
        if ((short)flag > 0) {
            func_00100670(self);
        }
    }
    return self;
}

}
