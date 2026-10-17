#include <cassert>
#include "zone_spatial_entity_set_velocity.h"
#include "zone_spatial_entity_set_heading.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

static int s_state2e8_called = 0;

static void mock_method2e8() {
    s_state2e8_called++;
}

static void *s_mock_vtable[256];

struct SpatialEntity {
    void *vtable;
    char pad[0x70 - 4];
    float f70;
    float f74;
    float f78;
    float heading;
};

static void test_velocity() {
    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;

    func_001DD6E0(&ent, 1.5f, 2.5f, 3.5f);
    assert(ent.f70 == 1.5f);
    assert(ent.f74 == 2.5f);
    assert(ent.f78 == 3.5f);
}

static void test_heading() {
    for (int i = 0; i < 256; i++) s_mock_vtable[i] = (void *)mock_method2e8;

    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;
    ent.vtable = s_mock_vtable;

    s_state2e8_called = 0;
    func_001DD6F0(&ent, 3.14159f);
    assert(ent.heading == 3.14159f);
    assert(s_state2e8_called == 1);
}

int main(int argc, char **argv) {
    test_velocity();
    test_heading();
    return 0;
}
