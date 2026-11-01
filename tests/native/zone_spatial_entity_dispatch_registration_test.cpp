#include <cassert>
#include "zone_spatial_entity_dispatch_registration.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

void *D_004D6F34 = (void *)0x12345678;

static void *g_last_mgr = nullptr;
static void *g_last_ent = nullptr;
static int g_last_flag = -1;

extern "C" void func_1EE040(void *mgr, void *ent, int flag) {
    g_last_mgr = mgr;
    g_last_ent = ent;
    g_last_flag = flag;
}

// In SpatialEntity, Method270 is at offset 0x278 in the vtable
// Let's create an object whose vtable has a function pointer at index 0x278 / 4 = 156
typedef int (*Method270Fn)(void *);

static int MockMethod270_True(void *) {
    return 1;
}

static int MockMethod270_False(void *) {
    return 0;
}

struct MockSpatialEntity {
    void **vtable;
};

static void *vtable_true[200];
static void *vtable_false[200];

int main() {
    vtable_true[0x268 / 4] = (void *)(Method270Fn)MockMethod270_True;
    vtable_false[0x268 / 4] = (void *)(Method270Fn)MockMethod270_False;

    MockSpatialEntity mock1;
    mock1.vtable = vtable_true;

    func_001DD790((SpatialEntity *)&mock1);
    assert(g_last_mgr == (void *)0x12345678);
    assert(g_last_ent == &mock1);
    assert(g_last_flag == 0x10);

    MockSpatialEntity mock0;
    mock0.vtable = vtable_false;

    func_001DD790((SpatialEntity *)&mock0);
    assert(g_last_mgr == (void *)0x12345678);
    assert(g_last_ent == &mock0);
    assert(g_last_flag == 0);

    return 0;
}
