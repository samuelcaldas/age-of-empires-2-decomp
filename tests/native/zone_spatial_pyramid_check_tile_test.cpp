#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D29F0(void *self, int y, int x, void *out_flag);
}

static void test_check_tile() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    // Map limits: max_y = 5, max_x = 5
    *reinterpret_cast<int *>(zm + 0xEC) = 5;
    *reinterpret_cast<int *>(zm + 0xF0) = 5;

    // 3 columns: x=0, x=1, x=2
    // Each column has 5 tiles of 28 bytes = 140 bytes
    char col0[140];
    char col1[140];
    char col2[140];
    std::memset(col0, 0, sizeof(col0));
    std::memset(col1, 0, sizeof(col1));
    std::memset(col2, 0, sizeof(col2));

    char *cols[3] = {col0, col1, col2};
    *reinterpret_cast<char ***>(zm + 0x98) = cols;

    // Thresholds: index 1 is passable (1.0f), index 0 is impassable (0.0f)
    float thresholds[4] = {0.0f, 1.0f, 1.0f, 1.0f};
    *reinterpret_cast<float **>(zm + 0x9C) = thresholds;

    unsigned char out = 0xFF;

    // Test 1: center tile (1, 1) has terrain 0 -> impassable
    col1[1 * 28 + 5] = 0;
    func_001D29F0(zm, 1, 1, &out);
    assert(out == 0);

    // Test 2: center tile (1, 1) passable, but all neighbors impassable (terrain 0)
    col1[1 * 28 + 5] = 1;
    func_001D29F0(zm, 1, 1, &out);
    assert(out == 0);

    // Test 3: Set North neighbor (x=1, y=0) to passable -> bit 0x2
    col1[0 * 28 + 5] = 1;
    func_001D29F0(zm, 1, 1, &out);
    assert(out == 0x2);

    // Test 4: Set West neighbor (x=0, y=1) to passable -> bit 0x1
    col0[1 * 28 + 5] = 1;
    func_001D29F0(zm, 1, 1, &out);
    assert(out == (0x2 | 0x1));

    // Test 5: Set South neighbor (x=1, y=2) to passable -> bit 0x4
    col1[2 * 28 + 5] = 1;
    func_001D29F0(zm, 1, 1, &out);
    assert(out == (0x2 | 0x1 | 0x4));

    // Test 6: Set East neighbor (x=2, y=1) to passable -> bit 0x8
    col2[1 * 28 + 5] = 1;
    func_001D29F0(zm, 1, 1, &out);
    assert(out == (0x2 | 0x1 | 0x4 | 0x8));
}

int main(int argc, char **argv) {
    test_check_tile();
    return 0;
}
