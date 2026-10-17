#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D5610(void *self, int x0, int y0, int x1, int y1, void *out1, void *out2);

static int g_func_1d5a30_calls = 0;

int func_1D5A30(void *self, int x, int y) {
    g_func_1d5a30_calls++;
    return (x == 5 && y == 5) ? 1 : 0;
}
}

static void test_step_path_hit() {
    g_func_1d5a30_calls = 0;
    char zm[0x100];
    int res = func_001D5610(zm, 5, 5, 10, 10, nullptr, nullptr);
    assert(g_func_1d5a30_calls == 1);
    assert(res == 1);
}

int main(int argc, char **argv) {
    test_step_path_hit();
    return 0;
}
