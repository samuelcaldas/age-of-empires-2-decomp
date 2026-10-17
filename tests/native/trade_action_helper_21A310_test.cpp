#include <cassert>
#include <cctype>
#include <cstring>
#include <iostream>

int D_004E2E50[10] = {0, 1, 2};
char D_003921D0[100 * 12];
extern "C" char D_01E98000[0x10000] = {0};
char D_00C5C2BA[2] = {0, 0};

void *D_00C5C2C0 = nullptr;
char *D_00C5C2C4 = nullptr;
int D_00C5C2C8 = 0;
int D_00C5C2CC = 0;

static int c21bc30_calls = 0;
static void *last_21bc30_arg0 = nullptr;
static void *last_21bc30_buf = nullptr;
static int last_21bc30_cap = -1;

extern "C" {
void func_0021A310(int index);
void *func_0021A3F0(const char *name);
int func_0021A4A0(int index);
char func_0021A4E0(int index);
void func_0021A500(int index, char val);

int func_0021BC30(void *arg0, void *buf, int arg2, int capacity, int arg4) {
    c21bc30_calls++;
    last_21bc30_arg0 = arg0;
    last_21bc30_buf = buf;
    last_21bc30_cap = capacity;
    return 1;
}

int func_0011C888(int c) {
    return std::tolower(c);
}
}

static void reset_mocks() {
    c21bc30_calls = 0;
    last_21bc30_arg0 = nullptr;
    last_21bc30_buf = nullptr;
    last_21bc30_cap = -1;

    std::memset(D_01E98000, 0, sizeof(D_01E98000));
    std::memset(D_003921D0, 0, sizeof(D_003921D0));
    D_00C5C2BA[0] = 0;
    D_00C5C2BA[1] = 0;

    D_00C5C2C0 = nullptr;
    D_00C5C2C4 = nullptr;
    D_00C5C2C8 = 0;
    D_00C5C2CC = 0;
}

void test_case_load_archive_table() {
    reset_mocks();
    D_004E2E50[0] = 2; // id = 2
    // Record for id 2 at 2 * 12 = 24
    *(int *)(D_003921D0 + 24) = 1024; // capacity = 1024

    // Mock header at D_01E98000: count = 2, stride = 16
    *(short *)(D_01E98000 + 0) = 2;  // count
    *(short *)(D_01E98000 + 2) = 16; // stride

    // Two items at D_01E98000 + 4, each 36 bytes (0x24)
    // Item 0: offset 0x20 relative pointer = 0x100
    *(char **)(D_01E98000 + 4 + 0x20) = (char *)0x100;
    // Item 1: offset 0x20 relative pointer = 0x200
    *(char **)(D_01E98000 + 4 + 0x24 + 0x20) = (char *)0x200;

    func_0021A310(0);

    assert(c21bc30_calls == 1);
    assert(last_21bc30_arg0 == D_003921D0 + 24);
    assert(last_21bc30_buf == D_01E98000);
    assert(last_21bc30_cap == 1024);

    assert(D_00C5C2C8 == 2);
    assert(D_00C5C2CC == 16);
    assert(D_00C5C2C4 == D_01E98000 + 4);

    // Verify pointer relocation
    char *rel0 = *(char **)(D_01E98000 + 4 + 0x20);
    assert(rel0 == D_01E98000 + 0x100);
    char *rel1 = *(char **)(D_01E98000 + 4 + 0x24 + 0x20);
    assert(rel1 == D_01E98000 + 0x200);
}

void test_case_find_item_lower() {
    reset_mocks();
    D_00C5C2C8 = 3; // total 3 items (checks count - 1 = 2 items)
    D_00C5C2C4 = D_01E98000 + 4;

    // Item 0: "archer"
    std::strcpy(D_01E98000 + 4, "archer");
    *(void **)(D_01E98000 + 4 + 0x20) = (void *)0xAAA;

    // Item 1: "knight"
    std::strcpy(D_01E98000 + 4 + 0x24, "knight");
    *(void **)(D_01E98000 + 4 + 0x24 + 0x20) = (void *)0xBBB;

    // Search with uppercase
    void *res0 = func_0021A3F0("ARCHER");
    assert(res0 == (void *)0xAAA);

    void *res1 = func_0021A3F0("KnIgHt");
    assert(res1 == (void *)0xBBB);

    void *res_none = func_0021A3F0("scout");
    assert(res_none == nullptr);
}

void test_case_offset_and_flags() {
    reset_mocks();
    D_00C5C2C8 = 2; // count = 2
    D_00C5C2CC = 16; // stride = 16
    D_00C5C2C4 = D_01E98000 + 4;

    // end_item is D_00C5C2C4 + 2 * 36 = D_00C5C2C4 + 72
    // base is at end_item - 4
    *(int *)(D_01E98000 + 4 + 72 - 4) = 500;

    int offset0 = func_0021A4A0(0);
    assert(offset0 == 500); // 500 + 0 * 16

    int offset3 = func_0021A4A0(3);
    assert(offset3 == 500 + 3 * 16); // 548

    // Flag2 getter / setter
    func_0021A500(1, 42);
    assert(func_0021A4E0(1) == 42);
    assert(func_0021A4E0(0) == 0);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_load_archive_table();
    else if (c == 1) test_case_find_item_lower();
    else if (c == 2) test_case_offset_and_flags();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
