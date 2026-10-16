#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialTreeManager {
    void *root;
    char pad[0x10];
    void *buffer;
};

extern "C" {
void *func_001D8160(SpatialTreeManager *self, int flag);

static int g_func_100630_calls = 0;
static int g_func_1d8070_calls = 0;
static int g_func_100670_calls = 0;

void func_100630(void *ptr) {
    g_func_100630_calls++;
}

void *func_1D8070(void *self, int flag) {
    g_func_1d8070_calls++;
    assert(flag == 1);
    return self;
}

void func_100670(void *ptr) {
    g_func_100670_calls++;
}
}

static void test_manager_dtor_null() {
    g_func_100630_calls = 0;
    g_func_1d8070_calls = 0;
    g_func_100670_calls = 0;

    assert(func_001D8160(nullptr, 0) == nullptr);
    assert(g_func_100630_calls == 0);
    assert(g_func_1d8070_calls == 0);
    assert(g_func_100670_calls == 0);
}

static void test_manager_dtor_flow() {
    g_func_100630_calls = 0;
    g_func_1d8070_calls = 0;
    g_func_100670_calls = 0;

    SpatialTreeManager mgr;
    mgr.root = reinterpret_cast<void *>(0x1111);
    mgr.buffer = reinterpret_cast<void *>(0x2222);

    void *res = func_001D8160(&mgr, 1);
    assert(res == &mgr);
    assert(g_func_100630_calls == 1);
    assert(g_func_1d8070_calls == 1);
    assert(g_func_100670_calls == 1);
}

int main(int argc, char **argv) {
    test_manager_dtor_null();
    test_manager_dtor_flow();
    return 0;
}
