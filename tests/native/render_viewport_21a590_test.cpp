#include <cassert>
#include <cstring>
#include <iostream>

extern "C" {
int func_0021A590(void *self, const int *in_rect, void *out_view);
}

void test_case_null_rect_and_offset() {
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));

    *(int *)(obj + 0x3C) = 100; // rect[2] = 99
    *(int *)(obj + 0x38) = 50;  // rect[3] = 49
    *(int *)(obj + 0x40) = 640; // pitch = 640
    *(int *)(obj + 0x84) = 8;   // f84 = 8
    *(int *)(obj + 0x98) = 0;   // flags: no 0x4000

    // Fill 27 words at self + 0x30
    for (int i = 0; i < 27; i++) {
        *(int *)(obj + 0x30 + i * 4) = i + 1;
    }

    int out_view[27] = {0};
    int res = func_0021A590(obj, nullptr, out_view);
    assert(res == 0);

    // Verify 27 words copied
    for (int i = 0; i < 27; i++) {
        if (i != 9) { // 0x24 / 4 = 9
            assert(out_view[i] == i + 1);
        }
    }

    // local_rect[0] = 0, local_rect[1] = 0 -> offset = 0
    // initial out_view[9] was 10, offset 0 -> 10
    assert(out_view[9] == 10);
}

void test_case_custom_rect_and_offset() {
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));

    *(int *)(obj + 0x40) = 100; // pitch = 100
    *(int *)(obj + 0x84) = 16;  // f84 = 16 (>> 3 is * 2)
    *(int *)(obj + 0x98) = 0;   // flags: no 0x4000

    int out_view[27] = {0};
    out_view[9] = 1000; // offset 0x24 initial value
    *(int *)(obj + 0x30 + 0x24) = 1000;

    int in_rect[4] = {10, 5, 20, 15}; // x=10, y=5
    // offset = 100 * 5 + ((10 * 16) >> 3) = 500 + 20 = 520
    func_0021A590(obj, in_rect, out_view);
    assert(out_view[9] == 1000 + 520);
}

void test_case_flag_4000_sets_minus_one() {
    unsigned char obj[0x100];
    std::memset(obj, 0, sizeof(obj));

    *(int *)(obj + 0x98) = 0x4000; // flag 0x4000 active

    int out_view[27] = {0};
    func_0021A590(obj, nullptr, out_view);
    assert(out_view[9] == -1);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_null_rect_and_offset();
    else if (c == 1) test_case_custom_rect_and_offset();
    else if (c == 2) test_case_flag_4000_sets_minus_one();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
