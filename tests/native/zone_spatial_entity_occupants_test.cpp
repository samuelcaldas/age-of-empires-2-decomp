#include <cassert>
#include "zone_spatial_entity_resolve_world_node.h"
#include "zone_spatial_entity_query_spatial_cell.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialEntity {
    char pad[0x10];
};

static void test_stubs() {
    SpatialEntity ent;
    assert(func_001DDCD0(&ent, nullptr, nullptr, 0.0f) == 0);
    assert(func_001DDE50(&ent, nullptr, nullptr, 0.0f) == 0);
}

int main(int argc, char **argv) {
    test_stubs();
    return 0;
}
