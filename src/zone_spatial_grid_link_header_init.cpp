#pragma exceptions off
#include "zone_spatial_grid_link_header_init.h"

struct LinkHeader {
    short count;
    char pad_02[2];
    void *head;
};

extern "C" void *func_001EC980(void *self_ptr) {
    LinkHeader *self = (LinkHeader *)self_ptr;
    self->head = 0;
    self->count = 0;
    return self;
}
