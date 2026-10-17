#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D3440(void *self, int level, int x, int y, void *p1, void *p2);
}

static void test_search_cell_occupied() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char cell[4] = { 0, 0x10, 0, 0 }; // occupied bit 0x10 set
    void *level0[1] = { cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    int res = func_001D3440(zm, 0, 0, 0, nullptr, nullptr);
    assert(res == 1);
}

static void test_search_cell_unoccupied() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char cell[4] = { 0, 0, 0, 0 }; // occupied bit not set
    void *level0[1] = { cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    int res = func_001D3440(zm, 0, 0, 0, nullptr, nullptr);
    assert(res == 0);
}

int main(int argc, char **argv) {
    test_search_cell_occupied();
    test_search_cell_unoccupied();
    return 0;
}
