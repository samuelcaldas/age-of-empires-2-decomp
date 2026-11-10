#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_entity_set_state.h"

struct SpatialEntityInfo {
    char pad[0x10];
    int default_state;
};

static int s_func_2673D0_called = 0;
static int s_last_2673D0_state = 0;
static int s_vtable_called = 0;

static void mock_method_2e8(void *self) {
    (void)self;
    s_vtable_called++;
}

extern "C" {
void func_2673D0(void *self, int state) {
    (void)self;
    s_func_2673D0_called++;
    s_last_2673D0_state = state;
}
}

// Memory layout of SpatialEntity for func_001DC9D0:
// 0x00: vtable pointer
// 0x04: info pointer (SpatialEntityInfo*)
// 0x10: int state
// 0x14: int prev_state
struct SpatialEntityMock {
    void **vtable;
    SpatialEntityInfo *info;
    char pad[8];
    int state;
    int prev_state;
};

int main() {
    // Vtable needs to have entry at offset 0x2E8 (which is index 0x2E8 / 4 = 186)
    void *vtable_entries[200];
    std::memset(vtable_entries, 0, sizeof(vtable_entries));
    vtable_entries[0x2E8 / sizeof(void*)] = (void*)mock_method_2e8;

    SpatialEntityInfo info;
    std::memset(&info, 0, sizeof(info));
    info.default_state = 5;

    SpatialEntityMock entity;
    std::memset(&entity, 0, sizeof(entity));
    entity.vtable = vtable_entries;
    entity.info = &info;
    entity.state = 1;
    entity.prev_state = 0;

    SpatialEntity *se = reinterpret_cast<SpatialEntity*>(&entity);

    // Test 1: state changes to target_state = 2
    func_001DC9D0(se, 2);
    assert(s_func_2673D0_called == 1);
    assert(s_last_2673D0_state == 2);
    assert(s_vtable_called == 1);
    assert(entity.prev_state == 1);

    // Test 2: state does not change when target_state == current state
    entity.state = 2;
    func_001DC9D0(se, 2);
    assert(s_func_2673D0_called == 1);
    assert(s_vtable_called == 1);

    // Test 3: target_state == 0 falls back to default_state (5)
    func_001DC9D0(se, 0);
    assert(s_func_2673D0_called == 2);
    assert(s_last_2673D0_state == 5);
    assert(s_vtable_called == 2);
    assert(entity.prev_state == 2);

    return 0;
}
