#pragma exceptions off

#include "zone_free_cell_items_buffer.h"

extern "C" void func_001D0EC0(void *self, void *bucket, void *buffer) {
    char *b = (char *)bucket;
    *(void **)buffer = *(void **)(b + 0x18);
    *(void **)(b + 0x18) = buffer;
    *(int *)(b + 0x28) += 1;
}
