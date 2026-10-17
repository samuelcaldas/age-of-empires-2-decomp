#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D51B0(void *self, int x0, int y0, int x1, int y1, void *out1, void *out2);

static int g_func_1d5610_calls = 0;

int func_1D5610(void *self, int x0, int y0, int x1, int y1, void *out1, void *out2) {
    g_func_1d5610_calls++;
    return 1;
}
}

static void test_search_path_flow() {
    g_func_1d5610_calls = 0;
    char zm[0x100];
    int res = func_001D51B0(zm, 0, 0, 5, 5, nullptr, nullptr);
    assert(g_func_1d5610_calls == 1);
    assert(res == 1);
}

int main(int argc, char **argv) {
    test_search_path_flow();
    return 0;
}
