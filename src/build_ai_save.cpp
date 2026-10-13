#include "sub_list.h"

struct BuildAIBuffer {
    void *m_data;
    int m_size;
    int m_cap;
    int m_flags;
};

extern "C" {
void func_00226F70(void *stream, void *src, int size);
void func_0011ABBC(char *dst, const char *src);
int func_0011ACD0(const char *str);

const char *func_0013C7F0(void *item);
int func_0013C7C0(void *item);
int func_0013C7D0(void *item);
int func_0013C7E0(void *item);
float func_0013C800(void *item);
float func_0013C810(void *item);
float func_0013C820(void *item);
float func_0013C830(void *item);
float func_0013C840(void *item);
float func_0013C850(void *item);
int func_0013C860(void *item);
int func_0013CAB0(void *item);
int func_0013CAC0(void *item);
int func_0013CAD0(void *item);
int func_0013CAE0(void *item);
int func_0013CAF0(void *item);
int func_0013CB00(void *item);
int func_0013CB10(void *item, int idx);
int func_0013CB50(void *item);
int func_0013CBD0(void *item);
int func_0013CC00(void *item);
int func_0013CC20(void *item);
unsigned char func_0013CC40(void *item);
}

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

    int Save(void *stream);
};

int BuildAI::Save(void *stream) {
    char buf[264];
    int val;
    int count;
    float fval;
    int val2;
    unsigned char pad[3];
    unsigned char bval;

    func_00226F70(stream, &this->m_field160, 4);

    func_0011ABBC(buf, this->m_buf1);
    val = func_0011ACD0(buf);
    func_00226F70(stream, &val, 4);
    func_00226F70(stream, buf, func_0011ACD0(buf));

    func_0011ABBC(buf, this->m_buf2);
    val = func_0011ACD0(buf);
    func_00226F70(stream, &val, 4);
    func_00226F70(stream, buf, func_0011ACD0(buf));

    func_0011ABBC(buf, this->m_buf3);
    val = func_0011ACD0(buf);
    func_00226F70(stream, &val, 4);
    func_00226F70(stream, buf, func_0011ACD0(buf));

    func_0011ABBC(buf, this->m_buf4);
    val = func_0011ACD0(buf);
    func_00226F70(stream, &val, 4);
    func_00226F70(stream, buf, func_0011ACD0(buf));

    func_00226F70(stream, &this->m_field568, 4);

    count = 0;
    for (char *node = *(char**)((char*)this + 0x118); node != (char*)this + 0xAC; node = *(char**)(node + 0x6C)) {
        count++;
    }
    func_00226F70(stream, &count, 4);

    for (char *item = *(char**)((char*)this + 0x118); item != (char*)this + 0xAC && item != 0; item = *(char**)(item + 0x6C)) {
        func_0011ABBC(buf, func_0013C7F0(item));
        val = func_0011ACD0(buf);
        func_00226F70(stream, &val, 4);
        func_00226F70(stream, buf, func_0011ACD0(buf));

        val = func_0013C7C0(item);
        func_00226F70(stream, &val, 4);

        val = func_0013C7D0(item);
        func_00226F70(stream, &val, 4);

        val = func_0013C7E0(item);
        func_00226F70(stream, &val, 4);

        fval = func_0013C800(item);
        func_00226F70(stream, &fval, 4);

        fval = func_0013C810(item);
        func_00226F70(stream, &fval, 4);

        fval = func_0013C820(item);
        func_00226F70(stream, &fval, 4);

        fval = func_0013C830(item);
        func_00226F70(stream, &fval, 4);

        fval = func_0013C840(item);
        func_00226F70(stream, &fval, 4);

        fval = func_0013C850(item);
        func_00226F70(stream, &fval, 4);

        val2 = func_0013C860(item);
        func_00226F70(stream, &val2, 4);

        val = func_0013CAB0(item);
        func_00226F70(stream, &val, 4);

        val2 = func_0013CAC0(item);
        func_00226F70(stream, &val2, 4);

        val2 = func_0013CAD0(item);
        func_00226F70(stream, &val2, 4);

        val = func_0013CAE0(item);
        func_00226F70(stream, &val, 4);

        val = func_0013CAF0(item);
        func_00226F70(stream, &val, 4);

        val = func_0013CB00(item);
        func_00226F70(stream, &val, 4);

        val = func_0013CB10(item, 1);
        func_00226F70(stream, &val, 4);

        val = func_0013CB10(item, 2);
        func_00226F70(stream, &val, 4);

        val2 = func_0013CB50(item);
        func_00226F70(stream, &val2, 4);

        val = func_0013CBD0(item);
        func_00226F70(stream, &val, 4);

        val = func_0013CC00(item);
        func_00226F70(stream, &val, 4);

        val = func_0013CC20(item);
        func_00226F70(stream, &val, 4);

        bval = func_0013CC40(item);
        func_00226F70(stream, &bval, 1);

        val2 = *(int*)((char*)item + 0xAC);
        func_00226F70(stream, &val2, 4);
    }

    return 1;
}
