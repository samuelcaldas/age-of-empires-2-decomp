#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D4E70(void *self, int p1, int p2, int p3);

static char g_grid_pool[32][64];
static int g_grid_idx = 0;

void *func_100730(int size) {
    assert(g_grid_idx < 32);
    return g_grid_pool[g_grid_idx++];
}
}

static void test_alloc_grid_flow() {
    g_grid_idx = 0;
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xE4) = 4; // width 4
    *reinterpret_cast<int *>(zm + 0xE8) = 8; // height 8

    func_001D4E70(zm, 0, 0, 0);

    // 1 call for row pointers + 4 calls for rows = 5 calls
    assert(g_grid_idx == 5);
    assert(*reinterpret_cast<void ***>(zm + 0x11C) != nullptr);
}

int main(int argc, char **argv) {
    test_alloc_grid_flow();
    return 0;
}
