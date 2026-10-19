#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
int func_0021BC30(void *stream_info, void *dest, int offset, int count, int direct_flag);
int func_0021BDD0();
void func_0021BDE0(int val);

int D_004E32E0 = 0;
char D_01E98000[0x100000];

static int g_cd_reads = 0;
static int g_last_lba = 0;
static int g_last_num_sectors = 0;
static void *g_last_target_buffer = nullptr;
static int g_read_result = 1;
static int g_read_status = 1;

int func_12C388(int lba, int num_sectors, void *target_buffer, int *out_status) {
    g_cd_reads++;
    g_last_lba = lba;
    g_last_num_sectors = num_sectors;
    g_last_target_buffer = target_buffer;
    if (out_status != nullptr) {
        *out_status = g_read_status;
    }
    if (target_buffer != nullptr) {
        char *buf = (char *)target_buffer;
        for (int s = 0; s < num_sectors; ++s) {
            int sector_lba = lba + s;
            for (int b = 0; b < 2048; ++b) {
                buf[s * 2048 + b] = (char)((sector_lba * 17 + b) & 0xFF);
            }
        }
    }
    return g_read_result;
}

static int g_memcpy_calls = 0;
void *func_117AF8(void *dst, const void *src, int len) {
    g_memcpy_calls++;
    std::memcpy(dst, src, len);
    return dst;
}
}

struct StreamInfo {
    int total_size;
    int sector_base;
};

static void test_helpers() {
    assert(func_0021BDD0() == 0x175E9);

    func_0021BDE0(12345);
    assert(D_004E32E0 == 12345);
    func_0021BDE0(0);
    assert(D_004E32E0 == 0);

    std::cout << "PASS: test_helpers" << std::endl;
}

static void test_func_0021BC30_direct() {
    g_cd_reads = 0;
    g_memcpy_calls = 0;
    D_004E32E0 = 0;

    StreamInfo stream = {4096, 100};
    char dest[4096];
    std::memset(dest, 0, sizeof(dest));

    // offset = 0, count = 4096, direct_flag = 1
    int res = func_0021BC30(&stream, dest, 0, 4096, 1);
    assert(res == 1);
    assert(g_cd_reads == 1);
    assert(g_last_lba == 100 + 0xC350);
    assert(g_last_num_sectors == 2);
    assert(g_last_target_buffer == dest);
    assert(g_memcpy_calls == 0);

    // Verify all 4096 bytes in direct destination buffer
    for (int s = 0; s < 2; ++s) {
        int lba = 100 + 0xC350 + s;
        for (int b = 0; b < 2048; ++b) {
            char expected = (char)((lba * 17 + b) & 0xFF);
            assert(dest[s * 2048 + b] == expected);
        }
    }

    std::cout << "PASS: test_func_0021BC30_direct" << std::endl;
}

static void test_func_0021BC30_staging() {
    g_cd_reads = 0;
    g_memcpy_calls = 0;
    D_004E32E0 = 0;

    // stream base = 50. offset = 100 (intra_sector_offset = 100, sector_base = 50 + 0 = 50).
    // count = 500 (unaligned). direct_flag = 0.
    // Total rounded = (500 + 100) = 600 -> rounded up to 2048 (1 sector).
    StreamInfo stream = {10000, 50};
    char dest[1024];
    std::memset(dest, 0, sizeof(dest));

    int res = func_0021BC30(&stream, dest, 100, 500, 0);
    assert(res == 1);
    assert(g_cd_reads == 1);
    assert(g_last_lba == 50 + 0xC350);
    assert(g_last_num_sectors == 1);
    assert(g_last_target_buffer == D_01E98000);
    assert(g_memcpy_calls == 1);

    // Verify all 500 copied bytes starting from offset 100 of staging buffer
    int lba = 50 + 0xC350;
    for (int i = 0; i < 500; ++i) {
        char expected = (char)((lba * 17 + 100 + i) & 0xFF);
        assert(dest[i] == expected);
    }

    std::cout << "PASS: test_func_0021BC30_staging" << std::endl;
}

static void test_func_0021BC30_skip_when_debug_flag() {
    g_cd_reads = 0;
    g_memcpy_calls = 0;
    D_004E32E0 = 1;

    StreamInfo stream = {2048, 200};
    char dest[2048];
    std::memset(dest, 0, sizeof(dest));

    int res = func_0021BC30(&stream, dest, 0, 2048, 1);
    assert(res == 1);
    assert(g_cd_reads == 0);

    D_004E32E0 = 0;
    std::cout << "PASS: test_func_0021BC30_skip_when_debug_flag" << std::endl;
}

static void test_func_0021BC30_count_zero_and_offset() {
    g_cd_reads = 0;
    g_memcpy_calls = 0;
    D_004E32E0 = 0;

    // stream base = 50. offset = 4500 (offset >> 11 = 2 sectors, intra = 4500 & 0x7FF = 404).
    // count = 0 (defaults to stream.total_size = 8192).
    // Total rounded = (8192 + 404) = 8596 -> rounded up to 10240 (5 sectors).
    StreamInfo stream = {8192, 50};
    char dest[8192];
    std::memset(dest, 0, sizeof(dest));

    int res = func_0021BC30(&stream, dest, 4500, 0, 0);
    assert(res == 1);
    assert(g_cd_reads == 1);
    assert(g_last_lba == (50 + 2) + 0xC350);
    assert(g_last_num_sectors == 5);
    assert(g_last_target_buffer == D_01E98000);
    assert(g_memcpy_calls == 1);

    // Verify all 8192 payload bytes starting from offset 404 in staging buffer across 5 sectors
    for (int i = 0; i < 8192; ++i) {
        int byte_pos = 404 + i;
        int s = byte_pos / 2048;
        int b = byte_pos % 2048;
        int lba = (50 + 2) + 0xC350 + s;
        char expected = (char)((lba * 17 + b) & 0xFF);
        assert(dest[i] == expected);
    }

    std::cout << "PASS: test_func_0021BC30_count_zero_and_offset" << std::endl;
}

static void test_func_0021BC30_just_over_sector() {
    g_cd_reads = 0;
    g_memcpy_calls = 0;
    D_004E32E0 = 0;

    // count = 2049 (1 sector + 1 byte), offset = 0, direct_flag = 0.
    // Unaligned count forces staging: use_staging = 1.
    // Total rounded = (2049 & ~0x7FF) + 0x800 = 4096 (2 sectors).
    StreamInfo stream = {2049, 10};
    char dest[2049];
    std::memset(dest, 0, sizeof(dest));

    int res = func_0021BC30(&stream, dest, 0, 2049, 0);
    assert(res == 1);
    assert(g_cd_reads == 1);
    assert(g_last_lba == 10 + 0xC350);
    assert(g_last_num_sectors == 2);
    assert(g_memcpy_calls == 1);

    // Verify all 2049 payload bytes across both sectors
    for (int i = 0; i < 2049; ++i) {
        int s = i / 2048;
        int b = i % 2048;
        int lba = 10 + 0xC350 + s;
        char expected = (char)((lba * 17 + b) & 0xFF);
        assert(dest[i] == expected);
    }

    std::cout << "PASS: test_func_0021BC30_just_over_sector" << std::endl;
}

static void test_func_0021BC30_exact_sector_with_offset() {
    g_cd_reads = 0;
    g_memcpy_calls = 0;
    D_004E32E0 = 0;

    // count = 2048 (exact 1 sector), offset = 512, direct_flag = 0.
    // Unaligned offset forces staging: use_staging = 1.
    // Total rounded = (2048 + 512) = 2560 -> 4096 (2 sectors).
    StreamInfo stream = {2048, 30};
    char dest[2048];
    std::memset(dest, 0, sizeof(dest));

    int res = func_0021BC30(&stream, dest, 512, 2048, 0);
    assert(res == 1);
    assert(g_cd_reads == 1);
    assert(g_last_lba == 30 + 0xC350);
    assert(g_last_num_sectors == 2);
    assert(g_memcpy_calls == 1);

    // Verify all 2048 payload bytes starting from offset 512 of first sector
    for (int i = 0; i < 2048; ++i) {
        int byte_pos = 512 + i;
        int s = byte_pos / 2048;
        int b = byte_pos % 2048;
        int lba = 30 + 0xC350 + s;
        char expected = (char)((lba * 17 + b) & 0xFF);
        assert(dest[i] == expected);
    }

    std::cout << "PASS: test_func_0021BC30_exact_sector_with_offset" << std::endl;
}

static void test_func_0021BC30_multi_chunk_1mb() {
    g_cd_reads = 0;
    g_memcpy_calls = 0;
    D_004E32E0 = 0;

    // Stream with 1.25 MiB: 0x140000 = 1,310,720 bytes. Offset = 100 forces staging.
    // base sector = 20. direct_flag = 0.
    // Total rounded = (1,310,720 + 100) = 1,310,820 -> rounded up to 1,312,768 (641 sectors).
    // Chunk 1: size 0x100000 (512 sectors), reads LBA 20 + 0xC350, copies 1,048,476 bytes from offset 100.
    // Chunk 2: size 264,192 (129 sectors), reads LBA 20 + 512 + 0xC350, copies remaining 262,244 bytes.
    static char dest[0x140000];
    std::memset(dest, 0, sizeof(dest));

    StreamInfo stream = {0x140000, 20};
    int res = func_0021BC30(&stream, dest, 100, 0x140000, 0);
    assert(res == 1);
    assert(g_cd_reads == 2);
    assert(g_memcpy_calls == 2);
    assert(g_last_lba == 20 + 512 + 0xC350);
    assert(g_last_num_sectors == 129);

    // Verify all 1,310,720 bytes copied across both chunks
    int base_lba = 20 + 0xC350;
    for (int i = 0; i < 0x140000; ++i) {
        int byte_pos = 100 + i;
        int s = byte_pos / 2048;
        int b = byte_pos % 2048;
        int lba = base_lba + s;
        char expected = (char)((lba * 17 + b) & 0xFF);
        assert(dest[i] == expected);
    }

    std::cout << "PASS: test_func_0021BC30_multi_chunk_1mb" << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_helpers();
        test_func_0021BC30_direct();
        test_func_0021BC30_staging();
        test_func_0021BC30_skip_when_debug_flag();
        test_func_0021BC30_count_zero_and_offset();
        test_func_0021BC30_just_over_sector();
        test_func_0021BC30_exact_sector_with_offset();
        test_func_0021BC30_multi_chunk_1mb();
        return 0;
    }
    if (argv[1][0] == '0') {
        test_helpers();
    } else if (argv[1][0] == '1') {
        test_func_0021BC30_direct();
    } else if (argv[1][0] == '2') {
        test_func_0021BC30_staging();
    } else if (argv[1][0] == '3') {
        test_func_0021BC30_skip_when_debug_flag();
    } else if (argv[1][0] == '4') {
        test_func_0021BC30_count_zero_and_offset();
    } else if (argv[1][0] == '5') {
        test_func_0021BC30_just_over_sector();
    } else if (argv[1][0] == '6') {
        test_func_0021BC30_exact_sector_with_offset();
    } else if (argv[1][0] == '7') {
        test_func_0021BC30_multi_chunk_1mb();
    }
    return 0;
}
