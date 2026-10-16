#include <cassert>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

unsigned int D_00492570[32] = {
    1u << 0,  1u << 1,  1u << 2,  1u << 3,
    1u << 4,  1u << 5,  1u << 6,  1u << 7,
    1u << 8,  1u << 9,  1u << 10, 1u << 11,
    1u << 12, 1u << 13, 1u << 14, 1u << 15,
    1u << 16, 1u << 17, 1u << 18, 1u << 19,
    1u << 20, 1u << 21, 1u << 22, 1u << 23,
    1u << 24, 1u << 25, 1u << 26, 1u << 27,
    1u << 28, 1u << 29, 1u << 30, 1u << 31
};

extern "C" {
int func_001DAA60(const unsigned int *self, int idx);
}

static void test_check_bitmask_valid() {
    unsigned int mask = 0b1010; // bits 1 and 3 set
    assert(func_001DAA60(&mask, 0) == 0);
    assert(func_001DAA60(&mask, 1) == 1);
    assert(func_001DAA60(&mask, 2) == 0);
    assert(func_001DAA60(&mask, 3) == 1);
}

static void test_check_bitmask_out_of_bounds() {
    unsigned int mask = 0xFFFFFFFF;
    assert(func_001DAA60(&mask, -1) == 0);
    assert(func_001DAA60(&mask, 32) == 0);
    assert(func_001DAA60(&mask, 100) == 0);
}

int main(int argc, char **argv) {
    test_check_bitmask_valid();
    test_check_bitmask_out_of_bounds();
    return 0;
}
