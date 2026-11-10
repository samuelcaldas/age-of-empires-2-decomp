#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_entity_update_sub_entity.h"

struct SubEntityInfo {
    unsigned char type;
};

static int s_func_266780_calls = 0;
static void *s_mock_sub_ptr = NULL;
static int s_methodC4_calls = 0;
static float s_last_methodC4_speed = 0.0f;

extern "C" {
void *func_266780(void *self) {
    (void)self;
    s_func_266780_calls++;
    return s_mock_sub_ptr;
}
}

static void mock_method_c4(void *self, float speed) {
    (void)self;
    s_methodC4_calls++;
    s_last_methodC4_speed = speed;
}

struct MockSubEntity {
    void **vtable;
    SubEntityInfo *info;
};

struct SpatialEntity {
    char pad[0x7C];
    float f7C;
};

int main() {
    SpatialEntity entity;
    std::memset(&entity, 0, sizeof(entity));
    entity.f7C = 3.5f;

    // Test 1: func_266780 returns NULL -> returns NULL, MethodC4 not called
    s_mock_sub_ptr = NULL;
    s_func_266780_calls = 0;
    s_methodC4_calls = 0;
    void *r0 = func_001DCA30(&entity);
    assert(r0 == NULL);
    assert(s_func_266780_calls == 1);
    assert(s_methodC4_calls == 0);

    // Vtable with MethodC4 at offset 0xC4 (index 0xC4 / 4 = 49)
    void *vtable[60];
    std::memset(vtable, 0, sizeof(vtable));
    vtable[0xC4 / sizeof(void *)] = (void *)mock_method_c4;

    SubEntityInfo info;
    std::memset(&info, 0, sizeof(info));

    MockSubEntity sub;
    std::memset(&sub, 0, sizeof(sub));
    sub.vtable = vtable;
    sub.info = &info;

    // Test 2: type < 0x1E (e.g. 10) -> returns sub, MethodC4 not called
    info.type = 10;
    s_mock_sub_ptr = &sub;
    s_func_266780_calls = 0;
    s_methodC4_calls = 0;
    void *r1 = func_001DCA30(&entity);
    assert(r1 == &sub);
    assert(s_func_266780_calls == 1);
    assert(s_methodC4_calls == 0);

    // Test 3: type >= 0x1E (e.g. 0x1E = 30) -> returns sub, MethodC4 called with f7C
    info.type = 0x1E;
    s_func_266780_calls = 0;
    s_methodC4_calls = 0;
    void *r2 = func_001DCA30(&entity);
    assert(r2 == &sub);
    assert(s_func_266780_calls == 1);
    assert(s_methodC4_calls == 1);
    assert(s_last_methodC4_speed == 3.5f);

    return 0;
}
