#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001CCE10(void *self, int x0, int y0, int x1, int y1, int width, int terrain_type);
}

// Emulate the fixed-point math helpers with 16.16 fixed point for 32-bit native testing
typedef long long int64_t;
extern "C" {
int64_t func_122690(int x) { return static_cast<int64_t>(x) << 16; }
int64_t func_122118(int64_t a, int64_t b) { return (a * b) >> 16; }
int64_t func_122058(int64_t a, int64_t b) { return a + b; }
int64_t func_1228E8(int64_t a) {
    double val = static_cast<double>(a) / 65536.0;
    return static_cast<int64_t>(std::sqrt(val) * 65536.0);
}
float func_1234E0(float f) { return f; }
int func_122748(int64_t a) {
    return static_cast<int>((a + 32768) >> 16);
}
int64_t func_1223C0(int64_t a, int64_t b) {
    if (b == 0) return 0;
    return (a << 16) / b;
}
int func_100100(int64_t a, int64_t b) {
    return (a == b) ? 0 : 1;
}
}

struct PointRecord {
    int x, y, radius, terrain;
};
static std::vector<PointRecord> g_history;

static int mock_paint_terrain(void *self, int x, int y, int radius, int terrain) {
    g_history.push_back({x, y, radius, terrain});
    return 1;
}

static void *g_vtable[10] = {
    nullptr, nullptr, nullptr, nullptr,
    reinterpret_cast<void *>(&mock_paint_terrain),
    nullptr, nullptr, nullptr, nullptr, nullptr
};

struct PaintLayout {
    void **vtable;
    char pad_4[4];
    int width;
    int height;
    char pad_10[0x8ED8];
    void *m_world;
};

static void setup_layout(PaintLayout *zm, int width, int height) {
    std::memset(zm, 0, sizeof(PaintLayout));
    zm->vtable = g_vtable;
    zm->width = width;
    zm->height = height;
    g_history.clear();
}

static void test_line_zero_length() {
    PaintLayout zm;
    setup_layout(&zm, 10, 10);

    int ret = func_001CCE10(&zm, 3, 3, 3, 3, 2, 5);
    assert(ret == 1);
    assert(!g_history.empty());
    assert(g_history[0].x == 3 && g_history[0].y == 3);
    assert(g_history[0].radius == 1); // 2 >> 1
    assert(g_history[0].terrain == 5);
}

static void test_line_single_step() {
    PaintLayout zm;
    setup_layout(&zm, 10, 10);

    int ret = func_001CCE10(&zm, 2, 3, 3, 3, 4, 7);
    assert(ret == 1);
    assert(g_history.size() >= 2);
    assert(g_history.front().x == 2 && g_history.front().y == 3);
    assert(g_history.back().x == 3 && g_history.back().y == 3);
}

static void test_line_multiple_directions() {
    const int dirs[4][4] = {
        {1, 1, 4, 4},   // +dx, +dy
        {4, 1, 1, 4},   // -dx, +dy
        {1, 4, 4, 1},   // +dx, -dy
        {4, 4, 1, 1}    // -dx, -dy
    };
    for (int i = 0; i < 4; i++) {
        PaintLayout zm;
        setup_layout(&zm, 10, 10);
        int ret = func_001CCE10(&zm, dirs[i][0], dirs[i][1], dirs[i][2], dirs[i][3], 2, 8);
        assert(ret == 1);
        assert(g_history.size() >= 4);
        assert(g_history.front().x == dirs[i][0] && g_history.front().y == dirs[i][1]);
        assert(g_history.back().x == dirs[i][2] && g_history.back().y == dirs[i][3]);
    }
}

static void test_line_boundary_clipping() {
    PaintLayout zm;
    setup_layout(&zm, 10, 10);

    // Endpoints outside [0, 9]
    int ret = func_001CCE10(&zm, -5, 2, 15, 2, 2, 6);
    assert(ret == 1);
    assert(!g_history.empty());
    for (size_t i = 0; i < g_history.size(); i++) {
        assert(g_history[i].x >= 0 && g_history[i].x < 10);
        assert(g_history[i].y >= 0 && g_history[i].y < 10);
    }
}

static void test_callback_order_and_return() {
    PaintLayout zm;
    setup_layout(&zm, 10, 10);

    int ret = func_001CCE10(&zm, 1, 1, 5, 1, 2, 9);
    assert(ret == 1);
    assert(g_history.size() >= 5);
    for (size_t i = 0; i < g_history.size() - 1; i++) {
        assert(g_history[i].x <= g_history[i + 1].x); // Monotonic order
        assert(g_history[i].y == 1);
    }
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "zero_length") {
        test_line_zero_length();
    } else if (argc > 1 && std::string(argv[1]) == "single_step") {
        test_line_single_step();
    } else if (argc > 1 && std::string(argv[1]) == "multiple_dirs") {
        test_line_multiple_directions();
    } else if (argc > 1 && std::string(argv[1]) == "clipping") {
        test_line_boundary_clipping();
    } else if (argc > 1 && std::string(argv[1]) == "callback_order") {
        test_callback_order_and_return();
    } else {
        test_line_zero_length();
        test_line_single_step();
        test_line_multiple_directions();
        test_line_boundary_clipping();
        test_callback_order_and_return();
    }
    return 0;
}
