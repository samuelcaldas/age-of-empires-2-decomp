#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001CD3D0(void *self, int x0, int y0, int x1, int y1, int param1, int param2);
}

typedef long long int64_t;
extern "C" {
int64_t func_122690(int x) { return static_cast<int64_t>(x) << 16; }
int64_t func_122118(int64_t a, int64_t b) { return (a * b) >> 16; }
int64_t func_122058(int64_t a, int64_t b) { return a + b; }
float func_1228E8(int64_t a) {
    return static_cast<float>(static_cast<double>(a) / 65536.0);
}
int64_t func_1234E0(float f) {
    return static_cast<int64_t>(static_cast<double>(f) * 65536.0);
}
int func_122748(int64_t a) {
    return static_cast<int>((a + 32768) >> 16);
}
int64_t func_1223C0(int64_t a, int64_t b) {
    return (b == 0) ? 0 : (a << 16) / b;
}
int func_100100(int64_t a, int64_t b) {
    return (a == b) ? 0 : 1;
}
}

struct CliffRecord { int x, y, p1, p2; };
static std::vector<CliffRecord> g_history;
static int g_secondary_called = 0;

struct PaintLayout {
    void **vtable;
    char pad_4[4];
    int width, height;
    char pad_10[0x8ED8];
    void *m_world;
};

static int mock_paint_primary(void *self, int x, int y, int p1, int p2);
static int mock_paint_secondary(void *self, int x, int y, int p1, int p2);

static void *g_vtable1[10] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, (void *)&mock_paint_primary, nullptr };
static void *g_vtable2[10] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, (void *)&mock_paint_secondary, nullptr };

static int mock_paint_primary(void *self, int x, int y, int p1, int p2) {
    g_history.push_back({x, y, p1, p2});
    if (g_history.size() == 2) {
        reinterpret_cast<PaintLayout *>(self)->vtable = g_vtable2;
    }
    return 1;
}

static int mock_paint_secondary(void *self, int x, int y, int p1, int p2) {
    g_secondary_called++;
    g_history.push_back({x, y, p1, p2});
    return 1;
}

static void setup_layout(PaintLayout *zm, int width, int height) {
    std::memset(zm, 0, sizeof(PaintLayout));
    zm->vtable = g_vtable1;
    zm->width = width; zm->height = height;
    g_history.clear(); g_secondary_called = 0;
}

static void test_cliff_zero_length() {
    PaintLayout zm;
    setup_layout(&zm, 10, 10);

    int ret = func_001CD3D0(&zm, 3, 3, 3, 3, 4, 9);
    assert(ret == 1);
    assert(!g_history.empty());
    assert(g_history[0].x == 3 && g_history[0].y == 3);
    assert(g_history[0].p1 == 4);
    assert(g_history[0].p2 == 9);
}

static void test_cliff_single_step() {
    PaintLayout zm;
    setup_layout(&zm, 10, 10);

    int ret = func_001CD3D0(&zm, 2, 3, 3, 3, 6, 8);
    assert(ret == 1);
    assert(g_history.size() >= 2);
    assert(g_history.front().x == 2 && g_history.front().y == 3);
    assert(g_history.back().x == 3 && g_history.back().y == 3);
}

static void test_cliff_multiple_directions() {
    const int dirs[4][4] = {{1,1,4,4},{4,1,1,4},{1,4,4,1},{4,4,1,1}};
    for (int i = 0; i < 4; i++) {
        PaintLayout zm;
        setup_layout(&zm, 10, 10);
        int ret = func_001CD3D0(&zm, dirs[i][0], dirs[i][1], dirs[i][2], dirs[i][3], 5, 7);
        assert(ret == 1);
        assert(g_history.size() >= 4);
        assert(g_history.front().x == dirs[i][0] && g_history.front().y == dirs[i][1]);
        assert(g_history.back().x == dirs[i][2] && g_history.back().y == dirs[i][3]);
    }
}

static void test_cliff_boundary_clipping() {
    PaintLayout zm;
    setup_layout(&zm, 10, 10);

    int ret = func_001CD3D0(&zm, -5, 2, 15, 2, 3, 11);
    assert(ret == 1);
    assert(!g_history.empty());
    for (size_t i = 0; i < g_history.size(); i++) {
        assert(g_history[i].x >= 0 && g_history[i].x < 10);
        assert(g_history[i].y >= 0 && g_history[i].y < 10);
    }
}

static void test_cliff_order_and_vtable_reload() {
    PaintLayout zm;
    setup_layout(&zm, 10, 10);

    int ret = func_001CD3D0(&zm, 1, 1, 5, 1, 2, 12);
    assert(ret == 1);
    assert(g_history.size() >= 5);
    for (size_t i = 0; i < g_history.size() - 1; i++) {
        assert(g_history[i].x <= g_history[i + 1].x);
    }
    assert(g_secondary_called > 0);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "zero_length") {
        test_cliff_zero_length();
    } else if (argc > 1 && std::string(argv[1]) == "single_step") {
        test_cliff_single_step();
    } else if (argc > 1 && std::string(argv[1]) == "multiple_dirs") {
        test_cliff_multiple_directions();
    } else if (argc > 1 && std::string(argv[1]) == "clipping") {
        test_cliff_boundary_clipping();
    } else if (argc > 1 && std::string(argv[1]) == "order_vtable") {
        test_cliff_order_and_vtable_reload();
    } else {
        test_cliff_zero_length();
        test_cliff_single_step();
        test_cliff_multiple_directions();
        test_cliff_boundary_clipping();
        test_cliff_order_and_vtable_reload();
    }
    return 0;
}
