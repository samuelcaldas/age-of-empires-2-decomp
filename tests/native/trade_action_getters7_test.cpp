#include <iostream>
#include <cassert>
#include <climits>
#include <vector>

extern "C" {
int select_trade_increment(int mode, int flag);
void *p_sentinel = reinterpret_cast<void *>(0x78563412);
void *ctx_sentinel = reinterpret_cast<void *>(0x4E3180);

int func_00332da0(void *ptr) {
    assert(ptr == p_sentinel);
    return 2;
}
int func_00188070(void *ctx) {
    assert(ctx == ctx_sentinel);
    return 1;
}
int func_00123350(float val) { return static_cast<int>(val); }
int func_002a0b30(void *mgr, int id) { return id; }
int func_0029df60(void *mgr, int id) { return id; }

void func_002B6220(void *self, int index, int value);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int test_case = std::stoi(argv[1]);

    assert(select_trade_increment(1, 0) == 0);
    assert(select_trade_increment(1, 1) == 0);
    assert(select_trade_increment(2, 0) == 240);
    assert(select_trade_increment(2, 1) == 600);
    assert(select_trade_increment(3, 0) == 900);
    assert(select_trade_increment(3, 1) == 1200);
    assert(select_trade_increment(4, 0) == 1260);
    assert(select_trade_increment(4, 1) == 1800);
    assert(select_trade_increment(0, 0) == 0);
    assert(select_trade_increment(5, 1) == 0);

    const size_t buf_size = 4096;
    std::vector<char> storage(buf_size, 0);
    void *self = storage.data();

    if (test_case == 0) {
        func_002B6220(self, -1, 50);
    } else if (test_case == 1) {
        func_002B6220(self, 239, 50);
    } else if (test_case == 2) {
        func_002B6220(self, 0x75, -2);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x75 * 4);
        assert(*slot == 0);

        func_002B6220(self, 0x75, 100);
        assert(*slot == 100);

        func_002B6220(self, 0x75, 101);
        assert(*slot == 100);
    } else if (test_case == 3) {
        func_002B6220(self, 0x9F, 101);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x9F * 4);
        assert(*slot == 100);
    } else if (test_case == 4) {
        func_002B6220(self, 0x14, 51);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x14 * 4);
        assert(*slot == 50);
    } else if (test_case == 5) {
        func_002B6220(self, 0xE6, 35);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0xE6 * 4);
        assert(*slot == 30);
    } else if (test_case == 6) {
        func_002B6220(self, 0xCC, 10);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0xCC * 4);
        assert(*slot == 8);
    } else if (test_case == 7) {
        func_002B6220(self, 0x2C, 3);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x2C * 4);
        assert(*slot == 1);
    } else if (test_case == 8) {
        char *base = storage.data();
        *reinterpret_cast<int *>(base + 0x0BEC) = 1;
        func_002B6220(self, 0x75, -5);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x75 * 4);
        assert(*slot == 0);
    } else if (test_case == 9) {
        std::vector<char> p1_obj(4096, 0);
        std::vector<char> p2_obj(4096, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        func_002B6220(self, 0x68, 20);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x68 * 4);
        assert(*slot == 620);
    }

    std::cout << "GETTERS7 TEST " << test_case << " PASSED\n";
    return 0;
}
