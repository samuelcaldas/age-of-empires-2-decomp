#include <cassert>
#include <cmath>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialViewObj {
    char pad[0x64];
    float x;
    float y;
    float z;
};

extern "C" {
int func_001D8FD0(SpatialViewObj *self);
}

static void test_is_valid_zero() {
    SpatialViewObj obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.x = 0.0f;
    obj.y = 0.0f;
    obj.z = 0.0f;
    assert(func_001D8FD0(&obj) == 0);
}

static void test_is_valid_nonzero() {
    SpatialViewObj obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.x = 1.0f;
    obj.y = 2.0f;
    obj.z = 2.0f;
    assert(func_001D8FD0(&obj) == 1);
}

int main(int argc, char **argv) {
    test_is_valid_zero();
    test_is_valid_nonzero();
    return 0;
}
