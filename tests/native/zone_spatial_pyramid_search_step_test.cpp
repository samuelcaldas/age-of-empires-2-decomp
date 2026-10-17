#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D3880(void *self, int level, int x, int y, float f12, int t0, int mask);
}

static void test_search_step_match() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char cell[4] = { 0x04, 0, 0, 0 }; // mask bit 4 set
    void *level0[1] = { cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    int res = func_001D3880(zm, 0, 0, 0, 0.0f, 0, 0x04);
    assert(res == 1);
}

static void test_search_step_no_match() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char cell[4] = { 0x02, 0, 0, 0 }; // mask bit 4 not set
    void *level0[1] = { cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    int res = func_001D3880(zm, 0, 0, 0, 0.0f, 0, 0x04);
    assert(res == 0);
}

int main(int argc, char **argv) {
    test_search_step_match();
    test_search_step_no_match();
    return 0;
}
