#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
void func_00218820(void *self);
}

void reset_mocks();
extern int ab8f0_calls;
extern int acdf0_calls;
extern int ad940_calls;
extern int ada70_calls;
extern int adc00_calls;
extern int ab9d0_calls;
extern void *last_manager;
extern void *cleanup_manager;
extern int return_ab8f0_val;

void test_case_218820_zero_state() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    func_00218820(obj);
    assert(ab8f0_calls == 0);
    assert(ab9d0_calls == 0);
}

void test_case_218820_case_0() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x1AC) = 1;
    *reinterpret_cast<void **>(obj + 0x20) = (void *)0x9999;
    func_00218820(obj);
    assert(ab8f0_calls == 1);
    assert(acdf0_calls == 1);
    assert(ab9d0_calls == 1);
}

void test_case_218820_case_1() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x1AC) = 2;
    *reinterpret_cast<void **>(obj + 0x20) = (void *)0x9999;
    func_00218820(obj);
    assert(ab8f0_calls == 1);
    assert(ad940_calls == 1);
    assert(ab9d0_calls == 1);
}

void test_case_218820_case_2() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x1AC) = 3;
    *reinterpret_cast<void **>(obj + 0x20) = (void *)0x9999;
    func_00218820(obj);
    assert(ab8f0_calls == 1);
    assert(ada70_calls == 1);
    assert(ab9d0_calls == 1);
}

void test_case_218820_case_3() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x1AC) = 4;
    *reinterpret_cast<void **>(obj + 0x20) = (void *)0x9999;
    func_00218820(obj);
    assert(ab8f0_calls == 1);
    assert(adc00_calls == 1);
    assert(ab9d0_calls == 1);
}

void test_case_218820_case_4() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x1AC) = 5;
    *reinterpret_cast<void **>(obj + 0x20) = (void *)0x9999;
    func_00218820(obj);
    assert(ab8f0_calls == 1);
    assert(ad940_calls == 1);
    assert(ab9d0_calls == 1);
}

void test_case_218820_case_5() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x1AC) = 6;
    *reinterpret_cast<void **>(obj + 0x20) = (void *)0x9999;
    func_00218820(obj);
    assert(ab8f0_calls == 1);
    assert(ada70_calls == 1);
    assert(ab9d0_calls == 1);
}

void test_case_218820_case_6() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x1AC) = 7;
    *reinterpret_cast<void **>(obj + 0x20) = (void *)0x9999;
    func_00218820(obj);
    assert(ab8f0_calls == 1);
    assert(adc00_calls == 1);
    assert(ab9d0_calls == 1);
}

void test_case_218820_state_8_fallback() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x1AC) = 8; // >= 8 -> cleanup only, zero handlers
    *reinterpret_cast<void **>(obj + 0x20) = (void *)0x9999;
    func_00218820(obj);
    assert(ab8f0_calls == 1);
    assert(acdf0_calls == 0);
    assert(ad940_calls == 0);
    assert(ada70_calls == 0);
    assert(adc00_calls == 0);
    assert(ab9d0_calls == 1); // cleanup only
}

void test_case_218820_out_of_range() {
    reset_mocks();
    unsigned char obj[0x300];
    std::memset(obj, 0, sizeof(obj));
    *reinterpret_cast<int *>(obj + 0x1AC) = 9; // >= 8 -> cleanup only
    *reinterpret_cast<void **>(obj + 0x20) = (void *)0x9999;
    func_00218820(obj);
    assert(ab8f0_calls == 1);
    assert(acdf0_calls == 0);
    assert(ab9d0_calls == 1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int case_num = std::stoi(argv[1]);
    if (case_num == 0) test_case_218820_zero_state();
    else if (case_num == 1) test_case_218820_case_0();
    else if (case_num == 2) test_case_218820_case_1();
    else if (case_num == 3) test_case_218820_case_2();
    else if (case_num == 4) test_case_218820_case_3();
    else if (case_num == 5) test_case_218820_case_4();
    else if (case_num == 6) test_case_218820_case_5();
    else if (case_num == 7) test_case_218820_case_6();
    else if (case_num == 8) test_case_218820_state_8_fallback();
    else if (case_num == 9) test_case_218820_out_of_range();
    else {
        std::cerr << "Unknown case\n";
        return 1;
    }
    std::cout << "PASS\n";
    return 0;
}
