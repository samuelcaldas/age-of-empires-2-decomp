#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D8000(float *dst, const float *m, const float *v);
}

static void test_matrix_mul_vec3_identity() {
    float m[12] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f
    };
    float v[3] = { 2.5f, -3.0f, 7.2f };
    float dst[3] = { 0.0f, 0.0f, 0.0f };

    func_001D8000(dst, m, v);

    assert(dst[0] == 2.5f);
    assert(dst[1] == -3.0f);
    assert(dst[2] == 7.2f);
}

static void test_matrix_mul_vec3_scale_and_swap() {
    float m[12] = {
        0.0f, 2.0f, 0.0f, 0.0f, // dst[0] = 2 * v[1]
        0.0f, 0.0f, 3.0f, 0.0f, // dst[1] = 3 * v[2]
        4.0f, 0.0f, 0.0f, 0.0f  // dst[2] = 4 * v[0]
    };
    float v[3] = { 1.0f, 2.0f, 3.0f };
    float dst[3] = { 0.0f, 0.0f, 0.0f };

    func_001D8000(dst, m, v);

    assert(dst[0] == 4.0f);
    assert(dst[1] == 9.0f);
    assert(dst[2] == 4.0f);
}

int main(int argc, char **argv) {
    test_matrix_mul_vec3_identity();
    test_matrix_mul_vec3_scale_and_swap();
    return 0;
}
