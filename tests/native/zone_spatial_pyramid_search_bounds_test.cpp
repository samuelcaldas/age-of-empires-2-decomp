#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D3EB0(
    void *self, int level, int x, int y, float f12, float f13, float f14, float f15,
    void *out1
);
}

static void test_search_bounds_flow() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xF4) = 8;
    *reinterpret_cast<int *>(zm + 0xF8) = 16;
    *reinterpret_cast<int *>(zm + 0xFC) = 32;
    *reinterpret_cast<int *>(zm + 0x100) = 48;

    int res = func_001D3EB0(zm, 2, 3, 5, 0.0f, 0.0f, 0.0f, 0.0f, nullptr);
    assert(res == 1);

    int oob = func_001D3EB0(zm, 2, 1, 5, 0.0f, 0.0f, 0.0f, 0.0f, nullptr);
    assert(oob == 0);
}

int main(int argc, char **argv) {
    test_search_bounds_flow();
    return 0;
}
