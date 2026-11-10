#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_104558(void *buffer, int a1, int a2, int a3);
void *func_1043D8(void *buffer);
void func_221880(void);
void func_221920(void);
int func_00221AC0(void);

static int s_dma_buffer_index;

struct SprEntry {
    int cur;
    int base;
    int pad[2];
};

void *func_00221B60(int type) {
    SprEntry *buffer = &((SprEntry *)0x70000000)[s_dma_buffer_index];
    unsigned int diff = ((unsigned int)buffer->cur - (unsigned int)((SprEntry *)0x70000000)[s_dma_buffer_index].base) >> 4;
    if (diff + type + 32 > 256) {
        func_104558(buffer, 0, 0, 0);
        func_1043D8(buffer);
        func_221880();
        func_221920();
    }
    return &((SprEntry *)0x70000000)[s_dma_buffer_index];
}
}
