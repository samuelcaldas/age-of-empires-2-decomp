#include "sub_list.h"

#pragma exceptions off

extern "C" {
void *memset(void *dst, int val, unsigned int size);
void func_144310(void *ptr);
void func_144340(void *ptr, int a1, int a2);
int func_21A3F0(int a0);
int func_142980(void *ptr);
int func_143860(void *ptr);
int func_143440(void *ptr);
}

struct TacticalItem {
    int m_field00;
    char m_name[1024];
    int m_field404;
    int m_field408;
    int m_field40C;
    int m_field410;
    int m_field414;
};

struct TacticalAI2 {
    void *m_vtable;
    char pad_004[0x190 - 4];
    int m_field190;
    int m_field194;
    int m_field198;
    int m_field19C;
    char pad_1A0[0x2A8 - 0x1A0];
    char m_name[1024];
    char *m_field6A8;
    int m_field6AC;
    int m_field6B0;
    int m_field6B4;
    int m_field6B8;
    int m_field6BC;
    int m_item_count;
    TacticalItem m_items[10];
    int m_stack_count;
    int m_stack[50];
    int m_field3080;
};

extern "C" {

int func_00142560(TacticalAI2 *self, int a1);

int func_001424A0(TacticalAI2 *self, int a1, int a2, int a3, int t0) {
    self->m_field190 = a1;
    self->m_field6B4 = t0;
    self->m_field3080 = a3;
    self->m_field194 = 0;
    self->m_field198 = 1;
    self->m_item_count = 0;
    self->m_stack_count = 0;
    memset(self->m_items, 0, 0x28F0);
    memset(self->m_stack, 0, 0xC8);
    func_144310(self);
    if (!func_00142560(self, a2)) {
        return 0;
    }
    if (!self->m_field194) {
        func_144340(self, 0x12, 0);
        return 0;
    }
    return 1;
}

int func_00142560(TacticalAI2 *self, int a1) {
    self->m_field6AC = a1;
    int saved_stack = self->m_stack_count;
    self->m_name[0] = 0;
    self->m_field6A8 = self->m_name;
    self->m_field6B0 = 0;
    self->m_field6B8 = func_21A3F0(a1);
    self->m_field6BC = 0;
    int tok = func_142980(self);
    while (tok == 2) {
        if (self->m_field19C == 1) {
            if (!func_143860(self)) {
                return 0;
            }
        } else if (self->m_field19C == 2) {
            if (!func_143440(self)) {
                return 0;
            }
        } else {
            func_144340(self, 0xF, 0);
            return 0;
        }
        tok = func_142980(self);
    }
    if (tok != 0) {
        return 0;
    }
    if (self->m_stack_count != saved_stack) {
        func_144340(self, 0xA, 0);
        return 0;
    }
    return 1;
}

}
