#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

typedef unsigned char u8;
typedef unsigned short u16;

extern "C" {
void func_001D5610(void *self, int min_x, int min_y, int max_x, int max_y, int dir, int flag, int level);

static int g_func_1d4330_calls = 0;
static int g_func_001d42a0_calls = 0;
static int g_func_001d5b00_calls = 0;

static char g_dummy_node[64];

void *func_1D4330(void *self, int x, int y, int level, float g_score, float h_score, void *parent, int dir, void *t2, void *t3) {
    g_func_1d4330_calls++;
    return g_dummy_node;
}

void func_001D42A0(void *self, void *list_head, void *node, int flag) {
    g_func_001d42a0_calls++;
}

void func_001D5B00(void *self, int x, int y, void *node, int dir, int flag) {
    g_func_001d5b00_calls++;
}
}

struct TestFixture {
    char zm[0x200];
    u16 *grid_cols[32];
    u16 grid_cells[32][32];
    void *grid_levels[4];

    TestFixture() {
        std::memset(this, 0, sizeof(*this));
        for (int i = 0; i < 32; ++i) {
            grid_cols[i] = grid_cells[i];
        }
        grid_levels[0] = grid_cols;
        *reinterpret_cast<void ****>(zm + 0x0) = (void ***)grid_levels;

        *reinterpret_cast<int *>(zm + 0xE4) = 20; // map_w
        *reinterpret_cast<int *>(zm + 0xE8) = 20; // map_h
        *reinterpret_cast<int *>(zm + 0xEC) = 19; // max_coord_w
        *reinterpret_cast<int *>(zm + 0xF0) = 19; // max_coord_h
    }
};

static void reset_counters() {
    g_func_1d4330_calls = 0;
    g_func_001d42a0_calls = 0;
    g_func_001d5b00_calls = 0;
}

static void test_step_path_out_of_bounds() {
    TestFixture fix;
    reset_counters();

    // min_x >= map_w (20)
    func_001D5610(fix.zm, 20, 5, 10, 10, 0, 0, 0);
    assert(g_func_1d4330_calls == 0);

    // max_x < 0
    func_001D5610(fix.zm, 5, 5, -1, 10, 0, 0, 0);
    assert(g_func_1d4330_calls == 0);

    // min_y >= map_h (20)
    func_001D5610(fix.zm, 5, 20, 10, 10, 0, 0, 0);
    assert(g_func_1d4330_calls == 0);

    // max_y <= 0
    func_001D5610(fix.zm, 5, 5, 10, 0, 0, 0, 0);
    assert(g_func_1d4330_calls == 0);
}

static void test_step_path_valid_setup() {
    TestFixture fix;
    reset_counters();

    // min_x = 2, min_y = 3, max_x = 10, max_y = 12, dir = 1, flag = 0, level = 0
    func_001D5610(fix.zm, 2, 3, 10, 12, 1, 0, 0);

    // Bounds should be stored in zm
    assert(*reinterpret_cast<int *>(fix.zm + 0xF4) == 2);
    assert(*reinterpret_cast<int *>(fix.zm + 0xF8) == 3);
    assert(*reinterpret_cast<int *>(fix.zm + 0xFC) == 10);
    assert(*reinterpret_cast<int *>(fix.zm + 0x100) == 12);

    // Root node allocated and inserted
    assert(g_func_1d4330_calls >= 1);
    assert(g_func_001d42a0_calls >= 1);
}

int main(int argc, char **argv) {
    test_step_path_out_of_bounds();
    test_step_path_valid_setup();
    return 0;
}
