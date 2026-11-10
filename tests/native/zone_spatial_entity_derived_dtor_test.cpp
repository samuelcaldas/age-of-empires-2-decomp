#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_entity_derived_dtor.h"

void *D_004D96B0 = (void *)0x1111;
void *D_004D7A90 = (void *)0x2222;

static int s_func_001DC0B0_calls = 0;
static int s_func_2639D0_calls = 0;
static int s_func_100670_calls = 0;
static void *s_last_001DC0B0_vtable = NULL;
static void *s_last_2639D0_vtable = NULL;
static void *s_freed_ptr = NULL;

extern "C" {
void func_001DC0B0(void *self, void *sub) {
    (void)sub;
    s_func_001DC0B0_calls++;
    s_last_001DC0B0_vtable = *(void **)self;
}

void func_2639D0(void *self, int flag) {
    (void)flag;
    s_func_2639D0_calls++;
    s_last_2639D0_vtable = *(void **)self;
}

void func_100670(void *ptr) {
    s_func_100670_calls++;
    s_freed_ptr = ptr;
    std::free(ptr);
}
}

int main() {
    // Test 1: self == NULL returns NULL without doing anything
    void *r0 = func_001DC100(NULL, 1);
    assert(r0 == NULL);
    assert(s_func_001DC0B0_calls == 0);
    assert(s_func_2639D0_calls == 0);
    assert(s_func_100670_calls == 0);

    // Test 2: stack allocated object with flags == 0 (no free)
    void *obj_stack[4];
    std::memset(obj_stack, 0, sizeof(obj_stack));
    SpatialEntity *se_stack = (SpatialEntity *)obj_stack;

    void *r1 = func_001DC100(se_stack, 0);
    assert(r1 == se_stack);
    assert(s_func_001DC0B0_calls == 1);
    assert(s_last_001DC0B0_vtable == &D_004D96B0);
    assert(s_func_2639D0_calls == 1);
    assert(s_last_2639D0_vtable == &D_004D7A90);
    assert(s_func_100670_calls == 0);

    // Test 3: heap allocated object with flags > 0 (triggers func_100670)
    void **obj_heap = (void **)std::malloc(sizeof(void *) * 4);
    std::memset(obj_heap, 0, sizeof(void *) * 4);
    SpatialEntity *se_heap = (SpatialEntity *)obj_heap;

    void *r2 = func_001DC100(se_heap, 1);
    assert(r2 == se_heap);
    assert(s_func_001DC0B0_calls == 2);
    assert(s_func_2639D0_calls == 2);
    assert(s_func_100670_calls == 1);
    assert(s_freed_ptr == se_heap);

    return 0;
}
