#include <cassert>
#include <csetjmp>
#include <iostream>
#include <string>
#include <vector>
#include <sys/mman.h>
#include "kt_vsync_thread.h"

struct SemaContainer D_00C80490 = {30, {0, 0, 0, 0, 0, 0}};
int D_004E3318 = -1;

static std::vector<std::string> g_call_order;
static jmp_buf g_jump_buf;
static int g_loop_iterations = 0;
static volatile u64 *g_csr_ptr = nullptr;

extern "C" {
int func_2204D0(int sema_id) {
    assert(sema_id == 30);
    g_call_order.push_back("func_2204D0");
    return 0;
}

int func_104D60(int sema_id) {
    assert(sema_id == 30);
    g_call_order.push_back("func_104D60");
    g_loop_iterations++;
    if (g_loop_iterations == 1) {
        // Bit 13 set
        *g_csr_ptr = (1ULL << 13) | 0x42ULL;
    } else if (g_loop_iterations == 2) {
        // Bit 13 clear
        *g_csr_ptr = 0x42ULL;
    } else {
        longjmp(g_jump_buf, 1);
    }
    return 0;
}
}

static void test_case_0_vsync_field_reader_loop() {
    g_call_order.clear();
    g_loop_iterations = 0;
    D_004E3318 = -1;

    if (setjmp(g_jump_buf) == 0) {
        func_00220C10();
    }

    assert(g_loop_iterations == 3);
    assert(g_call_order.size() == 6);
    assert(D_004E3318 == 0); // After iteration 2, bit 13 was clear
    std::cout << "PASS: case 0 vsync field reader loop" << std::endl;
}

int main(int argc, char **argv) {
    void *page = mmap((void *)0x12001000, 4096, PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
    assert(page == (void *)0x12001000);
    g_csr_ptr = reinterpret_cast<volatile u64 *>(0x12001000);

    test_case_0_vsync_field_reader_loop();
    return 0;
}
