#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D20D0(void *self, const float *values, int count);
}

static void test_pyramid_compare_count_mismatch() {
    char zm[0x100];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xA0) = 5;

    float vals[4] = { 1.0f, 2.0f, 3.0f, 4.0f };
    int res = func_001D20D0(zm, vals, 4);
    assert(res == 1); // count mismatch returns 1
}

static void test_pyramid_compare_elements_match() {
    char zm[0x100];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xA0) = 3;

    float arr[3] = { 10.5f, 20.25f, 30.125f };
    *reinterpret_cast<float **>(zm + 0x9C) = arr;

    float vals[3] = { 10.5f, 20.25f, 30.125f };
    int res = func_001D20D0(zm, vals, 3);
    assert(res == 1); // all match returns 1
}

static void test_pyramid_compare_element_differs() {
    char zm[0x100];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xA0) = 3;

    float arr[3] = { 10.5f, 20.25f, 30.125f };
    *reinterpret_cast<float **>(zm + 0x9C) = arr;

    float vals[3] = { 10.5f, 99.0f, 30.125f };
    int res = func_001D20D0(zm, vals, 3);
    assert(res == 0); // difference returns 0
}

int main(int argc, char **argv) {
    test_pyramid_compare_count_mismatch();
    test_pyramid_compare_elements_match();
    test_pyramid_compare_element_differs();
    return 0;
}
