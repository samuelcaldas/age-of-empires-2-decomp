#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_entity_stop.h"

static int s_func_267A80_calls = 0;
static int s_method2e8_calls = 0;

extern "C" {
void func_267A80(void *self) {
    (void)self;
    s_func_267A80_calls++;
}
}

static void mock_method2e8(void *self) {
    (void)self;
    s_method2e8_calls++;
}

struct SpatialEntityMock {
    void **vtable;
    char pad_vtable_to_motion[0x70 - 4];
    int f70;
    int f74;
    int f78;
    char pad_motion_to_80[0x80 - 0x7C];
    int f80;
    int f84;
};

int main() {
    void *vtable_entries[200];
    std::memset(vtable_entries, 0, sizeof(vtable_entries));
    // Index for offset 0x2E8 is 0x2E8 / 4 = 186
    vtable_entries[0x2E8 / sizeof(void *)] = (void *)mock_method2e8;

    SpatialEntityMock mock;
    std::memset(&mock, 0, sizeof(mock));
    mock.vtable = vtable_entries;
    mock.f70 = 10;
    mock.f74 = 20;
    mock.f78 = 30;
    mock.f80 = 40;
    mock.f84 = 50;

    SpatialEntity *se = reinterpret_cast<SpatialEntity *>(&mock);

    func_001DCAA0(se);

    assert(s_func_267A80_calls == 1);
    assert(mock.f70 == 0);
    assert(mock.f74 == 0);
    assert(mock.f78 == 0);
    assert(mock.f80 == 0);
    assert(mock.f84 == 0);
    assert(s_method2e8_calls == 1);

    return 0;
}
