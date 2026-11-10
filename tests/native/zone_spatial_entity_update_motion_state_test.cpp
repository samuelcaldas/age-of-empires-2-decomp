#include <cassert>
#include <cstring>
#include <iostream>
#include "zone_spatial_entity_update_motion_state.h"

static void *g_freed_ptr = 0;

extern "C" {
void func_1002A0(void *ptr, void *fn) {
    g_freed_ptr = ptr;
}
}

struct SpatialEntity {
    char pad[0x88];
    void *field_88;
    short field_8c;
    short field_8e;
};

int main() {
    SpatialEntity entity;
    std::memset(&entity, 0xFF, sizeof(entity));

    int dummy = 42;
    entity.field_88 = &dummy;
    entity.field_8c = 10;
    entity.field_8e = 20;

    func_001DED70(&entity);

    assert(g_freed_ptr == &dummy);
    assert(entity.field_88 == 0);
    assert(entity.field_8c == 0);
    assert(entity.field_8e == 0);

    // Call again when field_88 is null
    g_freed_ptr = 0;
    entity.field_8c = 5;
    entity.field_8e = 6;
    func_001DED70(&entity);

    assert(g_freed_ptr == 0);
    assert(entity.field_88 == 0);
    assert(entity.field_8c == 0);
    assert(entity.field_8e == 0);

    std::cout << "zone_spatial_entity_update_motion_state_test passed\n";
    return 0;
}
