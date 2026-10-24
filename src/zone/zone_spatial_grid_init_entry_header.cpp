#pragma exceptions off
#include "zone_spatial_grid_init_entry_header.h"

struct EntryHeader {
    int id;
    short val1;
    short val2;
    char flag;
};

extern "C" void *func_001EB900(void *self_ptr) {
    EntryHeader *self = (EntryHeader *)self_ptr;
    self->id = 0;
    self->val1 = 0;
    self->val2 = 0;
    self->flag = 0;
    return self;
}
