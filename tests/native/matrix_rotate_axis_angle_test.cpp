#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D7ED0(float *dst, const float *axis, float angle);

int func_00123350(float val) {
    return static_cast<int>(std::floor(val));
}

float func_33D560(int idx) {
    // 4096 units = 2pi
    float rad = (static_cast<float>(idx) / 4096.0f) * 6.2831855f;
    return std::cos(rad);
}

float func_33D530(int idx) {
    float rad = (static_cast<float>(idx) / 4096.0f) * 6.2831855f;
    return std::sin(rad);
}
}

static void test_rotation_zero_angle() {
    float m[12];
    std::memset(m, 0, sizeof(m));
    float axis[3] = { 0.0f, 0.0f, 1.0f };

    func_001D7ED0(m, axis, 0.0f);

    // Should approximate identity matrix
    assert(std::fabs(m[0] - 1.0f) < 0.01f);
    assert(std::fabs(m[5] - 1.0f) < 0.01f);
    assert(std::fabs(m[10] - 1.0f) < 0.01f);
    assert(std::fabs(m[1]) < 0.01f);
    assert(std::fabs(m[2]) < 0.01f);
    assert(std::fabs(m[4]) < 0.01f);
    assert(std::fabs(m[6]) < 0.01f);
    assert(std::fabs(m[8]) < 0.01f);
    assert(std::fabs(m[9]) < 0.01f);
}

static void test_rotation_z_90_degrees() {
    float m[12];
    std::memset(m, 0, sizeof(m));
    float axis[3] = { 0.0f, 0.0f, 1.0f };

    // 90 degrees = pi / 2
    func_001D7ED0(m, axis, 1.5707963f);

    // cos(90) = 0, sin(90) = 1
    // m[0] = 0, m[1] = -1, m[4] = 1, m[5] = 0, m[10] = 1
    assert(std::fabs(m[0]) < 0.05f);
    assert(std::fabs(m[1] - (-1.0f)) < 0.05f);
    assert(std::fabs(m[4] - 1.0f) < 0.05f);
    assert(std::fabs(m[5]) < 0.05f);
    assert(std::fabs(m[10] - 1.0f) < 0.05f);
}

int main(int argc, char **argv) {
    test_rotation_zero_angle();
    test_rotation_z_90_degrees();
    return 0;
}
