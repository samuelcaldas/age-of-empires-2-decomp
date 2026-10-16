#include <iostream>
#include <cassert>
#include <climits>
#include <vector>

extern "C" {
void *func_00332da0(int id) { return reinterpret_cast<void *>(0x1234); }
int func_00188070(void *ctx, int id) { return id; }
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
        func_002B6220(self, 0x68, 20);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x68 * 4);
        assert(*slot == 20);
    } else if (test_case == 3) {
        func_002B6220(self, 6, 42);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 6 * 4);
        assert(*slot == 42);
    }

    std::cout << "GETTERS7 TEST " << test_case << " PASSED\n";
    return 0;
}
