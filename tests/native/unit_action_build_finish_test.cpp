#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_finish.h"

static int g_func_26A540_called = 0;
static int g_func_205F70_called = 0;
static int g_func_1EDF20_called = 0;
static int g_func_1ECD00_called = 0;
static int g_audio_calls = 0;
static float g_last_audio_delta = 0.0f;
static unsigned short g_mock_flags = 0;

extern "C" {
    void func_0026A540(void *action, int flag) { (void)action; (void)flag; g_func_26A540_called++; }
    void func_205F70(void *world, void *action) { (void)world; (void)action; g_func_205F70_called++; }
    char func_26AD20(void *action, int flag) { (void)action; return (g_mock_flags & flag) != 0; }
    void func_26AD30(void *action, int flag) { (void)action; g_mock_flags |= (unsigned short)flag; }
    void func_26AD60(void *action, int flag) { (void)action; g_mock_flags &= (unsigned short)~flag; }
    void func_1EDF20(void *obj, void *action) { (void)obj; (void)action; g_func_1EDF20_called++; }
    void func_1ECD00(void *field98, void *action) { (void)field98; (void)action; g_func_1ECD00_called++; }
}

static void mock_audio_notify(void *world, short id, int a2, float delta) {
    (void)world; (void)id; (void)a2;
    g_audio_calls++;
    g_last_audio_delta = delta;
}

static void* dummy_vtable[200];

struct ExtendedMock {
    void *vtable;
    void *m_field4;
    void *m_world;
    char pad_0C[0x30 - 0xC];
    float m_field30;
    char pad_34[2];
    unsigned char m_field36;
    char pad_37[2];
    unsigned char m_field39;
    char pad_3A[0x170 - 0x3A];
    float m_field170;

    ExtendedMock() {
        memset(this, 0, sizeof(*this));
        vtable = dummy_vtable;
    }
};

struct DummyAudioSlot {
    short val_12c;
    short val_12e;
    unsigned char val_130;
    char pad;
};

struct DummyMaster {
    char pad[0x12C];
    DummyAudioSlot slots[3]; // 0x12C (3 * 6 = 18 bytes)
    short m_max_work;        // exactly at 0x13E!
};

// Case 0: Guard checks on null inputs
static void test_finish_guards() {
    func_0026E750(nullptr);
    func_0026E940(nullptr);
}

// Case 1: Audio notification with zero, one, and many active slots
static void test_audio_slots_zero_one_many() {
    ExtendedMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    DummyMaster master;
    memset(&master, 0, sizeof(master));
    mock.m_field4 = &master;

    char dummy_sub[0x80];
    *(void**)(dummy_sub + 0x7C) = (void*)mock_audio_notify;
    char dummy_world[0x1C00];
    *(void**)(dummy_world + 0x1B30) = dummy_sub;
    mock.m_world = (WorldExtended*)dummy_world;

    mock.m_field39 = 1;
    mock.m_field30 = 1.0f;
    master.m_max_work = 100;
    mock.m_field170 = 50.0f; // ratio = (100 - 50) / 100 = 0.5f

    // 0 active slots
    master.slots[0].val_12c = -1;
    master.slots[1].val_12c = -1;
    master.slots[2].val_12c = -1;
    g_audio_calls = 0;
    func_0026E750(act);
    assert(g_audio_calls == 0);

    // 1 active slot
    master.slots[0].val_12c = 10;
    master.slots[0].val_12e = 4;
    master.slots[0].val_130 = 1;
    g_audio_calls = 0;
    func_0026E750(act);
    assert(g_audio_calls == 1);
    assert(g_last_audio_delta == 2.0f); // 4 * 0.5f = 2.0f

    // Many (3 active slots)
    master.slots[1].val_12c = 20; master.slots[1].val_12e = 6; master.slots[1].val_130 = 1;
    master.slots[2].val_12c = 30; master.slots[2].val_12e = 8; master.slots[2].val_130 = 1;
    g_audio_calls = 0;
    func_0026E750(act);
    assert(g_audio_calls == 3);
}

// Case 2: func_0026E940 work completion and flag mutations
static void test_func_0026E940() {
    ExtendedMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_world[200];
    mock.m_world = (WorldExtended*)dummy_world;

    // work > 0 -> nothing
    mock.m_field170 = 10.0f;
    g_func_1EDF20_called = 0;
    func_0026E940(act);
    assert(g_func_1EDF20_called == 0);

    // work == 0 but flag 0x800 set -> nothing
    mock.m_field170 = 0.0f;
    g_mock_flags = 0x800;
    func_0026E940(act);
    assert(g_func_1EDF20_called == 0);

    // work == 0 and flag 0x800 clear -> triggers calls and sets 0x800
    g_mock_flags = 0x8000;
    g_func_1EDF20_called = 0;
    g_func_1ECD00_called = 0;
    func_0026E940(act);
    assert(g_func_1EDF20_called == 1);
    assert(g_func_1ECD00_called == 1);
    assert((g_mock_flags & 0x800) != 0);
    assert((g_mock_flags & 0x8000) == 0);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_finish_guards();
        test_audio_slots_zero_one_many();
        test_func_0026E940();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_finish_guards(); break;
        case 1: test_audio_slots_zero_one_many(); break;
        case 2: test_func_0026E940(); break;
        default: return 1;
    }
    return 0;
}
