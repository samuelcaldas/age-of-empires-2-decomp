#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_entity_clear_velocity_threshold.h"

struct SpatialEntityMock {
    char pad[0x68];
    float f68;
};

int main() {
    SpatialEntityMock mock;
    std::memset(&mock, 0, sizeof(mock));
    mock.f68 = 123.456f;

    func_001DCB20(reinterpret_cast<SpatialEntity *>(&mock));

    assert(mock.f68 == 0.0f);

    return 0;
}
