#include <cassert>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

float D_004E2808 = 1e30f;
float D_004E27FC = 100.0f;

struct SpatialViewObj {
    char pad[0xA0];
    float fA0;
    float fA4;
};

extern "C" {
void func_001D8F90(SpatialViewObj *self, float val);
}

static void test_set_rate_zero() {
    SpatialViewObj obj;
    std::memset(&obj, 0, sizeof(obj));
    func_001D8F90(&obj, 0.0f);
    assert(obj.fA0 == 0.0f);
    assert(obj.fA4 == 1e30f);
}

static void test_set_rate_nonzero() {
    SpatialViewObj obj;
    std::memset(&obj, 0, sizeof(obj));
    func_001D8F90(&obj, 2.0f);
    assert(obj.fA0 == 2.0f);
    assert(obj.fA4 == 50.0f);
}

int main(int argc, char **argv) {
    test_set_rate_zero();
    test_set_rate_nonzero();
    return 0;
}
