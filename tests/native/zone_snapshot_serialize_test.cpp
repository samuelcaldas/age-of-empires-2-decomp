#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>
#include <vector>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CDBB0(void *self, void *stream);

static int g_alloc_calls = 0;
static int g_memcpy_calls = 0;
static int g_write_calls = 0;
static int g_sub_serialize_calls = 0;
static int g_free_calls = 0;
static void *g_last_sub_obj = nullptr;

static char g_snapshot_mem[0x9158];

void *func_1143F8(int pool, int size) {
    g_alloc_calls++;
    assert(pool == 1);
    assert(size == 0x9158);
    std::memset(g_snapshot_mem, 0, sizeof(g_snapshot_mem));
    return g_snapshot_mem;
}

void *func_117AF8(void *dst, void *src, int size) {
    g_memcpy_calls++;
    assert(size == 0x9158);
    std::memcpy(dst, src, size);
    return dst;
}

int func_226F70(void *stream, void *src, int size) {
    g_write_calls++;
    assert(src == g_snapshot_mem);
    assert(size == 0x9158);
    return size;
}

void func_229940(void *sub, void *stream) {
    g_sub_serialize_calls++;
    g_last_sub_obj = sub;
}

void func_116F68(void *ptr) {
    g_free_calls++;
    assert(ptr == g_snapshot_mem);
}
}

struct EntityRef {
    char pad_0[8];
    short id;
};

struct ZoneLayout {
    char pad_0[0x8EE4];
    void *f_8EE4;
};

static void test_snapshot_sanitization_and_write() {
    g_alloc_calls = 0; g_memcpy_calls = 0; g_write_calls = 0;
    g_sub_serialize_calls = 0; g_free_calls = 0;

    static char live_zone[0x9158 + 0x100];
    std::memset(live_zone, 0, sizeof(live_zone));

    ZoneLayout *zm = reinterpret_cast<ZoneLayout *>(live_zone);
    zm->f_8EE4 = reinterpret_cast<void *>(0x77777777);

    EntityRef ent1, ent2;
    ent1.id = 0x1234;
    ent2.id = 0x5678;

    // Table 1, entry 0 (active, entity present)
    *reinterpret_cast<unsigned char *>(live_zone + 0x8C) = 1;
    *reinterpret_cast<EntityRef **>(live_zone + 0xB0) = &ent1;

    // Table 1, entry 1 (active, null entity)
    *reinterpret_cast<unsigned char *>(live_zone + 416 + 0x8C) = 1;
    *reinterpret_cast<EntityRef **>(live_zone + 416 + 0xB0) = nullptr;

    // Table 2, entry 0 (entity present, flag set)
    *reinterpret_cast<EntityRef **>(live_zone + 0x34B0) = &ent2;
    *reinterpret_cast<unsigned char *>(live_zone + 0x348C) = 1;

    // Table 2, entry 1 (entity present, flag 0 -> -1)
    *reinterpret_cast<EntityRef **>(live_zone + 1440 + 0x34B0) = &ent2;
    *reinterpret_cast<unsigned char *>(live_zone + 1440 + 0x348C) = 0;

    int stream_dummy = 0;
    func_001CDBB0(live_zone, &stream_dummy);

    assert(g_alloc_calls == 1);
    assert(g_memcpy_calls == 1);
    assert(g_write_calls == 1);
    assert(g_sub_serialize_calls == 1);
    assert(g_last_sub_obj == reinterpret_cast<void *>(0x77777777));
    assert(g_free_calls == 1);

    // Verify sanitized snapshot fields
    assert(*reinterpret_cast<int *>(g_snapshot_mem + 0xB0) == 0x1234);
    assert(*reinterpret_cast<int *>(g_snapshot_mem + 416 + 0xB0) == -1);
    assert(*reinterpret_cast<int *>(g_snapshot_mem + 0x34B0) == 0x5678);
    assert(*reinterpret_cast<int *>(g_snapshot_mem + 1440 + 0x34B0) == -1);

    // Verify live memory was NOT mutated in-place
    assert(*reinterpret_cast<EntityRef **>(live_zone + 0xB0) == &ent1);
    assert(*reinterpret_cast<EntityRef **>(live_zone + 0x34B0) == &ent2);
}

int main(int argc, char **argv) {
    test_snapshot_sanitization_and_write();
    return 0;
}
