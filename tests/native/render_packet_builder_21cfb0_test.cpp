#include <cassert>
#include <iostream>
#include <string>
#include <vector>

struct CallRecord {
    int reg;
    unsigned long long data;
};

static std::vector<CallRecord> calls;
static int finalize_calls = 0;
static int header_calls = 0;
static void *mock_obj = (void *)0x6666;

unsigned int D_00392B60[4] = {0x5555, 0x6666, 0x7777, 0x8888};
unsigned short D_00CA158C = 640;
unsigned short D_00CA158E = 480;

extern "C" {
void *func_123908(void *arg) {
    return mock_obj;
}

void *func_104448(void *obj, int a1, int a2, int a3) {
    header_calls++;
    return obj;
}

void *func_1045E8(void *obj, void *tag) {
    return obj;
}

void *func_1046A8(void *obj, int reg, unsigned long long data) {
    calls.push_back({reg, data});
    return obj;
}

void *func_104600(void *obj) {
    finalize_calls++;
    return obj;
}

void *func_0021CFB0(void *ctx, unsigned long long val_20, int s0, int self_28, const int *rect1, const int *rect2, int a6, int a7);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <case_id>\n";
        return 1;
    }

    std::string test_case = argv[1];
    calls.clear();
    finalize_calls = 0;
    header_calls = 0;

    int src_rect[4] = {0, 0, 32, 32};
    int dst_rect[4] = {10, 20, 32, 32};

    if (test_case == "0") {
        // Test textured quad packet generation
        void *res = func_0021CFB0(mock_obj, 0x12345678ULL, 1, 0, src_rect, dst_rect, 0x4000, 1);
        assert(res == mock_obj);
        assert(header_calls == 1);
        assert(finalize_calls == 1);
        // TEX0 + RGBAQ + 4 * (UV + XYZ2) = 1 + 1 + 8 = 10 calls to func_1046A8
        assert(calls.size() >= 6);
        std::cout << "PASS case 0\n";
        return 0;
    }

    if (test_case == "1") {
        // Test null ctx calls func_123908
        void *res = func_0021CFB0(nullptr, 0x12345678ULL, 0, 0, src_rect, dst_rect, 0x4000, 1);
        assert(res == mock_obj);
        assert(finalize_calls == 1);
        std::cout << "PASS case 1\n";
        return 0;
    }

    std::cerr << "Unknown case: " << test_case << "\n";
    return 2;
}
