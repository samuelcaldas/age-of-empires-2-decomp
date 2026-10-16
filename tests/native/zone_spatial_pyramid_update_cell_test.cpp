#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D21B0(void *self, int level, int x, int y);
}

static void test_update_cell_leaf_inside_bounds() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xE4) = 10; // max_x
    *reinterpret_cast<int *>(zm + 0xE8) = 10; // max_y

    char cell[4] = { 0, 0, 0, 0 };
    void *level0[1] = { cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    int res = func_001D21B0(zm, 0, 0, 0);
    assert(res == 1);
    assert((static_cast<unsigned char>(cell[1]) & 0xF) == 0xF);
}

static void test_update_cell_leaf_outside_bounds() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xE4) = 5;
    *reinterpret_cast<int *>(zm + 0xE8) = 5;

    char cell[4] = { 0, 0, 0, 0 };
    void *level0[6] = { nullptr, nullptr, nullptr, nullptr, nullptr, cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    int res = func_001D21B0(zm, 0, 5, 5); // x=5 >= max_x(5)
    assert(res == 0);
    assert((static_cast<unsigned char>(cell[1]) & 0xF) == 0);
}

int main(int argc, char **argv) {
    test_update_cell_leaf_inside_bounds();
    test_update_cell_leaf_outside_bounds();
    return 0;
}
