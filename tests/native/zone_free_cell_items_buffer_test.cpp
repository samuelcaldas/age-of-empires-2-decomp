#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D0EC0(void *self, void *bucket, void *buffer);
}

static void test_push_buffer_to_free_list() {
    char bucket[68];
    std::memset(bucket, 0, sizeof(bucket));

    char buf1[32] = {}, buf2[32] = {};
    *reinterpret_cast<void **>(bucket + 0x18) = nullptr; // free list empty
    *reinterpret_cast<int *>(bucket + 0x28) = 0; // free count = 0

    // Push buf1
    func_001D0EC0(nullptr, bucket, buf1);

    assert(*reinterpret_cast<void **>(bucket + 0x18) == buf1);
    assert(*reinterpret_cast<void **>(buf1) == nullptr); // next is null
    assert(*reinterpret_cast<int *>(bucket + 0x28) == 1);

    // Push buf2
    func_001D0EC0(nullptr, bucket, buf2);

    assert(*reinterpret_cast<void **>(bucket + 0x18) == buf2); // head is buf2
    assert(*reinterpret_cast<void **>(buf2) == buf1); // buf2 points to buf1 (LIFO)
    assert(*reinterpret_cast<int *>(bucket + 0x28) == 2);
}

int main(int argc, char **argv) {
    test_push_buffer_to_free_list();
    return 0;
}
