#include <cassert>
#include <cstring>
#include "zone_spatial_grid_query_ray_cell.h"
#include "zone_spatial_grid_filter_intersecting_obstacles.h"
#include "zone_spatial_grid_link_header_init.h"
#include "zone_spatial_grid_link_header_destructor.h"
#include "zone_spatial_grid_link_header_clear.h"

extern "C" {
void func_1EC9E0(void *self) {}
void func_100670(void *ptr) {}
void func_116F68(void *ptr) { delete[] (char *)ptr; }
}

int main() {
    struct LinkHeader {
        short count;
        char pad_02[2];
        void *head;
    } link;
    link.count = 10;
    link.head = (void *)0x1234;

    void *res = func_001EC980(&link);
    assert(res == &link);
    assert(link.count == 0);
    assert(link.head == nullptr);

    func_001EC9F0(&link);
    assert(link.count == 0);
    assert(link.head == nullptr);

    assert(func_001EC5B0(nullptr, nullptr, nullptr, nullptr, nullptr, -2.0f, 0.0f) == 0);
    func_001EC7C0(nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, 0, 0);
    return 0;
}
