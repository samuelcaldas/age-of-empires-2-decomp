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

typedef long long int64_t;
static std::vector<std::string> g_math_log;

extern "C" {
int64_t func_122690(int x) { g_math_log.push_back("122690"); return static_cast<int64_t>(x) << 16; }
int64_t func_122118(int64_t a, int64_t b) { g_math_log.push_back("122118"); return (a * b) >> 16; }
int64_t func_122058(int64_t a, int64_t b) { g_math_log.push_back("122058"); return a + b; }
float func_1228E8(int64_t a) {
    g_math_log.push_back("1228E8");
    return static_cast<float>(static_cast<double>(a) / 65536.0);
}
int64_t func_1234E0(float f) {
    g_math_log.push_back("1234E0");
    return static_cast<int64_t>(static_cast<double>(f) * 65536.0);
}
int func_122748(int64_t a) {
    g_math_log.push_back("122748");
    return static_cast<int>((a + 32768) >> 16);
}
int64_t func_1223C0(int64_t a, int64_t b) {
    g_math_log.push_back("1223C0");
    return (b == 0) ? 0 : (a << 16) / b;
}
int func_100100(int64_t a, int64_t b) {
    g_math_log.push_back("100100");
    return (a == b) ? 0 : 1;
}
}

struct PointRecord { int x, y, radius, terrain; };
static std::vector<PointRecord> g_history;
static int g_secondary_called = 0;

struct PaintLayout {
    void **vtable;
    char pad_4[4];
    int width, height;
    char pad_10[0x8ED8];
    void *m_world;
};

static int mock_paint_primary(void *self, int x, int y, int radius, int terrain);
static int mock_paint_secondary(void *self, int x, int y, int radius, int terrain);

static void *g_vtable1[10] = { nullptr, nullptr, nullptr, nullptr, (void *)&mock_paint_primary, nullptr };
static void *g_vtable2[10] = { nullptr, nullptr, nullptr, nullptr, (void *)&mock_paint_secondary, nullptr };

static int mock_paint_primary(void *self, int x, int y, int radius, int terrain) {
    g_history.push_back({x, y, radius, terrain});
    if (g_history.size() == 2) {
        reinterpret_cast<PaintLayout *>(self)->vtable = g_vtable2;
    }
    return 1;
}

static int mock_paint_secondary(void *self, int x, int y, int radius, int terrain) {
    g_secondary_called++;
    g_history.push_back({x, y, radius, terrain});
    return 1;
}

static void setup_layout(PaintLayout *zm, int width, int height) {
    std::memset(zm, 0, sizeof(PaintLayout));
    zm->vtable = g_vtable1;
    zm->width = width; zm->height = height;
    g_history.clear(); g_math_log.clear(); g_secondary_called = 0;
}

static void test_math_3_4_5_and_vtable_reload() {
    PaintLayout zm;
    setup_layout(&zm, 10, 10);
    // dx = 4 - 1 = 3, dy = 5 - 1 = 4 -> 3-4-5 triangle, hypotenuse distance = 5
    int ret = func_001CCE10(&zm, 1, 1, 4, 5, 2, 7);
    assert(ret == 1);
    assert(g_history.size() == 6); // 1 start + 5 steps

    // Verify exact coordinates and inputs for all 6 points along the 3-4-5 line
    const PointRecord expected_pts[6] = {
        {1, 1, 1, 7}, // start (1, 1)
        {2, 2, 1, 7}, // step 1 (1.6 -> 2, 1.8 -> 2)
        {2, 3, 1, 7}, // step 2 (2.2 -> 2, 2.6 -> 3)
        {3, 3, 1, 7}, // step 3 (2.8 -> 3, 3.4 -> 3)
        {3, 4, 1, 7}, // step 4 (3.4 -> 3, 4.2 -> 4)
        {4, 5, 1, 7}  // step 5 (4.0 -> 4, 5.0 -> 5)
    };
    for (size_t i = 0; i < 6; i++) {
        assert(g_history[i].x == expected_pts[i].x);
        assert(g_history[i].y == expected_pts[i].y);
        assert(g_history[i].radius == expected_pts[i].radius);
        assert(g_history[i].terrain == expected_pts[i].terrain);
    }

    // Verifies vtable swap during callback was dynamically honored on subsequent steps
    assert(g_secondary_called > 0);

    // Verifies exact math helper sequence
    assert(g_math_log.size() >= 13);
    assert(g_math_log[0] == "122690"); // dx_fp
    assert(g_math_log[1] == "122690"); // dy_fp
    assert(g_math_log[2] == "122118"); // dx2
    assert(g_math_log[3] == "122118"); // dy2
    assert(g_math_log[4] == "122058"); // sum2
    assert(g_math_log[5] == "1228E8"); // float sum_flt
    assert(g_math_log[6] == "1234E0"); // dist_fp from sqrtf
    assert(g_math_log[7] == "122748"); // steps = 5
    assert(g_math_log[8] == "122690"); // steps_fp
    assert(g_math_log[9] == "1223C0"); // step_x
    assert(g_math_log[10] == "1223C0"); // step_y
    assert(g_math_log[11] == "122690"); // cur_x
    assert(g_math_log[12] == "122690"); // cur_y
}

static void test_line_directions_and_clipping() {
    const int dirs[4][4] = {{1,1,4,4},{4,1,1,4},{1,4,4,1},{4,4,1,1}};
    for (int i = 0; i < 4; i++) {
        PaintLayout zm;
        setup_layout(&zm, 10, 10);
        assert(func_001CCE10(&zm, dirs[i][0], dirs[i][1], dirs[i][2], dirs[i][3], 2, 8) == 1);
        assert(g_history.size() >= 4);
    }

    PaintLayout zm_clip;
    setup_layout(&zm_clip, 10, 10);
    assert(func_001CCE10(&zm_clip, -5, 2, 15, 2, 2, 6) == 1);
    for (size_t i = 0; i < g_history.size(); i++) {
        assert(g_history[i].x >= 0 && g_history[i].x < 10);
    }
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "math_3_4_5") {
        test_math_3_4_5_and_vtable_reload();
    } else if (argc > 1 && std::string(argv[1]) == "directions_clipping") {
        test_line_directions_and_clipping();
    } else {
        test_math_3_4_5_and_vtable_reload();
        test_line_directions_and_clipping();
    }
    return 0;
}
