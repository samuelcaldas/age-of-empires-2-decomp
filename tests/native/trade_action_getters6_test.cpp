#include <iostream>
#include <cassert>
#include <climits>
#include <vector>

extern "C" int func_002B61F0(void *self, int index);

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <case>\n";
        return 1;
    }
    int test_case = std::stoi(argv[1]);

    const size_t buf_size = 0x858 + 240 * sizeof(int);
    std::vector<char> storage(buf_size, 0);
    void *self = storage.data();

    for (int i = 0; i < 239; ++i) {
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + i * sizeof(int));
        *slot = i * 10 + 5;
    }

    const std::vector<char> original_storage = storage;

    if (test_case == 0) {
        assert(func_002B61F0(self, INT_MIN) == -1);
    } else if (test_case == 1) {
        assert(func_002B61F0(self, -1) == -1);
    } else if (test_case == 2) {
        assert(func_002B61F0(self, 0) == 5);
    } else if (test_case == 3) {
        assert(func_002B61F0(self, 238) == 2385);
    } else if (test_case == 4) {
        assert(func_002B61F0(self, 239) == -1);
    } else if (test_case == 5) {
        assert(func_002B61F0(self, INT_MAX) == -1);
    }

    assert(storage == original_storage);
    std::cout << "TEST " << test_case << " PASSED\n";
    return 0;
}
