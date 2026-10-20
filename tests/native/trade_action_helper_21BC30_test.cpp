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
        for (int i = 0; i < num_sectors * 2048; ++i) {
            buf[i] = (char)((i + 1) & 0xFF);
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

    // Verify copied content starts from offset 100 of staging buffer
    for (int i = 0; i < 500; ++i) {
        assert(dest[i] == (char)((100 + i + 1) & 0xFF));
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

int main(int argc, char **argv) {
    if (argc < 2) {
        test_helpers();
        test_func_0021BC30_direct();
        test_func_0021BC30_staging();
        test_func_0021BC30_skip_when_debug_flag();
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
    }
    return 0;
}
