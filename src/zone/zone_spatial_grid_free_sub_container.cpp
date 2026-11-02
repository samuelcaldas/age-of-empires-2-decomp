#pragma exceptions off
#include "zone_spatial_grid_free_sub_container.h"

extern "C" {
void func_100630(void *ptr);
}

SubContainerItem::~SubContainerItem() {
    if (this->buffer != 0) {
        func_100630(this->buffer);
        this->buffer = 0;
    }
}
