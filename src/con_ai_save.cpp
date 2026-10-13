#include "sub_list.h"

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

int func_0013E160(void *item);
int func_0013E170(void *item);
int func_0013E180(void *item);
}

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
    SubListConItem m_sentinel2;
    char pad_2CC[0x4];
    SubListConItem m_items[10];

    SubListConItem* GetSentinel1() { return &this->m_sentinel1; }
    SubListConItem* GetSentinel2() { return &this->m_sentinel2; }

    int Save(void *stream);
};

int ConAI::Save(void *stream) {
    char buf[264];
    int val;
    float fval1;
    int ival1;
    float fval2;
    int ival2;

    func_00226F70(stream, (char*)this + 0xAC, 4);

    func_0011ABBC(buf, (char*)this + 0xC8);
    val = func_0011ACD0(buf);
    func_00226F70(stream, &val, 4);
    func_00226F70(stream, buf, func_0011ACD0(buf));

    func_00226F70(stream, (char*)this + 0xBC, 4);
    func_00226F70(stream, (char*)this + 0xC0, 4);
    func_00226F70(stream, (char*)this + 0xC4, 4);
    func_00226F70(stream, (char*)this + 0xB4, 4);
    func_00226F70(stream, (char*)this + 0xB8, 4);

    for (SubListConItem *item = *(SubListConItem**)((char*)this + 0x238); item != this->GetSentinel1() && item != 0; item = *(SubListConItem**)((char*)item + 0x6C)) {
        func_0011ABBC(buf, func_0013C7F0(item));
        val = func_0011ACD0(buf);
        func_00226F70(stream, &val, 4);
        func_00226F70(stream, buf, val);

        val = func_0013C7C0(item);
        func_00226F70(stream, &val, 4);
        val = func_0013C7D0(item);
        func_00226F70(stream, &val, 4);
        val = func_0013C7E0(item);
        func_00226F70(stream, &val, 4);

        fval1 = func_0013C800(item);
        func_00226F70(stream, &fval1, 4);
        fval1 = func_0013C810(item);
        func_00226F70(stream, &fval1, 4);
        fval1 = func_0013C820(item);
        func_00226F70(stream, &fval1, 4);
        fval1 = func_0013C830(item);
        func_00226F70(stream, &fval1, 4);
        fval1 = func_0013C840(item);
        func_00226F70(stream, &fval1, 4);
        fval1 = func_0013C850(item);
        func_00226F70(stream, &fval1, 4);

        ival1 = func_0013C860(item);
        func_00226F70(stream, &ival1, 4);
        ival1 = func_0013E160(item);
        func_00226F70(stream, &ival1, 4);
        ival1 = func_0013E170(item);
        func_00226F70(stream, &ival1, 4);
        val = func_0013E180(item);
        func_00226F70(stream, &val, 4);
    }

    func_00226F70(stream, (char*)this + 0xB0, 4);

    for (SubListConItem *item = *(SubListConItem**)((char*)this + 0x2B8); item != this->GetSentinel2() && item != 0; item = *(SubListConItem**)((char*)item + 0x6C)) {
        func_0011ABBC(buf, func_0013C7F0(item));
        val = func_0011ACD0(buf);
        func_00226F70(stream, &val, 4);
        func_00226F70(stream, buf, val);

        val = func_0013C7C0(item);
        func_00226F70(stream, &val, 4);
        val = func_0013C7D0(item);
        func_00226F70(stream, &val, 4);
        val = func_0013C7E0(item);
        func_00226F70(stream, &val, 4);

        fval2 = func_0013C800(item);
        func_00226F70(stream, &fval2, 4);
        fval2 = func_0013C810(item);
        func_00226F70(stream, &fval2, 4);
        fval2 = func_0013C820(item);
        func_00226F70(stream, &fval2, 4);
        fval2 = func_0013C830(item);
        func_00226F70(stream, &fval2, 4);
        fval2 = func_0013C840(item);
        func_00226F70(stream, &fval2, 4);
        fval2 = func_0013C850(item);
        func_00226F70(stream, &fval2, 4);

        ival2 = func_0013C860(item);
        func_00226F70(stream, &ival2, 4);
        ival2 = func_0013E160(item);
        func_00226F70(stream, &ival2, 4);
        ival2 = func_0013E170(item);
        func_00226F70(stream, &ival2, 4);
        val = func_0013E180(item);
        func_00226F70(stream, &val, 4);
    }

    return 1;
}
