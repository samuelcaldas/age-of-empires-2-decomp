#include <cassert>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct Vec3f {
    float x, y, z;
};

float D_004E2820 = 50.0f;

static int g_call_idx = 0;

extern "C" {
void func_315110(void *dst, void *a1, void *a2, void *a3) {
    Vec3f *d = (Vec3f *)dst;
    g_call_idx++;
    if (g_call_idx == 1) {
        // v1: length = 10
        d->x = 6.0f; d->y = 999.0f; d->z = 8.0f;
    } else if (g_call_idx == 2) {
        // v2: length = 5
        d->x = 3.0f; d->y = 999.0f; d->z = 4.0f;
    } else {
        // v3: length = 2
        d->x = 2.0f; d->y = 999.0f; d->z = 0.0f;
    }
}

int func_001DACD0(void *a0, void *a1, void *a2, void *a3, void *s0, void *s1, void *s2);
}

static void test_eval_lengths_case1() {
    g_call_idx = 0;
    int a0 = 0, a1 = 0, a2 = 0, a3 = 0, s0 = 0, s1 = 0, s2 = 0;
    // len1 = 10, len2 = 5, len3 = 2.
    // len1 > len2 (10 > 5), len2 >= len3 (5 >= 2), len1 < 50 (10 < 50) -> return 1
    int res = func_001DACD0(&a0, &a1, &a2, &a3, &s0, &s1, &s2);
    assert(res == 1);
}

int main(int argc, char **argv) {
    test_eval_lengths_case1();
    return 0;
}
