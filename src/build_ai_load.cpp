#include "sub_list.h"

extern "C" {

extern char D_4D75F0[];
extern char D_00490C18[];
extern float D_004E2F24;
extern float D_004E2AD0;
extern float D_004E2AD4;

void *func_001452B0(void *self, const char *name, int id, void *p2, void *p1);
void *func_0013C8E0(void *self);
void *func_0013CA40(void *self, int flag);
void func_001003B0(void *list, void *ctor, void *dtor, int elem_size, int count);
void func_00226D90(void *stream, void *dst, int size);
void *func_0013DAC0(void *self, int param);

void func_0013CB70(void *item, int val);
void func_0013CB60(void *item, int val);
void func_0013CB80(void *item, int val);
void func_0013C8D0(void *item, int val);
void func_0013C880(void *item, int val);
void func_0013C8A0(void *item, float val);
void func_0013C8B0(void *item, float val);
void func_0013C8C0(void *item, float val);
void func_0013CBF0(void *item, int val);
void func_0013CC10(void *item, int val);
void func_0013CC30(void *item, int val);
void func_0013CC50(void *item, unsigned char val);

void func_0013DEC0(void *self);
void func_00100340(void *list, void *dtor, int elem_size, int count);
void func_00100630(void *ptr);
void func_00145350(void *self, int flag);
void func_00100670(void *ptr);
struct SubListBuildItem;
struct BuildAIBuffer {
    void *m_data;
    int m_size;
    int m_cap;
    int m_flags;
};

struct BuildAI {
    void *m_vtable;
    char m_pad4[0xA8];
    char m_buildItem[0xB4];
    int m_field160;
    char m_buf1[257];
    char m_buf2[257];
    char m_buf3[257];
    char m_buf4[257];
    int m_field568;
    BuildAIBuffer m_buffer;
    char m_items[50 * 0xB4];
};

void *func_0013CDE0(BuildAI *self, void *p1, void *stream) {
    (void)&self;
    func_001452B0(self, D_00490C18, 1001, p1, 0);
    *(void**)self = D_4D75F0;
    func_0013C8E0((char*)self + 0xAC);
    self->m_field160 = 0;
    self->m_field568 = 0;
    self->m_buffer.m_data = 0;
    self->m_buffer.m_size = 0;
    self->m_buffer.m_cap = 0;
    self->m_buffer.m_flags = 0;
    func_001003B0((char*)self + 0x57C, (void*)func_0013C8E0, (void*)func_0013CA40, 0xB4, 50);
    *(void**)((char*)self + 0x118) = (char*)self + 0xAC;
    *(void**)((char*)self + 0x11C) = (char*)self + 0xAC;

    func_00226D90(stream, &self->m_field160, 4);

    int len;
    func_00226D90(stream, &len, 4);
    func_00226D90(stream, self->m_buf1, len);
    self->m_buf1[len] = 0;

    func_00226D90(stream, &len, 4);
    func_00226D90(stream, self->m_buf2, len);
    self->m_buf2[len] = 0;

    func_00226D90(stream, &len, 4);
    func_00226D90(stream, self->m_buf3, len);
    self->m_buf3[len] = 0;

    func_00226D90(stream, &len, 4);
    func_00226D90(stream, self->m_buf4, len);
    self->m_buf4[len] = 0;

    func_00226D90(stream, &self->m_field568, 4);

    int count;
    int i = 0;
    if (D_004E2F24 > D_004E2AD0) {
        func_00226D90(stream, &count, 4);
        i = 0;
    }
    for (; i < count; i++) {
        func_00226D90(stream, &len, 4);
        char name_buf[264];
        func_00226D90(stream, name_buf, len);
        name_buf[len] = 0;

        int f160;
        int f164;
        int f168;
        float f16C;
        float f170;
        float f174;
        int f178;
        int f17C;
        int f180;
        int f184;
        int f188;
        int f18C;
        int f190;
        int f194;
        int f198;
        int f19C;
        int f1A0;
        int f1A4;
        int f1A8;
        int f1AC;
        int f1B0;
        int f1B4;
        int f1B8;
        unsigned char pad_1BC[3];
        unsigned char f1BF;

        func_00226D90(stream, &f160, 4);
        func_00226D90(stream, &f164, 4);
        func_00226D90(stream, &f168, 4);
        func_00226D90(stream, &f16C, 4);
        func_00226D90(stream, &f170, 4);
        func_00226D90(stream, &f174, 4);
        func_00226D90(stream, &f178, 4);
        func_00226D90(stream, &f17C, 4);
        func_00226D90(stream, &f180, 4);
        func_00226D90(stream, &f184, 4);
        func_00226D90(stream, &f188, 4);
        func_00226D90(stream, &f18C, 4);
        func_00226D90(stream, &f190, 4);
        func_00226D90(stream, &f194, 4);
        func_00226D90(stream, &f198, 4);
        func_00226D90(stream, &f19C, 4);
        func_00226D90(stream, &f1A0, 4);
        func_00226D90(stream, &f1A4, 4);
        func_00226D90(stream, &f1A8, 4);
        func_00226D90(stream, &f1AC, 4);
        f1B0 = -1;
        func_00226D90(stream, &f1B0, 4);
            func_00226D90(stream, &f1B4, 4);
            func_00226D90(stream, &f1BF, 1);

            if (D_004E2F24 > D_004E2AD4) {
                func_00226D90(stream, &f1B8, 4);
            }

            if (f190 == 0) {
                void *item = func_0013DAC0(self, 0);
                if (item != 0) {
                    func_0013CB70(item, f190);
                    func_0013CB60(item, f18C);
                    func_0013CB80(item, f194);
                    func_0013C8D0(item, f184);
                    func_0013C880(item, f164);
                    func_0013C8A0(item, f16C);
                    func_0013C8B0(item, f170);
                    func_0013C8C0(item, f174);
                    func_0013CBF0(item, f1AC);
                    func_0013CC10(item, f1B0);
                    func_0013CC30(item, f1B4);
                    func_0013CC50(item, f1BF);
                    *(int*)((char*)item + 0xAC) = f1B8;
                    *(void**)((char*)item + 0x6C) = (char*)self + 0xAC;
                    *(void**)((char*)item + 0x70) = *(void**)((char*)self + 0x11C);
                    *(void**)(*(char**)((char*)item + 0x70) + 0x6C) = item;
                    *(void**)((char*)self + 0x11C) = item;
                }
            }
        }

    return self;
}

void *func_0013D2B0(BuildAI *self, int flag) {
    if (self != 0) {
        self->m_vtable = D_4D75F0;
        func_0013DEC0(self);
        func_00100340((SubListBuildItem*)((char*)self + 0x57C), (void*)func_0013CA40, 0xB4, 50);
        if (&self->m_buffer != 0) {
            if (self->m_buffer.m_data != 0) {
                func_00100630(self->m_buffer.m_data);
                self->m_buffer.m_data = 0;
            }
            self->m_buffer.m_size = 0;
            self->m_buffer.m_cap = 0;
            self->m_buffer.m_flags = 0;
        }
        func_0013CA40(self->m_buildItem, -1);
        func_00145350(self, 0);
        if ((short)flag > 0) {
            func_00100670(self);
        }
    }
    return self;
}

}
