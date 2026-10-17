#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D4C20(void *self, void *node, int *out_x, int *out_y, int tx, int ty);
}

static void test_resolve_target_level0() {
    char zm[0x100];
    char node[0x30];
    std::memset(zm, 0, sizeof(zm));
    std::memset(node, 0, sizeof(node));

    *reinterpret_cast<int *>(node + 0x4) = 15;
    *reinterpret_cast<int *>(node + 0x8) = 25;
    *reinterpret_cast<int *>(node + 0xC) = 0; // level 0

    int ox = 0, oy = 0;
    func_001D4C20(zm, node, &ox, &oy, 0, 0);
    assert(ox == 15);
    assert(oy == 25);
}

static void test_resolve_target_higher_level() {
    char zm[0x100];
    char node[0x30];
    std::memset(zm, 0, sizeof(zm));
    std::memset(node, 0, sizeof(node));

    *reinterpret_cast<int *>(node + 0x4) = 3;
    *reinterpret_cast<int *>(node + 0x8) = 5;
    *reinterpret_cast<int *>(node + 0xC) = 2; // level 2 (<< 2)

    int ox = 0, oy = 0;
    func_001D4C20(zm, node, &ox, &oy, 0, 0);
    assert(ox == 12);
    assert(oy == 20);
}

int main(int argc, char **argv) {
    test_resolve_target_level0();
    test_resolve_target_higher_level();
    return 0;
}
