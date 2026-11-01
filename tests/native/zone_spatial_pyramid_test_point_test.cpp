#include <cassert>
#include <cstddef>
#include <cstring>
typedef unsigned char u8;
typedef unsigned short u16;

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D5B00(void *self, int x, int y, void *node, int dir, int flag);

static int g_func_1d5a30_calls = 0;
static int g_func_00123350_calls = 0;
static int g_func_1d4330_calls = 0;
static int g_func_001d42a0_calls = 0;

static float g_last_g_score = 0.0f;
static float g_last_h_score = 0.0f;
static void *g_last_parent = NULL;
static int g_last_alloc_x = -1;
static int g_last_alloc_y = -1;

int func_1D5A30(void *self, int x, int y) {
    g_func_1d5a30_calls++;
    return 0;
}

int func_00123350(float val) {
    g_func_00123350_calls++;
    return (int)val;
}

static char g_dummy_allocated_node[64];

void *func_1D4330(void *self, int x, int y, int level, float g_score, float h_score, void *parent, int dir, void *t2, void *t3) {
    g_func_1d4330_calls++;
    g_last_alloc_x = x;
    g_last_alloc_y = y;
    g_last_g_score = g_score;
    g_last_h_score = h_score;
    g_last_parent = parent;
    return g_dummy_allocated_node;
}

void func_001D42A0(void *self, void *list_head, void *node, int flag) {
    g_func_001d42a0_calls++;
    assert(node == g_dummy_allocated_node);
}
}

struct TestFixture {
    char zm[0x200];
    u16 *grid_cols[32];
    u16 grid_cells[32][32];
    u8 *arr120_cols[32];
    u8 arr120_cells[32][32];
    void *grid_levels[4];

    TestFixture() {
        std::memset(this, 0, sizeof(*this));
        for (int i = 0; i < 32; ++i) {
            grid_cols[i] = grid_cells[i];
            arr120_cols[i] = arr120_cells[i];
        }
        grid_levels[0] = grid_cols;
        *reinterpret_cast<void ****>(zm + 0x0) = (void ***)grid_levels;
        *reinterpret_cast<u8 ***>(zm + 0x120) = arr120_cols;

        *reinterpret_cast<int *>(zm + 0xEC) = 30; // map_w
        *reinterpret_cast<int *>(zm + 0xF0) = 30; // map_h
        *reinterpret_cast<int *>(zm + 0xF4) = 5;  // min_x
        *reinterpret_cast<int *>(zm + 0xF8) = 5;  // min_y
        *reinterpret_cast<int *>(zm + 0xFC) = 25; // max_x
        *reinterpret_cast<int *>(zm + 0x100) = 25;// max_y
    }
};

static void reset_counters() {
    g_func_1d5a30_calls = 0;
    g_func_00123350_calls = 0;
    g_func_1d4330_calls = 0;
    g_func_001d42a0_calls = 0;
    g_last_g_score = 0.0f;
    g_last_h_score = 0.0f;
    g_last_parent = NULL;
    g_last_alloc_x = -1;
    g_last_alloc_y = -1;
}

static void test_out_of_bounds() {
    TestFixture fix;
    char parent_node[64];
    reset_counters();

    // x < min_x
    func_001D5B00(fix.zm, 4, 10, parent_node, 0, 0);
    assert(g_func_1d4330_calls == 0);

    // x > max_x
    func_001D5B00(fix.zm, 26, 10, parent_node, 0, 0);
    assert(g_func_1d4330_calls == 0);

    // y < min_y
    func_001D5B00(fix.zm, 10, 4, parent_node, 0, 0);
    assert(g_func_1d4330_calls == 0);

    // y > max_y
    func_001D5B00(fix.zm, 10, 26, parent_node, 0, 0);
    assert(g_func_1d4330_calls == 0);
}

static void test_already_visited() {
    TestFixture fix;
    char parent_node[64];
    reset_counters();

    // Set bit 0x10 on grid cell (10, 10)
    fix.grid_cells[10][10] = 0x10;

    func_001D5B00(fix.zm, 10, 10, parent_node, 0, 0);
    assert(g_func_1d4330_calls == 0);
}

static void test_valid_point_expansion() {
    TestFixture fix;
    char parent_node[64];
    *reinterpret_cast<float *>(parent_node + 0x1C) = 50.0f;
    reset_counters();

    // Point (10, 12), dir = 1
    func_001D5B00(fix.zm, 10, 12, parent_node, 1, 0);

    assert(g_func_1d4330_calls == 1);
    assert(g_func_001d42a0_calls == 1);
    assert(g_last_alloc_x == 10);
    assert(g_last_alloc_y == 12);
    assert(g_last_parent == parent_node);

    // Cell flags should have been updated with +0x10
    assert((fix.grid_cells[10][12] & 0x10) == 0x10);

    // Check h_score: for dir 1, h = max_x - x = 25 - 10 = 15
    assert(g_last_h_score == 15.0f);
}

static void test_arr120_penalty() {
    TestFixture fix;
    char parent_node[64];
    *reinterpret_cast<float *>(parent_node + 0x1C) = 10.0f;
    reset_counters();

    fix.arr120_cells[12][12] = 1;
    func_001D5B00(fix.zm, 12, 12, parent_node, 1, 0);

    assert(g_func_1d4330_calls == 1);
    // Cost should be 2000 + 10 (parent) = 2010
    assert(g_last_g_score == 2010.0f);
}

int main(int argc, char **argv) {
    test_out_of_bounds();
    test_already_visited();
    test_valid_point_expansion();
    test_arr120_penalty();
    return 0;
}
