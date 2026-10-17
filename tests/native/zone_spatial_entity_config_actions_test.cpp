#include <cassert>
#include "zone_spatial_entity_check_motion_flag.h"
#include "zone_spatial_entity_dispatch_config_action_ac.h"
#include "zone_spatial_entity_dispatch_config_action_a8.h"
#include "zone_spatial_entity_dispatch_config_action_10.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

unsigned int D_00492600 = 0x4;

struct SubEntity2 {
    char pad[0x18];
    unsigned int flags;
};

struct SubEntity {
    char pad[0x8];
    SubEntity2 *sub2;
};

struct ConfigEntity {
    char pad[0x10];
    void *f10;
    char pad2[0xA8 - 0x14];
    void *fA8;
    void *fAC;
};

static void *s_m4c_ptr = nullptr;
static void mock_method4c(void *self, void *p) {
    s_m4c_ptr = p;
}

static void *s_mock_vtable[256];

struct SpatialEntity {
    void *vtable;
    ConfigEntity *config;
    char pad[0xB4 - 0x8];
    SubEntity *sub;
};

static void test_check_motion_flag() {
    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;

    assert(func_001E3600(&ent) == 0);

    SubEntity s1;
    SubEntity2 s2;
    s2.flags = 0x4;
    s1.sub2 = &s2;
    ent.sub = &s1;

    assert(func_001E3600(&ent) == 1);

    s2.flags = 0x8;
    assert(func_001E3600(&ent) == 0);
}

static void test_dispatch_config_actions() {
    for (int i = 0; i < 256; i++) s_mock_vtable[i] = (void *)mock_method4c;

    ConfigEntity cfg;
    for (int i = 0; i < sizeof(cfg); i++) ((char *)&cfg)[i] = 0;

    SpatialEntity ent;
    for (int i = 0; i < sizeof(ent); i++) ((char *)&ent)[i] = 0;
    ent.vtable = s_mock_vtable;
    ent.config = &cfg;

    assert(func_001E3660(&ent) == 0);
    assert(func_001E36A0(&ent) == 0);
    assert(func_001E36E0(&ent) == 0);

    cfg.fAC = (void *)0x1111;
    s_m4c_ptr = nullptr;
    assert(func_001E3660(&ent) == 1);
    assert(s_m4c_ptr == (void *)0x1111);

    cfg.fA8 = (void *)0x2222;
    s_m4c_ptr = nullptr;
    assert(func_001E36A0(&ent) == 1);
    assert(s_m4c_ptr == (void *)0x2222);

    cfg.f10 = (void *)0x3333;
    s_m4c_ptr = nullptr;
    assert(func_001E36E0(&ent) == 1);
    assert(s_m4c_ptr == (void *)0x3333);
}

int main(int argc, char **argv) {
    test_check_motion_flag();
    test_dispatch_config_actions();
    return 0;
}
