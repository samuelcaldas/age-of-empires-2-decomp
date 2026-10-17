#include <cassert>
#include <cstddef>
#include <cstring>
#include <cstdlib>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialBufferHolder {
    void *buffer;
};

extern "C" {
int func_001D80D0(SpatialBufferHolder *self, unsigned int w, unsigned int h);
}

static void test_alloc_buffer() {
    SpatialBufferHolder holder;
    holder.buffer = nullptr;

    int res = func_001D80D0(&holder, 4, 5);
    assert(res == 1);
    assert(holder.buffer != nullptr);

    delete[] reinterpret_cast<void **>(holder.buffer);
}

int main(int argc, char **argv) {
    test_alloc_buffer();
    return 0;
}
