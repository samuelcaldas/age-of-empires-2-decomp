#include <cassert>
#include <cstring>
#include <iostream>

void *D_00C5C2A0[2] = {nullptr, nullptr};
int D_00C5C2A8[2] = {0, 0};
int D_00C5C2B0[2] = {0, 0};

int D_004E32D8 = 0;
extern "C" char D_01DC8000[0x80000] = {0};

static int c219fb0_calls = 0;
static void *last_219fb0_buf = nullptr;
static int last_219fb0_cap = -1;
static char last_219fb0_f1 = -1;
static char last_219fb0_f2 = -1;
static int mock_219fb0_ret = 1;

static int c21a040_calls = 0;
static int last_21a040_index = -1;

extern "C" {
void func_0021A190(void);
int func_0021A1C0(void);
void func_0021A1E0(void);
void *func_0021A210(void);
int func_0021A240(void);
int func_0021A260(const void *src, int len);

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
    c219fb0_calls = 0;
    last_219fb0_buf = nullptr;
    last_219fb0_cap = -1;
    last_219fb0_f1 = -1;
    last_219fb0_f2 = -1;
    mock_219fb0_ret = 1;

    c21a040_calls = 0;
    last_21a040_index = -1;

    std::memset(D_01DC8000, 0, sizeof(D_01DC8000));
}

void test_case_open_and_close_slot() {
    reset_mocks();
    mock_219fb0_ret = 1; // assigned to slot 1

    func_0021A190();
    assert(c219fb0_calls == 1);
    assert(last_219fb0_buf == &D_01DC8000);
    assert(last_219fb0_cap == 0);
    assert(last_219fb0_f1 == 0);
    assert(last_219fb0_f2 == 1);
    assert(D_004E32D8 == 1);

    int res = func_0021A1C0();
    assert(res == 0);
    assert(c21a040_calls == 1);
    assert(last_21a040_index == 1);
}

void test_case_capacity_and_buffer_access() {
    reset_mocks();
    D_004E32D8 = 0;

    unsigned char buffer_obj[0x100];
    std::memset(buffer_obj, 0, sizeof(buffer_obj));

    D_00C5C2A0[0] = buffer_obj;
    D_00C5C2A8[0] = 5000;

    func_0021A1E0();
    assert(*(int *)(buffer_obj + 0x40) == 5000);

    assert(func_0021A210() == buffer_obj);
    assert(func_0021A240() == 5000);

    // If buffer_obj is null, 21A210 returns (void *)-1
    D_00C5C2A0[0] = nullptr;
    assert(func_0021A210() == (void *)(long)-1);
}

void test_case_append_data() {
    reset_mocks();
    D_004E32D8 = 0;
    D_00C5C2A0[0] = D_01DC8000;
    D_00C5C2A8[0] = 100;
    D_00C5C2B0[0] = 10;

    // Append 5 bytes
    const char *msg = "HELLO";
    int appended = func_0021A260(msg, 5);
    assert(appended == 5);
    assert(std::memcmp(&D_01DC8000[10], "HELLO", 5) == 0);
    assert(D_00C5C2B0[0] == 15);
    assert(D_00C5C2A8[0] == 105);

    // Exceed maximum limit (0x7D001)
    D_00C5C2B0[0] = 0x7D000;
    int fail = func_0021A260("X", 1);
    assert(fail == -1);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_open_and_close_slot();
    else if (c == 1) test_case_capacity_and_buffer_access();
    else if (c == 2) test_case_append_data();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
