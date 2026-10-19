#include "sub_list.h"

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
    char pad_004[0x194];
    int m_field198;
    char pad_19C[0x108];
    int m_field2A4;
    char m_name[1024];
    int m_field6A8;
    int m_field6AC;
    int m_field6B0;
    int pad_6B4;
    int m_field6B8;
    int m_field6BC;
    int m_item_count;
    TacticalItem m_items[10];
    int m_stack_count;
    int m_stack[50];
};

extern "C" {

char *func_0011ABBC(char *dst, const char *src);

void func_144050(TacticalAI2 *self) {
    self->m_item_count--;
    self->m_field2A4 = self->m_items[self->m_item_count].m_field00;
    self->m_field6AC = self->m_items[self->m_item_count].m_field408;
    self->m_field6A8 = self->m_items[self->m_item_count].m_field404;
    self->m_field6B0 = self->m_items[self->m_item_count].m_field40C;
    func_0011ABBC(self->m_name, self->m_items[self->m_item_count].m_name);
    self->m_field6B8 = self->m_items[self->m_item_count].m_field410;
    self->m_field6BC = self->m_items[self->m_item_count].m_field414;
}

void func_144180(TacticalAI2 *self) {
    self->m_stack_count--;
    self->m_field198 = self->m_stack[self->m_stack_count];
}

}
