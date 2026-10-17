#include <cassert>
#include "zone_spatial_entity_has_positive_threshold.h"
#include "zone_spatial_entity_clear_velocity_threshold.h"
#include "zone_spatial_entity_stop.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialEntity {
    char pad[0x68];
    float f68;
};

static int s_state2e8_called = 0;

static void mock_method2e8() {
    s_state2e8_called++;
}

static void *s_mock_vtable[256];

extern "C" void func_267A80(void *self) {
}

static void test_threshold() {
    SpatialEntity ent;
    ent.f68 = -1.0f;
    assert(func_001DCAF0(&ent) == 0);

    ent.f68 = 5.0f;
    assert(func_001DCAF0(&ent) == 1);

    func_001DCB20(&ent);
    assert(ent.f68 == 0.0f);
}

static void test_stop() {
    for (int i = 0; i < 256; i++) s_mock_vtable[i] = (void *)mock_method2e8;

    char ent_buffer[0x100];
    for (int i = 0; i < sizeof(ent_buffer); i++) ent_buffer[i] = 0;
    *(void **)ent_buffer = s_mock_vtable;

    *(int *)(ent_buffer + 0x70) = 10;
    *(int *)(ent_buffer + 0x74) = 20;

    s_state2e8_called = 0;
    func_001DCAA0((::SpatialEntity *)ent_buffer);
    assert(*(int *)(ent_buffer + 0x70) == 0);
    assert(*(int *)(ent_buffer + 0x74) == 0);
    assert(s_state2e8_called == 1);
}

int main(int argc, char **argv) {
    test_threshold();
    test_stop();
    return 0;
}
