#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_entity_resolve_wrapper.h"

struct SpatialEntity {
    char pad[0x38];
    unsigned char f38;
    char pad2[0x130 - 0x39];
    void *sub_obj;
};

int main() {
    // Test 1: self == NULL returns NULL
    void *r0 = func_001DBE50(NULL);
    assert(r0 == NULL);

    SpatialEntity ent;
    std::memset(&ent, 0, sizeof(ent));

    // Test 2: f38 != 0x50 returns self
    ent.f38 = 0x10;
    ent.sub_obj = (void *)0x1234;
    void *r1 = func_001DBE50(&ent);
    assert(r1 == &ent);

    // Test 3: f38 == 0x50 and sub_obj != NULL returns sub_obj
    ent.f38 = 0x50;
    ent.sub_obj = (void *)0xBEEF;
    void *r2 = func_001DBE50(&ent);
    assert(r2 == (void *)0xBEEF);

    // Test 4: f38 == 0x50 but sub_obj == NULL returns self
    ent.sub_obj = NULL;
    void *r3 = func_001DBE50(&ent);
    assert(r3 == &ent);

    return 0;
}
