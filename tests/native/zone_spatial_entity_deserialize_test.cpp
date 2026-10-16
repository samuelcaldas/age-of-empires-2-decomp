#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialEntityState {
    char pad[0x100];
    int field_100;
    short field_104;
    char field_106;
    char field_107;
};

struct MockStream {
    const char *data;
    size_t pos;
};

extern "C" {
int func_001D8550(SpatialEntityState *self, void *stream, void *arg2);

static int g_func_194f00_calls = 0;

void func_194F00(void *self, void *arg1, void *arg2) {
    g_func_194f00_calls++;
}

void func_226D90(void *stream, void *dst, int size) {
    MockStream *s = reinterpret_cast<MockStream *>(stream);
    std::memcpy(dst, s->data + s->pos, size);
    s->pos += size;
}
}

static void test_deserialize_flow() {
    g_func_194f00_calls = 0;

    // Stream layout:
    // int field_100 = 0x12345678 (4 bytes)
    // int temp_val  = 0x00000042 (4 bytes -> short 0x0042)
    // char field_107 = 0x7F (1 byte)
    unsigned char stream_data[9] = {
        0x78, 0x56, 0x34, 0x12, // 0x12345678
        0x42, 0x00, 0x00, 0x00, // 0x42
        0x7F                    // 0x7F
    };

    MockStream stream = { reinterpret_cast<const char *>(stream_data), 0 };

    SpatialEntityState entity;
    std::memset(&entity, 0, sizeof(entity));

    int res = func_001D8550(&entity, &stream, nullptr);
    assert(res == 1);
    assert(g_func_194f00_calls == 1);
    assert(entity.field_106 == 1);
    assert(entity.field_100 == 0x12345678);
    assert(entity.field_104 == 0x0042);
    assert(entity.field_107 == 0x7F);
    assert(stream.pos == 9);
}

int main(int argc, char **argv) {
    test_deserialize_flow();
    return 0;
}
