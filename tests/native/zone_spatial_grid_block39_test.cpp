#include <cassert>
#include <cstring>
#include "zone_spatial_grid_search_nearest_cell.h"
#include "zone_spatial_grid_query_ray_intersection.h"
#include "zone_spatial_grid_vector_find_by_id.h"

struct Element {
    char pad_24[0x24];
    short id;
};

struct FastVector {
    Element **buffer;
    short count;
};

int main() {
    Element el1, el2;
    el1.id = 42;
    el2.id = 99;
    Element *arr[2] = { &el1, &el2 };

    FastVector vec;
    vec.buffer = arr;
    vec.count = 2;

    void *found = func_001EC560(&vec, 99);
    assert(found == &el2);
    void *not_found = func_001EC560(&vec, 123);
    assert(not_found == nullptr);

    assert(func_001EC090(nullptr, nullptr, nullptr, 0, nullptr, nullptr, -2.0f, 0.0f) == -1);
    assert(func_001EC360(nullptr, 0, nullptr, nullptr, nullptr, -2.0f, 0.0f) == 0);
    return 0;
}
