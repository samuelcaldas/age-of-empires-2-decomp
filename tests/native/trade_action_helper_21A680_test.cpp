#include <cassert>
#include <cstring>
#include <iostream>

static int c21e350_calls = 0;
static unsigned short last_21e350_val = 0;
static int mock_21e350_ret = 0x7C000;

extern "C" {
void func_0021A680(void *self);

int func_0021E350(unsigned short val) {
    c21e350_calls++;
    last_21e350_val = val;
    return mock_21e350_ret;
}
}

static void reset_mocks() {
    c21e350_calls = 0;
    last_21e350_val = 0;
    mock_21e350_ret = 0x7C000;
}

void test_case_default_flags_no_ptr14() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));

    *(unsigned int *)(obj + 0x98) = 0;    // no 0x800
    *(int *)(obj + 0x3C) = 128;           // s2 = 128 (128 >> 6 = 2)
    *(int *)(obj + 0x54) = 256;           // s3 = 256 (256 >> 6 = 4)
    *(int *)(obj + 0x1C) = 7;             // f1c = 7
    *(void **)(obj + 0x14) = nullptr;     // s0 = 0

    mock_21e350_ret = 0x1000;             // 0x1000 >> 6 = 0x40 = 64

    func_0021A680(obj);

    assert(c21e350_calls == 1);
    assert(last_21e350_val == 0);

    unsigned long long val = *(unsigned long long *)(obj + 0x20);

    // bits 0..13: 4
    assert((val & 0x3FFF) == 4);
    // bits 14..19: 2
    assert(((val >> 14) & 0x3F) == 2);
    // bits 20..27: (7 | 0x80) = 0x87 (due to 0xA8000000 bit 27)
    assert(((val >> 20) & 0x7F) == 7);
    // bits 28..31: 0xA
    assert(((val >> 28) & 0xF) == 0xA);
    // bits 32..36: 6
    assert(((val >> 32) & 0x1F) == 6);
    // bit 45: 1
    assert((val & (1ULL << 45)) != 0);
    // bits 56..59: 0
    assert(((val >> 56) & 0xF) == 0);
}

void test_case_flag_800_with_ptr14() {
    reset_mocks();
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));

    *(unsigned int *)(obj + 0x98) = 0x800; // flag 0x800 active
    *(int *)(obj + 0x1C) = 3;

    unsigned char ptr14_obj[0x20];
    std::memset(ptr14_obj, 0, sizeof(ptr14_obj));
    *(unsigned short *)(ptr14_obj + 2) = 0x567B; // s0 & 0xF = 0xB

    *(void **)(obj + 0x14) = ptr14_obj;
    mock_21e350_ret = 0x2000;

    func_0021A680(obj);

    assert(c21e350_calls == 1);
    assert(last_21e350_val == 0x567B);

    unsigned long long val = *(unsigned long long *)(obj + 0x20);

    // s2 was overridden to 640 (640 >> 6 = 10)
    assert(((val >> 14) & 0x3F) == 10);
    // s3 was overridden to 0xA3000 (0xA3000 >> 6 = 0x28C0)
    assert((val & 0x3FFF) == (0xA3000 >> 6));
    // bits 56..59: s0 & 0xF = 0xB
    assert(((val >> 56) & 0xF) == 0xB);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_default_flags_no_ptr14();
    else if (c == 1) test_case_flag_800_with_ptr14();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
