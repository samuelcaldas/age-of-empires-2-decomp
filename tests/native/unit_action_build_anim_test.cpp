#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_anim.h"

static int g_frame_set_called = 0;
static unsigned char g_last_frame = 255;
static int g_func_26AD30_called = 0;
static int g_func_26E750_called = 0;
static int g_e230_called = 0;

extern "C" {
    void func_0026E230(ActionRebind *self, void *zone) {
        (void)self;
        g_e230_called++;
        int *sp = (int*)zone;
        sp[0] = 1; sp[1] = 1; sp[2] = 0; sp[3] = 0;
    }
    void func_0026A680(void *action, unsigned char frame) {
        (void)action;
        g_frame_set_called++;
        g_last_frame = frame;
    }
    void func_26AD30(void *action, int flag) {
        (void)action; (void)flag;
        g_func_26AD30_called++;
    }
    void func_26E750(ActionRebind *self) {
        (void)self;
        g_func_26E750_called++;
    }
}

struct ExtendedMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    char pad_0C[0x10 - 0xC];
    void *m_field10;
};

// Case 0: Guard checks on null inputs
static void test_anim_guards() {
    func_0026E560(nullptr, 1);

    ExtendedMock mock;
    memset(&mock, 0, sizeof(mock));
    mock.m_field10 = nullptr;
    func_0026E560((ActionRebind*)&mock, 1);
    assert(g_e230_called == 0);
}

// Case 1: Frame determination and dispatch
static void test_frame_dispatch() {
    ExtendedMock mock;
    memset(&mock, 0, sizeof(mock));
    char dummy_target[16];
    mock.m_field10 = dummy_target;

    g_frame_set_called = 0;
    g_e230_called = 0;

    func_0026E560((ActionRebind*)&mock, 0);

    assert(g_e230_called == 1);
    assert(g_frame_set_called == 1);
    assert(g_last_frame == 1); // sp_vals[0]=1, sp_vals[1]=1, sp_vals[2]=0, sp_vals[3]=0 -> frame 1!
}

// Case 2: func_0026E710 sets flag 0x200 and invokes func_26E750
static void test_func_0026E710() {
    ExtendedMock mock;
    memset(&mock, 0, sizeof(mock));

    g_func_26AD30_called = 0;
    g_func_26E750_called = 0;

    func_0026E710((ActionRebind*)&mock);

    assert(g_func_26AD30_called == 1);
    assert(g_func_26E750_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_anim_guards();
        test_frame_dispatch();
        test_func_0026E710();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_anim_guards(); break;
        case 1: test_frame_dispatch(); break;
        case 2: test_func_0026E710(); break;
        default: return 1;
    }
    return 0;
}
