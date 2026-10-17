#include <cassert>
#include "zone_spatial_entity_alloc_waypoint_buffer.h"
#include "zone_spatial_entity_free_waypoint_buffer.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialEntity {
    char pad[0x10];
};

static void test_stubs() {
    SpatialEntity ent;
    assert(func_001DEDC0(&ent, 10) == 0);
    func_001DEEE0(&ent);
}

int main(int argc, char **argv) {
    test_stubs();
    return 0;
}
