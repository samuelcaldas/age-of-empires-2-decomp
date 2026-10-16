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

int func_002B6220(void *self, int index, int value);
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
        assert(func_002B6220(self, -1, 0) == -1);
    } else if (test_case == 1) {
        assert(func_002B6220(self, 239, 0) == -1);
    } else if (test_case == 2) {
        assert(func_002B6220(self, 5, 42) == 42);
    } else if (test_case == 3) {
        char *base = storage.data();
        *reinterpret_cast<int *>(base + 0x0BEC) = 2;
        assert(func_002B6220(self, 10, 100) == 100);
    }

    std::cout << "GETTERS7 TEST " << test_case << " PASSED\n";
    return 0;
}
