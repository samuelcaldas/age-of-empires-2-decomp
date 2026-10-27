#include <cassert>
#include <iostream>
#include <string>

static int ensure_obj_calls = 0;
static int kick_calls = 0;
static void *mock_obj = (void *)0x9999;

unsigned int D_00392BB0[4] = {0xAAAA, 0xBBBB, 0xCCCC, 0xDDDD};
unsigned short D_00CA158C = 0;
unsigned short D_00CA158E = 0;

extern "C" {
void *func_123908(void *arg) {
    ensure_obj_calls++;
    return mock_obj;
}

void func_102C88(void *a, void *b, void *c, void *d, void *e) {}
void *func_104448(void *obj, int a1, int a2, int a3) { return obj; }
void *func_1045E8(void *obj, void *tag) { return obj; }
void *func_104890(void *obj, void *data, int count) { return obj; }
void *func_104600(void *obj) { return obj; }
void func_104FA0(void *obj) { kick_calls++; }

void *func_0021E370(void *obj, int v0, int f1c, int a3, int t0, int t1, int t2, int t3);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <case_id>\n";
        return 1;
    }

    std::string test_case = argv[1];
    ensure_obj_calls = 0;
    kick_calls = 0;
    D_00CA158C = 0;
    D_00CA158E = 0;

    if (test_case == "0") {
        // Standard call: sets screen center and kicks DMA
        void *res = func_0021E370(mock_obj, 0, 0, 640, 512, 0x50000, 2, 2);
        assert(res == mock_obj);
        assert(kick_calls == 1);
        assert(D_00CA158C == 640);
        assert(D_00CA158E == 512);
        std::cout << "PASS case 0\n";
        return 0;
    }

    if (test_case == "1") {
        // Null object allocates packet
        void *res = func_0021E370(nullptr, 0, 0, 800, 600, 0x50000, 2, 2);
        assert(res == mock_obj);
        assert(ensure_obj_calls == 1);
        assert(kick_calls == 1);
        assert(D_00CA158C == 800);
        assert(D_00CA158E == 600);
        std::cout << "PASS case 1\n";
        return 0;
    }

    std::cerr << "Unknown case: " << test_case << "\n";
    return 2;
}
