#include <cassert>
#include <cstdlib>
#include <cstring>

bool fail_allocation = false;
unsigned int allocation_count = 0;
static void *allocations[16] = {};

extern "C" void *func_100730(int size) {
    if (fail_allocation) return 0;
    assert(size > 0 && allocation_count < 16);
    void *result = std::malloc(static_cast<unsigned int>(size));
    assert(result);
    std::memset(result, 0x5a, static_cast<unsigned int>(size));
    allocations[allocation_count++] = result;
    return result;
}

extern "C" void func_00100630(void *) {
    // Keep allocations live to detect source/destination aliasing during growth.
}

void release_allocations() {
    for (unsigned int index = 0; index < allocation_count; index++) {
        std::free(allocations[index]);
    }
    allocation_count = 0;
}
