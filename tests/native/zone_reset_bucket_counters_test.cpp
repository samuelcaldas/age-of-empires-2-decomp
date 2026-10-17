#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D0EE0(void *self, void *bucket);
}

static void test_reset_bucket_counters_flow() {
    char bucket[0x50];
    std::memset(bucket, 0xFF, sizeof(bucket)); // fill with non-zero

    func_001D0EE0(nullptr, bucket);

    assert(*reinterpret_cast<int *>(bucket + 0x34) == 0);
    assert(*reinterpret_cast<int *>(bucket + 0x38) == 0);
    assert(*reinterpret_cast<int *>(bucket + 0x3C) == 0);
    assert(*reinterpret_cast<int *>(bucket + 0x40) == 0);
}

int main(int argc, char **argv) {
    test_reset_bucket_counters_flow();
    return 0;
}
