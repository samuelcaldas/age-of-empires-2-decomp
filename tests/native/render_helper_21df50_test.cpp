#include <cassert>
#include <iostream>
#include <string>

static int ensure_obj_calls = 0;
static int send_calls = 0;
static int finalize_calls = 0;
static void *mock_obj = (void *)0x8888;

extern "C" {
void *func_123908(void *arg) {
    ensure_obj_calls++;
    return mock_obj;
}

void func_1046D0(void *obj, void *data, int count) {
    send_calls++;
}

void *func_0021C050(void *obj) {
    finalize_calls++;
    return obj;
}

void *func_0021DF50(void *ctx, int a1, int f1c, int a3, int s1, int a5, int a6, int aligned_3c, long long f38);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <case_id>\n";
        return 1;
    }

    std::string test_case = argv[1];
    ensure_obj_calls = 0;
    send_calls = 0;
    finalize_calls = 0;

    if (test_case == "0") {
        // Standard texture setup call from viewport
        void *res = func_0021DF50(mock_obj, 0x28C0, 10, 0xA, 16, 0, 0, 32, 0x1000ULL);
        assert(res == mock_obj);
        assert(send_calls == 1);
        assert(finalize_calls == 1);
        std::cout << "PASS case 0\n";
        return 0;
    }

    if (test_case == "1") {
        // Null ctx allocates packet
        void *res = func_0021DF50(nullptr, 0x28C0, 10, 0xA, 16, 0, 0, 32, 0x1000ULL);
        assert(res == mock_obj);
        assert(ensure_obj_calls == 1);
        assert(finalize_calls == 1);
        std::cout << "PASS case 1\n";
        return 0;
    }

    std::cerr << "Unknown case: " << test_case << "\n";
    return 2;
}
