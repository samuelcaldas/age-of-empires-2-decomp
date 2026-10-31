#include <cassert>
#include <cstdlib>
#include <cstring>
#include "unit_action_targets.h"

static int g_func_1827B0_called = 0;
static int g_func_1827B0_target = 0;

static int g_func_182610_called = 0;
static int g_func_182610_target = 0;
static int g_func_182610_code = 0;

static int g_func_2634A0_called = 0;
static int g_func_26A460_called = 0;
static int g_func_205F70_called = 0;
static int g_func_2643C0_called = 0;
static int g_func_264290_called = 0;
static int g_func_26AD20_called = 0;

static int g_method61_called = 0;
static int g_method62_called = 0;
static int g_method19_called = 0;
static int g_method19_target = 0;
static int g_method90_called = 0;

static int g_method110_called = 0;
static int g_method114_called = 0;

extern "C" {
    void func_1827B0(void *fieldC, int target) {
        (void)fieldC;
        g_func_1827B0_called++;
        g_func_1827B0_target = target;
    }
    void func_001827b0(void *fieldC, int target) { func_1827B0(fieldC, target); }

    void func_182610(void *fieldC, int target, int code, int zero1, int zero2, unsigned char field35) {
        (void)fieldC; (void)zero1; (void)zero2; (void)field35;
        g_func_182610_called++;
        g_func_182610_target = target;
        g_func_182610_code = code;
    }
    void func_00182610(void *fieldC, int target, int code, int zero1, int zero2, unsigned char field35) {
        func_182610(fieldC, target, code, zero1, zero2, field35);
    }

    int func_2634A0(int target) {
        (void)target;
        g_func_2634A0_called++;
        return 1;
    }
    int func_2634a0(int target) { return func_2634A0(target); }

    void func_26A460(void *action) {
        (void)action;
        g_func_26A460_called++;
    }
    void func_0026A460(void *action) { func_26A460(action); }
    void func_205F70(void *world, void *action) {
        (void)world; (void)action;
        g_func_205F70_called++;
    }
    void func_2643C0(void *action) {
        (void)action;
        g_func_2643C0_called++;
    }
    void func_264290(void *action) {
        (void)action;
        g_func_264290_called++;
    }
    char func_26AD20(void *action, int flag) {
        (void)action;
        g_func_26AD20_called++;
        return (char)flag;
    }
}

static void MockMethod61(void *self, void *world, int a2, int a3, int a4) {
    (void)self; (void)world; (void)a2; (void)a3; (void)a4;
    g_method61_called++;
}

static void MockMethod62(void *self, void *world, int a2, int a3, int a4) {
    (void)self; (void)world; (void)a2; (void)a3; (void)a4;
    g_method62_called++;
}

static void MockMethod19(void *self, int target) {
    (void)self;
    g_method19_called++;
    g_method19_target = target;
}

static void MockMethod90(void *self, short a1, short a2, int a3, void *ba0, int zero1, int zero2) {
    (void)self; (void)a1; (void)a2; (void)a3; (void)ba0; (void)zero1; (void)zero2;
    g_method90_called++;
}

static short MockMethod110(void *world, void *action, int a2, int a3) {
    (void)world; (void)action; (void)a2; (void)a3;
    g_method110_called++;
    return 77;
}

static void MockMethod114(void *world, void *action, int a2, int a3, short a4) {
    (void)world; (void)action; (void)a2; (void)a3; (void)a4;
    g_method114_called++;
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
    char m_field3A;
    char m_field3B;
    short m_field3C;
    char pad_3E[0x2];
    int m_field40;
    float m_x;
    float m_y;
    float m_z;
};

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    int case_num = std::atoi(argv[1]);

    std::memset(dummy_action_vtable, 0, sizeof(dummy_action_vtable));
    dummy_action_vtable[17] = (void*)MockMethod19;
    dummy_action_vtable[59] = (void*)MockMethod61;
    dummy_action_vtable[60] = (void*)MockMethod62;
    dummy_action_vtable[88] = (void*)MockMethod90;

    ActionMock action;
    std::memset(&action, 0, sizeof(action));
    action.vtable = dummy_action_vtable;

    char field4_buf[256];
    std::memset(field4_buf, 0, sizeof(field4_buf));
    action.m_field4 = field4_buf;

    ActionExtended *act = (ActionExtended*)&action;

    switch (case_num) {
    case 0: {
        // func_00267380
        field4_buf[2] = 0;
        act->m_z = 5.0f;
        float res = func_00267380(act, 10.0f);
        assert(res == 10.0f && act->m_z == 10.0f);

        field4_buf[2] = 1;
        res = func_00267380(act, 8.0f);
        assert(res == 10.0f && act->m_z == 10.0f); // not updated because 10 >= 8

        res = func_00267380(act, 15.0f);
        assert(res == 15.0f && act->m_z == 15.0f);
        break;
    }
    case 1: {
        // func_002673D0
        char dummy_c = 1;
        act->m_fieldC = &dummy_c;
        act->m_field10 = 100;
        act->m_field35 = 7;

        // Same target returns early
        func_002673D0(act, 100);
        assert(g_func_1827B0_called == 0);

        // Different target
        func_002673D0(act, 200);
        assert(act->m_field14 == 100);
        assert(act->m_field10 == 200);
        assert(g_func_1827B0_called == 1 && g_func_1827B0_target == 100);
        assert(g_func_182610_called == 1 && g_func_182610_target == 200 && g_func_182610_code == 60);
        assert(act->m_field35 == 0);
        break;
    }
    case 2: {
        // func_002674C0
        char dummy_c = 1;
        act->m_fieldC = &dummy_c;
        act->m_field35 = 9;
        func_002674C0(act, 12, 34);
        assert(g_func_182610_called == 1 && g_func_182610_target == 12 && g_func_182610_code == 34);
        break;
    }
    case 3: {
        // func_00267500
        char dummy_c = 1;
        act->m_fieldC = &dummy_c;
        func_00267500(act, 88);
        assert(g_func_1827B0_called == 1 && g_func_1827B0_target == 88);
        break;
    }
    case 4: {
        // func_00267530 null entity returns early
        WorldExtended world;
        std::memset(&world, 0, sizeof(world));
        void *entities[16] = {};
        world.m_entities = entities;
        *(short*)(field4_buf + 8) = 3;
        entities[3] = nullptr;

        func_00267530(act, &world);
        assert(g_func_205F70_called == 0);
        assert(g_func_2643C0_called == 0);
        break;
    }
    case 5: {
        // func_00267530 full chain
        WorldExtended world;
        std::memset(&world, 0, sizeof(world));
        WorldSub1B30 sub1b30;
        std::memset(&sub1b30, 0, sizeof(sub1b30));
        sub1b30.Method110 = MockMethod110;
        sub1b30.Method114 = MockMethod114;
        world.m_field1B30 = &sub1b30;

        char entity_buf[256];
        std::memset(entity_buf, 0, sizeof(entity_buf));
        void *entities[16] = {};
        world.m_entities = entities;
        *(short*)(field4_buf + 8) = 1;
        entities[1] = entity_buf;

        act->m_world = &world;
        act->m_field36 = 1; // triggers func_205F70
        act->m_field39 = 2; // triggers Method62 and Method61
        act->m_field30 = 10.0f;
        *(short*)(field4_buf + 62) = 5;
        *(short*)(entity_buf + 62) = 15;
        *(int*)(field4_buf + 16) = 50;
        *(int*)(entity_buf + 16) = 999;
        act->m_field10 = 50; // matches field4 + 16

        func_00267530(act, &world);

        assert(g_func_205F70_called == 1);
        assert(g_func_2643C0_called == 1);
        assert(g_method62_called == 1);
        assert(g_method114_called == 1);
        assert(g_method110_called == 1);
        assert(act->m_field26 == 77); // from MockMethod110
        assert(g_method19_called == 1 && g_method19_target == 999);
        assert(act->m_field4 == entity_buf);
        // f20 = (15 * 10) / 5 = 30.0f
        assert(act->m_field30 == 30.0f);
        assert(g_method61_called == 1);
        assert(g_func_264290_called == 1);
        assert(g_method90_called == 1);
        break;
    }
    default:
        return 1;
    }

    return 0;
}
