#include <iostream>
#include <cassert>
#include <climits>
#include <vector>

extern "C" {
int func_00332da0(void *ptr) { return 1; }
int func_00188070(void *ctx) { return 1; }
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
        func_002B6220(self, 0x2C, 5);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x2C * 4);
        assert(*slot == 1);
    } else if (test_case == 6) {
        char *base = storage.data();
        *reinterpret_cast<int *>(base + 0x0BEC) = 1;
        func_002B6220(self, 0x75, -10);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x75 * 4);
        assert(*slot == 0);
    }

    std::cout << "GETTERS7 TEST " << test_case << " PASSED\n";
    return 0;
}
