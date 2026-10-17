#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D5E50(void *self, int x, int y);
}

static void test_terrain_passable() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char cell[32];
    std::memset(cell, 0, sizeof(cell));
    cell[5] = 3; // terrain 3
    char *row0[1] = { cell };
    *reinterpret_cast<char ***>(zm + 0x98) = row0;

    float thresholds[5] = { 0.0f, 0.0f, 0.0f, 1.5f, 0.0f }; // terrain 3 threshold = 1.5 > 0
    *reinterpret_cast<float **>(zm + 0x9C) = thresholds;

    assert(func_001D5E50(zm, 0, 0) == 1);
}

static void test_terrain_impassable() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char cell[32];
    std::memset(cell, 0, sizeof(cell));
    cell[5] = 2; // terrain 2
    char *row0[1] = { cell };
    *reinterpret_cast<char ***>(zm + 0x98) = row0;

    float thresholds[5] = { 0.0f, 0.0f, 0.0f, 1.5f, 0.0f }; // terrain 2 threshold = 0.0 <= 0
    *reinterpret_cast<float **>(zm + 0x9C) = thresholds;

    assert(func_001D5E50(zm, 0, 0) == 0);
}

int main(int argc, char **argv) {
    test_terrain_passable();
    test_terrain_impassable();
    return 0;
}
