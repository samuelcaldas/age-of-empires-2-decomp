#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
void func_002184D0(void *self);

static int ac470_calls = 0;
static int ab8f0_calls = 0;
static int e640_calls = 0;
static int ab9d0_calls = 0;
static int ad650_calls = 0;
static int return_ab8f0_val = 1;

int func_001AC470(void *arg0, void *arg1, void *arg2, int arg3, int arg4) {
    ac470_calls++;
    return 1;
}

int func_001AB8F0(void *arg0, int arg1) {
    ab8f0_calls++;
    return return_ab8f0_val;
}

int func_0025E640(void *arg0, void *arg1, void *arg2, void *arg3, int arg4, int arg5) {
    e640_calls++;
    return 1;
}

int func_001AB9D0(void *arg0) {
    ab9d0_calls++;
    return 1;
}

int func_001AD650(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5) {
    ad650_calls++;
    return 1;
}
}

static void reset_mocks() {
    ac470_calls = 0;
    ab8f0_calls = 0;
    e640_calls = 0;
    ab9d0_calls = 0;
    ad650_calls = 0;
    return_ab8f0_val = 1;
}

void test_case_2184D0_zero_spans() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    unsigned char arg20_buf[0x100];
    std::memset(arg20_buf, 0, sizeof(arg20_buf));

    *reinterpret_cast<void **>(obj + 0x180) = (void *)0x8888;
    *reinterpret_cast<void **>(obj + 0x20) = arg20_buf;
    *reinterpret_cast<short *>(obj + 0x184) = 0; // zero step x
    *reinterpret_cast<short *>(obj + 0x186) = 2;

    func_002184D0(obj);

    assert(e640_calls == 0); // zero step guard
}

void test_case_2184D0_zero_span_non_zero_step() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    unsigned char arg20_buf[0x100];
    std::memset(arg20_buf, 0, sizeof(arg20_buf));

    *reinterpret_cast<void **>(obj + 0x180) = (void *)0x8888;
    *reinterpret_cast<void **>(obj + 0x20) = arg20_buf;
    *reinterpret_cast<short *>(obj + 0x184) = 2; // step x = 2
    *reinterpret_cast<short *>(obj + 0x186) = 2; // step y = 2
    // spans 14/18 = 0
    *reinterpret_cast<void **>(obj + 0x14) = (void *)0;
    *reinterpret_cast<void **>(obj + 0x18) = (void *)0;

    func_002184D0(obj);

    assert(e640_calls == 1); // exactly 1 call + cleanup
    assert(ab9d0_calls == 1);
}

void test_case_2184D0_span_5_step_2() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    unsigned char arg20_buf[0x100];
    std::memset(arg20_buf, 0, sizeof(arg20_buf));

    *reinterpret_cast<void **>(obj + 0x180) = (void *)0x8888;
    *reinterpret_cast<void **>(obj + 0x20) = arg20_buf;
    *reinterpret_cast<short *>(obj + 0x184) = 2; // step x = 2
    *reinterpret_cast<short *>(obj + 0x186) = 2; // step y = 2
    *reinterpret_cast<void **>(obj + 0x14) = (void *)5; // span x = 5
    *reinterpret_cast<void **>(obj + 0x18) = (void *)2; // span y = 2

    func_002184D0(obj);

    assert(e640_calls == 3); // 3 positions
}

void test_case_2184D0_manager_restoration_on_zero() {
    reset_mocks();
    return_ab8f0_val = 0; // func_001AB8F0 returns 0
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    unsigned char arg20_buf[0x100];
    std::memset(arg20_buf, 0, sizeof(arg20_buf));

    *reinterpret_cast<void **>(obj + 0x180) = (void *)0x8888;
    *reinterpret_cast<void **>(obj + 0x20) = arg20_buf;
    *reinterpret_cast<int *>(arg20_buf + 0x28) = 123;

    func_002184D0(obj);

    assert(ab8f0_calls == 1);
    assert(e640_calls == 0);
    assert(*reinterpret_cast<int *>(arg20_buf + 0x28) == 123); // restored
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int case_num = std::stoi(argv[1]);
    if (case_num == 0) test_case_2184D0_zero_spans();
    else if (case_num == 1) test_case_2184D0_zero_span_non_zero_step();
    else if (case_num == 2) test_case_2184D0_span_5_step_2();
    else if (case_num == 3) test_case_2184D0_manager_restoration_on_zero();
    else {
        std::cerr << "Unknown case\n";
        return 1;
    }
    std::cout << "PASS\n";
    return 0;
}
