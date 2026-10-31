#include <cassert>
#include <iostream>
#include <string>
#include <sys/mman.h>

static int sync_calls = 0;
extern "C" {
int func_00221AC0(void) {
    sync_calls++;
    return 1;
}

void *func_104558(void *, int, int, int) { return 0; }
void *func_1043D8(void *) { return 0; }
void func_221880(void) {}
void func_221920(void) {}

void *func_00221B60(int type);
void func_00221C00(void) {
    func_00221B60(0x100);
    func_00221AC0();
}
}

int main(int argc, char **argv) {
    void *dma_state = mmap((void *)0x70000000, 0x10000, PROT_READ | PROT_WRITE,
                           MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
    assert(dma_state == (void *)0x70000000);
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <case_id>\n";
        return 1;
    }

    std::string test_case = argv[1];
    sync_calls = 0;

    if (test_case == "0") {
        void *ctx = func_00221B60(16);
        assert(ctx != nullptr);
        std::cout << "PASS case 0\n";
        return 0;
    }

    if (test_case == "1") {
        func_00221C00();
        assert(sync_calls == 1);
        std::cout << "PASS case 1\n";
        return 0;
    }

    std::cerr << "Unknown case: " << test_case << "\n";
    return 2;
}
