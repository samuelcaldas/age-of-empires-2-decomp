#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CD770(void *self, void *stream);

static std::vector<int> g_resize_calls;
static int g_ai_teardown_calls = 0;
static int g_ai_load_calls = 0;
static int g_raster_load_calls = 0;
static int g_comp_load_calls = 0;
static int g_cf3e0_calls = 0;
static int g_cf9b0_calls = 0;

void func_1C98A0(void *self, int width, int height) {
    g_resize_calls.push_back(width);
    g_resize_calls.push_back(height);
}

void func_335560(void *ai_mgr) { g_ai_teardown_calls++; }
void func_335470(void *ai_mgr, void *stream, void *self) { g_ai_load_calls++; }
void func_1CAD90(void *self, void *stream) { g_raster_load_calls++; }
void func_138830(void *obj, void *stream) { g_comp_load_calls++; }
void func_1CF3E0(void *self, int x0, int y0, int x1, int y1, int p5, int p6, int p7) { g_cf3e0_calls++; }
void func_1CF9B0(void *self, int p1, void *world, int p3, int p4, int x1, int y1, int p7) { g_cf9b0_calls++; }

void *D_4E2DF0 = reinterpret_cast<void *>(0x11111111);
float D_004E2F24 = 11.5f;
float D_004E29E8 = 9.09f;
float D_004E29EC = 10.8f;

struct StreamMock {
    const unsigned char *data;
    size_t offset;
    size_t length;
};

int func_226D90(void *stream, void *dst, int size) {
    StreamMock *s = reinterpret_cast<StreamMock *>(stream);
    assert(s->offset + size <= s->length);
    std::memcpy(dst, s->data + s->offset, size);
    s->offset += size;
    return size;
}
}

struct TestCell {
    short f_0, f_2;
    char pad_4;
    char f_5, f_6, f_7, f_8, f_9, f_A, f_B, f_C, f_D, f_E, f_F;
    void *f_10, *f_14;
    char pad_18[4];
};
static_assert(sizeof(TestCell) == 28, "Cell size must be 28 bytes");

struct TestLayout {
    char pad_0[8];
    int width, height;
    char pad_10[0x8E7C];
    TestCell **cells_ptr;
    char pad_8E90[0x22];
    short f_8EB2, f_8EB4, f_8EB6;
    char pad_8EB8[0x15];
    char f_8ECD, f_8ECE;
    char pad_8ECF[0x19];
    void *m_world, *f_8EEC, *f_8EF0;
};

static void reset_counters() {
    g_resize_calls.clear();
    g_ai_teardown_calls = 0; g_ai_load_calls = 0;
    g_raster_load_calls = 0; g_comp_load_calls = 0;
    g_cf3e0_calls = 0; g_cf9b0_calls = 0;
}

static void test_deserialize_full_flow() {
    reset_counters();
    D_004E2F24 = 11.5f; // All versions pass

    TestLayout zm;
    std::memset(&zm, 0, sizeof(TestLayout));
    zm.width = 2; zm.height = 2;
    zm.f_8EB2 = 10; zm.f_8EB4 = 20; zm.f_8EB6 = 5;
    zm.f_8EEC = reinterpret_cast<void *>(0x22222222);

    TestCell cells[2][2];
    std::memset(cells, 0, sizeof(cells));
    TestCell *row_ptrs[2] = {cells[0], cells[1]};
    zm.cells_ptr = row_ptrs;

    // Stream: width(4), height(4), byte1(0xAA), byte2(0xBB), 4 cells of [terrain, elev]
    unsigned char buffer[64];
    size_t off = 0;
    int w = 2, h = 2;
    std::memcpy(buffer + off, &w, 4); off += 4;
    std::memcpy(buffer + off, &h, 4); off += 4;
    buffer[off++] = 0xAA; // f_8ECD
    buffer[off++] = 0xBB; // f_8ECE
    // Cell (0,0): terrain 3, elev 4
    buffer[off++] = 3; buffer[off++] = 4;
    // Cell (0,1): terrain 5, elev 2
    buffer[off++] = 5; buffer[off++] = 2;
    // Cell (1,0): terrain 1, elev 6
    buffer[off++] = 1; buffer[off++] = 6;
    // Cell (1,1): terrain 7, elev 3
    buffer[off++] = 7; buffer[off++] = 3;

    StreamMock stream = {buffer, 0, off};
    func_001CD770(&zm, &stream);

    assert(g_resize_calls.size() == 2 && g_resize_calls[0] == 2 && g_resize_calls[1] == 2);
    assert(g_ai_teardown_calls == 1);
    assert(g_ai_load_calls == 1);
    assert(zm.f_8ECD == (char)0xAA && zm.f_8ECE == (char)0xBB);

    // Verify cell (0, 0)
    assert(cells[0][0].f_5 == 3 && cells[0][0].f_6 == 4);
    assert(cells[0][0].f_8 == -1 && cells[0][0].f_E == -1);
    assert(cells[0][0].f_0 == 0); // (0+0)*20
    assert(cells[0][0].f_2 == -20); // (0-0)*10 - 4*5

    // Verify callbacks executed
    assert(g_raster_load_calls == 1);
    assert(g_comp_load_calls == 1);
    assert(g_cf3e0_calls == 1);
    assert(g_cf9b0_calls == 1);
}

static void test_version_below_grid() {
    reset_counters();
    D_004E2F24 = 5.0f; // Version < 7.0f

    TestLayout zm;
    std::memset(&zm, 0, sizeof(TestLayout));
    zm.width = 2; zm.height = 2;
    TestCell cells[2][2];
    std::memset(cells, 0, sizeof(cells));
    TestCell *row_ptrs[2] = {cells[0], cells[1]};
    zm.cells_ptr = row_ptrs;

    unsigned char buffer[16];
    int w = 2, h = 2;
    std::memcpy(buffer, &w, 4);
    std::memcpy(buffer + 4, &h, 4);
    buffer[8] = 0x11; buffer[9] = 0x22;
    StreamMock stream = {buffer, 0, 10};

    func_001CD770(&zm, &stream);

    assert(g_resize_calls.size() == 2);
    assert(g_raster_load_calls == 0); // Skipped
    assert(g_cf3e0_calls == 0);       // Skipped
    assert(g_comp_load_calls == 1);   // Always called
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "below_grid") {
        test_version_below_grid();
    } else {
        test_deserialize_full_flow();
        test_version_below_grid();
    }
    return 0;
}
