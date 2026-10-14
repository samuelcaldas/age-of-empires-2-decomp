#include "sub_list.h"

struct TacticalAI2 {
    char m_padding[0x40];
    int m_counter;
    char m_padding2[0x2FB4 - 0x44];
    int m_value;
};

extern "C" {

void func_144340(void *ptr, int a1, int a2);

int func_00142C80(TacticalAI2 *self) {
    return self->m_value == 0;
}

int func_00142C90(TacticalAI2 *self) {
    return self->m_value == 0x32;
}

int func_00142CA0(TacticalAI2 *self) {
    int index = self->m_value;
    return (&self->m_value)[index];
}

int func_00142CC0(TacticalAI2 *self) {
    self->m_counter += 1;
    if (self->m_counter >= 0x10) {
        func_144340(self, 0x14, 0);
        return 0;
    }
    return 1;
}

}
