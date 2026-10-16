#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "unit_action_coords.h"

static int g_func_263020_called = 0;
static int g_func_2621E0_called = 0;
static int g_func_268410_called = 0;

extern "C" {
    int func_00263020(int target, int frame, int dir, int *out_x, int *out_y) {
        (void)target; (void)frame; (void)dir;
        *out_x = 7;
        *out_y = 11;
        g_func_263020_called++;
        return 1;
    }
    int func_002621E0(int target, int frame, int dir) {
        (void)target; (void)frame; (void)dir;
        g_func_2621E0_called++;
        return 1;
    }
    int func_00268410(ActionRebind *self) {
        (void)self;
        g_func_268410_called++;
        return 1;
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

// Case 0: SetPosition (func_002697B0) 100% exact match verification
static void test_set_position() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    func_002697B0(act, 12.5f, -34.75f, 100.0f);
    assert(mock.m_x == 12.5f);
    assert(mock.m_y == -34.75f);
    assert(mock.m_z == 100.0f);
}

// Case 1: CalculateOffset (func_00269290)
static void test_calculate_offset() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    int dir, frame, ox, oy, extra;
    // Guard on m_field10 == 0
    mock.m_field10 = 0;
    assert(func_00269290(act, &dir, &frame, &ox, &oy, &extra) == 0);

    mock.m_field10 = 999;
    mock.m_field28 = 10;
    mock.m_field2A = 20;
    mock.m_field35 = 3;
    g_func_263020_called = 0;

    int ok = func_00269290(act, &dir, &frame, &ox, &oy, &extra);
    assert(ok == 1);
    assert(g_func_263020_called == 1);
    assert(frame == 3);
    assert(ox == 10 + 7); // 17
    assert(oy == 20 + 11); // 31
}

// Case 2: RenderFrame (func_00269450)
static void test_render_frame() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;

    mock.m_field10 = 0;
    assert(func_00269450(act, nullptr, 0, 0, 0, 0, 0) == 0);

    mock.m_field10 = 500;
    mock.m_field35 = 4;
    g_func_2621E0_called = 0;
    g_func_268410_called = 0;

    int ok = func_00269450(act, nullptr, 0, 0, 0, 0, 0);
    assert(ok == 1);
    assert(g_func_2621E0_called == 1);
    assert(g_func_268410_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_set_position();
        test_calculate_offset();
        test_render_frame();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_set_position(); break;
        case 1: test_calculate_offset(); break;
        case 2: test_render_frame(); break;
        default: return 1;
    }
    return 0;
}
