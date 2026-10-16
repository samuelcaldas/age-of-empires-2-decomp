#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialEntityState {
    char pad[0x104];
    short field_104;
    char field_106;
    char field_107;
};

extern "C" {
int func_001D8520(SpatialEntityState *self, void *arg1, void *arg2, float x, float y, float z);

static int g_func_194e90_calls = 0;

void func_194E90(void *self, void *arg1, void *arg2, float x, float y, float z) {
    g_func_194e90_calls++;
    assert(x == 10.0f);
    assert(y == 20.0f);
    assert(z == 30.0f);
}
}

static void test_update_pos_fields() {
    g_func_194e90_calls = 0;
    SpatialEntityState entity;
    std::memset(&entity, 0, sizeof(entity));

    int res = func_001D8520(&entity, nullptr, nullptr, 10.0f, 20.0f, 30.0f);
    assert(res == 1);
    assert(entity.field_106 == 1);
    assert(entity.field_104 == -1);
    assert(entity.field_107 == 0);
    assert(g_func_194e90_calls == 1);
}

int main(int argc, char **argv) {
    test_update_pos_fields();
    return 0;
}
