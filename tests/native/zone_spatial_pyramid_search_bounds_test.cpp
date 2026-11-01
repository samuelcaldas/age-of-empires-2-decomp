#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D3EB0(
    void *self, int level, int x, int y, float minX, float minY, float maxX, float maxY, int op
);
}

static int s_mock_test_cell_ret = 1;

extern "C" int func_1D40E0(void *self, int level, int x, int y, float f12, float f13, float f14, float f15) {
    (void)self;
    (void)level;
    (void)x;
    (void)y;
    (void)f12;
    (void)f13;
    (void)f14;
    (void)f15;
    return s_mock_test_cell_ret;
}

static void test_search_bounds() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xF4) = 0;   // minX
    *reinterpret_cast<int *>(zm + 0xF8) = 0;   // minY
    *reinterpret_cast<int *>(zm + 0xFC) = 64;  // maxX
    *reinterpret_cast<int *>(zm + 0x100) = 64; // maxY

    // Setup hierarchy for level 1 and level 0
    // level 1: 1 column at x=0
    // level 0: 2 columns at x=0, 1
    unsigned short cell_l1[4] = {0, 0, 0, 0}; // y=0..3
    unsigned short *col_l1[2] = {cell_l1, nullptr};

    unsigned short cell_l0_c0[4] = {0, 0, 0, 0};
    unsigned short cell_l0_c1[4] = {0, 0, 0, 0};
    unsigned short *col_l0[2] = {cell_l0_c0, cell_l0_c1};

    unsigned short **levels[2] = {col_l0, col_l1};
    *reinterpret_cast<void ***>(zm + 0x0) = reinterpret_cast<void **>(levels);

    // Test 1: Out of bounds checks
    assert(func_001D3EB0(zm, 0, -1, 0, 0, 0, 0, 0, 1) == 0);
    assert(func_001D3EB0(zm, 0, 0, -1, 0, 0, 0, 0, 1) == 0);
    assert(func_001D3EB0(zm, 0, 65, 0, 0, 0, 0, 0, 1) == 0);
    assert(func_001D3EB0(zm, 0, 0, 65, 0, 0, 0, 0, 1) == 0);

    // Test 2: Leaf cell with flag 0x20, test_cell_bounds passes, op=1 (set 0x10)
    reinterpret_cast<unsigned char *>(cell_l1)[1] = 0x20;
    s_mock_test_cell_ret = 1;
    int res = func_001D3EB0(zm, 1, 0, 0, 0.0f, 0.0f, 10.0f, 10.0f, 1);
    assert(res == 1);
    assert((reinterpret_cast<unsigned char *>(cell_l1)[1] & 0x10) == 0x10);

    // Test 2b: Repeat with op=1 when 0x10 is already set -> returns 0
    res = func_001D3EB0(zm, 1, 0, 0, 0.0f, 0.0f, 10.0f, 10.0f, 1);
    assert(res == 0);

    // Test 3: Clear with op=0 (clears 0x10)
    res = func_001D3EB0(zm, 1, 0, 0, 0.0f, 0.0f, 10.0f, 10.0f, 0);
    assert(res == 1);
    assert((reinterpret_cast<unsigned char *>(cell_l1)[1] & 0x10) == 0);

    // Test 3b: Repeat with op=0 when 0x10 is already cleared -> returns 0
    res = func_001D3EB0(zm, 1, 0, 0, 0.0f, 0.0f, 10.0f, 10.0f, 0);
    assert(res == 0);

    // Test 4: test_cell_bounds returns 0 -> returns 0, no bit change
    s_mock_test_cell_ret = 0;
    res = func_001D3EB0(zm, 1, 0, 0, 0.0f, 0.0f, 10.0f, 10.0f, 1);
    assert(res == 0);
    assert((reinterpret_cast<unsigned char *>(cell_l1)[1] & 0x10) == 0);

    // Test 5: Internal node (flag 0x20 NOT set) recurses into children at level 0
    s_mock_test_cell_ret = 1;
    reinterpret_cast<unsigned char *>(cell_l1)[1] = 0x00; // not leaf
    // Child (0, 0) in col 0
    reinterpret_cast<unsigned char *>(&cell_l0_c0[0])[1] = 0x20;
    // Child (1, 0) in col 1
    reinterpret_cast<unsigned char *>(&cell_l0_c1[0])[1] = 0x20;
    // Child (0, 1) in col 0
    reinterpret_cast<unsigned char *>(&cell_l0_c0[1])[1] = 0x20;
    // Child (1, 1) in col 1
    reinterpret_cast<unsigned char *>(&cell_l0_c1[1])[1] = 0x20;

    res = func_001D3EB0(zm, 1, 0, 0, 0.0f, 0.0f, 10.0f, 10.0f, 1);
    assert(res == 4);
    assert((reinterpret_cast<unsigned char *>(&cell_l0_c0[0])[1] & 0x10) == 0x10);
    assert((reinterpret_cast<unsigned char *>(&cell_l0_c1[0])[1] & 0x10) == 0x10);
    assert((reinterpret_cast<unsigned char *>(&cell_l0_c0[1])[1] & 0x10) == 0x10);
    assert((reinterpret_cast<unsigned char *>(&cell_l0_c1[1])[1] & 0x10) == 0x10);
}

int main(int argc, char **argv) {
    test_search_bounds();
    return 0;
}
