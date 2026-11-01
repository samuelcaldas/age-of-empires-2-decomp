#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D51B0(void *self, void *result);

static int g_func_117cac_calls = 0;
static int g_func_100850_calls = 0;

void *func_117CAC(void *dest, int c, int n) {
    g_func_117cac_calls++;
    return std::memset(dest, c, n);
}

static char g_allocated_nodes[32][32];
static int g_node_index = 0;

void *func_100850(int size) {
    g_func_100850_calls++;
    assert(size == 0x1C);
    assert(g_node_index < 32);
    char *node = g_allocated_nodes[g_node_index++];
    std::memset(node, 0, size);
    return node;
}
}

struct PathNode {
    int length;
    char field_4;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    PathNode *next;
};

struct ResultBucket {
    int count;
    PathNode *head;
};

struct TestFixture {
    char zm[0x200];
    char *buf11c_rows[16];
    char buf11c_data[16][16];
    char *buf120_rows[16];
    char buf120_data[16][16];
    char *grid0_rows[16];
    char grid0_data[16][32]; // 16-bit elements
    void *grid_levels[4];

    TestFixture() {
        std::memset(this, 0, sizeof(*this));
        for (int i = 0; i < 16; ++i) {
            buf11c_rows[i] = buf11c_data[i];
            buf120_rows[i] = buf120_data[i];
            grid0_rows[i] = grid0_data[i];
        }
        grid_levels[0] = grid0_rows;
        *reinterpret_cast<void ****>(zm + 0x0) = (void ***)grid_levels;
        *reinterpret_cast<char ***>(zm + 0x11C) = buf11c_rows;
        *reinterpret_cast<char ***>(zm + 0x120) = buf120_rows;

        *reinterpret_cast<int *>(zm + 0xE4) = 4; // width
        *reinterpret_cast<int *>(zm + 0xE8) = 4; // height
        *reinterpret_cast<int *>(zm + 0xEC) = 4; // bounds_w
        *reinterpret_cast<int *>(zm + 0xF0) = 4; // bounds_h
    }
};

static void test_search_path_init_and_empty() {
    TestFixture fix;
    ResultBucket result[10];
    std::memset(result, 0, sizeof(result));
    g_func_117cac_calls = 0;
    g_func_100850_calls = 0;
    g_node_index = 0;

    func_001D51B0(fix.zm, result);

    // memset called for each of the 4 columns
    assert(g_func_117cac_calls == 4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            assert(fix.buf11c_data[i][j] == 1);
        }
    }
    // No bits set in arr120, so no nodes allocated
    assert(g_func_100850_calls == 0);
}

static void test_search_path_with_bits() {
    TestFixture fix;
    ResultBucket result[10];
    std::memset(result, 0, sizeof(result));
    g_func_117cac_calls = 0;
    g_func_100850_calls = 0;
    g_node_index = 0;

    // Set bit 0 (dir 0) and bit 1 (dir 1) at (1, 2)
    fix.buf120_data[1][2] = 0x03;

    func_001D51B0(fix.zm, result);

    assert(g_func_100850_calls == 2);
    // result[1] (dir 0 + 1) should have 1 node
    assert(result[1].count == 1);
    assert(result[1].head != nullptr);
    assert(result[1].head->start_x == 1);
    assert(result[1].head->start_y == 2);

    // result[2] (dir 1 + 1) should have 1 node
    assert(result[2].count == 1);
    assert(result[2].head != nullptr);
    assert(result[2].head->start_x == 1);
    assert(result[2].head->start_y == 2);
}

int main(int argc, char **argv) {
    test_search_path_init_and_empty();
    test_search_path_with_bits();
    return 0;
}
