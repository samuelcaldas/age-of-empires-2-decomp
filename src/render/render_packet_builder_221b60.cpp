#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_104558(void *buffer, int a1, int a2, int a3);
void *func_1043D8(void *buffer);
void func_00221880(void);
void func_00221920(void);
int func_00221AC0(void);

static int s_dma_buffer_index;

void *func_00221B60(int type) {
    unsigned int index = (unsigned int)s_dma_buffer_index;
    unsigned int slot_offset = index << 4;
    char *buffer = (char *)(0x70000000 + slot_offset);
    unsigned int read_pointer_address = 0x70000004 + slot_offset;
    unsigned int write_address = *(unsigned int *)buffer;
    unsigned int read_address = *(unsigned int *)read_pointer_address;
    unsigned int pending = ((write_address - read_address) >> 4) + (unsigned int)type + 0x20;

    if (pending >= 0x101) {
        func_104558(buffer, 0, 0, 0);
        func_1043D8(buffer);
        func_00221880();
        func_00221920();
    }
    index = (unsigned int)s_dma_buffer_index;
    return (void *)(0x70000000 + (index << 4));
}

void func_00221C00(void) {
    func_00221B60(0x100);
    func_00221AC0();
}
}
