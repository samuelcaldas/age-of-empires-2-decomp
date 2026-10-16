#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");
static_assert(sizeof(int) == 4, "native fixture requires 32-bit integers");

// --- Declarations from production headers ---
extern "C" {
void func_001CAC00(void *self, short *buffer, short dx, short dy);
void func_001CAC90(void *self, void *stream);
void func_001C9FA0(void *self, int x0, int y0, int x1, int y1);
int func_001CA430(void *self, int x0, int y0, int x1, int y1);
int func_001CA560(void *self, int x, int y, int *out_x, int *out_y);
int func_001CA670(void *self, int x, int y, int *out_x1, int *out_y1, int *out_x2, int *out_y2);

// Mock stream callee called by func_001CAC90
void func_00226F70(void *stream, void *data, int size);

// Mock delta table for func_001CA560 and func_001CA670
int D_00392020[16] = {0, 1, 2, 3, 4, 5, 6, 7, -8, -7, -6, -5, -4, -3, -2, -1};
}

// Mock stream recorder
struct StreamRecord {
    std::vector<unsigned char> bytes;
};

static StreamRecord g_stream;

void func_00226F70(void *stream, void *data, int size) {
    assert(stream == &g_stream);
    assert(data != nullptr);
    assert(size > 0);
    const unsigned char *p = static_cast<const unsigned char *>(data);
    g_stream.bytes.insert(g_stream.bytes.end(), p, p + size);
}

// Layout definitions matching production C++
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
    char pad_D[15];         // to reach 0x1C (28 bytes)
};
static_assert(sizeof(TestCell) == 28, "TestCell must be 28 bytes");

struct TestZoneLayout {
    char pad_0[8];          // 0x0..0x7
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

// -----------------------------------------------------------------------------
// Test 1: zone_perimeter_point (func_001CAC00)
// -----------------------------------------------------------------------------
static void test_perimeter_point_null_and_zero() {
    // Null buffer must not crash
    func_001CAC00(nullptr, nullptr, 5, 5);

    // dx == 0 && dy == 0 must return immediately with buffer unchanged
    short buf[16];
    std::memset(buf, 0x55, sizeof(buf));
    buf[0] = 0;   // count = 0
    buf[1] = 5;   // capacity = 5
    func_001CAC00(nullptr, buf, 0, 0);
    assert(buf[0] == 0);
    assert(buf[1] == 5);
}

static void test_perimeter_point_deduplication_and_capacity() {
    short buf[32];
    std::memset(buf, 0xEE, sizeof(buf));
    buf[0] = 0;   // count = 0
    buf[1] = 2;   // capacity = 2

    // Insert first point
    func_001CAC00(nullptr, buf, 10, 20);
    assert(buf[0] == 1);
    assert(buf[2] == 10);
    assert(buf[3] == 20);

    // Insert duplicate point -> must not add, count stays 1
    func_001CAC00(nullptr, buf, 10, 20);
    assert(buf[0] == 1);

    // Insert second point -> reaches capacity 2
    func_001CAC00(nullptr, buf, 30, 40);
    assert(buf[0] == 2);
    assert(buf[4] == 30);
    assert(buf[5] == 40);

    // Insert third point -> capacity full (count >= capacity), must not add
    func_001CAC00(nullptr, buf, 50, 60);
    assert(buf[0] == 2);
    // Sentinel check: buf[6] and buf[7] must remain untouched (0xEEEE)
    assert(buf[6] == static_cast<short>(0xEEEE));
    assert(buf[7] == static_cast<short>(0xEEEE));
}

static void test_perimeter_point_many_points() {
    short buf[64];
    std::memset(buf, 0, sizeof(buf));
    buf[0] = 0;
    buf[1] = 10;

    const short points[][2] = {
        {1, 2}, {-3, 4}, {5, -6}, {-7, -8}, {9, 10}
    };
    for (int i = 0; i < 5; i++) {
        func_001CAC00(nullptr, buf, points[i][0], points[i][1]);
    }
    assert(buf[0] == 5);
    for (int i = 0; i < 5; i++) {
        assert(buf[(i + 1) * 2 + 0] == points[i][0]);
        assert(buf[(i + 1) * 2 + 1] == points[i][1]);
    }
}

// -----------------------------------------------------------------------------
// Test 2: zone_raster_serialize (func_001CAC90)
// -----------------------------------------------------------------------------
static void test_raster_serialize_zero_extents() {
    TestZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.f_8ED0 = 0;   // 0 extents
    zm.f_8ED4 = 123; // search limit

    g_stream.bytes.clear();
    func_001CAC90(&zm, &g_stream);

    // Exactly 8 bytes: f_8ED0 (0) and f_8ED4 (123)
    assert(g_stream.bytes.size() == 8);
    int count = 0, limit = 0;
    std::memcpy(&count, g_stream.bytes.data(), 4);
    std::memcpy(&limit, g_stream.bytes.data() + 4, 4);
    assert(count == 0);
    assert(limit == 123);
}

static void test_raster_serialize_multiple_extents() {
    TestZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.f_8ED0 = 2;
    zm.f_8ED4 = 50;

    int extents[2] = {0x01020304, 0x05060708};
    zm.f_8ED8 = extents;

    short buf0[8] = {1, 4, 10, 20, 0, 0, 0, 0};       // 1 point
    short buf1[8] = {2, 4, 30, 40, 50, 60, 0, 0};       // 2 points
    short *buffers[2] = {buf0, buf1};
    zm.f_8EDC = buffers;

    g_stream.bytes.clear();
    func_001CAC90(&zm, &g_stream);

    // Expected byte sequence:
    // 4B: f_8ED0 (2)
    // 4B: f_8ED4 (50)
    // 8B: extents array (extents[0], extents[1])
    // 4B: buf0 point count (1)
    // 4B: buf0 point (10, 20)
    // 4B: buf1 point count (2)
    // 8B: buf1 points ((30, 40), (50, 60))
    // Total: 4 + 4 + 8 + 4 + 4 + 4 + 8 = 36 bytes
    assert(g_stream.bytes.size() == 36);

    const unsigned char *data = g_stream.bytes.data();
    int read_count, read_limit;
    std::memcpy(&read_count, data, 4);
    std::memcpy(&read_limit, data + 4, 4);
    assert(read_count == 2);
    assert(read_limit == 50);

    int read_ext[2];
    std::memcpy(read_ext, data + 8, 8);
    assert(read_ext[0] == 0x01020304);
    assert(read_ext[1] == 0x05060708);

    int pt_count0;
    std::memcpy(&pt_count0, data + 16, 4);
    assert(pt_count0 == 1);
    short pt0[2];
    std::memcpy(pt0, data + 20, 4);
    assert(pt0[0] == 10 && pt0[1] == 20);

    int pt_count1;
    std::memcpy(&pt_count1, data + 24, 4);
    assert(pt_count1 == 2);
    short pt1[4];
    std::memcpy(pt1, data + 28, 8);
    assert(pt1[0] == 30 && pt1[1] == 40);
    assert(pt1[2] == 50 && pt1[3] == 60);
}

// -----------------------------------------------------------------------------
// Test 3: zone_rect_update (func_001C9FA0)
// -----------------------------------------------------------------------------
static void test_rect_update_calculations_and_mask_subtraction() {
    TestZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.width = 8;
    zm.height = 8;
    zm.f_8EB2 = 3;   // scale factor 1
    zm.f_8EB4 = 5;   // scale factor 2
    zm.f_8EB6 = 7;   // edge subtraction factor

    TestCell cells[8][8];
    std::memset(cells, 0, sizeof(cells));
    TestCell *row_ptrs[8];
    for (int y = 0; y < 8; y++) {
        row_ptrs[y] = cells[y];
    }
    zm.cells_ptr = row_ptrs;

    // Set special edge flags for test
    cells[2][2].f_4 = 15; // mask hit -> subtracts f_8EB6
    cells[2][3].f_4 = 16; // mask hit
    cells[3][2].f_4 = 2;  // mask hit
    cells[3][3].f_4 = 99; // no mask hit -> no subtraction

    // Call update with clamping bounds [-2, -2, 10, 10]
    func_001C9FA0(&zm, -2, -2, 10, 10);

    // Verify cell at (2, 2):
    // f_0 = (2 + 2) * f_8EB4 = 4 * 5 = 20
    // base f_2 = (2 - 2) * f_8EB2 - f_6 * f_8EB6 = 0
    // With f_4 == 15, f_2 = base - f_8EB6 = 0 - 7 = -7
    assert(cells[2][2].f_0 == 20);
    assert(cells[2][2].f_2 == -7);

    // Verify cell at (3, 3):
    // f_0 = (3 + 3) * 5 = 30
    // base f_2 = (3 - 3) * 3 - 0 = 0
    // With f_4 == 99, f_2 = 0 (no subtraction)
    assert(cells[3][3].f_0 == 30);
    assert(cells[3][3].f_2 == 0);
}

// -----------------------------------------------------------------------------
// Test 4: zone_raster_untag (func_001CA430)
// -----------------------------------------------------------------------------
static void test_raster_untag_clears_cells() {
    TestZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.width = 6;
    zm.height = 6;

    TestCell cells[6][6];
    std::memset(cells, 0x7F, sizeof(cells));
    TestCell *row_ptrs[6];
    for (int y = 0; y < 6; y++) {
        row_ptrs[y] = cells[y];
    }
    zm.cells_ptr = row_ptrs;

    // Degenerate rect returns 1 without change
    int res = func_001CA430(&zm, 1, 1, 1, 1);
    assert(res == 1);
    assert(cells[1][1].f_C == static_cast<unsigned char>(0x7F));

    // Clear rectangle [1, 2] x [1, 2]
    res = func_001CA430(&zm, 1, 1, 2, 2);
    assert(res == 1);
    for (int y = 1; y <= 2; y++) {
        for (int x = 1; x <= 2; x++) {
            assert(cells[y][x].f_C == 0);
            assert(cells[y][x].f_B == (0x7F & 0x9F));
        }
    }
    // Outside cell untouched
    assert(cells[0][0].f_C == static_cast<unsigned char>(0x7F));
    assert(cells[0][0].f_B == static_cast<unsigned char>(0x7F));
}

// -----------------------------------------------------------------------------
// Test 5: zone_raster_trace (func_001CA560)
// -----------------------------------------------------------------------------
static void test_raster_trace_backtracking() {
    TestZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.width = 5;
    zm.height = 5;

    TestCell cells[5][5];
    std::memset(cells, 0, sizeof(cells));
    TestCell *row_ptrs[5];
    for (int y = 0; y < 5; y++) {
        row_ptrs[y] = cells[y];
    }
    zm.cells_ptr = row_ptrs;

    // Origin cell at (1, 1) has tag 0x40
    cells[1][1].f_B = 0x40;

    // Cell at (2, 3) has tag 0x20 and delta nibbles dx=1 (nibble 1), dy=2 (nibble 2)
    // val = (2 << 4) | 1 = 0x21
    cells[3][2].f_B = 0x20;
    cells[3][2].f_C = 0x21;

    int out_x = -1, out_y = -1;
    // Trace starting from (2, 3) -> should step dx=1, dy=2 to (1, 1) and find origin!
    int ok = func_001CA560(&zm, 2, 3, &out_x, &out_y);
    assert(ok == 1);
    assert(out_x == 1);
    assert(out_y == 1);

    // Trace from cell with tag 0x20 but zero deltas -> returns 0 (stationary loop termination)
    cells[4][4].f_B = 0x20;
    cells[4][4].f_C = 0x00;
    ok = func_001CA560(&zm, 4, 4, &out_x, &out_y);
    assert(ok == 0);

    // Trace from out of bounds coordinates -> returns 0
    ok = func_001CA560(&zm, -1, 2, &out_x, &out_y);
    assert(ok == 0);
    ok = func_001CA560(&zm, 5, 2, &out_x, &out_y);
    assert(ok == 0);
}

// -----------------------------------------------------------------------------
// Test 6: zone_raster_extent (func_001CA670)
// -----------------------------------------------------------------------------
static void test_raster_extent_resolution() {
    TestZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.width = 10;
    zm.height = 10;

    TestCell cells[10][10];
    std::memset(cells, 0, sizeof(cells));
    TestCell *row_ptrs[10];
    for (int y = 0; y < 10; y++) {
        row_ptrs[y] = cells[y];
    }
    zm.cells_ptr = row_ptrs;

    // Extents table with packed 4 signed bytes at index 0: left=1, top=2, right=3, bottom=4
    // packed = 0x04030201
    int packed_table[4] = {0x04030201, 0, 0, 0};
    zm.f_8ED8 = packed_table;

    // Origin cell at (5, 5) with tag 0x40 and index = 1 (f_C = 1)
    cells[5][5].f_B = 0x40;
    cells[5][5].f_C = 1;

    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    int ok = func_001CA670(&zm, 5, 5, &x1, &y1, &x2, &y2);
    assert(ok == 1);
    // Extents:
    // x1 = 5 - 1 = 4
    // y1 = 5 - 2 = 3
    // x2 = 5 + 3 = 8
    // y2 = 5 + 4 = 9
    assert(x1 == 4);
    assert(y1 == 3);
    assert(x2 == 8);
    assert(y2 == 9);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_perimeter_point_null_and_zero();
        test_perimeter_point_deduplication_and_capacity();
        test_perimeter_point_many_points();
        test_raster_serialize_zero_extents();
        test_raster_serialize_multiple_extents();
        test_rect_update_calculations_and_mask_subtraction();
        test_raster_untag_clears_cells();
        test_raster_trace_backtracking();
        test_raster_extent_resolution();
        return 0;
    }

    const char *test_name = argv[1];
    if (std::strcmp(test_name, "perimeter_null_zero") == 0) {
        test_perimeter_point_null_and_zero();
    } else if (std::strcmp(test_name, "perimeter_dedup_cap") == 0) {
        test_perimeter_point_deduplication_and_capacity();
    } else if (std::strcmp(test_name, "perimeter_many") == 0) {
        test_perimeter_point_many_points();
    } else if (std::strcmp(test_name, "serialize_zero") == 0) {
        test_raster_serialize_zero_extents();
    } else if (std::strcmp(test_name, "serialize_many") == 0) {
        test_raster_serialize_multiple_extents();
    } else if (std::strcmp(test_name, "rect_update") == 0) {
        test_rect_update_calculations_and_mask_subtraction();
    } else if (std::strcmp(test_name, "raster_untag") == 0) {
        test_raster_untag_clears_cells();
    } else if (std::strcmp(test_name, "raster_trace") == 0) {
        test_raster_trace_backtracking();
    } else if (std::strcmp(test_name, "raster_extent") == 0) {
        test_raster_extent_resolution();
    } else {
        return 1;
    }
    return 0;
}
