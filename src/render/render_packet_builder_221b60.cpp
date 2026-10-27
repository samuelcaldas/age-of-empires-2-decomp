#pragma exceptions off
#include "sub_list.h"

extern "C" {
int func_00221AC0(void);

static char s_packet_buffer[4096];
static int s_buffer_idx = 0;

void *func_00221B60(int type) {
    if (s_buffer_idx + type > 4096) {
        s_buffer_idx = 0;
    }
    void *ptr = &s_packet_buffer[s_buffer_idx];
    s_buffer_idx += type;
    return ptr;
}

void func_00221C00(void) {
    func_00221B60(0x100);
    func_00221AC0();
}
}
