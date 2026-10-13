#include "sub_list.h"

struct SubListBuildItem {
    char pad[0x6C];
    SubListBuildItem *m_next;
    SubListBuildItem *m_prev;
};

struct BuildAI {
    char pad[0xAC];
    SubListBuildItem m_sentinel;
};

extern "C" {
int func_0013C7C0(void *item);
int func_0013CAB0(void *item);
int func_0013CAD0(void *item);
int func_0013CAC0(void *item);
int func_0013C7E0(void *item);

int func_0013DE00(BuildAI *self, int type, int category) {
    int count = 0;
    SubListBuildItem *it = self->m_sentinel.m_next;
    while (it != &self->m_sentinel && it != 0) {
        if (func_0013C7C0(it) == type && func_0013CAB0(it) == category) {
            if (func_0013CAD0(it) == 1 || func_0013CAC0(it) == 1) {
                count++;
            }
        }
        it = it->m_next;
    }
    return count;
}

void func_0013DEC0(BuildAI *self) {
    SubListBuildItem *it = self->m_sentinel.m_next;
    while (it != &self->m_sentinel && it != 0) {
        SubListBuildItem *next = it->m_next;
        it->m_next = 0;
        it->m_prev = 0;
        it = next;
    }
    self->m_sentinel.m_next = &self->m_sentinel;
    self->m_sentinel.m_prev = &self->m_sentinel;
}

void* func_0013DF00(BuildAI *self, int id) {
    SubListBuildItem *it = self->m_sentinel.m_next;
    while (it != &self->m_sentinel && it != 0) {
        if (func_0013C7E0(it) == id) {
            return it;
        }
        it = it->m_next;
    }
    return 0;
}

int func_0013DF80(BuildAI *self) {
    return 0;
}
}
