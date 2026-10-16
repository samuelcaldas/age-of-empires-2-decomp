#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D66E0(void *self, int p1, int p2, int p3, int p4, int p5, int p6, int p7);
}

static void test_find_path_flow() {
    char zm[0x100];
    assert(func_001D66E0(nullptr, 0, 0, 0, 0, 0, 0, 0) == 0);
    assert(func_001D66E0(zm, 0, 0, 0, 0, 0, 0, 0) == 1);
}

int main(int argc, char **argv) {
    test_find_path_flow();
    return 0;
}
