#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialEntityState {
    char pad[0x106];
    unsigned char field_106;
};

float D_004E2960 = -99.9f;

extern "C" {
float func_001D8AB0(SpatialEntityState *self);

static int g_func_26ad60_calls = 0;
static int g_func_1dd650_calls = 0;

void func_26AD60(void *self, int flag) {
    g_func_26ad60_calls++;
    assert(flag == 0x20);
}

float func_1DD650(void *self) {
    g_func_1dd650_calls++;
    return 42.5f;
}
}

static void test_view_check_status_flag_set() {
    g_func_26ad60_calls = 0;
    g_func_1dd650_calls = 0;

    SpatialEntityState entity;
    std::memset(&entity, 0, sizeof(entity));
    entity.field_106 = 1;

    float res = func_001D8AB0(&entity);
    assert(res == -99.9f);
    assert(g_func_26ad60_calls == 1);
    assert(g_func_1dd650_calls == 0);
}

static void test_view_check_status_flag_zero() {
    g_func_26ad60_calls = 0;
    g_func_1dd650_calls = 0;

    SpatialEntityState entity;
    std::memset(&entity, 0, sizeof(entity));
    entity.field_106 = 0;

    float res = func_001D8AB0(&entity);
    assert(res == 42.5f);
    assert(g_func_26ad60_calls == 0);
    assert(g_func_1dd650_calls == 1);
}

int main(int argc, char **argv) {
    test_view_check_status_flag_set();
    test_view_check_status_flag_zero();
    return 0;
}
