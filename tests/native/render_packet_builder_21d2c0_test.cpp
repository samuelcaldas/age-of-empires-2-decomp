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
static void *mock_obj = (void *)0x5555;

unsigned int D_00392B70[4] = {0x1111, 0x2222, 0x3333, 0x4444};
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

void *func_0021D2C0(void *ctx, int a1, unsigned long long a2, const int *rect, int a4, int a5);
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

    int rect[4] = {10, 20, 100, 50}; // x=10, y=20, w=100, h=50

    if (test_case == "0") {
        // Test basic rect fill packet generation
        void *res = func_0021D2C0(mock_obj, 1, 0xFF00FF00ULL, rect, 0x4000, 1);
        assert(res == mock_obj);
        assert(header_calls == 1);
        assert(finalize_calls == 1);
        // RGBAQ + 4 vertices = 5 calls to func_1046A8
        assert(calls.size() == 5);
        assert(calls[0].reg == 1); // RGBAQ
        assert(calls[0].data == 0xFF00FF00ULL);
        assert(calls[1].reg == 4); // XYZ2 pt 0
        assert(calls[2].reg == 4); // XYZ2 pt 1
        assert(calls[3].reg == 4); // XYZ2 pt 2
        assert(calls[4].reg == 4); // XYZ2 pt 3
        std::cout << "PASS case 0\n";
        return 0;
    }

    if (test_case == "1") {
        // Test null ctx calls func_123908
        void *res = func_0021D2C0(nullptr, 0, 0x80000000ULL, rect, 0x4000, 1);
        assert(res == mock_obj);
        assert(finalize_calls == 1);
        std::cout << "PASS case 1\n";
        return 0;
    }

    std::cerr << "Unknown case: " << test_case << "\n";
    return 2;
}
