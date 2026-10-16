#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D5EB0(void *self, int p1);

static int g_func_117cac_calls = 0;

void *func_117CAC(void *dst, int val, int size) {
    g_func_117cac_calls++;
    std::memset(dst, val, size);
    return dst;
}
}

static void test_build_graph_flow() {
    g_func_117cac_calls = 0;
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char row0[16], row1[16];
    std::memset(row0, 0xFF, sizeof(row0));
    std::memset(row1, 0xFF, sizeof(row1));

    char *grid[2] = { row0, row1 };
    *reinterpret_cast<char ***>(zm + 0x11C) = grid;
    *reinterpret_cast<int *>(zm + 0xE4) = 2; // width
    *reinterpret_cast<int *>(zm + 0xE8) = 16; // height

    int res = func_001D5EB0(zm, 0);
    assert(res == 1);
    assert(g_func_117cac_calls == 2);
    assert(row0[0] == 0);
    assert(row1[0] == 0);
}

int main(int argc, char **argv) {
    test_build_graph_flow();
    return 0;
}
