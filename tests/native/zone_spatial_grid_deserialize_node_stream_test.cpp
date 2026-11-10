#include <cassert>
#include <cstdlib>
#include <cstring>
#include <vector>
#include "zone_spatial_grid_deserialize_node_stream.h"

struct MockStream {
    const unsigned char *data;
    size_t size;
    size_t offset;
};

struct EntityCall {
    void *self;
    unsigned char type;
    void *stream;
    void *p2;
};

static std::vector<EntityCall> g_entity_calls;

extern "C" {
int func_226D90(void *stream_ptr, void *dst, int size) {
    MockStream *s = (MockStream *)stream_ptr;
    if (s->offset + size <= s->size) {
        std::memcpy(dst, s->data + s->offset, size);
        s->offset += size;
        return size;
    }
    return 0;
}

void func_001EBCC0(void *self, unsigned char type, void *stream, void *p2) {
    EntityCall call;
    call.self = self;
    call.type = type;
    call.stream = stream;
    call.p2 = p2;
    g_entity_calls.push_back(call);
}
}

static void test_empty_node_stream() {
    g_entity_calls.clear();
    // 4 bytes header1 (100), 4 bytes header2 (200), 1 byte type (0 = terminator)
    unsigned char stream_bytes[9] = {
        0x64, 0x00, 0x00, 0x00,
        0xC8, 0x00, 0x00, 0x00,
        0x00
    };
    MockStream stream = {stream_bytes, sizeof(stream_bytes), 0};
    int dummy_self = 1;
    int dummy_p2 = 2;

    func_001EBC40(&dummy_self, &stream, &dummy_p2);

    assert(stream.offset == 9);
    assert(g_entity_calls.empty());
}

static void test_multi_node_stream() {
    g_entity_calls.clear();
    // header1, header2, type 0x14, type 0x28, type 0x50, type 0
    unsigned char stream_bytes[12] = {
        0x01, 0x02, 0x03, 0x04,
        0x05, 0x06, 0x07, 0x08,
        0x14,
        0x28,
        0x50,
        0x00
    };
    MockStream stream = {stream_bytes, sizeof(stream_bytes), 0};
    int dummy_self = 10;
    int dummy_p2 = 20;

    func_001EBC40(&dummy_self, &stream, &dummy_p2);

    assert(stream.offset == 12);
    assert(g_entity_calls.size() == 3);
    assert(g_entity_calls[0].self == &dummy_self);
    assert(g_entity_calls[0].type == 0x14);
    assert(g_entity_calls[0].stream == &stream);
    assert(g_entity_calls[0].p2 == &dummy_p2);

    assert(g_entity_calls[1].self == &dummy_self);
    assert(g_entity_calls[1].type == 0x28);

    assert(g_entity_calls[2].self == &dummy_self);
    assert(g_entity_calls[2].type == 0x50);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int case_num = std::atoi(argv[1]);
    switch (case_num) {
        case 0: test_empty_node_stream(); break;
        case 1: test_multi_node_stream(); break;
        default: return 2;
    }
    return 0;
}
