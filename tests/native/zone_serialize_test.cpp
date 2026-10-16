#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CDA40(void *self, void *stream);

static int g_ai_save_calls = 0;
static int g_raster_save_calls = 0;
static int g_comp_save_calls = 0;

void func_3355C0(void *ai_mgr, void *stream) { g_ai_save_calls++; }
void func_1CAC90(void *self, void *stream) { g_raster_save_calls++; }
void func_1388E0(void *obj, void *stream) { g_comp_save_calls++; }

float D_004E2F24 = 11.5f;

struct StreamOutMock {
    unsigned char buffer[128];
    size_t size;
};

int func_226F70(void *stream, void *src, int size) {
    StreamOutMock *s = reinterpret_cast<StreamOutMock *>(stream);
    assert(s->size + size <= sizeof(s->buffer));
    std::memcpy(s->buffer + s->size, src, size);
    s->size += size;
    return size;
}
}

struct TestCell {
    char pad_0[5];
    char f_5, f_6;
    char pad_7[21];
};
static_assert(sizeof(TestCell) == 28, "Cell size must be 28 bytes");

struct TestLayout {
    char pad_0[8];
    int width, height;
    char pad_10[0x8E7C];
    TestCell **cells_ptr;
    char pad_8E90[0x3D];
    char f_8ECD, f_8ECE;
    char pad_8ECF[0x1D];
    void *f_8EEC, *m_world;
    char pad_8EF0[4];
    void *f_8EF0;
};

static void reset_counters() {
    g_ai_save_calls = 0;
    g_raster_save_calls = 0;
    g_comp_save_calls = 0;
}

static void test_serialize_full_flow() {
    reset_counters();
    D_004E2F24 = 11.5f;

    TestLayout zm;
    std::memset(&zm, 0, sizeof(TestLayout));
    zm.width = 2; zm.height = 2;
    zm.f_8ECD = (char)0xAA;
    zm.f_8ECE = (char)0xBB;
    zm.f_8EEC = reinterpret_cast<void *>(0x33333333);
    zm.f_8EF0 = reinterpret_cast<void *>(0x44444444);

    TestCell cells[2][2];
    std::memset(cells, 0, sizeof(cells));
    cells[0][0].f_5 = 3; cells[0][0].f_6 = 4;
    cells[0][1].f_5 = 5; cells[0][1].f_6 = 2;
    cells[1][0].f_5 = 1; cells[1][0].f_6 = 6;
    cells[1][1].f_5 = 7; cells[1][1].f_6 = 3;

    TestCell *row_ptrs[2] = {cells[0], cells[1]};
    zm.cells_ptr = row_ptrs;

    StreamOutMock stream;
    stream.size = 0;
    func_001CDA40(&zm, &stream);

    assert(g_ai_save_calls == 1);
    assert(g_raster_save_calls == 1);
    assert(g_comp_save_calls == 1);

    // Verify stream payload: width(4), height(4), flags(2), 4 cells of (t, e) = 4+4+2+8 = 18 bytes
    assert(stream.size == 18);
    int w, h;
    std::memcpy(&w, stream.buffer, 4);
    std::memcpy(&h, stream.buffer + 4, 4);
    assert(w == 2 && h == 2);
    assert(stream.buffer[8] == 0xAA && stream.buffer[9] == 0xBB);

    // Cell (0, 0)
    assert(stream.buffer[10] == 3 && stream.buffer[11] == 4);
    // Cell (0, 1)
    assert(stream.buffer[12] == 5 && stream.buffer[13] == 2);
    // Cell (1, 0)
    assert(stream.buffer[14] == 1 && stream.buffer[15] == 6);
    // Cell (1, 1)
    assert(stream.buffer[16] == 7 && stream.buffer[17] == 3);
}

static void test_serialize_version_below_7() {
    reset_counters();
    D_004E2F24 = 5.0f; // Version < 7.0f -> skips grid dump

    TestLayout zm;
    std::memset(&zm, 0, sizeof(TestLayout));
    zm.width = 2; zm.height = 2;
    zm.f_8ECD = (char)0x11;
    zm.f_8ECE = (char)0x22;

    TestCell cells[2][2];
    std::memset(cells, 0, sizeof(cells));
    TestCell *row_ptrs[2] = {cells[0], cells[1]};
    zm.cells_ptr = row_ptrs;

    StreamOutMock stream;
    stream.size = 0;
    func_001CDA40(&zm, &stream);

    assert(g_ai_save_calls == 1);
    assert(g_raster_save_calls == 1);
    assert(g_comp_save_calls == 1);

    // Only header written: width(4) + height(4) + flags(2) = 10 bytes
    assert(stream.size == 10);
    assert(stream.buffer[8] == 0x11 && stream.buffer[9] == 0x22);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "below_7") {
        test_serialize_version_below_7();
    } else {
        test_serialize_full_flow();
        test_serialize_version_below_7();
    }
    return 0;
}
