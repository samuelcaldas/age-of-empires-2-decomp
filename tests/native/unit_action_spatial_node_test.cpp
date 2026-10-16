#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_spatial_node.h"

static int g_func_3357B0_called = 0;
static int g_func_335920_called = 0;
static int g_func_334FC0_called = 0;
static int g_func_335040_called = 0;
static int g_func_3352B0_called = 0;
static int g_func_333B30_called = 0;
static short g_last_short_val = 0;
static void *g_last_ptr = nullptr;

extern "C" {
    int func_123350(float val) { return (int)val; }
    void func_003357B0(void *arg0, short val) { (void)arg0; g_func_3357B0_called++; g_last_short_val = val; }
    void func_00335920(void *arg0, short val) { (void)arg0; g_func_335920_called++; g_last_short_val = val; }
    void func_00334FC0(void *arg0, short val) { (void)arg0; g_func_334FC0_called++; g_last_short_val = val; }
    void func_00335040(void *arg0, short val) { (void)arg0; g_func_335040_called++; g_last_short_val = val; }
    void func_003352B0(void *arg0, short val) { (void)arg0; g_func_3352B0_called++; g_last_short_val = val; }
    void func_333b30(void *arg0, void *arg1) { (void)arg0; g_func_333B30_called++; g_last_ptr = arg1; }
}

struct DummyNode {
    char pad_00[4];
    void *m_field4; // 0x04
    void *m_field8; // 0x08
    char pad_0C[0x4C];
    void *m_field58; // 0x58
    short m_field5C; // 0x5C
    char pad_5E[2];
    short m_field60; // 0x60
    char pad_62[2];
    int m_field64;   // 0x64
};

// Case 0: func_0026A2A0 detach and cleanup
static void test_func_0026A2A0() {
    g_func_333B30_called = 0;
    func_0026A2A0(nullptr);
    assert(g_func_333B30_called == 0);

    DummyNode node;
    memset(&node, 0, sizeof(node));
    node.m_field64 = -1;
    func_0026A2A0(&node);
    assert(g_func_333B30_called == 0);

    node.m_field64 = 0x1234;
    func_0026A2A0(&node);
    assert(g_func_333B30_called == 1);
    assert(g_last_ptr == (void*)0x1234);
    assert(node.m_field64 == -1);
}

// Case 1: func_0026A300 and func_0026A420 buffer allocation and release
static void test_buffer_lifecycle() {
    DummyNode node;
    memset(&node, 0, sizeof(node));

    func_0026A300(&node, 4);
    assert(node.m_field5C == 4);
    assert(node.m_field58 != nullptr);

    // Reallocate
    void *first_buf = node.m_field58;
    func_0026A300(&node, 8);
    assert(node.m_field5C == 8);
    assert(node.m_field58 != nullptr);

    // Release
    func_0026A420(&node);
    assert(node.m_field5C == 0);
    assert(node.m_field58 == nullptr);

    // Idempotent release
    func_0026A420(&node);
    assert(node.m_field5C == 0);
}

// Case 2: func_00269FF0, func_0026A0C0, func_0026A1B0 coordinate rounding
static void test_coords_rounding() {
    DummyNode node;
    memset(&node, 0, sizeof(node));
    node.m_field60 = 50;

    g_func_3357B0_called = 0;
    g_func_335920_called = 0;
    g_func_334FC0_called = 0;
    func_00269FF0(&node, 10.8f, 20.2f);
    assert(g_func_3357B0_called == 1);
    assert(g_func_335920_called == 1);
    assert(g_func_334FC0_called == 1);
    assert(g_last_short_val == 10);

    g_func_3352B0_called = 0;
    func_0026A1B0(&node, 0.0f, 0.0f);
    assert(g_func_3352B0_called == 1);
    assert(g_last_short_val == 50);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_func_0026A2A0();
        test_buffer_lifecycle();
        test_coords_rounding();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_func_0026A2A0(); break;
        case 1: test_buffer_lifecycle(); break;
        case 2: test_coords_rounding(); break;
        default: return 1;
    }
    return 0;
}
