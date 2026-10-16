#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D4440(void *self, void *node);
}

static void test_check_edge_flow() {
    char zm[0x100];
    char node[0x30];
    char parent[0x30];
    std::memset(zm, 0, sizeof(zm));
    std::memset(node, 0, sizeof(node));
    std::memset(parent, 0, sizeof(parent));

    // Case 1: no parent -> 0
    assert(func_001D4440(zm, node) == 0);

    // Case 2: parent present
    *reinterpret_cast<void **>(node + 0x24) = parent;
    *reinterpret_cast<int *>(node + 0xC) = 2; // level 2
    *reinterpret_cast<int *>(parent + 0xC) = 1; // parent level 1 < node level 2
    assert(func_001D4440(zm, node) == 1);
}

int main(int argc, char **argv) {
    test_check_edge_flow();
    return 0;
}
