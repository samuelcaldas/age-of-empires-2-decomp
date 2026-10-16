#include <iostream>
#include <cassert>
#include <climits>
#include <vector>

extern "C" {
void *func_00332da0(int id) { return reinterpret_cast<void *>(0x1234); }
int func_00188070(void *ctx, int id) { return 1; }
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
        func_002B6220(self, 5, -2);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 5 * 4);
        assert(*slot == -2);
    } else if (test_case == 1) {
        std::vector<char> p1_obj(4096, 0);
        std::vector<char> p2_obj(4096, 0);
        std::vector<char> mgr_obj(4096, 0);

        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = mgr_obj.data();

        func_002B6220(self, 0x68, 20);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x68 * 4);
        assert(*slot == 260);
    }

    std::cout << "GETTERS7 TEST " << test_case << " PASSED\n";
    return 0;
}
