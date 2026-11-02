#include <cassert>
#include <cstdlib>
#include <iostream>
#include "zone_spatial_grid_free_sub_container.h"

static int s_freed_buffer = 0;
static int s_deleted_obj = 0;

extern "C" void func_100630(void *ptr) {
    s_freed_buffer++;
    std::free(ptr);
}

void operator delete(void *ptr) throw() {
    s_deleted_obj++;
    std::free(ptr);
}

int main() {
    SubContainerItem *item = (SubContainerItem *)std::malloc(sizeof(SubContainerItem));
    item->buffer = std::malloc(32);

    delete item;

    assert(s_freed_buffer == 1);
    assert(s_deleted_obj == 1);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
