#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include "unit_action_properties.h"

static int g_func_123350_called = 0;
static float g_last_123350_val = 0.0f;

extern "C" int func_123350(float val) {
    g_func_123350_called++;
    g_last_123350_val = val;
    return static_cast<int>(val);
}

static int g_method61_called = 0;
static int g_method61_arg3 = 0;
static int g_method62_called = 0;
static int g_method62_arg3 = 0;

static int g_method7c_called = 0;
static short g_method7c_last_arg1 = 0;
static float g_method7c_last_f0 = 0.0f;

static void MockMethod61(void *self, void *world, int a2, int a3, int a4) {
    (void)self; (void)world; (void)a2; (void)a4;
    g_method61_called++;
    g_method61_arg3 = a3;
}

static void MockMethod62(void *self, void *world, int a2, int a3, int a4) {
    (void)self; (void)world; (void)a2; (void)a4;
    g_method62_called++;
    g_method62_arg3 = a3;
}

static void MockMethod7C(void *world, short arg1, int a2, float f0) {
    (void)world; (void)a2;
    g_method7c_called++;
    g_method7c_last_arg1 = arg1;
    g_method7c_last_f0 = f0;
}

static void *dummy_action_vtable[128] = {};

struct ActionMock {
    void *vtable;
    void *m_field4;
    WorldExtended *m_world;
    void *m_fieldC;
    int m_field10;
    int m_field14;
    int m_field18;
    int m_field1C;
    char pad_20[0x4];
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
};

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    int case_num = std::atoi(argv[1]);

    std::memset(dummy_action_vtable, 0, sizeof(dummy_action_vtable));
    dummy_action_vtable[59] = (void*)MockMethod61;
    dummy_action_vtable[60] = (void*)MockMethod62;

    ActionMock action;
    std::memset(&action, 0, sizeof(action));
    action.vtable = dummy_action_vtable;

    char field4_buf[256];
    std::memset(field4_buf, 0, sizeof(field4_buf));
    action.m_field4 = field4_buf;

    WorldProps world;
    std::memset(&world, 0, sizeof(world));
    WorldSub1B30Props sub1b30;
    std::memset(&sub1b30, 0, sizeof(sub1b30));
    sub1b30.Method7C = MockMethod7C;
    world.m_field1B30 = &sub1b30;
    action.m_world = (WorldExtended*)&world;

    ActionExtended *act = (ActionExtended*)&action;

    g_func_123350_called = 0;
    g_method61_called = 0;
    g_method62_called = 0;
    g_method7c_called = 0;

    switch (case_num) {
    case 0: {
        // func_00267750 case 0: (m_field30 * val) / *(short*)(field4 + 62)
        action.m_field30 = 100.0f;
        *(short*)(field4_buf + 62) = 20;
        func_00267750(act, 0, 10.0f);
        // (100 * 10) / 20 = 50.0f
        assert(g_func_123350_called == 1);
        assert(action.m_field30 == 50.0f);
        break;
    }
    case 1: {
        // func_00267750 case 1: m_field18 != 0 && m_field39 == 2
        action.m_field18 = 1;
        action.m_field39 = 2;
        func_00267750(act, 1, 42.0f);
        assert(g_method62_called == 1);
        assert(g_method62_arg3 == -1);
        assert(g_method61_called == 1);
        assert(g_method61_arg3 == 42);
        break;
    }
    case 2: {
        // func_00267750 case 21: field4[112] == 2
        field4_buf[112] = 2;
        *(short*)(field4_buf + 90) = 5;
        *(float*)(field4_buf + 96) = 15.0f;
        func_00267750(act, 21, 25.0f);
        // Should call Method7C twice: first with -15.0f, second with 25.0f
        assert(g_method7c_called == 2);
        assert(g_method7c_last_arg1 == 5);
        assert(g_method7c_last_f0 == 25.0f);
        break;
    }
    case 3: {
        // func_002678A0 case 0:
        action.m_field30 = 100.0f;
        *(short*)(field4_buf + 62) = 20;
        // val2 = 20, (100 * (5 + 20)) / 20 = 125, + 0.5f = 125.5 -> func_123350 -> 125.0f
        func_002678A0(act, 0, 5.0f);
        assert(g_func_123350_called == 1);
        assert(action.m_field30 == 125.0f);
        break;
    }
    case 4: {
        // func_002678A0 case 1:
        action.m_field18 = 1;
        action.m_field39 = 2;
        *(float*)(field4_buf + 28) = 10.0f;
        func_002678A0(act, 1, 30.0f);
        assert(g_method62_called == 1);
        assert(g_method61_called == 1);
        assert(g_method61_arg3 == 40); // 30 + 10
        break;
    }
    case 5: {
        // func_002679A0 case 0:
        action.m_field30 = 20.0f;
        // 20 * 3.0 = 60 + 0.5 = 60.5 -> 60.0f
        func_002679A0(act, 0, 3.0f);
        assert(g_func_123350_called == 1);
        assert(action.m_field30 == 60.0f);
        break;
    }
    case 6: {
        // func_002679A0 case 1:
        action.m_field18 = 1;
        action.m_field39 = 2;
        *(float*)(field4_buf + 28) = 4.0f;
        func_002679A0(act, 1, 5.0f);
        assert(g_method62_called == 1);
        assert(g_method61_called == 1);
        assert(g_method61_arg3 == 20); // 4 * 5
        break;
    }
    default:
        return 1;
    }

    return 0;
}
