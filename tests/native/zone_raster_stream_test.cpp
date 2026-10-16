#include "zone_raster_fixture_common.h"

StreamRecord g_stream;
size_t g_read_offset = 0;
int g_alloc_count = 0;
int g_free_count = 0;

extern "C" {
void func_001CAC90(void *self, void *stream);
void func_001CAD90(void *self, void *stream);

int D_938AC0[128];
short *D_938CC0[128];

void func_00226F70(void *stream, void *data, int size) {
    StreamRecord *rec = static_cast<StreamRecord *>(stream);
    assert(rec != nullptr);
    assert(data != nullptr);
    assert(size > 0);
    const unsigned char *p = static_cast<const unsigned char *>(data);
    rec->bytes.insert(rec->bytes.end(), p, p + size);
}

void func_00226D90(void *stream, void *data, int size) {
    StreamRecord *rec = static_cast<StreamRecord *>(stream);
    assert(rec != nullptr);
    assert(data != nullptr);
    assert(g_read_offset + size <= rec->bytes.size());
    std::memcpy(data, rec->bytes.data() + g_read_offset, size);
    g_read_offset += size;
}

void *func_00100730(unsigned int size) {
    g_alloc_count++;
    return std::malloc(size);
}

void func_00100630(void *ptr) {
    if (ptr != nullptr) {
        g_free_count++;
        std::free(ptr);
    }
}
}

void test_raster_serialize_zero_extents() {
    TestZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.f_8ED0 = 0;
    zm.f_8ED4 = 123;

    g_stream.bytes.clear();
    func_001CAC90(&zm, &g_stream);

    assert(g_stream.bytes.size() == 8);
    int count = 0, limit = 0;
    std::memcpy(&count, g_stream.bytes.data(), 4);
    std::memcpy(&limit, g_stream.bytes.data() + 4, 4);
    assert(count == 0 && limit == 123);
}

void test_raster_serialize_multiple_extents() {
    TestZoneLayout zm;
    std::memset(&zm, 0, sizeof(zm));
    zm.f_8ED0 = 2;
    zm.f_8ED4 = 50;
    int extents[2] = {0x01020304, 0x05060708};
    zm.f_8ED8 = extents;

    short buf0[8] = {1, 4, 10, 20, 0, 0, 0, 0};
    short buf1[8] = {2, 4, 30, 40, 50, 60, 0, 0};
    short *buffers[2] = {buf0, buf1};
    zm.f_8EDC = buffers;

    g_stream.bytes.clear();
    func_001CAC90(&zm, &g_stream);
    assert(g_stream.bytes.size() == 36);

    const unsigned char *d = g_stream.bytes.data();
    int read_count, read_limit;
    std::memcpy(&read_count, d, 4);
    std::memcpy(&read_limit, d + 4, 4);
    assert(read_count == 2 && read_limit == 50);

    int read_ext[2];
    std::memcpy(read_ext, d + 8, 8);
    assert(read_ext[0] == 0x01020304 && read_ext[1] == 0x05060708);
}

void test_raster_deserialize_round_trip() {
    TestZoneLayout zm_write;
    std::memset(&zm_write, 0, sizeof(zm_write));
    zm_write.f_8ED0 = 2;
    zm_write.f_8ED4 = 150;
    int extents[2] = {0x11223344, 0x55667788};
    zm_write.f_8ED8 = extents;
    short buf0[8] = {1, 4, 10, 20, 0, 0, 0, 0};
    short buf1[8] = {2, 4, 30, 40, 50, 60, 0, 0};
    short *buffers[2] = {buf0, buf1};
    zm_write.f_8EDC = buffers;

    g_stream.bytes.clear();
    func_001CAC90(&zm_write, &g_stream);

    g_read_offset = 0;
    TestZoneLayout zm_read;
    std::memset(&zm_read, 0, sizeof(zm_read));
    func_001CAD90(&zm_read, &g_stream);

    assert(zm_read.f_8ED0 == 2 && zm_read.f_8ED4 == 150);
    assert(zm_read.f_8ED8[0] == 0x11223344);
    assert(zm_read.f_8ED8[1] == 0x55667788);
    assert(zm_read.f_8EDC[0][0] == 1 && zm_read.f_8EDC[0][2] == 10);
    assert(zm_read.f_8EDC[1][0] == 2 && zm_read.f_8EDC[1][4] == 50);

    // Teardown and clamp test on empty stream
    StreamRecord empty_stream;
    int zero_hdr[2] = {0, 50};
    const unsigned char *p = reinterpret_cast<const unsigned char *>(zero_hdr);
    empty_stream.bytes.assign(p, p + 8);
    g_read_offset = 0;
    int frees_before = g_free_count;
    func_001CAD90(&zm_read, &empty_stream);
    assert(g_free_count == frees_before + 2);
    assert(zm_read.f_8ED4 == 128); // clamped
    assert(zm_read.f_8ED0 == 0);
}
