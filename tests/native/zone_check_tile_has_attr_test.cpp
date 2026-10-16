#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D5A30(void *self, int x, int y);
}

static void test_check_tile_has_attr_matching() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xE4) = 10; // width 10
    *reinterpret_cast<int *>(zm + 0xE8) = 10; // height 10

    char cell[32];
    std::memset(cell, 0, sizeof(cell));
    char *row0[1] = { cell };
    *reinterpret_cast<char ***>(zm + 0x98) = row0;

    cell[0xD] = 1; // 1 item

    char info[32];
    std::memset(info, 0, sizeof(info));
    *reinterpret_cast<short *>(info + 0xE) = 8; // attr 8

    char item[16];
    std::memset(item, 0, sizeof(item));
    *reinterpret_cast<void **>(item + 4) = info;

    void *items[1] = { item };
    *reinterpret_cast<void ***>(cell + 0x14) = items;

    int res = func_001D5A30(zm, 0, 0);
    assert(res == 1); // found attr 8!

    *reinterpret_cast<short *>(info + 0xE) = 32; // attr 32 (0x20)
    res = func_001D5A30(zm, 0, 0);
    assert(res == 1); // found attr 32!

    *reinterpret_cast<short *>(info + 0xE) = 99; // attr other
    res = func_001D5A30(zm, 0, 0);
    assert(res == 0); // neither 8 nor 32
}

static void test_check_tile_oob() {
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));
    *reinterpret_cast<int *>(zm + 0xE4) = 5;
    *reinterpret_cast<int *>(zm + 0xE8) = 5;

    assert(func_001D5A30(zm, -1, 0) == 0);
    assert(func_001D5A30(zm, 5, 0) == 0);
    assert(func_001D5A30(zm, 0, -1) == 0);
    assert(func_001D5A30(zm, 0, 5) == 0);
}

int main(int argc, char **argv) {
    test_check_tile_has_attr_matching();
    test_check_tile_oob();
    return 0;
}
