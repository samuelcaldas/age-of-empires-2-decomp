#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D3C70(void *self, void *mgr, float x, float y, float r1, float r2);

static int g_func_1d3310_calls = 0;

int func_123350(float f) {
    return static_cast<int>(f + 0.5f);
}

int func_1D3310(void *self, int x0, int y0, int x1, int y1, void *p1, void *p2) {
    g_func_1d3310_calls++;
    return 1;
}
}

static void test_search_radius_flow() {
    g_func_1d3310_calls = 0;
    char zm[0x100];
    int res = func_001D3C70(zm, nullptr, 10.0f, 20.0f, 2.0f, 3.0f);
    assert(g_func_1d3310_calls == 1);
    assert(res == 1);
}

int main(int argc, char **argv) {
    test_search_radius_flow();
    return 0;
}
