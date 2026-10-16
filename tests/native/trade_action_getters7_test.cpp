#include <iostream>
#include <cassert>
#include <climits>
#include <vector>

static float last_scaled_val = 0.0f;
static int helper_call_count = 0;
static int custom_mock_return = -1;
static int last_helper_id = -1;
static int last_helper_val = -1;
static void *last_mgr_target = nullptr;

extern "C" {
int select_trade_increment(int mode, int flag);
float get_scaling_factor(int index, int mode, int flag);
void *p_sentinel = reinterpret_cast<void *>(0x78563412);
void *ctx_sentinel = reinterpret_cast<void *>(0x4E3180);
void *D_004E3180 = ctx_sentinel;

static int mock_mode = 2;
static int mock_flag = 0;

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
    return (custom_mock_return != -1) ? custom_mock_return : static_cast<int>(val);
}
int func_002a0b30(void *mgr, int id) {
    helper_call_count++;
    last_mgr_target = mgr;
    last_helper_id = id;
    return id;
}
int func_0029df60(void *mgr, int val) {
    helper_call_count++;
    last_mgr_target = mgr;
    last_helper_val = val;
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

    const size_t buf_size = 16384;
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
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
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
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 0; // f21 mode 2 flag 0 -> 0.75 scaling factor
        custom_mock_return = 731;
        func_002B6220(self, 0x10, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x10 * 4);
        assert(*slot == 731);
        assert(last_scaled_val == 75.0f);
    } else if (test_case == 6) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 1;
        mock_flag = 0; // ID 0x10 mode 1 flag 0 -> factor 1.0f
        custom_mock_return = -1;
        func_002B6220(self, 0x10, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x10 * 4);
        assert(*slot == 100);
        assert(last_scaled_val == 100.0f);
    } else if (test_case == 7) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 0;
        func_002B6220(self, 0x68, 20);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x68 * 4);
        assert(*slot == 260);
    } else if (test_case == 8) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 1;
        mock_flag = 0; // ID 0xE3 mode 1 flag 0 -> factor 1.0f
        func_002B6220(self, 0xE3, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0xE3 * 4);
        assert(*slot == 100);
        assert(last_scaled_val == 100.0f);
    } else if (test_case == 9) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 1;
        mock_flag = 1; // mode 1, flag 1 -> factor 0.8f for 0x10
        func_002B6220(self, 0x10, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x10 * 4);
        assert(*slot == 80);
        assert(last_scaled_val == 80.0f);
    } else if (test_case == 10) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 1; // ID 0x10 mode 2 flag 1 -> 0.75 scaling factor
        custom_mock_return = -1;
        func_002B6220(self, 0x10, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x10 * 4);
        assert(*slot == 75);
        assert(last_scaled_val == 75.0f);
    } else if (test_case == 11) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 0;
        custom_mock_return = 0; // Scaler returns 0 -> forces 1
        func_002B6220(self, 0x10, 50);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x10 * 4);
        assert(*slot == 1);
    } else if (test_case == 12) {
        std::vector<char> p1_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<int *>(base + 0x0BEC) = 1;
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        func_002B6220(self, 0x14, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x14 * 4);
        assert(*slot == 50);
    } else if (test_case == 13) {
        // Test case 13: Tail ID 0x56 with p1 backing >= 0x3624 + 4
        std::vector<char> p1_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        helper_call_count = 0;
        last_helper_id = -1;
        func_002B6220(self, 0x56, 42);
        assert(helper_call_count == 1);
        assert(last_helper_id == 0x56);
        assert(last_mgr_target == (p1_obj.data() + 0x3624));
    } else if (test_case == 14) {
        // Test case 14: Tail ID 0x57 with p1 backing >= 0x3624 + 4
        std::vector<char> p1_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        helper_call_count = 0;
        last_helper_id = -1;
        func_002B6220(self, 0x57, 55);
        assert(helper_call_count == 1);
        assert(last_helper_id == 0x57);
        assert(last_mgr_target == (p1_obj.data() + 0x3624));
    } else if (test_case == 15) {
        // Test case 15: Tail ID 0x69 with p1 backing >= 0x3624 + 4
        std::vector<char> p1_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        helper_call_count = 0;
        last_helper_val = -1;
        func_002B6220(self, 0x69, 77);
        assert(helper_call_count == 1);
        assert(last_helper_val == 77);
        assert(last_mgr_target == (p1_obj.data() + 0x3624));
    }

    std::cout << "GETTERS7 TEST " << test_case << " PASSED\n";
    return 0;
}
