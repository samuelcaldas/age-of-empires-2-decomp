#include <cassert>
#include <cstring>
#include <iostream>

void *D_00C5C2A0[2] = {nullptr, nullptr};
int D_00C5C2A8[2] = {0, 0};
int D_00C5C2B0[2] = {0, 0};

char D_01E98000 = 'S';

static int c21bc30_calls = 0;
static void *last_21bc30_arg0 = nullptr;
static void *last_21bc30_buf = nullptr;
static int last_21bc30_arg2 = -1;
static int last_21bc30_cap = -1;
static int last_21bc30_arg4 = -1;

static int c219fb0_calls = 0;
static void *last_219fb0_buf = nullptr;
static int last_219fb0_cap = -1;
static char last_219fb0_f1 = -1;
static char last_219fb0_f2 = -1;
static int mock_219fb0_ret = 1;

static int c21a040_calls = 0;
static int last_21a040_index = -1;

extern "C" {
int func_0021A0A0(void *arg0, int arg1, int capacity);
void func_0021A0F0(int index);
int func_0021A100(int slot, void *user_dest, int len);

int func_0021BC30(void *arg0, void *buf, int arg2, int capacity, int arg4) {
    c21bc30_calls++;
    last_21bc30_arg0 = arg0;
    last_21bc30_buf = buf;
    last_21bc30_arg2 = arg2;
    last_21bc30_cap = capacity;
    last_21bc30_arg4 = arg4;
    return 1;
}

int func_00219FB0(void *buf, int capacity, char flag1, char flag2) {
    c219fb0_calls++;
    last_219fb0_buf = buf;
    last_219fb0_cap = capacity;
    last_219fb0_f1 = flag1;
    last_219fb0_f2 = flag2;
    return mock_219fb0_ret;
}

void func_0021A040(int index) {
    c21a040_calls++;
    last_21a040_index = index;
}

void *func_117AF8(void *dst, const void *src, int len) {
    return std::memcpy(dst, src, len);
}
}

static void reset_mocks() {
    c21bc30_calls = 0;
    last_21bc30_arg0 = nullptr;
    last_21bc30_buf = nullptr;
    last_21bc30_arg2 = -1;
    last_21bc30_cap = -1;
    last_21bc30_arg4 = -1;

    c219fb0_calls = 0;
    last_219fb0_buf = nullptr;
    last_219fb0_cap = -1;
    last_219fb0_f1 = -1;
    last_219fb0_f2 = -1;
    mock_219fb0_ret = 1;

    c21a040_calls = 0;
    last_21a040_index = -1;
}

void test_case_21A0A0_and_21A0F0() {
    reset_mocks();
    void *ctx = (void *)0x7777;
    mock_219fb0_ret = 0;

    int slot = func_0021A0A0(ctx, 42, 512);
    assert(slot == 0);
    assert(c21bc30_calls == 1);
    assert(last_21bc30_arg0 == ctx);
    assert(last_21bc30_buf == (void *)0x01E98000 || last_21bc30_buf == &D_01E98000);
    assert(last_21bc30_arg2 == 42);
    assert(last_21bc30_cap == 512);
    assert(last_21bc30_arg4 == 1);

    assert(c219fb0_calls == 1);
    assert(last_219fb0_buf == (void *)0x01E98000 || last_219fb0_buf == &D_01E98000);
    assert(last_219fb0_cap == 512);
    assert(last_219fb0_f1 == 0);
    assert(last_219fb0_f2 == 0);

    // Free slot via 21A0F0
    func_0021A0F0(0);
    assert(c21a040_calls == 1);
    assert(last_21a040_index == 0);
}

void test_case_21A100_read_buffer() {
    reset_mocks();
    char internal_buf[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    D_00C5C2A0[0] = internal_buf;
    D_00C5C2A8[0] = 64; // capacity
    D_00C5C2B0[0] = 5;  // cur_size: offset 5 ('F')

    // Read 10 bytes
    char dest[20] = {0};
    int read_bytes = func_0021A100(0, dest, 10);
    assert(read_bytes == 10);
    assert(std::memcmp(dest, "FGHIJKLMNO", 10) == 0);
    assert(D_00C5C2B0[0] == 15); // updated cur_size

    // Overflow attempt: capacity 64, cur_size 15, try reading 50 bytes (15 + 50 = 65 > 64)
    int fail_bytes = func_0021A100(0, dest, 50);
    assert(fail_bytes == -1);
    assert(D_00C5C2B0[0] == 15); // unchanged
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_21A0A0_and_21A0F0();
    else if (c == 1) test_case_21A100_read_buffer();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
