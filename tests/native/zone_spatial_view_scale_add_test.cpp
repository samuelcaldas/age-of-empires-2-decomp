#include <cassert>
#include "zone_spatial_view_scale_add.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

static void test_scale_add() {
    float res = func_001DAE20(nullptr, nullptr, 10.0f, 3.0f, 4.0f);
    assert(res == 22.0f); // 10.0 + 4.0 * 3.0 = 22.0
}

int main(int argc, char **argv) {
    test_scale_add();
    return 0;
}
