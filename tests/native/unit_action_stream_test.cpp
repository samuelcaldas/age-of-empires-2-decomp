#include <cassert>
#include <climits>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "unit_action_stream.h"

static int g_func_116F68_called = 0;
static int g_func_11AA78_called = 0;

extern "C" {
    void func_00116F68(void *stream, void *data, int size) {
        (void)stream; (void)data; (void)size;
        g_func_116F68_called++;
    }
    void func_00116F40(void *stream, void *data, int size) {
        (void)stream; (void)data; (void)size;
    }
    void func_0011AA78(void *stream, void *data, int size) {
        (void)stream; (void)data; (void)size;
        g_func_11AA78_called++;
    }
    void func_0011ACD0(void *stream, void *data, int size) {
        (void)stream; (void)data; (void)size;
    }
    void func_0011ABBC(void *stream, void *data, int size) {
        (void)stream; (void)data; (void)size;
    }
    void* func_00100850(void *dst, const void *src, int n) {
        return memcpy(dst, src, n);
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

// Case 0: func_0026AEC0 string length
static void test_string_length() {
    assert(func_0026AEC0(nullptr) == 0);
    assert(func_0026AEC0("") == 0);
    assert(func_0026AEC0("hello") == 5);
    assert(func_0026AEC0("Age of Empires II") == 17);
}

// Case 1: func_0026AE00 save and func_0026AF90 load stream dispatch
static void test_stream_dispatch() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_stream[100];

    func_0026AE00(nullptr, nullptr);
    func_0026AF90(nullptr, nullptr);

    g_func_116F68_called = 0;
    func_0026AE00(act, dummy_stream);
    assert(g_func_116F68_called == 3);

    g_func_11AA78_called = 0;
    func_0026AF90(act, dummy_stream);
    assert(g_func_11AA78_called == 3);
}

// Case 2: func_0026B0A0 logging dispatch
static void test_logging() {
    ActionMock mock;
    ActionRebind *act = (ActionRebind*)&mock;
    char dummy_log[100];

    g_func_11AA78_called = 0;
    func_0026B0A0(act, dummy_log);
    assert(g_func_11AA78_called == 1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_string_length();
        test_stream_dispatch();
        test_logging();
        return 0;
    }
    int test = atoi(argv[1]);
    switch (test) {
        case 0: test_string_length(); break;
        case 1: test_stream_dispatch(); break;
        case 2: test_logging(); break;
        default: return 1;
    }
    return 0;
}
