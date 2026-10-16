#pragma once

#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");
static_assert(sizeof(int) == 4, "native fixture requires 32-bit integers");

struct TestCell {
    short f_0;              // 0x0
    short f_2;              // 0x2
    unsigned char f_4;      // 0x4
    unsigned char f_5;      // 0x5
    unsigned char f_6;      // 0x6
    unsigned char f_7;      // 0x7
    char pad_8[3];          // 0x8..0xA
    unsigned char f_B;      // 0xB (11)
    unsigned char f_C;      // 0xC (12)
    char pad_D[3];          // 0xD..0xF
    void *f_10;             // 0x10
    char pad_14[8];         // to reach 0x1C (28 bytes)
};
static_assert(sizeof(TestCell) == 28, "TestCell must be 28 bytes");

struct TestZoneLayout {
    char pad_0[4];          // 0x0..0x3
    int child_count;        // 0x4
    int width;              // 0x8
    int height;             // 0xC
    char pad_10[0x8E7C];    // 0x10..0x8E8B
    TestCell **cells_ptr;   // 0x8E8C (-0x7174)
    char pad_8E90[0x22];    // 0x8E90..0x8EB1
    short f_8EB2;           // 0x8EB2 (-0x714E)
    short f_8EB4;           // 0x8EB4 (-0x714C)
    short f_8EB6;           // 0x8EB6 (-0x714A)
    char pad_8EB8[0x18];    // 0x8EB8..0x8ECF
    int f_8ED0;             // 0x8ED0 (-28976)
    int f_8ED4;             // 0x8ED4 (-28972)
    int *f_8ED8;            // 0x8ED8 (-28968)
    short **f_8EDC;         // 0x8EDC (-28964)
};

struct StreamRecord {
    std::vector<unsigned char> bytes;
};

extern StreamRecord g_stream;
extern size_t g_read_offset;
extern int g_alloc_count;
extern int g_free_count;
