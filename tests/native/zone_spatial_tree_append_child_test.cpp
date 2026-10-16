#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialTreeNode {
    void *buffer;
    SpatialTreeNode *child;
};

extern "C" {
void func_001D8120(SpatialTreeNode *self, SpatialTreeNode *child);
}

static void test_append_to_leaf() {
    SpatialTreeNode root = { nullptr, nullptr };
    SpatialTreeNode child = { nullptr, nullptr };

    func_001D8120(&root, &child);
    assert(root.child == &child);
    assert(child.child == nullptr);
}

static void test_append_recursive() {
    SpatialTreeNode root = { nullptr, nullptr };
    SpatialTreeNode node1 = { nullptr, nullptr };
    SpatialTreeNode node2 = { nullptr, nullptr };

    root.child = &node1;

    func_001D8120(&root, &node2);
    assert(root.child == &node1);
    assert(node1.child == &node2);
    assert(node2.child == nullptr);
}

int main(int argc, char **argv) {
    test_append_to_leaf();
    test_append_recursive();
    return 0;
}
