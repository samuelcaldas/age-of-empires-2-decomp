#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D2140(void *self);

static int g_func_1d21b0_calls = 0;
static std::vector<std::pair<int, int>> g_coords;

int func_1D21B0(void *self, int level, int x, int y) {
    g_func_1d21b0_calls++;
    assert(level == 3);
    g_coords.push_back({x, y});
    return 1;
}
}

static void test_reset_level3_flow() {
    g_func_1d21b0_calls = 0;
    g_coords.clear();

    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xD0) = 1; // max_x = 1 (iterates 1, 0 -> 2 values)
    *reinterpret_cast<int *>(zm + 0xE0) = 2; // max_y = 2 (iterates 2, 1, 0 -> 3 values)

    func_001D2140(zm);

    assert(g_func_1d21b0_calls == 6);
    assert(g_coords.size() == 6);
}

int main(int argc, char **argv) {
    test_reset_level3_flow();
    return 0;
}
