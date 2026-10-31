#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
int func_001D2C70(void *self, float min_x, float min_y, float max_x, float max_y, float *out_x, float *out_y);

static int g_func_333500_calls = 0;
static int g_func_3335c0_calls = 0;
static int g_func_1d2de0_calls = 0;
static int g_func_1fd4e0_calls = 0;

static char g_dummy_item[64];
static void *g_expected_mgr = nullptr;

void *func_333500(void *mgr) {
    g_func_333500_calls++;
    return g_dummy_item;
}

void func_3335C0(void *mgr, void *field_8) {
    g_func_3335c0_calls++;
}

int func_1D2DE0(void *self, void *item, int p2, int p3, int p4, float min_x, float min_y, float max_x, float max_y, float p9) {
    g_func_1d2de0_calls++;
    return 1; // hit
}

struct Point3D {
    float x;
    float z;
    float y;
};

void func_1FD4E0(void *out_point, void *item, int index) {
    g_func_1fd4e0_calls++;
    Point3D *pt = reinterpret_cast<Point3D *>(out_point);
    pt->x = 5.0f;
    pt->z = 0.0f;
    pt->y = 3.0f;
}

int func_00123350(float val) {
    return static_cast<int>(val);
}
}

static void test_query_bounds_hit() {
    g_func_333500_calls = 0;
    g_func_3335c0_calls = 0;
    g_func_1d2de0_calls = 0;
    g_func_1fd4e0_calls = 0;

    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    // Cell at level 0, x=5, y=3 has non-zero byte
    char cell[4] = { 0x01, 0x00, 0x00, 0x00 };
    char col[16];
    std::memset(col, 0, sizeof(col));
    // y=3 is byte offset 3 * 2 = 6
    col[6] = 0x01;

    void *level0[8];
    std::memset(level0, 0, sizeof(level0));
    level0[5] = col;

    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    // item has count = 1 at offset 0x20
    std::memset(g_dummy_item, 0, sizeof(g_dummy_item));
    *reinterpret_cast<char *>(g_dummy_item + 0x20) = 1;

    float out_x = 0.0f;
    float out_y = 0.0f;
    int res = func_001D2C70(zm, 0.0f, 0.0f, 10.0f, 10.0f, &out_x, &out_y);

    assert(res == 1);
    assert(out_x == 5.0f);
    assert(out_y == 3.0f);
    assert(g_func_333500_calls == 1);
    assert(g_func_1d2de0_calls == 1);
    assert(g_func_1fd4e0_calls == 1);
    assert(g_func_3335c0_calls == 1);
}

int main(int argc, char **argv) {
    test_query_bounds_hit();
    return 0;
}
