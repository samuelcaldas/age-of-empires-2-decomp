#include <cassert>
#include <cstdlib>
#include <cstring>
#include "zone_spatial_grid_transfer_bucket.h"

extern "C" {
void *func_100730(unsigned int size) {
    return std::malloc(size);
}

void func_100630(void *ptr) {
    std::free(ptr);
}

void *func_117AF8(void *dst, const void *src, unsigned int size) {
    return std::memcpy(dst, src, size);
}
}

struct Node {
    char pad[0xC];
    Node *next;
};

struct Bucket {
    char pad[0x20];
    Node *head;
    char pad_64[0x40];
    void **items;
    int count;
    int capacity;
};

struct SpatialGridMock {
    char pad[0x20];
    Bucket buckets[2];
};

int main() {
    SpatialGridMock mock;
    std::memset(&mock, 0, sizeof(mock));

    Node n2;
    std::memset(&n2, 0, sizeof(n2));
    n2.next = NULL;

    Node n1;
    std::memset(&n1, 0, sizeof(n1));
    n1.next = &n2;

    mock.buckets[0].head = &n1;

    SpatialGrid *self = reinterpret_cast<SpatialGrid *>(&mock);

    func_001E67B0(self, 0);

    assert(mock.buckets[0].head == NULL);
    assert(mock.buckets[0].count == 2);
    assert(mock.buckets[0].capacity >= 2);
    assert(mock.buckets[0].items[0] == &n1);
    assert(mock.buckets[0].items[1] == &n2);

    std::free(mock.buckets[0].items);

    return 0;
}
