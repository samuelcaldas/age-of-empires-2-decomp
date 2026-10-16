#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CC6E0(void *self, int x0, int y0, int x1, int y1, int terrain_param);
}

struct BlendCallRecord {
    void *self;
    void *world;
    int x;
    int y;
    int terrain;
    int p5;
    int p6;
};
static std::vector<BlendCallRecord> g_call_log;

struct BlendCell {
    char pad_0[5];
    char f_5;
    char f_6;
    char pad_7[21];
};
static_assert(sizeof(BlendCell) == 28, "Cell size must be 28 bytes");

struct BlendLayout {
    char pad_0[8];
    short stride_param;     // 0x8
    short pad_A;            // 0xA
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    BlendCell **cells_ptr;  // 0x8E8C
    char pad_8E90[0x58];    // 0x8E90..0x8EE7
    void *m_world;          // 0x8EE8
};

extern "C" void func_1CF830(void *self, void *world, int x, int y, int terrain_type, int p5, int p6) {
    g_call_log.push_back({self, world, x, y, terrain_type, p5, p6});
    BlendLayout *zm = reinterpret_cast<BlendLayout *>(self);
    zm->cells_ptr[y][x].f_5 = static_cast<char>(terrain_type);
}

static void setup_grid(BlendLayout *zm, BlendCell cells[7][7], BlendCell *row_ptrs[7], int width, int height, char initial_terrain) {
    std::memset(zm, 0, sizeof(BlendLayout));
    *reinterpret_cast<int *>(&zm->stride_param) = width;
    zm->stride_param = static_cast<short>(width);
    zm->height = height;
    zm->m_world = reinterpret_cast<void *>(0x55555555);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::memset(&cells[y][x], 0, sizeof(BlendCell));
            cells[y][x].f_5 = initial_terrain;
        }
        row_ptrs[y] = cells[y];
    }
    zm->cells_ptr = row_ptrs;
    g_call_log.clear();
}

static void test_matching_terrain_no_op() {
    BlendLayout zm;
    BlendCell cells[7][7];
    BlendCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 2);

    func_001CC6E0(&zm, 1, 1, 5, 5, 2);
    assert(g_call_log.empty());
    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 7; x++) {
            assert(cells[y][x].f_5 == 2);
        }
    }
}

static void test_orthogonal_saddle_replacement() {
    BlendLayout zm;
    BlendCell cells[7][7];
    BlendCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 1);

    cells[2][3].f_5 = 2; // North
    cells[4][3].f_5 = 2; // South

    func_001CC6E0(&zm, 3, 3, 3, 3, 2);
    assert(g_call_log.size() == 1);
    assert(g_call_log[0].self == &zm);
    assert(g_call_log[0].world == zm.m_world); // m_world verified
    assert(g_call_log[0].x == 3 && g_call_log[0].y == 3);
    assert(g_call_log[0].terrain == 2);
    assert(g_call_log[0].p5 == 0 && g_call_log[0].p6 == 0); // Trailing args zeroed
    assert(cells[3][3].f_5 == 2);
}

static void test_corner_diagonal_replacement() {
    BlendLayout zm;
    BlendCell cells[7][7];
    BlendCell *row_ptrs[7];
    setup_grid(&zm, cells, row_ptrs, 7, 7, 1);

    cells[2][2].f_5 = 2; // NW
    cells[3][4].f_5 = 2; // East
    cells[2][4].f_5 = 1; // NE
    cells[2][3].f_5 = 1; // North
    cells[4][3].f_5 = 1; // South
    cells[3][2].f_5 = 1; // West

    func_001CC6E0(&zm, 3, 3, 3, 3, 2);
    // Exact count of 2 calls: (3, 2) in pass 0, (3, 3) in pass 1
    assert(g_call_log.size() == 2);
    assert(g_call_log[0].self == &zm && g_call_log[0].world == zm.m_world);
    assert(g_call_log[0].x == 3 && g_call_log[0].y == 2 && g_call_log[0].terrain == 2);
    assert(g_call_log[0].p5 == 0 && g_call_log[0].p6 == 0);

    assert(g_call_log[1].self == &zm && g_call_log[1].world == zm.m_world);
    assert(g_call_log[1].x == 3 && g_call_log[1].y == 3 && g_call_log[1].terrain == 2);
    assert(g_call_log[1].p5 == 0 && g_call_log[1].p6 == 0);

    assert(cells[2][3].f_5 == 2 && cells[3][3].f_5 == 2);
}

static void test_bounds_clamping() {
    BlendLayout zm1, zm2;
    BlendCell cells1[7][7], cells2[7][7];
    BlendCell *row_ptrs1[7], *row_ptrs2[7];
    setup_grid(&zm1, cells1, row_ptrs1, 7, 7, 1);
    setup_grid(&zm2, cells2, row_ptrs2, 7, 7, 1);

    cells1[2][3].f_5 = 2; cells1[4][3].f_5 = 2;
    cells2[2][3].f_5 = 2; cells2[4][3].f_5 = 2;

    func_001CC6E0(&zm1, -10, -10, 50, 50, 2);
    assert(g_call_log.size() == 1);
    assert(g_call_log[0].self == &zm1 && g_call_log[0].world == zm1.m_world);
    assert(g_call_log[0].x == 3 && g_call_log[0].y == 3);
    assert(g_call_log[0].p5 == 0 && g_call_log[0].p6 == 0);

    g_call_log.clear();
    func_001CC6E0(&zm2, 0, 0, 6, 6, 2);
    assert(g_call_log.size() == 1);
    assert(g_call_log[0].self == &zm2 && g_call_log[0].world == zm2.m_world);
    assert(g_call_log[0].x == 3 && g_call_log[0].y == 3);
    assert(g_call_log[0].p5 == 0 && g_call_log[0].p6 == 0);

    assert(cells1[3][3].f_5 == 2 && cells2[3][3].f_5 == 2);
    assert(std::memcmp(cells1, cells2, sizeof(cells1)) == 0);
}

static void test_truncation_andi_ff() {
    const int test_vals[] = {0, 1, 2, 5, 20, 100};
    for (int i = 0; i < 6; i++) {
        int v = test_vals[i];
        BlendLayout zm1, zm2;
        BlendCell cells1[7][7], cells2[7][7];
        BlendCell *row_ptrs1[7], *row_ptrs2[7];

        setup_grid(&zm1, cells1, row_ptrs1, 7, 7, 1);
        setup_grid(&zm2, cells2, row_ptrs2, 7, 7, 1);
        cells1[2][3].f_5 = static_cast<char>(v & 0xFF);
        cells1[4][3].f_5 = static_cast<char>(v & 0xFF);
        cells2[2][3].f_5 = static_cast<char>(v & 0xFF);
        cells2[4][3].f_5 = static_cast<char>(v & 0xFF);

        func_001CC6E0(&zm1, 3, 3, 3, 3, v);
        func_001CC6E0(&zm2, 3, 3, 3, 3, v | 0x100);
        assert(std::memcmp(cells1, cells2, sizeof(cells1)) == 0);
    }
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "matching_no_op") {
        test_matching_terrain_no_op();
    } else if (argc > 1 && std::string(argv[1]) == "orthogonal_saddle") {
        test_orthogonal_saddle_replacement();
    } else if (argc > 1 && std::string(argv[1]) == "corner_diagonal") {
        test_corner_diagonal_replacement();
    } else if (argc > 1 && std::string(argv[1]) == "bounds_clamping") {
        test_bounds_clamping();
    } else if (argc > 1 && std::string(argv[1]) == "truncation_andi_ff") {
        test_truncation_andi_ff();
    } else {
        test_matching_terrain_no_op();
        test_orthogonal_saddle_replacement();
        test_corner_diagonal_replacement();
        test_bounds_clamping();
        test_truncation_andi_ff();
    }
    return 0;
}
