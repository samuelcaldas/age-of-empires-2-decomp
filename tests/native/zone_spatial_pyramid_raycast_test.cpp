#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D2DE0(
    void *self, void *mgr, float x0, float y0, float z0, float x1, float y1, float z1,
    void *out1, void *out2
);

static int g_func_1d3310_calls = 0;

int func_123350(float f) {
    return static_cast<int>(f + 0.5f);
}

int func_1D3310(void *self, int x0, int y0, int x1, int y1, void *p1, void *p2) {
    g_func_1d3310_calls++;
    return 1;
}
}

static void test_raycast_flow() {
    g_func_1d3310_calls = 0;
    char zm[0x100];
    int res = func_001D2DE0(zm, nullptr, 0.0f, 0.0f, 0.0f, 10.0f, 10.0f, 0.0f, nullptr, nullptr);
    assert(g_func_1d3310_calls == 1);
    assert(res == 1);
}

int main(int argc, char **argv) {
    test_raycast_flow();
    return 0;
}
