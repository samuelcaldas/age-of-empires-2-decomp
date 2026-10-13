
#include "sub_list.h"

extern "C" {
void func_0011ABBC(char *dst, const char *src);
void func_0011B170(char *dst, const char *src, int n);
void func_0013C960(void *self, int category, int type, int id,
                   int p78, int p7C, int arg5, const char *name,
                   float f12, float f13, float f14,
                   int p88, int p8C, int p90, int pA8);

void func_0013CB70(void *self, int val);
void func_0013CB60(void *self, int val);
void func_0013CB80(void *self, int val);
void func_0013C8D0(void *self, int val);
void func_0013C880(void *self, int val);
void func_0013C8A0(void *self, float val);
void func_0013C8B0(void *self, float val);
void func_0013C8C0(void *self, float val);
void func_0013CBF0(void *self, int val);
void func_0013CC10(void *self, int val);
void func_0013CC30(void *self, int val);
void func_0013CC50(void *self, int val);

extern const char D_00490D50[];
extern const char D_00490D60[];
extern const char D_00490D80[];
}

struct MasterObject {
    char pad[0x20];
    float m_width;
    float m_height;
};

struct BuildAIWorld {
    char pad_00[0x70];
    MasterObject **m_items;
};

struct BuildAIItem {
    char pad_00[0x6C];
    BuildAIItem *m_next;
    BuildAIItem *m_prev;
    char pad_74[0xAC - 0x74];
    int m_fieldAC;
};

struct BuildAI {
    char pad_00[0x11C];
    BuildAIItem *m_buildItemPrev;
    char pad_120[0x160 - 0x120];
    int m_field160;

    BuildAIItem *AllocItem(int type);
    int AddItem(void *world, int type, int category,
                int arg5, int arg6, int arg7);
};

int BuildAI::AddItem(void *world, int type, int category,
                     int arg5, int arg6, int arg7) {
    char name[64];
    float f20;
    float f21;

    if (category != 6) {
        if (((BuildAIWorld *)world)->m_items[type] != 0) {
            func_0011ABBC(name, D_00490D50);
            MasterObject *obj = ((BuildAIWorld *)world)->m_items[type];
            f20 = 2.0f * obj->m_width;
            f21 = 2.0f * obj->m_height;
        } else {
            func_0011B170(name, D_00490D60, 63);
            f20 = 3.0f;
            f21 = 3.0f;
        }
    } else {
        func_0011B170(name, D_00490D80, 63);
        f20 = 3.0f;
        f21 = 3.0f;
    }

    BuildAIItem *item = this->AllocItem(type);
    if (item == 0) {
        return 0;
    }

    func_0013C960(item, category, type, this->m_field160, 1, 0, arg5, name,
                  f20, f21, 1.0f, -1, -1, -1, 0);

    func_0013CB70(item, 0);
    func_0013CB60(item, 0);
    func_0013CB80(item, 0);
    func_0013C8D0(item, 0);
    func_0013C880(item, -1);
    func_0013C8A0(item, -1.0f);
    func_0013C8B0(item, -1.0f);
    func_0013C8C0(item, -1.0f);
    func_0013CBF0(item, 0);
    func_0013CC10(item, arg6);
    func_0013CC30(item, 0);
    func_0013CC50(item, 0);

    item->m_fieldAC = arg7;

    BuildAIItem *prev = this->m_buildItemPrev;
    item->m_prev = prev;
    item->m_next = prev->m_next;
    item->m_next->m_prev = item;
    prev->m_next = item;

    this->m_field160++;
    return 1;
}
