#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D48B0(void *self, void *node, int *out_x, int *out_y);
}

static void test_connect_nodes_flow() {
    char zm[0x100];
    char node[0x30];
    char parent[0x30];
    std::memset(zm, 0, sizeof(zm));
    std::memset(node, 0, sizeof(node));
    std::memset(parent, 0, sizeof(parent));

    // Setup map zone bounds
    *reinterpret_cast<int *>(zm + 0xEC) = 100; // max_x
    *reinterpret_cast<int *>(zm + 0xF0) = 100; // max_y

    int out_x = -1;
    int out_y = -1;

    // Case 1: no parent -> 0
    assert(func_001D48B0(zm, node, &out_x, &out_y) == 0);

    // Case 2: parent present, p_lvl < n_lvl, lvl 0
    *reinterpret_cast<void **>(node + 0x24) = parent;
    *reinterpret_cast<int *>(node + 0x4) = 5;
    *reinterpret_cast<int *>(node + 0x8) = 6;
    *reinterpret_cast<int *>(node + 0xC) = 2; // level 2
    *reinterpret_cast<unsigned char *>(node + 0x28) = 1; // dir 1

    *reinterpret_cast<int *>(parent + 0x4) = 10;
    *reinterpret_cast<int *>(parent + 0x8) = 12;
    *reinterpret_cast<int *>(parent + 0xC) = 0; // parent level 0 < node level 2

    int res = func_001D48B0(zm, node, &out_x, &out_y);
    assert(res == 1);
    assert(out_x == 10);
    assert(out_y == 24); // node->y (6) << node->level (2) = 24

    // Case 3: dir = 8 (south)
    *reinterpret_cast<unsigned char *>(node + 0x28) = 8;
    res = func_001D48B0(zm, node, &out_x, &out_y);
    assert(res == 1);
    assert(out_x == 10);
    assert(out_y == ((6 + 1) << 2) - 1); // 27

    // Case 4: dir = 2 (east)
    *reinterpret_cast<unsigned char *>(node + 0x28) = 2;
    res = func_001D48B0(zm, node, &out_x, &out_y);
    assert(res == 1);
    assert(out_y == 12);
    assert(out_x == (5 << 2)); // 20

    // Case 5: dir = 4 (west)
    *reinterpret_cast<unsigned char *>(node + 0x28) = 4;
    res = func_001D48B0(zm, node, &out_x, &out_y);
    assert(res == 1);
    assert(out_y == 12);
    assert(out_x == ((5 + 1) << 2) - 1); // 23

    // Case 6: clamping to max_x / max_y
    *reinterpret_cast<int *>(zm + 0xEC) = 15;
    *reinterpret_cast<int *>(zm + 0xF0) = 18;
    res = func_001D48B0(zm, node, &out_x, &out_y);
    assert(res == 1);
    assert(out_x == 15);
    assert(out_y == 12);
}

int main(int argc, char **argv) {
    test_connect_nodes_flow();
    return 0;
}
