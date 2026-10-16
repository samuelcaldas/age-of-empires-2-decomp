#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "unit_action_distance.h"

static int g_func_26A540_called = 0;
static int g_last_flag = 0;

extern "C" {
    void func_0026A540(void *action, int flag) {
        (void)action;
        g_func_26A540_called++;
        g_last_flag = flag;
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
    char pad_00[0x20];
    float m_extent_x; // 0x20
    float m_extent_y; // 0x24
    char pad_28[0x1C];
    float m_x;        // 0x44 (when viewed as other entity)
    float m_y;        // 0x48
};

// Case 0: Hold and unhold counters and state triggers
static void test_hold_unhold() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    mock.m_field3A = 0;
    g_func_26A540_called = 0;
    func_00269030(act);
    assert(mock.m_field3A == 1);
    assert(g_func_26A540_called == 1);
    assert(g_last_flag == 0);

    // Limit clamp at 250
    mock.m_field3A = 250;
    func_00269030(act);
    assert((unsigned char)mock.m_field3A == 250);

    // Unhold down to 0
    mock.m_field3A = 1;
    mock.m_field39 = 2; // state 2 triggers resume
    mock.m_field30 = 0.5f;
    g_func_26A540_called = 0;
    func_00269060(act);
    assert(mock.m_field3A == 0);
    assert(g_func_26A540_called == 1);
    assert(g_last_flag == 1);

    // Unhold when state != 2 does not call func_26A540
    mock.m_field3A = 0;
    mock.m_field39 = 0;
    g_func_26A540_called = 0;
    func_00269060(act);
    assert(mock.m_field3A == 0);
    assert(g_func_26A540_called == 0);
}

// Case 1: Distance between two bounding boxes (func_002690D0 / func_002690E0)
static void test_entity_distance() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    assert(func_002690D0(act, nullptr) > 1.0e30f);

    DummyEntity self_ent;
    self_ent.m_extent_x = 1.0f;
    self_ent.m_extent_y = 1.0f;
    mock.m_field4 = &self_ent;
    mock.m_x = 0.0f;
    mock.m_y = 0.0f;

    struct OtherMock {
        char pad[4];
        void *m_field4;
        char pad2[0x3C];
        float m_x;
        float m_y;
    } other;
    DummyEntity other_ent;
    other_ent.m_extent_x = 1.0f;
    other_ent.m_extent_y = 1.0f;
    other.m_field4 = &other_ent;
    other.m_x = 5.0f;
    other.m_y = 0.0f;

    // Dist between (0,0) ext 1 and (5,0) ext 1:
    // dx = |5 - 0| - (1 + 1) = 3.0f, dy = 0.0f -> dist = 3.0f
    float dist = func_002690D0(act, &other);
    assert(std::fabs(dist - 3.0f) < 0.001f);

    // Overlapping boxes
    other.m_x = 1.5f;
    dist = func_002690D0(act, &other);
    assert(std::fabs(dist - 0.0f) < 0.001f);
}

// Case 2: Distance to point and distance squared (func_00269190 / func_00269220)
static void test_point_distance() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    DummyEntity ent;
    ent.m_extent_x = 2.0f;
    ent.m_extent_y = 1.0f;
    mock.m_field4 = &ent;
    mock.m_x = 10.0f;
    mock.m_y = 20.0f;

    // Point at (15, 25):
    // dx = |15 - 10| - 2 = 3.0f
    // dy = |25 - 20| - 1 = 4.0f
    // dist = sqrt(3^2 + 4^2) = 5.0f
    // dist_sq = 3^2 + 4^2 = 25.0f
    float d = func_00269190(act, 15.0f, 25.0f);
    assert(std::fabs(d - 5.0f) < 0.001f);

    float d_sq = func_00269220(act, 15.0f, 25.0f);
    assert(std::fabs(d_sq - 25.0f) < 0.001f);

    // Point inside box:
    d = func_00269190(act, 11.0f, 20.5f);
    assert(std::fabs(d - 0.0f) < 0.001f);
    d_sq = func_00269220(act, 11.0f, 20.5f);
    assert(std::fabs(d_sq - 0.0f) < 0.001f);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_hold_unhold();
        test_entity_distance();
        test_point_distance();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_hold_unhold(); break;
        case 1: test_entity_distance(); break;
        case 2: test_point_distance(); break;
        default: return 1;
    }
    return 0;
}
