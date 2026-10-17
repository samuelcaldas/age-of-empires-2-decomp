#include <cassert>
#include "zone_spatial_entity_resolve_wrapper.h"
#include "zone_spatial_entity_setup.h"
#include "zone_spatial_entity_derived_dtor.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

void *D_004D96B0 = (void *)0x1111;
void *D_004D7A90 = (void *)0x2222;

static int s_rebind_called = 0;
static int s_base_dtor_called = 0;
static int s_delete_called = 0;

extern "C" void func_1E3710(void *self) {
}

extern "C" void func_151B90(void *self, void *sub) {
    s_rebind_called++;
}

extern "C" void func_2639D0(void *self, int flag) {
    s_base_dtor_called++;
}

extern "C" void func_100670(void *ptr) {
    s_delete_called++;
}

struct SpatialEntity {
    void *vtable;
    char pad[0x34];
    unsigned char f38;
    char pad2[0x130 - 0x39];
    void *sub_obj;
};

static void test_spatial_entity_resolve() {
    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;

    assert(func_001DBE50(nullptr) == nullptr);
    assert(func_001DBE50((::SpatialEntity *)&ent) == &ent);

    int dummy = 42;
    ent.f38 = 0x50;
    ent.sub_obj = &dummy;
    assert(func_001DBE50((::SpatialEntity *)&ent) == &dummy);
}

static void test_spatial_entity_dtor() {
    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;

    s_base_dtor_called = 0;
    s_delete_called = 0;
    func_001DC100((::SpatialEntity *)&ent, 0);
    assert(s_base_dtor_called == 1);
    assert(s_delete_called == 0);

    func_001DC100((::SpatialEntity *)&ent, 1);
    assert(s_delete_called == 1);
}

int main(int argc, char **argv) {
    test_spatial_entity_resolve();
    test_spatial_entity_dtor();
    return 0;
}
