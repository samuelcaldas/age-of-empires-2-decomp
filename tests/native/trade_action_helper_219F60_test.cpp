#include <cassert>
#include <cstring>
#include <iostream>

void *D_00C5C2A0[2] = {nullptr, nullptr};
int D_00C5C2A8[2] = {0, 0};
int D_00C5C2B0[2] = {0, 0};
char D_00C5C2B8[2] = {0, 0};
char D_00C5C2BA[2] = {0, 0};

extern "C" {
void func_00219F60(void);
int func_00219FB0(void *buf, int capacity, char flag1, char flag2);
void func_0021A040(int index);
}

void test_case_init_table() {
    D_00C5C2A0[0] = (void *)0x1111;
    D_00C5C2A0[1] = (void *)0x2222;
    D_00C5C2A8[0] = 100;
    D_00C5C2A8[1] = 200;
    D_00C5C2B0[0] = 50;
    D_00C5C2B0[1] = 60;
    D_00C5C2B8[0] = 1;
    D_00C5C2BA[1] = 2;

    func_00219F60();

    for (int i = 0; i < 2; i++) {
        assert(D_00C5C2A0[i] == nullptr);
        assert(D_00C5C2A8[i] == 0);
        assert(D_00C5C2B0[i] == 0);
        assert(D_00C5C2B8[i] == 0);
        assert(D_00C5C2BA[i] == 0);
    }
}

void test_case_alloc_and_free_slot() {
    func_00219F60();

    // Allocate slot 0
    void *buf0 = (void *)0xAAAA;
    int slot0 = func_00219FB0(buf0, 1024, 3, 4);
    assert(slot0 == 0);
    assert(D_00C5C2A0[0] == buf0);
    assert(D_00C5C2A8[0] == 1024);
    assert(D_00C5C2B0[0] == 0);
    assert(D_00C5C2B8[0] == 3);
    assert(D_00C5C2BA[0] == 4);

    // Allocate slot 1
    void *buf1 = (void *)0xBBBB;
    int slot1 = func_00219FB0(buf1, 2048, 5, 6);
    assert(slot1 == 1);
    assert(D_00C5C2A0[1] == buf1);
    assert(D_00C5C2A8[1] == 2048);
    assert(D_00C5C2B0[1] == 0);
    assert(D_00C5C2B8[1] == 5);
    assert(D_00C5C2BA[1] == 6);

    // Table is now full (max 2 slots)
    int slot_fail = func_00219FB0((void *)0xCCCC, 512, 1, 1);
    assert(slot_fail == -1);

    // Free slot 0
    func_0021A040(0);
    assert(D_00C5C2A0[0] == nullptr);
    assert(D_00C5C2A8[0] == 0);
    assert(D_00C5C2B0[0] == 0);
    assert(D_00C5C2B8[0] == 0);
    assert(D_00C5C2BA[0] == 0);

    // Slot 0 can now be reallocated
    void *buf_new = (void *)0xDDDD;
    int slot_realloc = func_00219FB0(buf_new, 4096, 7, 8);
    assert(slot_realloc == 0);
    assert(D_00C5C2A0[0] == buf_new);
    assert(D_00C5C2A8[0] == 4096);
    assert(D_00C5C2B8[0] == 7);
    assert(D_00C5C2BA[0] == 8);

    // Free both
    func_0021A040(0);
    func_0021A040(1);
    assert(D_00C5C2A0[0] == nullptr);
    assert(D_00C5C2A0[1] == nullptr);
}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int c = std::stoi(argv[1]);
    if (c == 0) test_case_init_table();
    else if (c == 1) test_case_alloc_and_free_slot();
    else return 1;
    std::cout << "PASS\n";
    return 0;
}
