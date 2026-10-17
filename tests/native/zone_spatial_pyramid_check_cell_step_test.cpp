#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D4E00(void *self, int x, int y, int level, int min_x, int min_y);
}

static void test_check_cell_step_valid() {
    char zm[0x100];
    std::memset(zm, 0, sizeof(zm));

    char cell[16];
    std::memset(cell, 0, sizeof(cell));
    void *level0[3] = { nullptr, nullptr, cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    int dist = func_001D4E00(zm, 5, 3, 0, 2, 1);
    // dx = 5 - 2 = 3, dy = 3 - 1 = 2 -> 3 + 2 = 5
    assert(dist == 5);
}

static void test_check_cell_step_blocked() {
    char zm[0x100];
    std::memset(zm, 0, sizeof(zm));

    char cell[16];
    std::memset(cell, 0, sizeof(cell));
    cell[1 * 2 + 1] = 0x0F; // min_y = 1, byte 1 == 0xF (blocked)
    void *level0[3] = { nullptr, nullptr, cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    int dist = func_001D4E00(zm, 5, 3, 0, 2, 1);
    assert(dist == -1);
}

int main(int argc, char **argv) {
    test_check_cell_step_valid();
    test_check_cell_step_blocked();
    return 0;
}
