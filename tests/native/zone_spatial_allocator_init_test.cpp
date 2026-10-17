#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialNodeProps {
    char pad0[4];
    int prop1;
    int prop2;
    char pad1[0x18 - 0xC];
    char prop3;
};

extern "C" {
int func_001D81C0(SpatialNodeProps *self, int p1, int p2, char p3);
}

static void test_allocator_init() {
    SpatialNodeProps props;
    std::memset(&props, 0, sizeof(props));

    int res = func_001D81C0(&props, 16, 64, 1);
    assert(res == 1);
    assert(props.prop1 == 16);
    assert(props.prop2 == 64);
    assert(props.prop3 == 1);
}

int main(int argc, char **argv) {
    test_allocator_init();
    return 0;
}
