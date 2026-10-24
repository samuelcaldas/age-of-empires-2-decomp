#include "sub_list.h"

extern "C" {
void func_0013DD80(void *self, void *item);
void func_0013DDD0(void *self, void *item);
}

struct BuildAIItem {
    char pad_00[0x6C];
    BuildAIItem *m_next;
    BuildAIItem *m_prev;
};

struct BuildAI {
    char pad_00[0x11C];
    BuildAIItem *m_buildItemPrev;
};

void func_0013DD80(void *self, void *item) {
    BuildAIItem *it = (BuildAIItem *)item;
    if (it != 0) {
        it->m_prev->m_next = it->m_next;
        it->m_next->m_prev = it->m_prev;

        BuildAIItem *prev = ((BuildAI *)self)->m_buildItemPrev;
        it->m_prev = prev;
        it->m_next = prev->m_next;
        it->m_next->m_prev = it;
        prev->m_next = it;
    }
}

void func_0013DDD0(void *self, void *item) {
    BuildAIItem *it = (BuildAIItem *)item;
    if (it != 0) {
        it->m_prev->m_next = it->m_next;
        it->m_next->m_prev = it->m_prev;
        it->m_next = 0;
        it->m_prev = 0;
    }
}
