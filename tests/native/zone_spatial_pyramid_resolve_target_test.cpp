#include <cassert>
#include <cstddef>
#include <cstring>
#include <cmath>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D4C20(void *self, void *node, int *out_x, int *out_y, int tx, int ty);

// Test double for func_1D4E00
int func_1D4E00(void *self, int target_x, int target_y, int level, int child_x, int child_y) {
    // Return Manhattan distance to target as cost
    int dx = target_x - child_x;
    if (dx < 0) dx = -dx;
    int dy = target_y - child_y;
    if (dy < 0) dy = -dy;
    return dx + dy;
}
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

    // Node at (1, 1) at level 1.
    // Children at level 0: (2, 2), (2, 3), (3, 2), (3, 3).
    // Target is (3, 3).
    *reinterpret_cast<int *>(node + 0x4) = 1;
    *reinterpret_cast<int *>(node + 0x8) = 1;
    *reinterpret_cast<int *>(node + 0xC) = 1; // level 1

    int ox = 0, oy = 0;
    func_001D4C20(zm, node, &ox, &oy, 3, 3);
    assert(ox == 3);
    assert(oy == 3);
}

int main(int argc, char **argv) {
    test_resolve_target_level0();
    test_resolve_target_higher_level();
    return 0;
}
