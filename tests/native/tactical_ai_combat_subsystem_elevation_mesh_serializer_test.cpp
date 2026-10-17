#include <cassert>
#include <cstddef>
#include <cstring>
#include "tactical_ai_combat_subsystem_elevation_mesh_serializer.h"

static_assert(sizeof(void *) == 4, "PS2 pointer width required");
static_assert(sizeof(int) == 4, "PS2 integer width required");
static_assert(offsetof(ElevationMeshDescriptor, m_table_0) == 0, "table0");
static_assert(offsetof(ElevationMeshDescriptor, m_table_4) == 4, "table4");
static_assert(offsetof(ElevationMeshDescriptor, m_table_8) == 8, "table8");
static_assert(offsetof(ElevationMeshDescriptor, m_count) == 16, "count");
static_assert(sizeof(ElevationMeshDescriptor) == 20, "descriptor size");

struct RecordedWrite {
    const void *source;
    int size;
    unsigned char bytes[32];
};

static RecordedWrite writes[16];
static int write_count;
static int stream_context;
static int *count_to_clear;

static void copy_bytes(RecordedWrite *write) {
    if (!write->source || write->size <= 0 || write->size > 32) return;
    std::memcpy(write->bytes, write->source, write->size);
}

extern "C" void func_00226F70(void *stream, const void *source, int size) {
    assert(stream == &stream_context);
    assert(write_count < 16);
    RecordedWrite *write = &writes[write_count++];
    write->source = source;
    write->size = size;
    copy_bytes(write);
    if (count_to_clear) *count_to_clear = 0;
}

static void reset_writes() {
    write_count = 0;
    count_to_clear = 0;
    std::memset(writes, 0, sizeof(writes));
}

static void expect_write(int index, const void *source, int size) {
    assert(index < write_count);
    const RecordedWrite *write = &writes[index];
    assert(write->source == source);
    assert(write->size == size);
    if (!source || size <= 0 || size > 32) return;
    assert(std::memcmp(write->bytes, source, size) == 0);
}

static void test_count_only(int count) {
    ElevationMeshDescriptor descriptor = {0, 0, 0, {0}, count};
    reset_writes();
    func_00328020(&descriptor, &stream_context);
    assert(write_count == 1);
    expect_write(0, &descriptor.m_count, 4);
}

static void verify_single(ElevationMeshDescriptor *descriptor, int payload_size) {
    expect_write(0, &descriptor->m_count, 4);
    expect_write(1, descriptor->m_table_4, 4);
    expect_write(2, descriptor->m_table_8, 4);
    if (descriptor->m_table_8[0] <= 0) {
        assert(write_count == 3);
        return;
    }
    assert(write_count == 4);
    expect_write(3, descriptor->m_table_0[0], payload_size);
}

static void test_single(int vertex_count, int payload_size, bool null_payload) {
    unsigned char payload[32] = {1, 3, 5, 7, 9, 11, 13, 15};
    void *buffers[] = {payload};
    if (null_payload) buffers[0] = 0;
    int offsets[] = {0x12345678};
    int counts[] = {vertex_count};
    ElevationMeshDescriptor descriptor = {buffers, offsets, counts, {0}, 1};
    reset_writes();
    func_00328020(&descriptor, &stream_context);
    verify_single(&descriptor, payload_size);
}

static void verify_many(ElevationMeshDescriptor *descriptor) {
    assert(write_count == 9);
    expect_write(0, &descriptor->m_count, 4);
    expect_write(1, &descriptor->m_table_4[0], 4);
    expect_write(2, &descriptor->m_table_8[0], 4);
    expect_write(3, &descriptor->m_table_4[1], 4);
    expect_write(4, &descriptor->m_table_8[1], 4);
    expect_write(5, &descriptor->m_table_4[2], 4);
    expect_write(6, &descriptor->m_table_8[2], 4);
    expect_write(7, descriptor->m_table_0[0], 16);
    expect_write(8, descriptor->m_table_0[2], 8);
}

static void test_many() {
    unsigned char first[16] = {17, 18, 19, 20};
    unsigned char last[8] = {29, 30, 31, 32};
    void *buffers[] = {first, 0, last};
    int offsets[] = {10, 20, 30};
    int counts[] = {2, 0, 1};
    ElevationMeshDescriptor descriptor = {buffers, offsets, counts, {0}, 3};
    reset_writes();
    func_00328020(&descriptor, &stream_context);
    verify_many(&descriptor);
}

static void test_count_reloaded_after_write() {
    ElevationMeshDescriptor descriptor = {0, 0, 0, {0}, 2};
    reset_writes();
    count_to_clear = &descriptor.m_count;
    func_00328020(&descriptor, &stream_context);
    assert(write_count == 1);
    assert(writes[0].source == &descriptor.m_count);
    assert(writes[0].size == 4);
    int original_count = 2;
    assert(std::memcmp(writes[0].bytes, &original_count, 4) == 0);
    assert(descriptor.m_count == 0);
}

static void test_payload_sizes() {
    test_single(1, 8, false);
    test_single(2, 16, false);
    test_single(0, 0, false);
    test_single(-1, 0, false);
    test_single(1, 8, true);
    test_single(0x20000001, 8, false);
    test_single(0x10000000, static_cast<int>(0x80000000u), false);
}

int main() {
    test_count_only(0);
    test_count_only(-1);
    test_payload_sizes();
    test_many();
    test_count_reloaded_after_write();
    return 0;
}
