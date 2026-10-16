#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialEntityState {
    char pad[0x100];
    int field_100;
    short field_104;
    char field_106;
    char field_107;
};

struct MockOutStream {
    std::vector<char> buffer;
};

extern "C" {
void func_001D85E0(SpatialEntityState *self, void *stream);

static int g_func_195000_calls = 0;

void func_195000(void *self, void *stream) {
    g_func_195000_calls++;
}

void func_226F70(void *stream, const void *src, int size) {
    MockOutStream *s = reinterpret_cast<MockOutStream *>(stream);
    const char *p = reinterpret_cast<const char *>(src);
    s->buffer.insert(s->buffer.end(), p, p + size);
}
}

static void test_serialize_flow() {
    g_func_195000_calls = 0;

    SpatialEntityState entity;
    std::memset(&entity, 0, sizeof(entity));
    entity.field_100 = 0x12345678;
    entity.field_104 = 0x0042;
    entity.field_107 = 0x7F;

    MockOutStream stream;
    func_001D85E0(&entity, &stream);

    assert(g_func_195000_calls == 1);
    // Should have written 4 + 4 + 1 = 9 bytes
    assert(stream.buffer.size() == 9);

    int field_100_val;
    std::memcpy(&field_100_val, &stream.buffer[0], 4);
    assert(field_100_val == 0x12345678);

    int field_104_val;
    std::memcpy(&field_104_val, &stream.buffer[4], 4);
    assert(field_104_val == 0x42);

    char field_107_val = stream.buffer[8];
    assert(field_107_val == 0x7F);
}

int main(int argc, char **argv) {
    test_serialize_flow();
    return 0;
}
