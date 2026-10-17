#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D48B0(void *self, void *node, void *p2, void *p3);
}

static void test_connect_nodes_flow() {
    char zm[0x100];
    char node[0x30];
    char parent[0x30];
    std::memset(zm, 0, sizeof(zm));
    std::memset(node, 0, sizeof(node));
    std::memset(parent, 0, sizeof(parent));

    // Case 1: no parent -> 0
    assert(func_001D48B0(zm, node, nullptr, nullptr) == 0);

    // Case 2: parent present
    *reinterpret_cast<void **>(node + 0x24) = parent;
    *reinterpret_cast<int *>(node + 0xC) = 2; // level 2
    *reinterpret_cast<int *>(parent + 0xC) = 1; // parent level 1 < node level 2
    assert(func_001D48B0(zm, node, nullptr, nullptr) == 1);
}

int main(int argc, char **argv) {
    test_connect_nodes_flow();
    return 0;
}
