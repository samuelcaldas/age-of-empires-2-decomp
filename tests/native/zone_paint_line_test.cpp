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
struct MathLogEntry {
    std::string fn;
    int64_t in_a, in_b;
    float in_f;
    int64_t out_val;
    float out_f;
};
static std::vector<MathLogEntry> g_math_calls;

extern "C" {
int64_t func_122690(int x) {
    int64_t res = static_cast<int64_t>(x) << 16;
    g_math_calls.push_back({"122690", x, 0, 0.0f, res, 0.0f});
    return res;
}
int64_t func_122118(int64_t a, int64_t b) {
    int64_t res = (a * b) >> 16;
    g_math_calls.push_back({"122118", a, b, 0.0f, res, 0.0f});
    return res;
}
int64_t func_122058(int64_t a, int64_t b) {
    int64_t res = a + b;
    g_math_calls.push_back({"122058", a, b, 0.0f, res, 0.0f});
    return res;
}
float func_1228E8(int64_t a) {
    float res = static_cast<float>(static_cast<double>(a) / 65536.0);
    g_math_calls.push_back({"1228E8", a, 0, 0.0f, 0, res});
    return res;
}
int64_t func_1234E0(float f) {
    int64_t res = static_cast<int64_t>(static_cast<double>(f) * 65536.0);
    g_math_calls.push_back({"1234E0", 0, 0, f, res, 0.0f});
    return res;
}
int func_122748(int64_t a) {
    int res = static_cast<int>((a + 32768) >> 16);
    g_math_calls.push_back({"122748", a, 0, 0.0f, res, 0.0f});
    return res;
}
int64_t func_1223C0(int64_t a, int64_t b) {
    int64_t res = (b == 0) ? 0 : (a << 16) / b;
    g_math_calls.push_back({"1223C0", a, b, 0.0f, res, 0.0f});
    return res;
}
int func_100100(int64_t a, int64_t b) {
    int res = (a == b) ? 0 : 1;
    g_math_calls.push_back({"100100", a, b, 0.0f, res, 0.0f});
    return res;
}
}

struct PointRecord { int x, y, radius, terrain; };
static std::vector<PointRecord> g_history;
static int g_secondary_called = 0;
static void *g_expected_zm = nullptr;

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
    assert(self != nullptr);
    assert(self == g_expected_zm);
    g_history.push_back({x, y, radius, terrain});
    if (g_history.size() == 2) {
        reinterpret_cast<PaintLayout *>(self)->vtable = g_vtable2;
    }
    return 1;
}

static int mock_paint_secondary(void *self, int x, int y, int radius, int terrain) {
    assert(self != nullptr);
    assert(self == g_expected_zm);
    g_secondary_called++;
    g_history.push_back({x, y, radius, terrain});
    return 1;
}

static void setup_layout(PaintLayout *zm, int width, int height) {
    std::memset(zm, 0, sizeof(PaintLayout));
    zm->vtable = g_vtable1;
    zm->width = width; zm->height = height;
    g_expected_zm = zm;
    g_history.clear(); g_math_calls.clear(); g_secondary_called = 0;
}

static void test_math_3_4_5_and_vtable_reload() {
    PaintLayout zm;
    setup_layout(&zm, 10, 10);
    int ret = func_001CCE10(&zm, 1, 1, 4, 5, 2, 7);
    assert(ret == 1);
    assert(g_history.size() == 6);

    const PointRecord expected_pts[6] = {
        {1, 1, 1, 7}, {2, 2, 1, 7}, {2, 3, 1, 7},
        {3, 3, 1, 7}, {3, 4, 1, 7}, {4, 5, 1, 7}
    };
    for (size_t i = 0; i < 6; i++) {
        assert(g_history[i].x == expected_pts[i].x);
        assert(g_history[i].y == expected_pts[i].y);
        assert(g_history[i].radius == expected_pts[i].radius);
        assert(g_history[i].terrain == expected_pts[i].terrain);
    }
    assert(g_secondary_called > 0);

    // Verify exact math pipeline and exact fixed-point step interpolation
    assert(g_math_calls.size() >= 13);
    assert(g_math_calls[0].fn == "122690" && g_math_calls[0].in_a == 3 && g_math_calls[0].out_val == 196608); // dx
    assert(g_math_calls[1].fn == "122690" && g_math_calls[1].in_a == 4 && g_math_calls[1].out_val == 262144); // dy
    assert(g_math_calls[2].fn == "122118" && g_math_calls[2].in_a == 196608 && g_math_calls[2].out_val == 589824); // dx2
    assert(g_math_calls[3].fn == "122118" && g_math_calls[3].in_a == 262144 && g_math_calls[3].out_val == 1048576); // dy2
    assert(g_math_calls[4].fn == "122058" && g_math_calls[4].in_a == 589824 && g_math_calls[4].in_b == 1048576 && g_math_calls[4].out_val == 1638400); // sum2
    assert(g_math_calls[5].fn == "1228E8" && g_math_calls[5].in_a == 1638400 && g_math_calls[5].out_f == 25.0f); // sum_flt
    assert(g_math_calls[6].fn == "1234E0" && g_math_calls[6].in_f == 5.0f && g_math_calls[6].out_val == 327680); // dist_fp
    assert(g_math_calls[7].fn == "122748" && g_math_calls[7].in_a == 327680 && g_math_calls[7].out_val == 5); // steps = 5
    assert(g_math_calls[8].fn == "122690" && g_math_calls[8].in_a == 5 && g_math_calls[8].out_val == 327680); // steps_fp
    // Exact LSB-checked step interpolation values
    assert(g_math_calls[9].fn == "1223C0" && g_math_calls[9].in_a == 196608 && g_math_calls[9].in_b == 327680 && g_math_calls[9].out_val == 39321); // step_x
    assert(g_math_calls[10].fn == "1223C0" && g_math_calls[10].in_a == 262144 && g_math_calls[10].in_b == 327680 && g_math_calls[10].out_val == 52428); // step_y
    assert(g_math_calls[11].fn == "122690" && g_math_calls[11].in_a == 1); // cur_x = x0
    assert(g_math_calls[12].fn == "122690" && g_math_calls[12].in_a == 1); // cur_y = y0
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
