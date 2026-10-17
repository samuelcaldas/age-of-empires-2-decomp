#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

union StagingWord { unsigned char bytes[4]; int word; };
union StagingPtr { unsigned char bytes[4]; unsigned char *ptr; int word; };

extern "C" {
StagingWord D_004E2DA0;
StagingPtr D_004E2DA4;
int D_004E2DA8;
unsigned char *D_004E2DB0;
int D_004E3070;
int D_004E3084;
int D_004E3088;

void func_00181e40();
void func_001820a0(int val);
void func_001820c0(int val);
}

static void test_opcode_0() {
    unsigned char stream_data[16] = { 0x20, 0xAA, 0xBB, 0xCC };
    D_004E2DB0 = stream_data;
    func_00181e40();
    assert(D_004E2DA8 == 8);
    assert(D_004E2DB0 == stream_data + 1 + 8);
}

static void test_opcode_2() {
    unsigned char stream_data[16] = { 0x02, 0x05, 0x00, 0x00 };
    D_004E2DB0 = stream_data;
    func_00181e40();
    assert(D_004E2DA8 == 0x25);
}

static void test_helper_20a0() {
    D_004E3088 = 0;
    func_001820a0(1);
    assert(D_004E3088 == 2);

    func_001820a0(2);
    assert(D_004E3088 == 4);
}

static void test_helper_20c0() {
    D_004E3084 = 0;
    func_001820c0(0x1234);
    assert(D_004E3084 == 0x1234);
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int case_num = atoi(argv[1]);
    switch (case_num) {
        case 0: test_opcode_0(); break;
        case 1: test_opcode_2(); break;
        case 2: test_helper_20a0(); break;
        case 3: test_helper_20c0(); break;
        default: return 1;
    }
    return 0;
}
