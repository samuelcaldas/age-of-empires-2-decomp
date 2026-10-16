#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D35C0(void *self, int level, int x, int y, int cur_x, int cur_y);
}

static void test_eval_cost_flow() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char cell[4] = { 1, 0, 0, 0 }; // cell[0] != 0
    void *level0[1] = { cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    *reinterpret_cast<int *>(zm + 0x104) = 10; // target_x
    *reinterpret_cast<int *>(zm + 0x108) = 20; // target_y

    int cost = func_001D35C0(zm, 0, 0, 0, 7, 16);
    // dx = 10 - 7 = 3, dy = 20 - 16 = 4 -> 3*3 + 4*4 = 25
    assert(cost == 25);
}

int main(int argc, char **argv) {
    test_eval_cost_flow();
    return 0;
}
