#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D7E90(float *m);
}

static void test_matrix_init_identity() {
    float m[12];
    std::memset(m, 0xFF, sizeof(m));

    func_001D7E90(m);

    // Diagonal elements = 1.0f
    assert(m[0] == 1.0f);
    assert(m[5] == 1.0f);
    assert(m[10] == 1.0f);

    // Off-diagonal elements = 0.0f
    assert(m[1] == 0.0f);
    assert(m[2] == 0.0f);
    assert(m[3] == 0.0f);
    assert(m[4] == 0.0f);
    assert(m[6] == 0.0f);
    assert(m[7] == 0.0f);
    assert(m[8] == 0.0f);
    assert(m[9] == 0.0f);
    assert(m[11] == 0.0f);
}

int main(int argc, char **argv) {
    test_matrix_init_identity();
    return 0;
}
