#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "unit_action_waypoint.h"

static int g_func_186010_called = 0;
static int g_func_1378C0_called = 0;
static int g_func_26A680_called = 0;
static unsigned char g_last_frame = 0;

extern "C" {
    int func_123350(float val) { return (int)val; }
    int func_186010(void *world, int tx, int ty) {
        (void)world; (void)tx; (void)ty;
        g_func_186010_called++;
        return 1;
    }
    int func_001378C0(void *zone, int tx, int ty) {
        (void)zone; (void)tx; (void)ty;
        g_func_1378C0_called++;
        return 1;
    }
    float func_001141E8(float val) { return val; }
    float func_003151E0(float val) { return val; }
    float func_00113FB8(float y, float x) { return std::atan2(y, x); }
    void func_0026A680(void *action, unsigned char frame) {
        (void)action;
        g_func_26A680_called++;
        g_last_frame = frame;
    }
}

static void* dummy_vtable[120];

struct ActionMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    void *m_fieldC;
    int m_field10;
    int m_field14;
    int m_field18;
    int m_field1C;
    int m_field20;
    short m_field24;
    short m_field26;
    short m_field28;
    short m_field2A;
    short m_field2C;
    short m_field2E;
    float m_field30;
    char m_field34;
    char m_field35;
    unsigned char m_field36;
    unsigned char m_field37;
    unsigned char m_field38;
    unsigned char m_field39;
    char m_field3A;
    char m_field3B;
    short m_field3C;
    char pad_3E[2];
    int m_field40;
    float m_x;
    float m_y;
    float m_z;

    ActionMock() {
        memset(this, 0, sizeof(*this));
        vtable = dummy_vtable;
    }
};

struct DummyEntity {
    char pad_00[0x1C];
    float m_radius; // 0x1C
};

// Case 0: func_0026AC30 radius getter (100% exact match)
static void test_func_0026AC30() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    DummyEntity ent;
    ent.m_radius = 4.5f;
    mock.m_field4 = &ent;

    float r = func_0026AC30(act);
    assert(std::fabs(r - 4.5f) < 0.001f);
}

// Case 1: func_0026A9E0 3D coordinate vector copy
static void test_func_0026A9E0() {
    ActionMock other;
    other.m_x = 10.0f;
    other.m_y = 20.0f;
    other.m_z = 30.0f;

    float out_vec[4] = {0};
    void *res = func_0026A9E0(out_vec, (ActionRebind*)&other);
    assert(res == out_vec);
    assert(out_vec[0] == 10.0f);
    assert(out_vec[1] == 30.0f);
    assert(out_vec[2] == 20.0f);
}

// Case 2: func_0026A700 tile coords and world query
static void test_func_0026A700() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    int ox = 0, oy = 0;
    assert(func_0026A700(nullptr, &ox, &oy) == 0);

    mock.m_world = nullptr;
    assert(func_0026A700(act, &ox, &oy) == 0);

    char dummy_world[0xC00] = {0};
    mock.m_world = (WorldExtended*)dummy_world;
    mock.m_x = 14.2f;
    mock.m_y = 28.9f;

    g_func_186010_called = 0;
    g_func_1378C0_called = 0;
    int ok = func_0026A700(act, &ox, &oy);
    assert(ok == 1);
    assert(g_func_186010_called == 1);
    assert(g_func_1378C0_called == 1);
    assert(ox == 14);
    assert(oy == 28);
}

// Case 3: func_0026AA00 angle calculation and frame update
static void test_func_0026AA00() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    assert(func_0026AA00(nullptr, nullptr, 1.0f) == 0);

    mock.m_x = 0.0f;
    mock.m_y = 0.0f;
    float target[2] = {10.0f, 0.0f};

    g_func_26A680_called = 0;
    int ok = func_0026AA00(act, target, 2.0f);
    assert(ok == 1);
    assert(g_func_26A680_called == 1);
    assert(g_last_frame == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0026AC30();
        test_func_0026A9E0();
        test_func_0026A700();
        test_func_0026AA00();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_func_0026AC30(); break;
        case 1: test_func_0026A9E0(); break;
        case 2: test_func_0026A700(); break;
        case 3: test_func_0026AA00(); break;
        default: return 1;
    }
    return 0;
}
