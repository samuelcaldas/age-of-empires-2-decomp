#include "sub_list.h"

extern "C" {
void func_001454C0(void *obj, const char *fmt, ...);

const char *func_0013C7F0(void *item);
int func_0013C7C0(void *item);
int func_0013C7D0(void *item);
int func_0013C7E0(void *item);
int func_0013C860(void *item);
int func_0013CAB0(void *item);
int func_0013CAC0(void *item);
int func_0013CAD0(void *item);
int func_0013CAE0(void *item);
int func_0013CAF0(void *item);
int func_0013CBD0(void *item);
int func_0013CC00(void *item);
int func_0013CC20(void *item);
unsigned char func_0013CC40(void *item);

extern const char D_00490C30[];
extern const char D_00490C50[];
extern const char D_00490CD0[];

void func_0013D820(void *self);
}

struct BuildAIListItem {
    char pad_00[0x6C];
    BuildAIListItem *m_next;
};

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

    void Log();
};

void BuildAI::Log() {
    func_001454C0(this, D_00490C30, this->m_buf1);

    for (char *item = *(char **)((char *)this + 0x118);
         item != this->m_buildItem && item != 0;
         item = *(char **)(item + 0x6C)) {
        if (func_0013CAD0(item) == 1) {
            func_001454C0(
                this,
                D_00490C50,
                func_0013C7C0(item),
                func_0013C7F0(item),
                func_0013C7D0(item),
                func_0013CAB0(item),
                func_0013C7E0(item),
                func_0013CAC0(item),
                func_0013CAE0(item),
                func_0013C860(item),
                func_0013CBD0(item),
                func_0013CC00(item),
                func_0013CAF0(item),
                (unsigned int)func_0013CC40(item),
                func_0013CC20(item)
            );
        } else {
            func_001454C0(
                this,
                D_00490CD0,
                func_0013C7C0(item),
                func_0013C7F0(item),
                func_0013C7D0(item),
                func_0013CAB0(item),
                func_0013C7E0(item),
                func_0013CAC0(item),
                func_0013CAE0(item),
                func_0013C860(item),
                func_0013CBD0(item),
                func_0013CC00(item),
                func_0013CAF0(item),
                (unsigned int)func_0013CC40(item),
                func_0013CC20(item)
            );
        }
    }
}

