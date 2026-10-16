#include <iostream>
#include <cassert>
#include <climits>
#include <vector>

static float last_scaled_val = 0.0f;
static int helper_call_count = 0;

extern "C" {
int select_trade_increment(int mode, int flag);
float get_scaling_factor(int index, int mode, int flag);
void *p_sentinel = reinterpret_cast<void *>(0x78563412);
void *ctx_sentinel = reinterpret_cast<void *>(0x4E3180);
void *D_004E3180 = ctx_sentinel;

static int mock_mode = 2;
static int mock_flag = 1;

int func_00332da0(void *ptr) {
    assert(ptr == p_sentinel);
    return mock_mode;
}
int func_00188070(void *ctx) {
    assert(ctx == ctx_sentinel);
    return mock_flag;
}
int func_00123350(float val) {
    last_scaled_val = val;
    return static_cast<int>(val);
}
int func_002a0b30(void *mgr, int id) {
    helper_call_count++;
    return id;
}
int func_0029df60(void *mgr, int val) {
    helper_call_count++;
    return val;
}

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
        func_002B6220(self, 5, -2);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 5 * 4);
        assert(*slot == -2);

        func_002B6220(self, 5, 150);
        assert(*slot == 150);
    } else if (test_case == 3) {
        char *base = storage.data();
        *reinterpret_cast<int *>(base + 0x0BEC) = 1;
        func_002B6220(self, 0x75, -5);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x75 * 4);
        assert(*slot == 0);
    } else if (test_case == 4) {
        std::vector<char> p1_obj(4096, 0);
        std::vector<char> p2_obj(4096, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 1;
        func_002B6220(self, 0x68, 20);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x68 * 4);
        assert(*slot == 620);
    } else if (test_case == 5) {
        std::vector<char> p1_obj(4096, 0);
        std::vector<char> p2_obj(4096, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 1;
        func_002B6220(self, 0x10, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x10 * 4);
        assert(*slot == 75);
        assert(last_scaled_val == 75.0f);
    } else if (test_case == 6) {
        std::vector<char> p1_obj(4096, 0);
        std::vector<char> p2_obj(4096, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 1;
        mock_flag = 0; // mode 1, flag 0 -> factor 1.0f
        func_002B6220(self, 0x10, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x10 * 4);
        assert(*slot == 100);
        assert(last_scaled_val == 100.0f);
    } else if (test_case == 7) {
        std::vector<char> p1_obj(4096, 0);
        std::vector<char> p2_obj(4096, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 0;
        func_002B6220(self, 0x68, 20);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x68 * 4);
        assert(*slot == 260);
    }

    std::cout << "GETTERS7 TEST " << test_case << " PASSED\n";
    return 0;
}
