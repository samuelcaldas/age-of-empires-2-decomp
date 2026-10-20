#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include "tactical_ai_func_342880.h"

struct StreamCall {
    void *stream;
    void *src;
    int count;
};

static std::vector<StreamCall> g_stream_calls;

extern "C" {
int func_00226D90(void *stream, void *src, int count) {
    StreamCall call;
    call.stream = stream;
    call.src = src;
    call.count = count;
    g_stream_calls.push_back(call);
    return 0;
}
}

static void test_func_342880_serializes_five_fields_in_order() {
    TacticalItem_342820 item;
    std::memset(&item, 0, sizeof(item));
    void *mock_stream = (void*)0x55AA1234;
    g_stream_calls.clear();

    func_00342880(&item, mock_stream);

    assert(g_stream_calls.size() == 5);

    // Call 1: item.name (offset 0, 16 bytes)
    assert(g_stream_calls[0].stream == mock_stream);
    assert(g_stream_calls[0].src == (void*)item.name);
    assert(g_stream_calls[0].count == 16);

    // Call 2: item.field_10 (offset 16, 4 bytes)
    assert(g_stream_calls[1].stream == mock_stream);
    assert(g_stream_calls[1].src == (void*)&item.field_10);
    assert(g_stream_calls[1].count == 4);

    // Call 3: item.field_14 (offset 20, 4 bytes)
    assert(g_stream_calls[2].stream == mock_stream);
    assert(g_stream_calls[2].src == (void*)&item.field_14);
    assert(g_stream_calls[2].count == 4);

    // Call 4: item.field_18 (offset 24, 4 bytes)
    assert(g_stream_calls[3].stream == mock_stream);
    assert(g_stream_calls[3].src == (void*)&item.field_18);
    assert(g_stream_calls[3].count == 4);

    // Call 5: item.field_1C (offset 28, 7 bytes)
    assert(g_stream_calls[4].stream == mock_stream);
    assert(g_stream_calls[4].src == (void*)item.field_1C);
    assert(g_stream_calls[4].count == 7);

    std::printf("PASS test_func_342880_serializes_five_fields_in_order\n");
}

int main() {
    test_func_342880_serializes_five_fields_in_order();
    std::printf("ALL TACTICAL AI FUNC 342880 TESTS PASSED\n");
    return 0;
}
