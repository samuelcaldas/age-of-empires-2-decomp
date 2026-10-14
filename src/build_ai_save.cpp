#include "sub_list.h"

#pragma exceptions off

extern "C" {
void func_00226F70(void *stream, void *src, int size);
char* func_0011ABBC(char *dst, const char *src);
int func_0011ACD0(const char *str);

int func_0013C7C0(void*);
int func_0013C7D0(void*);
int func_0013C7E0(void*);
char* func_0013C7F0(void*);
float func_0013C800(void*);
float func_0013C810(void*);
float func_0013C820(void*);
float func_0013C830(void*);
float func_0013C840(void*);
float func_0013C850(void*);
int func_0013C860(void*);
int func_0013CAB0(void*);
int func_0013CAC0(void*);
int func_0013CAD0(void*);
int func_0013CAE0(void*);
int func_0013CAF0(void*);
int func_0013CB00(void*);
int func_0013CB10(void*, int);
int func_0013CB50(void*);
int func_0013CBD0(void*);
int func_0013CC00(void*);
int func_0013CC20(void*);
unsigned char func_0013CC40(void*);
}

struct BuildItemNode {
    char pad_00[0x6C];
    BuildItemNode *m_next;
    char pad_70[0xAC - 0x70];
    int m_fieldAC;
};

struct BuildAI {
    void *m_vtable;
    char pad_04[0xA8];
    BuildItemNode m_sentinel;
    char pad_sentinel[0x160 - (0xAC + sizeof(BuildItemNode))];
    int m_field160;
    char m_buf1[257];
    char m_buf2[257];
    char m_buf3[257];
    char m_buf4[257];
    int m_field568;

    int Save(void *stream);
};

int BuildAI::Save(void *stream) {
    char pad_stack[8];
    char buf[256];
    int len;
    int count;
    float f;
    int v2;
    char b;

    func_00226F70(stream, &this->m_field160, 4);

    func_0011ABBC(buf, this->m_buf1);
    len = func_0011ACD0(buf);
    func_00226F70(stream, &len, 4);
    func_00226F70(stream, buf, func_0011ACD0(buf));

    func_0011ABBC(buf, this->m_buf2);
    len = func_0011ACD0(buf);
    func_00226F70(stream, &len, 4);
    func_00226F70(stream, buf, func_0011ACD0(buf));

    func_0011ABBC(buf, this->m_buf3);
    len = func_0011ACD0(buf);
    func_00226F70(stream, &len, 4);
    func_00226F70(stream, buf, func_0011ACD0(buf));

    func_0011ABBC(buf, this->m_buf4);
    len = func_0011ACD0(buf);
    func_00226F70(stream, &len, 4);
    func_00226F70(stream, buf, func_0011ACD0(buf));

    func_00226F70(stream, &this->m_field568, 4);

    BuildItemNode *cur = this->m_sentinel.m_next;
    count = 0;
    while (cur != &this->m_sentinel) {
        count++;
        cur = cur->m_next;
    }
    func_00226F70(stream, &count, 4);

    for (cur = this->m_sentinel.m_next; cur != &this->m_sentinel && cur != 0; cur = cur->m_next) {
        char *name = func_0013C7F0(cur);
        func_0011ABBC(buf, name);
        len = func_0011ACD0(buf);
        func_00226F70(stream, &len, 4);
        func_00226F70(stream, buf, func_0011ACD0(buf));

        len = func_0013C7C0(cur); func_00226F70(stream, &len, 4);
        len = func_0013C7D0(cur); func_00226F70(stream, &len, 4);
        len = func_0013C7E0(cur); func_00226F70(stream, &len, 4);

        f = func_0013C800(cur); func_00226F70(stream, &f, 4);
        f = func_0013C810(cur); func_00226F70(stream, &f, 4);
        f = func_0013C820(cur); func_00226F70(stream, &f, 4);
        f = func_0013C830(cur); func_00226F70(stream, &f, 4);
        f = func_0013C840(cur); func_00226F70(stream, &f, 4);
        f = func_0013C850(cur); func_00226F70(stream, &f, 4);

        v2 = func_0013C860(cur); func_00226F70(stream, &v2, 4);
        len = func_0013CAB0(cur); func_00226F70(stream, &len, 4);
        v2 = func_0013CAC0(cur); func_00226F70(stream, &v2, 4);
        v2 = func_0013CAD0(cur); func_00226F70(stream, &v2, 4);
        len = func_0013CAE0(cur); func_00226F70(stream, &len, 4);
        len = func_0013CAF0(cur); func_00226F70(stream, &len, 4);
        len = func_0013CB00(cur); func_00226F70(stream, &len, 4);
        len = func_0013CB10(cur, 1); func_00226F70(stream, &len, 4);
        len = func_0013CB10(cur, 2); func_00226F70(stream, &len, 4);
        v2 = func_0013CB50(cur); func_00226F70(stream, &v2, 4);
        len = func_0013CBD0(cur); func_00226F70(stream, &len, 4);
        len = func_0013CC00(cur); func_00226F70(stream, &len, 4);
        len = func_0013CC20(cur); func_00226F70(stream, &len, 4);

        b = (char)func_0013CC40(cur);
        func_00226F70(stream, &b, 1);

        v2 = cur->m_fieldAC;
        func_00226F70(stream, &v2, 4);
    }
    return 1;
}
