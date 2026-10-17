// Tests for func_00271690 — ActionBuild field-writer (160B)
// Verifies that func_001C4240 is called with self/stream, then
// func_00226F70 is called for 3 loop iterations at offsets 300+i*6,
// followed by fixed calls at offsets 318, 328, 325.
#include <cassert>
#include <cstdio>
#include "unit_action_build_690.h"

// --- Stubs ---

struct CallRecord {
    void *stream_arg;
    void *data_arg;
    int   size_arg;
};

static int          g_base_calls    = 0;
static void        *g_base_self     = nullptr;
static void        *g_base_stream   = nullptr;
static int          g_write_count   = 0;
static CallRecord   g_writes[16];

extern "C" void func_001C4240(ActionRebind *self, void *stream) {
    g_base_self   = self;
    g_base_stream = stream;
    g_base_calls++;
}

extern "C" void func_00226F70(void *stream, void *data, int size) {
    if (g_write_count < 16) {
        g_writes[g_write_count] = {stream, data, size};
    }
    g_write_count++;
}

// --- Test helpers ---

static void reset_stubs() {
    g_base_calls  = 0;
    g_base_self   = nullptr;
    g_base_stream = nullptr;
    g_write_count = 0;
    for (int i = 0; i < 16; ++i) g_writes[i] = {};
}

// --- Tests ---

static void test_base_init_called() {
    reset_stubs();
    unsigned char self_buf[512] = {};
    void *dummy_stream = (void *)0xBEEF;
    func_00271690((ActionRebind *)self_buf, dummy_stream);
    assert(g_base_calls    == 1);
    assert(g_base_self     == (void *)self_buf);
    assert(g_base_stream   == dummy_stream);
    printf("PASS test_base_init_called\n");
}

static void test_write_offsets() {
    reset_stubs();
    unsigned char self_buf[512] = {};
    void *dummy_stream = (void *)0xCAFE;
    func_00271690((ActionRebind *)self_buf, dummy_stream);
    assert(g_write_count == 6);
    for (int i = 0; i < 3; ++i) {
        assert(g_writes[i].stream_arg == dummy_stream);
        assert(g_writes[i].data_arg   == (void *)(self_buf + 300 + i * 6));
        assert(g_writes[i].size_arg   == 6);
    }
    assert(g_writes[3].data_arg == (void *)(self_buf + 318) && g_writes[3].size_arg == 2);
    assert(g_writes[4].data_arg == (void *)(self_buf + 328) && g_writes[4].size_arg == 4);
    assert(g_writes[5].data_arg == (void *)(self_buf + 325) && g_writes[5].size_arg == 1);
    printf("PASS test_write_offsets\n");
}

static void test_stream_forwarded() {
    reset_stubs();
    unsigned char self_buf[512] = {};
    void *dummy_stream = (void *)0xDEAD;
    func_00271690((ActionRebind *)self_buf, dummy_stream);
    for (int i = 0; i < g_write_count; ++i) {
        assert(g_writes[i].stream_arg == dummy_stream);
    }
    printf("PASS test_stream_forwarded\n");
}

int main() {
    test_base_init_called();
    test_write_offsets();
    test_stream_forwarded();
    printf("All unit_action_build_690 tests passed\n");
    return 0;
}
