#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D3440(void *self, int level, int x, int y, void *p1, void *p2);
}

static void test_search_cell_set_flag_within_bounds() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    // Bounds: [0, 10] for x, [0, 10] for y
    *reinterpret_cast<int *>(zm + 0xF4) = 0;   // min_x
    *reinterpret_cast<int *>(zm + 0xF8) = 0;   // min_y
    *reinterpret_cast<int *>(zm + 0xFC) = 10;  // max_x
    *reinterpret_cast<int *>(zm + 0x100) = 10; // max_y

    // cell has cell[1] & 0x20 != 0, cell[0] = 0
    char cell[4] = { 0x00, 0x20, 0, 0 };
    void *level0[1] = { cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    // Call with flag = (void *)1 (set flag)
    func_001D3440(zm, 0, 0, 0, reinterpret_cast<void *>(1), nullptr);

    // cell[0] should now have bit 0x20 set
    assert((static_cast<unsigned char>(cell[0]) & 0x20) == 0x20);
}

static void test_search_cell_clear_flag_within_bounds() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    *reinterpret_cast<int *>(zm + 0xF4) = 0;   // min_x
    *reinterpret_cast<int *>(zm + 0xF8) = 0;   // min_y
    *reinterpret_cast<int *>(zm + 0xFC) = 10;  // max_x
    *reinterpret_cast<int *>(zm + 0x100) = 10; // max_y

    // cell has cell[1] & 0x20 != 0, cell[0] has bit 0x20 set
    char cell[4] = { 0x20, 0x20, 0, 0 };
    void *level0[1] = { cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    // Call with flag = nullptr (clear flag)
    func_001D3440(zm, 0, 0, 0, nullptr, nullptr);

    // cell[0] should now have bit 0x20 cleared
    assert((static_cast<unsigned char>(cell[0]) & 0x20) == 0);
}

static void test_search_cell_out_of_bounds() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    // Bounds: [2, 5] for x, [2, 5] for y
    *reinterpret_cast<int *>(zm + 0xF4) = 2;   // min_x
    *reinterpret_cast<int *>(zm + 0xF8) = 2;   // min_y
    *reinterpret_cast<int *>(zm + 0xFC) = 5;   // max_x
    *reinterpret_cast<int *>(zm + 0x100) = 5;  // max_y

    // x = 0 is out of bounds (< 2)
    char cell[4] = { 0x00, 0x20, 0, 0 };
    void *level0[1] = { cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    func_001D3440(zm, 0, 0, 0, reinterpret_cast<void *>(1), nullptr);

    // cell[0] should NOT be modified
    assert(cell[0] == 0);
}

static void test_search_cell_recursion() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    *reinterpret_cast<int *>(zm + 0xF4) = 0;   // min_x
    *reinterpret_cast<int *>(zm + 0xF8) = 0;   // min_y
    *reinterpret_cast<int *>(zm + 0xFC) = 10;  // max_x
    *reinterpret_cast<int *>(zm + 0x100) = 10; // max_y

    // Level 1: cell has bit 0x20 cleared in cell[1] -> will recurse to 4 children in Level 0
    char cell_l1[4] = { 0, 0x00, 0, 0 };
    void *level1[1] = { cell_l1 };

    // Level 0: 2x2 grid of cells, all have bit 0x20 set in cell[1]
    char col0_cells[8]; // y=0: bytes 0..1, y=1: bytes 2..3
    col0_cells[0] = 0; col0_cells[1] = 0x20;
    col0_cells[2] = 0; col0_cells[3] = 0x20;

    char col1_cells[8]; // x=1, y=0: bytes 0..1, y=1: bytes 2..3
    col1_cells[0] = 0; col1_cells[1] = 0x20;
    col1_cells[2] = 0; col1_cells[3] = 0x20;

    void *level0[2] = { col0_cells, col1_cells };

    void **root[2] = { level0, level1 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    // Call on level 1, (0, 0)
    func_001D3440(zm, 1, 0, 0, reinterpret_cast<void *>(1), nullptr);

    // All 4 subcells should have bit 0x20 set
    assert((static_cast<unsigned char>(col0_cells[0]) & 0x20) == 0x20);
    assert((static_cast<unsigned char>(col0_cells[2]) & 0x20) == 0x20);
    assert((static_cast<unsigned char>(col1_cells[0]) & 0x20) == 0x20);
    assert((static_cast<unsigned char>(col1_cells[2]) & 0x20) == 0x20);
}

int main(int argc, char **argv) {
    test_search_cell_set_flag_within_bounds();
    test_search_cell_clear_flag_within_bounds();
    test_search_cell_out_of_bounds();
    test_search_cell_recursion();
    return 0;
}
