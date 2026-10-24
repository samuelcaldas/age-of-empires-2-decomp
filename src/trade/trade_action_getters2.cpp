#pragma exceptions off
#include "sub_list.h"

struct TradeAction {
    void *m_vtable;          // 0x0
    char m_field04[0x29];    // 0x4 to 0x2C
    unsigned char m_field2D; // 0x2D
};

extern "C" {

void func_00147FB0() {
}

int func_00147FC0() {
    return 0;
}

int func_00147FD0(TradeAction *self, int action) {
    if (self->m_field2D == 1) {
        return 1;
    }

    if ((action == 0x258 || action == 0x259) ||
        (action == 0x25B || action == 0x25C) ||
        action == 0x26A || action == 0x264) {
        return 1;
    }

    return 0;
}

}
