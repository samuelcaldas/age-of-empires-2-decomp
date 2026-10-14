#include "sub_list.h"

extern "C" {
    extern char D_00490D50[];
    extern char D_00490D60[];
    extern char D_00490D80[];

    void* func_0011ABBC(void *dst, const void *src);
    void* func_0011B170(void *dst, const void *src, int n);
    void* func_0013DAC0(void *self, int param);
    void func_0013C960(void *self, int p74, int a1, int a3,
                       int p78, int p7C, int p84, const char *str,
                       float f12, float f13, float f14,
                       long long p88, long long p8C, long long p90, long long pA8);

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
}

struct BuildItemNode {
    char pad_00[0x6C];
    BuildItemNode *m_prev;
    BuildItemNode *m_next;
    char pad_74[0xAC - 0x74];
    int m_fieldAC;
};

struct BuildAI {
    void *m_vtable;
    char pad_04[0x118];
    BuildItemNode *m_head;
    char pad_120[0x160 - 0x120];
    int m_count;

    int AddItem(void *player, int unit_id, int type, int a5, int a6, int a7);
};

int BuildAI::AddItem(void *player, int unit_id, int type, int a5, int a6, int a7) {
    char name_buf[64];
    float f20;
    float f21;

    if (type != 6) {
        void *unit_type = (*(void***)((char*)player + 112))[unit_id];
        if (unit_type) {
            func_0011ABBC(name_buf, D_00490D50);
            void *ut = (*(void***)((char*)player + 112))[unit_id];
            float f2 = 2.0f;
            f20 = f2 * *(float*)((char*)ut + 32);
            f21 = f2 * *(float*)((char*)ut + 36);
        } else {
            func_0011B170(name_buf, D_00490D60, 63);
            f20 = 3.0f;
            f21 = 3.0f;
        }
    } else {
        func_0011B170(name_buf, D_00490D80, 63);
        f20 = 3.0f;
        f21 = 3.0f;
    }

    BuildItemNode *item = (BuildItemNode*)func_0013DAC0(this, unit_id);
    if (!item) {
        return -1;
    }

    func_0013C960(item, type, unit_id, this->m_count,
                   1, 0, a5, name_buf,
                   f20, f21, 1.0f,
                   -1LL, -1LL, -1LL, 0LL);

    func_0013CB70(item, 0);
    func_0013CB60(item, 0);
    func_0013CB80(item, 0);
    func_0013C8D0(item, 0);
    func_0013C880(item, -1);
    func_0013C8A0(item, -1.0f);
    func_0013C8B0(item, -1.0f);
    func_0013C8C0(item, -1.0f);
    func_0013CBF0(item, 0);
    func_0013CC10(item, a6);
    func_0013CC30(item, 0);
    func_0013CC50(item, 0);
    item->m_fieldAC = a7;

    BuildItemNode *head = this->m_head;
    item->m_next = head;
    item->m_prev = head->m_prev;
    item->m_prev->m_next = item;
    head->m_prev = item;
    this->m_count++;
    return 1;
}
