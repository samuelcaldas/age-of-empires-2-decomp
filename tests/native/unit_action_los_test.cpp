#include <cassert>
#include <cstdio>
#include <cstdlib>
#include "unit_action_los_fixture.h"

int g_func_137AA0_called = 0;
int g_func_137EA0_called = 0;
int g_func_138040_called = 0;
int g_func_138320_called = 0;

int g_last_radius = 0;
int g_last_arg4 = 0;
int g_last_diff = 0;
short g_last_field24 = 0;

static void* dummy_vtable[120];

ActionMock::ActionMock() {
    memset(this, 0, sizeof(*this));
    vtable = dummy_vtable;
}

extern "C" {
    int func_123350(float val) {
        return (int)val;
    }
    void func_00137AA0(void *zone, int x, int y, int radius, int arg4, int diff, short field24) {
        (void)zone; (void)x; (void)y;
        g_func_137AA0_called++;
        g_last_radius = radius;
        g_last_arg4 = arg4;
        g_last_diff = diff;
        g_last_field24 = field24;
    }
    void func_00137EA0(void *zone, int x, int y, int radius, int arg4, int diff, short field24) {
        (void)zone; (void)x; (void)y;
        g_func_137EA0_called++;
        g_last_radius = radius;
        g_last_arg4 = arg4;
        g_last_diff = diff;
        g_last_field24 = field24;
    }
    void func_00138040(void *zone, int min_x, int min_y, int max_x, int max_y, int diff, short field24) {
        (void)zone; (void)min_x; (void)min_y; (void)max_x; (void)max_y;
        g_func_138040_called++;
        g_last_diff = diff;
        g_last_field24 = field24;
    }
    void func_00138320(void *zone, int min_x, int min_y, int max_x, int max_y, int diff, short field24) {
        (void)zone; (void)min_x; (void)min_y; (void)max_x; (void)max_y;
        g_func_138320_called++;
        g_last_diff = diff;
        g_last_field24 = field24;
    }
}

static void test_los_guards() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    g_func_137AA0_called = 0;
    func_00268A60(act, nullptr, 0, 5, 0);
    assert(g_func_137AA0_called == 0);

    LosWorldMock world;
    memset(&world, 0, sizeof(world));
    LosEntityMock ent;
    memset(&ent, 0, sizeof(ent));
    mock.m_field4 = &ent;

    func_00268A60(act, &world, 0, 0, 0);
    assert(g_func_137AA0_called == 0);
    func_00268A60(act, &world, 0, -5, 0);
    assert(g_func_137AA0_called == 0);
}

static void test_los_circle() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    LosWorldMock world;
    memset(&world, 0, sizeof(world));
    LosMapMock map;
    memset(&map, 0, sizeof(map));
    world.m_map = &map;
    world.m_val_ba0 = 100;
    map.m_map_98 = 100;

    LosEntityMock ent;
    memset(&ent, 0, sizeof(ent));
    ent.m_field8 = 0;
    ent.m_radius = 8.0f;
    mock.m_field4 = &ent;
    mock.m_field24 = 77;
    mock.m_x = 10.0f;
    mock.m_y = 20.0f;

    g_func_137AA0_called = 0;
    func_00268A60(act, &world, 0, -1, 4);
    assert(g_func_137AA0_called == 1 && g_last_radius == 8);
    assert(g_last_arg4 == 4 && g_last_diff == 1 && g_last_field24 == 77);

    g_func_137EA0_called = 0;
    func_00268C30(act, &world, 0, 12, 9);
    assert(g_func_137EA0_called == 1 && g_last_radius == 12);
    assert(g_last_arg4 == 9 && g_last_diff == 1 && g_last_field24 == 77);
}

static void test_los_rect() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    LosWorldMock world;
    memset(&world, 0, sizeof(world));
    LosMapMock map;
    memset(&map, 0, sizeof(map));
    world.m_map = &map;
    world.m_val_ba0 = 100;
    map.m_map_98 = 200;

    LosEntityMock ent;
    memset(&ent, 0, sizeof(ent));
    ent.m_field8 = 0;
    ent.m_extent_x = 3.0f;
    ent.m_extent_y = 4.0f;
    mock.m_field4 = &ent;
    mock.m_field24 = 33;
    mock.m_x = 15.0f;
    mock.m_y = 25.0f;

    g_func_138040_called = 0;
    func_00268A60(act, &world, 1, 5, 0);
    assert(g_func_138040_called == 1 && g_last_diff == 0 && g_last_field24 == 33);

    g_func_138320_called = 0;
    func_00268C30(act, &world, 1, 5, 0);
    assert(g_func_138320_called == 1 && g_last_diff == 0 && g_last_field24 == 33);
}

static void test_los_field8_override() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    LosWorldMock world;
    memset(&world, 0, sizeof(world));
    LosMapMock map;
    memset(&map, 0, sizeof(map));
    world.m_map = &map;

    LosEntityMock ent;
    memset(&ent, 0, sizeof(ent));
    ent.m_field8 = 0x70;
    ent.m_extent_x = 3.0f;
    ent.m_extent_y = 4.0f;
    mock.m_field4 = &ent;

    g_func_137AA0_called = 0;
    g_func_138040_called = 0;
    func_00268A60(act, &world, 1, 6, 0);
    assert(g_func_137AA0_called == 1 && g_func_138040_called == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_los_guards();
        test_los_circle();
        test_los_rect();
        test_los_field8_override();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_los_guards(); break;
        case 1: test_los_circle(); break;
        case 2: test_los_rect(); break;
        case 3: test_los_field8_override(); break;
        default: return 1;
    }
    return 0;
}
