#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void *func_001D7AA0(void *self, int arg);
}

struct SpatialNode {
    int f0;
    int f4;
    int f8;
};

static void test_spatial_node_ctor() {
    SpatialNode node;
    node.f0 = 123;
    node.f4 = 456;
    node.f8 = 789;

    void *res = func_001D7AA0(&node, 42);
    assert(res == &node);
    assert(node.f0 == 0);
    assert(node.f4 == 0);
    assert(node.f8 == 42);
}

int main(int argc, char **argv) {
    test_spatial_node_ctor();
    return 0;
}
