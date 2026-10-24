#include "sub_list.h"

struct SubListBuildItemNode {
    char pad_00[0x6C];
    void *m_next;
    void *m_prev;
    char pad_74[0xB4 - 0x74];
};

struct BuildAI {
    void *m_vtable;
    char pad_04[0x578];
    SubListBuildItemNode m_items[50];
};

extern "C" void *func_0013DAC0(BuildAI *self) {
    for (int i = 0; i < 50; i++) {
        if (self->m_items[i].m_next != 0) {
            continue;
        }
        if (self->m_items[i].m_prev != 0) {
            continue;
        }
        return &self->m_items[i];
    }
    return 0;
}
