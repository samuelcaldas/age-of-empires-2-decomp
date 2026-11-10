#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_entity_setup.h"

static int s_func_1E3710_calls = 0;
static void *s_func_1E3710_last_self = NULL;

static int s_func_151B90_calls = 0;
static void *s_func_151B90_last_self = NULL;
static void *s_func_151B90_last_sub = NULL;

extern "C" {
void func_1E3710(void *self) {
    s_func_1E3710_calls++;
    s_func_1E3710_last_self = self;
}

void func_151B90(void *self, void *sub) {
    s_func_151B90_calls++;
    s_func_151B90_last_self = self;
    s_func_151B90_last_sub = sub;
}
}

int main() {
    int dummy_entity = 123;
    int dummy_sub = 456;

    // Test case 1: sub is non-null
    func_001DC0B0(reinterpret_cast<SpatialEntity *>(&dummy_entity), &dummy_sub);
    assert(s_func_1E3710_calls == 1);
    assert(s_func_1E3710_last_self == &dummy_entity);
    assert(s_func_151B90_calls == 1);
    assert(s_func_151B90_last_self == &dummy_entity);
    assert(s_func_151B90_last_sub == &dummy_sub);

    // Test case 2: sub is null
    func_001DC0B0(reinterpret_cast<SpatialEntity *>(&dummy_entity), NULL);
    assert(s_func_1E3710_calls == 2);
    assert(s_func_1E3710_last_self == &dummy_entity);
    assert(s_func_151B90_calls == 1); // Not called when sub is null

    return 0;
}
