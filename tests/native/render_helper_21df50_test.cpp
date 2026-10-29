#include <cassert>
#include <iostream>
#include <string>

static int ensure_obj_calls = 0;
static int send_calls = 0;
static int finalize_calls = 0;
static void *mock_obj = (void *)0x8888;
static int sent_args[10];
static void *sent_obj = nullptr;

extern "C" {
void *func_123908(void *arg) {
    ensure_obj_calls++;
    return mock_obj;
}

void func_1046D0(void *obj, unsigned short a1, unsigned char a2, unsigned short a3,
                 void *t0, int t1, short t2, short t3, long long stack_t3, long long stack_arg_b0) {
    sent_obj = obj;
    sent_args[0] = a1;
    sent_args[1] = a2;
    sent_args[2] = a3;
    sent_args[3] = static_cast<int>(reinterpret_cast<long>(t0));
    sent_args[4] = t1;
    sent_args[5] = t2;
    sent_args[6] = t3;
    sent_args[7] = static_cast<int>(stack_t3);
    sent_args[8] = static_cast<int>(stack_arg_b0);
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
        assert(sent_obj == mock_obj);
        assert(sent_args[0] == 0x28C0);
        assert(sent_args[1] == 10);
        assert(sent_args[2] == 0xA);
        assert(sent_args[3] == 16);
        assert(sent_args[4] == 32768);
        assert(sent_args[5] == 0);
        assert(sent_args[6] == 0);
        assert(sent_args[7] == 32);
        assert(sent_args[8] == 0x1000);
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
