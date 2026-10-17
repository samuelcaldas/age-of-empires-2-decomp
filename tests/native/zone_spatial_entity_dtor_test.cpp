#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialEntityDestructor {
    void *vtable;
};

void *__vt__004D92B0 = reinterpret_cast<void *>(0x004D92B0);

extern "C" {
void *func_001D84B0(SpatialEntityDestructor *self, int flag);

static int g_func_1d8480_calls = 0;
static int g_func_194e20_calls = 0;
static int g_func_100670_calls = 0;

void func_1D8480(void *self, void *arg) {
    g_func_1d8480_calls++;
    assert(arg == nullptr);
}

void func_194E20(void *self, int flag) {
    g_func_194e20_calls++;
    assert(flag == 0);
}

void func_100670(void *ptr) {
    g_func_100670_calls++;
}
}

static void test_entity_dtor_null() {
    g_func_1d8480_calls = 0;
    g_func_194e20_calls = 0;
    g_func_100670_calls = 0;

    assert(func_001D84B0(nullptr, 0) == nullptr);
    assert(g_func_1d8480_calls == 0);
    assert(g_func_194e20_calls == 0);
    assert(g_func_100670_calls == 0);
}

static void test_entity_dtor_with_delete() {
    g_func_1d8480_calls = 0;
    g_func_194e20_calls = 0;
    g_func_100670_calls = 0;

    SpatialEntityDestructor entity;
    entity.vtable = nullptr;

    void *res = func_001D84B0(&entity, 1);
    assert(res == &entity);
    assert(entity.vtable == &__vt__004D92B0);
    assert(g_func_1d8480_calls == 1);
    assert(g_func_194e20_calls == 1);
    assert(g_func_100670_calls == 1);
}

static void test_entity_dtor_without_delete() {
    g_func_1d8480_calls = 0;
    g_func_194e20_calls = 0;
    g_func_100670_calls = 0;

    SpatialEntityDestructor entity;
    entity.vtable = nullptr;

    void *res = func_001D84B0(&entity, 0);
    assert(res == &entity);
    assert(entity.vtable == &__vt__004D92B0);
    assert(g_func_1d8480_calls == 1);
    assert(g_func_194e20_calls == 1);
    assert(g_func_100670_calls == 0);
}

int main(int argc, char **argv) {
    test_entity_dtor_null();
    test_entity_dtor_with_delete();
    test_entity_dtor_without_delete();
    return 0;
}
