#include <cassert>
#include <cstdio>
#include <cstring>
#include "unit_action_spatial.h"

void *D_004E3244 = (void*)0x4444;
void *D_004E3180 = (void*)0x8888;

static int g_1d0b40_called = 0;
static int g_1edf20_called = 0;
static int g_1ee720_called = 0;
static int g_333b30_called = 0;
static int g_1b8910_called = 0;
static int g_205f70_called = 0;
static int g_123350_called = 0;
static int g_00137a40_called = 0;

static int g_method56_called = 0;
static int g_method58_called = 0;
static int g_method62_called = 0;
static int g_method143_called = 0;
static int g_method59_called = 0;
static int g_method60_called = 0;

extern "C" {
void func_1D0B40(void *sub, int field18, void *action) { g_1d0b40_called++; }
void func_1EDF20(void *obj, void *action) { g_1edf20_called++; }
void func_1EE720(void *obj, void *action) { g_1ee720_called++; }
void* func_333B30(void *obj, int field64) { g_333b30_called++; return (void*)0x7777; }
void func_1B8910(void *obj, short field24) { g_1b8910_called++; }
void func_205F70(void *world, void *action) { g_205f70_called++; }
int func_123350(float val) { g_123350_called++; return (int)val; }
void* func_00137A40(int tile_x, int tile_y) { g_00137a40_called++; return (void*)0x9999; }
}

static void* g_vtable_self[200];
static void* g_vtable_parent[200];

static int mock_method56(void *p) { g_method56_called++; return 1; }
static void mock_method58_fn(void *s) { g_method58_called++; }
static void mock_method62_fn(void *s, void *w, int a, int b, int c) { g_method62_called++; }
static void mock_method143_fn(void *s) { g_method143_called++; }
static void mock_method59_fn(void *p, void *s) { g_method59_called++; }
static void mock_method60_fn(void *p, void *s) { g_method60_called++; }

#include "../../src/unit/unit_action_spatial.cpp"

int main() {
    // 224 / 4 = 56
    // 236 / 4 = 59
    // 240 / 4 = 60
    // 572 / 4 = 143
    g_vtable_parent[56] = (void*)mock_method56;
    g_vtable_parent[59] = (void*)mock_method59_fn;
    g_vtable_parent[60] = (void*)mock_method60_fn;

    g_vtable_self[143] = (void*)mock_method143_fn;

    char dummy_d004e3180_data[2000];
    char dummy_sub_data[200];
    *(void**)(dummy_d004e3180_data + 0x404) = dummy_sub_data;
    *(void**)(dummy_sub_data + 0x3C) = (void*)0x1111;
    D_004E3180 = dummy_d004e3180_data;

    char world_data[4000];
    memset(world_data, 0, sizeof(world_data));

    char entity_field4[100];
    *(float*)(entity_field4 + 28) = 12.5f;

    char self_buf[400];
    char parent_buf[400];
    char child_buf[400];
    memset(self_buf, 0, sizeof(self_buf));
    memset(parent_buf, 0, sizeof(parent_buf));
    memset(child_buf, 0, sizeof(child_buf));

    *(void***)self_buf = g_vtable_self;
    *(void***)parent_buf = g_vtable_parent;
    *(void***)child_buf = g_vtable_parent;

    ActionRebind *self = (ActionRebind*)self_buf;
    ActionRebind *parent = (ActionRebind*)parent_buf;
    ActionRebind *child = (ActionRebind*)child_buf;

    self->m_world = (WorldExtended*)world_data;
    self->m_field4 = entity_field4;
    self->m_field18 = 0;
    self->m_field1C = 0;
    self->m_field36 = 1;
    *(int*)((char*)self + 84) = 1; // test func_1EE720 trigger
    *(int*)((char*)self + 100) = 42; // test field64 trigger

    // 1. Test func_00268800 with force = 0
    func_00268800(self, parent, 0);
    assert(g_method56_called == 1);
    assert(g_1edf20_called == 1);
    assert(g_1ee720_called == 1);
    assert(g_333b30_called == 1);
    assert(g_1b8910_called == 1);
    assert(g_method143_called == 1);
    assert(g_method59_called == 1);
    assert(g_205f70_called == 1);

    // 2. Test func_00268940
    self->m_field1C = (int)(long)parent;
    func_00268940(self);
    assert(g_method60_called == 1);

    // 3. Test func_00268970 (insert child)
    self->m_x = 100.0f;
    self->m_y = 200.0f;
    func_00268970(self, child);
    assert(child->m_x == 100.0f);
    assert(child->m_y == 200.0f);
    assert(*(ActionRebind**)((char*)self + 32) == child);

    // 4. Test func_002689B0 (remove child)
    func_002689B0(self, child);
    assert(*(void**)((char*)self + 32) == NULL);
    assert(child->m_field1C == 0);

    // 5. Test func_00268A10
    void *sight = func_00268A10(self);
    assert(sight == (void*)0x9999);
    assert(g_123350_called == 1);
    assert(g_00137a40_called == 1);

    printf("unit_action_spatial_test passed\n");
    return 0;
}
