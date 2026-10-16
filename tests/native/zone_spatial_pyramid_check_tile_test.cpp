#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D29F0(void *self, int x, int y, void *out_flag);
}

static void test_check_tile_passable() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char cell[32];
    std::memset(cell, 0, sizeof(cell));
    cell[5] = 2; // terrain type 2

    char *row0[1] = { cell };
    *reinterpret_cast<char ***>(zm + 0x98) = row0;

    float thresholds[4] = { 1.0f, 1.0f, 2.5f, 1.0f };
    *reinterpret_cast<float **>(zm + 0x9C) = thresholds;

    char out_flag = 0;
    func_001D29F0(zm, 0, 0, &out_flag);
    assert(out_flag == 1);
}

static void test_check_tile_impassable() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char cell[32];
    std::memset(cell, 0, sizeof(cell));
    cell[5] = 1; // terrain type 1

    char *row0[1] = { cell };
    *reinterpret_cast<char ***>(zm + 0x98) = row0;

    float thresholds[4] = { 1.0f, 0.0f, 2.5f, 1.0f }; // terrain 1 threshold <= 0
    *reinterpret_cast<float **>(zm + 0x9C) = thresholds;

    char out_flag = 1;
    func_001D29F0(zm, 0, 0, &out_flag);
    assert(out_flag == 0);
}

int main(int argc, char **argv) {
    test_check_tile_passable();
    test_check_tile_impassable();
    return 0;
}
