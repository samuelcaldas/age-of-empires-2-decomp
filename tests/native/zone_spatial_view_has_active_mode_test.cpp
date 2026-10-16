#include <cassert>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SubObj {
    char pad[0x26];
    char mode;
};

struct SpatialViewObj {
    char pad[0xA8];
    SubObj *sub;
};

extern "C" {
int func_001D9020(SpatialViewObj *self);
}

static void test_has_active_mode_null_sub() {
    SpatialViewObj obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.sub = nullptr;
    assert(func_001D9020(&obj) == 0);
}

static void test_has_active_mode_values() {
    SpatialViewObj obj;
    SubObj sub;
    std::memset(&obj, 0, sizeof(obj));
    std::memset(&sub, 0, sizeof(sub));
    obj.sub = &sub;

    sub.mode = 0;
    assert(func_001D9020(&obj) == 0);

    sub.mode = 1;
    assert(func_001D9020(&obj) == 1);

    sub.mode = 2;
    assert(func_001D9020(&obj) == 1);

    sub.mode = 3;
    assert(func_001D9020(&obj) == 0);
}

int main(int argc, char **argv) {
    test_has_active_mode_null_sub();
    test_has_active_mode_values();
    return 0;
}
