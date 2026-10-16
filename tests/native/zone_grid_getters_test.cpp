#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void *func_001CB6A0(void *self);
int func_001CB6B0(void *self);
int func_001CB6C0(void *self);
void func_001CB4D0(void *self, void *stream);

// Callee mocks called by func_001CB4D0
static int g_1c98a0_calls = 0;
static void *g_1c98a0_self = nullptr;
static int g_1c98a0_w = -1, g_1c98a0_h = -1;

static int g_1cf3e0_calls = 0;
static short g_1cf3e0_maxx = -1, g_1cf3e0_maxy = -1;

static int g_1cf9b0_calls = 0;
static short g_1cf9b0_maxx = -1, g_1cf9b0_maxy = -1;

void func_1C98A0(void *self, int width, int height) {
    g_1c98a0_calls++;
    g_1c98a0_self = self;
    g_1c98a0_w = width;
    g_1c98a0_h = height;
}

void func_1CF3E0(void *self, int, int, short a3, short a4, int, int, int) {
    (void)self;
    g_1cf3e0_calls++;
    g_1cf3e0_maxx = a3;
    g_1cf3e0_maxy = a4;
}

void func_1CF9B0(void *self, int, int, int, int, short a5, short a6, int, long long, long long) {
    (void)self;
    g_1cf9b0_calls++;
    g_1cf9b0_maxx = a5;
    g_1cf9b0_maxy = a6;
}

// Stream read mock
struct GridStream {
    const unsigned char *data;
    size_t size;
    size_t offset;
};

void func_00226D90(void *stream, void *data, int size) {
    GridStream *s = static_cast<GridStream *>(stream);
    assert(s != nullptr && data != nullptr);
    assert(s->offset + size <= s->size);
    std::memcpy(data, s->data + s->offset, size);
    s->offset += size;
}
}

struct GetterCell {
    char pad_0[5];
    unsigned char f_5;
    unsigned char f_6;
    char pad_7[21];
};
static_assert(sizeof(GetterCell) == 28, "Cell size must be 28 bytes");

struct GetterLayout {
    char pad_0[8];
    int width;
    int height;
    char pad_10[0x8E7C];
    GetterCell **cells_ptr;
};

static void test_getters_exact_returns() {
    GetterLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.width = 42;
    zm.height = 84;
    GetterCell *dummy_cells = reinterpret_cast<GetterCell *>(0x12345678);
    zm.cells_ptr = &dummy_cells;

    assert(func_001CB6A0(&zm) == &dummy_cells);
    assert(func_001CB6B0(&zm) == 42);
    assert(func_001CB6C0(&zm) == 84);
}

static void test_grid_deserialize_stream_and_postload() {
    GetterLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.width = 2;
    zm.height = 2;

    GetterCell cells[2][2];
    std::memset(cells, 0, sizeof(cells));
    GetterCell *row_ptrs[2] = {cells[0], cells[1]};
    zm.cells_ptr = row_ptrs;

    // Stream payload:
    // 4B: w = 2
    // 4B: h = 2
    // 3B per cell: [0,0]={0x11, 0x22, 0x33}, [0,1]={0x44, 0x55, 0x66},
    //              [1,0]={0x77, 0x88, 0x99}, [1,1]={0xAA, 0xBB, 0xCC}
    // Total: 8 + 12 = 20 bytes
    unsigned char stream_payload[20] = {
        2, 0, 0, 0,  // w = 2
        2, 0, 0, 0,  // h = 2
        0x11, 0x22, 0x33, // cell (0,0)
        0x44, 0x55, 0x66, // cell (1,0)
        0x77, 0x88, 0x99, // cell (0,1)
        0xAA, 0xBB, 0xCC  // cell (1,1)
    };

    GridStream stream = {stream_payload, sizeof(stream_payload), 0};

    g_1c98a0_calls = 0;
    g_1cf3e0_calls = 0;
    g_1cf9b0_calls = 0;

    func_001CB4D0(&zm, &stream);

    // Verify func_1C98A0 called with width=2, height=2
    assert(g_1c98a0_calls == 1);
    assert(g_1c98a0_self == &zm);
    assert(g_1c98a0_w == 2 && g_1c98a0_h == 2);

    // Verify cell contents loaded from stream
    assert(cells[0][0].f_5 == 0x11 && cells[0][0].f_6 == 0x22);
    assert(cells[0][1].f_5 == 0x44 && cells[0][1].f_6 == 0x55);
    assert(cells[1][0].f_5 == 0x77 && cells[1][0].f_6 == 0x88);
    assert(cells[1][1].f_5 == 0xAA && cells[1][1].f_6 == 0xBB);

    // Verify post-load callbacks receive max_x = 1, max_y = 1
    assert(g_1cf3e0_calls == 1);
    assert(g_1cf3e0_maxx == 1 && g_1cf3e0_maxy == 1);

    assert(g_1cf9b0_calls == 1);
    assert(g_1cf9b0_maxx == 1 && g_1cf9b0_maxy == 1);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "grid_deserialize") {
        test_grid_deserialize_stream_and_postload();
    } else {
        test_getters_exact_returns();
    }
    return 0;
}
