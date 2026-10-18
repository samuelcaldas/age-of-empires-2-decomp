#pragma exceptions off
#include "zone_spatial_grid_single_list_init.h"

struct SingleList {
    void *head;
};

extern "C" void *func_001ECFD0(void *self_ptr) {
    SingleList *self = (SingleList *)self_ptr;
    self->head = 0;
    return self;
}
