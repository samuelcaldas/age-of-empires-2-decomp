#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D35C0(void *self, int level, int x, int y, int cur_x, int cur_y);

float func_122690(int dist_sq) {
    return static_cast<float>(dist_sq);
}

float func_1228E8(float val) {
    return val;
}

static char s_dummy_start_node[64];
static char s_dummy_cell[4];

void *func_1D4330(
    void *self, int x, int y, int level, int p4, int p5, float f12, float f13, int cur_x, int cur_y
) {
    (void)self; (void)x; (void)y; (void)level; (void)p4; (void)p5; (void)f12; (void)f13; (void)cur_x; (void)cur_y;
    *reinterpret_cast<void **>(s_dummy_start_node) = s_dummy_cell;
    return s_dummy_start_node;
}

void func_001D42A0(void *self, void *list, void *node, int flag) {
    (void)self; (void)list; (void)node; (void)flag;
}

int func_001D3880(void *self, void *node, int next_x, int next_y, float cost, int dir) {
    (void)self; (void)node; (void)next_x; (void)next_y; (void)cost; (void)dir;
    return 0;
}
}

static void test_eval_cost() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char cell[4] = {0, 0, 0, 0};
    void *col0[1] = {cell};
    void **level0[1] = {col0};
    void ***root[1] = {level0};
    *reinterpret_cast<void ***>(zm + 0) = reinterpret_cast<void **>(root);

    *reinterpret_cast<int *>(zm + 0x104) = 10; // target_x
    *reinterpret_cast<int *>(zm + 0x108) = 20; // target_y

    // Test 1: cell[0] == 0 -> returns 0
    int res = func_001D35C0(zm, 0, 0, 0, 5, 5);
    assert(res == 0);

    // Test 2: cell[0] != 0, start_cell[1] has bit 0x10 -> returns start_node
    cell[0] = 1;
    s_dummy_cell[0] = 0;
    s_dummy_cell[1] = 0x10;
    res = func_001D35C0(zm, 0, 0, 0, 5, 5);
    assert(res == reinterpret_cast<int>(s_dummy_start_node));

    // Test 3: cell[0] != 0, start_cell[1] has no bit 0x10, open list empty -> returns 0
    s_dummy_cell[1] = 0x00;
    *reinterpret_cast<void **>(zm + 0x28) = nullptr;
    res = func_001D35C0(zm, 0, 0, 0, 5, 5);
    assert(res == 0);
}

int main(int argc, char **argv) {
    test_eval_cost();
    return 0;
}
