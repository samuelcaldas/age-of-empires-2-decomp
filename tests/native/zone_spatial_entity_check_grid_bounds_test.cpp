#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_entity_check_grid_bounds.h"

extern "C" {
int func_123350(float val) {
    return (int)val;
}

int func_1EE540(void *mgr, void *node) {
    (void)mgr; (void)node;
    return 1;
}

void *D_004D6F34 = NULL;
}

struct SpatialEntityMock {
    char pad[0x10];
};

int main() {
    SpatialEntityMock mock;
    std::memset(&mock, 0, sizeof(mock));
    SpatialEntity *self = reinterpret_cast<SpatialEntity *>(&mock);

    // Negative coordinates -> return 0
    assert(func_001DD7F0(self, -1.0f, 5.0f) == 0);
    assert(func_001DD7F0(self, 5.0f, -1.0f) == 0);

    // Positive coordinates -> return 1
    assert(func_001DD7F0(self, 5.0f, 10.0f) == 1);

    return 0;
}
