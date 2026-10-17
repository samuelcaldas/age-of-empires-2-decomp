#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialItemVector {
    char pad[0xC];
    int count;
    char pad2[4];
    void **items;
};

extern "C" {
void func_001D8340(SpatialItemVector *self, void *item);
}

static void test_allocator_push() {
    void *item_buf[4];
    std::memset(item_buf, 0, sizeof(item_buf));

    SpatialItemVector vec;
    vec.count = 0;
    vec.items = item_buf;

    func_001D8340(&vec, reinterpret_cast<void *>(0x1234));
    assert(vec.count == 1);
    assert(vec.items[0] == reinterpret_cast<void *>(0x1234));

    func_001D8340(&vec, reinterpret_cast<void *>(0x5678));
    assert(vec.count == 2);
    assert(vec.items[1] == reinterpret_cast<void *>(0x5678));
}

int main(int argc, char **argv) {
    test_allocator_push();
    return 0;
}
