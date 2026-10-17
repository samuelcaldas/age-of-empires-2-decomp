#include <cassert>
#include <cstddef>
#include <cstring>
#include <cstdlib>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialTreeNode {
    void *buffer;
    SpatialTreeNode *child;
};

struct SpatialChunkAllocator {
    SpatialTreeNode *root;    // 0x0
    int elem_size;            // 0x4
    int chunk_capacity;       // 0x8
    int count;                // 0xC
    int capacity;             // 0x10
    void **items;             // 0x14
    unsigned char clear_flag; // 0x18
};

extern "C" {
void *func_001D81E0(SpatialChunkAllocator *self);

void *func_100730(unsigned int size) {
    return std::malloc(size);
}

void *func_117AF8(void *dst, const void *src, unsigned int size) {
    return std::memcpy(dst, src, size);
}

void func_100630(void *ptr) {
    std::free(ptr);
}

void *func_100850(unsigned int size) {
    return std::malloc(size);
}

void func_1D8120(void *root, void *node) {
    SpatialTreeNode *r = reinterpret_cast<SpatialTreeNode *>(root);
    SpatialTreeNode *n = reinterpret_cast<SpatialTreeNode *>(node);
    while (r->child != nullptr) {
        r = r->child;
    }
    r->child = n;
}

int func_1D80D0(void *node, unsigned int w, unsigned int h) {
    SpatialTreeNode *n = reinterpret_cast<SpatialTreeNode *>(node);
    n->buffer = std::malloc(w * h);
    return 1;
}

void *func_117CAC(void *dst, int val, unsigned int size) {
    return std::memset(dst, val, size);
}
}

static void test_allocator_pop_existing() {
    char elem[16];
    std::memset(elem, 0xAB, sizeof(elem));
    void *items[2] = { elem, nullptr };

    SpatialChunkAllocator alloc;
    std::memset(&alloc, 0, sizeof(alloc));
    alloc.elem_size = 16;
    alloc.count = 1;
    alloc.capacity = 2;
    alloc.items = items;
    alloc.clear_flag = 1;

    void *item = func_001D81E0(&alloc);
    assert(item == elem);
    assert(alloc.count == 0);
    // Should be zeroed since clear_flag = 1
    assert(elem[0] == 0);
    assert(elem[15] == 0);
}

static void test_allocator_pop_empty_allocates_chunk() {
    SpatialChunkAllocator alloc;
    std::memset(&alloc, 0, sizeof(alloc));
    alloc.elem_size = 16;
    alloc.chunk_capacity = 4;
    alloc.count = 0;
    alloc.capacity = 0;
    alloc.items = nullptr;
    alloc.clear_flag = 0;

    void *item = func_001D81E0(&alloc);
    assert(item != nullptr);
    assert(alloc.count == 3); // 4 allocated, 1 popped -> 3 remain
    assert(alloc.root != nullptr);
    assert(alloc.items != nullptr);

    // Clean up allocated resources
    std::free(alloc.root->buffer);
    std::free(alloc.root);
    std::free(alloc.items);
}

int main(int argc, char **argv) {
    test_allocator_pop_existing();
    test_allocator_pop_empty_allocates_chunk();
    return 0;
}
