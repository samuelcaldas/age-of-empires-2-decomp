#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialTreeNode {
    void *buffer;
    SpatialTreeNode *child;
};

extern "C" {
void *func_001D8070(SpatialTreeNode *self, int flag);

static int g_func_100630_calls = 0;
static int g_func_100670_calls = 0;

void func_100630(void *ptr) {
    g_func_100630_calls++;
}

void func_100670(void *ptr) {
    g_func_100670_calls++;
}
}

static void test_tree_node_dtor_null() {
    g_func_100630_calls = 0;
    g_func_100670_calls = 0;
    assert(func_001D8070(nullptr, 0) == nullptr);
    assert(g_func_100630_calls == 0);
    assert(g_func_100670_calls == 0);
}

static void test_tree_node_dtor_recursive() {
    g_func_100630_calls = 0;
    g_func_100670_calls = 0;

    SpatialTreeNode child;
    child.buffer = reinterpret_cast<void *>(0x1000);
    child.child = nullptr;

    SpatialTreeNode parent;
    parent.buffer = reinterpret_cast<void *>(0x2000);
    parent.child = &child;

    void *res = func_001D8070(&parent, 1);
    assert(res == &parent);
    // Should have freed both parent.buffer and child.buffer
    assert(g_func_100630_calls == 2);
    // Since flag=1 on parent, and child is called with flag=1:
    // Both child and parent get operator delete called
    assert(g_func_100670_calls == 2);
}

static void test_tree_node_dtor_no_delete() {
    g_func_100630_calls = 0;
    g_func_100670_calls = 0;

    SpatialTreeNode node;
    node.buffer = reinterpret_cast<void *>(0x3000);
    node.child = nullptr;

    void *res = func_001D8070(&node, 0);
    assert(res == &node);
    assert(g_func_100630_calls == 1);
    assert(g_func_100670_calls == 0);
}

int main(int argc, char **argv) {
    test_tree_node_dtor_null();
    test_tree_node_dtor_recursive();
    test_tree_node_dtor_no_delete();
    return 0;
}
